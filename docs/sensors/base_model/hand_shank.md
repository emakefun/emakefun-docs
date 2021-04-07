# PH2.0小手柄

## ![](C:\Users\Administrator\Desktop\给toy的照片\手柄.png)概述

PH2.0小手柄包含两个电位器（X轴和Y轴）操纵杆和五个按键（A、B、C、D、摇杆按键Z）。操纵杆根据两个触点控制运动，其中一个触点向左和向右，另一个向上和向下。操纵杆通过AD传感器读取不同的电压值，从而识别特定的位置。X轴和Y轴的模拟值都是从0到255，分别表示从左到右的位置和从上到下的位置。当没有操作时，X和Y轴方向的模拟值都为128。A、B、C、D和摇杆按键Z五个按键都有5种状态（按下、释放、单击、双击、长按）。通过I2C连接Arduino主板发送数据。

## 模块参数

- l 电源要求：+3.3-5V

  l 通信方式：IIC

  l 接口模式：pH2.0-4

  l 外形尺寸：90*40mm

## 引脚定义

| 引脚名称 | 描述            |
| -------- | --------------- |
| G        | GND地线         |
| V        | 5V电源引脚      |
| SCL      | I2C通信时钟引脚 |
| SDA      | I2C通信数据引脚 |

## 模块尺寸

![11](E:\emakefun-docs\docs\sensors\base_model\hand shank\11.jpg)

## arduino 应用场景



### arduino示例程序

[下载最新固件](http://www.emakefun.com/uploads/data/asr_control.zip)

```
#include "JoystickHandle.h"

JoystickHandle joystick(JOYSTICK_I2C_ADDR);

void setup()
{
  Serial.begin(9600); // Set the serial port baud rate to 9600
}

void loop()
{ 
    int val_x, val_y;
    int button_left, button_right, button_up, button_down, joystick_button;
    val_x = joystick.AnalogRead_X();
    val_y = joystick.AnalogRead_Y();
    button_left = joystick.Get_Button_Status(BUTOON_LEFT);
    button_right = joystick.Get_Button_Status(BUTOON_RIGHT);
    button_up = joystick.Get_Button_Status(BUTOON_UP);
    button_down = joystick.Get_Button_Status(BUTOON_DOWN);
    joystick_button = joystick.Get_Button_Status(JOYSTICK_BUTTON);

/******************TEST joystick_X_Y VAL ********************************/

    Serial.print("val_x: ");
    Serial.println(val_x);
    Serial.print("val_y: ");
    Serial.println(val_y);

/*************TEST ButtonPressed OR ButtonReleased************/

//    if(joystick.ButtonPressed(button_left))
//    {
//      Serial.println("ButtonPressed");
//    }
    
//    if(joystick.ButtonReleased(button_left))
//    {
//      Serial.println("ButtonReleased");
//    }

/*************************TEST button_status***********************/
/**********The key status can only be displayed by judgment********/

    if(button_right == DOUBLE_CLICK)
    {
      Serial.println("DOUBLE_CLICK");  
    }
}
```

