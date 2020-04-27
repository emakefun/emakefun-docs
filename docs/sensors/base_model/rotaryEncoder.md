# 旋转编码器模块规格书

![135](旋转编码器模块图片\135.jpg)

## 概述

编码器是一种将旋转位移转换为一连串数字脉冲信号的旋转式传感器，旋转编码器可通过旋转可以计数正方向和反方向转动过程中输出脉冲的次数，旋转计数不像电位计，这种转动计数是没有限制的。配合旋转编码器上的按键，可以复位到初始状态，即从0开始计数。这些脉冲用来控制角位移。在Eltra编码器中角位移的转换采用了光电扫描原理。读数系统以由交替的透光窗口和不透光窗口构成的径向分度盘（码盘）的旋转为依据，同时被一个红外光源垂直照射，光把码盘的图像投射到接收器表面上。接收器覆盖着一层衍射光栅，它具有和码盘相同的窗口宽度。接收器的工作是感受光盘转动所产生的变化，然后将光变化转换成相应的电变化。再使低电平信号上升到较高电平，并产生没有任何干扰的方形脉冲，这就必须用电子电路来处理。读数系统通常采用差分方式，即将两个波形一样但相位差为180°的不同信号进行比较，以便提高输出信号的质量和稳定性。

## 模块参

* 工作电压：5V
* 连接方式：5 PIN 防反接杜邦线
* 模块尺寸：4*2.1cm
* 安装方式： M4 螺钉螺母固定

## 引脚定义

| 引脚名称| 描述 |
|---- |----|
| V | 5V电源引脚 |
| G | GND 地线 |
| A | 左旋检测引脚 |
| B | 右旋检测引脚 |
| D | 按键功能引脚 |

## 模块尺寸

![05](旋转编码器模块图片\05.jpg)

## 连接方式

![02](旋转编码器模块图片\02.jpg)

##  arduino 应用场景

### arduino 控制LED模块程序代码
```c++
#define A_PIN A0 
#define B_PIN A1
#define D_PIN A2

int counter=0,count_A = 0,lastcount_A = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A_PIN, INPUT); 
  pinMode(B_PIN, INPUT); 
  pinMode(D_PIN, INPUT); 
  lastcount_A = digitalRead(A_PIN);
}
void loop() {
   count_A = digitalRead(A_PIN);
  if(digitalRead(D_PIN) == LOW){ 
     Serial.println("count reset to 0");
  }
 if(count_A!=lastcount_A)
 {
  if(digitalRead(B_PIN)!= count_A)
  {
    counter++;
    }
    else
    {
      counter--;
      }
  Serial.print("counter===");
  Serial.println(counter);
  }
  lastcount_A = count_A;
}
```

### 实验效果图

![01](旋转编码器模块图片\01.jpg)