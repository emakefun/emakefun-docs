# 触摸矩阵键盘

## 实物图

![实物图](matrix_keyboard_module/matrix_keyboard_module.png)

## 概述

​		触摸键盘模块是通过 TTP229芯片驱动，共16个触摸键， TTP229芯片是一款使用电容感应式原理设计的触摸芯片。此芯片内建稳压电路供触摸传感器使用，稳定的触摸效果可以应用在各种不同应用上,人体触摸面板可以通过非导电性绝缘材料连接，主要应用是以取代机械开关或按钮,此芯片可以独立支持8个触摸键或16个触摸键. 模块使用IIC通讯。

## 原理图

[原理图下载](matrix_keyboard_module/matrix_keyboard_module_schematic.pdf) 

![原理图](matrix_keyboard_module/matrix_keyboard_module_schematic.png)

## 模块参数

| 引脚名称 |   描述   |
| :------: | :------: |
|    G     | GND 地线 |
|    V     |   VCC    |
|   SCL    | 时钟引脚 |
|   SDO    | 数据引脚 |

- 供电电压:5V

- 两线串行接口

- 连接方式：PH2.0 4PIN防反接线

- 模块尺寸:56*70mm

- 安装方式:M4螺钉兼容乐高插孔固定


## 机械尺寸图

![机械尺寸图](matrix_keyboard_module/matrix_keyboard_module_assembly.png)

## Arduino示例程序

[下载示例程序](matrix_keyboard_module/matrix_keyboard_module.zip)

```c
#include"TTP229.h"
int SCLPin = A5, SDOPin = A4;   //定义 SCL时钟 、SDO数据 端口
unsigned int h = 0, oldh = 0;
TTP229 mTTP229;
char str[128];
void setup()
{
  Serial.begin(9600);   //设置串口波特率为9600
  mTTP229.initTTP229(SCLPin, SDOPin);
}

void loop()
{
  uint16_t keycode = mTTP229.GetKeyCode();
  if (keycode != 0xFFFF) {      //判断按键是否按下
    String key_name = mTTP229.GetKeyMap();
    sprintf(str, "Get ir code: 0x%x key name: %s \n", keycode, (char *)key_name.c_str()); 
    //将按键的值转为字符串
    Serial.println(str);    //打印按键对应的字符
  }
  delay(100);
}
```
## Mixly示例程序

[下载示例程序](matrix_keyboard_module/matrix_keyboard_Mixly_demo.zip)

## Microbit示例程序

<a href="https://makecode.microbit.org/_7TtfV5XKvH50" target="_blank">动手试一试</a>

## MicroBit经典案例

<a href="https://makecode.microbit.org/_KbfXs2JcUir9" target="_blank">矩阵键盘+RGB超声波+LCD1602</a>

**程序讲解**：RGB超声波RGB引脚与Microbit P8引脚相连，IO引脚与P2引脚相连，矩阵键盘的SDO引脚与Microbit P1引脚相连，SCL引脚与P12引脚相连，LCD1602模块接Microbit  I2C接口（SDA引脚与Microbit P20引脚相连，SCL引脚与P19引脚相连）

**现象**：程序上传之后，RGB超声波模块的探头先依次亮红、绿、蓝三种颜色；然后LCD1602显示屏第一行显示超声波测出的距离，第二行显示按下的键盘值。