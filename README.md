# ESP-CAR 🚗

![ESP32](https://img.shields.io/badge/ESP32-Compatible-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Version](https://img.shields.io/badge/version-1.0.0-orange)
![Status](https://img.shields.io/badge/status-stable-brightgreen)



# ESP-CAR 🚗
## Author
Abdul Rafeul Mallick

ESP-CAR is an ESP32-based Arduino library to control a robot car using:
- 🔵 Bluetooth (Serial)
- 🌐 WiFi (Web Control)

## ✨ Features
- Easy motor control (Forward, Backward, Left, Right, Stop)
- Speed control (PWM)
- WiFi control using browser
- Clean and beginner-friendly API

## 📦 Installation

1. Download ZIP from GitHub
2. Open Arduino IDE
3. Go to Sketch → Include Library → Add .ZIP Library
4. Select downloaded ZIP

## 🚀 Usage

```cpp
#include <ESPCar.h>

ESPCar car(5, 18, 19, 21);

void setup() {
  car.begin();
}

void loop() {
  car.forward();
}
