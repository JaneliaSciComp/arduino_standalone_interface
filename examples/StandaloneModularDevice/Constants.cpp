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

const int enc_a_pin = 18;
const int enc_b_pin = 2;
const int enc_btn_pin = 19;
const int enc_btn_int = 4;
const int btn_pin = 21;
const int btn_int = 2;
const int led_pwr_pin = 17;
const int standalone_update_period = 300;

const uint8_t dsp_lbl1_display_position = 48;
const uint8_t dsp_lbl2_display_position = 68;
const uint8_t dsp_lbl3_display_position = 68;

const uint8_t dsp_var1_display_position = 51;
const int dsp_var1_default_value = 11;
const int dsp_var1_min = -32768;
const int dsp_var1_max = 32767;

const uint8_t int_var1_display_position = 71;
const uint8_t int_var1_min = 7;
const uint8_t int_var1_max = 38;

const uint8_t int_var2_display_position = 71;
const uint8_t int_var2_min = 66;
const uint8_t int_var2_max = 199;

FLASH_STRING(device_name,"standalone_modular_device");
FLASH_STRING(dsp_lbl1_string,"dsp_var1");
FLASH_STRING(dsp_lbl2_string,"int_var1");
FLASH_STRING(dsp_lbl3_string,"int_var2");
FLASH_STRING(execute_standalone_callback_method_name,"executeStandaloneCallback");
FLASH_STRING(get_dsp_var1_method_name,"getDspVar1");
FLASH_STRING(set_dsp_var1_method_name,"setDspVar1");
FLASH_STRING(get_int_var1_method_name,"getIntVar1");
FLASH_STRING(set_int_var1_method_name,"setIntVar1");
FLASH_STRING(get_int_var2_method_name,"getIntVar2");
FLASH_STRING(set_int_var2_method_name,"setIntVar2");
FLASH_STRING(dsp_var1_parameter_name,"dsp_var1");
FLASH_STRING(int_var1_parameter_name,"int_var1");
FLASH_STRING(int_var2_parameter_name,"int_var2");

FLASH_STRING(frame0_name,"dsp_var1 += int_var1");
FLASH_STRING(frame1_name,"dsp_var1 -= int_var2");
const _FLASH_STRING frame_name_array[] =
  {
    frame0_name,
    frame1_name,
  };
}
