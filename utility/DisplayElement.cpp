// ----------------------------------------------------------------------------
// DisplayElement.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "DisplayElement.h"


namespace Standalone
{
DisplayElement::DisplayElement()
{
  display_position_ = 0;
  setDisplayWidth();
  setLeftJustify();
}

void DisplayElement::setDisplayPosition(const uint8_t display_position)
{
  display_position_ = display_position;
}

uint8_t DisplayElement::getDisplayPosition()
{
  return display_position_;
}

void DisplayElement::setDisplayWidth(const uint8_t display_width)
{
  display_width_ = display_width;
}

uint8_t DisplayElement::getDisplayWidth()
{
  return display_width_;
}

void DisplayElement::setLeftJustify()
{
  left_justify_ = true;
}

void DisplayElement::setRightJustify()
{
  left_justify_ = false;
}

boolean DisplayElement::checkLeftJustify()
{
  return left_justify_;
}

void DisplayElement::updateOnDisplay(NewhavenDisplay &display)
{
  display.setCursor(getDisplayPosition());
  uint8_t display_width = getDisplayWidth();
  if (checkLeftJustify())
  {
    display.printPadRight(getDisplayString(),display_width);
  }
  else
  {
    display.printPadLeft(getDisplayString(),display_width);
  }
}
}
