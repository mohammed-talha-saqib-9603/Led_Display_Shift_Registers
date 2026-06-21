const uint8_t dataIn=6;
const uint8_t clockPin=9;
const uint8_t latchPin=7;
uint8_t image[]={
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100,
};
void setup() {
  Serial.begin(9600);
  pinMode(dataIn,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
}

void loop() {
  display(image);
}
void display(uint8_t img[]){
  uint8_t rowselect=0b10000000;
  for(uint8_t i=0;i<8;i++){
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataIn,clockPin,LSBFIRST,~(rowselect>>i));
    shiftOut(dataIn,clockPin,LSBFIRST,img[i]);
    digitalWrite(latchPin, HIGH);

    delay(1);

  }
}