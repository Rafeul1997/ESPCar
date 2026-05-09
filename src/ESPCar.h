#ifndef ESPCAR_H
#define ESPCAR_H

#include <Arduino.h>

class ESPCar {
  public:
    // Constructors
    ESPCar(); // For debug (no pins)
    ESPCar(int in1, int in2, int in3, int in4);
    ESPCar(int in1, int in2, int in3, int in4, int ena, int enb);

    void begin();

    // Movement
    void forward();
    void backward();
    void left();
    void right();
    void stop();

    // Speed
    void setSpeed(int speed);

    // WiFi
    void beginWiFi(const char* ssid, const char* password);
    String getWiFiRequest();
    void sendWiFiResponse();

  private:
    int _in1, _in2, _in3, _in4;
    int _ena, _enb;
    bool _usePWM = false;
    int _speed = 150;

    void move(int a, int b, int c, int d);
};

#endif
