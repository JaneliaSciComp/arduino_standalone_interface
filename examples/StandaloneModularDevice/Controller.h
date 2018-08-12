// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <ModularServer.h>
#include <StandaloneInterface.h>

#include "Constants.h"
#include "Callbacks.h"


class Controller
{
public:
  Controller();
  void setup();
  void update();
  ModularDevice::ModularServer& getModularServer();

  void executeStandaloneCallback();
  int getDspVar1();
  void setDspVar1(int value);
  int getIntVar1();
  void setIntVar1(int value);
  int getIntVar2();
  void setIntVar2(int value);
private:
  ModularDevice::ModularServer modular_server_;
  SavedVariable saved_variables_[constants::SAVED_VARIABLE_COUNT_MAX];
  ModularDevice::Parameter parameters_[constants::PARAMETER_COUNT_MAX];
  ModularDevice::Method methods_[constants::METHOD_COUNT_MAX];

  Standalone::StandaloneInterface standalone_interface_;
  Standalone::DisplayLabel display_labels_[constants::DISPLAY_LABEL_COUNT_MAX];
  Standalone::DisplayVariable display_variables_[constants::DISPLAY_VARIABLE_COUNT_MAX];
  Standalone::InteractiveVariable interactive_variables_[constants::INTERACTIVE_VARIABLE_COUNT_MAX];

  Standalone::DisplayVariable *dsp_var1_ptr_;
  Standalone::InteractiveVariable *int_var1_ptr_;
  Standalone::InteractiveVariable *int_var2_ptr_;
};

extern Controller controller;

#endif
