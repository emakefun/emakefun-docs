#include <Arduino.h>

#include "gamepad.h"
#include "gamepad_publisher_rf24.h"

emakefun::Gamepad g_gamepad;
emakefun::GamepadModel g_gamepad_model;
emakefun::GamepadPublisherRf24 g_gamepad_publisher;

void setup() {
  Serial.begin(115200);
  Serial.println("gamepad initialize");
  g_gamepad.Initialize();
  Serial.println("gamepad initialize done");
  g_gamepad.EnableGyroscope(false);

  Serial.println("gamepad publisher initialize");
  g_gamepad_publisher.Initialize(7, 8, 115, 5, 0x0011000011LL);
  Serial.println("gamepad publisher initialize done");
  g_gamepad.AttachModel(&g_gamepad_model);
  g_gamepad_model.AddObserver(&g_gamepad_publisher);
  Serial.println("setup done");
}

void loop() {
  g_gamepad.Tick();
  if (g_gamepad_model.NewButtonState()) {
    Serial.println(F("new button state"));
  }

  for (uint8_t button_type = emakefun::GamepadModel::kButtonJoystick; button_type < emakefun::GamepadModel::kButtonMax;
       button_type++) {
    if (g_gamepad_model.NewButtonState(button_type)) {
      Serial.print(F("new button state:"));
      Serial.println(button_type);
    }

    if (g_gamepad_model.ButtonPressed(button_type)) {
      Serial.print(F("button pressed: "));
      Serial.println(button_type);
    }

    if (g_gamepad_model.ButtonReleased(button_type)) {
      Serial.print(F("button released: "));
      Serial.println(button_type);
    }

    if (g_gamepad_model.GetButtonState(button_type)) {
      Serial.print(F("button is being held: "));
      Serial.println(button_type);
    }
  }

  if (g_gamepad_model.NewJoystickCoordinate()) {
    Serial.print(F("joystick coordinate: "));
    Serial.print(g_gamepad_model.GetJoystickCoordinate().x);
    Serial.print(F(", "));
    Serial.println(g_gamepad_model.GetJoystickCoordinate().y);
  }

  if (g_gamepad_model.NewGravityAcceleration()) {
    Serial.print(F("gravity acceleration: "));
    Serial.print(g_gamepad_model.GetGravityAcceleration().x);
    Serial.print(F(", "));
    Serial.print(g_gamepad_model.GetGravityAcceleration().y);
    Serial.print(F(", "));
    Serial.println(g_gamepad_model.GetGravityAcceleration().z);
  }
}