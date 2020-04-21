# 触摸传感器模块规格书

![41](E:\GitLab\sensors-kit\22.触摸传感器模块\触摸传感器模块图片\41.jpg)

## 概述

​       触摸传感器模块是一个基于触摸检测IC（TTP223B）的电容式点动型触摸开关模块。常态下，模块输出低电平，模式为低功耗模式；当用手指触摸相应位置时，模块会输出高电平，模式切换为快速模式；当持续12秒没有触摸时，模式又切换为低功耗模式。可以将模块安装在非金属材料如塑料、玻璃的表面，另外将薄薄的纸片（非金属）覆盖在模块的表面，只要触摸的位置正确，即可做成隐藏在墙壁、桌面等地方的按键。  

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

![05](E:\GitLab\sensors-kit\22.触摸传感器模块\触摸传感器模块图片\05.jpg)

## 连接方式

![03](E:\GitLab\sensors-kit\22.触摸传感器模块\触摸传感器模块图片\03.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int SensorPin=8;
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

![04](E:\GitLab\sensors-kit\22.触摸传感器模块\触摸传感器模块图片\04.jpg)