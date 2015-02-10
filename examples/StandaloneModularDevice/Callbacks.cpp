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

void setDisplayVariable1Callback()
{
  long display_value = modular_device.getParameterValue(constants::display_value_parameter_name);
  controller.setDisplayVariable1(display_value);
}

void setInteractiveVariable1Callback()
{
  long int_var = modular_device.getParameterValue(constants::interactive_variable1_parameter_name);
  controller.setInteractiveVariable1(int_var);
}

void getInteractiveVariable1Callback()
{
  uint8_t value = controller.getInteractiveVariable1();
  modular_device.addToResponse("value",value);
}

void setInteractiveVariable2Callback()
{
  long int_var = modular_device.getParameterValue(constants::interactive_variable2_parameter_name);
  controller.setInteractiveVariable2(int_var);
}

void getInteractiveVariable2Callback()
{
  uint8_t value = controller.getInteractiveVariable2();
  modular_device.addToResponse("value",value);
}

}
