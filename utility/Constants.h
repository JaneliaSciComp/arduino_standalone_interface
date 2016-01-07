// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_CONSTANTS_H_
#define _STANDALONE_CONSTANTS_H_


namespace Standalone
{
namespace constants
{
// enum{DISPLAY_LABEL_COUNT_MAX=24};
// enum{DISPLAY_VARIABLE_COUNT_MAX=20};
// enum{INTERACTIVE_VARIABLE_COUNT_MAX=20};
enum{FRAMES_COUNT_MAX=16};
enum{INC_STRING_COUNT=5};

extern ConstantString inc0;
extern ConstantString inc1;
extern ConstantString inc2;
extern ConstantString inc3;
extern ConstantString inc4;
extern const ConstantString increment_array[INC_STRING_COUNT];
}
}
#endif
