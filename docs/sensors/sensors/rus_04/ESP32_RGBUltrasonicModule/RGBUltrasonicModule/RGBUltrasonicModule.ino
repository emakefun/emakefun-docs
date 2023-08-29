#include <Wire.h>                       //导入通信库
#include "RgbUltrasonic.h"              //导入RGB超声波库
#include "Adafruit_NeoPixel.h"
#define IOPin  14                        //定义RGB超声波 IO引脚
#define RGBPin 12                          //定义RGB超声波 RGB引脚

Adafruit_NeoPixel rgb_display = Adafruit_NeoPixel(4, RGBPin, NEO_GRB + NEO_KHZ800);
                
RgbUltrasonic mRUS04(IOPin);             //创建RGB超声波对象与初始化IO引脚和RGB引脚
uint16_t Distance;                           //定义数字变量读取RGB超声波数据
void setup() {
  rgb_display.begin();
  Serial.begin(9600);                 //设置串口波特率
  rgb_display.setPixelColor(0, 0xff0000);   // 红灯
  rgb_display.setPixelColor(1, 0xff0000);   // 红灯
  rgb_display.setPixelColor(2, 0xff0000);   // 红灯
  rgb_display.setPixelColor(3, 0xff0000);   // 红灯
  rgb_display.setPixelColor(4, 0xff0000);   // 红灯
  rgb_display.setPixelColor(5, 0xff0000);   // 红灯
  rgb_display.show();
  delay(1000);
  rgb_display.setPixelColor(0, 0x00ff00);   // 绿灯
  rgb_display.setPixelColor(1, 0x00ff00);   // 绿灯
  rgb_display.setPixelColor(2, 0x00ff00);   // 绿灯
  rgb_display.setPixelColor(3, 0x00ff00);   // 绿灯
  rgb_display.setPixelColor(4, 0x00ff00);   // 绿灯
  rgb_display.setPixelColor(5, 0x00ff00);   // 绿灯
  rgb_display.show();
  delay(1000);
  rgb_display.setPixelColor(0, 0x0000ff);   // 蓝灯
  rgb_display.setPixelColor(1, 0x0000ff);   // 蓝灯
  rgb_display.setPixelColor(2, 0x0000ff);   // 蓝灯
  rgb_display.setPixelColor(3, 0x0000ff);   // 蓝灯
  rgb_display.setPixelColor(4, 0x0000ff);   // 蓝灯
  rgb_display.setPixelColor(5, 0x0000ff);   // 蓝灯
  rgb_display.show();
  delay(1000);
}
void loop() {
	Distance = mRUS04.GetUltrasonicDistance();            //获取RGB超声波所测距离
	Serial.print("Distance is: ");
  Serial.print(Distance);                              //打印RGB超声波所测距离
  Serial.println("cm");
  delay(300);
} 
