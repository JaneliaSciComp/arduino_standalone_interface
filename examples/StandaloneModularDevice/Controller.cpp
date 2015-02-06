// ----------------------------------------------------------------------------
// Controller.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Controller.h"


Controller::Controller() :
  standalone_interface_(Standalone::StandaloneInterface(constants::display_serial,
                                                        constants::enc_a_pin,
                                                        constants::enc_b_pin,
                                                        constants::enc_btn_pin,
                                                        constants::enc_btn_int,
                                                        constants::btn_pin,
                                                        constants::btn_int,
                                                        constants::standalone_update_period))
{
}

void Controller::setup()
{
  // Pin Setup

  // Device Info
  modular_device.setName(constants::device_name);
  modular_device.setModelNumber(constants::model_number);
  modular_device.setFirmwareNumber(constants::firmware_number);

  // Saved Variables

  // Parameters
  ModularDevice::Parameter& display_value_parameter = modular_device.createParameter(constants::display_value_parameter_name);
  display_value_parameter.setRange(constants::display_variable_min,constants::display_variable_max);

  ModularDevice::Parameter& interactive_variable1_parameter = modular_device.createParameter(constants::interactive_variable1_parameter_name);
  interactive_variable1_parameter.setRange(constants::interactive_var1_min,constants::interactive_var1_max);

  ModularDevice::Parameter& interactive_variable2_parameter = modular_device.createParameter(constants::interactive_variable2_parameter_name);
  interactive_variable2_parameter.setRange(constants::interactive_var2_min,constants::interactive_var2_max);

  // Methods
  ModularDevice::Method& set_display_variable1_method = modular_device.createMethod(constants::set_display_variable1_method_name);
  set_display_variable1_method.attachCallback(callbacks::setDisplayVariable1Callback);
  set_display_variable1_method.addParameter(display_value_parameter);

  ModularDevice::Method& set_interactive_variable1_method = modular_device.createMethod(constants::set_interactive_variable1_method_name);
  set_interactive_variable1_method.attachCallback(callbacks::setInteractiveVariable1Callback);
  set_interactive_variable1_method.addParameter(interactive_variable1_parameter);

  ModularDevice::Method& get_interactive_variable1_method = modular_device.createMethod(constants::get_interactive_variable1_method_name);
  get_interactive_variable1_method.attachCallback(callbacks::getInteractiveVariable1Callback);

  ModularDevice::Method& set_interactive_variable2_method = modular_device.createMethod(constants::set_interactive_variable2_method_name);
  set_interactive_variable2_method.attachCallback(callbacks::setInteractiveVariable2Callback);
  set_interactive_variable2_method.addParameter(interactive_variable2_parameter);

  ModularDevice::Method& get_interactive_variable2_method = modular_device.createMethod(constants::get_interactive_variable2_method_name);
  get_interactive_variable2_method.attachCallback(callbacks::getInteractiveVariable2Callback);

  // Start ModularDevice Server
  modular_device.startServer(constants::baudrate);

  // Standalone Interface
  standalone_interface_.setup();

  // Display Labels
  Standalone::DisplayLabel& display_label1 = standalone_interface_.createDisplayLabel();
  display_label1.setDisplayPosition(constants::display_label1_display_position);
  display_label1.setFlashString(constants::display_label1_string);

  Standalone::DisplayLabel& display_label2 = standalone_interface_.createDisplayLabel();
  display_label2.setDisplayPosition(constants::display_label2_display_position);
  display_label2.setFlashString(constants::display_label2_string);

  Standalone::DisplayLabel& display_label3 = standalone_interface_.createDisplayLabel();
  display_label3.setDisplayPosition(constants::display_label3_display_position);
  display_label3.setFlashString(constants::display_label3_string);

  // Display Variables
  display_var1_ptr_ = &(standalone_interface_.createDisplayVariable());
  display_var1_ptr_->setDisplayPosition(constants::display_var1_display_position);
  display_var1_ptr_->setValue(constants::display_var1_default_value);

  // Interactive Variables
  interactive_var1_ptr_ = &(standalone_interface_.createInteractiveVariable());
  interactive_var1_ptr_->setDisplayPosition(constants::interactive_var1_display_position);
  interactive_var1_ptr_->setRange(constants::interactive_var1_min,constants::interactive_var1_max);
  interactive_var1_ptr_->setRightJustify();

  interactive_var2_ptr_ = &(standalone_interface_.createInteractiveVariable());
  interactive_var2_ptr_->setDisplayPosition(constants::interactive_var2_display_position);
  interactive_var2_ptr_->setRange(constants::interactive_var2_min,constants::interactive_var2_max);
  interactive_var2_ptr_->setLeftJustify();

  // Enable Standalone Interface
  standalone_interface_.enable();
}

void Controller::update()
{
  modular_device.handleServerRequests();
  standalone_interface_.update();
}

void Controller::setDisplayVariable1(uint8_t value)
{
  display_var1_ptr_->setValue(value);
}

void Controller::setInteractiveVariable1(uint8_t value)
{
  interactive_var1_ptr_->setValue(value);
}

uint8_t Controller::getInteractiveVariable1()
{
  return interactive_var1_ptr_->getValue();
}

void Controller::setInteractiveVariable2(uint8_t value)
{
  interactive_var2_ptr_->setValue(value);
}

uint8_t Controller::getInteractiveVariable2()
{
  return interactive_var2_ptr_->getValue();
}

Controller controller;
