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
  void setup();
  void enable();
  void disable();
  void update();
  DisplayLabel& createDisplayLabel();
  DisplayVariable& createDisplayVariable();
  InteractiveVariable& createInteractiveVariable();
private:
  NewhavenDisplay display_;
  Encoder encoder_;
  const int enc_btn_pin_;
  const int enc_btn_int_;
  const int btn_pin_;
  const int btn_int_;
  const int led_pwr_pin_;
  const int update_period_;
  boolean enabled_;
  boolean led_off_;
  unsigned long time_last_update_;
  std::vector<DisplayLabel> display_label_vector_;
  std::vector<DisplayVariable> display_variable_vector_;
  std::vector<InteractiveVariable> interactive_variable_vector_;
  boolean display_labels_dirty_;
  static int interactive_variable_count_;
  static volatile int interactive_variable_index_;
  static volatile boolean interactive_variable_index_changed_;
  static void encBtnIsr();
  void ledOn();
  void ledOff();
};
}
#endif
