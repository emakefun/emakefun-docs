#include <Arduino.h>

#include "gamepad.h"
#include "gamepad_publisher_ble.h"

emakefun::Gamepad g_gamepad;
emakefun::GamepadModel g_gamepad_model;
emakefun::GamepadPublisherBle g_gamepad_publisher;

void setup() {
  Serial.begin(115200);
  Serial.println("AT+ROLE=0");
  delay(100);
  Serial.println("AT+CON=B0:64:AC:A7:14:54");
  delay(100);
  g_gamepad.Initialize();
  g_gamepad.EnableGyroscope(false);
  g_gamepad_publisher.Initialize(Serial);
  g_gamepad.AttachModel(&g_gamepad_model);
  g_gamepad_model.AddObserver(&g_gamepad_publisher);
}

void loop() { g_gamepad.Tick(); }