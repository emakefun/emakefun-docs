#pragma once

#include "RF24.h"
#include "gamepad_model.h"
#include "gamepad_subscriber.h"
#include "utility/packet_parser.h"

namespace emakefun {
class GamepadSubscriberRf24 : public GamepadSubscriber {
 public:
  GamepadSubscriberRf24();
  bool Initialize(const uint8_t ce_pin, const uint8_t cs_pin, const uint8_t channel, const uint8_t address_width, const uint64_t address);

 private:
  void OnHandleData(void (GamepadSubscriber::*handle_data)(const uint8_t* data, const uint32_t length)) override;
  RF24 rf24_;
};
}  // namespace emakefun
