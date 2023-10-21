# MotorDriverBoard编码电机库

## 介绍

该库用于在MotorDriverBoard上控制带编码器的编码电机，可以实现电机的速度控制和位置控制。*请联系技术支持获取该库源码*。

主要功能:

- 支持4个电机控制
- 编码器中断读取,实时计算速度和位置
- 速度闭环控制PID
- 位置闭环控制PID
- 直接设置PWM占空比
- 相对位置移动和绝对位置移动

## Arduino API说明

### 获取电机对象引用

`EncoderMotor& GetEncoderMotor(const MotorIndex index);`
  
- `index`: `emakefun::EncoderMotor::kE1` ~ `emakefun::EncoderMotor::kE3`，对于MotorDriverBoard上`E1` ~ `E3`的电机

### 初始化

`void Initialize(const uint8_t ppr, const uint8_t reduction_ratio);`

- `ppr`: 编码器每转脉冲数
- `reduction_ratio`: 电机减速比

需要在使用其他功能前先初始化。

### 设置速度PID

`void SetSpeedPid(const float p, const float i, const float d);`

- `p`,`i`,`d`: PID参数

用于速度闭环控制,通过调节PID可以改善速度控制性能。

### 获取速度PID

`float GetSpeedPidP() const;`

`float GetSpeedPidI() const;`

`float GetSpeedPidD() const;`

获取已设置的速度PID参数。

### 设置位置PID

`void SetPositionPid(const float p, const float i, const float d);`

- `p`,`i`,`d`: PID参数

### 获取位置PID

`float GetPositionPidP() const;`

`float GetPositionPidI() const;`

`float GetPositionPidD() const;`

获取已设置的位置PID参数。

### 更新状态

`void Tick();`

需要在主循环中调用以更新编码器计数、速度、位置等信息。

### 直接设置PWM

`void RunPwm(const int16_t pwm, const uint16_t pwm_fade_speed = kDefaultPwmFadeSpeed);`

- `pwm`: -4095 ~ 4095，PWM占空比
- `pwm_fade_speed`：渐变速度，单位为pwm/毫秒，可选，如果未设置，默认值为10 pwm/ms

用于直接设置PWM驱动电机而不启用闭环控制。

### 速度控制

`void RunSpeed(const int16_t speed);`

- `speed`: 速度设置值，单位为RPM，大于0为正向转动，小于0为反向转动

进入到闭环模式，驱动电机以恒定速度转动。

### 相对位置移动

`void Move(const int32_t relative_position, const int16_t speed);`

- `relative_position`: 目标位置相对当前位置的偏移量，单位为角度
- `speed`: 速度值，单位为RPM

进入到位置闭环模式，驱动电机以恒定速度转动到相对位置

### 绝对位置移动

`void MoveTo(const int32_t position, const int16_t speed);`

- `position`: 绝对目标位置，单位为角度
- `speed`: 速度设置值，单位为RPM

进入到位置闭环模式，驱动电机以恒定速度转动到绝对位置

### 停止电机

`void Stop();`

### 检查是否到达目标位置

`bool IsTargetPositionReached() const;`

在位置闭环模式下使用，返回是否已到达目标位置。

### 获取当前位置

`int32_t GetCurrentPosition() const;`

返回当前的电机轴位置, 单位为角度。

### 获取编码盘计数值

`int32_t GetEncoderPulseCount() const;`

### 设置编码盘计数值

`void SetEncoderPulseCount(const int32_t count);`

### 获取当前PWM值

`int16_t GetCurrentPwm() const;`

### 获取当前速度值

`float GetCurrentSpeed() const;`

## Arduino头文件参考

**encoder_motor.h**位置位于**emakefun_motor_driver_board_encoder_motor/src/encoder_motor.h**

