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
  setDisplayWidth(0);
  setLeftJustify();
  frames_ = 0;
  display_dirty_ = true;
}

void DisplayElement::setDisplayPosition(const uint8_t display_position)
{
  if (left_justify_)
  {
    display_position_ = display_position;
  }
  else
  {
    display_position_ = display_position - (display_width_ - 1);
  }
}

uint8_t DisplayElement::getDisplayPosition()
{
  return display_position_;
}

void DisplayElement::setDisplayWidth(const uint8_t display_width)
{
  if (!left_justify_)
  {
    display_position_ += display_width_ - 1;
  }

  if (display_width <= DISPLAY_WIDTH_MAX)
  {
    display_width_ = display_width;
  }
  else
  {
    display_width_ = DISPLAY_WIDTH_MAX;
  }

  if (!left_justify_)
  {
    display_position_ -= display_width_ - 1;
  }
}

uint8_t DisplayElement::getDisplayWidth()
{
  return display_width_;
}

void DisplayElement::setLeftJustify()
{
  if (!left_justify_)
  {
    left_justify_ = true;
    display_position_ += display_width_ - 1;
  }
}

void DisplayElement::setRightJustify()
{
  if (left_justify_)
  {
    left_justify_ = false;
    display_position_ -= display_width_ - 1;
  }
}

void DisplayElement::updateOnDisplay(NewhavenDisplay &display, int frame)
{
  if (inFrame(frame))
  {
    if (display_dirty_)
    {
      display_dirty_ = false;
      display.setCursor(getDisplayPosition());
      uint8_t display_width = getDisplayWidth();
      if (left_justify_)
      {
        display.printPadRight(getDisplayString(),display_width);
      }
      else
      {
        display.printPadLeft(getDisplayString(),display_width);
      }
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

void DisplayElement::setDisplayDirty()
{
  display_dirty_ = true;
}
}
