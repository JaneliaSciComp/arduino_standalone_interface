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
                                                        constants::lights_pin,
                                                        constants::standalone_update_period))
{
}

void Controller::setup()
{
  // Pin Setup

  // Device Info
  modular_device.setName(constants::device_name);
  modular_device.setModelNumber(constants::model_number);
  modular_device.setFirmwareVersion(constants::firmware_major,constants::firmware_minor,constants::firmware_patch);

  // Saved Variables

  // Parameters
  ModularDevice::Parameter& dsp_var1_parameter = modular_device.createParameter(constants::dsp_var1_parameter_name);
  dsp_var1_parameter.setRange(constants::dsp_var1_min,constants::dsp_var1_max);

  ModularDevice::Parameter& int_var1_parameter = modular_device.createParameter(constants::int_var1_parameter_name);
  int_var1_parameter.setRange(constants::int_var1_min,constants::int_var1_max);

  ModularDevice::Parameter& int_var2_parameter = modular_device.createParameter(constants::int_var2_parameter_name);
  int_var2_parameter.setRange(constants::int_var2_min,constants::int_var2_max);

  // Methods
  ModularDevice::Method& execute_standalone_callback_method = modular_device.createMethod(constants::execute_standalone_callback_method_name);
  execute_standalone_callback_method.attachCallback(callbacks::executeStandaloneCallbackCallback);

  ModularDevice::Method& get_dsp_var1_method = modular_device.createMethod(constants::get_dsp_var1_method_name);
  get_dsp_var1_method.attachCallback(callbacks::getDspVar1Callback);

  ModularDevice::Method& set_dsp_var1_method = modular_device.createMethod(constants::set_dsp_var1_method_name);
  set_dsp_var1_method.attachCallback(callbacks::setDspVar1Callback);
  set_dsp_var1_method.addParameter(dsp_var1_parameter);

  ModularDevice::Method& get_int_var1_method = modular_device.createMethod(constants::get_int_var1_method_name);
  get_int_var1_method.attachCallback(callbacks::getIntVar1Callback);

  ModularDevice::Method& set_int_var1_method = modular_device.createMethod(constants::set_int_var1_method_name);
  set_int_var1_method.attachCallback(callbacks::setIntVar1Callback);
  set_int_var1_method.addParameter(int_var1_parameter);

  ModularDevice::Method& get_int_var2_method = modular_device.createMethod(constants::get_int_var2_method_name);
  get_int_var2_method.attachCallback(callbacks::getIntVar2Callback);

  ModularDevice::Method& set_int_var2_method = modular_device.createMethod(constants::set_int_var2_method_name);
  set_int_var2_method.attachCallback(callbacks::setIntVar2Callback);
  set_int_var2_method.addParameter(int_var2_parameter);

  // Start ModularDevice Server
  modular_device.startServer(constants::baudrate);

  // Standalone Interface
  standalone_interface_.setup(constants::frame_name_array,constants::FRAME_COUNT);

  // Display Labels
  Standalone::DisplayLabel& dsp_lbl0 = standalone_interface_.createDisplayLabel();
  dsp_lbl0.setDisplayPosition(constants::dsp_lbl0_display_position);
  dsp_lbl0.setConstantString(constants::dsp_lbl0_string);
  dsp_lbl0.setRightJustify();

  Standalone::DisplayLabel& dsp_lbl1 = standalone_interface_.createDisplayLabel();
  dsp_lbl1.setDisplayPosition(constants::dsp_lbl1_display_position);
  dsp_lbl1.setConstantString(constants::dsp_lbl1_string);
  dsp_lbl1.setRightJustify();

  Standalone::DisplayLabel& dsp_lbl2 = standalone_interface_.createDisplayLabel();
  dsp_lbl2.setDisplayPosition(constants::dsp_lbl2_display_position);
  dsp_lbl2.setConstantString(constants::dsp_lbl2_string);
  dsp_lbl2.setRightJustify();

  Standalone::DisplayLabel& dsp_lbl3 = standalone_interface_.createDisplayLabel();
  dsp_lbl3.setDisplayPosition(constants::dsp_lbl3_display_position);
  dsp_lbl3.setConstantString(constants::dsp_lbl3_string);
  dsp_lbl3.setRightJustify();

  // Display Variables
  dsp_var1_ptr_ = &(standalone_interface_.createDisplayVariable());
  dsp_var1_ptr_->setDisplayPosition(constants::dsp_var1_display_position);
  dsp_var1_ptr_->setValue(constants::dsp_var1_default_value);

  // Interactive Variables
  Standalone::InteractiveVariable& inc_var = standalone_interface_.createIncrementVariable();
  inc_var.setDisplayPosition(constants::inc_var_display_position);

  int_var1_ptr_ = &(standalone_interface_.createInteractiveVariable());
  int_var1_ptr_->setDisplayPosition(constants::int_var1_display_position);
  int_var1_ptr_->setRange(constants::int_var1_min,constants::int_var1_max);

  int_var2_ptr_ = &(standalone_interface_.createInteractiveVariable());
  int_var2_ptr_->setDisplayPosition(constants::int_var2_display_position);
  int_var2_ptr_->setRange(constants::int_var2_min,constants::int_var2_max);

  // All Frames
  dsp_lbl1.addToAllFrames();
  dsp_var1_ptr_->addToAllFrames();

  // Frame 0
  int frame = 0;
  dsp_lbl2.addToFrame(frame);
  int_var1_ptr_->addToFrame(frame);
  standalone_interface_.attachCallbackToFrame(callbacks::addIntVar1ToDspVar1Callback,frame);

  // Frame 1
  frame = 1;
  inc_var.addToFrame(frame);
  dsp_lbl0.addToFrame(frame);
  dsp_lbl3.addToFrame(frame);
  int_var2_ptr_->addToFrame(frame);
  standalone_interface_.attachCallbackToFrame(callbacks::subIntVar2FromDspVar1Callback,frame);

  // Enable Standalone Interface
  standalone_interface_.enable();
}

void Controller::update()
{
  modular_device.handleServerRequests();
  standalone_interface_.update();
}

void Controller::executeStandaloneCallback()
{
  standalone_interface_.executeCurrentFrameCallback();
}

int Controller::getDspVar1()
{
  return dsp_var1_ptr_->getValue();
}

void Controller::setDspVar1(int value)
{
  dsp_var1_ptr_->setValue(value);
}

int Controller::getIntVar1()
{
  return int_var1_ptr_->getValue();
}

void Controller::setIntVar1(int value)
{
  int_var1_ptr_->setValue(value);
}

int Controller::getIntVar2()
{
  return int_var2_ptr_->getValue();
}

void Controller::setIntVar2(int value)
{
  int_var2_ptr_->setValue(value);
}

Controller controller;
