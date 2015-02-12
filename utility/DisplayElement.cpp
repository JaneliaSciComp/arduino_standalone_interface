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
  frames_ = 0;
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
  if (display_width <= DISPLAY_WIDTH_MAX)
  {
    display_width_ = display_width;
  }
  else
  {
    display_width_ = DISPLAY_WIDTH_MAX;
  }
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

void DisplayElement::updateOnDisplay(NewhavenDisplay &display, int frame)
{
  if (inFrame(frame))
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

void DisplayElement::addToFrame(int frame)
{
  frames_t bit = 1;
  frames_ |= (1 << frame);
}

void DisplayElement::addToAllFrames()
{
  frames_t frames = 0;
  frames_ = frames - 1;
}

void DisplayElement::removeFromFrame(int frame)
{
  frames_t bit = 1;
  frames_ &= ~(1 << frame);
}

boolean DisplayElement::inFrame(int frame)
{
  frames_t bit = 1;
  return frames_ & (1 << frame);
}
}
