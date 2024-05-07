#include "WiFiEsp.h"
#include "WifiEspMqtt.h"
#include "SoftwareSerial.h"
SoftwareSerial esp8266_serial(5, 6);  // RX, TX
uint32_t _startMillis = 0;

WiFiEspMqtt esp8266;

void setup() {
  Serial.begin(115200);
  esp8266_serial.begin(9600);
  WiFi.init(&esp8266_serial);
  if (WiFi.begin("K30", "12345678") == WL_CONNECTED) {    //在此设置wifi和密码
    Serial.println("wifi connected");
    esp8266.mqtt_connect("remote.microprinttech.com", 19824, 0);    //服务器地址和端口
    // esp8266.mqtt_connect_cfg(120, 1, "lws_topic", "lws_kill", 0);
    esp8266.mqtt_usercfg("esp8266_client", "kxmqttp1", "public985");    //个人账号和密码
    esp8266.mqtt_sub("topic_1", 0);  //订阅topic_1主题，qos为0
  }
  esp8266.mqtt_public("topic_led", "on", 0);
  delay(30000);
}

void loop() {
  if (esp8266.mqtt_receive()) {

    Serial.print("topic:");
    Serial.println(esp8266.mqtt_topic);
    Serial.print("message:");
    Serial.println(esp8266.mqtt_message);
  }
}