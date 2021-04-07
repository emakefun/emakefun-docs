# 压力传感器模块

![压力模块 - 副本](E:\emakefun-docs\docs\sensors\sensors\Pressure sensor module\压力模块 - 副本.jpg)

## 概述

薄膜压力传感器模块是基于新型纳米压敏材料辅以舒适杨式模量的超薄薄膜衬底一次性贴片而成，兼具防水和压敏双重功能。当传感器感知到外界的压力变化虎，传感器电阻值发生变化，我们采用电路讲传感器感知到的压力信号转换成相应变化的强度电信号输出。这样我们就可以通过检测电信号的变化就可以得知压力的变化情况。

## 模块参数

- 工作电压：5V
- 连接方式：3 PIN 防反接杜邦线
- 模块尺寸：4 * 2.1cm
- 安装方式：M4螺钉螺母固定

## 引脚定义

| 引脚名称 | 描述       |
| -------- | ---------- |
| G        | GND地线    |
| V        | 5V电源引脚 |
| S        | 数字引脚   |

## 模块尺寸

![fd49378c5b44555ed7651740ec96103](E:\emakefun-docs\docs\sensors\sensors\Pressure sensor module\fd49378c5b44555ed7651740ec96103.png)



## arduino 应用场景

### arduino函数介绍

```
bool ld3320_reset(void); // 复位语音识别模块，启动时必须先复位,才可配置和添加关键字，延时要超过200ms等待模块初始化完全完成
bool ld3320_config_mode(E_WORK_MODE m); // 配置工作模式
typedef enum
{
    LOOP_MODE = 0,           // 循环模式
    BUTTON_MODE = 1,         // 按键模式
    KEYWORDS_MODE = 2,       // 关键字模式
    KEYWORDS_AND_BUTTON = 3, // 关键字加按键模式
}E_WORK_MODE;
bool ld3320_add_words(unsigned char id, unsigned char *words); // 添加关键字第一个参数是关键字序号，1~49， 后面是关键字字符串，不超过79个字符，汉字不超过10个
bool ld3320_config_time(unsigned char t); // 配置唤醒等待时间默认为5s
bool ld3320_config_keywords(unsigned char *words); // 配置唤醒关键字
bool ld3320_asr_start(void); // 语音识别模块开始识别
unsigned char ld3320_get_result(void);  // 获取识别到关键字序号
```

### arduino示例程序

[下载最新固件](http://www.emakefun.com/uploads/data/asr_control.zip)

```
#include "asr_ld3320.h"

void setup()
{
  E_WORK_MODE asr_mode = LOOP_MODE;      // 0：循环识别模式  1：口令模式，以第一个词条为口令  2、按键模式，按下开始识别
  Wire.begin();
  Serial.begin(9600);
  ld3320_reset();
  ld3320_config_mode(asr_mode);  // 循环模式
  ld3320_add_words(0, "xiao yi xiao yi");  // 小易小易
  Serial.println("xiao yi xiao yi");
  ld3320_add_words(5, "shen zhen shi");    // 深圳市
  Serial.println("shen zhen shi");
  ld3320_add_words(1, "ni hao");  // 你好
  Serial.println("ni hao");
  ld3320_add_words(2,"kai deng");          // 开灯
  Serial.println("kai deng");
  ld3320_add_words(3, "xiao yi tong xue");              
  Serial.println("xiao yi tong xue");
  ld3320_add_words(4, "guan deng");        // 关灯
  Serial.println("guan deng");
  ld3320_add_words(8, "wo ai ni");         // 我爱你
  Serial.println("wo ai ni");
  ld3320_asr_start();
  Serial.println("ld3320 start ");
}

void loop()
{
  unsigned char result;
  result = ld3320_get_result();
  if (result != 0xFF) {
    Serial.print("asr result is:");
    Serial.println(result);   //返回识别结果，即识别到的词条编号
    delay(20);
  }

}
```

