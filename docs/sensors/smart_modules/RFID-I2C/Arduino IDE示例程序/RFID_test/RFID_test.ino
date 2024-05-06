#include "Emakefun_RFID.h"
#include <Wire.h>

MFRC522 mfrc522(0x28);

void setup() {
  Serial.begin(115200);  // 设置波特率为115200
  Wire.begin();          // 初始化 I2C
  mfrc522.PCD_Init();    // 初始化 MFRC522
}

void loop() {
  
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) { //判断是否检测到卡片
      Serial.println(mfrc522.Read_Uid()); //串口打印读取到的卡片UID，注意调整串口波特率为115200
  }
  delay(50);
  
}
