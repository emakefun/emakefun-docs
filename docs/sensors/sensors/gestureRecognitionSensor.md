# 手势传感器模块规格书

![03](手势传感器模块模块图片\03.jpg)

## 概述

 手势检测利用四个方向的光电二极管感应反射的红外能量（由集成LED提供），将物理运动信息（即速度、方向和距离）转换为数字信息。手势引擎的体系结构具有自动激活（基于接近引擎结果）、环境光减法、串音消除、双8位数据转换器、省电的内部转换延迟、32个数据集FIFO和中断驱动的I2C总线通信。手势引擎可满足各种移动设备手势要求：简单的上下左右手势或更复杂的手势可以被准确地感知。通过可调的红外LED定时，功耗和噪音最小化。 

## 模块参数

* 工作电压：5V
* 连接方式：4 PIN 防反接杜邦线
* 模块尺寸：4 * 2.1cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| SDA | IIC 数据引脚 |
|SCL | IIC 时钟引脚 |

## 模块尺寸

![04](手势传感器模块模块图片\04.jpg)

## 连接方式

![08](手势传感器模块模块图片\08.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include <Wire.h>
#include "SparkFun_APDS9960.h"

// Pins
#define APDS9960_INT    2 // Needs to be an interrupt pin

// Constants

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
int isr_flag = 0;

void setup() {

  // Set interrupt pin as input
  pinMode(APDS9960_INT, INPUT);

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - GestureTest"));
  Serial.println(F("--------------------------------"));
  
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  
  // Start running the APDS-9960 gesture sensor engine
  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("Gesture sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }
}

void loop() {

    detachInterrupt(0);
    handleGesture();
    isr_flag = 0;
}

void interruptRoutine() {
  isr_flag = 1;
}

void handleGesture() {
    if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        Serial.println("UP");
        break;
      case DIR_DOWN:
        Serial.println("DOWN");
        break;
      case DIR_LEFT:
        Serial.println("LEFT");
        break;
      case DIR_RIGHT:
        Serial.println("RIGHT");
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
        break;
      case DIR_FAR:
        Serial.println("FAR");
        break;
      default:
        Serial.println("NONE");
    }
  }
}

```

### 实验效果图

![05](手势传感器模块模块图片\05.jpg)