# 五路循迹模块

## 概述

   五路循迹是具有五组红外发射和接收器件的传感器模块，其原理是红外发射二极管不断发射红外线，当发射出的红外线被物体反射时，被红外接收器接收，并输出模拟值。本模块在支持五路数字输出的基础上，还可以设置红外反射模拟阈值。 模拟量的输出和距离、物体颜色等有关，当红外反射越强(白色)时，输出越小，红外放射越弱(黑色)，输出越大。依据这样的原理我们可以通过输出的模拟量判断距离黑线的远近，数值越大的传感器距离黑线越近，相反数值越小距离黑线越远。

## 硬件参数

- 工作电压：5V
- 通信方式：IIC 
- 接口类型：PH2.0-4Pin (G V SDA SCL)
- 有效高度：0.5cm ~ 4 cm

## 寄存器地址
| 地址 | 描述                                                         |
| :--- | :----------------------------------------------------------- |
| 0x50 | 模块的 IIC地址                                               |
| 0x00 | 红外线反射检测灵敏度配置寄存器，范围0~1000（当传感器读取到的值大于此值时，传感器对应的灯亮，代表识别到黑线） |
| 0x01 | 传感器模拟数据的起始地址，使用时请求10字节数据<br>每两字节表示一路输出0~1023（高8位在后，低8位在前） |
| 0x02 | 传感器状态位地址，读取一字节数据<br/>     bit0  bit1  bit2  bit3  bit4<br/>     inf1  inf2  inf3  inf4  inf5<br/>分别对用五路循迹状态 |


## 引脚定义：
| 引脚名称 | 描述       |
| -------- | ---------- |
| V        | 5V电源引脚 |
| G        | GND 地线   |
| SDA       | IIC数据引脚 |
| SCL       | IIC时钟引脚 |

## 模块尺寸
![infraredtracking](five_way_tracking_sensor/infraredtracking.png)



### arduino函数介绍

```

Sensitivity设置五路循迹模块的检测灵敏度
当对应通道的循迹管脚输出的模拟值高于此灵敏度值时，对应通道的灯亮和状态位置1
void Sensitivity(uint16_t threshold);

获取当前状态位（返回值 bit0 ~ bit4 分别对应红外通道 1 ~ 5）
bit0  bit1  bit2  bit3  bit4
inf1  inf2  inf3  inf4  inf5
uint8_t GetState();

读取全部数据前需要调用GetRawDat刷新数据
void GetRawDat();
```
### arduino示例程序

[下载最新库程序](five_way_tracking_sensor/five_way_tracking_sensor.zip)

```
#include "InfraredTracking.h"

InfraredTracking _5line_track(INFRARED_I2C_ADDR);

void setup() {
    Serial.begin(9600);
/*******************************************
*** Sensitivity 设置五路循迹模块的检测灵敏度(高于此值模块上对应的灯亮)
*** 阈值范围（0~1000）
*******************************************/
    _5line_track.Sensitivity(500);
}

void loop() {
/*******************************************
*** 读取全部数据前需要调用 GetRawDat() 刷新数据
*** ir_track X：分别对应 1-5 路红外循迹管脚的模拟值(0~1023)
*** Threshold： 为红外管脚的临界值，高于此值红外对应的灯亮
*** state： 五路循迹模块状态的数字值（0bit ~ 4bit 对应 1 ~ 5 个红外循迹）
*******************************************/
  _5line_track.GetRawDat();
  Serial.print("line_1: ");
  Serial.print(_5line_track.ir_track1);
  Serial.print(" ");
  Serial.print("line_2: ");
  Serial.print(_5line_track.ir_track2);
  Serial.print(" ");
  Serial.print("line_3: ");
  Serial.print(_5line_track.ir_track3);
  Serial.print(" ");
  Serial.print("line_4: ");
  Serial.print(_5line_track.ir_track4);
  Serial.print(" ");
  Serial.print("line_5: ");
  Serial.println(_5line_track.ir_track5);
//  Serial.print(_5line_track.state);
//  Serial.println();
//  Serial.println();


/*******************************************
*** GetState 获取循迹模块状态的数字值(高于设置的阈值对应位置读取的值为1)
***     bit0  bit1  bit2  bit3  bit4
***     inf1  inf2  inf3  inf4  inf5
***    参数默认是INFRARED_ALL 读取5路循迹状态 
*******************************************/ 
  uint8_t state = _5line_track.GetState();
  Serial.println(state); 
}
```

### MagicBlock图形化编程块

### Mixly图形化块（暂不支持）

### microbit makecode块

### microbit micropython支持
敬请期待。。。。。