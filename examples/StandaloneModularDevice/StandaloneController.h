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


namespace Standalone
{
class StandaloneController
{
public:
  StandaloneController();
  void init();
  void update();

private:
  StandaloneInterface standalone_interface_;
  DisplayLabel *display_label1_ptr_;
  DisplayVariable *display_var1_ptr_;
  InteractiveVariable *interactive_var1_ptr_;
  InteractiveVariable *interactive_var2_ptr_;
};
}
extern Standalone::StandaloneController standalone_controller;

#endif
