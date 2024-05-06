
#ifndef WiFiEspMqtt_h
#define WiFiEspMqtt_h

#include "Arduino.h"
#include "Print.h"
#include "IPAddress.h"

#define MQTT_RECV_LEN 128
#define isblank(c)	(c == ',' || c == ' ' || c == '"')

class WiFiEspMqtt
{
public:
  WiFiEspMqtt();
  char *mqtt_topic, *mqtt_message;
  virtual uint8_t mqtt_connect(const char* host, uint16_t port, bool reconnect);
  virtual int mqtt_connect_cfg(uint8_t keepalive, uint8_t clean_session, const char* lwt_topic, const char* lwt_msg, uint8_t lwt_qos);
  int mqtt_usercfg(const char* client_id, const char* name, const char* pass);
  int mqtt_public(const char* topic, const char* data, uint8_t qos);
  int mqtt_sub(const char* topic, uint8_t qos);
  int mqtt_unsub(const char* topic);
  virtual int mqtt_disconnect(void);
  
  /*
  * Read the next byte received from the server the Mqtt is connected to (after the last call to read()).
  * Returns the next byte (or character), or -1 if none is available.
  */
  bool mqtt_receive(void);

private:
  char mqtt_buf[MQTT_RECV_LEN];
  char *mqtt_recv[2];
  uint8_t _sock;     // connection id
  uint8_t cli_simple_parse_line(char *line, char *argv[]);
};

#endif