```c++
#pragma once

#include <inttypes.h>

#include "utility/motor_driver.h"

namespace emakefun {

class EncoderMotor {
 public:
  /**
   * @brief Motor index enumeration.
   */
  enum MotorIndex : uint8_t {
    kE1,  ///< Motor 1
    kE2,  ///< Motor 2
    kE3,  ///< Motor 3
    kE4   ///< Motor 4
  };

  /**
   * @brief Maximum number of encoder motors supported.
   */
  static constexpr uint8_t kMaxMotorNum = 4;

  /**
   * @brief Default PWM fade speed of 10 units per millisecond.
   */
  static constexpr uint16_t kDefaultPwmFadeSpeed = 10;

  /**
   * @brief Get encoder motor instance.
   *
   * @param[in] index Motor index
   * @return EncoderMotor& Motor instance
   */
  static EncoderMotor& GetEncoderMotor(const MotorIndex index);

  /**
   * @brief Constructor.
   *
   * @param[in] pin_a Encoder channel A pin
   * @param[in] pin_b Encoder channel B pin
   * @param[in] pin_positive Motor driver positive pin
   * @param[in] pin_negative Motor driver negative pin
   */
  EncoderMotor(const uint8_t pin_a, const uint8_t pin_b, const uint8_t pin_positive, const uint8_t pin_negative);

  /**
   * @brief Initialize motor settings.
   *
   * @param[in] ppr Encoder pulses per revolution
   * @param[in] ratio Gear reduction ratio
   */
  void Initialize(const uint8_t ppr, const uint8_t reduction_ratio);

  /**
   * @brief Set PID gains for speed control.
   *
   * @param[in] p Proportional gain
   * @param[in] i Integral gain
   * @param[in] d Derivative gain
   */
  void SetSpeedPid(const float p, const float i, const float d);

  /**
   * @brief Get proportional gain for speed PID.
   *
   * @return Float speed PID P gain
   */
  float GetSpeedPidP() const;

  /**
   * @brief Get integral gain for speed PID.
   *
   * @return Float speed PID I gain
   */
  float GetSpeedPidI() const;

  /**
   * @brief Get derivative gain for speed PID.
   *
   * @return Float speed PID D gain
   */
  float GetSpeedPidD() const;

  /**
   * @brief Set PID gains for position.
   *
   * @param[in] p Proportional gain
   * @param[in] i Integral gain
   * @param[in] d Derivative gain
   */
  void SetPositionPid(const float p, const float i, const float d);

  /**
   * @brief Get proportional gain for position PID.
   *
   * @return Float position PID P gain
   */
  float GetPositionPidP() const;

  /**
   * @brief Get integral gain for position PID.
   *
   * @return Float position PID I gain
   */
  float GetPositionPidI() const;

  /**
   * @brief Get derivative gain for position PID.
   *
   * @return Float position PID D gain
   */
  float GetPositionPidD() const;

  /**
   * @brief Update motor state.
   *
   * Should be called periodically.
   */
  void Tick();

  /**
   * @brief Set motor PWM directly.
   *
   * @param[in] pwm PWM duty cycle (-4095 to 4095)
   * @param[in] pwm_fade_speed PWM change per millisecond during fade (default 10)
   */
  void RunPwm(const int16_t pwm, const uint16_t pwm_fade_speed = kDefaultPwmFadeSpeed);

  /**
   * @brief Run motor at speed setpoint.
   *
   * @param[in] speed Speed setpoint(RPM)
   */
  void RunSpeed(const int16_t speed);

  /**
   * @brief Move relative to current position.
   *
   * @param[in] relative_position Position change relative to current position (degrees)
   * @param[in] speed Cruise speed (RPM)
   */
  void Move(const int32_t relative_position, const int16_t speed);

  /**
   * @brief Move to absolute position.
   *
   * @param[in] position Target position (degrees)
   * @param[in] speed Cruise speed (RPM)
   */
  void MoveTo(const int32_t position, const int16_t speed);

  /**
   * @brief Stop motor.
   */
  void Stop();

  /**
   * @brief Check if target position reached.
   *
   * @return true If at target
   * @return false If moving
   */
  bool IsTargetPositionReached() const;

  /**
   * @brief Get current motor position.
   *
   * @return int32_t Position in encoder ticks
   */
  int32_t GetCurrentPosition() const;

  /**
   * @brief Get encoder pulse count.
   *
   * @return int32_t Encoder pulses
   */
  int32_t GetEncoderPulseCount() const;

  /**
   * @brief Set encoder pulse count.
   *
   * @param[in] count New encoder pulse count
   */
  void SetEncoderPulseCount(const int32_t count);

  /**
   * @brief Get current motor PWM.
   *
   * @return int16_t PWM duty cycle (-4095 to 4095)
   */
  int16_t GetCurrentPwm() const;

  /**
   * @brief Get current speed estimate.
   *
   * @return float Speed(RPM)
   */
  float GetCurrentSpeed() const;

 private:
  enum Mode {
    kNoneMode,
    kGradualPwmMode,
    kSpeedMode,
    kPositionMode,
  };

  struct Pid {
    float p = 0.0;
    float i = 0.0;
    float d = 0.0;
    float integral = 0.0;
    float last_error = 0.0;
  };

  static void InterruptCallback(void*);
  void InterruptCallback();
  void UpdateCurrentPosition();
  void UpdateCurrentSpeed();
  void UpdatePwmToTarget();
  void UpdatePwmForSpeed();
  void UpdatePwmForPosition();

  MotorDriver motor_driver_;
  const uint8_t pin_a_ = 0;
  const uint8_t pin_b_ = 0;
  double total_ppr_ = 0;

  Mode mode_ = kNoneMode;
  Pid pid_position_;
  Pid pid_speed_;

  int32_t previous_pulse_count_ = 0;
  int32_t current_pulse_count_ = 0;

  int32_t current_position_ = 0;
  int32_t target_position_ = 0;

  uint16_t pwm_fade_speed_ = kDefaultPwmFadeSpeed;
  int16_t target_pwm_ = 0;

  float previous_speed_ = 0.0;
  float current_speed_ = 0.0;
  float target_speed_ = 0.0;

  uint64_t last_update_pwm_time_ = 0;
  uint64_t last_update_speed_time_ = 0;
};
}  // namespace emakefun
```

