#include"EM_Piano.h"
#include "Buzzer.h"

Buzzer buzzer(A3);

int SCLPin = A5, SDOPin = A4;   // Define SCL clock and SDO data port
unsigned int h = 0, oldh = 0;
Piano mPiano;
char str[128];
void setup()
{
  Serial.begin(9600);  // Set the serial port baud rate to 9600
  mPiano.initPiano(SCLPin, SDOPin); //初始话钢琴模块
}

void loop()
{
  uint16_t keycode = mPiano.GetKeyCode(); //获取钢琴模块键值
  if (keycode != 0xFFFF) {   // 判断按键是否按下
    String key_name = mPiano.GetKeyMap();
    if (key_name == "1") {   //判断按键1是否按下
      buzzer.tone(A3, 262, 100);
    }else if (key_name == "2") {  //判断按键2是否按下
      buzzer.tone(A3, 294, 100);
    }else if (key_name == "3") {  //判断按键3是否按下
       buzzer.tone(A3, 330, 100);
    }else if (key_name == "4") {  //判断按键4是否按下
       buzzer.tone(A3, 349, 100);
    }else if (key_name == "5") {  //判断按键5是否按下
       buzzer.tone(A3, 392, 100);
    }else if (key_name == "6") {  //判断按键6是否按下
       buzzer.tone(A3, 440, 100);
    }else if (key_name == "7") {  //判断按键7是否按下
       buzzer.tone(A3, 494, 100);
    }else if (key_name == "8") {  //判断按键8是否按下
       buzzer.tone(A3, 523, 100);
    }
  }
}
