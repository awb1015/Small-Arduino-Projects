#include <CapacitiveSensor.h>
int threshold = 1000;
const int NumberofKeys = 2;
CapacitiveSensor capSensor[NumberofKeys];

void setup() {
    
  for(int i=0; i < NumberofKeys - 1; i++){
    CapacitiveSensor capSensor[i] = CapacitiveSensor(13, i + 2);
  }
    
  for(int i=1; i = NumberofKeys; i++){
    pinMode(NumberofKeys + i, OUTPUT);
    //sets enough output LEDs for HIL support
  }
   
}

void loop() {
  int i;
  long sensorValue;
  
  for(int i=0; i = NumberofKeys; i++){
    sensorValue = capSensor[i].capacitiveSensor(30);
    if(sensorValue > threshold){
      digitalWrite(NumberofKeys + 1 + i, HIGH);
    }
    else{
      digitalWrite(NumberofKeys + 1 + i, LOW);
    }
    
    delay(10);
  }    
}
