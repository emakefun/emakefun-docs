# PS2摇杆模块

## 模块图

![Rocker Module](rocker module\Rocker Module.png)

## 概述

​       PS2摇杆结构非常简单，它包含一个触摸按钮（Z轴）和两个电位器（X轴和Y轴）。 操纵杆根据两个触点控制运动，其中一个触点向左和向右，另一个向上和向下。 操纵杆移动决定了触点的位置，就像地球的纬度和经度一样，不同的位置对应不同的电压，然后控制器可以通过AD传感器读取不同的电压值，从而识别特定的远程位置。模拟信号从上方操纵杆的X和Y轴引脚输入.B的值从0到1023表示从左到右的位置，或者从上到下的位置，如果没有按下按钮，则两个值都是512，这是中间值。

## 原理图

![tu2](rocker module\tu2.png)

## 详细原理图

 [摇杆模块.pdf](PS2摇杆模块图片/摇杆模块.pdf) 

## 模块参数

* V:电源5V
* G:GND
* VRX:通过获取左右
* VRY:通过获取上下
* SW：通过按键的高低电平，获取是否被按下。

## 机械尺寸

![图片4](rocker module\图片4.png)

## 示例程序

```c
#define JOYSTICK_X    A4  //define X pin
#define JOYSTICK_Y    A5  //define Y pin
#define JOYSTICK_B    2//define button pin

int value_x,value_y,value_b;  //define three variables
void setup()
{
    pinMode(JOYSTICK_X, INPUT);  //init X pin
    pinMode(JOYSTICK_Y, INPUT);  //init Y pin
    pinMode(JOYSTICK_B, INPUT_PULLUP);  //init button pin
    Serial.begin(9600);  //set serial
}

void loop() 
{
    value_x=analogRead(JOYSTICK_X);  //get X pin analog value
    value_y=analogRead(JOYSTICK_Y);  //get X pin analog value
    value_b=digitalRead(JOYSTICK_B); //get button pin value 
    if(value_x==0)    //
    {
        Serial.println("right");//print right

    }
    else if(value_x==1023)  //
    {
         Serial.println("left");    //print left
    }
    if(value_y==0)  //
    {
        Serial.println("up");//print up
    }
    else if(value_y==1023) //
    {
        Serial.println("down");//print down
    }
    if(value_b == 0 )  //
    {
        Serial.println("enter");//print enter
    }
    delay(100);
}
```

