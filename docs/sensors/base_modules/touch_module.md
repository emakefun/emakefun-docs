# 触摸模块

## 实物图

![实物图](touch_module/touch_module.png)

## 概述

​        触摸传感器模块是一个基于触摸检测IC（TTP223B）的电容式点动型触摸开关模块，当模块的金属触片被触摸，相当于按键被按下。我们可以将模块安装在非金属材料如塑料、玻璃的表面，另外将薄薄的纸片（非金属）覆盖在模块的表面，只要触摸的位置正确，即可做成隐藏在墙壁、桌面等地方的按键。我们的模块当被触摸时，蓝色灯亮，输出高电平，否则蓝色灯熄灭，输出低电平。


## 原理图

![原理图](touch_module/touch_module_schematic.png)

## 模块参数

| 引脚名称 |                          描述                          |
| :------: | :----------------------------------------------------: |
|    G     |                          GND                           |
|    V     |                         5V电源                         |
|    S     | 信号输出引脚，当被触摸时，输出低电平，松开时输出高电平 |

- 供电电压：5V
- 连接方式：PH2.0 3PIN防反接线

- 模块尺寸：40x22.5mm

- 安装方式：M4螺钉兼容乐高插孔固定

## 原理图和数据手册

[查看原理图](touch_module/touch_module_schematic.pdf) 

[查看数据手册](touch_module/ttp223_datasheet.pdf) 

## 机械尺寸图

![机械尺寸图](touch_module/touch_module_assembly.png)

## Arduino示例程序

[下载示例程序](touch_module/touch_module.zip)

```c
int touch_pin = A3; //定义触摸按键引脚
int led_out = A2; //定义LED引脚
int value = 0 ;
void setup()
{
  pinMode(touch_pin, INPUT); //初始化触摸按键连接的引脚为输入
  pinMode(led_out, OUTPUT); //初始化LED连接的引脚为输出引脚
}
void loop()
{
  value = digitalRead(touch_pin); //读取按键输入引脚的值
   if (value == LOW)
   {
    digitalWrite(led_out,HIGH); //如果读取值为低即被触摸到了，LED亮
    }
   else
   {
      digitalWrite(led_out,LOW); //如果读取值为高即没有触摸按键，LED灭
    }
}
```

## microbit示例程序
请直接参考microbit图形化编程[makecode库链接](https://github.com/emakefun/pxt-sensorbit)里面的基础输入模块的触摸模块。

