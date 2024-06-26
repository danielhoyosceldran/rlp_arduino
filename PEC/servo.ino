#include <Adafruit_MotorShield.h>
#include <Servo.h>
Servo elbow, shoulder, finger;

#define FINGER 2
#define SHOULDER 9
#define ELBOW 10

int _currentElbowAngle;
int _currentShoulderAngle;

void setup_servos() {
  Serial.println("Setting up servos...");
  finger.attach(FINGER);
  shoulder.attach(SHOULDER);
  elbow.attach(ELBOW);
  delay(1000); // time to prepare servos
  Serial.println("Servos ready.");
}

void updateCurrentElbowAngle(int a) {
  _currentElbowAngle = a;
}

void updateCurrentShoulderAngle(int a) {
  _currentShoulderAngle = a;
}

int getElbowAngle() { 
  return _currentElbowAngle;
}

int getShoulderAngle() {
  return _currentShoulderAngle;
}

void setElbowToZero() {
  updateElbow(90);
}

void setShoulderToZero() {
  updateShoulder(90);
}

void setToZero(){
  setShoulderToZero();
  setElbowToZero();
}

void updateElbow(int deg) {
  if (deg >= 0 && deg <= 180) {
    setStatusLed(1);
    elbow.write(deg);
    updateCurrentElbowAngle(deg);
    delay(800);
    setStatusLed(0);
  }
}

void updateShoulder(int deg) {
  if (deg >= 0 && deg <= 180) {
    setStatusLed(1);
    shoulder.write(deg);
    updateCurrentShoulderAngle(deg);
    delay(800);
    setStatusLed(0);
  }
}

// good example position: 0, 23 (23 = minimum value for "y")
void moveTo(double x, double y) {
  Serial.print("Move to ("); Serial.print(x); Serial.print(", "); Serial.print(y); Serial.println(")");
  double alfa = 0, beta = 0;
  inverseKinematics(x, y, alfa, beta);
  // print results
  Serial.print("alfa: "); Serial.println(alfa);
  Serial.print("beta: "); Serial.println(beta);

  updateShoulder(alfa);
  updateElbow(beta);
}

void moveFinger(int direction) {
  setStatusLed(1);
  switch(direction) {
    case 0:
      finger.write(60);
    break;
    case 1:
      finger.write(5);
    break;
  }
  delay(800);
  setStatusLed(0);
}