#include <ESPCar.h>

ESPCar car(5, 18, 19, 21);
String req;

void setup() {
  car.begin();
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

    car.sendWiFiResponse();
  }
}
