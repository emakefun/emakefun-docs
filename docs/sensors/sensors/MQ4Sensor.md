# MQ-4气体传感器规格书

![01](E:\GitLab\sensors-kit\24.MQ-4气体传感器\MQ-4气体传感器图片\01.jpg)

## 概述

 MQ-4天然气传感器所使用的气敏材料是在清洁空气中电导率较低的二氧化锡(SnO2)。当传感器所处环境中存在可燃气体时，传感器的电导率随空气中可燃气体浓度的增加而增大。使用简单的电路即可将电导率的变化转换为与该气体浓度相对应的输出信号。MQ-4天然气检测传感器对甲烷的灵敏度高，对丙烷、丁烷也有较好的灵敏度。这种传感器可检测多种可燃性气体，特别是天然气，是一款适合多种应用的低成本传感器。

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
| A | 模拟信号引脚 |
|D | 数字信号引脚 |

## 模块尺寸

![02](E:\GitLab\sensors-kit\24.MQ-4气体传感器\MQ-4气体传感器图片\02.jpg)

## 连接方式

![15](E:\GitLab\sensors-kit\24.MQ-4气体传感器\MQ-4气体传感器图片\15.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int SensorPin=11;      
void setup() 
{  
  pinMode(SensorPin,INPUT);
  Serial.begin(9600);
}  
void loop() 
{  
  val=digitalRead(SensorPin);
  Serial.println(val);
  delay(100);
}
```

### 实验效果图

![13](E:\GitLab\sensors-kit\24.MQ-4气体传感器\MQ-4气体传感器图片\13.jpg)