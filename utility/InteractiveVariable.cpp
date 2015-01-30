// ----------------------------------------------------------------------------
// InteractiveVariable.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "InteractiveVariable.h"


InteractiveVariable::InteractiveVariable()
{
  display_position_ = 0;
  min_ = 0;
  max_ = 255;
  value_ = 0;
}

void InteractiveVariable::setDisplayPosition(const uint8_t display_position)
{
  display_position_ = display_position;
}

uint8_t InteractiveVariable::getDisplayPosition()
{
  return display_position_;
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
    value_ = min_;
  }
  else if (value_ > max_)
  {
    value_ = max_;
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
  value_ = value;
}

uint8_t InteractiveVariable::getValue()
{
  return value_;
}
