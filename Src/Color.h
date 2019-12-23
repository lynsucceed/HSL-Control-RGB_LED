/*
  颜色类，可以分别设置色彩的RGB分量
 */
 
#ifndef COLOR_H  //预编译指令，防止重复定义类
#define COLOR_H
#include <Arduino.h>

#define RED_MAX 255
#define GREEN_MAX 255
#define BLUE_MAX 255

class Color
{
private:    //私有成员，用来保存色彩的RGB分量
  uint8_t rValue;
  uint8_t gValue;
  uint8_t bValue;
  uint8_t R_pin;
  uint8_t G_pin;
  uint8_t B_pin;

public:
  void Color::setPin(uint8_t R_pin, uint8_t G_pin, uint8_t B_pin);//类的方法，设置引脚
  void setRGB(uint8_t r, uint8_t g, uint8_t b); //类的方法，RGB设置显示函数
  void inforRGB(uint8_t r, uint8_t g, uint8_t b);//类的方法，串口打印函数
  void HSVtoRGB(float h, float s, float v,uint8_t * rgbOut);//类的方法，HSV转RGB函数
};

#endif // COLOR_H


