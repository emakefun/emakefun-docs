# 继电器模块规格书

![126](E:\GitLab\sensors-kit\35.继电器模块\继电器模块图片\126.jpg)

## 概述

​         继电器是一种电控制器件。它具有控制系统（又称输入回路）和被控制系统（又称输出回路）之间的互动关系。通常应用于自动化的控制电路中，它实际上是用小电流去控制大电流运作的一种“自动开关” 。故在电路中起着自动调节、安全保护、转换电路等作用。特别适合于单片机控制强电装置。  

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

![01](E:\GitLab\sensors-kit\35.继电器模块\继电器模块图片\01.jpg)

## 连接方式

![03](E:\GitLab\sensors-kit\35.继电器模块\继电器模块图片\03.jpg)

##  arduino 应用场景

### arduino 控制LED模块程序代码
```c++
int relay_pin = 11;
void setup() 
{
  pinMode(relay_pin,OUTPUT);
}

void loop() 
{
 digitalWrite(relay_pin,HIGH);
 delay(500);
 digitalWrite(relay_pin,LOW);
 delay(500);
}
```

### 实验效果图

![05](E:\GitLab\sensors-kit\35.继电器模块\继电器模块图片\05.jpg)