#ifndef ESPCAR_H
#define ESPCAR_H

#include <Arduino.h>

class ESPCar {
  public:
    // Constructor
    ESPCar(int in1, int in2, int in3, int in4, int enA = -1, int enB = -1);

    // Initialization
    void begin();

    // Movement
    void forward();
    void backward();
    void left();
    void right();
    void stop();

    // Speed Control (0–255)
    void setSpeed(int speed);

  private:
    int _in1, _in2, _in3, _in4;
    int _enA, _enB;
    int _speed;
};

#endif
