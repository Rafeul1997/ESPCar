#include <ESPCar.h>   // Include ESPCar library

// Create car object with motor pins + speed control pins
// IN1, IN2, IN3, IN4, ENA, ENB
ESPCar car(5, 18, 19, 21, 23, 22);

String req;           // Variable to store incoming WiFi request
int speedValue = 150; // Default speed (range: 0–255)

void setup() {
  car.begin();   // Initialize motor control pins

  car.setSpeed(speedValue); // Set initial speed of motors

  // Start ESP32 as WiFi Access Point
  // SSID: ESP-CAR
  // Password: 12345678
  car.beginWiFi("ESP-CAR", "12345678");
}

void loop() {

  // Get incoming HTTP request from browser/client
  req = car.getWiFiRequest();

  // Proceed only if a request is received
  if (req != "") {

    // Movement control using URL paths
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

    // -------- SPEED CONTROL --------
    // URL format: /SPEED?val=XXX
    // Example: /SPEED?val=200

    int idx = req.indexOf("val="); // Find "val=" in request

    if (idx != -1) {
      // Extract number after "val="
      speedValue = req.substring(idx + 4).toInt();

      // Ensure speed stays within valid range (0–255)
      speedValue = constrain(speedValue, 0, 255);

      // Apply new speed to motors
      car.setSpeed(speedValue);
    }

    // Send HTML response (control page) back to browser
    car.sendWiFiResponse();
  }
}
