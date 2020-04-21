# 触摸键盘模块规格书

![主图6](E:\GitLab\sensors-kit\PH2.0模块规格书\49.触摸键盘模块\触摸键盘模块图片\主图6.jpg)

## 概述

触摸键盘模块是通过 TTP229芯片驱动，共16个触摸键， TTP229芯片是一款使用电容感应式原理设计的触摸芯片。此芯片内建稳压电路供触摸传感器使用，稳定的触摸效果可以应用在各种不同应用上,人体触摸面板可以通过非导电性绝缘材料连接，主要应用是以取代机械开关或按钮,此芯片可以独立支持8个触摸键或16个触摸键. 模块使用IIC通讯。

## 模块参数

* 工作电压：5V
* 连接方式：4 PIN 防反接杜邦线
* 模块尺寸：7 * 5.5cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| SCL | 时钟引脚 |
| SDO | 数据引脚 |

## 模块尺寸

![主图5](E:\GitLab\sensors-kit\PH2.0模块规格书\49.触摸键盘模块\触摸键盘模块图片\主图5.jpg)

## 连接方式

![主图1](E:\GitLab\sensors-kit\PH2.0模块规格书\49.触摸键盘模块\触摸键盘模块图片\主图1.jpg)


##  arduino 应用场景

### arduino  程序代码

```c++
#include"TTP229.h"
#define KEY_VALUE_A A;
#define KEY_VALUE_B A;
#define KEY_VALUE_C A;
#define KEY_VALUE_D A;
#define KEY_VALUE_# #;
#define KEY_VALUE_* *;

int SCLPin = A5, SDOPin = A4;
unsigned int h = 0, oldh = 0;
TTP229 mTTP229;
char str[128];
void setup()
{
  Serial.begin(9600);
  mTTP229.initTTP229(SCLPin, SDOPin);

}

void loop()
{
  uint16_t keycode = mTTP229.GetKeyCode();
  if (keycode != 0xFFFF) {
    String key_name = mTTP229.GetKeyMap();
    sprintf(str, "Get ir code: 0x%x key name: %s \n", keycode, (char *)key_name.c_str());
    Serial.println(str);
  }
  delay(100);
}
```

### 实验效果图

![主图2](E:\GitLab\sensors-kit\PH2.0模块规格书\49.触摸键盘模块\触摸键盘模块图片\主图2.jpg)