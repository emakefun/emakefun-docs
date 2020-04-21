# 温湿度传感器模块规格书

![55](E:\GitLab\sensors-kit\18.温湿度传感器模块\温湿度传感器模块图片\55.jpg)

## 概述

DHT11数字温度 - 湿度传感器是一种包含校准数字信号输出的复合传感器。它采用特殊的数字模块采集技术和湿度 - 温度传感器技术，确保高可靠性和出色的长期稳定性。传感器由电阻式湿度元件和NTC温度测量元件组成 。        DHT11通过单总线与微处理器通信。 它只需要一个线程，一次发送40个数据  。

数据格式：  8位湿度整数数据+ 8位湿度十进制数据+ 8位温度整数数据+ 8位温度十进制数据+ 8位奇偶校验位。   

数据发送过程：主控发送启动信号 - > DHT响应信号 - > DHT通知主控它已准备好接受信号 - > DHT发送准备好的数据 - > DHT结束信号 - > DHT内部重新测试环境温度和湿度，记录下一个数据 从主控开始发出信号。

 通过该过程获得，每次收集的数据主控始终是最后一次DHT数据。如果我们想获得实时数据，那么主控可以收集两个连续的数据，但是，正式地，不建议连续多次读取DHT。如果每次读取的间隔时间超过5秒，则足以获得准确的数据。DHT在通电时需要1秒才能稳定。  



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

![05](E:\GitLab\sensors-kit\18.温湿度传感器模块\温湿度传感器模块图片\05.jpg)

## 连接方式

![01](E:\GitLab\sensors-kit\18.温湿度传感器模块\温湿度传感器模块图片\01.jpg)


##  arduino 应用场景

### arduino 程序代码

```c++
#include <Wire.h>
#include"dht11.h"
#define    DHT11PIN     4
dht11 DHT11;
void setup() {
  pinMode(DHT11PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Tep: ");
  Serial.print((float)DHT11.temperature);
  Serial.print("C"); 
  Serial.print("     Hum: ");
  Serial.print((float)DHT11.humidity);
  Serial.println("%");
  delay(200);
}
```

### 实验效果图

![02](E:\GitLab\sensors-kit\18.温湿度传感器模块\温湿度传感器模块图片\02.jpg)