#include <led_matrix_8x8_lib.h>
#include<TimerOne.h>  //download this library because this library helps for internal interrupts.
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
  displayChar('A');
  delay(2000);
  displayEmoji(EMOJI_HAPPY);
  delay(2000);
  display(EMOJI_HEART);
  delay(2000);
}
