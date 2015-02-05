// ----------------------------------------------------------------------------
// DisplayLabel.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _DISPLAY_LABEL_H_
#define _DISPLAY_LABEL_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Flash.h"
#include "DisplayElement.h"


namespace Standalone
{
class DisplayLabel : public DisplayElement
{
public:
  DisplayLabel(const _FLASH_STRING &label);
  String getDisplayString();
private:
  const _FLASH_STRING *label_ptr_;
};
}
#endif
