#include "Streaming.h"
#include "NewhavenDisplay.h"
#include "Encoder.h"
#include "StandaloneInterface.h"

// See README.md for more information

HardwareSerial DISPLAY_SERIAL = Serial3;
const int ENC_A_PIN = 2;
const int ENC_B_PIN = 3;
const int ENC_BTN_PIN = 19;
const int ENC_BTN_INT = 4;
const int BTN_PIN = 21;
const int BTN_INT = 2;
const int UPDATE_PERIOD = 300;

const int COUNTER_DISPLAY_POSITION = 40;
const int COUNTER_MIN = 7;
const int COUNTER_MAX = 38;

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

InteractiveVariable counter = standalone_interface.createInteractiveVariable();
counter.setDisplayPosition(COUNTER_DISPLAY_POSITION);
counter.setRange(COUNTER_MIN,COUNTER_MAX);

unsigned long time_last_serial_update = 0;

void setup()
{
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
    Serial << counter.value << endl;
    counter.value += 1;
  }
}
