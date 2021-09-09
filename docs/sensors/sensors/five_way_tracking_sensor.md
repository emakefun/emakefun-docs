# 五路循迹模块

## 概述

五路循迹模块是具有五组红外发射和红外接收器件的传感器，其原理是红外发射二极管不断发射红外线，当发射出的红外线被物体反射时，被红外接收器接收，并输出模拟值。本模块在支持五路模拟输出，五路数字输出的基础上，还可以设置五路循迹模块输出的阈值。 模拟量的输出和距离、物体颜色等有关，当红外反射越强(白色)时，输出越小，红外放射越弱(黑色)，输出越大。依据这样的原理我们可以通过输出的模拟量判断距离黑线的远近，数值越大的传感器离黑线越近，相反数值越小距离黑线越远。

## 硬件参数

- 工作电压：5V
- 通信方式：IIC
- 接口类型：PH2.0-4Pin (G V SDA SCL)

## 模块特点：

## 引脚定义：
| 引脚名称 | 描述       |
| -------- | ---------- |
| V        | 5V电源引脚 |
| G        | GND 地线   |
| SDA       | IIC数据引脚 |
| SCL       | IIC时钟引脚 |

## 模块尺寸

## 接线示例

##  arduino 应用场景

读取五路循迹模块五路模拟值、五路数字值和阈值。
```
#include "InfraredTracking.h"

InfraredTracking inf(INFRARED_I2C_ADDR);

void setup() {
  Serial.begin(9600);
/*******************************************
*** 设置高度（模块底端到地面的垂直距离）
*** 有效距离 0.5cm ~ 4 cm
*******************************************/
  inf.Set_High(4);
}

void loop() {
/*******************************************
*** 读取全部数据前需要调用 flush() 刷新数据
*** INF_X：分别对应 1-5 路红外循迹管脚的模拟值(0~1023)
*** Threshold： 为红外管脚的临界值，高于此值红外对应的灯亮
*** state： 五路循迹模块状态的数字值（0bit ~ 4bit 对应 1 ~ 5 个红外循迹）
*******************************************/
  inf.flush();
  Serial.print("INF_1: ");
  Serial.print(inf.INF_1);
  Serial.print(" ");
  Serial.print("INF_2: ");
  Serial.print(inf.INF_2);
  Serial.print(" ");
  Serial.print("INF_3: ");
  Serial.print(inf.INF_3);
  Serial.print(" ");
  Serial.print("INF_4: ");
  Serial.print(inf.INF_4);
  Serial.print(" ");
  Serial.print("INF_5: ");
  Serial.print(inf.INF_5);
  Serial.print(" ");
  Serial.println();
  Serial.print(inf.state);
  Serial.println();
  Serial.print(inf.Threshold);
  Serial.println();
  delay(200);
}
```
### arduino函数介绍

```
设置模块到地面的高度(有效距离 0.5cm ~ 4cm)
void Set_High(double high);

设置模拟值的阈值函数，输入参数 threshold ，范围 0 ~ 1023
当对应通道的循迹管脚输出的模拟值高于此阈值时，对应通道的灯亮和状态位置1
void Set_Threshold(uint16_t threshold);

获取当前阈值
uint16_t Get_Threshold();

获取当前状态位（返回值 bit0 ~ bit4 分别对应红外通道 1 ~ 5）
bit0  bit1  bit2  bit3  bit4
inf1  inf2  inf3  inf4  inf5
uint8_t Get_State();

读取全部数据前需要调用 flush() 刷新数据
void flush();
```
### arduino示例程序

[下载最新库程序](http://www.emakefun.com/sources/five_way_tracking_sensor.zip)

```
#include "InfraredTracking.h"

InfraredTracking inf(INFRARED_I2C_ADDR);

void setup() {
  Serial.begin(9600);
/*******************************************
*** 设置高度（模块底端到地面的垂直距离）
*** 有效距离 0.5cm ~ 4 cm
*******************************************/
  inf.Set_High(4);
}

void loop() {
/*******************************************
*** 读取全部数据前需要调用 flush() 刷新数据
*** INF_X：分别对应 1-5 路红外循迹管脚的模拟值(0~1023)
*** Threshold： 为红外管脚的临界值，高于此值红外对应的灯亮
*** state： 五路循迹模块状态的数字值（0bit ~ 4bit 对应 1 ~ 5 个红外循迹）
*******************************************/
  inf.flush();
  Serial.print("INF_1: ");
  Serial.print(inf.INF_1);
  Serial.print(" ");
  Serial.print("INF_2: ");
  Serial.print(inf.INF_2);
  Serial.print(" ");
  Serial.print("INF_3: ");
  Serial.print(inf.INF_3);
  Serial.print(" ");
  Serial.print("INF_4: ");
  Serial.print(inf.INF_4);
  Serial.print(" ");
  Serial.print("INF_5: ");
  Serial.print(inf.INF_5);
  Serial.print(" ");
  Serial.println();
//  delay(500);
//  Serial.print(inf.state);
//  Serial.println();
//  Serial.print(inf.Threshold);
//  Serial.println();

/*******************************************
*** Set_Threshold 设置五路循迹模块的阈值(高于此值模块上对应的灯亮)
*** 阈值范围（0~1023）
*******************************************/
//  inf.Set_Threshold(300);
  
/*******************************************
*** Get_Threshold 获取五路循迹模块的阈值
*******************************************/ 
//  int data = inf.Get_Threshold();
//  Serial.println(data);

/*******************************************
*** Get_State 获取五路循迹模块状态的数字值(高于设置的阈值对应位置1)
***     bit0  bit1  bit2  bit3  bit4
***     inf1  inf2  inf3  inf4  inf5
*******************************************/ 
//  uint8_t state = inf.Get_State();
//  Serial.println(state); 
}
```

### MagicBlock图形化编程块

### Mixly图形化块（暂不支持）

### microbit makecode块

### microbit micropython支持
敬请期待。。。。。