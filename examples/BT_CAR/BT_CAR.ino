#include <ESPCar.h>

// Motor pins: IN1, IN2, IN3, IN4
ESPCar car(5, 18, 19, 21);

char cmd;

void setup() {
  Serial.begin(9600);   // Bluetooth uses Serial
  car.begin();
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();

    // Control commands from mobile app
    if (cmd == 'F') car.forward();   // Forward
    else if (cmd == 'B') car.backward(); // Backward
    else if (cmd == 'L') car.left(); // Left
    else if (cmd == 'R') car.right(); // Right
    else if (cmd == 'S') car.stop(); // Stop
  }
}
