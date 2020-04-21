# 震动传感器模块规格书



## 概述

​        震动传感器模块实质是一个开关,其内部是一个金属片和一个弹簧, 产品不震动时，震动开关呈断开状态，输出端输出高电平；产品震动时，震动开关由于弹簧和金属片瞬间导通，输出端输出低电平；输出端可以与单片机直接相连，通过单片机来检测高低电平，由此来检测环境是否有震动，起到报警作用。  

![07](E:\GitLab\sensors-kit\PH2.0模块规格书\47.震动传感器模块\震动传感器模块图片\07.jpg)

## 模块参数

* 工作电压：5V
* 连接方式：4 PIN 防反接杜邦线
* 模块尺寸：4 * 2.1cm
* 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| A | 模拟信号引脚 |
| D | 数字信号脚 |
## 模块尺寸

![05](E:\GitLab\sensors-kit\PH2.0模块规格书\47.震动传感器模块\震动传感器模块图片\05.jpg)

## 连接方式

![02](E:\GitLab\sensors-kit\PH2.0模块规格书\47.震动传感器模块\震动传感器模块图片\02.jpg)


##  arduino 应用场景

### arduino  程序代码

```c++
int buttonpin=11;  
int val=0;
void setup() 
{ 
  pinMode(buttonpin,INPUT);
  Serial.begin(9600);
}  
void loop() 
{  
  val=digitalRead(buttonpin);
  Serial.println(val);
 delay(200);
}
```

### 实验效果图

![01](E:\GitLab\sensors-kit\PH2.0模块规格书\47.震动传感器模块\震动传感器模块图片\01.jpg)