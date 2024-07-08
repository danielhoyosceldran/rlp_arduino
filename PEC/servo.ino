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
    delay(200);
    setStatusLed(0);
  }
}

void updateShoulder(int deg) {
  if (deg >= 0 && deg <= 180) {
    setStatusLed(1);
    shoulder.write(deg);
    updateCurrentShoulderAngle(deg);
    delay(200);
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

void updateFinger(int a) {
  finger.write(a);
}


void fingerController(String action) {
  if (action == "UP") {
    updateFinger(90);
  }
  else if (action == "DOWN") {
    updateFinger(80);
  }
}

void moves(int row, int col) {
  int matrix[8][8][3] = {
    {{70, 90, 3}, {80, 90, 3}, {73, 90, 1}, {73, 90, 1}, {73, 90, 1}, {90, 90, 2}, {90, 90, 2}, {96, 88, 2}},
    {{70, 90, 2}, {70, 90, 2}, {73, 90, 1}, {73, 90, 1}, {73, 90, 1}, {90, 90, 2}, {90, 90, 2}, {96, 88, 2}},
    {{70, 90, 1}, {70, 90, 1}, {73, 90, 0}, {73, 90, 0}, {62, 120, 0}, {62, 120, 0}, {90, 88, 0}, {90, 88, 0}},
    {{80, 70, 0}, {80, 70, 0}, {80, 90, 0}, {144, 5, 2}, {62, 120, 0}, {62, 120, 0}, {45, 170, 2}, {45, 170, 2}},
    {{15, 167, 1}, {15, 167, 1}, {144, 5, 1}, {144, 5, 1}, {40, 160, 0}, {40, 160, 0}, {45, 170, 2}, {45, 170, 2}},
    {{16, 170, 0}, {16, 170, 0}, {144, 5, 0}, {144, 5, 0}, {40, 160, 0}, {40, 160, 0}, {160, 5, 0}, {160, 5, 0}},
    {{16, 170, 0}, {16, 170, 0}, {160, 0, 1}, {160, 0, 1}, {20, 180, 0}, {20, 180, 0}, {160, 5, 0}, {160, 5, 0}},
    {{138, 2, 0}, {138, 2, 0}, {160, 0, 1}, {160, 0, 1}, {20, 180, 0}, {20, 180, 0}, {35, 180, 0}, {35, 180, 0}}
  };
  /*
  Serial.print(row);Serial.print(", ");Serial.println(col);
  Serial.print(matrix[row][col][0]);Serial.print(", ");Serial.println(matrix[row][col][1]);
  */
  updateShoulder(180);
  updateElbow(0);
  delay(1500);
  updateFinger(matrix[row][col][2]);
  updateShoulder(matrix[row][col][0]);
  updateElbow(matrix[row][col][1]);
  delay(2800);
  updateShoulder(180);
  updateElbow(0);
}