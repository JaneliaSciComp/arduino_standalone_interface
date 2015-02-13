// ----------------------------------------------------------------------------
// DisplayLabel.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "DisplayLabel.h"


namespace Standalone
{
DisplayLabel::DisplayLabel()
{
  label_ptr_ = NULL;
  setDisplayWidth(0);
}

String DisplayLabel::getDisplayString()
{
  if (label_ptr_)
  {
    char label_char_array[getDisplayWidth()+1];
    label_ptr_->copy(label_char_array);
    return String(label_char_array);
  }
  else
  {
    return String("");
  }
}

void DisplayLabel::setFlashString(const _FLASH_STRING &label)
{
  label_ptr_ = &label;
  if (getDisplayWidth() == 0)
  {
    setDisplayWidth(label.length());
  }
}
}
