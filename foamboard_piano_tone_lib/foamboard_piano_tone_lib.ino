
#include "pitches.h"

const int buttonPin01 = 5;
const int buttonPin02 = 4;
const int buttonPin03 = 3;

const int ledPin =  13;      // the number of the LED pin

const int noteDuration = 8;

const int speakerPin = 9;

// variables will change:
int buttonState01 = 0;         // variable for reading the pushbutton status
int buttonState02 = 0;
int buttonState03 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  pinMode(buttonPin03, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState01 = digitalRead(buttonPin01);
  buttonState02 = digitalRead(buttonPin02);
  buttonState03 = digitalRead(buttonPin03);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState01 == HIGH or buttonState02 == HIGH or buttonState03 == HIGH ) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  if(buttonState01 == HIGH){
    tone(speakerPin, NOTE_C2, noteDuration);
  }else if(buttonState02 == HIGH){
    tone(speakerPin, NOTE_D2, noteDuration);
  }else if(buttonState03 == HIGH){
    tone(speakerPin, NOTE_E2, noteDuration);
  }else{
    noTone(speakerPin);
  }
  
}
