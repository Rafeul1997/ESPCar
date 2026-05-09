#include <WiFi.h>
#include <ESPCar.h>

ESPCar car(5, 18, 19, 21);

const char* ssid = "ESP-CAR";
const char* password = "12345678";

WiFiServer server(80);

void setup() {
  car.begin();

  WiFi.softAP(ssid, password); // Create hotspot
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // Control from browser buttons
    if (request.indexOf("/F") != -1) car.forward();
    else if (request.indexOf("/B") != -1) car.backward();
    else if (request.indexOf("/L") != -1) car.left();
    else if (request.indexOf("/R") != -1) car.right();
    else if (request.indexOf("/S") != -1) car.stop();

    // Simple HTML page
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<h1>ESP CAR CONTROL</h1>");
    client.println("<a href='/F'>Forward</a><br>");
    client.println("<a href='/B'>Backward</a><br>");
    client.println("<a href='/L'>Left</a><br>");
    client.println("<a href='/R'>Right</a><br>");
    client.println("<a href='/S'>Stop</a><br>");

    client.stop();
  }
}
