# 触摸模块

## 模块图

![Touch Module](touch_module/touch_module.png)

## 概述

​        触摸传感器模块是一个基于触摸检测IC（TTP223B）的电容式点动型触摸开关模块。可以将模块安装在非金属材料如塑料、玻璃的表面，另外将薄薄的纸片（非金属）覆盖在模块的表面，只要触摸的位置正确，即可做成隐藏在墙壁、桌面等地方的按键。


## 原理图

![原理图](touch_module/schematic.png)

## 模块参数

* 1.供电电压:5V
* 2.模块尺寸:4*2.1cm
* 3.S:信号输出引脚，触摸按键按下时输出高电平，板子蓝色信号灯亮起
* 4.安装方式:M4螺钉兼容乐高插孔固定

## 原理图和数据手册

  [查看原理图](touch_module/schematic.pdf) 

  [查看数据手册](touch_module/ttp223_datasheet.pdf) 

## 装配尺寸图

![装配](touch_module/assembly_drawing.png)

## 示例程序

```c
int touch_PIN = 3 ;  //GPIO 3  touch pin
int led_out = 13 ;   //GPIO A3  LED pin
int value = 0 ;
void setup()
{
    pinMode(touch_PIN, INPUT);              // init touch pin output
    pinMode(led_out, OUTPUT);               // init led pin output
}
void loop()
{
        value = digitalRead(touch_PIN);    // read touch pin vaule
        if (value == HIGH)
        {
            digitalWrite(led_out,HIGH);      // if touch turn on LED
        }
        else
        {
            digitalWrite(led_out,LOW);      //   turn off LED
        }
}
```

## microbit示例程序
请直接参考microbit图形化编程[makecode库链接](https://github.com/emakefun/pxt-sensorbit)里面的基础输入部分触摸按键图形化编程块介绍

