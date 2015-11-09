#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int fireSwitch = 0;
int scroll = 0;
const int switchPin = 13;
const int light1Pin = 8;
const int light2Pin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(light1Pin, OUTPUT);
  pinMode(light2Pin, OUTPUT);
  
  digitalWrite(light1Pin, LOW);
  digitalWrite(light2Pin, LOW);
  
  lcd.begin(16, 2);
  lcd.print("Safe");
  
}

void loop() {
  fireSwitch = digitalRead(switchPin);
  
  if(fireSwitch == LOW){
    lcd.begin(16, 2);
    lcd.print("Safe");
    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, LOW);
  }
  
  else{
    
    for(int scroll = 0; scroll<16; scroll++){
      lcd.clear();
      lcd.setCursor(scroll, 0);
      lcd.print("FIRE!");
      if(scroll % 2){
        digitalWrite(light1Pin, LOW);
        digitalWrite(light2Pin, HIGH);
      }
      else{
        digitalWrite(light1Pin, HIGH);
        digitalWrite(light2Pin, LOW);
     }
     delay(250);      
    }
  }   
 }
