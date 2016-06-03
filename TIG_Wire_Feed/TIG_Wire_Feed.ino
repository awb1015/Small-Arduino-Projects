#include <Stepper.h>
const int stepsPerRevolution = 200
const int stepPin = 3;
const int minStepInterval = 50;
const int maxStepInterval = 2000;
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
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  //output our parameters and their values
  Serial.print(“stepSpeed”);
  Serial.print(stepSpeed);
  Serial.print(“stepInterval”);
  Serial.print(stepInterval);
  Serial.print(“stepSize”);
  Serial.println(stepSize);
 
  //now map our three potentiometers to the new values of stepSize, stepSpeed, and stepInterval;
  stepInterval =  map(potvalue, lowpot, highpot, minStepInterval, maxStepInterval );
  stepSpeed = map(potvalue, lowpot, highpot, minStepSpeed, maxStepSpeed);
  stepSize =  map(potvalue, lowpot, highpot, minStepSize, maxStepSize);
 
  //now we update the speed field of the stepper object
  myStepper.setSpeed(stepSpeed);
 
  //check that delay time has passed 
 
  //if step pin is pushed and delay time has passed step again
  if(digitalRead(stepPin)==HIGH){
  //command to step motor at given speed, for given step size
  }
 
 
 
}
