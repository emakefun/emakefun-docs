# 五路循迹模块V2.0

## 概述

五路循迹是一款基于红外感光原理的传感器模块，它包含五组红外发射和接收器件。当红外发射二极管发射红外线时，若有物体反射红外线，红外接收器就会接收到反射回来的信号，并输出模拟电压值。传感器输出的电压值与反射的强弱成反比关系，即反射越强，输出电压越小；反射越弱，输出电压越大。

本模块支持五路数字输出，并且可以设置红外反射模拟阈值。通过读取传感器的模拟电压值，可以判断传感器距离黑线的远近。数值越大的传感器距离黑线越近，相反数值越小传感器距离黑线越远。

使用该传感器模块，你可以通过读取传感器的数字输出或模拟电压值来实现循迹或避障等功能。具体的使用方法，请参考本库的示例代码和API文档。

## 硬件参数

- 工作电压：5V
- 通信方式：IIC
- 接口类型：PH2.0-4Pin (G V SDA SCL)
- 有效高度：0.5cm ~ 4 cm

## 寄存器地址

| 地址   | 描述 |
|:-----|:-----|
| 0x50 | 模块的 IIC地址 |
| 0x00 | 红外线反射检测灵敏度配置寄存器，范围0~1000（当传感器读取到的值大于此值时，传感器对应的灯灭，代表识别到黑线）|
| 0x02 | 传感器模拟数据的起始地址，使用时请求10字节数据 <br> 每两字节表示一路输出0~1023（高8位在前，低8位在后）|
| 0x0c | 传感器状态位地址，读取一字节数据 <br> bit0 bit1 bit2 bit3 bit4 <br> inf1 inf2 inf3 inf4 inf5 <br> 分别对用五路循迹状态，0代表识别到黑线，1代表未识别到黑线 |

## 引脚定义

| 引脚名称 | 描述 |
|------|---------|
| V    | 5V电源引脚  |
| G    | GND 地线  |
| SDA  | IIC数据引脚 |
| SCL  | IIC时钟引脚 |

## 模块尺寸

![模块尺寸](five_way_tracking_sensor/infraredtracking.png)

## Arduino应用场景

### Arduino 示例程序

[下载Arduino库](https://github.com/emakefun-arduino-library/emakefun_five_line_tracker/archive/refs/tags/release.zip)，包含Arduino库文件和示例代码

### Arduino 库使用文档

[说明文档](https://github.com/emakefun-arduino-library/emakefun_five_line_tracker#linetracker-library-v20)

### Arduino 库示例程序

[示例程序](https://github.com/emakefun-arduino-library/emakefun_five_line_tracker#%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81)

### MagicBlock图形化编程块

### Mixly图形化块（暂不支持）

### microbit makecode块

### microbit micropython支持

敬请期待
