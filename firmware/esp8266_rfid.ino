#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <MFRC522.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASS";
const char* serverURL = "https://your-server/newscan";

#define RST_PIN D3
#define SS_PIN D4

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  SPI.begin(); // default hardware SPI pins on NodeMCU
  mfrc522.PCD_Init();
  Serial.println("Place your card near the scanner...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String cardID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) cardID += "0";
    cardID += String(mfrc522.uid.uidByte[i], HEX);
  }
  cardID.toUpperCase();
  Serial.println("Card ID: " + cardID);

  sendCardID(cardID);

  mfrc522.PICC_HaltA();
  delay(300);
}

void sendCardID(String cardID) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi disconnected");
    return;
  }

  WiFiClientSecure client;
  client.setInsecure(); // dev only
  HTTPClient http;

  http.begin(client, serverURL); // use WiFiClient variant
  http.addHeader("Content-Type", "application/json");

  String payload = "{\"cardID\":\"" + cardID + "\"}";
  Serial.println("Sending payload: " + payload);
  int code = http.POST(payload);

  if (code > 0) {
    Serial.println("Response code: " + String(code));
    Serial.println("Body: " + http.getString());
  } else {
    Serial.println("HTTP POST failed, code: " + String(code));
  }
  http.end();
}
