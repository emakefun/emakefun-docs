/*--------------------------------------------------------------------
This file is part of the Arduino WiFiEsp library.

The Arduino WiFiEsp library is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

The Arduino WiFiEsp library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The Arduino WiFiEsp library.  If not, see
<http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#include <inttypes.h>

#include "WiFiEsp.h"
#include "WiFiEspClient.h"
// #include "WiFiEspServer.h"

#include "EspDrv.h"
//#include "debug.h"

WiFiEspClient::WiFiEspClient() : _sock(255)
{
}

WiFiEspClient::WiFiEspClient(uint8_t sock) : _sock(sock)
{
}


////////////////////////////////////////////////////////////////////////////////
// Overrided Print methods
////////////////////////////////////////////////////////////////////////////////

// the standard print method will call write for each character in the buffer
// this is very slow on ESP
size_t WiFiEspClient::print(const __FlashStringHelper *ifsh)
{
  printFSH(ifsh, false);
}

// if we do override this, the standard println will call the print
// method twice
size_t WiFiEspClient::println(const __FlashStringHelper *ifsh)
{
  printFSH(ifsh, true);
}

////////////////////////////////////////////////////////////////////////////////
// Implementation of Client virtual methods
////////////////////////////////////////////////////////////////////////////////

int WiFiEspClient::connectSSL(const char* host, uint16_t port)
{
  return connect(host, port, SSL_MODE);
}

int WiFiEspClient::connectSSL(IPAddress ip, uint16_t port)
{
  char s[16];
  sprintf_P(s, PSTR("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip[3]);
  return connect(s, port, SSL_MODE);
}

int WiFiEspClient::connect(const char* host, uint16_t port)
{
    WiFiEspClient::host = String(host);
    WiFiEspClient::port = port;
    return connect(host, port, TCP_MODE);
}

int WiFiEspClient::connect(IPAddress ip, uint16_t port)
{
  char s[16];
  sprintf_P(s, PSTR("%d.%d.%d.%d"), ip[0], ip[1], ip[2], ip[3]);

  return connect(s, port, TCP_MODE);
}

/* Private method */
int WiFiEspClient::connect(const char* host, uint16_t port, uint8_t protMode)
{
//  LOGINFO1(F("Connecting to"), host);

  _sock = WiFiEspClass::getFreeSocket();
//   Serial.print("connect: ");
    
    if (_sock != NO_SOCKET_AVAIL)
    {
      int r = EspDrv::startClient(host, port, _sock, protMode);
      if (!r)
      return 0;
     
      WiFiEspClass::allocateSocket(_sock);
    }
  else
  {
//      LOGERROR(F("No socket available"));
      return 0;
    }
//    Serial.println("connect http server success!");
    return 1;
}



size_t WiFiEspClient::write(uint8_t b)
{
    return write(&b, 1);
}

size_t WiFiEspClient::write(const uint8_t *buf, size_t size)
{
  
  if (_sock >= MAX_SOCK_NUM or size==0)
  {
    setWriteError();
    return 0;
  }
  bool r = EspDrv::sendData(_sock, buf, size);
  if (!r)
  {
    setWriteError();
//    LOGERROR1(F("Failed to write to socket"), _sock);
    delay(4000);
    stop();
    return 0;
  }

  return size;
}

int WiFiEspClient::available()
{
  if (_sock != 255)
  {
    int bytes = EspDrv::availData(_sock);
    if (bytes>0)
    {
      return bytes;
    }
  }

  return 0;
}

int WiFiEspClient::read()
{
  uint8_t b;
  if (!available())
    return -1;

  bool connClose = false;
  EspDrv::getData(_sock, &b, false, &connClose);

  if (connClose)
  {
    WiFiEspClass::releaseSocket(_sock);
    _sock = 255;
  }

  return b;
}

