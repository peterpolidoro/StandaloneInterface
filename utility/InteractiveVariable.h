// ----------------------------------------------------------------------------
// InteractiveVariable.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _STANDALONE_INTERACTIVE_VARIABLE_H_
#define _STANDALONE_INTERACTIVE_VARIABLE_H_
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "DisplayVariable.h"

namespace Standalone
{
class InteractiveVariable : public DisplayVariable
{
public:
  InteractiveVariable();
  void setRange(const int min, const int max);
  int getMin();
  int getMax();
  virtual void setValue(int value);
  virtual void setConstantStringArray(const ConstantString string_array[],
                                      const uint8_t string_count);
private:
  static const uint8_t DISPLAY_WIDTH_DEFAULT=6;
  int min_;
  int max_;
  boolean value_dirty_;
  void updateWithEncoderValue(int value);
  boolean checkValueDirty();
  void clearValueDirty();
  int wrapValue(int value);
  friend class Server;
};
}
#endif
