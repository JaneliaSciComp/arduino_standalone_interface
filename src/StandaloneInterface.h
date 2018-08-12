// ----------------------------------------------------------------------------
// StandaloneInterface.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef STANDALONE_INTERFACE_H
#define STANDALONE_INTERFACE_H
#include "StandaloneInterface/Server.h"


namespace Standalone
{
typedef void(*Callback)();

struct Configuration;

class StandaloneInterface
{
public:
  StandaloneInterface(Configuration configuration);
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
  InteractiveVariable& createIncrementVariable(int width_max=4);
  void attachCallbackToFrame(Callback callback, uint8_t frame);
  void executeCurrentFrameCallback();
private:
  Server server_;
};
}
#include "StandaloneInterface/StandaloneInterfaceDefinitions.h"

#endif
