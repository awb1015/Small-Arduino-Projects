#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ResetPin = 8;
const int PausePin = 9;
const long screenrefresh = 50;
unsigned long previousrefresh = 0;
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
int milliseconds = 0;

void setup() {
  // put your setup code here, to run once
  lcd.begin(16, 2);
  pinMode(ResetPin, INPUT);
  pinMode(PausePin, INPUT);
  ElapsedTime = 0;
  TotalPauseTime = 0;
  Timing = false;
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
  while(Timing == false){
    
    display();
    
    if (digitalRead(ResetPin) == HIGH && ElapsedTime != 0){
      ElapsedTime = 0;
      TotalPauseTime = 0;
      delay(150);
    }
    
    if (digitalRead(PausePin) == HIGH && ElapsedTime !=0) {
      PauseTime = millis() - PauseTimeStart;
      TotalPauseTime = TotalPauseTime + PauseTime;
      Timing = true;
      delay(150);
    }
    
    
    if (digitalRead(PausePin) == HIGH && ElapsedTime == 0){
      StartTime = millis();
      Timing = true;
      delay(150);
    }

  }
  
  while(Timing == true){
    
    ElapsedTime = millis() - (StartTime + TotalPauseTime); 
    
    display();
    
    if (digitalRead(PausePin) == HIGH && ElapsedTime != 0){
      PauseTimeStart = millis();
      Timing = false;
      delay(150);
   }
  }

}

void display(){
  unsigned long currentrefresh = millis();
  
  if (currentrefresh - previousrefresh >= screenrefresh){
    previousrefresh = currentrefresh;
    milliseconds = (ElapsedTime % 1000);
    seconds = (ElapsedTime / 1000) % 60;
    minutes = (((ElapsedTime / 1000)/ 60) % 60);
    hours = ((((ElapsedTime / 1000) / 60) / 60) % 24);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(hours);
    lcd.setCursor(2, 0);
    lcd.print(minutes);
    lcd.setCursor(4, 0);
    lcd.print(seconds);
    lcd.setCursor(7, 0);
    lcd.print(milliseconds);  
  }
}
  
  //This is just a trial display set-up
  

