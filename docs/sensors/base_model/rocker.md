# PS2摇杆模块规格书

![63](E:\GitLab\sensors-kit\21.PS2摇杆模块\PS2摇杆模块图片\63.jpg)

## 概述

PS2摇杆结构非常简单，它包含一个触摸按钮（Z轴）和两个电位器（X轴和Y轴）。 操纵杆根据两个触点控制运动，其中一个触点向左和向右，另一个向上和向下。 操纵杆移动决定了触点的位置，就像地球的纬度和经度一样，不同的位置对应不同的电压，然后控制器可以通过AD传感器读取不同的电压值，从而识别特定的远程位置。模拟信号从上方操纵杆的X和Y轴引脚输入.B的值从0到1023表示从左到右的位置，或者从上到下的位置，如果没有按下按钮，则两个值都是512，这是中间值。  

## 模块参

* 工作电压：5V
* 连接方式：5 PIN 防反接杜邦线
* 模块尺寸：4*3.2cm
* 安装方式： M4 螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| X | X轴引脚 |
| Y | y轴引脚 |
| B | 摇杆偏移量引脚 |

## 模块尺寸

![01](E:\GitLab\sensors-kit\21.PS2摇杆模块\PS2摇杆模块图片\01.jpg)

## 连接方式

![02](E:\GitLab\sensors-kit\21.PS2摇杆模块\PS2摇杆模块图片\02.jpg)

##  arduino 应用场景

### arduino 控制LED模块程序代码
```c++

#define JOYSTICK_X    A0
#define JOYSTICK_Y    A1
#define JOYSTICK_B   A2

int value_x,value_y,value_b;
void setup()
{
    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);
    pinMode(JOYSTICK_B, INPUT_PULLUP);
    Serial.begin(9600); 
}

void loop() 
{
    value_x=analogRead(JOYSTICK_X);  
    value_y=analogRead(JOYSTICK_Y);  
    value_b=digitalRead(JOYSTICK_B);
    if(value_x==0)
    {
        Serial.println("right");

    }
    else if(value_x==1023)
    {
         Serial.println("left");   
    }
    if(value_y==0)
    {
        Serial.println("up");
    }
    else if(value_y==1023)
    {
        Serial.println("down");
    }
    if(value_b == 0 )
    {
        Serial.println("enter");
    }
    delay(100);
}
```

### 实验效果图

![05](E:\GitLab\sensors-kit\21.PS2摇杆模块\PS2摇杆模块图片\05.jpg)