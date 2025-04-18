# 倾斜传感器

## 实物图

![实物图](tilt_switch_sensor/tilt_switch_sensor.png)

## 概述

​    	倾斜开关模块也称为珠形开关，钢球开关，实际上是一种振动开关。它有不同的名称，但工作原理保持不变。滚珠通过与金属板接触或不接触来控制电路的连接或断开。简单地说，就像打开或关闭灯一样，如果开关接触内部的金属板，灯将亮，当开关离开时，灯将熄灭。与金属端子接触或在开关中用小珠子改变光的行进路径将能够产生传导效应。

## 原理图
[查看原理图](tilt_switch_sensor/tilt_switch_sensor_schematic.pdf) 
![原理图](tilt_switch_sensor/tilt_switch_sensor_schematic.png)

## 模块参数

| 引脚名称 | 描述         |
| -------- | ------------ |
| G        | GND          |
| V        | VCC          |
| A        | 模拟信号引脚 |
| D        | 数字信号引脚 |

- 供电电压:3v3/5V

- 连接方式:4PIN防反接杜邦线

- 模块尺寸:40 x 22.5 mm

- 安装方式:M4螺钉兼容乐高插孔固定


## 机械尺寸

![机械尺寸图](tilt_switch_sensor/tilt_switch_sensor_assembly.png)

## Arduino示例程序

 [下载示例程序](tilt_switch_sensor/tilt_switch_sensor.zip) 

```c++
void setup()
{
    Serial.begin(9600); //设置串口波特率为9600
	pinMode(A3, INPUT);  //设置A3口为输入模式
	pinMode(3, OUTPUT);  //设置3口为输入模式
}

void loop()
{
    if (digitalRead(A3) == 0) //判断物体是否倾斜
    {  
		digitalWrite(3, HIGH);  //点亮灯
	}
	else
	{
		digitalWrite(3, LOW); //熄灭灯
	}
}
```

## microbit示例程序

<a href="https://makecode.microbit.org/_DhRKX9fpCL3a" target="_blank">动手试一试</a>

