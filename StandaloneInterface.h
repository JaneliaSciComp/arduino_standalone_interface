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
                      const int lights_pin,
                      const int update_period);
  template <size_t FRAME_COUNT>
  void setup(const ConstantString (&frame_names)[FRAME_COUNT]);
  void enable();
  void disable();
  bool update();
  template <size_t MAX_SIZE>
  void setDisplayLabelStorage(DisplayLabel (&display_labels)[MAX_SIZE]);
  DisplayLabel& createDisplayLabel();
  template <size_t MAX_SIZE>
  void setDisplayVariableStorage(DisplayVariable (&display_variables)[MAX_SIZE]);
  DisplayVariable& createDisplayVariable();
  template <size_t MAX_SIZE>
  void setInteractiveVariableStorage(InteractiveVariable (&interactive_variables)[MAX_SIZE]);
  InteractiveVariable& createInteractiveVariable();
  InteractiveVariable& createIncrementVariable();
  void attachCallbackToFrame(Callback callback, uint8_t frame);
  void executeCurrentFrameCallback();
private:
  Server server_;
};
}
#include "StandaloneInterfaceDefinitions.h"

#endif
