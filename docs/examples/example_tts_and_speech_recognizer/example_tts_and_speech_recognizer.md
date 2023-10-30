# 语音识别模块和语音合成模块的综合程序(Arduino)

## 介绍

  该程序在Arduino实现了一个简单的语音交互功能，使用语音控制Led灯，并使用语音播报来回复，用来模拟智能音箱的应用场景

- Arduino R3的D3脚接Led灯
- Arduino R3的I2C接语音识别模块
- Arduino R3的I2C接语音合成模块

## 示例程序

需要安装Arduino语音识别库和语音播报库，请参考文档：

- [语音识别模块](../..//sensors/smart_modules/speech_recognizer.md#arduino应用场景)

- [语音合成模块](../../sensors/smart_modules/text_to_speech_synthesizer.md#arduino应用场景)

### 代码

```c++
#include <Arduino.h>

#include "speech_recognizer.h"
#include "tts.h"

emakefun::SpeechRecognizer g_speech_recognizer(emakefun::SpeechRecognizer::kDefaultI2cAddress);
emakefun::Tts g_tts(emakefun::Tts::kDefaultI2cAddress);
constexpr auto g_led_pin = 3;  // led灯

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  g_tts.Initialize();                                                                   // 语音合成播报模块初始化
  g_speech_recognizer.Initialize();                                                     // 语音识别模块初始化
  g_speech_recognizer.SetRecognitionMode(emakefun::SpeechRecognizer::kKeywordTrigger);  // 设置为关键词唤醒模式
  g_speech_recognizer.SetTimeout(5000);                                                 // 设置超时时间为5s
  g_speech_recognizer.AddKeyword(0, F("xiao yi xiao yi"));  // 添加小易小易词条为关键词，index为0
  g_speech_recognizer.AddKeyword(1, F("qing kai deng"));    // 添加"请开灯"词条
  g_speech_recognizer.AddKeyword(2, F("qing guan deng"));   // 添加"请关灯"词条
  pinMode(g_led_pin, OUTPUT);
  digitalWrite(g_led_pin, 0);  // 默认关闭led灯
  Serial.println("setup done");
}

void loop() {
  // 语音识别模块进行识别并获取结果
  const auto result = g_speech_recognizer.Recognize();
  switch (result) {
    case 1: {
      // 识别到"请开灯"，播报"已开灯"，并打开led灯
      g_tts.Play(F("已开灯"));
      digitalWrite(g_led_pin, 1);
      break;
    }
    case 2: {
      // 识别到"请关灯"，播报"已关灯"，并关闭led灯
      g_tts.Play(F("已关灯"));
      digitalWrite(g_led_pin, 0);
      break;
    }
    default: {
      break;
    }
  }

  // 对各种事件进行处理
  switch (g_speech_recognizer.GetEvent()) {
    // 如果被关键词唤醒
    case emakefun::SpeechRecognizer::kEventKeywordTriggered: {
      // 识别到关键词，播报"在呢"
      g_tts.Play(F("在呢"));
      break;
    }

    // 如果识别超时
    case emakefun::SpeechRecognizer::kEventSpeechRecognitionTimedOut: {
      // 小易小易唤醒后，如果超时未识别到新的指令，则播报"有需要再叫我"
      g_tts.Play(F("有需要再叫我"));
      break;
    }

    default: {
      break;
    }
  }
}
```

## 使用

- 对着语音识别模块说"**小易小易**"进行唤醒，唤醒成功后语音播报模块会回答: "**在呢**"

- 唤醒后对着语音识别说: "**请开灯**"，led灯会亮，语音合成模块会播报："**已开灯**"，并重新等待唤醒

- 唤醒后对着语音识别说: "**请关灯**"，led灯会灭，语音合成模块会播报："**已关灯**"，并重新等待唤醒

- 唤醒后如果5秒内未识别到新的指令，则播报"有需要再叫我"，并重新等待唤醒
