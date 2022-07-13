/*
Driver A4988 which has 200 steps per revolution
        so, per step = 200/360  = 1.8° while Resulution Full Step.
currently using only two switch for controlling the tunning in "single" direcetion
        ~either dirPin = HIGH or  dirPin = LOW ~
*/

const int enablePin = 3;
const int stepPin = 4;
const int dirPin = 5;
const int scanSwitch = 8;
const int tuneSwitch = 9;
const int ledPin = 13;


void setup() {
  
  pinMode(stepPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(scanSwitch, INPUT);
  pinMode(scanSwitch, INPUT);

}

void Tunning(int Delay, int Rotation){
  digitalWrite(enablePin, LOW);
  for(int i = 0; i < Rotation; i++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(Delay);
    digitalWrite(stepPin, LOW);
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(Delay);
  }
}

void loop() {
  digitalWrite(enablePin, HIGH);

  if(tuneSwitch == HIGH){
    digitalWrite(dirPin, LOW);
    Tunning(1500,200);
  }
  
  while(scanSwitch == HIGH) {
    digitalWrite(dirPin, LOW);
    Tunning(1000,16);
  }

}