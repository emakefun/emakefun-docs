#include "gamepad_publisher_ble.h"

#include <Arduino.h>

namespace emakefun {

GamepadPublisherBle::GamepadPublisherBle() = default;

bool GamepadPublisherBle::Initialize(Stream& stream) {
  stream_ = &stream;
  return true;
}

void GamepadPublisherBle::OnPacket(const uint8_t* packet, uint8_t length) {
  if (stream_ == nullptr) {
    return;
  }

  const auto now = millis();
  if (now - last_send_packet_time_ < send_packet_min_interval_ms_) {
    return;
  }

  stream_->write(packet, length);
}
}  // namespace emakefun