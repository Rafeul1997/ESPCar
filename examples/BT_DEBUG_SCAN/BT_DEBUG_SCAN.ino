#include <ESPCar.h>

// No pins needed
ESPCar car;

void setup() {
  Serial.begin(9600);
  Serial.println("BT Scan Ready");
}

void loop() {
  if (Serial.available()) {
    Serial.println(Serial.read());
  }
}
