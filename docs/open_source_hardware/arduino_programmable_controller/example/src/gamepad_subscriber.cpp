#include "gamepad_subscriber.h"

#include "gamepad_protocol.h"

namespace emakefun {
void GamepadSubscriber::AttachModel(GamepadModel* const model) {
  model_ = model;
}

void GamepadSubscriber::Tick() {
  if (model_ != nullptr) {
    model_->Tick();
  }
  OnHandleData(&HandleData);
  HandlePacket();
}

void GamepadSubscriber::HandleData(const uint8_t* data, const uint32_t length) {
  if (length != packet_parser_.AppendData(data, length)) {
    // LOG(ERROR) << "buffer is full and drop " << length << " bytes";
  }
}

void GamepadSubscriber::HandlePacket() {
  PacketParser::Packet* packet = nullptr;
  while ((packet = packet_parser_.ReadPacket()) != nullptr) {
    HandlePacket(packet);
    packet_parser_.ReleasePacket(packet);
  }
}

void GamepadSubscriber::HandlePacket(PacketParser::Packet* packet) {
  if (packet == nullptr || packet->data == nullptr || packet->data_length == 0) {
    return;
  }

  if (model_ == nullptr) {
    return;
  }

  uint8_t index = 0;
  const uint8_t* const data = packet->data;
  const MessageType message_type = data[index++];
  switch (message_type) {
    case kButtonState: {
      uint16_t button_state = data[index++];
      button_state = (button_state << 8) | data[index++];
      model_->OnButtonState(button_state);
      break;
    }

    case kJoystickCoordinate: {
      GamepadModel::JoystickCoordinate joystick_coordinate{0};
      joystick_coordinate.x = data[index++];
      joystick_coordinate.y = data[index++];
      model_->OnJoystickCoordinate(joystick_coordinate);
      break;
    }

    case kGravityAcceleration: {
      GamepadModel::GravityAcceleration gravity_acceleration{0};
      gravity_acceleration.x = data[index++];
      gravity_acceleration.x = (gravity_acceleration.x << 8) | data[index++];
      gravity_acceleration.y = data[index++];
      gravity_acceleration.y = (gravity_acceleration.y << 8) | data[index++];
      gravity_acceleration.z = data[index++];
      gravity_acceleration.z = (gravity_acceleration.z << 8) | data[index++];
      model_->OnGravityAcceleration(gravity_acceleration);
      break;
    }

    default: {
      break;
    }
  }
}
}  // namespace emakefun