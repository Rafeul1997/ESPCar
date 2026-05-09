#include <ESPCar.h>

ESPCar car(5, 18, 19, 21);

char cmd;

void setup() {
  car.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();

    if (cmd == 'F') car.forward();
    else if (cmd == 'B') car.backward();
    else if (cmd == 'L') car.left();
    else if (cmd == 'R') car.right();
    else if (cmd == 'S') car.stop();
  }
}
