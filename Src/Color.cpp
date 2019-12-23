#include <Arduino.h>
#include <math.h>
#include "Color.h"


void Color::setPin(uint8_t R_pin, uint8_t G_pin, uint8_t B_pin) //类的方法，设置引脚
{
	this->R_pin = R_pin;
	this->G_pin = G_pin;
	this->B_pin = B_pin;
	pinMode(R_pin,OUTPUT);
	pinMode(G_pin,OUTPUT);
	pinMode(B_pin,OUTPUT);
}   

void Color::setRGB(uint8_t r, uint8_t g, uint8_t b) //类的方法，RGB设置显示函数
{
    rValue = r;
    gValue = g;
    bValue = b;
   analogWrite(R_pin,255-rValue);
   analogWrite(G_pin,255-gValue);
   analogWrite(B_pin,255-bValue);
}

void Color::inforRGB(uint8_t r, uint8_t g, uint8_t b) //类的方法，串口打印函数
{
    rValue = r;
    gValue = g;
    bValue = b;
  Serial.print("R:");
  Serial.print( rValue );
  Serial.print(",G:");
  Serial.print( gValue);
  Serial.print(",B:");
  Serial.print(bValue );
  Serial.println();
 }

void Color::HSVtoRGB( float h,  float s, float v,uint8_t * rgbOut) //类的方法，HSL转RGB函数
{

	float r = 0.0f, g = 0.0f, b = 0.0f;
	float p, q, t;
	float h60 = h/60.0f;
	float h60f = floor(h60);
	int hi =int(h60f) % 6;
	float f = h60 - h60f;
	p = v * (1 - s);
    q = v * (1 - f * s);
    t = v * (1 - (1 - f) * s);
	switch(hi)
	{
	  case 0: r = v; g = t; b = p; break;
      case 1: r = q; g = v; b = p; break;
	  case 2: r = p; g = v; b = t; break;
      case 3: r = p; g = q; b = v; break;
      case 4: r = t; g = p; b = v; break;
      case 5: r = v; g = p; b = q; break;
	}
	rgbOut[0] = int(r * RED_MAX);
	rgbOut[1] = int(g * GREEN_MAX);
	rgbOut[2] = int(b * BLUE_MAX);
}

