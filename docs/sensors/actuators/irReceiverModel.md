# 红外接收传感器模块规格书

![79](红外接收传感器模块图片\79.jpg)

## 概述

红外接收管是直接将电能转化为近红外光的器件，属于二极管类。它的结构和原理与一般的发光二极管相似，只是半导体材料有所不同。红外接收头是一种接收、放大、解调装置，内部集成电路已完成解调，输出是数字信号。红外接收头由IC和PD两部分组成。IC是接收头的处理元件，主要由硅晶体和电路组成。它是一个高度集成的设备。PD是一种光电二极管，主要功能是接收光信号。红外发射二极管发出调制信号，红外接收头经过接收、解码、滤波等一系列操作后恢复信号。

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：4 * 2.1cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| S | 信号引脚 |

## 模块尺寸

![05](红外接收传感器模块图片\05.jpg)

## 连接方式

![01](红外接收传感器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include "IRremote.h"  
int RECV_PIN = 4;  
int a = 0;
IRrecv irrecv(RECV_PIN);
  
decode_results results;
  
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();    
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        if(results.value == 0x4CB3817E & a == 0) 
        {
            Serial.println("Recived: 0x4CB3817E & a == 0");
            a=1;
        }
        else if(results.value == 0x4CB3817E & a == 1)
        {
            Serial.println("Recived: 0x4CB3817E & a == 1");;
            a=0;
        }
        irrecv.resume(); 
    }
    delay(120);
}
```
### 实验效果图

![04](红外接收传感器模块图片\04.jpg)

