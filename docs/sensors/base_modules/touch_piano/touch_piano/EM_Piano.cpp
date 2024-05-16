#include "EM_Piano.h"

ST_KEY_MAP em_piano_keymap[16] = {
  {"1", 0xFEFE},
  {"2", 0xFDFD},
  {"3", 0xFBFB},
  {"4", 0xF7F7},
  {"5", 0xEFEF},
  {"6", 0xDFDF},
  {"7", 0xBFBF},
  {"8", 0x7F7F},
};

void Piano::initPiano(uint8_t SclPin, uint8_t SdoPin) {
  SCLPin = SclPin;
  SDOPin = SdoPin;
  pinMode(SCLPin , OUTPUT);
  pinMode(SDOPin , INPUT);
}

uint16_t Piano::GetKeyCode(void) {
  unsigned int DATA = 0;
  pinMode(SDOPin , OUTPUT);
  digitalWrite(SDOPin, HIGH);
  delayMicroseconds(93);
  digitalWrite(SDOPin, LOW);
  delayMicroseconds(10);
  pinMode(SDOPin , INPUT);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(SCLPin, HIGH);
    digitalWrite(SCLPin, LOW);
    DATA |= digitalRead(SDOPin) << i;
  }
  delay(4);
  // Serial.println(DATA);
  return DATA & 0xFFFF;
}
String Piano::GetKeyMap(void) {
  byte i;
  uint16_t keycode = GetKeyCode();
  ST_KEY_MAP *pianokeymap = em_piano_keymap;
  for (i = 0; i < KEY_MAX; i++) {
    //    Serial.println(irkeymap[i].keycode);
    if (pianokeymap[i].keycode == keycode)
      return pianokeymap[i].keyname;
  }
  return "";
}

uint16_t Piano::GetKey(void) {
  byte i;
  uint16_t keycode = GetKeyCode();
  ST_KEY_MAP *pianokeymap = em_piano_keymap;
  for (i = 0; i < KEY_MAX; i++) {
    //    Serial.println(irkeymap[i].keycode);
    if (pianokeymap[i].keycode == keycode)
      return i;
  }
  return 0xff;
}

boolean Piano::PressBsButton(unsigned int button) {
  int PianoKey = GetKeyCode();
  if (PianoKey != 0xFFFFFFFF) {
    if ((PianoKey & button) == button)
      return 1;
    else
      return 0;
  }
  else
    return 0;
}