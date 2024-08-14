#include "gamepad.h"

#include <Arduino.h>

namespace emakefun {

namespace {

constexpr uint8_t kMinJoystickCoordinateDiff = 10;
constexpr uint8_t kMinGravityAccelerationDiff = 50;

enum Pin : uint8_t {
  kPinButtonJoystick = A0,
  kPinButtonL = A1,
  kPinButtonR = 6,
  kPinButtonSelect = 2,
  kPinButtonMode = A3,
  kPinButtonA = 3,
  kPinButtonB = A2,
  kPinButtonC = 5,
  kPinButtonD = 4,
  kPinRockerCoordinateX = A6,
  kPinRockerCoordinateY = A7,
};

uint32_t Diff(const int32_t a, const int32_t b) {
  return abs(a - b);
}

}  // namespace

Gamepad::Gamepad()
    : buttons_({emakefun::Button(kPinButtonJoystick),
                emakefun::Button(kPinButtonL),
                emakefun::Button(kPinButtonR),
                emakefun::Button(kPinButtonSelect),
                emakefun::Button(kPinButtonMode),
                emakefun::Button(kPinButtonA),
                emakefun::Button(kPinButtonB),
                emakefun::Button(kPinButtonC),
                emakefun::Button(kPinButtonD)}) {
}

void Gamepad::Initialize() {
  mpu6050_.Setup();
  pinMode(kPinRockerCoordinateX, INPUT);
  pinMode(kPinRockerCoordinateY, INPUT);
  for (const auto& button : buttons_) {
    button.Initialize();
  }
}

void Gamepad::EnableGyroscope(const bool enabled) {
  enable_gyroscope_ = enabled;
}

void Gamepad::Tick() {
  if (model_ != nullptr) {
    model_->Tick();
  }

  const auto now = millis();
  uint16_t button_state = 0;
  for (uint8_t i = 0; i < GamepadModel::kButtonMax; i++) {
    buttons_[i].Tick();
    bitWrite(button_state, i, buttons_[i].IsActive());
  }

  if (model_ != nullptr) {
    if (model_->ButtonState() != button_state || last_update_button_state_time_ == 0 ||
        now - last_update_button_state_time_ > 500) {
      model_->OnButtonState(button_state);
      last_update_button_state_time_ = now;
    }

    const GamepadModel::JoystickCoordinate joystick_coordinate{analogRead(kPinRockerCoordinateX) >> 2,
                                                               1023 - analogRead(kPinRockerCoordinateY) >> 2};

    if (Diff(model_->GetJoystickCoordinate().x, joystick_coordinate.x) > kMinJoystickCoordinateDiff ||
        Diff(model_->GetJoystickCoordinate().y, joystick_coordinate.y) > kMinJoystickCoordinateDiff ||
        last_update_joystick_coordinate_time_ == 0 || now - last_update_joystick_coordinate_time_ > 500) {
      model_->OnJoystickCoordinate(joystick_coordinate);
      last_update_joystick_coordinate_time_ = now;
    }

    if (enable_gyroscope_ && mpu6050_.UpdateMotionInfo()) {
      const auto acceleration = mpu6050_.GetAcceleration();
      if (Diff(model_->GetGravityAcceleration().x, acceleration.x) > kMinGravityAccelerationDiff ||
          Diff(model_->GetGravityAcceleration().y, acceleration.y) > kMinGravityAccelerationDiff ||
          Diff(model_->GetGravityAcceleration().z, acceleration.z) > kMinGravityAccelerationDiff ||
          last_update_gravity_acceleration_time_ == 0 || now - last_update_gravity_acceleration_time_ > 500) {
        model_->OnGravityAcceleration({acceleration.x, acceleration.y, acceleration.z});
        last_update_gravity_acceleration_time_ = now;
      }
    }
  }
}

void Gamepad::AttachModel(const GamepadModel* model) {
  model_ = model;
}
}  // namespace emakefun