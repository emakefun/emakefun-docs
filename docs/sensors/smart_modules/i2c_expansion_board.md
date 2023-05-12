# 8 路 ADC/I2C/IO 三合一口扩展板

## 模块实物图

![实物图](i2c_expansion_board/i2c_expansion_board.png)

## 概述

  该模块是 emakefun 为了解决创客在使用中，主板的 adc/io/i2c 不够用的场景而开发的一块扩展板，可以扩展4 路 i2c接口，8路io口可以通过软件分别配置成adc，输入，输出模式。配置接口为I2C接口，地址为0x24

## 模块参数

| 引脚名称 | 描述         |
| -------- | ------------ |
| G        | GND 地线     |
| V        | 3~5V电源引脚 |
| SDA      | I2C数据引脚  |
| SDL      | I2C时钟引脚  |

## 硬件尺寸图

## arduino 应用场景

### arduino 函数介绍

```c++
#pragma once

#include <stdint.h>

/**
 * @class I2cExpansionBoard
 * @brief I2C扩展板主类
 */
class I2cExpansionBoard {
 public:
  /**
   * @enum GpioMode
   * @brief 扩展板GPIO模式类型
   */
  enum GpioMode : uint8_t {
    kNone = 0,
    kInputPullUp = 1 << 0,   /**< 输入模式，默认拉高电平*/
    kInputPullDown = 1 << 1, /**< 输入模式，默认拉低电平*/
    kInputFloating = 1 << 2, /**< 浮空输入模式*/
    kOutput = 1 << 3,        /**< 输出模式*/
    kAdc = 1 << 4,           /**< ADC模式*/
    kPwm = 1 << 5,           /**< PWM输出模式*/
  };

  /**
   * @enum GpioPin
   * @brief 扩展板GPIO引脚
   */
  enum GpioPin : uint8_t {
    kGpioPinE0 = 0, /**< 引脚E0*/
    kGpioPinE1 = 1, /**< 引脚E1*/
    kGpioPinE2 = 2, /**< 引脚E2*/
    kGpioPinE3 = 3, /**< 引脚E3*/
    kGpioPinE4 = 4, /**< 引脚E4*/
    kGpioPinE5 = 5, /**< 引脚E5*/
    kGpioPinE6 = 6, /**< 引脚E6*/
    kGpioPinE7 = 7, /**< 引脚E7*/
  };

  /**
   * @brief 扩展板默认I2C地址
   */
  enum { kDeviceI2cAddressDefault = 0x24, /**< 默认I2C地址：0x24*/ };

  /**
   * @brief 构造函数
   * @param [in] device_i2c_address 扩展板I2C地址，默认值为0x24, @see kDeviceI2cAddressDefault
   */
  I2cExpansionBoard(uint8_t device_i2c_address = kDeviceI2cAddressDefault);

  /**
   * @brief 设置GPIO模式
   * @param [in] gpio_pin GPIO引脚 @see GpioPin
   * @param [in] mode GPIO模式 @see GpioMode
   * @return bool 成功返回true，失败返回false
   */
  bool SetGpioMode(GpioPin gpio_pin, GpioMode mode);

  /**
   * @brief 设置GPIO输出电平
   * @param [in] gpio_pin GPIO引脚 @see GpioPin
   * @param [in] level 电平值，0为低电平，1为高电平
   * @return bool 成功返回true，失败返回false
   */
  bool SetGpioLevel(GpioPin gpio_pin, uint8_t level);

  /**
   * @brief 获取GPIO输出电平
   * @param [in] gpio_pin GPIO引脚 @see GpioPin
   * @return uint8_t 电平值，0为低电平，1为高电平
   */
  uint8_t GetGpioLevel(GpioPin gpio_pin);

  /**
   * @brief 获取GPIO ADC电平值
   * @param [in] gpio_pin GPIO引脚 @see GpioPin
   * @return uint16_t ADC电平值
   */
  uint16_t GetGpioAdcValue(GpioPin gpio_pin);

  bool SetPwmFrequency(uint32_t frequency);

  bool SetPwmDuty(GpioPin gpio_pin, uint8_t duty);

  /**
   * @brief 驱动舵机转动到指定角度
   * @note 只支持E1 ~ E2
   * @param [in] gpio_pin GPIO引脚 @see GpioPin
   * @param [in] angle 角度值，范围0 ~ 180
   * @return bool 成功返回true，失败返回false
   */
  bool SetServoAngle(GpioPin gpio_pin, float angle);

 private:
  uint8_t device_i2c_address_;
};

```

