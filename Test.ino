// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       LED.ino
    Created:	2019/12/20 
    Author:     lynsucceed@gmail.com
*/

// Define User Types below here or use a .h file

#include <Arduino.h>
#include "Color.h"

#define HUE_POT_PIN A1
Color  Led; //定义颜色对象

// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
 void led_set_rgb(uint8_t r, uint8_t g, uint8_t b)
{
   Led.setRGB(r,g,b);
   Led.inforRGB(r,g,b);
  }

void led_set_hsl(float h, float s, float l)
{
	uint8_t rgb[3];
	Led.HSVtoRGB(h,s,l,rgb);
    Led.setRGB(rgb[0],rgb[1],rgb[2]);
	Led.inforRGB(rgb[0],rgb[1],rgb[2]);

}


void play()
{
  int R = 255;
  int G = 0;
  int B= 0;
 for(G=0;G<255;G++) led_set_rgb(R,G,B);
  while(R!=0) { R--;led_set_rgb(R,G,B);}
  for(B=0;B<255;B++) led_set_rgb(R,G,B);
  for(G=255;G>0;G--) led_set_rgb(R,G,B);
  for(R=0;R<255;R++) led_set_rgb(R,G,B);
}

/*void play_control()
{
    int value;
	float h;
	value = analogRead(HUE_POT_PIN);
	h = map(value,0,1023,0,360);
	led_set_hsl(h,1,1);

}*/

// The setup() function runs once each time the micro-controller starts
void setup()
{
  Led.setPin(9,10,11);
  Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop()
{
  led_set_rgb(255,0,0);//red
  delay(1000);
  led_set_rgb(255,128,0);//orange
  delay(1000);
  led_set_rgb(255,255,0);//yellow
  delay(1000);
  led_set_rgb(0,255,0);//green
  delay(1000);
  led_set_rgb(0,255,255);//cyan
  delay(1000);
  led_set_rgb(0,0,255);//blue
  delay(1000);
  led_set_rgb(128,0,255);//purple
  delay(1000);
  led_set_rgb(255,255,255);//white
  delay(1000);
  play(); 
  //led_set_hsl(173,1,1);
	

}


