// ----------------------------------------------------------------------------
// Callbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Callbacks.h"


namespace callbacks
{
// Callbacks must be non-blocking (avoid 'delay')
//
// modular_server.getParameterValue must be cast to either:
// const char*
// long
// double
// bool
// ArduinoJson::JsonArray&
// ArduinoJson::JsonObject&
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server.getSavedVariableValue type must match the saved variable default type
// modular_server.setSavedVariableValue type must match the saved variable default type

void executeStandaloneCallbackCallback()
{
  controller.executeStandaloneCallback();
}

void getDspVar1Callback()
{
  int value = controller.getDspVar1();
  modular_server.writeResultToResponse(value);
}

void setDspVar1Callback()
{
  long value = modular_server.getParameterValue(constants::dsp_var1_parameter_name);
  controller.setDspVar1(value);
}

void getIntVar1Callback()
{
  uint8_t value = controller.getIntVar1();
  modular_server.writeResultToResponse(value);
}

void setIntVar1Callback()
{
  long value = modular_server.getParameterValue(constants::int_var1_parameter_name);
  controller.setIntVar1(value);
}

void getIntVar2Callback()
{
  uint8_t value = controller.getIntVar2();
  modular_server.writeResultToResponse(value);
}

void setIntVar2Callback()
{
  long value = modular_server.getParameterValue(constants::int_var2_parameter_name);
  controller.setIntVar2(value);
}

// Standalone Callbacks
void addIntVar1ToDspVar1Callback()
{
  int dis_var1 = controller.getDspVar1();
  int int_var1 = controller.getIntVar1();
  controller.setDspVar1(dis_var1+int_var1);
}

void subIntVar2FromDspVar1Callback()
{
  int dis_var1 = controller.getDspVar1();
  int int_var2 = controller.getIntVar2();
  controller.setDspVar1(dis_var1-int_var2);
}
}
