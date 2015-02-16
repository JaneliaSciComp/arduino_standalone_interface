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
#include "Flash.h"
#include "DisplayElement.h"


namespace Standalone
{
class DisplayVariable : public DisplayElement
{
public:
  DisplayVariable();
  void setValue(int value);
  int getValue();
  String getDisplayString();
  virtual void setFlashStringArray(const _FLASH_STRING string_array[],
                                   const uint8_t string_count);
private:
  static const uint8_t DISPLAY_WIDTH_DEFAULT=6;
  int value_;
  const _FLASH_STRING *string_array_;
  uint8_t string_count_;
};
}
#endif
