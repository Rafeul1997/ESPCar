#include <ESPCar.h>

ESPCar car(5, 18, 19, 21, 23, 22);

String req;
int speedValue = 150;

void setup() {
  car.begin();
  car.setSpeed(speedValue);
  car.beginWiFi("ESP-CAR", "12345678");
}

void loop() {
  req = car.getWiFiRequest();

  if (req != "") {

    if (req.indexOf("/F") != -1) car.forward();
    else if (req.indexOf("/B") != -1) car.backward();
    else if (req.indexOf("/L") != -1) car.left();
    else if (req.indexOf("/R") != -1) car.right();
    else if (req.indexOf("/S") != -1) car.stop();

    int idx = req.indexOf("val=");
    if (idx != -1) {
      speedValue = req.substring(idx + 4).toInt();
      speedValue = constrain(speedValue, 0, 255);
      car.setSpeed(speedValue);
    }

    car.sendWiFiResponse();
  }
}
