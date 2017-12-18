

#define BLACK 0x00
#define WHITE 0xFF

#define BLE_DEBUG true

#include <TinyScreen.h>
#include <Wire.h>
#include <SPI.h>
#include "lib_aci.h"
#include "aci_setup.h"
#include "uart_over_ble.h"
#include "services.h"

TinyScreen myDisplay = TinyScreen(0);

uint8_t ble_rx_buffer[21];
uint8_t ble_rx_buffer_len = 0;
uint8_t ble_connection_state = false;


void setup(void)
{
  Serial.begin(9600);
  
  Wire.begin();
  myDisplay.begin();
  myDisplay.setBrightness(15);
  myDisplay.clearWindow(0, 0, 96, 64);
  myDisplay.setFont(liberationSans_8ptFontInfo);
  
  delay(100);
  BLEsetup();
}

void loop() {
  aci_loop();//Process any ACI commands or events from the NRF8001- main BLE handler, must run often.
  
  if (ble_rx_buffer_len) {//Check if data is available
    myDisplay.print(ble_rx_buffer_len);
    myDisplay.print(" : ");
    myDisplay.print((char*)ble_rx_buffer);
    ble_rx_buffer_len = 0;//clear afer reading
  }

  

}
