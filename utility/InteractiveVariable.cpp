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
  min_ = 0;
  max_ = 255;
  value_dirty_ = true;
}

void InteractiveVariable::setRange(const uint8_t min, const uint8_t max)
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

uint8_t InteractiveVariable::getMin()
{
  return min_;
}

uint8_t InteractiveVariable::getMax()
{
  return max_;
}

void InteractiveVariable::setValue(uint8_t value)
{
  Variable::setValue(wrapValue(value));
  value_dirty_ = true;
}

void InteractiveVariable::updateWithEncoderValue(uint8_t value)
{
  Variable::setValue(wrapValue(value));
}

boolean InteractiveVariable::checkValueDirty()
{
  return value_dirty_;
}

void InteractiveVariable::clearValueDirty()
{
  value_dirty_ = false;
}

uint8_t InteractiveVariable::wrapValue(int value)
{
  if ((value >= min_) && (value <= max_))
  {
    return value;
  }
  else
  {
    value_dirty_ = true;
    int range = max_ - min_ + 1;
    if (value < min_)
        value += range*((min_ - value)/range + 1);
    return min_ + (value - min_)%range;
  }
}
}