### Arduino 示例程序

[下载Arduino库](i2c_expansion_board/emakefun_i2c_expansion_board.zip)

#### ADC输入

```c++
#include <Arduino.h>

#include "i2c_expansion_board.h"

// 创建 I2cExpansionBoard 实例
I2cExpansionBoard i2c_expansion_board;

void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  Serial.println("setup");

  // 配置E0为ADC模式
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE0, I2cExpansionBoard::kAdc);
}

void loop() {
  Serial.print("adc value:");
  // 读取E0的ADC值并打印
  Serial.println(i2c_expansion_board.GetGpioAdcValue(I2cExpansionBoard::kGpioPinE0));
  delay(100);
}

```

#### 数字高低电平输入

```c++

#include <Arduino.h>

#include "i2c_expansion_board.h"

// 创建 I2cExpansionBoard 实例
I2cExpansionBoard i2c_expansion_board;

void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  Serial.println("setup");

  // 配置E0为输入模式，默认拉高电平
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE0, I2cExpansionBoard::kInputPullDown);
}

void loop() {
  Serial.print("digital value:");
  // 读取E0的数字值并打印
  Serial.println(i2c_expansion_board.GetGpioLevel(I2cExpansionBoard::kGpioPinE0));
  delay(100);
}

```

#### 数字高低电平输出

```c++

#include <Arduino.h>

#include "i2c_expansion_board.h"

// 创建 I2cExpansionBoard 实例
I2cExpansionBoard i2c_expansion_board;

void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  Serial.println("setup");

  // 配置E0为输出模式
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE0, I2cExpansionBoard::kOutput);
}

void loop() {
  // 设置E0的输出高电平
  i2c_expansion_board.SetGpioLevel(I2cExpansionBoard::kGpioPinE0, 1);
  delay(100);
  // 设置E0的输出低电平
  i2c_expansion_board.SetGpioLevel(I2cExpansionBoard::kGpioPinE0, 0);
  delay(100);
}

```

#### 舵机控制(只支持E1 ~ E2)

```c++

#include <Arduino.h>

#include "i2c_expansion_board.h"

// 创建 I2cExpansionBoard 实例
I2cExpansionBoard i2c_expansion_board;

void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  Serial.println("setup");
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE1, I2cExpansionBoard::kPwm);
  i2c_expansion_board.SetGpioMode(I2cExpansionBoard::kGpioPinE2, I2cExpansionBoard::kPwm);
}

// 注意，舵机控制只支持E1 ~ E2
void loop() {
  // 设置E1舵机转动到0度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE1, 0);
  delay(500);

  // 设置E2舵机转动到0度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE2, 0);
  delay(500);

  // 设置E1舵机转动到90度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE1, 90);
  delay(500);

  // 设置E2舵机转动到90度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE2, 90);
  delay(500);

  // 设置E1舵机转动到180度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE1, 180);
  delay(500);

  // 设置E2舵机转动到180度位置
  i2c_expansion_board.SetServoAngle(I2cExpansionBoard::kGpioPinE2, 180);
  delay(500);
}

```

### Mixly示例程序

![](i2c_expansion_board/i2c_expansion_board_mixly.png)

[下载mixly示例程序](i2c_expansion_board/i2c_expansion_board_mixly.zip)
