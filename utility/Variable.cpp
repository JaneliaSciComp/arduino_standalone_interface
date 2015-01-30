// ----------------------------------------------------------------------------
// Variable.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Variable.h"


namespace Standalone
{
Variable::Variable()
{
  display_position_ = 0;
  setDisplayWidth();
  setLeftJustify();
  value_ = 0;
}

void Variable::setDisplayPosition(const uint8_t display_position)
{
  display_position_ = display_position;
}

uint8_t Variable::getDisplayPosition()
{
  return display_position_;
}

void Variable::setDisplayWidth(const uint8_t display_width)
{
  display_width_ = display_width;
}

uint8_t Variable::getDisplayWidth()
{
  return display_width_;
}

void Variable::setLeftJustify()
{
  left_justify_ = true;
}

void Variable::setRightJustify()
{
  left_justify_ = false;
}

boolean Variable::checkLeftJustify()
{
  return left_justify_;
}

void Variable::setValue(uint8_t value)
{
  value_ = value;
}

uint8_t Variable::getValue()
{
  return value_;
}
}
