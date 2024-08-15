#pragma once
#include <Stream.h>

#include "gamepad_publisher.h"

namespace emakefun {
class GamepadPublisherBle : public GamepadPublisher {
 public:
  GamepadPublisherBle();
  bool Initialize(Stream& stream);

 private:
  void OnPacket(const uint8_t* packet, uint8_t length) override;

  uint32_t send_packet_min_interval_ms_ = 100;
  uint64_t last_send_packet_time_ = 0;
  Stream* stream_ = nullptr;
};
}  // namespace emakefun