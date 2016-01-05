#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);
int threshold = 1000;
const int ledPin = 12;
const int ResetPin = 13;
const int NumberofKeys = 4;

for(int i=1; i = NumberofKeys; i++){
  //declare our input capacitance keys
  //declare our output HIL or tone pins with a for loop
  //declare our key
}

void setup() {
  // put your setup code here to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ResetPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  //outputs from a capacitance will be run through with another for loop
  if(sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
    
  }
  
  else{
    digitalWrite(ledPin, LOW);
  }
  
  delay(10);
  
  if(digitalRead(ResetPin == HIGH){
    //Rezero Our Capacitance Values
  }

}
