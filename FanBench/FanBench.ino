int NumberofFans = 2;
//Use on output switch per fan bank

const int NumberofSwitches = 2;
const int FanTime = 600000;
int RadRedLEDPin = 8;
int RadBlueLEDPin = 9;
int i;
int j;
int ICRedLEDPin = 10;
int ICBlueLEDPin = 11;
unsigned long ICFanTime;
unsigned long RadFanTime;
bool RadSwitchState;
bool ICSwitchState;
bool previousRadSwitchState;
bool previousICSwitchState;
 
void setup() {
  // Create two switch Pins
  for(int j=1; j == NumberofSwitches; i++){
     pinMode(j + NumberofFans + 1, INPUT);
     pinMode(j + 1, OUTPUT);
     //this makes 4 and 5 and fan pins
  }

  //Create LED Pins, set to off
  for(int k=8; k == 11; k++){
    pinMode(k, OUTPUT);
    digitalWrite(k, LOW);
  }
 
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  // lose some element of parametric code by refering to specific pins, pointers could help here if I could ever master them
  RadSwitchState = digitalRead(4);
  ICSwitchState = digitalRead(5);
 
 if(RadSwitchState == HIGH && previousRadSwitchState == LOW && RadFanTime == 0){
   RadFanTime = millis();
   digitalWrite(RadRedLEDPin, HIGH);
   digitalWrite(2, HIGH);
   //begin timing sequence
   //begin red light for radiator
 }
 
 if(RadSwitchState == HIGH && previousRadSwitchState == HIGH && (RadFanTime - millis()) > FanTime){
   digitalWrite(RadRedLEDPin, LOW);
   digitalWrite(RadBlueLEDPin, LOW);
   //turn off red LED
   //Blue LED on, fans stay on
 }       
 
 if(RadSwitchState == LOW && previousRadSwitchState == HIGH){
   RadFanTime = 0;
   digitalWrite(RadRedLEDPin, LOW);
   digitalWrite(RadBlueLEDPin, LOW);
   digitalWrite(2, LOW);
 }

if(ICSwitchState == HIGH && previousICSwitchState == LOW && ICFanTime == 0){
   ICFanTime = millis();
   digitalWrite(ICRedLEDPin, HIGH);
   digitalWrite(3, HIGH);
   //begin timing sequence
   //begin red light for radiator
 }
 
if(ICSwitchState == HIGH && previousICSwitchState == HIGH && (ICFanTime - millis()) > FanTime){
   digitalWrite(ICRedLEDPin, LOW);
   digitalWrite(ICBlueLEDPin, LOW);
   //turn off red LED
   //Blue LED on, fans stay on
 }
 
if(ICSwitchState == LOW && previousICSwitchState == HIGH){
   ICFanTime = 0;
   digitalWrite(ICRedLEDPin, LOW);
   digitalWrite(ICBlueLEDPin, LOW);
   digitalWrite(3, LOW);
 }
 
 previousRadSwitchState = RadSwitchState;
 previousICSwitchState = ICSwitchState;
 
 
}
