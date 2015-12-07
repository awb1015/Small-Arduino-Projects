#define	BLACK           0x00
#define	BLUE            0xE0
#define	RED             0x03
#define	GREEN           0x1C
#define	DGREEN          0x0C
#define YELLOW          0x1F
#define WHITE           0xFF
#define ALPHA           0xFE
#define	BROWN           0x32

#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>

TinyScreen display = TinyScreen(0);

const int HallPin = 10;
const long screenrefresh = 75;
unsigned long previousrefresh = 0;
unsigned long StartTime;
unsigned long ElapsedTime;
unsigned long PauseTimeStart;
unsigned long PauseTime;
unsigned long TotalPauseTime;
unsigned long SpinTime;
unsigned long OldSpinTime;
int Speed = 0;
int AverageSpeed = 0;
boolean Timing = false;
int hours = 0;
int minutes = 0;
int seconds = 0;
int milliseconds = 0;
int RPM = 0;
int WheelRevolutions = 0;
int DistanceTraveled = 0;
int laparray[];
int lap = 0;
int i;
int laphours = 0;
int lapminutes = 0;
int lapseconds = 0;
int lapmilliseconds = 0;

void setup() {
  
  Wire.begin();
  display.begin();
  display.setBrightness(15);
  display.clearWindow(0, 0, 96, 64);
  pinMode(HallPin, INPUT);
  ElapsedTime = 0;
  TotalPauseTime = 0;
  Timing = false;
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
  while(Timing == false){
    
    bikespeed();
    dashboard();
    
    if (display.getButtons() == 8 && ElapsedTime != 0){
      ElapsedTime = 0;
      TotalPauseTime = 0;
      delay(250);
    }
    
    if (display.getButtons() == 4 && ElapsedTime !=0) {
      PauseTime = millis() - PauseTimeStart;
      TotalPauseTime = TotalPauseTime + PauseTime;
      Timing = true;
      delay(250);
    }
    
    
    if (display.getButtons() == 4 && ElapsedTime == 0){
      StartTime = millis();
      Timing = true;
      delay(250);
    }

  }
  
  while(Timing == true){
    
    ElapsedTime = millis() - (StartTime + TotalPauseTime); 
    
    bikespeed();
    dashboard();
    
    if (display.getButtons() == 4 && ElapsedTime != 0){
      PauseTimeStart = millis();
      Timing = false;
      delay(250);
   }
   
   if (display.getButtons() == 8 && ElapsedTime != 0){
     laparray[lap] = ElapsedTime;    
     lap++; 
   }
   
  }
  
}

void dashboard(){
  unsigned long currentrefresh = millis();
  
  if (currentrefresh - previousrefresh >= screenrefresh){
    previousrefresh = currentrefresh;
    //this way the displayed values of time are only recalculated when the display is refreshed
    //next we need to add a new page for the cycling computer that displays laps by using the value of lap and the difference between array values
    milliseconds = (ElapsedTime % 1000);
    seconds = (ElapsedTime / 1000) % 60;
    minutes = (((ElapsedTime / 1000)/ 60) % 60);
    hours = ((((ElapsedTime / 1000) / 60) / 60) % 24);
    DistanceTraveled = ((WheelRevolutions * 211 ) / 160934);
   
    display.setFont(liberationSans_8ptFontInfo);
    display.clearWindow(0, 0, 96, 64);
    display.setCursor(1, 0);
    display.fontColor(WHITE, BLACK);
    display.print(hours);
    
            
    display.setCursor(9, 0);
    display.print(":");
    if (minutes < 10){
      display.print("0");      
      display.print(minutes);
    }
    else{
      display.print(minutes);
    }
    
    display.setCursor(26, 0);
    display.print(":");
    if (seconds < 10){
      display.print("0");      
      display.print(seconds);
    }
    else{
      display.print(seconds);
    }
    
    display.setCursor(43, 0);
    display.print(":");
    if (milliseconds < 10){
      display.print("00");      
      display.print(milliseconds);
    }
    if (milliseconds > 9 && milliseconds < 100){
      display.print("0");      
      display.print(milliseconds);
    }
    if (milliseconds > 99){
      display.print(milliseconds);
    }
    
    display.setCursor(54, 9);
    if (Speed < 10){
      display.print("0");
      display.print(Speed);
      display.print("MPH");
    }
    if (Speed >= 10){
      display.print(Speed);
      display.print(" MPH");
    }
    
    display.setCursor(54, 18);
    if (DistanceTraveled < 10){
      display.print("0");
      display.print(DistanceTraveled);
      display.print("Miles");
    }
    if (DistanceTraveled >= 10){
      display.print(DistanceTraveled);
      display.print("Miles");
    }
    
   
    display.setCursor(54, 27);
    if (AverageSpeed < 10){
      display.print("0");
      display.print(AverageSpeed);
      display.print("MPH");
    }
    
    if (AverageSpeed >= 10){
      display.print(AverageSpeed);
      display.print("MPH");
    }
  
}
}

