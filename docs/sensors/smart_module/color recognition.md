# 颜色识别传感器模块实验

想知道《人与自然》中变色龙是怎么变色的吗？想知道时下最流行的电子取色笔是怎么取色的吗？

不要多想，它们的原理很简单。大自然是人类最好的老师，很多奇趣创意的灵感都是从自然界的生物中获得的。变色龙在经过几千万年的衍化后，形成了一种生物本能，可以通过变换皮肤的保护色完美隐藏在周边的环境中。这是一种从“取色”到“配色”的过程。而现今的电子取色笔也是同样原理，通过检测物体的颜色，得到RGB三基色数值，再通过融合这些数值，调配出物体的颜色。就和小时候捏橡皮泥似得，在知道一定配比之后就能捏出你想要的颜色。

 ![未标题-1](C:\Users\Administrator\Desktop\给toy的照片\未标题-1.png)

## 概述

TCS34725是一款低成本，高性价比的RGB全彩颜色识别传感器，传感器通过光学感应来识别物体的表面颜色。支持红、绿、蓝(RGB)三基色，支持明光感应，可以输出对应的具体数值，帮助您还原颜色本真。



为了提高精度，让颜色管理更加准确。板载自带一个高亮LED，可以让传感器在低环境光的情况下依然能够正常使用，实现“补光”的功能，可以通过LED Switch开关对它进行打开或关闭。颜色识别传感器模块采用I2C通信，拥有PH2.0防反插接口，使用便利。

![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image004.jpg)



## 模块参数

l 工作电压：3.3-5V

l 工作电流：65uA

l 检测距离：3-10mm

l 时钟频率：0-400KHZ

l 接 口：IIC接口和2.54间距接口

l 温度范围：-30℃ ~ +70℃

l 尺 寸：40 * 22 mm，兼容乐高积木和M4螺丝固定孔

 

## 引脚定义

| 引脚名称 | 描述        |
| -------- | ----------- |
| G        | GND地线     |
| V        | 5V电源引脚  |
| SDA      | I2C数据引脚 |
| SCL      | I2C时钟引脚 |

## arduino 应用场景

### arduino函数介绍

```
include "EM_TCS34725.h"
EM_TCS34725 tcs34725;
int  R;
int  G;
int  B;
#define RGB_RED    5
#define RGB_GREEN    6
#define RGB_BLUE    3

void setup() {
tcs34725.begin();
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);   
  Serial.begin(9600);

}

void loop()  {
  R = tcs34725.getRedToGamma();
  G = tcs34725.getGreenToGamma();
  B = tcs34725.getBlueToGamma();
  Serial.print(String("R:") + String(R));
  Serial.print("，");
  Serial.print(String("G:") + String(G));
  Serial.print("，");
  Serial.println(String("B:") + String(B));
     analogWrite(RGB_BLUE,B);
     analogWrite(RGB_RED,R);
     analogWrite(RGB_GREEN,G);
  delay(500);

}

```



