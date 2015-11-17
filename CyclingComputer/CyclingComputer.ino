const int ResetPin = 2;
const int PausePin = 3;
unsigned long StartTime;
unsigned long ElapsedTime;
unsigned long PauseTimeStart;
unsigned long PauseTime;
unsigned long TotalPauseTime;
int Speed = 0;
int AverageSpeed = 0;
boolean Timing = false;
int hours = 0;
int minutes = 0;
int seconds = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ResetPin, INPUT);
  pinMode(PausePin, INPUT);
  ElapsedTime = 0;
  TotalPauseTime = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
    
  while(Timing = false){
    
    display();
    
    if (ResetPin == HIGH && ElapsedTime != 0){
      ElapsedTime = 0;
      TotalPauseTime = 0;
      delay(50);
    }
    
    if (PausePin == HIGH && ElapsedTime !=0){
      PauseTime = millis() - PauseTimeStart;
      TotalPauseTime = TotalPauseTime + PauseTime;
      Timing = true;
      delay(50);
    }
    
    
    if(PausePin == HIGH && ElapsedTime = 0){
      StartTime = millis();
      Timing = true;
      delay(50);
    }

  }
  
  while(timing = true){
    display();
    
    if (PausePin == HIGH && ElapsedTime != 0){
      PauseTimeStart = millis();
      Timing = false;
      delay(50);
   }
  }

}

void display(){
  ElapsedTime = millis() - ( StartTime + TotalPauseTime);
  seconds = (ElapsedTime / 1000) % 60;
  minutes = (ElapsedTime / (1000*60)) % 60;
  hours = (ElapsedTime / (1000*60*60)) % 24;
  //Now we'll need to display this elapsedtime in a friendly format
  
}
