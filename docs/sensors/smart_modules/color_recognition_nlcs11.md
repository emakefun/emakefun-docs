# NLCS11颜色识别模块

## 模块图









## 概述

NLCS11是一款基于颜色的光到数字的转换器，它结合了光电二极管、电流放大器、模拟电路和数字信号处理器。

为了提高精度，让颜色管理更加准确。板载自带一个高亮LED，可以让传感器在低环境光的情况下依然能够正常使用，实现“补光”的功能，可以通过LED Switch开关对它进行打开或关闭。颜色识别传感器模块采用I2C通信，拥有PH2.0防反插接口，使用便利

NLCS11设备可进行色温测量、亮度传感。内部状态机提供了将设备置于色温测量之间的低功率状态的能力，非常低的平均功耗。

此设备可以应用于亮度传感器丶彩色温度传感器、 小笔记本、 穿戴设备、工业及医疗等领域。



## 模块参数

* 工作电压：3.3-5V
* 工作电流：65uA
* 检测距离：3-10mm
* 时钟频率：0-400KHZ
* 接 口：IIC接口和2.54间距接口
* 温度范围：-30℃ ~ +70℃
* 通信方式:  IIC通信，地址0x43
* 尺 寸：40 * 22 mm，兼容乐高积木和M4螺丝固定孔



## 引脚定义

| 引脚名称 | 描述        |
| -------- | ----------- |
| G        | GND地线     |
| V        | 5V电源引脚  |
| SDA      | I2C数据引脚 |
| SCL      | I2C时钟引脚 |



## Arduino读取RGB示例函数

```c
/**
 * @example read_rgb.ino
 */

#include "color_sensor_nlcs11.h"

#define INFINITE_LOOP_ON_FAILURE InfiniteLoopOnFailure(__FUNCTION__, __LINE__)

namespace {
emakefun::ColorSensorNlcs11 g_color_sensor;
void InfiniteLoopOnFailure(const char* function, const uint32_t line_number) {
  Serial.println(String(F("entering an infinite loop due to failure in ")) + function + F(", at line number: ") + line_number);
  while (true) {
    yield();
  }
}

}  // namespace

void setup() {
  Serial.begin(115200);
  Serial.println(F("setup"));

  Wire.begin();

  Serial.println(String(F("color sensor lib version: ")) + emakefun::ColorSensorNlcs11::kVersionMajor + "." +
                 emakefun::ColorSensorNlcs11::kVersionMinor + "." + emakefun::ColorSensorNlcs11::kVersionPatch);

  const auto ret = g_color_sensor.Initialize();

  if (emakefun::ColorSensorNlcs11::kOK == ret) {
    Serial.println(F("color sensor initialization successful"));
  } else {
    Serial.println(String(F("color sensor device initialization failed: ")) + ret);
    INFINITE_LOOP_ON_FAILURE;
  }

  Serial.println(F("setup successful"));
}

void loop() {
  const auto color = g_color_sensor.GetColor();
  Serial.println(String("r: ") + color.r + ", g: " + color.g + ", b: " + color.b);
  delay(50);
}
```

[点击下载Arduino库以及示例程序](color_recognition_nlcs11/nlcs11_example.zip)

