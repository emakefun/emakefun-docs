# 按键模块规格书

![147](147.jpg)

## 概述

按键使我们生活中最常用的器件，它的原理非常简单，按键按下，回路导通，松开则断开回路。和单片机配合使用时，按键按下输出低电平，松开输出高电平。

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

![05](05.jpg)

## 连接方式

![01](01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int ButtonPin=4;
int val=0;
void setup() 
{    
  pinMode(ButtonPin,INPUT);
  Serial.begin(9600);
}  
void loop() 
{  
  val=digitalRead(ButtonPin);
  Serial.println(val);
  delay(200);
}
```

### 实验效果图

![02](02.jpg)