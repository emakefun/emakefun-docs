# 12位RGB灯环模块规格书

![01](12位RGB灯环图片\01.jpg)

## 概述

WS2812是一个集控制电路与发光电路于一体的智能外控LED光源。其外型与一个5050LED灯珠相同， 每个元件即为一个像素点。像素点内部包含了智能数字接口数据锁存信号整形放大驱动电路， 还包含有高精度的内部振荡器和12V高压可编程定电流控制部分，有效保证了像素点光的颜色高度一致。数据协议采用单线归零码的通讯方式，像素点在上电复位以后，DIN端接受从控制器传输过来的数据，首先送过来的24bit数据被第一个像素点提取后，送到像素点内部的数据锁存器，剩余的数据经过内部整形处理电路整形放大后通过DO端口开始转发输出给下一个级联的像素点，每经过一个像素点的传输，信号减少24bit。像素点采用自动整形转发技术，使得该像素点的级联个数不受信号传送的限制，仅仅受限信号传输速度要求。LED具有低电压驱动，环保节能，亮度高，散射角度大，一致性好，超低功率，超长寿命等优点。将控制电路集成于上面，电路变得更加简单，体积小，安装更加简便。

## 模块参数

* 工作电压：5V
* 连接方式：4 PIN*2.54 排针
* 模块尺寸：5 * 5cm
* 安装方式：M3螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| DI | 信号输入引脚 |
|DO | 信号输出引脚 |

## 模块尺寸

![02](12位RGB灯环图片\02.jpg)

## 连接方式

![08](12位RGB灯环图片\08.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include "Adafruit_NeoPixel.h"
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500; // delay for half a second
void setup() {
 
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); 
}

void loop() {
  
 for(int i=0;i<NUMPIXELS;i++)
  {

   
    pixels.setPixelColor(i, pixels.Color(0,150,0)); 

    pixels.show(); 

    delay(delayval); 

  }
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(150,0,0)); 
    pixels.show(); 
    delay(delayval);

  }
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,150)); 
    pixels.show(); 
    delay(delayval); 
  }
  for(int i=0;i<NUMPIXELS;i++)
  { 
    pixels.setPixelColor(i, pixels.Color(150,150,150)); 
    pixels.show(); 
    delay(delayval); 

  }
}
```

### 实验效果图

![05](12位RGB灯环图片\05.jpg)