// ----------------------------------------------------------------------------
// Callbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Callbacks.h"

using namespace ArduinoJson::Parser;

namespace callbacks
{
// Callbacks must be non-blocking (avoid 'delay')
//
// modular_device.getParameterValue must be cast to either:
// char*
// long
// double
// bool
// JsonArray
// JsonObject
//
// For more info read about ArduinoJson v3 JsonParser JsonValues
//
// modular_device.getSavedVariableValue type must match the saved variable default type
// modular_device.setSavedVariableValue type must match the saved variable default type

void executeStandaloneCallbackCallback()
{
  controller.executeStandaloneCallback();
}

void getDspVar1Callback()
{
  int value = controller.getDspVar1();
  modular_device.addToResponse("value",value);
}

void setDspVar1Callback()
{
  long value = modular_device.getParameterValue(constants::dsp_var1_parameter_name);
  controller.setDspVar1(value);
}

void getIntVar1Callback()
{
  uint8_t value = controller.getIntVar1();
  modular_device.addToResponse("value",value);
}

void setIntVar1Callback()
{
  long value = modular_device.getParameterValue(constants::int_var1_parameter_name);
  controller.setIntVar1(value);
}

void getIntVar2Callback()
{
  uint8_t value = controller.getIntVar2();
  modular_device.addToResponse("value",value);
}

void setIntVar2Callback()
{
  long value = modular_device.getParameterValue(constants::int_var2_parameter_name);
  controller.setIntVar2(value);
}

void addIntVar1ToDspVar1Callback()
{
  int dis_var1 = controller.getDspVar1();
  uint8_t int_var1 = controller.getIntVar1();
  controller.setDspVar1(dis_var1+int_var1);
}

void subIntVar2FromDspVar1Callback()
{
  int dis_var1 = controller.getDspVar1();
  uint8_t int_var2 = controller.getIntVar2();
  controller.setDspVar1(dis_var1-int_var2);
}
}
