# 语音识别模块2.1

## 前言

相比于[2.0](./speech_recognizer.md)来说，硬件相同，主要升级了固件和相关库，修复一些bug和优化，更易于用户使用

## 概述

该语音识别模块是`emakefun`基于非特定人语音识别`LD3320SI-ASR`：（Speaker-Independent Automatic Speech Recognition）芯片开发的一款语音识别模块。`LD3320`芯片上集成了高精度的A/D和D/A接口，不再需要外接辅助的Flash和RAM，即可以实现语音识别/声控/人机对话功能。提供了真正的单芯片语音识别解决方案。该模块有如下特点：

- 非特定人语音识别技术

用户不需要进行录音训练即可动态编辑的识别关键词语列表，只需要把识别的关键词语以字符串的形式传送进芯片，即可以在下次识别中立即生效。

- 支持用户自由编辑`50`条关键词语条

在同一时刻，最多在`50`条关键词语中进行识别，终端用户可以根据场景需要，随时编辑和更新关键词语的内容，每条词条的字符数不超过50个。

- 模块上有蓝色状态灯，亮起表示正在识别语音，灭掉表示不会识别语音，当识别到语音时状态灯闪烁

- 该模块采用MCU+`LD3320`设计，和应用主控采用I2C通讯，大大简化了用户接线和编程难度。

- 支持多种工作模式：自动识别、按键触发识别、关键词触发识别、按键或关键词触发识别，让用户可以在不同工作场景中使用。

## 模块参数

- 工作电压：5V
- 连接方式：4 PIN 防反接杜邦线
- 模块尺寸：4 * 2.1cm
- 安装方式：M4螺钉螺母固定
- I2C地址：0x30

## 引脚定义

| 引脚名称| 描述 |
| ---- | ---- |
| G | GND地线 |
| V | 5V电源引脚 |
| SDA | I2C数据引脚 |
| SCL | I2C时钟引脚 |

## 模块尺寸

TODO

## arduino应用场景

- Arduino库和示例程序下载链接 [点击此处链接下载](https://github.com/emakefun-arduino-library/emakefun_speech_recognizer_v2_1/archive/refs/tags/latest.zip)

- [点击此处文档链接查看API说明](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/classemakefun_1_1_speech_recognizer.html)

### arduino示例程序

- 自动循环识别 [点击此处链接查看](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/simple_example_8ino-example.html)
- 按键触发识别 [点击此处链接查看](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/button_trigger_mode_8ino-example.html)
- 关键词触发识别 [点击此处链接查看](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/keyword_trigger_mode_8ino-example.html)
- 关键字或者按键触发识别 [点击此处链接查看](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/button_or_keyword_trigger_mode_8ino-example.html)
- 大量关键词(50个)示例 [点击此处链接查看](https://emakefun-arduino-library.github.io/emakefun_speech_recognizer_v2_1/lots_of_keywords_8ino-example.html)

## Mixly示例程序

TODO

## microbit示例程序

TODO

## 语音识别模块和语音合成模块的综合程序(Arduino)

TODO
