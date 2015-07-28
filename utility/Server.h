// ----------------------------------------------------------------------------
// Server.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_SERVER_H_
#define _STANDALONE_SERVER_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Streaming.h"
#include "NewhavenDisplay.h"
#include "Encoder.h"
#include "Array.h"
#include "ConstantVariable.h"
#include "Constants.h"
#include "DisplayLabel.h"
#include "DisplayVariable.h"
#include "InteractiveVariable.h"


namespace Standalone
{
void defaultCallback();

class Server
{
public:
  typedef void(*Callback)();
  Server(HardwareSerial &serial,
         const int enc_a_pin,
         const int enc_b_pin,
         const int enc_btn_pin,
         const int enc_btn_int,
         const int btn_pin,
         const int btn_int,
         const int led_pwr_pin,
         const int update_period);
  void setup(const uint8_t frame_count);
  void setup(const ConstantString frame_name_array[],
             const uint8_t frame_count);
  void enable();
  void disable();
  bool update();
  DisplayLabel& createDisplayLabel();
  DisplayVariable& createDisplayVariable();
  InteractiveVariable& createInteractiveVariable();
  InteractiveVariable& createIncrementVariable();
  void attachCallbackToFrame(Callback callback, uint8_t frame);
  void executeCurrentFrameCallback();
private:
  NewhavenDisplay display_;
  Encoder encoder_;
  const int enc_btn_pin_;
  const int enc_btn_int_;
  const int btn_pin_;
  const int btn_int_;
  const int led_pwr_pin_;
  const int update_period_;
  bool setup_;
  bool enabled_;
  bool led_off_;
  unsigned long time_last_update_;
  uint8_t frame_count_;
  InteractiveVariable *frame_var_ptr_;
  const ConstantString *frame_name_array_;
  Array<DisplayLabel,constants::DISPLAY_LABEL_COUNT_MAX> display_label_array_;
  Array<DisplayVariable,constants::DISPLAY_VARIABLE_COUNT_MAX> display_variable_array_;
  Array<InteractiveVariable,constants::INTERACTIVE_VARIABLE_COUNT_MAX> interactive_variable_array_;
  int interactive_variable_index_;
  InteractiveVariable *inc_var_ptr_;
  uint32_t enc_value_prev_;
  static const int FRAME_VAR_DISPLAY_POSITION = 0;
  static const int FRAME_VAR_DISPLAY_WIDTH = 1;
  static volatile bool enc_btn_pressed_;
  static void encBtnIsr();
  static void btnIsr();
  static Callback callback_array_[constants::FRAMES_COUNT_MAX];
  static uint8_t frame_current_;
  void ledOn();
  void ledOff();
};
}
#endif
