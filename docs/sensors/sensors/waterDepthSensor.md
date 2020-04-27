# 光敏电阻传感器模块规格书

![110](水位检测传感器模块图片\110.jpg)

## 概述

水深传感器专为水质检测而设计，可广泛用于感应降雨，水位，甚至液体泄漏。
该传感器的工作原理是将一系列暴露的走线连接到地，并在接地走线之间交错，即感应走线。传感器走线具有1MΩ的弱上拉电阻。电阻器将传感器迹线值拉高，直到一滴水使传感器走线短路到接地走线。可以将它与模拟引脚配合使用，以检测接地和传感器走线之间的水接触量。

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：5.6 * 2.1cm
* 安装方式：M3螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| S | 信号引脚 |

## 模块尺寸

![05](水位检测传感器模块图片\05.jpg)

## 连接方式


##  arduino 应用场景

### arduino 程序代码

```c++
int analogPin=A0;
double temp,data;
void setup() {
    pinMode(analogPin,INPUT);
    Serial.begin(9600);
}

void loop() {   
    temp=(long)analogRead(analogPin);
    data=(temp/650)*4;
    Serial.print("the depth is:");
    Serial.print(data);
    Serial.println("cm");
    delay(1000);
}
```

### 实验效果图

![03](水位检测传感器模块图片\03.jpg)