String WiFiEspClient::readData(char *str, SoftwareSerial *espSerial, unsigned int timeout) 
{
  int BUFF_LEN = 100;
  unsigned char wifi_index = 0;
  unsigned char wifi_buff[BUFF_LEN] = {0}; 
  unsigned char ch;
  char* getStr;
  if(str[0] == '/') {
    getStr = "GET ";
  } else {
    getStr = "GET /";
  }
  char* headStr = " HTTP/1.1\r\nHost: ";
  char* host = WiFiEspClient::host.c_str();
  char* str1 = ":";
  char* port = (WiFiEspClient::port); 
  char* endStr = "\r\nConnection: keep-alive\r\n\r\n";
  int sendLength = strlen(getStr) + strlen(str) + strlen(headStr) + strlen(host) + strlen(str1) + strlen(port) + strlen(endStr);
  char sendData[sendLength];
  sprintf(sendData,"%s%s%s%s%s%s%s", getStr, str, headStr, host, str1, port, endStr);
  write(sendData, sendLength);
  long _startMillis = millis();
  String responseStr ;
  long respLength ;
  uint8_t _connId;
  do{
    if(available() > 0)  
    {
      EspDrv::readUntil(500, "\r\n\r\n");
      read(wifi_buff, BUFF_LEN);
      String s = wifi_buff;
      if(s.length() > 0){
        return split(s);;
      }
    }
  }while(millis() - _startMillis < timeout);
  return " ";
}
//
String WiFiEspClient::split(String tagStr)
{
  int offset;
  String temps[3];
  int i = 0;
  do
  {
    offset = tagStr.indexOf('\n');
    if(offset != -1)
    {
      temps[i] =  tagStr.substring(0, offset - 1);
//      Serial.println(temps[i]);
      tagStr = tagStr.substring(offset + 1, tagStr.length());
      i++;
      } else {
        if(tagStr.length() > 0)
        temps[i] = tagStr;
      }
  }
while(offset >= 0 && i < 3);
  if(temps[1] == "") return temps[0];
  return temps[1];
}

int WiFiEspClient::read(uint8_t* buf, size_t size)
{
  if (!available())
    return -1;
//  Serial.println("client read");
  return EspDrv::getDataBuf(_sock, buf, size);
}

int WiFiEspClient::peek()
{
  uint8_t b;
  if (!available())
    return -1;

  bool connClose = false;
  EspDrv::getData(_sock, &b, true, &connClose);

  if (connClose)
  {
    WiFiEspClass::releaseSocket(_sock);
    _sock = 255;
  }

  return b;
}


void WiFiEspClient::flush()
{
  while (available())
    read();
}



void WiFiEspClient::stop()
{
  if (_sock == 255)
    return;

//  LOGINFO1(F("Disconnecting "), _sock);

  EspDrv::stopClient(_sock);

  WiFiEspClass::releaseSocket(_sock);
  _sock = 255;
}


uint8_t WiFiEspClient::connected()
{
  return (status() == ESTABLISHED);
}


WiFiEspClient::operator bool()
{
  return _sock != 255;
}


////////////////////////////////////////////////////////////////////////////////
// Additional WiFi standard methods
////////////////////////////////////////////////////////////////////////////////


uint8_t WiFiEspClient::status()
{
  if (_sock == 255)
  {
    return CLOSED;
  }

  if (EspDrv::availData(_sock))
  {
    return ESTABLISHED;
  }

  if (EspDrv::getClientState(_sock))
  {
    return ESTABLISHED;
  }

  WiFiEspClass::releaseSocket(_sock);
  _sock = 255;

  return CLOSED;
}

IPAddress WiFiEspClient::remoteIP()
{
  IPAddress ret;
  EspDrv::getRemoteIpAddress(ret);
  return ret;
}

////////////////////////////////////////////////////////////////////////////////
// Private Methods
////////////////////////////////////////////////////////////////////////////////

size_t WiFiEspClient::printFSH(const __FlashStringHelper *ifsh, bool appendCrLf)
{
  size_t size = strlen_P((char*)ifsh);
  
  if (_sock >= MAX_SOCK_NUM or size==0)
  {
    setWriteError();
    return 0;
  }

  bool r = EspDrv::sendData(_sock, ifsh, size, appendCrLf);
  if (!r)
  {
    setWriteError();
//    LOGERROR1(F("Failed to write to socket"), _sock);
    delay(4000);
    stop();
    return 0;
  }

  return size;
}