## Arduino示例

### PWM直驱电机

```c++
#include <Arduino.h>
#include <string.h>

#include "encoder_motor.h"

auto g_encoder_motor_1 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE1);
auto g_encoder_motor_2 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE2);
auto g_encoder_motor_3 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE3);
auto g_encoder_motor_4 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE4);

void setup() {
  Serial.begin(115200);
  g_encoder_motor_1.Initialize(12, 90);
  g_encoder_motor_2.Initialize(12, 90);
  g_encoder_motor_3.Initialize(12, 90);
  g_encoder_motor_4.Initialize(12, 90);
  Serial.println("setup done");
}

void loop() {
  static auto s_change_direction_time = millis();
  static bool s_forward = true;

  g_encoder_motor_1.Tick();
  g_encoder_motor_2.Tick();
  g_encoder_motor_3.Tick();
  g_encoder_motor_4.Tick();

  if (millis() - s_change_direction_time > 4000) {
    s_forward = !s_forward;
    s_change_direction_time = millis();
  }

  if (s_forward) {
    g_encoder_motor_1.RunPwm(4095);
    g_encoder_motor_2.RunPwm(4095);
    g_encoder_motor_3.RunPwm(4095);
    g_encoder_motor_4.RunPwm(4095);
  } else {
    g_encoder_motor_1.RunPwm(-4095);
    g_encoder_motor_2.RunPwm(-4095);
    g_encoder_motor_3.RunPwm(-4095);
    g_encoder_motor_4.RunPwm(-4095);
  }
}
```

### 相对位置移动闭环控制

```c++
#include <Arduino.h>
#include <string.h>

#include "encoder_motor.h"

auto g_encoder_motor_1 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE1);
auto g_encoder_motor_2 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE2);
auto g_encoder_motor_3 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE3);
auto g_encoder_motor_4 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE4);

void setup() {
  Serial.begin(115200);
  g_encoder_motor_1.Initialize(12, 90);
  g_encoder_motor_2.Initialize(12, 90);
  g_encoder_motor_3.Initialize(12, 90);
  g_encoder_motor_4.Initialize(12, 90);

  g_encoder_motor_1.Move(360, 100);
  g_encoder_motor_2.Move(360, 100);
  g_encoder_motor_3.Move(360, 100);
  g_encoder_motor_4.Move(360, 100);
  Serial.println("setup done");
}

void loop() {
  static auto s_change_direction_time = millis();
  static auto s_last_print_time = millis();
  static bool s_forward = true;

  g_encoder_motor_1.Tick();
  g_encoder_motor_2.Tick();
  g_encoder_motor_3.Tick();
  g_encoder_motor_4.Tick();

  if (millis() - s_change_direction_time > 3000) {
    s_forward = !s_forward;
    s_change_direction_time = millis();
    if (s_forward) {
      g_encoder_motor_1.Move(360, 100);
      g_encoder_motor_2.Move(360, 100);
      g_encoder_motor_3.Move(360, 100);
      g_encoder_motor_4.Move(360, 100);
    } else {
      g_encoder_motor_1.Move(-360, 100);
      g_encoder_motor_2.Move(-360, 100);
      g_encoder_motor_3.Move(-360, 100);
      g_encoder_motor_4.Move(-360, 100);
    }
  }

  if (millis() - s_last_print_time > 500) {
    s_last_print_time = millis();
    Serial.print("is target position reached:");
    Serial.print(g_encoder_motor_1.IsTargetPositionReached());
    Serial.print(g_encoder_motor_2.IsTargetPositionReached());
    Serial.print(g_encoder_motor_3.IsTargetPositionReached());
    Serial.println(g_encoder_motor_4.IsTargetPositionReached());
  }
}
```

