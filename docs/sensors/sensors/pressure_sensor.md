# 压力传感器模块

## 实物图

![实物图](pressure_sensor/pressure_sensor_module.png)

## 概述

​		薄膜压力传感器模块是基于新型纳米压敏材料辅以舒适杨式模量的超薄薄膜衬底一次性贴片而成，兼具防水和压敏双重功能。当传感器感知到外界的压力变化虎，传感器电阻值发生变化，我们采用电路讲传感器感知到的压力信号转换成相应变化的强度电信号输出。这样我们就可以通过检测电信号的变化就可以得知压力的变化情况。

## 原理图
 [查看原理图](pressure_sensor/Pressure_Sensor.pdf) 
![原理图](pressure_sensor/pressure_sensor_module_schematic.png)

## 模块参数

| 引脚名称 |   描述   |
| :------: | :------: |
|    G     |   GND    |
|    V     |   VCC    |
|    S     | 数字引脚 |
- 工作电压：3v3/5V
- 连接方式：3 PIN 防反接杜邦线
- 模块尺寸：40 x 22.5 mm
- 安装方式：M4螺钉兼容乐高插孔固定

## 机械尺寸图

![机械尺寸图](pressure_sensor/pressure_sensor_module_assembly.png)

## Arduino示例程序

[下载示例程序](pressure_sensor/pressure_sensor.zip)

```c++
#define AnalogPin   A0//定义压力传感器模拟引脚

int  AnalogValue = 0 ;//定义数字变量,读取火焰模拟值

void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(AnalogPin, INPUT);//设置压力传感器模拟引脚为输入
}
void loop()
{
  AnalogValue = analogRead(AnalogPin);//读取压力传感器模拟值
  Serial.print("Analog Data:  ");
  Serial.print(AnalogValue);//打印压力传感器模拟值
  delay(200);
}
```

## microbit示例程序

