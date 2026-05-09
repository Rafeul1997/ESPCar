#include <ESPCar.h>   // Include ESPCar library

// Create car object with motor pins + speed control pins
// IN1, IN2, IN3, IN4, ENA, ENB
ESPCar car(5, 18, 19, 21, 23, 22);

char cmd;              // Variable to store received command
int speedValue = 150;  // Default speed (0–255)

void setup() {
  car.begin();            // Initialize motor and control pins
  Serial.begin(9600);     // Start Serial (Bluetooth/USB communication)

  car.setSpeed(speedValue); // Set initial motor speed
}

void loop() {

  // Check if any command is received
  if (Serial.available()) {

    cmd = Serial.read();  // Read incoming character

    // Movement control commands
    if (cmd == 'F') 
      car.forward();    // Move forward

    else if (cmd == 'B') 
      car.backward();   // Move backward

    else if (cmd == 'L') 
      car.left();       // Turn left

    else if (cmd == 'R') 
      car.right();      // Turn right

    else if (cmd == 'S') 
      car.stop();       // Stop the car

    // Speed control using numbers (0–9)
    else if (cmd >= '0' && cmd <= '9') {

      // Convert char ('0'-'9') to number (0–9) and map to 0–255
      speedValue = map(cmd - '0', 0, 9, 0, 255);

      car.setSpeed(speedValue);  // Apply new speed
    }
  }
}
