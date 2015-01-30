// ----------------------------------------------------------------------------
// InteractiveVariable.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _VARIABLE_H_
#define _VARIABLE_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


namespace Standalone
{
class InteractiveVariable
{
public:
  InteractiveVariable();
  void setDisplayPosition(const uint8_t display_position);
  uint8_t getDisplayPosition();
  void setDisplayWidth(const uint8_t display_width=3);
  uint8_t getDisplayWidth();
  void setLeftJustify();
  void setRightJustify();
  boolean checkLeftJustify();
  void setRange(const uint8_t min, const uint8_t max);
  uint8_t getMin();
  uint8_t getMax();
  void setValue(uint8_t value);
  uint8_t getValue();
private:
  uint8_t display_position_;
  uint8_t display_width_;
  boolean left_justify_;
  uint8_t min_;
  uint8_t max_;
  uint8_t value_;
  boolean value_dirty_;
  void updateWithEncoderValue(uint8_t value);
  boolean checkValueDirty();
  void clearValueDirty();
  uint8_t wrapValue(int value);
  friend class Server;
};
}
#endif
