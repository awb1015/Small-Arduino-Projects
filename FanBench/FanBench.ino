int NumberofFans = 2;
//Use on output switch per fan bank

const int NumberofSwitches = 2;
const int FanTime = 600000;
const int RadRedLEDPin = 8;
const int RadBlueLEDPin = 9;
const int ICRedLEDPin = 10;
const int ICBlueLEDPin = 11;
unsigned long ICFanTime;
unsigned long RadFanTime;
bol RadSwitchState;
bol ICSwitchState;
bol previousRadSwitchState;
bol previousICSwitchState;
 
void setup() {
  // Create two switch Pins
  for(int j=1; j == NumberofSwitches, i++){
     PinMode(J + NumberofFans + 1, INPUT);
     //this makes 4 and 5
  }
 
  //Create Fan Pins
  for(int i=1; i == NumberofFans, i++){
    PinMode(i+1, OUTPUT);
    // this makes 2 and 3
  } 
  
  //Create LED Pins, set to off
  for(int k=8; k == 11, k++){
    PinMode(k, OUTPUT);
    digitalWrite(k, LOW);
  }
 
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  // lose some element of parametric code by refering to specific pins, pointers could help here if I could ever master them
  radSwitchState = digitalRead(4);
  ICSwitchState = digitalRead(5);
 
 if(radSwitchState == HIGH && previousRadSwitchState == LOW && RadFanTime == 0){
   millis() = RadFanTime;
   digitalWrite(RadRedLEDPin, HIGH);
   digitalWrite(2, HIGH);
   //begin timing sequence
   //begin red light for radiator
 }
 
 if(radSwitchState == HIGH && previousRadSwitchState == HIGH && (RadFanTime - millis()) > FanTime){
   digitalWrite(RadRedLEDPin = LOW);
   digitalWrite(RadBlueLEDPin = LOW);
   //turn off red LED
   //Blue LED on, fans stay on
 }       
 
 if(radSwitchState == LOW && previousRadSwitchState == HIGH){
   RadFanTime = 0;
   digitalWrite(RadRedLEDPin, LOW);
   digitalWrite(RadBlueLEDPin, LOW);
   digitalWrite(2, LOW);
 }

if(ICSwitchState == HIGH && previousICSwitchState == LOW && ICFanTime == 0){
   millis() = ICFanTime;
   digitalWrite(ICRedLEDPin, HIGH);
   digitalWrite(3, HIGH);
   //begin timing sequence
   //begin red light for radiator
 }
 
 if(ICSwitchState == HIGH && previousICSwitchState == HIGH && (ICFanTime - millis()) > FanTime){
   digitalWrite(ICRedLEDPin = LOW);
   digitalWrite(ICBlueLEDPin = LOW);
   //turn off red LED
   //Blue LED on, fans stay on
 }
 
  if(ICSwitchState == LOW && previousICSwitchState == HIGH){
   ICFanTime = 0;
   digitalWrite(ICRedLEDPin, LOW);
   digitalWrite(ICBlueLEDPin, LOW);
   digitalWrite(3, LOW);
 }
 
 previousRadSwitchState = radSwitchState;
 previousICSwitchState = ICSwitchState;
 //need to add IC bench as well
 
}
