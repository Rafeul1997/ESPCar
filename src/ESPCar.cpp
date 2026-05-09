#include "ESPCar.h"
#include <WiFi.h>

// Internal WiFi server
WiFiServer server(80);
WiFiClient client;

// Default constructor (for debug)
ESPCar::ESPCar() {
  _usePWM = false;
}

// 4-pin constructor
ESPCar::ESPCar(int in1, int in2, int in3, int in4) {
  _in1 = in1; _in2 = in2; _in3 = in3; _in4 = in4;
}

// 6-pin constructor (with speed control)
ESPCar::ESPCar(int in1, int in2, int in3, int in4, int ena, int enb) {
  _in1 = in1; _in2 = in2; _in3 = in3; _in4 = in4;
  _ena = ena; _enb = enb;
  _usePWM = true;
}

void ESPCar::begin() {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);

  if (_usePWM) {
    pinMode(_ena, OUTPUT);
    pinMode(_enb, OUTPUT);
  }

  stop();
}

void ESPCar::move(int a, int b, int c, int d) {
  digitalWrite(_in1, a);
  digitalWrite(_in2, b);
  digitalWrite(_in3, c);
  digitalWrite(_in4, d);
}

void ESPCar::forward() { move(HIGH, LOW, HIGH, LOW); }
void ESPCar::backward(){ move(LOW, HIGH, LOW, HIGH); }
void ESPCar::left()    { move(LOW, HIGH, HIGH, LOW); }
void ESPCar::right()   { move(HIGH, LOW, LOW, HIGH); }
void ESPCar::stop()    { move(LOW, LOW, LOW, LOW); }

void ESPCar::setSpeed(int speed) {
  _speed = constrain(speed, 0, 255);

  if (_usePWM) {
    analogWrite(_ena, _speed);
    analogWrite(_enb, _speed);
  }
}

// WiFi setup
void ESPCar::beginWiFi(const char* ssid, const char* password) {
  WiFi.softAP(ssid, password);
  server.begin();
}

// Read request
String ESPCar::getWiFiRequest() {
  client = server.available();

  if (client) {
    String req = client.readStringUntil('\r');
    client.flush();
    return req;
  }
  return "";
}

// Send simple webpage
void ESPCar::sendWiFiResponse() {
  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<h1>ESP CAR</h1>");
    client.println("<a href='/F'>F</a><br>");
    client.println("<a href='/B'>B</a><br>");
    client.println("<a href='/L'>L</a><br>");
    client.println("<a href='/R'>R</a><br>");
    client.println("<a href='/S'>S</a><br>");

    client.println("<br>Speed:<br>");
    client.println("<a href='/SPEED?val=100'>100</a><br>");
    client.println("<a href='/SPEED?val=200'>200</a><br>");
    client.println("<a href='/SPEED?val=255'>MAX</a><br>");

    client.stop();
  }
}
