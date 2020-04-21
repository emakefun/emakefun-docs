# 滑动电阻器模块规格书

![139](E:\GitLab\sensors-kit\41.滑动电阻器模块\滑动电阻器模块图片\139.jpg)

## 概述

 滑动变阻器是电路中的一个重要元件，它可以通过移动滑片的位置来改变自身的电阻，从而起到控制电路的作用。在电路分析中，滑动变阻器既可以作为一个定值电阻，也可以作为一个变值电阻。 

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：6.7 * 2.1cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| S | 信号引脚 |

## 模块尺寸

![05](E:\GitLab\sensors-kit\41.滑动电阻器模块\滑动电阻器模块图片\05.jpg)

## 连接方式

![03](E:\GitLab\sensors-kit\41.滑动电阻器模块\滑动电阻器模块图片\03.jpg)


##  arduino 应用场景

### arduino程序代码

```c++
float i=0,j=0,data;
int analogPin = A0;
void setup()
{
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    data=analogRead(analogPin);
    i=data/1023;
    j=(1-i)*10000;  
    Serial.print("Resistance value is: ");
    Serial.print(j);
    Serial.println("Ω");
    delay(200);
}
```

### 实验效果图



![02](E:\GitLab\sensors-kit\41.滑动电阻器模块\滑动电阻器模块图片\02.jpg)