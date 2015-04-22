// ----------------------------------------------------------------------------
// InteractiveVariable.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "InteractiveVariable.h"


namespace Standalone
{
InteractiveVariable::InteractiveVariable()
{
  min_ = -32768;
  max_ = 32767;
  setDisplayWidth(DISPLAY_WIDTH_DEFAULT);
  value_dirty_ = true;
}

void InteractiveVariable::setRange(const int min, const int max)
{
  if (min_ < max_)
  {
    min_ = min;
    max_ = max;
  }
  else
  {
    min_ = max;
    max_ = min;
  }
  if (getValue() < min_)
  {
    setValue(min_);
  }
  else if (getValue() > max_)
  {
    setValue(max_);
  }
}

void InteractiveVariable::trimDisplayWidthUsingRange()
{
  uint8_t display_width = 1;
  if (min_ < 0)
  {
    ++display_width;
  }
  int max_temp = max_;
  while ((max_temp/10 > 0) && (display_width <= DISPLAY_WIDTH_DEFAULT))
  {
    ++display_width;
    max_temp /= 10;
  }
  setDisplayWidth(display_width);
}

int InteractiveVariable::getMin()
{
  return min_;
}

int InteractiveVariable::getMax()
{
  return max_;
}

void InteractiveVariable::setValue(int value)
{
  DisplayVariable::setValue(wrapValue(value));
  value_dirty_ = true;
}

void InteractiveVariable::updateWithEncoderValue(int value)
{
  DisplayVariable::setValue(wrapValue(value));
}

boolean InteractiveVariable::checkValueDirty()
{
  return value_dirty_;
}

void InteractiveVariable::clearValueDirty()
{
  value_dirty_ = false;
}

int InteractiveVariable::wrapValue(int value)
{
  if ((value >= min_) && (value <= max_))
  {
    return value;
  }
  else
  {
    value_dirty_ = true;
    unsigned int range = (max_ - min_) + 1;
    if (value < min_)
    {
      value += range*((min_ - value)/range + 1);
    }
    return min_ + (value - min_)%range;
  }
}

void InteractiveVariable::setConstantStringArray(const ConstantString string_array[],
                                                 const uint8_t string_count)
{
  DisplayVariable::setConstantStringArray(string_array,string_count);
  setRange(0,string_count-1);
}
}
