// ----------------------------------------------------------------------------
// DisplayVariable.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_DISPLAY_VARIABLE_H_
#define _STANDALONE_DISPLAY_VARIABLE_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "DisplayElement.h"


namespace Standalone
{
class DisplayVariable : public DisplayElement
{
public:
  DisplayVariable();
  void setValue(uint8_t value);
  uint8_t getValue();
  String getDisplayString();
private:
  uint8_t value_;
};
}
#endif
