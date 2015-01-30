// ----------------------------------------------------------------------------
// InteractiveVariable.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _INTERACTIVE_VARIABLE_H_
#define _INTERACTIVE_VARIABLE_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Variable.h"

namespace Standalone
{
class InteractiveVariable : public Variable
{
public:
  InteractiveVariable();
  void setRange(const uint8_t min, const uint8_t max);
  uint8_t getMin();
  uint8_t getMax();
  void setValue(uint8_t value);
private:
  uint8_t min_;
  uint8_t max_;
  boolean value_dirty_;
  void updateWithEncoderValue(uint8_t value);
  boolean checkValueDirty();
  void clearValueDirty();
  uint8_t wrapValue(int value);
  friend class Server;
};
}
#endif
