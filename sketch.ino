#include "WiFi.h"
#include "HTTPClient.h"
#include "DHT.h"

#define DHTPIN 15       
#define DHTTYPE DHT22
#define LEDPIN 2         // LED connected to GPIO 2

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";     // WiFi for Wokwi simulator
const char* password = "";            // No password for Wokwi virtual Wi-Fi
const char* server = "http://api.thingspeak.com/update";
String apiKey = "###";   // Your ThingSpeak Write API Key

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi Connected!");
  Serial.println("🌡️ Smart Temperature Alert System Started!");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ Failed to read from DHT22 sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.println(humidity);

  // LED alert for high temperature
  if (temperature > 30) {
    digitalWrite(LEDPIN, HIGH);
    Serial.println("⚠️ High Temperature! LED ON");
  } else {
    digitalWrite(LEDPIN, LOW);
    Serial.println("✅ Temperature Normal. LED OFF");
  }

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = server + String("?api_key=") + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity);
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("📤 Data sent to ThingSpeak!");
    } else {
      Serial.println("❌ Error sending data!");
    }
    http.end();
  } else {
    Serial.println("⚠️ WiFi Disconnected!");
  }

  delay(20000); // ThingSpeak update limit (15–20 sec)
}
