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

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int standalone_update_period;

extern const uint8_t display_label1_display_position;

extern const uint8_t display_var1_display_position;
extern const uint8_t display_var1_default_value;

extern const uint8_t interactive_var1_display_position;
extern const uint8_t interactive_var1_min;
extern const uint8_t interactive_var1_max;

extern const uint8_t interactive_var2_display_position;
extern const uint8_t interactive_var2_min;
extern const uint8_t interactive_var2_max;

extern _FLASH_STRING device_name;
extern _FLASH_STRING display_label1_string;
}
#endif
