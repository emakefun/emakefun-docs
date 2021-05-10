# 继电器规格书

## 模块图

![Relay Module](relay module/Relay Module.png)

## 概述

​         继电器是一种电控制器件。它具有控制系统（又称输入回路）和被控制系统（又称输出回路）之间的互动关系。通常应用于自动化的控制电路中，它实际上是用小电流去控制大电流运作的一种“自动开关” 。故在电路中起着自动调节、安全保护、转换电路等作用。特别适合于单片机控制强电装置。

## 原理图

![07](relay module/07.png)

## 模块参数

1.供电电压:5V
2.连接方式:3PIN防反接杜邦线
3.模块尺寸:4*2.1cm
4.安装方式:M4螺钉兼容乐高插孔固定

| 引脚名称 | 描述       |
| -------- | ---------- |
| V        | 5V电源引脚 |
| G        | GND 地线   |
| S        | 信号引脚   |

## 详细原理图

 [relay.pdf](relay module/relay.pdf) 

## 机械尺寸

![02](relay module/02.png)



## 示例程序

```c
#define buzzer_pin A3  // Set the buzzer port to A3
void setup() {
  pinMode(buzzer_pin, OUTPUT);  // Set the buzzer port to output mode
}

void loop()  {
  digitalWrite(buzzer_pin,HIGH);  // Set the buzzer port to high level
  delay(1);                       // Delay 1 ms
  digitalWrite(buzzer_pin,LOW);   // Set the buzzer port to low level
  delay(1);                       // Delay 1 ms
}
```

