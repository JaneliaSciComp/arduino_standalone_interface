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

const int enc_a_pin = 2;
const int enc_b_pin = 3;
const int enc_btn_pin = 19;
const int enc_btn_int = 4;
const int btn_pin = 21;
const int btn_int = 2;
const int standalone_update_period = 300;

const uint8_t counter1_display_position = 9;
const uint8_t counter1_min = 7;
const uint8_t counter1_max = 38;

const uint8_t counter2_display_position = 29;
const uint8_t counter2_min = 7;
const uint8_t counter2_max = 38;

FLASH_STRING(device_name,"standalone_modular_device");
}
