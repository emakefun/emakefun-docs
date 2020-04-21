# 旋转电位器模块规格书

![141](E:\GitLab\sensors-kit\31.旋转电位器模块\旋转电位器模块图片\141.jpg)

## 概述

 电位器实际上就是可变电阻器，由于它在电路中的作用是获得与输入电压(外加电压)成一定关系得输出电压，因此称之为电位器。通常被制造成不管使用多久均能维持原有的特性，若当位置传感器使用，电位计可以是直线或旋转式位置传感器。电位计输出一个电压值，其正比于沿着可变电阻器之滑动器的位置。因为温度变化、磨耗及滑动器与可变电阻器之间的污垢均会造成电阻变化，影响电位计的精度。 

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

![05](E:\GitLab\sensors-kit\31.旋转电位器模块\旋转电位器模块图片\05.jpg)

## 连接方式

![01](E:\GitLab\sensors-kit\31.旋转电位器模块\旋转电位器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
float Voltage=0,data;
int analogPin = A0;
void setup()
{
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    data=analogRead(analogPin);
    Voltage=(data/1023)*5;
    Serial.print("Voltage is: ");
    Serial.print(Voltage);
    Serial.println("V");
    delay(200);
}
```

### 实验效果图



![03](E:\GitLab\sensors-kit\31.旋转电位器模块\旋转电位器模块图片\03.jpg)