#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int rowHeight = 0;
int columnPosition = 0;
const int horizontalPlus = 6;
const int horizontalMin = 7;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(columnPosition, rowHeight);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(columnPosition, rowHeight);
  lcd.print("x");
  
  if(digitalRead(horizontalPlus)== HIGH && columnPosition < 15)
  {
    columnPosition++;
    lcd.clear();
    delay(200);
    //delay to debounce switch
  }
  
  if(digitalRead(horizontalMin) == HIGH && columnPosition > 0)
  {
    columnPosition--;
    lcd.clear();
    delay(200);
    //another massive delay to debounce for my fat fingers
  }
}
