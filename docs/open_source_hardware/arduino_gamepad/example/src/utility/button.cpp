#include "button.h"

namespace emakefun {
Button::Button(const uint8_t pin, const uint8_t active_level, const uint8_t pin_mode)
    : pin_(pin), active_level_(active_level), pin_mode_(pin_mode) {
}

void Button::Initialize() {
  pinMode(pin_, pin_mode_);
}

void Button::Tick() {
  const auto now = millis();
  Serial.println(now);
  if ((digitalRead(pin_) == active_level_) == debouncing_value_) {
    if (debounce_start_time_ + debounce_duration_ <= now) {
      active_ = debouncing_value_;
    }
  } else {
    debounce_start_time_ = now;
    debouncing_value_ = !debouncing_value_;
  }
}

bool Button::IsActive() const {
  return active_;
}

}  // namespace emakefun