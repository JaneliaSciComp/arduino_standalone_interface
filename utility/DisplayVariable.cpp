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
  setDisplayWidth(DISPLAY_WIDTH_DEFAULT);
}

void DisplayVariable::setValue(int value)
{
  value_ = value;
}

int DisplayVariable::getValue()
{
  return value_;
}

String DisplayVariable::getDisplayString()
{
  return String(value_);
}
}