### 绝对位置移动闭环控制

```c++
#include <Arduino.h>
#include <string.h>

#include "encoder_motor.h"

auto g_encoder_motor_1 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE1);
auto g_encoder_motor_2 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE2);
auto g_encoder_motor_3 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE3);
auto g_encoder_motor_4 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE4);

void setup() {
  Serial.begin(115200);
  g_encoder_motor_1.Initialize(12, 90);
  g_encoder_motor_2.Initialize(12, 90);
  g_encoder_motor_3.Initialize(12, 90);
  g_encoder_motor_4.Initialize(12, 90);
  Serial.println("setup done");
}

void loop() {
  static auto s_change_direction_time = millis();
  static auto s_last_print_time = millis();
  static bool s_forward = true;

  g_encoder_motor_1.Tick();
  g_encoder_motor_2.Tick();
  g_encoder_motor_3.Tick();
  g_encoder_motor_4.Tick();

  if (millis() - s_change_direction_time > 3000) {
    s_forward = !s_forward;
    s_change_direction_time = millis();
  }

  if (s_forward) {
    g_encoder_motor_1.MoveTo(360, 100);
    g_encoder_motor_2.MoveTo(360, 100);
    g_encoder_motor_3.MoveTo(360, 100);
    g_encoder_motor_4.MoveTo(360, 100);
  } else {
    g_encoder_motor_1.MoveTo(-360, 100);
    g_encoder_motor_2.MoveTo(-360, 100);
    g_encoder_motor_3.MoveTo(-360, 100);
    g_encoder_motor_4.MoveTo(-360, 100);
  }

  if (millis() - s_last_print_time > 500) {
    s_last_print_time = millis();
    Serial.print("is target position reached:");
    Serial.print(g_encoder_motor_1.IsTargetPositionReached());
    Serial.print(g_encoder_motor_2.IsTargetPositionReached());
    Serial.print(g_encoder_motor_3.IsTargetPositionReached());
    Serial.println(g_encoder_motor_4.IsTargetPositionReached());
  }
}
```

### 速度闭环控制

```c++
#include <Arduino.h>
#include <string.h>

#include "encoder_motor.h"

auto g_encoder_motor_1 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE1);
auto g_encoder_motor_2 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE2);
auto g_encoder_motor_3 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE3);
auto g_encoder_motor_4 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE4);

void setup() {
  Serial.begin(115200);
  g_encoder_motor_1.Initialize(12, 90);
  g_encoder_motor_2.Initialize(12, 90);
  g_encoder_motor_3.Initialize(12, 90);
  g_encoder_motor_4.Initialize(12, 90);
  Serial.println("setup done");
}

void loop() {
  static auto s_change_direction_time = millis();
  static auto s_last_print_time = millis();
  static bool s_forward = true;

  g_encoder_motor_1.Tick();
  g_encoder_motor_2.Tick();
  g_encoder_motor_3.Tick();
  g_encoder_motor_4.Tick();

  if (millis() - s_change_direction_time > 5000) {
    s_forward = !s_forward;
    s_change_direction_time = millis();
  }

  if (s_forward) {
    g_encoder_motor_1.RunSpeed(100);
    g_encoder_motor_2.RunSpeed(100);
    g_encoder_motor_3.RunSpeed(100);
    g_encoder_motor_4.RunSpeed(100);
  } else {
    g_encoder_motor_1.RunSpeed(-100);
    g_encoder_motor_2.RunSpeed(-100);
    g_encoder_motor_3.RunSpeed(-100);
    g_encoder_motor_4.RunSpeed(-100);
  }

  if (millis() - s_last_print_time > 100) {
    s_last_print_time = millis();
    Serial.print("current speed: ");
    Serial.print(g_encoder_motor_1.GetCurrentSpeed());
    Serial.print(", ");
    Serial.print(g_encoder_motor_2.GetCurrentSpeed());
    Serial.print(", ");
    Serial.print(g_encoder_motor_3.GetCurrentSpeed());
    Serial.print(", ");
    Serial.println(g_encoder_motor_4.GetCurrentSpeed());
  }
}
```

### 综合示例程序: PS2控制编码电机

