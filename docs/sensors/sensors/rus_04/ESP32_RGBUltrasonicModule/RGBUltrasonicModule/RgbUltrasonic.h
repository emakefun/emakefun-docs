#ifndef _RGBULTRASONIC_H_
#define _RGBULTRASONIC_H_

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
class RgbUltrasonic
{
  private:
    byte SignalPin;
  public:
    float FrontDistance;
    RgbUltrasonic(byte signal_pin);
    float GetUltrasonicDistance(void);
};
#endif
