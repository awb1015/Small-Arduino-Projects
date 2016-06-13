#include <Stepper.h>
const int stepsPerRevolution = 200
//Alter this depending on the motor used
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
 
int const stepIntervalPin = A0;
int const stepSpeedPin = A1;
int const stepSizePin = A2;
 
int intervalPotVal;
int speedPotVal;
int sizePotVal;
 
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
 
  //Potentiometer Values are simply values of a read from the specified pin
  intervalPotVal = analogRead(stepIntervalPin);
  speedPotVal = analogRead(stepSpeedPin);
  sizePotVal = analogRead(stepSizePin);
 
  //output our parameters and their values
  Serial.print(“stepSpeed”);
  Serial.print(stepSpeed);
  Serial.print(“stepInterval”);
  Serial.print(stepInterval);
  Serial.print(“stepSize”);
  Serial.println(stepSize);
 
  //now map our three potentiometers to the new values of stepSize, stepSpeed, and stepInterval;
  stepInterval =  map(intervalPotVal, 0, 1023, minStepInterval, maxStepInterval );
  stepSpeed = map(speedPotVal, 0, 1023, minStepSpeed, maxStepSpeed);
  stepSize =  map(sizePotVal, 0, 1023, minStepSize, maxStepSize);
 
  //now we update the speed field of the stepper object
  myStepper.setSpeed(stepSpeed);
 
  //check that delay time has passed and pin is pushed and has been pushed for sometime
  //We need to add variables for switchState and previousSwitchState
    if(digitalRead(stepPin)==HIGH && ){
  //command to step motor at given speed, for given step size
         myStepper.step(stepSize);
     delay(stepInterval);
     //both these commands are block, the program will not move on
 
  }
 
 
 
}
