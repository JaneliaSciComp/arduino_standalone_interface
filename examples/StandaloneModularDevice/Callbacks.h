// ----------------------------------------------------------------------------
// Callbacks.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef CALLBACKS_H
#define CALLBACKS_H
#include <ArduinoJson.h>
#include <ModularServer.h>

#include "Constants.h"
#include "Controller.h"


namespace callbacks
{
void executeStandaloneCallbackCallback();

void getDspVar1Callback();

void setDspVar1Callback();

void getIntVar1Callback();

void setIntVar1Callback();

void getIntVar2Callback();

void setIntVar2Callback();

// Standalone Callbacks
void addIntVar1ToDspVar1Callback();

void subIntVar2FromDspVar1Callback();
}
#endif
