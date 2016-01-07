// ----------------------------------------------------------------------------
// ServerDefinitions.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_SERVER_DEFINITIONS_H_
#define _STANDALONE_SERVER_DEFINITIONS_H_


namespace Standalone
{
template<size_t FRAME_COUNT>
void Server::setup(const ConstantString (&frame_names)[FRAME_COUNT])
{
  frame_names_ptr_ = &frame_names;
  setup(FRAME_COUNT);
}
}

#endif
