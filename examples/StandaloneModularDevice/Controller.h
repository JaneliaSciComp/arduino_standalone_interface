// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ModularDevice.h"
#include "StandaloneInterface.h"
#include "Constants.h"
#include "Callbacks.h"


class Controller
{
public:
  Controller();
  void setup();
  void update();

private:
  Standalone::StandaloneInterface standalone_interface_;
  Standalone::DisplayLabel *display_label1_ptr_;
  Standalone::DisplayVariable *display_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var2_ptr_;
};

extern Controller controller;

#endif
