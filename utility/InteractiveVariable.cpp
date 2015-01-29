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
  value = 0;
}

uint8_t InteractiveVariable::setDisplayPosition(const uint8_t display_position)
{
  display_position_ = display_position;
}

uint8_t InteractiveVariable::getDisplayPosition()
{
  return display_position_;
}

uint8_t InteractiveVariable::setRange(const uint8_t min, const uint8_t max)
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
  if (value < min_)
  {
    value = min_;
  }
  else if (value > max_)
  {
    value = max_;
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
