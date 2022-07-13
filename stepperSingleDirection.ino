const int enablePin = 3;
const int stepPin = 4;
const int dirPin = 5;
const int scanSwitch = 8;
const int tuneSwitch = 9;
const int ledPin = 13;
int tuneState = 0;
int scanState = 0;


void setup() {
  
  pinMode(stepPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(tuneSwitch, INPUT);
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
  tuneState = digitalRead(tuneSwitch);
  scanState = digitalRead(scanSwitch);
  if(tuneState == HIGH){
    digitalWrite(dirPin, LOW);
    Tunning(10000,1);
    
  }
  
  if(scanState == HIGH) {
    digitalWrite(dirPin, LOW);
    Tunning(1000,16);
  }

}