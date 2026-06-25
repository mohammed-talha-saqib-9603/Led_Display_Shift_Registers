/* 
 display refreshes independent of loop function you can use long delays.
 and these long delays won't blank display
 However, scrolling and animations works in loop.
 This Scroll function is designed for just upto 46 characters in string. just for basic library.
 
*/

#include <led_matrix_8x8_lib.h>
#include<TimerOne.h>  //download this library because this library helps for internal interrupts.
const int dataPin=6;
const int clockPin=9;
const int latchPin=7;
unsigned long time1=0;
unsigned long time2;

const uint8_t image[]={
    0b00010000,
    0b00111000,
    0b01111100,
    0b11111110,
    0b00111000,
    0b00111000,
    0b00111000,
    0b00111000
}

void setup() {
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  display_begin(dataPin,clockPin,latchPin);
  Timer1.begin(1000);
  Timer1.attachInterrupt(scanner);
}

void loop() {
  if(millis()-time1<=5000){
    scroll("HELLO",2);
    time2=millis();
  }else{
    scroll("MY NAME IS TALHA",3);
    if(millis()-time2>=10000){
      time1=millis();
    }
  }
}
