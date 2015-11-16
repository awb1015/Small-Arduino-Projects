const int ResetPin = 2;
const int PausePin = 3;
unsigned long StartTime;
unsigned long ElapsedTime;
int Speed = 0;
int AverageSpeed = 0;
boolean Timing = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ResetPin, INPUT);
  pinMode(PausePin, INPUT);
  ElapsedTime = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  ElapsedTime = millis() - StartTime
  
  while(Timing = false){
    
    display();
    
    if (ResetPin == HIGH && ElapsedTime != 0){
      ElapsedTime = 0;
      delay(50);
    }
    
    if (PausePin == HIGH && ElapsedTime !=0){
      Timing = true;
      //we need a way to resume the timer
      delay(50);
    }
    
    
    if(PausePin == HIGH && ElapsedTime =0){
      StartTime = millis();
      Timing = true;
      delay(50);
    }

  }
  
  while(timing = true){
    display();
    
    if (PausePin == HIGH && ElapsedTime != 0){
    Timing = false;
    delay(50);
    //We need a way to pause the timer here
    }
  }

}

void display(){
  //put somethings here to organise our display
}
