# 8X8点阵模块规格书

![95](E:\GitLab\sensors-kit\40.8X8点阵模块\8X8点阵模块图片\95.jpg)

## 概述

​     8X8点阵模块由MAX7219驱动，MAX7219是一种集成化的串行输入/输出显示驱动器,它连接微处理器与8位数字的7段数字LED显示，也可以连接条线图显示器或者64个独立的LED。其上包括一个片上的B型BCD编码器、多路扫描回路，段字驱动器，而且还有一个8X8的静态RAM用来存储每一个数据。只有一个外部寄存器用来设置各个LED的段电流。一个方便的五线串行接口可以联接通用的微处理器。每个数据可以寻址在更新时不需要改写所有的显示。MAX7219同样允许用户对每一个数据选择编码或者不编码。整个设备包含一个150μA的低功耗关闭模式，模拟和数字亮度控制，一个扫描限制寄存器允许用户显示1-8位数据，还有一个让所有LED发光的检测模式。如果用普通的方法来驱动一个8*8的点阵，需要用到8个单片机IO,2个就是16个IO ，如果驱动几个点阵，单片机的IO就不够了，如果用MAX7219帮忙的话，用单片机的3个IO口就可以驱动1个/10个/20个点阵。  

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：4* 3.2cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| CLK | 信号引脚 |
| CS |片选引脚 |
| DIN | 数据输入引脚 |



## 模块尺寸

![01](E:\GitLab\sensors-kit\40.8X8点阵模块\8X8点阵模块图片\01.jpg)

## 连接方式

![03](E:\GitLab\sensors-kit\40.8X8点阵模块\8X8点阵模块图片\03.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include "MAX7219_MaxMatrix.h"
 
#define PIN_DIN    7   //max 7219
#define PIN_CS     6
#define PIN_CLK    5

MaxMatrix ledmatrix(PIN_DIN,PIN_CS,PIN_CLK, 1);  

void setup(){
  ledmatrix.init();
  ledmatrix.setIntensity(1);
  ledmatrix.clearMatrix();
}

void loop() {
 for(int i=0;i<=30;i++)
 {
  ledmatrix.writeFull(ledmatrix.getMouthShape(i));
  delay(1000);
 }
}
```

### 实验效果图

![04](E:\GitLab\sensors-kit\40.8X8点阵模块\8X8点阵模块图片\04.jpg)