```c++
#include <Arduino.h>

#include "PS2X_lib.h"
#include "encoder_motor.h"

namespace {
constexpr uint8_t kPs2Dat = 12;
constexpr uint8_t kPs2Cmd = 11;
constexpr uint8_t kPs2Sel = 10;
constexpr uint8_t kPs2Clk = 13;

constexpr int16_t kMaxEncoderMotorSpeed = 120;

PS2X g_ps2x;
auto g_encoder_motor_1 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE1);
auto g_encoder_motor_2 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE2);
auto g_encoder_motor_3 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE3);
auto g_encoder_motor_4 = emakefun::EncoderMotor::GetEncoderMotor(emakefun::EncoderMotor::kE4);
}  // namespace

void setup() {
  Serial.begin(115200);
  Serial.println("setup done");
  g_ps2x.config_gamepad(kPs2Clk, kPs2Cmd, kPs2Sel, kPs2Dat, false, false);
  g_encoder_motor_1.Initialize(12, 90);
  g_encoder_motor_2.Initialize(12, 90);
  g_encoder_motor_3.Initialize(12, 90);
  g_encoder_motor_4.Initialize(12, 90);
}

void loop() {
  static int16_t s_speed = 0;
  static auto s_read_gamepad_time = millis();
  static auto* s_current_encoder_motor = &g_encoder_motor_1;

  g_encoder_motor_1.Tick();
  g_encoder_motor_2.Tick();
  g_encoder_motor_3.Tick();
  g_encoder_motor_4.Tick();

  if (millis() - s_read_gamepad_time > 50) {
    s_read_gamepad_time = millis();
    g_ps2x.read_gamepad();
    if (g_ps2x.ButtonPressed(PSB_PAD_UP)) {
      s_speed = constrain(s_speed + 10, -kMaxEncoderMotorSpeed, kMaxEncoderMotorSpeed);
      Serial.print("speed up: ");
      Serial.println(s_speed);
      g_encoder_motor_1.RunSpeed(s_speed);
      g_encoder_motor_2.RunSpeed(s_speed);
      g_encoder_motor_3.RunSpeed(s_speed);
      g_encoder_motor_4.RunSpeed(s_speed);
    } else if (g_ps2x.ButtonPressed(PSB_PAD_DOWN)) {
      s_speed = constrain(s_speed - 10, -kMaxEncoderMotorSpeed, kMaxEncoderMotorSpeed);
      Serial.print("speed down: ");
      Serial.println(s_speed);
      g_encoder_motor_1.RunSpeed(s_speed);
      g_encoder_motor_2.RunSpeed(s_speed);
      g_encoder_motor_3.RunSpeed(s_speed);
      g_encoder_motor_4.RunSpeed(s_speed);
    } else if (g_ps2x.ButtonPressed(PSB_TRIANGLE)) {
      g_encoder_motor_1.Move(360, 100);
      g_encoder_motor_2.Move(360, 100);
      g_encoder_motor_3.Move(360, 100);
      g_encoder_motor_4.Move(360, 100);
    } else if (g_ps2x.ButtonPressed(PSB_L1)) {
      Serial.println("current encoder motor change to 1");
      s_current_encoder_motor = &g_encoder_motor_1;
    } else if (g_ps2x.ButtonPressed(PSB_L2)) {
      Serial.println("current encoder motor change to 2");
      s_current_encoder_motor = &g_encoder_motor_2;
    } else if (g_ps2x.ButtonPressed(PSB_R1)) {
      Serial.println("current encoder motor change to 3");
      s_current_encoder_motor = &g_encoder_motor_3;
    } else if (g_ps2x.ButtonPressed(PSB_R2)) {
      Serial.println("current encoder motor change to 4");
      s_current_encoder_motor = &g_encoder_motor_4;
    } else if (g_ps2x.Button(PSB_PAD_LEFT)) {
      s_current_encoder_motor->Move(5, 10);
    } else if (g_ps2x.Button(PSB_PAD_RIGHT)) {
      s_current_encoder_motor->Move(-5, 10);
    } else if (g_ps2x.Button(PSB_CIRCLE)) {
      g_encoder_motor_1.RunSpeed(100);
      g_encoder_motor_2.RunSpeed(100);
      g_encoder_motor_3.RunSpeed(100);
      g_encoder_motor_4.RunSpeed(100);
    } else if (g_ps2x.Button(PSB_SQUARE)) {
      g_encoder_motor_1.RunSpeed(60);
      g_encoder_motor_2.RunSpeed(60);
      g_encoder_motor_3.RunSpeed(60);
      g_encoder_motor_4.RunSpeed(60);
    } else if (g_ps2x.ButtonPressed(PSB_CROSS)) {
      g_encoder_motor_1.Stop();
      g_encoder_motor_2.Stop();
      g_encoder_motor_3.Stop();
      g_encoder_motor_4.Stop();
    }
  }
}
```

## 注意事项

### 误差说明

- 由于普通的编码电机存在一定机械误差，所以速度和位置的闭环控制并不能非常精准，会存在一定误差。
