int NumberofFans = 4;
int PressureSwitchPin = 3;

void setup() {
  // put your setup code here, to run once:
  PinMode(PressureSwitchPin, INPUT);
  
  for(int i=0, i=4){
    //set fan PINS as outputs
  }  

}

void loop() {
  // put your main code here, to run repeatedly:
  if digitalRead(PressureSwitchPin) == HIGH{
    //Create a for loop to turn on all octolink couplers for fans
  }
  else{
    //turn off all fans
  }

}
