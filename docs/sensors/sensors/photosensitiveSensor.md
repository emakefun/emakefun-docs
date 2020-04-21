# 光敏电阻传感器模块规格书

![16](E:\GitLab\sensors-kit\8.光敏电阻传感器模块\光敏电阻传感器模块图片\16.jpg)

## 概述

众所周知，走廊中的语音控制灯除了语音控制外还有一个传感器，即光敏传感器。光电传感器也称为光敏电阻。它（光敏电阻，缩写为LDR）通常由硫化镉制成。当入射光上升时，电阻阻值会降低; 入射光减弱，阻值会增加。光敏电阻常用于光测量，控制和转换（光与电之间的变化）会发生变化（光变为电），它也可广泛应用于各种光控电路，比如控制 和调节灯以及光开关。 光敏电阻模块对环境光线最敏感，一般用来检测周围环境的光线的亮度，触发单片机或继电器模块等  。

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

![05](E:\GitLab\sensors-kit\8.光敏电阻传感器模块\光敏电阻传感器模块图片\05.jpg)

## 连接方式

![03](E:\GitLab\sensors-kit\8.光敏电阻传感器模块\光敏电阻传感器模块图片\03.jpg)


##  arduino 应用场景

### arduino程序代码

```c++
int  ADPIN  = A0  ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(ADPIN,INPUT);
    Serial.begin(9600);    
    delay(100);
}
void loop()
{
    value =  analogRead(ADPIN);    
    voltage = ( ( float )value )/1023*5 ;
    Serial.println(voltage);
}
```

### 实验效果图

![02](E:\GitLab\sensors-kit\8.光敏电阻传感器模块\光敏电阻传感器模块图片\02.jpg)

