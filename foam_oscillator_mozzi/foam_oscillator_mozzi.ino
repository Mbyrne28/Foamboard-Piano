#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

const int buttonPin01 = 5;
const int buttonPin02 = 4;
const int buttonPin03 = 3;

int buttonState01 = 0;
int buttonState02 = 0;
int buttonState03 = 0;

Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);

#define CONTROL_RATE 128

void setup() {
  // put your setup code here, to run once:
  startMozzi(CONTROL_RATE);
  aSin.setFreq(440);
  
  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  pinMode(buttonPin03, INPUT);

}

void updateControl(){
  // no controls being changed
}

int updateAudio(){
  return aSin.next();
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState01 = digitalRead(buttonPin01);
  buttonState02 = digitalRead(buttonPin02);
  buttonState03 = digitalRead(buttonPin03);

  if(buttonState01 == HIGH){
    aSin.setFreq(200);
  }else if(buttonState02 == HIGH){
    aSin.setFreq(300);
  }else if(buttonState03 == HIGH){
    aSin.setFreq(400);
  }else{
    aSin.setFreq(0);
  }
  
  audioHook();
}
