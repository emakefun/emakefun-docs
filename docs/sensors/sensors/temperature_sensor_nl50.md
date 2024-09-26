# NL50温度传感器

## 实物图







## 概述

NL50是由我司自主研发的温度传感器，该温度传感器是利用二极管的基本原理来测量已知温度值。随着温度的升高，二极管俩端的电压的已知的速率增加.通过精确放大电压变化，产生与环境温度成正比的电压信号,从而获取相应的温度值。

因此NL50传感器具有精确度高，连接方式简单等优点。



## 模块参数

| 引脚名称 |         描述         |
| :------: | :------------------: |
|    G     |         GND          |
|    V     |         VCC          |
|    S     | DATA串行数据，单总线 |

- 供电电压:3v3/5V
- 连接方式:4PIN防反接杜邦线
- 模块尺寸:40 x 22.5 mm
- 安装方式:M4螺钉兼容乐高插孔固定



## Arduino示例程序

```c
/**
 * @example read_temperature.ino
 */

#include "temperature_sensor_nl50.h"

namespace {
#if defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_ESP32S3)
constexpr uint8_t kPin = 34;
#elif defined(ARDUINO_ARCH_AVR)
constexpr uint8_t kPin = A0;
#endif

emakefun::TemperatureSensorNl50 g_nl50(kPin);
}  // namespace

void setup() {
  Serial.begin(115200);
  Serial.println(String(F("temperature sensor NL50 lib version: ")) + emakefun::TemperatureSensorNl50::Version());
  g_nl50.Initialize();
  Serial.println(F("setup successful"));
}

void loop() {
  Serial.println(String("temperature: ") + g_nl50.Read());
  delay(100);
}

```

[点击下载Arduino库以及示例程序](temperature_sensor_nl50/nl50_example.zip)