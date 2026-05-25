#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_PASSWORD";

int buzzer = 25;

void setup() {
  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting...");
  }

  Serial.println("Connected");
}

void loop() {

  if (WiFi.status() != WL_CONNECTED) {

    digitalWrite(buzzer, HIGH);   // buzzer ON
    Serial.println("WiFi Lost!");

  } else {

    digitalWrite(buzzer, LOW);    // buzzer OFF
  }

  delay(500);
}