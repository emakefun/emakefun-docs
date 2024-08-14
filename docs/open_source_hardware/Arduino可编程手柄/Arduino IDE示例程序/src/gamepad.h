#pragma once

#include "gamepad_model.h"
#include "mpu6050.h"
#include "utility/List.h"
#include "utility/button.h"

namespace emakefun {
class Gamepad {
 public:
  Gamepad();
  virtual ~Gamepad() = default;
  void Initialize();
  void Tick();
  void AttachModel(const GamepadModel* model);
  void EnableGyroscope(const bool enabled);

 private:
  Mpu6050 mpu6050_;
  const emakefun::Button buttons_[GamepadModel::kButtonMax];
  GamepadModel* model_ = nullptr;
  uint64_t last_update_button_state_time_ = 0;
  uint64_t last_update_joystick_coordinate_time_ = 0;
  uint64_t last_update_gravity_acceleration_time_ = 0;
  bool enable_gyroscope_ = true;
};
}  // namespace emakefun