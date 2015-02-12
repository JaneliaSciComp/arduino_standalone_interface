// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Flash.h"

namespace constants
{
extern const int baudrate;

extern const int model_number;
extern const int firmware_number;

extern HardwareSerial display_serial;

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int led_pwr_pin;
extern const int standalone_update_period;

extern const uint8_t frame_count;

extern const uint8_t display_label1_display_position;
extern const uint8_t display_label2_display_position;
extern const uint8_t display_label3_display_position;

extern const int display_variable_min;
extern const int display_variable_max;

extern const uint8_t display_var1_display_position;
extern const int display_var1_default_value;

extern const uint8_t interactive_var1_display_position;
extern const uint8_t interactive_var1_min;
extern const uint8_t interactive_var1_max;

extern const uint8_t interactive_var2_display_position;
extern const uint8_t interactive_var2_min;
extern const uint8_t interactive_var2_max;

extern _FLASH_STRING device_name;
extern _FLASH_STRING display_label1_string;
extern _FLASH_STRING display_label2_string;
extern _FLASH_STRING display_label3_string;
extern _FLASH_STRING set_display_variable1_method_name;
extern _FLASH_STRING set_interactive_variable1_method_name;
extern _FLASH_STRING get_interactive_variable1_method_name;
extern _FLASH_STRING set_interactive_variable2_method_name;
extern _FLASH_STRING get_interactive_variable2_method_name;
extern _FLASH_STRING display_value_parameter_name;
extern _FLASH_STRING interactive_variable1_parameter_name;
extern _FLASH_STRING interactive_variable2_parameter_name;
}
#endif
