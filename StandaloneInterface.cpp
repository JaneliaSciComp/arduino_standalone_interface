// ----------------------------------------------------------------------------
// StandaloneInterface.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "StandaloneInterface.h"


StandaloneInterface::StandaloneInterface(HardwareSerial &serial,
                                         const int enc_a_pin,
                                         const int enc_b_pin,
                                         const int enc_btn_pin,
                                         const int enc_btn_int,
                                         const int btn_pin,
                                         const int btn_int,
                                         const int update_period) :
  server_(serial,
          enc_a_pin,
          enc_b_pin,
          enc_btn_pin,
          enc_btn_int,
          btn_pin,
          btn_int,
          update_period)
{
}

void StandaloneInterface::update()
{
  server_.update();
}

void StandaloneInterface::enable()
{
  server_.enable();
}

void StandaloneInterface::disable()
{
  server_.disable();
}

void StandaloneInterface::disable()
{
  server_.disable();
}

InteractiveVariable& StandaloneInterface::createInteractiveVariable()
{
  return server_.createInteractiveVariable();
}
