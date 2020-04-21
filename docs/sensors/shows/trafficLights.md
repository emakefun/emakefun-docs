# 交通灯模块规格书

![67](E:\GitLab\sensors-kit\37.交通灯模块\交通灯模块图片\67.jpg)

## 概述

LED是发光二极管的缩写，由混合化合物制成，即镓（Ga），砷（AS），磷（P）。 磷化镓二极管发红光，磷化镓二极管发绿光，碳化硅二极管发黄光。发光二极管的反向击穿电压为5v。 其正伏安特性曲线太陡，模块上板载了限流电阻，以便在使用时控制流过管道的电流。交通灯就是板载了3个不同颜色的LED灯，通过控制对应的引脚就可以控制灯的亮灭。

## 模块参数

* 工作电压：5V
* 连接方式：5 PIN 防反接杜邦线
* 模块尺寸：5.6*2.1cm
* 安装方式： M4 螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| - | GND 地线 |
| G | 绿灯引脚 |
| Y | 黄灯引脚 |
| R | 红灯引脚 |

## 模块尺寸

![01](E:\GitLab\sensors-kit\37.交通灯模块\交通灯模块图片\01.jpg)

## 连接方式

![02](E:\GitLab\sensors-kit\37.交通灯模块\交通灯模块图片\02.jpg)

##  arduino 应用场景

### arduino 控制LED模块程序代码
```c++
#define RGB_RED    11
#define RGB_GREEN  10
#define RGB_BLUE   9

void setup()
{
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
}
 
void loop()
{
     analogWrite(RGB_RED,1);
     delay(500);
     analogWrite(RGB_GREEN,1);
     delay(500);
     analogWrite(RGB_BLUE,1);
     delay(500);
     analogWrite(RGB_RED,0);
     delay(500);
     analogWrite(RGB_GREEN,0);
     delay(500);
     analogWrite(RGB_BLUE,0);
     delay(500);
}
```

### 实验效果图

![03](E:\GitLab\sensors-kit\37.交通灯模块\交通灯模块图片\03.jpg)