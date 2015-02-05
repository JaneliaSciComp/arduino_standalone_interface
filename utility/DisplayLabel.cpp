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
DisplayLabel::DisplayLabel(const _FLASH_STRING &label)
{
  label_ptr_ = &label;
  setDisplayWidth(label.length());
}

String DisplayLabel::getDisplayString()
{
  char label_char_array[getDisplayWidth()+1];
  label_ptr_->copy(label_char_array);
  return String(label_char_array);
}
}
