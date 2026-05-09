#include <WiFi.h>
#include <ESPCar.h>

ESPCar car(5, 18, 19, 21, 23, 22);

const char* ssid = "ESP-CAR";
const char* password = "12345678";

WiFiServer server(80);

int speedValue = 150;

void setup() {
  car.begin();
  car.setSpeed(speedValue);

  WiFi.softAP(ssid, password);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/F") != -1) car.forward();
    else if (request.indexOf("/B") != -1) car.backward();
    else if (request.indexOf("/L") != -1) car.left();
    else if (request.indexOf("/R") != -1) car.right();
    else if (request.indexOf("/S") != -1) car.stop();

    // Speed control via URL like /SPEED?val=200
    int idx = request.indexOf("val=");
    if (idx != -1) {
      speedValue = request.substring(idx + 4).toInt();
      speedValue = constrain(speedValue, 0, 255);
      car.setSpeed(speedValue);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<h1>ESP CAR SPEED CONTROL</h1>");
    client.println("<a href='/F'>Forward</a><br>");
    client.println("<a href='/B'>Backward</a><br>");
    client.println("<a href='/L'>Left</a><br>");
    client.println("<a href='/R'>Right</a><br>");
    client.println("<a href='/S'>Stop</a><br>");

    client.println("<br>Set Speed:<br>");
    client.println("<a href='/SPEED?val=100'>Speed 100</a><br>");
    client.println("<a href='/SPEED?val=200'>Speed 200</a><br>");

    client.stop();
  }
}
