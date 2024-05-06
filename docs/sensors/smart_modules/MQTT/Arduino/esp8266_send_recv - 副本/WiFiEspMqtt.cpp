
#include <inttypes.h>

#include "WiFiEsp.h"
#include "WiFiEspMqtt.h"
#include "EspDrv.h"

WiFiEspMqtt::WiFiEspMqtt() : _sock(NO_SOCKET_AVAIL)
{

}

uint8_t WiFiEspMqtt::mqtt_connect(const char* host, uint16_t port, bool reconnect)
{
	LOGDEBUG(F("> Mqtt Connect"));

	int ret = EspDrv::sendCmd(F("AT+MQTTCONN=0,\"%s\",%d,%d"), 20000, host, port, reconnect);
    //int ret = EspDrv::sendCmd(F("AT+MQTTCONN=0,\"192.168.2.65\",1883,0"));
    if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Connected"));
		return true;
	}

	LOGWARN(F("Mqtt Connect Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

int WiFiEspMqtt::mqtt_usercfg(const char* client_id, const char* name, const char* pass)
{
	LOGDEBUG(F("> Mqtt User Config"));

	int ret = EspDrv::sendCmd(F("AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\""), 20000, client_id, name, pass);
    // int ret = EspDrv::sendCmd(F("AT+MQTTUSERCFG=0,1,\"ESP8266\",\"emakefunken\",\"12345678\",0,0,\"\""));
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt User Config Success"));
		return true;
	}

	LOGWARN(F("Mqtt User Config Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

//AT+MQTTCONNCFG=<LinkID>,<keepalive>,<disable_clean_session>,<"lwt_topic">,
//<"lwt_msg">,<lwt_qos>,<lwt_retain>

int WiFiEspMqtt::mqtt_connect_cfg(uint8_t keepalive, uint8_t clean_session, const char* lwt_topic, const char* lwt_msg, uint8_t lwt_qos)
{
	LOGDEBUG(F("> Mqtt Connect Config"));

	int ret = EspDrv::sendCmd(F("AT+MQTTCONNCFG=0,%d,%d,\"%s\",\"%s\",\"%s\",%d"), 20000, keepalive, clean_session, lwt_topic, lwt_msg, lwt_qos);
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Connect Config Success"));
		return true;
	}

	LOGWARN(F("Mqtt Connect Config Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

//AT+MQTTPUB=<LinkID>,<"topic">,<"data">,<qos>,<retain>
int WiFiEspMqtt::mqtt_public(const char* topic, const char* data, uint8_t qos)
{
	LOGDEBUG(F("> Mqtt Public"));

	int ret = EspDrv::sendCmd(F("AT+MQTTPUB=0,\"%s\",\"%s\",%d,1"), 20000, topic, data, qos);
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Public Success"));
		return true;
	}
	LOGWARN(F("Mqtt Public Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;

}

//AT+MQTTSUB=<LinkID>,<"topic">,<qos>
int WiFiEspMqtt::mqtt_sub(const char* topic, uint8_t qos)
{
	LOGDEBUG(F("> Mqtt Sub"));

	int ret = EspDrv::sendCmd(F("AT+MQTTSUB=0,\"%s\",%d"), 20000, topic, qos);
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Sub Success"));
		return true;
	}
	LOGWARN(F("Mqtt Sub Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

//AT+MQTTUNSUB=<LinkID>,<"topic">
int WiFiEspMqtt::mqtt_unsub(const char* topic)
{
	LOGDEBUG(F("> Mqtt Unsub"));

	int ret = EspDrv::sendCmd(F("AT+MQTTUNSUB=0,\"%s\""), 20000, topic);
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Unsub Success"));
		return true;
	}
	LOGWARN(F("Mqtt Unsub Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

//AT+MQTTCLEAN=<LinkID>
int WiFiEspMqtt::mqtt_disconnect(void)
{
    int ret;
	LOGDEBUG(F("> Mqtt Disconnect"));

    ret = EspDrv::sendCmd(F("AT+MQTTUNSUB=0"));
	if (ret==TAG_OK)
	{
		LOGINFO(F("Mqtt Disconnect Success"));
		return true;
	}
	LOGWARN(F("Mqtt Disconnect Failed"));
	delay(1000);
	EspDrv::espEmptyBuf(false);
	return false;
}

// char *line need end with '\0'
uint8_t WiFiEspMqtt::cli_simple_parse_line(char *line, char *argv[])
{
	int nargs = 0;

	while (nargs < 2) {
		/* skip any white space */
		while (isblank(*line))
			++line;

		if (*line == '\0') {	/* end of line, no more args	*/
			argv[nargs] = NULL;
			//os_printf("%s: nargs=%d\r\n", __func__, nargs);
			return nargs;
		}

		argv[nargs++] = line;	/* begin of argument string	*/

		/* find end of string */
		while (*line && !isblank(*line))
			++line;

		if (*line == '\0') {	/* end of line, no more args	*/
			argv[nargs] = NULL;
			//os_printf("parse_line: nargs=%d\r\n", nargs);
			return nargs;
		}
		*line++ = '\0';		/* terminate current arg	 */
	}

	//os_printf("** Too many args (max. %d) **\n", CONFIG_MAXARGS);
	return nargs;
}

bool WiFiEspMqtt::mqtt_receive(void)
{
    byte len = 0;
    bool ret = false;
	   // ret = EspDrv::sendCmdGet(F("AT+CIPSTATUS"), F("STATUS:"), F("\r\n"), buf, sizeof(buf));
		ret = EspDrv::sendCmdGet(NULL, F("+MQTTSUBRECV:"), F("\r\n"), mqtt_buf, MQTT_RECV_LEN);
		if (ret)
		{
		    cli_simple_parse_line(mqtt_buf, mqtt_recv);
		    mqtt_topic = mqtt_recv[0];
            mqtt_message = mqtt_recv[1];
            //Serial.println("rev0");
            //Serial.println(mqtt_topic);
            //Serial.println("rev1");
            //Serial.println(mqtt_message);
		}
	return ret;
}

