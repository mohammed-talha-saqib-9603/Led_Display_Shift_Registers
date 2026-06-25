#include "led_matrix_8x8_lib.h"
#include<TimerOne.h>  //download this library because this library helps for internal interrupts.
//#include <led_matrix_8x8_lib.h> //if you copied led_matrix_8x8_lib and pasted it in libraries folder of arduino
const int dataPin=6;
const int clockPin=9;
const int latchPin=7;
unsigned long time1=0;
unsigned long time2;

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
    scroll("hello",2);
    time2=millis();
  }else{
    scroll("my name is talha",3);
    if(millis()-time2>=10000){
      time1=millis();
    }
  }
}
