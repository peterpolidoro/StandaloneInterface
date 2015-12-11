// ----------------------------------------------------------------------------
// ModularStandalone.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef MODULAR_STANDALONE_H
#define MODULAR_STANDALONE_H
#include "utility/Server.h"


namespace Standalone
{
typedef void(*Callback)();

class ModularStandalone
{
public:
  ModularStandalone(HardwareSerial &display_serial,
                    const int enc_a_pin,
                    const int enc_b_pin,
                    const int enc_btn_pin,
                    const int enc_btn_int,
                    const int btn_pin,
                    const int btn_int,
                    const int lights_pin,
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
  Server server_;
};
}
#endif