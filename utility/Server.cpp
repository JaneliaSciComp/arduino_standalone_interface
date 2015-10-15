// ----------------------------------------------------------------------------
// Server.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Server.h"


namespace Standalone
{
void defaultCallback()
{
}
volatile bool Server::enc_btn_pressed_ = false;
uint8_t Server::frame_current_ = 0;
Server::Callback Server::callback_array_[constants::FRAMES_COUNT_MAX];
CONSTANT_STRING(inc0,"1");
CONSTANT_STRING(inc1,"10");
CONSTANT_STRING(inc2,"100");
CONSTANT_STRING(inc3,"1000");
CONSTANT_STRING(inc4,"10000");
const uint8_t INC_STRING_COUNT = 5;
const ConstantString increment_array[] =
  {
    inc0,
    inc1,
    inc2,
    inc3,
    inc4,
  };

Server::Server(HardwareSerial &serial,
               const int enc_a_pin,
               const int enc_b_pin,
               const int enc_btn_pin,
               const int enc_btn_int,
               const int btn_pin,
               const int btn_int,
               const int lights_pin,
               const int update_period) :
  display_(serial),
  encoder_(enc_b_pin,enc_a_pin),
  enc_btn_pin_(enc_btn_pin),
  enc_btn_int_(enc_btn_int),
  btn_pin_(btn_pin),
  btn_int_(btn_int),
  lights_pin_(lights_pin),
  update_period_(update_period)
{
  setup_ = false;
  interactive_variable_index_ = -1;
  frame_var_ptr_ = NULL;
  frame_name_array_ = NULL;
  inc_var_ptr_ = NULL;
  enc_value_prev_ = 0;
}

void Server::setup(const uint8_t frame_count)
{
  if (!setup_)
  {
    setup_ = true;
    display_.setup();
    disable();
    time_last_update_ = millis();

    pinMode(enc_btn_pin_,INPUT);
    digitalWrite(enc_btn_pin_,HIGH);
    attachInterrupt(enc_btn_int_,encBtnIsr,FALLING);

    pinMode(btn_pin_,INPUT);
    digitalWrite(btn_pin_,HIGH);
    attachInterrupt(btn_int_,btnIsr,FALLING);

    pinMode(lights_pin_,INPUT);

    frame_var_ptr_ = &(createInteractiveVariable());
    frame_var_ptr_->setDisplayPosition(FRAME_VAR_DISPLAY_POSITION);
    frame_var_ptr_->setDisplayWidth(FRAME_VAR_DISPLAY_WIDTH);
    frame_var_ptr_->addToAllFrames();

    for (uint8_t frame=0; frame < constants::FRAMES_COUNT_MAX; frame++)
    {
      Server::callback_array_[frame] = defaultCallback;
    }
  }
  if (frame_count > constants::FRAMES_COUNT_MAX)
  {
    frame_count_ = constants::FRAMES_COUNT_MAX;
  }
  else
  {
    frame_count_ = frame_count;
  }
  frame_var_ptr_->setConstantStringArray(frame_name_array_,frame_count_);
}

void Server::setup(const ConstantString frame_name_array[],
                   const uint8_t frame_count)
{
  frame_name_array_ = frame_name_array;
  setup(frame_count);
}

void Server::enable()
{
  enabled_ = true;
  display_.displayOn();
  display_.blinkingCursorOn();
}

void Server::disable()
{
  enabled_ = false;
  ledOff();
  display_.displayOff();
}

bool Server::update()
{
  if (!enabled_)
  {
    return false;
  }

  if (led_off_ && (digitalRead(lights_pin_) == LOW))
  {
    ledOn();
  }
  else if (!led_off_ && (digitalRead(lights_pin_) == HIGH))
  {
    ledOff();
  }

  unsigned long time_now = millis();
  if ((int)(time_now - time_last_update_) < update_period_)
  {
    return false;
  }

  time_last_update_ = time_now;
  Server::frame_current_ = frame_var_ptr_->getValue();

  // Update current interactive variable values
  if (interactive_variable_index_ >= 0)
  {
    InteractiveVariable *int_var_ptr = &(interactive_variable_array_[interactive_variable_index_]);
    bool interactive_variable_index_changed = false;
    if (Server::enc_btn_pressed_)
    {
      Server::enc_btn_pressed_ = false;
      int int_var_prev = interactive_variable_index_;
      do
      {
        interactive_variable_index_++;
        if (interactive_variable_index_ >= (int)interactive_variable_array_.size())
        {
          interactive_variable_index_ = 0;
        }
        int_var_ptr = &(interactive_variable_array_[interactive_variable_index_]);
      }
      while (!int_var_ptr->inFrame(Server::frame_current_));
      if (int_var_prev != interactive_variable_index_)
      {
        interactive_variable_index_changed = true;
      }
    }

    if (!int_var_ptr->checkValueDirty() && !interactive_variable_index_changed)
    {
      int32_t enc_value = encoder_.read();
      if (inc_var_ptr_ && (int_var_ptr != inc_var_ptr_) && (int_var_ptr != frame_var_ptr_))
      {
        if (inc_var_ptr_->inFrame(Server::frame_current_))
        {
          int8_t inc_exp = inc_var_ptr_->getValue();
          int inc_value = 1;
          for (int i=0; i<inc_exp; ++i)
          {
            inc_value *= 10;
          }
          enc_value = (enc_value - enc_value_prev_)*inc_value + enc_value_prev_;
          encoder_.write(enc_value);
        }
      }
      int_var_ptr->updateWithEncoderValue(enc_value);
      if (int_var_ptr == frame_var_ptr_)
      {
        int_var_ptr->trimDisplayWidth();
      }
      enc_value_prev_ = enc_value;
    }
    // updateWithEncoderValue may have dirtied value
    if (int_var_ptr->checkValueDirty() || interactive_variable_index_changed)
    {
      encoder_.write(int_var_ptr->getValue());
      enc_value_prev_ = encoder_.read();
      int_var_ptr->clearValueDirty();
      interactive_variable_index_changed = false;
    }
    int_var_ptr->executeUpdateCallback();
  }

  int frame_prev = Server::frame_current_;
  Server::frame_current_ = frame_var_ptr_->getValue();
  if (Server::frame_current_ != frame_prev)
  {
    display_.clearScreen();
    // Dirty all interactive_variables
    for (unsigned int i=0; i<interactive_variable_array_.size(); ++i)
    {
      interactive_variable_array_[i].setDisplayDirty();
    }

    // Dirty all display_variables
    for (unsigned int i=0; i<display_variable_array_.size(); ++i)
    {
      display_variable_array_[i].setDisplayDirty();
    }

    // Dirty all display_labels
    for (unsigned int i=0; i<display_label_array_.size(); ++i)
    {
      display_label_array_[i].setDisplayDirty();
    }
  }

  // Update all interactive_variables on display
  for (unsigned int i=0; i<interactive_variable_array_.size(); ++i)
  {
    interactive_variable_array_[i].updateOnDisplay(display_,Server::frame_current_);
  }

  // Update all display_variables on display
  for (unsigned int i=0; i<display_variable_array_.size(); ++i)
  {
    display_variable_array_[i].updateOnDisplay(display_,Server::frame_current_);
  }

  // Update all display_labels on display
  for (unsigned int i=0; i<display_label_array_.size(); ++i)
  {
    display_label_array_[i].updateOnDisplay(display_,Server::frame_current_);
  }

  // Place the cursor back on the current interactive variable
  if (interactive_variable_index_ >= 0)
  {
    InteractiveVariable &int_var = interactive_variable_array_[interactive_variable_index_];
    display_.setCursor(int_var.getDisplayPosition());
  }
  return true;
}

DisplayLabel& Server::createDisplayLabel()
{
  DisplayLabel display_label;
  display_label_array_.push_back(display_label);
  return display_label_array_.back();
}

DisplayVariable& Server::createDisplayVariable()
{
  DisplayVariable display_var;
  display_variable_array_.push_back(display_var);
  return display_variable_array_.back();
}

InteractiveVariable& Server::createInteractiveVariable()
{
  if (!setup_)
  {
    setup(constants::FRAMES_COUNT_MAX);
  }
  InteractiveVariable int_var;
  interactive_variable_array_.push_back(int_var);
  if (interactive_variable_index_ < 0)
  {
    interactive_variable_index_ = 0;
  }
  return interactive_variable_array_.back();
}

InteractiveVariable& Server::createIncrementVariable()
{
  if (!inc_var_ptr_)
  {
    InteractiveVariable& inc_var = createInteractiveVariable();
    inc_var_ptr_ = &inc_var;
    inc_var.setRange(0,INC_STRING_COUNT-1);
    inc_var.setDisplayWidth(5);
    inc_var.setConstantStringArray(increment_array,INC_STRING_COUNT);
    inc_var.setValue(0);
    return inc_var;
  }
  else
  {
    return *inc_var_ptr_;
  }
}

void Server::attachCallbackToFrame(Callback callback, uint8_t frame)
{
  if (frame < constants::FRAMES_COUNT_MAX)
  {
    Server::callback_array_[frame] = callback;
  }
}

void Server::executeCurrentFrameCallback()
{
  (*Server::callback_array_[Server::frame_current_])();
}

void Server::encBtnIsr()
{
  Server::enc_btn_pressed_ = true;
}

void Server::btnIsr()
{
  (*Server::callback_array_[Server::frame_current_])();
}

void Server::ledOn()
{
  display_.setBrightnessDefault();
  led_off_ = false;
}

void Server::ledOff()
{
  display_.setBrightness(0);
  led_off_ = true;
}
}
