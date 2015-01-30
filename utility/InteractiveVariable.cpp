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
  display_position_ = 0;
  setDisplayWidth();
  setLeftJustify();
  min_ = 0;
  max_ = 255;
  value_ = 0;
  value_dirty_ = true;
}

void InteractiveVariable::setDisplayPosition(const uint8_t display_position)
{
  display_position_ = display_position;
}

uint8_t InteractiveVariable::getDisplayPosition()
{
  return display_position_;
}

void InteractiveVariable::setDisplayWidth(const uint8_t display_width)
{
  display_width_ = display_width;
}

uint8_t InteractiveVariable::getDisplayWidth()
{
  return display_width_;
}

void InteractiveVariable::setLeftJustify()
{
  left_justify_ = true;
}

void InteractiveVariable::setRightJustify()
{
  left_justify_ = false;
}

boolean InteractiveVariable::checkLeftJustify()
{
  return left_justify_;
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
  if (value_ < min_)
  {
    setValue(min_);
  }
  else if (value_ > max_)
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

void InteractiveVariable::updateWithEncoderValue(uint8_t value)
{
  value_ = wrapValue(value);
}

void InteractiveVariable::setValue(uint8_t value)
{
  value_ = wrapValue(value);
  value_dirty_ = true;
}

uint8_t InteractiveVariable::getValue()
{
  return value_;
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
