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
#include "StandardCplusplus.h"
#include "vector"
#include "Flash.h"
#include "DisplayLabel.h"
#include "DisplayVariable.h"
#include "InteractiveVariable.h"


namespace Standalone
{
typedef void(*Callback)();
void defaultCallback();

class Server
{
public:
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
  void setup(const _FLASH_STRING frame_name_array[],
             const uint8_t frame_count);
  void enable();
  void disable();
  boolean update();
  DisplayLabel& createDisplayLabel();
  DisplayVariable& createDisplayVariable();
  InteractiveVariable& createInteractiveVariable();
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
  boolean setup_;
  boolean enabled_;
  boolean led_off_;
  unsigned long time_last_update_;
  uint8_t frame_count_;
  InteractiveVariable *frame_var_ptr_;
  const _FLASH_STRING *frame_name_array_;
  std::vector<DisplayLabel> display_label_vector_;
  std::vector<DisplayVariable> display_variable_vector_;
  std::vector<InteractiveVariable> interactive_variable_vector_;
  int interactive_variable_count_;
  int interactive_variable_index_;
  boolean display_labels_dirty_;
  static const int FRAME_VAR_DISPLAY_POSITION = 0;
  static const int FRAME_VAR_DISPLAY_WIDTH = 1;
  static volatile boolean enc_btn_pressed_;
  static void encBtnIsr();
  static void btnIsr();
  static Callback callback_array_[DisplayElement::FRAMES_COUNT_MAX];
  static uint8_t frame_current_;
  void ledOn();
  void ledOff();
};
}
#endif
