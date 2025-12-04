# Troubleshooting Guide

## Serial Monitor Shows Nothing
• Check baud rate is 115200  
• Confirm correct COM port  
• Ensure USB cable supports data  
• Add a debug print at the start of setup()  

---

## Card Not Detected or Inconsistent Detection
• Wires too long  
• Weak 3.3V power  
• Antenna misaligned  
• Interference nearby  
• Loose jumper wires  
• Add delay(50) before authentication  
• Add 10 µF capacitor at RC522 power pins  

---

## Authentication Errors  
Shown as:  
PCD_Authenticate() failed: Timeout in communication

Causes:  
• Loose wiring  
• Wrong SPI pins  
• Weak power  
• Card too far from antenna  

Fixes:  
• Shorten wire length  
• Re-seat all jumper wires  
• Confirm SPI pins match firmware  
• Add stability capacitor  

---

## Wi-Fi Issues
• Wrong credentials  
• ESP8266 only supports 2.4GHz  
• Router too far away  

---

## HTTP Errors

### 400 Bad Request
JSON not formatted correctly.

### -1 or -5
Network or SSL issue.  
Use:
http.begin(client, url);
client.setInsecure();


### 307 Redirect
Your URL is HTTP but server forces HTTPS.  
Always use the final HTTPS URL.

---

## Upload Errors
“Failed to connect to ESP32: No serial data received”  
• Wrong board selection  
• Boot button timing  
• Bad USB cable  


