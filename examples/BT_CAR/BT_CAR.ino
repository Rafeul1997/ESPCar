#include <ESPCar.h>   // Include ESPCar library

// Create car object with motor control pins
// IN1, IN2, IN3, IN4
ESPCar car(5, 18, 19, 21);

char cmd;  // Variable to store incoming Bluetooth/Serial command

void setup() {
  car.begin();          // Initialize motor pins
  Serial.begin(9600);   // Start serial communication (Bluetooth/USB)
}

void loop() {
  // Check if data is available from Serial (Bluetooth)
  if (Serial.available()) {

    cmd = Serial.read();  // Read incoming command

    // Control car movement based on received command
    if (cmd == 'F') 
      car.forward();   // Move forward

    else if (cmd == 'B') 
      car.backward();  // Move backward

    else if (cmd == 'L') 
      car.left();      // Turn left

    else if (cmd == 'R') 
      car.right();     // Turn right

    else if (cmd == 'S') 
      car.stop();      // Stop the car
  }
}
