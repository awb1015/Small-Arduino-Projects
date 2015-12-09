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

const int displaytime = 5000;
const

void setup() {
  
  Wire.begin();
  display.begin();
  display.setBrightness(15);
  display.clearWindow(0, 0, 96, 64);
    
}

void loop() {
  //We'll need prioritise messages and set a time for how long each display and to format the display
}  
  

