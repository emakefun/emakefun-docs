# 触碰开关传感器模块规格书

![39](E:\GitLab\sensors-kit\25.触碰开关传感器模块\触碰开关传感器模块图片\39.jpg)

## 概述

触碰开关传感器模块实质为一个微型快动开关，即广为人知的微型开关，是一种由很小的物理力启动的电子开关。它能够直接连在单片机上。它将负载电阻同LED指示灯整合在一起。这使得对他进行测试更为简单。当有物理压力触发开关闭合时，板上的LED指示灯会亮起。

常见应用于：

- 电梯的安全开关和水平测试
- 微波炉的门联锁装置
- 自动贩卖机
- 检测影印机里的纸堵塞或其他故障
- 3D影印机定位反馈等

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

![05](E:\GitLab\sensors-kit\25.触碰开关传感器模块\触碰开关传感器模块图片\05.jpg)

## 连接方式

![01](E:\GitLab\sensors-kit\25.触碰开关传感器模块\触碰开关传感器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int SensorPin=4;
int val=0;
void setup() 
{    
  pinMode(SensorPin,INPUT);
  Serial.begin(9600);
}  
void loop() 
{  
  val=digitalRead(SensorPin);
  Serial.println(val);
  delay(200);
}
```

### 实验效果图

![04](E:\GitLab\sensors-kit\25.触碰开关传感器模块\触碰开关传感器模块图片\04.jpg)