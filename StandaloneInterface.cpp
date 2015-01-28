// ----------------------------------------------------------------------------
// StandaloneInterface.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "StandaloneInterface.h"


StandaloneInterface::StandaloneInterface(HardwareSerial &serial,
                                         int enc_a_pin,
                                         int enc_b_pin,
                                         int enc_btn_pin,
                                         int btn_pin)
{
  display_ = NewhavenDisplay(serial);
  encoder_ = Encoder(enc_b_pin,enc_a_pin);
  enc_btn_pin_ = enc_btn_pin;
  btn_pin_ = btn_pin;
}

void StandaloneInterface::setServerSerial(HardwareSerial &serial)
{
  server_.setSerial(serial);
}

void StandaloneInterface::setName(const _FLASH_STRING &interface_name)
{
  server_.setName(interface_name);
}

StandaloneInterface::StandaloneInterface standalone_interface(Serial);
