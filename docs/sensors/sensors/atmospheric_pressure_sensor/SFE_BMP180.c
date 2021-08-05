/*
 
【Arduino】66种传感器模块系列实验（68）
 
实验六十八：BMP180 新款 BOSCH温度模块气压传感器（代替BMP085）
 
SFE_BMP180.cp
 
*/
 
#include <SFE_BMP180.h>
 
#include <Wire.h>
 
#include <stdio.h>
 
#include <math.h>
 
SFE_BMP180::SFE_BMP180()
 
{
 
}
 
char SFE_BMP180::begin()
 
{
 
    double c3,c4,b1;
 
 
 
    Wire.begin();
 
    if (readInt(0xAA,AC1) &&
 
        readInt(0xAC,AC2) &&
 
        readInt(0xAE,AC3) &&
 
        readUInt(0xB0,AC4) &&
 
        readUInt(0xB2,AC5) &&
 
        readUInt(0xB4,AC6) &&
 
        readInt(0xB6,VB1) &&
 
        readInt(0xB8,VB2) &&
 
        readInt(0xBA,MB) &&
 
        readInt(0xBC,MC) &&
 
        readInt(0xBE,MD))
 
    {
 
AC6 = 23153;
 
 
 
Calcs.pdf
 
 
 
25671; AC6 = 18974;
 
        c3 = 160.0 * pow(2,-15) * AC3;
 
        c4 = pow(10,-3) * pow(2,-15) * AC4;
 
        b1 = pow(160,2) * pow(2,-30) * VB1;
 
        c5 = (pow(2,-15) / 160) * AC5;
 
        c6 = AC6;
 
        mc = (pow(2,11) / pow(160,2)) * MC;
 
        md = MD / 160.0;
 
        x0 = AC1;
 
        x1 = 160.0 * pow(2,-13) * AC2;
 
        x2 = pow(160,2) * pow(2,-25) * VB2;
 
        y0 = c4 * pow(2,15);
 
        y1 = c4 * c3;
 
        y2 = c4 * b1;
 
        p0 = (3791.0 - 8.0) / 1600.0;
 
        p1 = 1.0 - 7357.0 * pow(2,-20);
 
        p2 = 3038.0 * 100.0 * pow(2,-36);
 
        return(1);
 
    }
 
    else
 
    {
 
 
 
        return(0);
 
    }
 
}
 
char SFE_BMP180::readInt(char address, int16_t &value)
 
{
 
    unsigned char data[2];
 
    data[0] = address;
 
    if (readBytes(data,2))
 
    {
 
        value = (int16_t)((data[0]<<8)|data[1]);
 
 
 
negative
 
        return(1);
 
    }
 
    value = 0;
 
    return(0);
 
}
 
char SFE_BMP180::readUInt(char address, uint16_t &value)
 
{
 
    unsigned char data[2];
 
    data[0] = address;
 
    if (readBytes(data,2))
 
    {
 
        value = (((uint16_t)data[0]<<8)|(uint16_t)data[1]);
 
        return(1);
 
    }
 
    value = 0;
 
    return(0);
 
}
 
char SFE_BMP180::readBytes(unsigned char *values, char length)
 
{
 
    char x;
 
    Wire.beginTransmission(BMP180_ADDR);
 
    Wire.write(values[0]);
 
    _error = Wire.endTransmission();
 
    if (_error == 0)
 
    {
 
        Wire.requestFrom(BMP180_ADDR,length);
 
while(Wire.available() != length) ;
 
        for(x=0;x<length;x++)
 
        {
 
            values[x] = Wire.read();
 
        }
 
        return(1);
 
    }
 
    return(0);
 
}
 
char SFE_BMP180::writeBytes(unsigned char *values, char length)
 
{
 
    char x;
 
 
 
    Wire.beginTransmission(BMP180_ADDR);
 
    Wire.write(values,length);
 
    _error = Wire.endTransmission();
 
    if (_error == 0)
 
        return(1);
 
    else
 
        return(0);
 
}
 
char SFE_BMP180::startTemperature(void)
 
{
 
    unsigned char data[2], result;
 
 
 
    data[0] = BMP180_REG_CONTROL;
 
    data[1] = BMP180_COMMAND_TEMPERATURE;
 
    result = writeBytes(data, 2);
 
if (result)
 
return(5);
 
    else
 
return(0);
 
}
 
char SFE_BMP180::getTemperature(double &T)
 
{
 
    unsigned char data[2];
 
    char result;
 
    double tu, a;
 
 
 
    data[0] = BMP180_REG_RESULT;
 
    result = readBytes(data, 2);
 
if (result)
 
    {
 
        tu = (data[0] * 256.0) + data[1];
 
 
 
        a = c5 * (tu - c6);
 
        T = a + (mc / (a + md));
 
    }
 
    return(result);
 
}
 
char SFE_BMP180::startPressure(char oversampling)
 
{
 
    unsigned char data[2], result, delay;
 
 
 
    data[0] = BMP180_REG_CONTROL;
 
    switch (oversampling)
 
    {
 
        case 0:
 
            data[1] = BMP180_COMMAND_PRESSURE0;
 
            delay = 5;
 
        break;
 
        case 1:
 
            data[1] = BMP180_COMMAND_PRESSURE1;
 
            delay = 8;
 
        break;
 
        case 2:
 
            data[1] = BMP180_COMMAND_PRESSURE2;
 
            delay = 14;
 
        break;
 
        case 3:
 
            data[1] = BMP180_COMMAND_PRESSURE3;
 
            delay = 26;
 
        break;
 
        default:
 
            data[1] = BMP180_COMMAND_PRESSURE0;
 
            delay = 5;
 
        break;
 
    }
 
    result = writeBytes(data, 2);
 
    if (result)
 
return(delay);
 
    else
 
return(0);
 
}
 
char SFE_BMP180::getPressure(double &P, double &T)
 
sealevel().
 
{
 
    unsigned char data[3];
 
    char result;
 
    double pu,s,x,y,z;
 
 
 
    data[0] = BMP180_REG_RESULT;
 
    result = readBytes(data, 3);
 
if (result)
 
    {
 
        pu = (data[0] * 256.0) + data[1] + (data[2]/256.0);
 
 
 
        s = T - 25.0;
 
        x = (x2 * pow(s,2)) + (x1 * s) + x0;
 
        y = (y2 * pow(s,2)) + (y1 * s) + y0;
 
        z = (pu - x) / y;
 
        P = (p2 * pow(z,2)) + (p1 * z) + p0;
 
    }
 
    return(result);
 
}
 
double SFE_BMP180::sealevel(double P, double A)
 
{
 
    return(P/pow(1-(A/44330.0),5.255));
 
}
 
double SFE_BMP180::altitude(double P, double P0)
 
{
 
    return(44330.0*(1-pow(P/P0,1/5.255)));
 
}
 
char SFE_BMP180::getError(void)
 
 
 
{
 
    return(_error);
 
}