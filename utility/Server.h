// ----------------------------------------------------------------------------
// Server.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _SERVER_H_
#define _SERVER_H_
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
         const int update_period);
  void update();
  void enable();
  void disable();
  InteractiveVariable& createInteractiveVariable();
private:
  NewhavenDisplay display_;
  Encoder encoder_;
  const int enc_btn_pin_;
  const int enc_btn_int_;
  const int btn_pin_;
  const int btn_int_;
  const int update_period_;
  boolean enabled_;
  unsigned long time_last_update_;
  std::vector<InteractiveVariable> interactive_variable_vector_;
  static int interactive_variable_count_;
  static volatile int interactive_variable_index_;
  static volatile boolean interactive_variable_index_changed_;
  static void encBtnIsr();
};
}
#endif
