// ----------------------------------------------------------------------------
// Server.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Server.h"


Server::Server(HardwareSerial &serial,
               const int enc_a_pin,
               const int enc_b_pin,
               const int enc_btn_pin,
               const int enc_btn_int,
               const int btn_pin,
               const int btn_int,
               const int update_period) :
  display_(serial),
  encoder_(enc_b_pin,enc_a_pin),
  enc_btn_pin_(enc_btn_pin),
  enc_btn_int_(enc_btn_int),
  btn_pin_(btn_pin),
  btn_int_(btn_int),
  update_period_(update_period)
{
  display_.init();
  disable();
  time_last_update_ = millis();
  interactive_variable_index_ = -1;
}

void Server::update()
{
  if (enabled_)
  {
    unsigned long time_now = millis();
    if ((time_now - time_last_update_) > update_period_)
    {
      time_last_update_ = time_now;
      if (interactive_variable_index_ > 0)
      {
        InteractiveVariable &int_var = interactive_variable_vector_[interactive_variable_index_];
      }
      // display_.setCursor(0);
      // display_.print("test");
      // display_.setCursor(20);
      // display_.print(57683);
      // display_.setCursor(40);
      // display_.printPadRight(String(encoder_.read()),4);
    }
  }
}

void Server::enable()
{
  enabled_ = true;
}

void Server::disable()
{
  enabled_ = false;
}

InteractiveVariable& Server::createInteractiveVariable()
{
  interactive_variable_vector_.push_back(InteractiveVariable());
  if (interactive_variable_index_ < 0)
  {
    interactive_variable_index_ = 0;
  }
  return interactive_variable_vector_.back();
}
