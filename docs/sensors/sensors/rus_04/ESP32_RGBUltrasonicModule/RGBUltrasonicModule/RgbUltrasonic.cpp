#include "RgbUltrasonic.h"

RgbUltrasonic::RgbUltrasonic(byte signal_pin)
{
    SignalPin = signal_pin;
}

float RgbUltrasonic::GetUltrasonicDistance(void)
{
  pinMode(SignalPin, OUTPUT);
  digitalWrite(SignalPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(SignalPin, LOW);
  pinMode(SignalPin, INPUT);
  FrontDistance = pulseIn(SignalPin, HIGH, 500000) / 58.00;
  return FrontDistance;
}
