// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace constants
{
const int baudrate = 9600;

const int model_number = 1003;
const int firmware_number = 1;

HardwareSerial display_serial = Serial3;

const int enc_a_pin = 2;
const int enc_b_pin = 3;
const int enc_btn_pin = 19;
const int enc_btn_int = 4;
const int btn_pin = 21;
const int btn_int = 2;
const int led_pwr_pin = 18;
const int standalone_update_period = 300;

const uint8_t display_label1_display_position = 0;
const uint8_t display_label2_display_position = 20;
const uint8_t display_label3_display_position = 40;

const uint8_t display_variable_min = 0;
const uint8_t display_variable_max = 255;

const uint8_t display_var1_display_position = 9;
const uint8_t display_var1_default_value = 11;

const uint8_t interactive_var1_display_position = 29;
const uint8_t interactive_var1_min = 7;
const uint8_t interactive_var1_max = 38;

const uint8_t interactive_var2_display_position = 49;
const uint8_t interactive_var2_min = 66;
const uint8_t interactive_var2_max = 199;

FLASH_STRING(device_name,"standalone_modular_device");
FLASH_STRING(display_label1_string,"dsp_var1");
FLASH_STRING(display_label2_string,"int_var1");
FLASH_STRING(display_label3_string,"int_var2");
FLASH_STRING(set_display_variable1_method_name,"setDisplayVariable1");
FLASH_STRING(set_interactive_variable1_method_name,"setInteractiveVariable1");
FLASH_STRING(get_interactive_variable1_method_name,"getInteractiveVariable1");
FLASH_STRING(set_interactive_variable2_method_name,"setInteractiveVariable2");
FLASH_STRING(get_interactive_variable2_method_name,"getInteractiveVariable2");
FLASH_STRING(display_value_parameter_name,"display_value");
FLASH_STRING(interactive_variable1_parameter_name,"interactive_variable1");
FLASH_STRING(interactive_variable2_parameter_name,"interactive_variable2");
}
