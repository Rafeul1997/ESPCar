# 🚗 ESPCar – ESP32 Smart RC Car Library

ESPCar is an Arduino library for ESP32 that enables WiFi and Bluetooth control of a robot car with speed and direction management.

![ESP32](https://img.shields.io/badge/ESP32-Compatible-blue)
![WiFi Control](https://img.shields.io/badge/WiFi-Control-00AEEF)
![Bluetooth Control](https://img.shields.io/badge/Bluetooth-Control-4A90E2)
![License](https://img.shields.io/badge/License-MIT-green)

---

## 👨‍💻 Author
Abdul Rafeul Mallick



## ✨ Features

- Forward / Backward / Left / Right / Stop control  
- Speed control using PWM  
- WiFi web control interface  
- Bluetooth serial commands  
- Easy integration with Arduino IDE  

---

## 📦 Installation

1. Download ZIP from GitHub  
2. Open Arduino IDE  
3. Go to **Sketch → Include Library → Add .ZIP Library**  
4. Select the downloaded file  

---

## 🚀 Usage Example

```cpp
#include <ESPCar.h>

ESPCar car(5, 18, 19, 21);

void setup() {
  car.begin();
}

void loop() {
  car.forward();
}
