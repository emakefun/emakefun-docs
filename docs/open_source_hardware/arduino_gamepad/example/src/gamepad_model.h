#pragma once

#include <stdint.h>

#include "utility/list.h"

namespace emakefun {
class GamepadModel {
 public:
  enum ButtonType : uint8_t {
    kButtonJoystick = 0,
    kButtonL = 1,
    kButtonR = 2,
    kButtonSelect = 3,
    kButtonMode = 4,
    kButtonA = 5,
    kButtonB = 6,
    kButtonC = 7,
    kButtonD = 8,
    kButtonMax,
  };

  struct JoystickCoordinate {
    uint8_t x;
    uint8_t y;

    bool operator==(const JoystickCoordinate& other) const {
      return x == other.x && y == other.y;
    }

    bool operator!=(const JoystickCoordinate& other) const {
      return x != other.x || y != other.y;
    }
  };

  struct GravityAcceleration {
    int16_t x;
    int16_t y;
    int16_t z;

    bool operator==(const GravityAcceleration& other) const {
      return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const GravityAcceleration& other) const {
      return x != other.x || y != other.y || z != other.z;
    }
  };

  struct Observer {
    virtual ~Observer() = default;
    virtual void OnButtonState(uint16_t button_state) = 0;
    virtual void OnJoystickCoordinate(const JoystickCoordinate&) = 0;
    virtual void OnGravityAcceleration(const GravityAcceleration&) = 0;
  };

  void AddObserver(const Observer* observer) {
    observers_.PushBack(observer);
  }

  void Tick() {
    last_button_state_ = button_state_;
    last_joystick_coordinate_ = joystick_coordinate_;
    last_gravity_acceleration_ = gravity_acceleration_;
  }

  bool NewButtonState() const {
    return (button_state_ ^ last_button_state_) != 0;
  }

  bool NewButtonState(const ButtonType button_type) const {
    return ((button_state_ ^ last_button_state_) & (static_cast<uint16_t>(1) << button_type)) != 0;
  }

  bool ButtonPressed(const ButtonType button_type) const {
    return NewButtonState(button_type) && GetButtonState(button_type);
  }

  bool ButtonReleased(const ButtonType button_type) const {
    return NewButtonState(button_type) && !GetButtonState(button_type);
  }

  bool GetButtonState(const ButtonType button_type) const {
    return (button_state_ & (static_cast<uint16_t>(1) << button_type)) != 0;
  }

  bool NewJoystickCoordinate() const {
    return joystick_coordinate_ != last_joystick_coordinate_;
  }

  bool NewGravityAcceleration() const {
    return gravity_acceleration_ != last_gravity_acceleration_;
  }

  const JoystickCoordinate& GetJoystickCoordinate() const {
    return joystick_coordinate_;
  }

  const GravityAcceleration& GetGravityAcceleration() const {
    return gravity_acceleration_;
  }

  uint16_t ButtonState() const {
    return button_state_;
  }

  void OnButtonState(const uint16_t button_state) {
    button_state_ = button_state;
    for (auto observer : observers_) {
      observer->OnButtonState(button_state);
    }
  }

  void OnJoystickCoordinate(const JoystickCoordinate& joystick_coordinate) {
    joystick_coordinate_ = joystick_coordinate;
    for (auto observer : observers_) {
      observer->OnJoystickCoordinate(joystick_coordinate);
    }
  }

  void OnGravityAcceleration(const GravityAcceleration& gravity_acceleration) {
    gravity_acceleration_ = gravity_acceleration;
    for (auto observer : observers_) {
      observer->OnGravityAcceleration(gravity_acceleration);
    }
  }

 private:
  uint16_t button_state_ = 0;
  uint16_t last_button_state_ = 0;
  JoystickCoordinate joystick_coordinate_{127, 127};
  JoystickCoordinate last_joystick_coordinate_{0};
  GravityAcceleration gravity_acceleration_{0};
  GravityAcceleration last_gravity_acceleration_{0};
  List<Observer*> observers_;
};
}  // namespace emakefun