// ----------------------------------------------------------------------------
// Variable.h
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
class Variable
{
public:
  Variable();
  void setDisplayPosition(const uint8_t display_position);
  uint8_t getDisplayPosition();
  void setDisplayWidth(const uint8_t display_width=3);
  uint8_t getDisplayWidth();
  void setLeftJustify();
  void setRightJustify();
  boolean checkLeftJustify();
  void setValue(uint8_t value);
  uint8_t getValue();
private:
  uint8_t display_position_;
  uint8_t display_width_;
  boolean left_justify_;
  uint8_t value_;
};
}
#endif
