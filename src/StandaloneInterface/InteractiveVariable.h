// ----------------------------------------------------------------------------
// InteractiveVariable.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_INTERACTIVE_VARIABLE_H_
#define _STANDALONE_INTERACTIVE_VARIABLE_H_
#include <Arduino.h>

#include "DisplayVariable.h"


namespace Standalone
{
class InteractiveVariable : public DisplayVariable
{
public:
  typedef void(*Callback)();
  InteractiveVariable();
  void setRange(long min,
    long max);
  void trimDisplayWidthUsingRange();
  long getMin();
  long getMax();
  virtual void setValue(long value);
  virtual void setConstantStringArray(const ConstantString string_array[],
    uint8_t string_count);
  void attachUpdateCallback(Callback callback);
private:
  long min_;
  long max_;
  bool value_dirty_;
  Callback update_callback_;
  void updateWithEncoderValue(long value);
  bool checkValueDirty();
  void clearValueDirty();
  long wrapValue(long value);
  void executeUpdateCallback();
  friend class Server;
};
}
#endif
