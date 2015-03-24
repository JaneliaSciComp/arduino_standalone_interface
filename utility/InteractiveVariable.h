// ----------------------------------------------------------------------------
// InteractiveVariable.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_INTERACTIVE_VARIABLE_H_
#define _STANDALONE_INTERACTIVE_VARIABLE_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "DisplayVariable.h"

namespace Standalone
{
class InteractiveVariable : public DisplayVariable
{
public:
  InteractiveVariable();
  void setRange(const uint8_t min, const uint8_t max);
  uint8_t getMin();
  uint8_t getMax();
  void setValue(uint8_t value);
  virtual void setFlashStringArray(const ConstantString string_array[],
                                   const uint8_t string_count);
private:
  static const uint8_t DISPLAY_WIDTH_DEFAULT=3;
  uint8_t min_;
  uint8_t max_;
  boolean value_dirty_;
  void updateWithEncoderValue(int value);
  boolean checkValueDirty();
  void clearValueDirty();
  uint8_t wrapValue(int value);
  friend class Server;
};
}
#endif
