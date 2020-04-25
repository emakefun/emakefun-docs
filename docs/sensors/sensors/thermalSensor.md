# 热敏电阻传感器模块规格书

![07](E:\GitLab\sensors-kit\9.热敏电阻传感器模块\热敏电阻传感器模块图片\07.jpg)

## 概述

​        热敏电阻器是敏感元件的一类，按照温度系数不同分为正温度系数热敏电阻器(PTC)和负温度系数热敏电阻器(NTC)。热敏电阻器的典型特点是对温度敏感，不同的温度下表现出不同的电阻值。正温度系数热敏电阻器(PTC)在温度越高时电阻值越大，负温度系数热敏电阻器(NTC)在温度越高时电阻值越低，它们同属于半导体器件。  

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

![08](E:\GitLab\sensors-kit\9.热敏电阻传感器模块\热敏电阻传感器模块图片\08.jpg)

## 连接方式

![01](E:\GitLab\sensors-kit\9.热敏电阻传感器模块\热敏电阻传感器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int  ADPIN  = A0  ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
  
    pinMode(ADPIN,INPUT);
    Serial.begin(9600);    
}
void loop()
{
    value =  analogRead(ADPIN);    
    voltage = ( ( float )value )/1023*5 ;
    Serial.println(voltage);
    delay(100);
}
```

### 实验效果图

![04](E:\GitLab\sensors-kit\9.热敏电阻传感器模块\热敏电阻传感器模块图片\04.jpg)