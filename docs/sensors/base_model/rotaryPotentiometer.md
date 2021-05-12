# 旋转电位器

## 旋转电位器模块图        

![实物图](rotary potentiomenter/Rotary Potentiometer.png)

![示意图](rotary potentiomenter/structure.png)

## 概述

电位器实际上就是可变电阻器，由于它在电路中的作用是获得与输入电压(外加电压)成一定关系得输出电压，因此称之为电位器。通常被制造成不管使用多久均能维持原有的特性，若当位置传感器使用，电位计可以是直线或旋转式位置传感器。电位计输出一个电压值，其正比于沿着可变电阻器之滑动器的位置。因为温度变化、磨耗及滑动器与可变电阻器之间的污垢均会造成电阻变化，影响电位计的精度。



## 原理图

![原理图](rotary potentiomenter/Schematic diagram.png)

## 模块参数

* 1.供电电压:5V
  2.连接方式:3PIN防反接杜邦线
  3.模块尺寸:4*2.1cm
  4.安装方式:M4螺钉兼容乐高插孔固定

## 详细原理图

 [旋转电位器.pdf](rotary potentiomenter/旋转电位器.pdf) 

## 机械尺寸

![机械尺寸图](rotary potentiomenter/mechanical.png)

## 示例程序

```c
float i=0,j=0,data;  
int analogPin = A3;
void setup()
{
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    data=analogRead(analogPin);
    i=data/1023;
    j=(1-i)*1000;  
    Serial.print("Resistance value is: ");
    Serial.print(j);
    Serial.println("Ω");
    delay(200);
}
```

