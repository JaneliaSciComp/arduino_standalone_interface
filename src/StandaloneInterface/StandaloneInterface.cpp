// ----------------------------------------------------------------------------
// StandaloneInterface.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "StandaloneInterface.h"


namespace Standalone
{
StandaloneInterface::StandaloneInterface(Configuration configuration) :
server_(configuration)
{
}

void StandaloneInterface::enable()
{
  server_.enable();
}

void StandaloneInterface::disable()
{
  server_.disable();
}

bool StandaloneInterface::update()
{
  return server_.update();
}

DisplayLabel& StandaloneInterface::createDisplayLabel()
{
  return server_.createDisplayLabel();
}

DisplayVariable& StandaloneInterface::createDisplayVariable()
{
  return server_.createDisplayVariable();
}

InteractiveVariable& StandaloneInterface::createInteractiveVariable()
{
  return server_.createInteractiveVariable();
}

InteractiveVariable& StandaloneInterface::createIncrementVariable(int width_max)
{
  return server_.createIncrementVariable(width_max);
}

void StandaloneInterface::attachCallbackToFrame(Callback callback, uint8_t frame)
{
  server_.attachCallbackToFrame(callback,frame);
}

void StandaloneInterface::executeCurrentFrameCallback()
{
  server_.executeCurrentFrameCallback();
}
}
