# 声音传感器模块规格书

![01](E:\GitLab\sensors-kit\11.声音传感器模块\声音传感器模块图片\01.jpg)

## 概述

  声音传感器模块的作用相当于一个话筒(麦克风)。它用来接收声波，显示声音的振动图象，但不能对噪声的强度进行测量。该传感器内置一个对声音敏感的电容式驻极体话筒。声波使话筒内的驻极体薄膜振动，导致电容的变化，而产生与之对应变化的微小电压。这一电压随后被转化成0-5V的电压，经过A/D转换被数据采集器接受，并传送给主控芯片。

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
| A | 模拟信号引脚 |
| D |数字信号引脚|

## 模块尺寸

![02](E:\GitLab\sensors-kit\11.声音传感器模块\声音传感器模块图片\02.jpg)

## 连接方式

![06](E:\GitLab\sensors-kit\11.声音传感器模块\声音传感器模块图片\06.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int analogPin=A0;
int value=0;

void setup()
{
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    value= analogRead(analogPin);
    Serial.println(value);
    delay(200);
}
```

### 实验效果图

![05](E:\GitLab\sensors-kit\11.声音传感器模块\声音传感器模块图片\05.jpg)