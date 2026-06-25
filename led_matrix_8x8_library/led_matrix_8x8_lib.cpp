#include <Arduino.h>
#include "led_matrix_8x8_lib.h"

static int dataIn, clockPin, latchPin;
uint8_t img[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

void display_begin(int dIn,int cPin,int lPin){
  dataIn=dIn;
  clockPin=cPin;
  latchPin=lPin;
}

void scanner(){
    static uint8_t i=0;
    uint8_t rowselect=0b10000000;
    digitalWrite(latchPin, LOW);
    shiftOut(dataIn,clockPin,LSBFIRST,~(rowselect>>i));
    shiftOut(dataIn,clockPin,LSBFIRST,img[i]);
    digitalWrite(latchPin, HIGH);
    if(i>=7){
      i=0;
    }else{
      i++;
    }
}

void displayChar (char ch){
    uint8_t i=(uint8_t)ch;
    noInterrupts();
    if(i>=127)
        for(uint8_t j=0;j<8;j++)
            img[j]=0x00;
    else{
      memcpy_P(img,font5x8[i],8);
    } 
    interrupts(); 
}

int scroll(char str[], int x_shift){
  if(strlen(str)>46){
    return 2;
  }
  static unsigned long t1=0;
  uint8_t n=strlen(str);
  static uint8_t j=0;
  static uint8_t pos=0;
  static char laststr[50];
  if(strcmp(laststr,str)){
    j=0;
    pos=0;
    strcpy(laststr,str);
  }
    if(millis()-t1>=100){
      char temp[50];
      strcpy(temp,str);
      strcat(temp,"   ");
      uint8_t L1[8],L2[8];
      if(x_shift < 1 || x_shift > 7){
        return 0;
      }
      memcpy_P(L1,font5x8[(uint8_t)temp[j]>=127 ? 0 :(uint8_t)temp[j] ],8);
      memcpy_P(L2,font5x8[(uint8_t)temp[j+1]>=127 ? 0 :(uint8_t)temp[j+1] ],8);
      noInterrupts();
      for(int r=0;r<8;r++){
        img[r]=((L1[r]<<pos) | (L2[r]>>(8-pos)));
      }
      interrupts();
      pos+=x_shift;
      if(pos>=8){
        pos=0;
        j++;
      }
      if(j==n+3){
        j=0;
      }
      t1=millis();
    }
  return 1;
}
void displayEmoji(const uint8_t *str){
  noInterrupts();
  memcpy_P(img,str,8);
  interrupts();
}
void displayImage(const uint8_t *str){
  noInterrupts();
  memcpy(img,str,8);
  interrupts();
}