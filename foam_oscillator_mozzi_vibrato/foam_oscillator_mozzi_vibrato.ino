#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>
#include <tables/cos2048_int8.h>

const int buttonPin01 = 5;
const int buttonPin02 = 4;
const int buttonPin03 = 3;

const int buttonPin04 = 1;

int buttonState01 = 0;
int buttonState02 = 0;
int buttonState03 = 0;

int offset = 0;

//const int KNOB_PIN = 1; // set the input for the knob to analog pin 0

//#define CONTROL_RATE 128 // Vibrato

Oscil <2048, AUDIO_RATE> aSin(SIN2048_DATA);

//Oscil <2048, CONTROL_RATE> kVib(SIN2048_DATA);// Vibrato
Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aVibrato(COS2048_DATA);

const byte intensity = 255;

float depth = .25;

void setup() {
  // put your setup code here, to run once:
  startMozzi(CONTROL_RATE);
  aSin.setFreq(440);
  aVibrato.setFreq(15.f);
  //kVib.setFreq(6.5f); // Vibrato

  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  pinMode(buttonPin03, INPUT);

  pinMode(buttonPin04, INPUT);
  //Serial.begin(115200);
}
int frequency = 0;
void updateControl(){
  // no controls being changed
  //int knob_value = mozziAnalogRead(KNOB_PIN);

  //Serial.print(knob_value); 

}

int updateAudio(){
  Q15n16 vibrato = (Q15n16) intensity * aVibrato.next();
  //return aSin.next();
  return aSin.phMod(vibrato);
}


void loop() {
  //int knob_value = mozziAnalogRead(KNOB_PIN)/100;

  // put your main code here, to run repeatedly:
  buttonState01 = digitalRead(buttonPin01);
  buttonState02 = digitalRead(buttonPin02);
  buttonState03 = digitalRead(buttonPin03);

  //offset = analogRead(buttonPin04);
  
  //float vibrato = depth * kVib.next();

  if(buttonState01 == HIGH){
    frequency = 261;
  }else if(buttonState02 == HIGH){
    frequency = 293;
  }else if(buttonState03 == HIGH){
    frequency = 329;
  }else{
    frequency = 0;

  }

  aSin.setFreq(frequency );
  audioHook();
}
