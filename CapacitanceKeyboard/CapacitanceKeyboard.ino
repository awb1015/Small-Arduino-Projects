#include <CapacitiveSensor.h>
int threshold = 1000;
const int NumberofKeys = 4;

for(int i=1; i = NumberofKeys; i++){
  CapacitiveSensor capSensor_i = CapacitiveSensor(13, i+1);
  //declare our keys as capactience sensors starting at pin 2
  //and using pin 13 as a common ground
}

void setup() {
  // put your setup code here to run once:
  Serial.begin(9600);
    
  for(int i=1; i = NumberofKeys; i++){
    pinMode(NumberofKeys + 1 + i, OUTPUT);
    //sets enough output LEDs for HIL support
  }
  
      
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=1; i = NumberofKeys; i++){
    //Check sensor value
    //then illuminate appropriate LED
    //or turn off LED as needed
  }
  
}
