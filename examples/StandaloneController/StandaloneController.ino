#include "Streaming.h"
#include "NewhavenDisplay.h"
#include "Encoder.h"
#include "StandardCplusplus.h"
#include "Flash.h"
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

const uint8_t DISPLAY_LABEL1_DISPLAY_POSITION = 0;
FLASH_STRING(DISPLAY_LABEL1_STRING,"tester");

const uint8_t DISPLAY_VAR1_DISPLAY_POSITION = 9;
const uint8_t DISPLAY_VAR1_DEFAULT_VALUE = 77;

const uint8_t INTERACTIVE_VAR1_DISPLAY_POSITION = 29;
const uint8_t INTERACTIVE_VAR1_DEFAULT_VALUE = 11;
const uint8_t INTERACTIVE_VAR1_MIN = 7;
const uint8_t INTERACTIVE_VAR1_MAX = 38;

const uint8_t INTERACTIVE_VAR2_DISPLAY_POSITION = 49;
const uint8_t INTERACTIVE_VAR2_MIN = 7;
const uint8_t INTERACTIVE_VAR2_MAX = 38;

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

DisplayLabel& display_label1 = standalone_interface.createDisplayLabel(DISPLAY_LABEL1_STRING);
DisplayVariable& display_var1 = standalone_interface.createDisplayVariable();
InteractiveVariable& interactive_var1 = standalone_interface.createInteractiveVariable();
InteractiveVariable& interactive_var2 = standalone_interface.createInteractiveVariable();
unsigned long time_last_serial_update = 0;

void setup()
{
  display_label1.setDisplayPosition(DISPLAY_LABEL1_DISPLAY_POSITION);

  display_var1.setDisplayPosition(DISPLAY_VAR1_DISPLAY_POSITION);
  display_var1.setValue(DISPLAY_VAR1_DEFAULT_VALUE);

  interactive_var1.setDisplayPosition(INTERACTIVE_VAR1_DISPLAY_POSITION);
  interactive_var1.setRange(INTERACTIVE_VAR1_MIN,INTERACTIVE_VAR1_MAX);
  interactive_var1.setRightJustify();
  interactive_var1.setValue(INTERACTIVE_VAR1_DEFAULT_VALUE);

  interactive_var2.setDisplayPosition(INTERACTIVE_VAR2_DISPLAY_POSITION);
  interactive_var2.setRange(INTERACTIVE_VAR2_MIN,INTERACTIVE_VAR2_MAX);
  interactive_var2.setLeftJustify();

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
    Serial << "display_var1: " << display_var1.getValue() << endl;
    Serial << "interactive_var1: " << interactive_var1.getValue() << endl;
    Serial << "interactive_var2: " << interactive_var2.getValue() << endl;
    display_var1.setValue(display_var1.getValue()+2);
    interactive_var1.setValue(interactive_var1.getValue()+1);
    interactive_var2.setValue(interactive_var2.getValue()-1);
  }
}
