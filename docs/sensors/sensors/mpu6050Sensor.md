# MPU6050六轴陀螺仪模块规格书

![85](mpu6050六轴陀螺仪模块图片\85.jpg)

## 概述

MPU6050是InvenSense公司推出全球首例集成3轴陀螺仪与3轴加速器的6轴运动处理组件，可以通过第二个I2C端口连接其他磁力传感器、或其他传感器的数字运动处理(DMP: Digital Motion Processor)硬件加速引擎，主要由I2C端口以单一数据流的形式，向主控端MCU输出完整的9轴融合演算技术。MPU6050芯片内自带了一个数据处理子模块，已经内置了硬件滤波算法，在许多应用中使用输出的数据已经能够很好地满足要求，不需要我们软件再做滤波。

* 以数字输出6轴或9轴的旋转矩阵、四元数(quaternion)、欧拉角格式(Euler Angle forma)的融合演算数据。

* 具有131 LSBs/°/sec 敏感度与全格感测范围为±250、±500、±1000与±2000°/sec 的3轴角速度感测器(陀螺仪)。

* 可程式控制，且程式控制范围为±2g、±4g、±8g和±16g的3轴加速器。

* 数字运动处理(DMP: Digital Motion Processing)引擎可减少复杂的融合演算数据、感测器同步化、姿势感应等的负荷。

* 运动处理数据库支持Android、Linux与Windows。

* 内建运作时间偏差与磁力感测器校正演算技术，免除了客户须另外进行校正的需求。

* 以数位输出的温度传感器。

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
| SDA | IIC 数据引脚 |
|SCL | IIC 时钟引脚 |

## 模块尺寸

![05](mpu6050六轴陀螺仪模块图片\05.jpg)

## 连接方式

![02](mpu6050六轴陀螺仪模块图片\02.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include "Mpu6050Module.h"
Mpu6050Module mpu6050;
void setup()
{
    Serial.begin(9600);
    mpu6050.InitMpu6050();
}

void loop() {
    // get inclination measurements from device
    mpu6050.GetInclination();
    Serial.print(mpu6050.GetGravity(BT_X)); Serial.print(",");
    Serial.print(mpu6050.GetGravity(BT_Y)); Serial.print(",");
    Serial.print(mpu6050.GetGravity(BT_Z)); Serial.print("\n");
}
```

### 实验效果图

![01](mpu6050六轴陀螺仪模块图片\01.jpg)