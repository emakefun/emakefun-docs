/*
 
【Arduino】66种传感器模块系列实验（68）
 
实验六十八：BMP180 新款 BOSCH温度模块气压传感器（代替BMP085）
 
SFE_BMP180.h
 
*/
 
 
 
#ifndef SFE_BMP180_h
 
#define SFE_BMP180_h
 
#if defined(ARDUINO) && ARDUINO >= 100
 
#include "Arduino.h"
 
#else
 
#include "WProgram.h"
 
#endif
 
class SFE_BMP180
 
{
 
  public:
 
      SFE_BMP180();
 
      char begin();
 
        shorted?)
 
       
 
      char startTemperature(void);
 
         
 
      char getTemperature(double &T);
 
        startTemperature command
 
         
 
      char startPressure(char oversampling);
 
         
 
      char getPressure(double &P, double &T);
 
        startPressure command       
 
      double sealevel(double P, double A);
 
        weather data)
 
         
 
      double altitude(double P, double P0);
 
        sea-level, runway, etc.)
 
         
 
      char getError(void);
 
         
 
  private:
 
    
 
      char readInt(char address, int16_t &value);
 
         
 
      char readUInt(char address, uint16_t &value);
 
        
 
      char readBytes(unsigned char *values, char length);
 
         
 
         
 
      char writeBytes(unsigned char *values, char length);
 
        subsequent registers)
 
         
 
      int16_t AC1,AC2,AC3,VB1,VB2,MB,MC,MD;
 
      uint16_t AC4,AC5,AC6;
 
      double c5,c6,mc,md,x0,x1,x2,y0,y1,y2,p0,p1,p2;
 
      char _error;
 
};
 
#define BMP180_ADDR 0x77
 
#define BMP180_REG_CONTROL 0xF4
 
#define BMP180_REG_RESULT 0xF6
 
#define BMP180_COMMAND_TEMPERATURE 0x2E
 
#define BMP180_COMMAND_PRESSURE0 0x34
 
#define BMP180_COMMAND_PRESSURE1 0x74
 
#define BMP180_COMMAND_PRESSURE2 0xB4
 
#define BMP180_COMMAND_PRESSURE3 0xF4