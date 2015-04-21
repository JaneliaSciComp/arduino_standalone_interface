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
  string_array_ = NULL;
  string_count_ = 0;
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
  if ((string_count_ > 0) && (value_ < string_count_))
  {
    // setDisplayWidth(string_array_[value_].length());
    char display_char_array[DISPLAY_WIDTH_MAX+1];
    string_array_[value_].copy(display_char_array);
    return String(display_char_array);
  }
  else
  {
    return String(value_);
  }
}

void DisplayVariable::setConstantStringArray(const ConstantString string_array[],
                                             const uint8_t string_count)
{
  string_array_ = string_array;
  string_count_ = string_count;
  uint8_t string_length_max = 0;
  for (int index=0; index<string_count; index++)
  {
    int string_length = string_array_[index].length();
    if (string_length > string_length_max)
    {
      string_length_max = string_length;
    }
  }
  if (string_length_max > 0)
  {
    setDisplayWidth(string_length_max);
  }
}
}
