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
volatile boolean Server::enc_btn_pressed_ = false;
uint8_t Server::frame_current_ = 0;
Callback Server::callback_array_[DisplayElement::FRAMES_COUNT_MAX];

Server::Server(HardwareSerial &serial,
               const int enc_a_pin,
               const int enc_b_pin,
               const int enc_btn_pin,
               const int enc_btn_int,
               const int btn_pin,
               const int btn_int,
               const int led_pwr_pin,
               const int update_period) :
  display_(serial),
  encoder_(enc_b_pin,enc_a_pin),
  enc_btn_pin_(enc_btn_pin),
  enc_btn_int_(enc_btn_int),
  btn_pin_(btn_pin),
  btn_int_(btn_int),
  led_pwr_pin_(led_pwr_pin),
  update_period_(update_period)
{
  setup_ = false;
  interactive_variable_count_ = 0;
  interactive_variable_index_ = -1;
  frame_var_ptr_ = NULL;
  frame_name_array_ = NULL;
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

    pinMode(led_pwr_pin_,INPUT);

    frame_var_ptr_ = &(createInteractiveVariable());
    frame_var_ptr_->setDisplayPosition(FRAME_VAR_DISPLAY_POSITION);
    frame_var_ptr_->setDisplayWidth(FRAME_VAR_DISPLAY_WIDTH);
    frame_var_ptr_->addToAllFrames();

    for (uint8_t frame=0; frame < DisplayElement::FRAMES_COUNT_MAX; frame++)
    {
      Server::callback_array_[frame] = defaultCallback;
    }
  }
  if (frame_count > DisplayElement::FRAMES_COUNT_MAX)
  {
    frame_count_ = DisplayElement::FRAMES_COUNT_MAX;
  }
  else
  {
    frame_count_ = frame_count;
  }
  frame_var_ptr_->setFlashStringArray(frame_name_array_,frame_count_);
  display_labels_dirty_ = true;
}

void Server::setup(const _FLASH_STRING frame_name_array[],
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

void Server::update()
{
  if (!enabled_)
  {
    return;
  }

  if (led_off_ && (digitalRead(led_pwr_pin_) == HIGH))
  {
    ledOn();
  }
  else if (!led_off_ && (digitalRead(led_pwr_pin_) == LOW))
  {
    ledOff();
  }

  unsigned long time_now = millis();
  if ((time_now - time_last_update_) < update_period_)
  {
    return;
  }

  time_last_update_ = time_now;
  Server::frame_current_ = frame_var_ptr_->getValue();

  // Update current interactive variable values
  if (interactive_variable_index_ >= 0)
  {
    InteractiveVariable *int_var_ptr = &(interactive_variable_vector_[interactive_variable_index_]);
    boolean interactive_variable_index_changed = false;
    if (Server::enc_btn_pressed_)
    {
      Server::enc_btn_pressed_ = false;
      int int_var_prev = interactive_variable_index_;
      do
      {
        interactive_variable_index_++;
        if (interactive_variable_index_ >= interactive_variable_count_)
        {
          interactive_variable_index_ = 0;
        }
        int_var_ptr = &(interactive_variable_vector_[interactive_variable_index_]);
      }
      while (!int_var_ptr->inFrame(Server::frame_current_));
      if (int_var_prev != interactive_variable_index_)
      {
        interactive_variable_index_changed = true;
      }
    }

    if (!int_var_ptr->checkValueDirty() && !interactive_variable_index_changed)
    {
      int_var_ptr->updateWithEncoderValue(encoder_.read());
    }
    // updateWithEncoderValue may have dirtied value
    if (int_var_ptr->checkValueDirty() || interactive_variable_index_changed)
    {
      encoder_.write(int_var_ptr->getValue());
      int_var_ptr->clearValueDirty();
      interactive_variable_index_changed = false;
    }
  }

  int frame_prev = Server::frame_current_;
  Server::frame_current_ = frame_var_ptr_->getValue();
  if (Server::frame_current_ != frame_prev)
  {
    display_.clearScreen();
    display_labels_dirty_ = true;
  }

  // Update all display_labels on display if necessary
  if (display_labels_dirty_)
  {
    display_labels_dirty_ = false;
    for (std::vector<DisplayLabel>::iterator display_label_it = display_label_vector_.begin();
         display_label_it != display_label_vector_.end();
         ++display_label_it)
    {
      display_label_it->updateOnDisplay(display_,Server::frame_current_);
    }
  }
  // Update all display_variables on display
  for (std::vector<DisplayVariable>::iterator display_var_it = display_variable_vector_.begin();
       display_var_it != display_variable_vector_.end();
       ++display_var_it)
  {
    display_var_it->updateOnDisplay(display_,Server::frame_current_);
  }
  // Update all interactive_variables on display
  for (std::vector<InteractiveVariable>::iterator int_var_it = interactive_variable_vector_.begin();
       int_var_it != interactive_variable_vector_.end();
       ++int_var_it)
  {
    int_var_it->updateOnDisplay(display_,Server::frame_current_);
  }
  // Place the cursor back on the current interactive variable
  if (interactive_variable_index_ >= 0)
  {
    InteractiveVariable &int_var = interactive_variable_vector_[interactive_variable_index_];
    display_.setCursor(int_var.getDisplayPosition());
  }
}

DisplayLabel& Server::createDisplayLabel()
{
  DisplayLabel display_label;
  display_label_vector_.push_back(display_label);
  return display_label_vector_.back();
}

DisplayVariable& Server::createDisplayVariable()
{
  DisplayVariable display_var;
  display_variable_vector_.push_back(display_var);
  return display_variable_vector_.back();
}

InteractiveVariable& Server::createInteractiveVariable()
{
  if (!setup_)
  {
    setup(DisplayElement::FRAMES_COUNT_MAX);
  }
  InteractiveVariable int_var;
  interactive_variable_vector_.push_back(int_var);
  if (interactive_variable_index_ < 0)
  {
    interactive_variable_index_ = 0;
  }
  interactive_variable_count_++;
  return interactive_variable_vector_.back();
}

void Server::attachCallbackToFrame(Callback callback, uint8_t frame)
{
  if (frame < DisplayElement::FRAMES_COUNT_MAX)
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
