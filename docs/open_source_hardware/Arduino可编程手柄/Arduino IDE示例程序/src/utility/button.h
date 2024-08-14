#pragma once

#include <Arduino.h>
#include <inttypes.h>

namespace emakefun {
class Button {
 public:
  explicit Button(const uint8_t pin, const uint8_t active_level = LOW, const uint8_t pin_mode = INPUT_PULLUP);
  void Initialize();
  void Tick();
  bool IsActive() const;

 private:
  uint32_t debounce_start_time_ = 0;
  bool debouncing_value_ = false;
  bool active_ = false;
  uint32_t debounce_duration_ = 50;
  const uint8_t pin_ = 0;
  const uint8_t active_level_ = LOW;
  const uint8_t pin_mode_ = INPUT_PULLUP;
};
}  // namespace emakefun