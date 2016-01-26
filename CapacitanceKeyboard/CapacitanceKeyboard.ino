#include <CapacitiveSensor.h>
#define NUMBER_OF_KEYS 2
int threshold = 300;
CapacitiveSensor* capSensor[NUMBER_OF_KEYS];

void setup() {
  Serial.begin(9600);

  for(int i=0; i < NUMBER_OF_KEYS; i++){
    capSensor[i] = new CapacitiveSensor(13, i + 2);
    }
     
  for(int j=1; j = NUMBER_OF_KEYS; j++){
    pinMode(NUMBER_OF_KEYS + j + 1, OUTPUT);
  }
   
}

void loop() {
  long sensorValue;
  for(int k=0; k < NUMBER_OF_KEYS; k++){
    sensorValue = capSensor[k]->capacitiveSensor(30);
    Serial.println(sensorValue);
    if(sensorValue > threshold){
      digitalWrite(NUMBER_OF_KEYS + k + 1, HIGH);
    }
    else{
      digitalWrite(NUMBER_OF_KEYS + k + 1, LOW);
    }
    
    delay(10);
  }
}
