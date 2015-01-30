#include "Streaming.h"
#include "NewhavenDisplay.h"
#include "Encoder.h"
#include "StandardCplusplus.h"
#include "StandaloneInterface.h"

// See README.md for more information

using namespace Standalone;

HardwareSerial DISPLAY_SERIAL = Serial3;
const int ENC_A_PIN = 2;
const int ENC_B_PIN = 3;
const int ENC_BTN_PIN = 19;
const int ENC_BTN_INT = 4;
const int BTN_PIN = 21;
const int BTN_INT = 2;
const int UPDATE_PERIOD = 300;

const uint8_t COUNTER1_DISPLAY_POSITION = 9;
const uint8_t COUNTER1_MIN = 7;
const uint8_t COUNTER1_MAX = 38;

const uint8_t COUNTER2_DISPLAY_POSITION = 29;
const uint8_t COUNTER2_MIN = 7;
const uint8_t COUNTER2_MAX = 38;

const int BAUDRATE = 9600;

const int SERIAL_UPDATE_PERIOD = 2000;

StandaloneInterface standalone_interface(DISPLAY_SERIAL,
                                         ENC_A_PIN,
                                         ENC_B_PIN,
                                         ENC_BTN_PIN,
                                         ENC_BTN_INT,
                                         BTN_PIN,
                                         BTN_INT,
                                         UPDATE_PERIOD);

InteractiveVariable& counter1 = standalone_interface.createInteractiveVariable();
InteractiveVariable& counter2 = standalone_interface.createInteractiveVariable();
unsigned long time_last_serial_update = 0;

void setup()
{
  counter1.setDisplayPosition(COUNTER1_DISPLAY_POSITION);
  counter1.setRange(COUNTER1_MIN,COUNTER1_MAX);
  counter1.setRightJustify();

  counter2.setDisplayPosition(COUNTER2_DISPLAY_POSITION);
  counter2.setRange(COUNTER2_MIN,COUNTER2_MAX);
  counter2.setLeftJustify();

  Serial.begin(BAUDRATE);
  standalone_interface.enable();
}

void loop()
{
  standalone_interface.update();
  unsigned long time_now = millis();
  if ((time_now - time_last_serial_update) > SERIAL_UPDATE_PERIOD)
  {
    time_last_serial_update = time_now;
    Serial << counter1.getValue() << endl;
  }
}
