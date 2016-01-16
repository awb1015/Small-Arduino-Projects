#include <CapacitiveSensor.h>
#define NUMBER_OF_KEYS 2
int threshold = 300;
int i;
CapacitiveSensor* capSensor[NUMBER_OF_KEYS];

void setup() {
  Serial.begin(9600);

  for(int i=0; i < NUMBER_OF_KEYS - 1; i++){
    capSensor[i] = new CapacitiveSensor(13, i + 2);
  }
    
  for(int i=1; i = NUMBER_OF_KEYS; i++){
    pinMode(NUMBER_OF_KEYS + i + 1, OUTPUT);
  }
   
}

void loop() {
  long sensorValue;
  Serial.println(sensorValue);
  for(int i=0; i < NUMBER_OF_KEYS; i++){
    sensorValue = capSensor[i]->capacitiveSensor(30);
    if(sensorValue > threshold){
      digitalWrite(NUMBER_OF_KEYS + 1 + i, HIGH);
    }
    else{
      digitalWrite(NUMBER_OF_KEYS + 1 + i, LOW);
    }
    
    delay(10);
  }    
}
