#include <ESPCar.h>

ESPCar car(5, 18, 19, 21, 23, 22);

char cmd;
int speedValue = 150;

void setup() {
  car.begin();
  Serial.begin(9600);
  car.setSpeed(speedValue);
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();

    if (cmd == 'F') car.forward();
    else if (cmd == 'B') car.backward();
    else if (cmd == 'L') car.left();
    else if (cmd == 'R') car.right();
    else if (cmd == 'S') car.stop();

    else if (cmd >= '0' && cmd <= '9') {
      speedValue = map(cmd - '0', 0, 9, 0, 255);
      car.setSpeed(speedValue);
    }
  }
}
