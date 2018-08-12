// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <ConstantVariable.h>


namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{SAVED_VARIABLE_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=3};
enum{METHOD_COUNT_MAX=7};

enum{DISPLAY_LABEL_COUNT_MAX=4};
enum{DISPLAY_VARIABLE_COUNT_MAX=1};
enum{INTERACTIVE_VARIABLE_COUNT_MAX=3};
enum{FRAME_COUNT=2};

extern const unsigned int baud;

extern const unsigned int model_number;

extern const unsigned char firmware_major;
extern const unsigned char firmware_minor;
extern const unsigned char firmware_patch;

extern HardwareSerial& display_serial;

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int lights_pin;
extern const int standalone_update_period;

extern const uint8_t dsp_lbl0_display_position;
extern const uint8_t dsp_lbl1_display_position;
extern const uint8_t dsp_lbl2_display_position;
extern const uint8_t dsp_lbl3_display_position;

extern const uint8_t dsp_var1_display_position;
extern const int dsp_var1_default_value;
extern const int dsp_var1_min;
extern const int dsp_var1_max;

extern const uint8_t inc_var_display_position;

extern const uint8_t int_var1_display_position;
extern const int int_var1_min;
extern const int int_var1_max;
extern const int int_var1_default_value;

extern const uint8_t int_var2_display_position;
extern const int int_var2_min;
extern const int int_var2_max;
extern const int int_var2_default_value;

extern ConstantString device_name;

extern ConstantString dsp_var1_parameter_name;
extern ConstantString int_var1_parameter_name;
extern ConstantString int_var2_parameter_name;

extern ConstantString get_dsp_var1_method_name;
extern ConstantString set_dsp_var1_method_name;
extern ConstantString get_int_var1_method_name;
extern ConstantString set_int_var1_method_name;
extern ConstantString get_int_var2_method_name;
extern ConstantString set_int_var2_method_name;

extern ConstantString dsp_lbl0_string;
extern ConstantString dsp_lbl1_string;
extern ConstantString dsp_lbl2_string;
extern ConstantString dsp_lbl3_string;

extern ConstantString execute_standalone_callback_method_name;

extern ConstantString frame0_name;
extern ConstantString frame1_name;
extern const ConstantString frame_name_array[FRAME_COUNT];
}
#endif
