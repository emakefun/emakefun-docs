# MQ-4气体传感器规格书

##  实物图

![实物图](mq_gas_sensor/mq_gas_sensor.png)

## 概述

​			MQ-4天然气传感器所使用的气敏材料是在清洁空气中电导率较低的二氧化锡(SnO2)。当传感器所处环境中存在可燃气体时，传感器的电导率随空气中可燃气体浓度的增加而增大。使用简单的电路即可将电导率的变化转换为与该气体浓度相对应的输出信号。MQ-4天然气检测传感器对甲烷的灵敏度高，对丙烷、丁烷也有较好的灵敏度。这种传感器可检测多种可燃性气体，特别是天然气，是一款适合多种应用的低成本传感器。

## 原理图

[查看原理图](mq_gas_sensor/mq_gas_sensor_schematic.pdf) 
![原理图](mq_gas_sensor/mq_gas_sensor_schematic.png)

## 模块参数

| 引脚名称 |     描述     |
| :------: | :----------: |
|    G     |     GND      |
|    V     |     VCC      |
|    A     | 模拟信号引脚 |
|    D     | 数字信号引脚 |

- 供电电压:3v3/5V

- 连接方式:4PIN防反接杜邦线

- 模块尺寸:40 x 22.5 mm

- 安装方式:M4螺钉兼容乐高插孔固定

## 机械尺寸图

![机械尺寸图](mq_gas_sensor/mq_gas_sensor_assembly.png)

## Arduino示例程序

 [下载示例程序](mq_gas_sensor/mq_gas_sensor.zip)

```c++
#include "Buzzer.h"

#define GaslDigitalPin  7//定义气体传感器数字引脚
#define GasAnalogPin   A0//定义气体传感器模拟引脚
#define BuzzerPin A3//定义无源蜂鸣器块引脚

Buzzer buzzer(BuzzerPin) ;
int  GasAnalogValue = 0 ;//定义数字变量,读取火焰模拟值
int  GasDigitalValue = 0 ;//定义数字变量,读取火焰数字值

void setup()
{
    Serial.begin(9600); //设置串口波特率为9600
    pinMode(GasDigitalPin, INPUT);//设置气体传感器数字引脚为输入
   pinMode(GasAnalogPin, INPUT);//设置气体传感器模拟引脚为输入
   pinMode(BuzzerPin, OUTPUT);//设置无源蜂鸣器模块引脚为输出
}

void loop()
{ 
    buzzer.noTone();//蜂鸣器停止
    GasAnalogValue = analogRead(GasAnalogPin);
    GasDigitalValue = digitalRead(GaslDigitalPin)
    Serial.print("GasAnalog Data:  ");
    Serial.print(GasAnalogValue);//打印气体传感器模拟值
    Serial.print("       GasDigital Data:  ");
    Serial.println(GasDigitalValue);//打印气体传感器数字值
 if (GasDigitalValue == 0) {//判断气体传感器是否检测到火焰  检测到有害气体  蜂鸣器报警 
     for(int i = 200; i <= 800; i++)
     {
       buzzer.tone(i, 10);
     }
     for(int i= 800; i >= 200; i--)
     {
        buzzer.tone(i, 10);
     }
  }
}
```

## microbit示例程序

<a href="https://makecode.microbit.org/_A9cLTEb0o49g" target="_blank">动手试一试</a>