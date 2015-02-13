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
enum {FRAME_COUNT=2};

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

extern const uint8_t dsp_lbl1_display_position;
extern const uint8_t dsp_lbl2_display_position;
extern const uint8_t dsp_lbl3_display_position;

extern const uint8_t dsp_var1_display_position;
extern const int dsp_var1_default_value;
extern const int dsp_var1_min;
extern const int dsp_var1_max;

extern const uint8_t int_var1_display_position;
extern const uint8_t int_var1_min;
extern const uint8_t int_var1_max;

extern const uint8_t int_var2_display_position;
extern const uint8_t int_var2_min;
extern const uint8_t int_var2_max;

extern _FLASH_STRING device_name;
extern _FLASH_STRING dsp_lbl1_string;
extern _FLASH_STRING dsp_lbl2_string;
extern _FLASH_STRING dsp_lbl3_string;
extern _FLASH_STRING execute_standalone_callback_method_name;
extern _FLASH_STRING get_dsp_var1_method_name;
extern _FLASH_STRING set_dsp_var1_method_name;
extern _FLASH_STRING get_int_var1_method_name;
extern _FLASH_STRING set_int_var1_method_name;
extern _FLASH_STRING get_int_var2_method_name;
extern _FLASH_STRING set_int_var2_method_name;
extern _FLASH_STRING dsp_var1_parameter_name;
extern _FLASH_STRING int_var1_parameter_name;
extern _FLASH_STRING int_var2_parameter_name;

extern _FLASH_STRING frame0_name;
extern _FLASH_STRING frame1_name;
extern const _FLASH_STRING frame_name_array[FRAME_COUNT];
}
#endif
