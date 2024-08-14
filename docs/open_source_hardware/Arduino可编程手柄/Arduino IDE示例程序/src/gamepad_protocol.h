#pragma once

#include "inttypes.h"

namespace emakefun {
constexpr uint8_t kProtocolVersion = 0x01;
constexpr uint8_t kDeviceType = 0x01;
constexpr uint8_t kDefaultDeviceAddress = kDeviceType;

enum MessageType : uint8_t {
  kButtonState = 0x00,
  kJoystickCoordinate = 0x01,
  kGravityAcceleration = 0x02,
};

uint16_t Checksum(const uint8_t* data, const uint8_t length) {
  uint16_t checksum = 0;
  for (uint8_t i = 0; i < length; i++) {
    checksum += data[i];
  }
  return checksum;
}
}  // namespace emakefun