#include <AFMotor.h>
#include <Servo.h>
Servo elbow, shoulder;

int _currentElbowAngle;
int _currentShoulderAngle;

void updateCurrentElbowAngle(int a) {
  _currentElbowAngle = a;
}

void updateCurrentShoulderAngle(int a) {
  _currentShoulderAngle = a;
}

int getElbowAngle() { return _currentElbowAngle; }
int getShoulderAngle() { return _currentShoulderAngle; }

void setToZero(){
  elbow.write(0);
  shoulder.write(0);

  updateCurrentElbowAngle(0);
  updateCurrentShoulderAngle(0);
}

void setElbowToZero() {
  elbow.write(0);
  updateCurrentElbowAngle(0);
}

void setShoulderToZero() {
  shoulder.write(0);
  updateCurrentShoulderAngle(0);
}

/*
void incElbow(int deg) {
  if (deg >= 0 && deg <= 180) {
    elbow.write(_currentElbowAngle + deg);
    updateCurrentElbowAngle(deg);
  }
}
 */

void updateElbow(int deg) {
  if (deg >= 0 && deg <= 180) {
    elbow.write(deg);
    updateCurrentElbowAngle(deg);
  }
}

void updateShoulder(int deg) {
  if (deg >= 0 && deg <= 180) {
    shoulder.write(deg);
    updateCurrentShoulderAngle(deg);
  }
}
