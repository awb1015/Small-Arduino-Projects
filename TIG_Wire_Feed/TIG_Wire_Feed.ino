#include <Stepper.h>
const int stepsPerRevolution = 200
const int stepPin = 3;
const int maxStepInterval = 2000;
const int minStepInterval = 50;
int stepInterval;
const int minStepSpeed = 25;
const int maxStepSpeed = 200;
int stepSpeed;
const int minStepSize = 10;
const int maxStepSize = 400;
int stepSize;
 
stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
//creates a new stepper object named myStepper

void setup() {
  // put your setup code here, to run once:
  PinMode(stepPin, OUTPUT);
  //set-up pins for potentiometers for speed, size and frequency
  Serial.begin(9600);
  myStepper.setSpeed(stepSpeed);
  //maybe this should be in loop as step speed will change
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(stepPin == HIGH)){
  //check step conditions
  //then step motor
  //and continue loop
  //output values of three parameters to serial monitor
  //a while loop may not be best as we want to continue the serial output even when the feed is not on
 
}

}
