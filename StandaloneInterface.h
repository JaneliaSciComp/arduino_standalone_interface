// ----------------------------------------------------------------------------
// StandaloneInterface.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef STANDALONE_INTERFACE_H
#define STANDALONE_INTERFACE_H
#include "utility/Server.h"


namespace Standalone
{
class StandaloneInterface
{
public:
  StandaloneInterface(HardwareSerial &display_serial,
                      const int enc_a_pin,
                      const int enc_b_pin,
                      const int enc_btn_pin,
                      const int enc_btn_int,
                      const int btn_pin,
                      const int btn_int,
                      const int update_period);
  void setup();
  void enable();
  void disable();
  void update();
  DisplayLabel& createDisplayLabel();
  DisplayVariable& createDisplayVariable();
  InteractiveVariable& createInteractiveVariable();
private:
  Server server_;
};
}
#endif
