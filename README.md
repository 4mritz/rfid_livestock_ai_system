# RFID IoT System: ESP32/ESP8266 + RC522 + Cloud Server

This repository contains a complete RFID-based IoT scanning system built using ESP32/ESP8266 microcontrollers and the MFRC522 RFID reader. The firmware reads the UID of any RFID tag and sends it to a cloud backend through an HTTP POST request.  

The backend server is implemented using Node.js + Express and exposes a `/newscan` endpoint that receives card UIDs as JSON.

This project supports:
- ESP32 (HTTPS POST with WiFiClientSecure)
- ESP8266 (HTTPS POST with WiFiClientSecure)
- Local testing (Node server)
- Cloud deployment (Render, Ngrok, or any HTTPS provider)

The system is designed for livestock tracking, portable scanners, and real-time RFID-based identification workflows.

---

## Features
- Real-time RFID card scanning
- Stable HTTP/HTTPS communication with cloud backend
- Clean firmware separation: `esp32_rfid.ino` and `esp8266_rfid.ino`
- Minimal Express server (`server/server.js`)
- Fully documented wiring, troubleshooting, and deployment instructions

---

## Project Structure
```text
firmware/
  esp32_rfid.ino         - ESP32 firmware
  esp8266_rfid.ino       - ESP8266 firmware

server/
  server.js              - Express server (POST /newscan)
  package.json
  .env.example

docs/
  hardware_and_wiring.md              - Hardware connection guide
  troubleshooting.md     - Fixes for common errors
  notes.md   - Project overview and technical notes
