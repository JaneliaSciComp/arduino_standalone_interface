// ----------------------------------------------------------------------------
// ServerDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef STANDALONE_INTERFACE_DEFINITIONS_H
#define STANDALONE_INTERFACE_DEFINITIONS_H


namespace Standalone
{
template<size_t FRAME_COUNT>
void StandaloneInterface::setup(const ConstantString (&frame_names)[FRAME_COUNT])
{
  server_.setup(frame_names);
}

template<size_t MAX_SIZE>
void StandaloneInterface::setDisplayLabelStorage(DisplayLabel (&display_labels)[MAX_SIZE])
{
  server_.setDisplayLabelStorage(display_labels);
}

template<size_t MAX_SIZE>
void StandaloneInterface::setDisplayVariableStorage(DisplayVariable (&display_variables)[MAX_SIZE])
{
  server_.setDisplayVariableStorage(display_variables);
}

template<size_t MAX_SIZE>
void StandaloneInterface::setInteractiveVariableStorage(InteractiveVariable (&interactive_variables)[MAX_SIZE])
{
  server_.setInteractiveVariableStorage(interactive_variables);
}
}

#endif
