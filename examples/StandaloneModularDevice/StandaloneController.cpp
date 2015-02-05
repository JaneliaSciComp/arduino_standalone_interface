// ----------------------------------------------------------------------------
// StandaloneController.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "StandaloneController.h"


namespace Standalone
{
StandaloneController::StandaloneController() :
  standalone_interface_(StandaloneInterface(constants::display_serial,
                                            constants::enc_a_pin,
                                            constants::enc_b_pin,
                                            constants::enc_btn_pin,
                                            constants::enc_btn_int,
                                            constants::btn_pin,
                                            constants::btn_int,
                                            constants::standalone_update_period))
{
  display_label1_ptr_ = &(standalone_interface_.createDisplayLabel());
  display_var1_ptr_ = &(standalone_interface_.createDisplayVariable());
  interactive_var1_ptr_ = &(standalone_interface_.createInteractiveVariable());
  interactive_var2_ptr_ = &(standalone_interface_.createInteractiveVariable());
}

void StandaloneController::init()
{
  display_label1_ptr_->setDisplayPosition(constants::display_label1_display_position);
  display_label1_ptr_->setFlashString(constants::display_label1_string);

  display_var1_ptr_->setDisplayPosition(constants::display_var1_display_position);
  display_var1_ptr_->setValue(constants::display_var1_default_value);

  interactive_var1_ptr_->setDisplayPosition(constants::interactive_var1_display_position);
  interactive_var1_ptr_->setRange(constants::interactive_var1_min,constants::interactive_var1_max);
  interactive_var1_ptr_->setRightJustify();

  interactive_var2_ptr_->setDisplayPosition(constants::interactive_var2_display_position);
  interactive_var2_ptr_->setRange(constants::interactive_var2_min,constants::interactive_var2_max);
  interactive_var2_ptr_->setLeftJustify();

  standalone_interface_.enable();
}

void StandaloneController::update()
{
  standalone_interface_.update();
}
}

Standalone::StandaloneController standalone_controller;
