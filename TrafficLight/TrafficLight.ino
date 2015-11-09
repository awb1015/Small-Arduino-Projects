const int RedPin = 5;
const int YellowPin = 4;
const int GreenPin = 3;
int RedTime = 10000;
int YellowTime = 2000;
int GreenTime = 10000;
int lightcycle = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  digitalWrite(RedPin, LOW);
  digitalWrite(YellowPin, LOW);
  digitalWrite(GreenPin, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lightcycle = lightcycle + 1 ;
  
  switch(lightcycle){
    case 0:
    break;
    case 1:
    digitalWrite(RedPin, HIGH);
    digitalWrite(YellowPin, LOW);
    digitalWrite(GreenPin, LOW);
    delay(RedTime);
    break;
    case 2:
    digitalWrite(RedPin, LOW);
    digitalWrite(YellowPin, HIGH);
    digitalWrite(GreenPin, HIGH);
    delay(YellowTime/2);    
    digitalWrite(RedPin, LOW);
    digitalWrite(YellowPin, LOW);
    digitalWrite(GreenPin, HIGH);
    delay(GreenTime);
    break;
    case 3:
    digitalWrite(RedPin, LOW);
    digitalWrite(YellowPin, HIGH);
    digitalWrite(GreenPin, LOW);
    delay(YellowTime);
    lightcycle = 0;
    break;
  }
    
  
}
