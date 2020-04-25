# LED 模块规格书

![06](E:\课件文本备份\Makedown文档\LED模块\LED模块图片\06.jpg)

## 概述

LED是发光二极管的缩写，由混合化合物制成，即镓（Ga），砷（AS），磷（P）。 磷化镓二极管发红光，磷化镓二极管发绿光，碳化硅二极管发黄光。发光二极管的反向击穿电压为5v。 其正伏安特性曲线太陡，模块上板载了限流电阻，以便在使用时控制流过管道的电流。

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

![07](E:\GitLab\sensors-kit\15.LED灯模块\LED模块图片\07.jpg)

## 连接方式

![04](E:\课件文本备份\Makedown文档\LED模块\LED模块图片\04.jpg)

##  arduino 应用场景

### arduino 控制LED模块程序代码
```c++
int LED = 11;
void setup() 
{
  pinMode(LED,OUTPUT);
}

void loop() 
{
 digitalWrite(LED,HIGH);
 delay(500);
 digitalWrite(LED,LOW);
 delay(500);
}
```

### 实验效果图

![03](E:\课件文本备份\Makedown文档\LED模块\LED模块图片\03.jpg)