const int ResetPin = 2;
const int PausePin = 3;
unsigned long StartTime;
unsigned long ElapsedTime;
int Speed = 0;
int AverageSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ResetPin, INPUT);
  pinMode(PausePin, INPUT);
  ElapsedTime = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  ElapsedTime = millis() - StartTime
  
  if (ResetPin == HIGH && ElapsedTime != 0){
    ElapsedTime = 0
    delay(50);
  }
  
  if (PausePin == HIGH && ElapsedTime = 0){
    StartTime = millis();
    delay(50);
  }
  
    
    
    



}
