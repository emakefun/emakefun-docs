#pragma once

#include <Arduino.h>

#include "gamepad_model.h"
#include "gamepad_subscriber.h"
#include "utility/packet_parser.h"

namespace emakefun {
class GamepadSubscriberBle : public GamepadSubscriber {
 public:
  GamepadSubscriberBle();
  bool Initialize(Stream& stream);

 private:
  void OnHandleData(void (GamepadSubscriber::*handle_data)(const uint8_t* data, const uint32_t length)) override;
  Stream* stream_ = nullptr;
};
}  // namespace emakefun
