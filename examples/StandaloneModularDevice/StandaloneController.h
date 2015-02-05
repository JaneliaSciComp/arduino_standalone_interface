// ----------------------------------------------------------------------------
// StandaloneController.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef STANDALONE_CONTROLLER_H
#define STANDALONE_CONTROLLER_H
#include "Constants.h"
#include "ModularDevice.h"
#include "StandaloneInterface.h"


class StandaloneController
{
public:
  StandaloneController();
  void init();
  void update();

private:
  Standalone::StandaloneInterface standalone_interface_;
  Standalone::DisplayLabel *display_label1_ptr_;
  Standalone::DisplayVariable *display_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var1_ptr_;
  Standalone::InteractiveVariable *interactive_var2_ptr_;
};

extern StandaloneController standalone_controller;

#endif
