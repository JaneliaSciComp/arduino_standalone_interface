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


class InteractiveVariable
{
public:
  InteractiveVariable();
  void setDisplayPosition(const uint8_t display_position);
  uint8_t getDisplayPosition();
  void setRange(const uint8_t min, const uint8_t max);
  uint8_t getMin();
  uint8_t getMax();
  uint8_t value;
private:
  uint8_t display_position_;
  uint8_t min_;
  uint8_t max_;
};
#endif
