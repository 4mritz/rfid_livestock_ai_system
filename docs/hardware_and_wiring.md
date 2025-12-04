# Wiring Guide (ESP32 and ESP8266)

This document explains how to wire the MFRC522 RFID module to ESP32 and ESP8266 microcontrollers.  
Always power the RC522 with 3.3V.

---

## ESP32 Wiring 

Wire the RC522 to these exact GPIO pins:

• Connect RC522 VCC to ESP32 3.3V  
• Connect RC522 GND to ESP32 GND  
• Connect RC522 RST to GPIO 22  
• Connect RC522 SDA (SS/CS) to GPIO 5  
• Connect RC522 SCK to GPIO 18  
• Connect RC522 MOSI to GPIO 23  
• Connect RC522 MISO to GPIO 19  

The ESP32 firmware uses:

#define RST_PIN 22
#define SS_PIN 5
SPI.begin(18, 19, 23); // SCK, MISO, MOSI

---

## ESP8266 Wiring 

Use default hardware SPI on the ESP8266.

• Connect RC522 VCC to 3.3V  
• Connect RC522 GND to GND  
• Connect RC522 RST to D3  
• Connect RC522 SDA to D4  
• Connect RC522 SCK to D5  
• Connect RC522 MOSI to D7  
• Connect RC522 MISO to D6  

The ESP8266 firmware uses:

#define RST_PIN D3
#define SS_PIN D4
SPI.begin(); // Uses default hardware SPI pins

# Hardware

This project uses the following components:

• ESP32 development board (ESP32 Dev Module or LILYGO T-Display)  
• ESP8266 development board (NodeMCU or WeMos D1 Mini)  
• RC522 (MFRC522) RFID module  
• Jumper wires (short wires recommended; shielded if possible)  
• Power source: USB or regulated 3.3V  
• Optional: 10 µF decoupling capacitor across VCC and GND near the RC522  

Always run the RC522 at 3.3V. Do not connect it to 5V on ESP32 or ESP8266.
