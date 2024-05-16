
#include "EM_Piano.h"

Piano mPiano;

void setup(){
  mPiano.initPiano(22, 21);  //初始化触摸钢琴模块  CLK 22,DIO 21
  Serial.begin(9600);
}

void loop(){
  if (mPiano.PressBsButton(EM_PIANO_KEYCODE_1)) {  // 判断钢琴模块按键1是被触摸，如果被触摸则打印Touch key 1
    Serial.println("Touch key 1");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_2)) {  // 判断钢琴模块按键2是被触摸，如果被触摸则打印Touch key 2
    Serial.println("Touch key 2");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_3)) {  // 判断钢琴模块按键3是被触摸，如果被触摸则打印Touch key 3
    Serial.println("Touch key 3");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_4)) {  // 判断钢琴模块按键4是被触摸，如果被触摸则打印Touch key 4
    Serial.println("Touch key 4");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_5)) {  // 判断钢琴模块按键5是被触摸，如果被触摸则打印Touch key 5
    Serial.println("Touch key 5");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_6)) {  // 判断钢琴模块按键6是被触摸，如果被触摸则打印Touch key 6
    Serial.println("Touch key 6");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_7)) {  // 判断钢琴模块按键7是被触摸，如果被触摸则打印Touch key 7
    Serial.println("Touch key 7");
  } else if (mPiano.PressBsButton(EM_PIANO_KEYCODE_8)) {  // 判断钢琴模块按键8是被触摸，如果被触摸则打印Touch key 8
    Serial.println("Touch key 8");
  }
  delay(100);
}