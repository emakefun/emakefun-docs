# 红外寻迹传感器模块规格书

![30](E:\GitLab\sensors-kit\12.红外循迹模块传感器模块\红外循迹模块传感器模块图片\30.jpg)

## 概述

​        红外循迹模块本质上是一个红外线收发装置，是具有一对红外线发射与接收管，发射管发射出一定频率的红外线，当检测方向遇到反射面时，红外线反射回来被接收管接收，经过比较器电路处理之后，指示灯会亮起，同时信号输出接口输出数字信号（一个低电平信号）。  

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：4 *1.2cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| S | 信号引脚 |

## 模块尺寸

![05](E:\GitLab\sensors-kit\12.红外循迹模块传感器模块\红外循迹模块传感器模块图片\05.jpg)

## 连接方式

![04](E:\GitLab\sensors-kit\12.红外循迹模块传感器模块\红外循迹模块传感器模块图片\04.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int  SensorPIN  = A0  ;
int  value = 0 ;

void setup()
{
    pinMode(SensorPIN,INPUT);
    Serial.begin(9600);    
}
void loop()
{
    value =  digitalRead(SensorPIN);    
    Serial.println(value);
    delay(100);
}
```

### 实验效果图

![03](E:\GitLab\sensors-kit\12.红外循迹模块传感器模块\红外循迹模块传感器模块图片\03.jpg)
