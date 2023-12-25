# 矩阵键盘模块V3.0

## 概述

触摸键盘模块是通过[BS8116A-3](matrix_keyboard_module_v2.0/BS8116A-3.pdf)芯片驱动，共16个触摸键。[BS8116A-3](matrix_keyboard_module_v2.0/BS8116A-3.pdf)芯片是一款使用电容感应式原理设计的触摸芯片,可用来检测外部触摸按键上人手的触摸动作。该系列的芯片具有较高的集成度，仅需极少的外部组件便可实现触摸按键的检测。BS81x 系列提供了串行及并行输出功能，可方便与外部 MCU 之间的通讯，实现设备安装及触摸引脚监测目的。 模块使用IIC通讯。

## 模块图

TODO

## 原理图

TODO

## 模块参数

- 供电电压:3.3V ~ 5V
- 两线串行接口
- 连接方式：PH2.0 4PIN防反接线
- 模块尺寸:56*70mm
- 安装方式:M4螺钉兼容乐高插孔固定

| G      | GND地线|
| :----- | :---: |
| V    | VCC|
| SCL   | 时钟引脚|
| SDA   | 数据引脚|

## 模块尺寸

TODO

## 软件

### Arduino（C/C++）

| 支持开发板系列 |
| --- |
| Arduino UNO R3 |
| Arduino Nano |
| Arduino Mega 2560 |
| ESP32 |

#### 库文件

[点击此处下载Arduino库](https://github.com/emakefun-arduino-library/emakefun_matrix_keyboard_v3/archive/refs/tags/latest.zip)

包含了Arduino库文件和示例代码

#### API说明文档

[点击此处查看API说明文档](https://emakefun-arduino-library.github.io/emakefun_matrix_keyboard_v3/class_matrix_keyboard.html)

#### 示例程序

[点击此处查看示例程序](https://emakefun-arduino-library.github.io/emakefun_matrix_keyboard_v3/get_touched_key_8ino-example.html)

### Micropython

| 支持开发板系列 |
| --- |
| ESP32 |
| ESP32S3 |

#### Micropython 库文件

| 库文件名 | 链接 |
| --- | --- |
| i2c_device.py | [https://github.com/emakefun-org/micropython_library/blob/main/i2c_device.py](https://github.com/emakefun-org/micropython_library/blob/main/i2c_device.py) |
| matrix_keyboard_v3.py | [https://github.com/emakefun-org/micropython_library/blob/main/matrix_keyboard_v3.py](https://github.com/emakefun-org/micropython_library/blob/main/matrix_keyboard_v3.py) |

请将以上的库文件上传到板子上

#### Micropython example

示例1：[获取按键值: https://github.com/emakefun-org/micropython_examples/blob/main/matrix_keyboard_v3/main.py](https://github.com/emakefun-org/micropython_examples/blob/main/matrix_keyboard_v3/main.py)
