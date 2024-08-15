#pragma once
#include "RF24.h"
#include "gamepad_publisher.h"

namespace emakefun {
class GamepadPublisherRf24 : public GamepadPublisher {
 public:
  GamepadPublisherRf24();
  bool Initialize(
      const uint8_t ce_pin, const uint8_t cs_pin, const uint8_t channel, const uint8_t address_width, const uint64_t address);

 private:
  void OnPacket(const uint8_t* packet, uint8_t length) override;

  RF24 rf24_;
};
}  // namespace emakefun