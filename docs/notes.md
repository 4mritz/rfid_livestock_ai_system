# Project Notes and Summary

This project implements a portable RFID scanning system using ESP32 or ESP8266 microcontrollers with the RC522 reader. The firmware reads the UID of MIFARE RFID tags and sends the UID to a backend server using an HTTP POST request.

## Key Concepts

• SPI communication between RC522 and microcontrollers  
• Wi-Fi connectivity and HTTP/HTTPS requests  
• Use of WiFiClientSecure with setInsecure() during development  
• JSON encoding of RFID UID data  
• Express.js backend for handling incoming POST requests  
• Cloud deployment using Render  
• Debugging SPI, power, and HTTP issues  

## Architecture

RFID Tag → RC522 → ESP → Wi-Fi → POST /newscan → Server → Logging / Storage  

# Server Technical Documentation

## Technology Stack
• Node.js  
• Express.js  
• JSON middleware  
• Render for deployment  
• Optional ngrok tunnel for HTTPS during development  

---

## Endpoint Definition

### POST /newscan

Expected JSON body:
{
"cardID": "<UID>"
}


Response on success:
{
"ok": true,
"cardID": "<UID>"
}


Response codes:
• 200 → success  
• 400 → missing or invalid JSON  
• 500 → server error  

---

## Local Development Commands

Install dependencies:
cd server
npm install

Run server:
node server.js

Test with curl:
curl -X POST http://localhost:3000/newscan
-H "Content-Type: application/json"
-d '{"cardID":"TEST123"}'

---

## Deployment (Render)

1. Create a Web Service  
2. Use Node.js runtime  
3. Deploy repository  
4. Set start command:  node server.js
5. Copy your Render URL and insert into firmware as `serverURL`.

---

## Using Ngrok

Expose local server:
ngrok http 3000

Use the HTTPS URL in your ESP firmware:
WiFiClientSecure client;
client.setInsecure();

---

## Production SSL Notes

Replace:
client.setInsecure();
