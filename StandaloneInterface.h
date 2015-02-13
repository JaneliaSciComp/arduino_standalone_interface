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
typedef void(*Callback)();

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
                      const int led_pwr_pin,
                      const int update_period);
  void setup(const uint8_t frame_count);
  void setup(const _FLASH_STRING frame_name_array[],
             const uint8_t frame_count);
  void enable();
  void disable();
  void update();
  DisplayLabel& createDisplayLabel();
  DisplayVariable& createDisplayVariable();
  InteractiveVariable& createInteractiveVariable();
  void attachCallbackToFrame(Callback callback, uint8_t frame);
  void executeCurrentFrameCallback();
private:
  Server server_;
};
}
#endif
