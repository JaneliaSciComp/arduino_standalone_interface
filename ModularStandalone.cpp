// ----------------------------------------------------------------------------
// ModularStandalone.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "ModularStandalone.h"


namespace Standalone
{
ModularStandalone::ModularStandalone(HardwareSerial &serial,
                                     const int enc_a_pin,
                                     const int enc_b_pin,
                                     const int enc_btn_pin,
                                     const int enc_btn_int,
                                     const int btn_pin,
                                     const int btn_int,
                                     const int lights_pin,
                                     const int update_period) :
  server_(serial,
          enc_a_pin,
          enc_b_pin,
          enc_btn_pin,
          enc_btn_int,
          btn_pin,
          btn_int,
          lights_pin,
          update_period)
{
}

void ModularStandalone::setup(const uint8_t frame_count)
{
  server_.setup(frame_count);
}

void ModularStandalone::setup(const ConstantString frame_name_array[],
                              const uint8_t frame_count)
{
  server_.setup(frame_name_array,frame_count);
}

void ModularStandalone::enable()
{
  server_.enable();
}

void ModularStandalone::disable()
{
  server_.disable();
}

bool ModularStandalone::update()
{
  return server_.update();
}

DisplayLabel& ModularStandalone::createDisplayLabel()
{
  return server_.createDisplayLabel();
}

DisplayVariable& ModularStandalone::createDisplayVariable()
{
  return server_.createDisplayVariable();
}

InteractiveVariable& ModularStandalone::createInteractiveVariable()
{
  return server_.createInteractiveVariable();
}

InteractiveVariable& ModularStandalone::createIncrementVariable()
{
  return server_.createIncrementVariable();
}

void ModularStandalone::attachCallbackToFrame(Callback callback, uint8_t frame)
{
  server_.attachCallbackToFrame(callback,frame);
}

void ModularStandalone::executeCurrentFrameCallback()
{
  server_.executeCurrentFrameCallback();
}
}
