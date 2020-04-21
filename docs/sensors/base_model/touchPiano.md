# 触摸钢琴模块规格书

![119](E:\GitLab\sensors-kit\42.触摸钢琴模块\触摸钢琴模块图片\119.jpg)

## 概述

​      触摸钢琴模块原理是通过分布在芯片端口的电容因为手指的接触，使电容发生了改变，经芯片处理后能将微小的电容变化转化成电压信号的变化，再通过软件AD采集端口电压，根据电压的变化实现触摸的识别。实际上MCU去获取的只是具体的键值，而要真正的模拟钢琴的声音，需要MCU在做进一步的处理，例如驱动蜂鸣器以不同的频率响。模块使用IIC通讯方式。

## 模块参数

* 工作电压：5V
* 连接方式：4 PIN 防反接杜邦线
* 模块尺寸：10.8 * 3.6cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| DIO | 数据引脚 |
|SCL | 时钟引脚   |

## 模块尺寸

![115](E:\GitLab\sensors-kit\42.触摸钢琴模块\触摸钢琴模块图片\115.jpg)

## 连接方式

![02](E:\GitLab\sensors-kit\42.触摸钢琴模块\触摸钢琴模块图片\02.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++

#include"BS818A.h"
BS818A BS;
void setup()
{
  Serial.begin(9600);
  BS.InitBS818A(A4, A5);
}


void loop()
{
  if (BS.PressBsButton(BS_KEYCODE_1))
    Serial.println("1");
  if (BS.PressBsButton(BS_KEYCODE_2))
    Serial.println("2");
  if (BS.PressBsButton(BS_KEYCODE_3))
    Serial.println("3");
  if (BS.PressBsButton(BS_KEYCODE_4))
    Serial.println("4");
  if (BS.PressBsButton(BS_KEYCODE_5))
    Serial.println("5");
  if (BS.PressBsButton(BS_KEYCODE_6))
    Serial.println("6");
  if (BS.PressBsButton(BS_KEYCODE_7))
    Serial.println("7");
  if (BS.PressBsButton(BS_KEYCODE_8))
    Serial.println("8");
}


```

### 实验效果图

![01](E:\GitLab\sensors-kit\42.触摸钢琴模块\触摸钢琴模块图片\01.jpg)

