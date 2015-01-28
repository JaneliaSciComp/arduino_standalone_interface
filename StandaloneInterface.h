// ----------------------------------------------------------------------------
// StandaloneInterface.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef STANDALONE_INTERFACE_H
#define STANDALONE_INTERFACE_H
#include "NewhavenDisplay.h"
#include "Encoder.h"


class StandaloneInterface
{
public:
  StandaloneInterface(HardwareSerial &serial,
                      int enc_a_pin,
                      int enc_b_pin,
                      int enc_btn_pin,
                      int btn_pin);
private:
  NewhavenDisplay display_;
  Encoder encoder_;
  int enc_btn_pin_;
  int btn_pin_;
};

extern StandaloneInterface::StandaloneInterface standalone_interface;

#endif
