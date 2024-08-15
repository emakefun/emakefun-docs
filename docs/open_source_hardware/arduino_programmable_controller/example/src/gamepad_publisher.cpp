#include "gamepad_publisher.h"

#include <string.h>

#include "gamepad_protocol.h"

namespace emakefun {
void GamepadPublisher::OnButtonState(uint16_t button_state) {
  SendPacket((uint8_t[]){kButtonState, button_state >> 8, button_state});
}

void GamepadPublisher::OnJoystickCoordinate(const GamepadModel::JoystickCoordinate& joystick_coordinate) {
  SendPacket((uint8_t[]){kJoystickCoordinate, joystick_coordinate.x, joystick_coordinate.y});
}

void GamepadPublisher::OnGravityAcceleration(const GamepadModel::GravityAcceleration& gravity_acceleration) {
  SendPacket((uint8_t[]){kGravityAcceleration,
                         gravity_acceleration.x >> 8,
                         gravity_acceleration.x,
                         gravity_acceleration.y >> 8,
                         gravity_acceleration.y,
                         gravity_acceleration.z >> 8,
                         gravity_acceleration.z});
}

template <size_t length>
void GamepadPublisher::SendPacket(const uint8_t (&data)[length]) {
  constexpr uint8_t packet_length = length + 7;
  uint8_t packet_data[packet_length] = {0};
  uint8_t index = 0;
  packet_data[index++] = 0xFB;                   // start_code
  packet_data[index++] = kProtocolVersion;       // protocol_version
  packet_data[index++] = packet_length;          // packet_datalength
  packet_data[index++] = kDeviceType;            // device_type
  packet_data[index++] = kDefaultDeviceAddress;  // device_address
  const uint16_t checksum = Checksum(packet_data, index) + Checksum(data, length);

  packet_data[index++] = checksum >> 8;       // checksum_high
  packet_data[index++] = checksum;            // checksum_low
  memcpy(packet_data + index, data, length);  // data
  OnPacket(packet_data, packet_length);
}
}  // namespace emakefun