// ----------------------------------------------------------------------------
// Controller.cpp
//
// Authors:
// Peter Polidoro peter@polidoro.io
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
  modular_server_.setName(constants::device_name);
  modular_server_.setModelNumber(constants::model_number);
  modular_server_.setFirmwareVersion(constants::firmware_major,constants::firmware_minor,constants::firmware_patch);

  // Add Server Streams
  modular_server_.addServerStream(Serial);

  // Set Storage
  modular_server_.setSavedVariableStorage(saved_variables_);
  modular_server_.setParameterStorage(parameters_);
  modular_server_.setMethodStorage(methods_);

  // Saved Variables

  // Parameters
  ModularDevice::Parameter& dsp_var1_parameter = modular_server_.createParameter(constants::dsp_var1_parameter_name);
  dsp_var1_parameter.setRange(constants::dsp_var1_min,constants::dsp_var1_max);

  ModularDevice::Parameter& int_var1_parameter = modular_server_.createParameter(constants::int_var1_parameter_name);
  int_var1_parameter.setRange(constants::int_var1_min,constants::int_var1_max);

  ModularDevice::Parameter& int_var2_parameter = modular_server_.createParameter(constants::int_var2_parameter_name);
  int_var2_parameter.setRange(constants::int_var2_min,constants::int_var2_max);

  // Methods
  ModularDevice::Method& execute_standalone_callback_method = modular_server_.createMethod(constants::execute_standalone_callback_method_name);
  execute_standalone_callback_method.attachCallback(callbacks::executeStandaloneCallbackCallback);

  ModularDevice::Method& get_dsp_var1_method = modular_server_.createMethod(constants::get_dsp_var1_method_name);
  get_dsp_var1_method.attachCallback(callbacks::getDspVar1Callback);
  get_dsp_var1_method.setReturnTypeLong();

  ModularDevice::Method& set_dsp_var1_method = modular_server_.createMethod(constants::set_dsp_var1_method_name);
  set_dsp_var1_method.attachCallback(callbacks::setDspVar1Callback);
  set_dsp_var1_method.addParameter(dsp_var1_parameter);

  ModularDevice::Method& get_int_var1_method = modular_server_.createMethod(constants::get_int_var1_method_name);
  get_int_var1_method.attachCallback(callbacks::getIntVar1Callback);
  get_int_var1_method.setReturnTypeLong();

  ModularDevice::Method& set_int_var1_method = modular_server_.createMethod(constants::set_int_var1_method_name);
  set_int_var1_method.attachCallback(callbacks::setIntVar1Callback);
  set_int_var1_method.addParameter(int_var1_parameter);

  ModularDevice::Method& get_int_var2_method = modular_server_.createMethod(constants::get_int_var2_method_name);
  get_int_var2_method.attachCallback(callbacks::getIntVar2Callback);
  get_int_var2_method.setReturnTypeLong();

  ModularDevice::Method& set_int_var2_method = modular_server_.createMethod(constants::set_int_var2_method_name);
  set_int_var2_method.attachCallback(callbacks::setIntVar2Callback);
  set_int_var2_method.addParameter(int_var2_parameter);

  // Setup Streams
  Serial.begin(constants::baud);

  // Start Modular Device Server
  modular_server_.startServer();

  // Standalone Interface

  // Set Storage
  standalone_interface_.setDisplayLabelStorage(display_labels_);
  standalone_interface_.setDisplayVariableStorage(display_variables_);
  standalone_interface_.setInteractiveVariableStorage(interactive_variables_);

  // Setup
  standalone_interface_.setup(constants::frame_name_array);

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
  int_var1_ptr_->setValue(constants::int_var1_default_value);

  int_var2_ptr_ = &(standalone_interface_.createInteractiveVariable());
  int_var2_ptr_->setDisplayPosition(constants::int_var2_display_position);
  int_var2_ptr_->setRange(constants::int_var2_min,constants::int_var2_max);
  int_var2_ptr_->setValue(constants::int_var2_default_value);

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
  modular_server_.handleServerRequests();
  standalone_interface_.update();
}

ModularDevice::ModularServer& Controller::getModularServer()
{
  return modular_server_;
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