void dashboard2(){
  //In here we begin the display of laptimes
  //calculate laptimes using a For Loop
  display.setCursor(0, 0);
  display.print("Laps");
  lapmilliseconds = ((laparray[0] - StartTime) % 1000);
  lapseconds = ((laparray[0] - StartTime) / 1000) % 60;
  lapminutes = ((((laparray[0] - StartTime) / 1000)/ 60) % 60);
  laphours = (((((laparray[0] - StartTime) / 1000) / 60) / 60) % 24);
  display.print(laphours);
  
  display.setCursor(9, 0);
  display.print(":");
  if (lapminutes < 10){
    display.print("0");      
    display.print(lapminutes);
  }
  else{
    display.print(lapminutes);
  }
  
  display.setCursor(26, 0);
  display.print(":");
  if (lapseconds < 10){
    display.print("0");      
    display.print(lapseconds);
  }
  else{
    display.print(lapseconds);
  }
  
  display.setCursor(43, 0);
  display.print(":");
  if (lapmilliseconds < 10){
    display.print("00");      
    display.print(lapmilliseconds);
  }
  if (lapmilliseconds > 9 && lapmilliseconds < 100){
    display.print("0");      
    display.print(lapmilliseconds);
  }
  if (lapmilliseconds > 99){
    display.print(lapmilliseconds);
  }
  //print our first lap
  
  //print subsequent laps
  //need to add contingency for additional pages if there are
  //too many laps to fit on one page
  for(int i = 1; i == lap, i++){
    display.setCursor(0, 9 * i);
    lapmilliseconds = ((laparray[i] - laparrary[i-1]) % 1000);
    lapseconds = ((laparray[i] - laparrary[i-1]) / 1000) % 60;
    lapminutes = ((((laparray[i] - laparrary[i-1]) / 1000)/ 60) % 60);
    laphours = (((((laparray[i] - laparrary[i-1]) / 1000) / 60) / 60) % 24);
    display.print(laphours);
    
    display.setCursor(9, 9 * i);
    display.print(":");
    if (lapminutes < 10){
      display.print("0");      
      display.print(lapminutes);
    }
    else{
      display.print(lapminutes);
    }
    
    display.setCursor(26, 9 * i);
    display.print(":");
    if (lapseconds < 10){
      display.print("0");      
      display.print(lapseconds);
    }
    else{
      display.print(lapseconds);
    }
    
    display.setCursor(43, 9 * i);
    display.print(":");
    if (lapmilliseconds < 10){
      display.print("00");      
      display.print(lapmilliseconds);
    }
    if (lapmilliseconds > 9 && lapmilliseconds < 100){
      display.print("0");      
      display.print(lapmilliseconds);
    }
    if (lapmilliseconds > 99){
      display.print(lapmilliseconds);
    }
        
  }
}

void bikespeed(){
  //we need to time between hall effects
  //then convert to a speed
  if( digitalRead(HallPin) == HIGH){
   SpinTime = millis();
   RPM = (SpinTime - OldSpinTime) * (1000 / 60);
   OldSpinTime = SpinTime;
   WheelRevolutions++; 
  }
  
  if (SpinTime > 2000 || OldSpinTime == 0){
    Speed = 0;
  }
  else{
    Speed = ( RPM * 60 * 211 ) / 160934;
  }
  
  if (DistanceTraveled > 0){
    AverageSpeed = DistanceTraveled / (ElapsedTime / 3600000);
  }
  if (DistanceTraveled == 0){
    AverageSpeed = 0;
  }
  
}

void timeformat(){
  //here we'll format the unsigned long into
  //a display friendly format
  //inputs to the function will be the long
  //value for time and position to put the formatted result
}  
  

