# 无源蜂鸣器模块规格书

![23](无源蜂鸣器模块图片\23.jpg)

## 概述

 无源蜂鸣器，是没有内部振荡器的蜂鸣器，在通电时，内部振荡器是不会发出嗡嗡声的，它需要2~5 kHz的方波驱动，然后不同频率的波形会驱动蜂鸣器发出相应频率的声音。 我们常见的一些贺卡里面会带一个音乐盒，打开后会播放生日快乐，圣诞歌这些曲调，就是通过无源蜂鸣器来实现的。 

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

![05](无源蜂鸣器模块图片\05.jpg)

## 连接方式

![01](无源蜂鸣器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
int buzzer = 4;
void frequence_1(void)  
{
  	int i ;
  	for(i=0;i<800;i++)
  	{
    		digitalWrite(buzzer,HIGH); 
    		delay(2);
    		digitalWrite(buzzer,LOW);
    		delay(2);
  	}
}

void frequence_2(void)   
{
    int i ;
    for(i=0;i<800;i++)
    {
      	digitalWrite(buzzer,HIGH); 
      	delay(5);
      	digitalWrite(buzzer,LOW);
      	delay(5);
    }
}

void setup()
{
	  pinMode(buzzer,OUTPUT);
}
void loop() 
{
  	frequence_1();
  	delay(1000);
  	frequence_2();
    delay(1000);
}
```

### 实验效果图

![04](无源蜂鸣器模块图片\04.jpg)