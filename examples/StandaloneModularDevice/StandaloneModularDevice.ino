#include <EEPROM.h>
#include "Streaming.h"
#include "JsonParser.h"
#include "StandardCplusplus.h"
#include "MemoryFree.h"
#include "Flash.h"
#include "ModularDevice.h"
#include "NewhavenDisplay.h"
#include "Encoder.h"
#include "StandaloneInterface.h"
#include "Constants.h"
#include "Callbacks.h"

// See README.md for more information

using namespace Standalone;
using namespace ModularDevice;

HardwareSerial DISPLAY_SERIAL = Serial3;

StandaloneInterface standalone_interface(DISPLAY_SERIAL,
                                         constants::enc_a_pin,
                                         constants::enc_b_pin,
                                         constants::enc_btn_pin,
                                         constants::enc_btn_int,
                                         constants::btn_pin,
                                         constants::btn_int,
                                         constants::standalone_update_period);

InteractiveVariable& counter1 = standalone_interface.createInteractiveVariable();
InteractiveVariable& counter2 = standalone_interface.createInteractiveVariable();
unsigned long time_last_serial_update = 0;

void setup()
{
  counter1.setDisplayPosition(constants::counter1_display_position);
  counter1.setRange(constants::counter1_min,constants::counter1_max);
  counter1.setRightJustify();

  counter2.setDisplayPosition(constants::counter2_display_position);
  counter2.setRange(constants::counter2_min,constants::counter2_max);
  counter2.setLeftJustify();

  standalone_interface.enable();

  modular_device.startServer(constants::baudrate);
}

void loop()
{
  standalone_interface.update();
  modular_device.handleServerRequests();
}
