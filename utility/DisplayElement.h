// ----------------------------------------------------------------------------
// DisplayElement.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_DISPLAY_ELEMENT_H_
#define _STANDALONE_DISPLAY_ELEMENT_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "NewhavenDisplay.h"


namespace Standalone
{

class DisplayElement
{
public:
  DisplayElement();
  void setDisplayPosition(const uint8_t display_position);
  uint8_t getDisplayPosition();
  void setDisplayWidth(const uint8_t display_width=3);
  uint8_t getDisplayWidth();
  void setLeftJustify();
  void setRightJustify();
  boolean checkLeftJustify();
  virtual String getDisplayString() {};
  void updateOnDisplay(NewhavenDisplay &display);
private:
  uint8_t display_position_;
  uint8_t display_width_;
  boolean left_justify_;
};
}
#endif
