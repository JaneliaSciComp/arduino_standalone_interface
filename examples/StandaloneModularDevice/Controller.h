// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ModularServer.h"
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
  int getDspVar1();
  void setDspVar1(int value);
  int getIntVar1();
  void setIntVar1(int value);
  int getIntVar2();
  void setIntVar2(int value);
private:
  Standalone::StandaloneInterface standalone_interface_;
  Standalone::DisplayVariable *dsp_var1_ptr_;
  Standalone::InteractiveVariable *int_var1_ptr_;
  Standalone::InteractiveVariable *int_var2_ptr_;
};

extern Controller controller;

#endif
