#include <ESPCar.h>   // Include ESPCar library

// Create car object with motor control pins
// IN1, IN2, IN3, IN4
ESPCar car(5, 18, 19, 21);

String req;  // Variable to store incoming WiFi request

void setup() {
  car.begin();   // Initialize motor pins

  // Start WiFi Access Point
  // SSID: ESP-CAR
  // Password: 12345678
  car.beginWiFi("ESP-CAR", "12345678");
}

void loop() {

  // Get incoming HTTP request from client (browser)
  req = car.getWiFiRequest();

  // Check if request is not empty
  if (req != "") {

    // Check URL and control movement accordingly
    if (req.indexOf("/F") != -1) 
      car.forward();   // Move forward

    else if (req.indexOf("/B") != -1) 
      car.backward();  // Move backward

    else if (req.indexOf("/L") != -1) 
      car.left();      // Turn left

    else if (req.indexOf("/R") != -1) 
      car.right();     // Turn right

    else if (req.indexOf("/S") != -1) 
      car.stop();      // Stop the car

    // Send response back to browser (HTML control page)
    car.sendWiFiResponse();
  }
}
