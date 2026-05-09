#include "ESPCar.h"

// Constructor
ESPCar::ESPCar(int in1, int in2, int in3, int in4, int enA, int enB) {
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _enA = enA;
  _enB = enB;
  _speed = 255;
}

// Initialize pins
void ESPCar::begin() {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);

  if (_enA != -1) pinMode(_enA, OUTPUT);
  if (_enB != -1) pinMode(_enB, OUTPUT);
}

// Forward
void ESPCar::forward() {
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);

  setSpeed(_speed);
}

// Backward
void ESPCar::backward() {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);

  setSpeed(_speed);
}

// Left
void ESPCar::left() {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);

  setSpeed(_speed);
}

// Right
void ESPCar::right() {
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);

  setSpeed(_speed);
}

// Stop
void ESPCar::stop() {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}

// Speed control
void ESPCar::setSpeed(int speed) {
  _speed = constrain(speed, 0, 255);

  if (_enA != -1) analogWrite(_enA, _speed);
  if (_enB != -1) analogWrite(_enB, _speed);
}
