# 土壤湿度传感器模块规格书

​        ![05](E:\GitLab\sensors-kit\36.土壤湿度传感器模块\土壤湿度传感器模块图片\05.jpg)

## 概述

土壤湿度传感器模块有两个铜条是传感器探头。 将它们插入土壤时，它们可以检测到水分。 土壤湿润，导电性越好，反映出它们之间的电阻越低。土壤干燥,导电性就相对差一点,因此他们之间的电阻越高。 它是模拟传感器，因此我们通过模拟输入获得电压值。因为土壤的湿度可以分为几个等级，当我们使用土壤湿度传感器做一个自动浇花系统的时候，将方便的使用。

## 模块参数

* 工作电压：5V
* 连接方式：3 PIN 防反接杜邦线
* 模块尺寸：5.6 * 1.9cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| S | 信号引脚 |

## 模块尺寸

![06](E:\GitLab\sensors-kit\36.土壤湿度传感器模块\土壤湿度传感器模块图片\06.jpg)

## 连接方式

![04](E:\GitLab\sensors-kit\36.土壤湿度传感器模块\土壤湿度传感器模块图片\04.jpg)


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
    i=(450-data)/450;
    j=(1-i)*100;  
    Serial.print("The hum is: ");
    Serial.print(j);
    Serial.println("%");
    delay(200);
}
```

### 实验效果图

![03](E:\GitLab\sensors-kit\36.土壤湿度传感器模块\土壤湿度传感器模块图片\03.jpg)