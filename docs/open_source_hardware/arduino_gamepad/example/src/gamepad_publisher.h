#pragma once

#include "gamepad_model.h"
#include "stddef.h"

namespace emakefun {
class GamepadPublisher : public GamepadModel::Observer {
 protected:
  virtual void OnPacket(const uint8_t* packet, uint8_t length) = 0;

 private:
  void OnButtonState(uint16_t button_state) override;
  void OnJoystickCoordinate(const GamepadModel::JoystickCoordinate&) override;
  void OnGravityAcceleration(const GamepadModel::GravityAcceleration&) override;
  template <size_t size>
  void SendPacket(const uint8_t (&data)[size]);
};
}  // namespace emakefun