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
#include "StandaloneController.h"

// See README.md for more information

void setup()
{
  standalone_controller.init();
  modular_device.startServer(constants::baudrate);
}

void loop()
{
  standalone_controller.update();
  modular_device.handleServerRequests();
}
