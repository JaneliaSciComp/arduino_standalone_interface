// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ModularDevice.h"
#include "Flash.h"
#include "StandaloneInterface.h"
#include "Constants.h"
#include "Callbacks.h"


class Controller
{
public:
  Controller();
  void setup();
  void update();
  void executeStandaloneCallback();
  int getDisplayVariable1();
  void setDisplayVariable1(int value);
  uint8_t getInteractiveVariable1();
  void setInteractiveVariable1(uint8_t value);
  uint8_t getInteractiveVariable2();
  void setInteractiveVariable2(uint8_t value);
private:
  Standalone::StandaloneInterface standalone_interface_;
  Standalone::DisplayVariable *display_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var2_ptr_;
};

extern Controller controller;

#endif
