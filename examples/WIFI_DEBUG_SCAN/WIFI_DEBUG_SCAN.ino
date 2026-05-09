#include <ESPCar.h>

// No pins needed
ESPCar car;

void setup() {
  Serial.begin(9600);

  car.beginWiFi("ESP-CAR", "12345678");
  Serial.println("WiFi Scan Ready");
}

void loop() {
  String req = car.getWiFiRequest();

  if (req != "") {
    Serial.println(req);
    car.sendWiFiResponse();
  }
}
