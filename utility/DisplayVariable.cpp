// ----------------------------------------------------------------------------
// DisplayVariable.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "DisplayVariable.h"


namespace Standalone
{
DisplayVariable::DisplayVariable()
{
  value_ = 0;
}

void DisplayVariable::setValue(uint8_t value)
{
  value_ = value;
}

uint8_t DisplayVariable::getValue()
{
  return value_;
}

String DisplayVariable::getDisplayString()
{
  return String(value_);
}
}
