## 振动马达模块

![1](E:\emakefun-docs\docs\sensors\actuators\Vibration motor module\1.png)

## 概述

振动马达模块，内含一个转子马达，通过马达转动带动转子产生离心引起振动。

许多产品均需要使用振动马达，如智能手机，手表等。

## 原理图

![2](E:\emakefun-docs\docs\sensors\actuators\Vibration motor module\2.png)

## 模块参数

1.供电电压:5V
2.连接方式:3PIN防反接杜邦线
3.模块尺寸:4*2.1cm
4.安装方式:M4螺钉兼容乐高插孔固定

| 引脚名称 | 描述       |
| -------- | ---------- |
| V        | 5V电源引脚 |
| G        | GND 地线   |
| S        | 信号引脚   |





## 机械尺寸



![3](E:\emakefun-docs\docs\sensors\actuators\Vibration motor module\3.png)

## 示例程序

```c
#include "Buzzer.h"

#define ShockAnalogPin A0//
#define ShockDigitalPin 7//
#define BuzzerPin A3//
Buzzer buzzer(BuzzerPin) ;

void setup()
{
    Serial.begin(9600); //
    pinMode(ShockAnalogPin, INPUT);//
   pinMode(ShockDigitalPin, INPUT);//
}

void loop()
{
	buzzer.noTone();//
	Serial.println("Shock Analog Data: ");
	Serial.println(analogRead(ShockAnalogPin)); //
if (digitalRead(ShockDigitalPin) == 0) {//
     for(int i = 200; i <= 800; i++)
     {
       buzzer.tone(i, 10);
     }
     for(int i= 800; i >= 200; i--)
     {
        buzzer.tone(i, 10);
     }
    } 
	delay(1000);
}
```

