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


void moves(int row, int col) {
  int matrix[8][8][3] = {
    {{82, 90, 16}, {84, 94, 10}, {90, 88, 10}, {85, 100, 9}, {90, 103, 9}, {96, 90, 10}, {100, 100, 10}, {112, 90, 16}},
    {{82, 90, 16}, {84, 94, 10}, {84, 94, 10}, {84, 94, 10}, {84, 94, 10}, {84, 94, 10}, {84, 94, 10}, {116, 90, 8}},
    {{70, 115, 8}, {70, 115, 8}, {60, 144, 0}, {60, 144, 0}, {80, 120, 0}, {80, 120, 0}, {83, 130, 0}, {83, 130, 0}},
    {{70, 115, 8}, {70, 115, 8}, {50, 154, 0}, {60, 148, 0}, {80, 120, 0}, {80, 120, 0}, {83, 130, 0}, {83, 130, 0}},
    {{31, 170, 11}, {31, 170, 11}, {50, 154, 0}, {60, 148, 0}, {60, 148, 0}, {70, 148, 0}, {70, 160, 0}, {70, 160, 0}},
    {{30, 173, 0}, {30, 173, 0}, {30, 180, 0}, {40, 180, 0}, {40, 180, 0}, {70, 148, 0}, {70, 160, 0}, {70, 160, 0}},
    {{15, 180, 0}, {20, 180, 0}, {20, 180, 0}, {40, 180, 0}, {40, 180, 0}, {52, 178, 0}, {1, 172,  10}, {1, 172,  10}},
    {{15, 180, 0}, {20, 180, 0}, {20, 180, 0}, {20, 180, 0}, {20, 180, 0}, {20, 180, 0}, {1, 172,  10}, {1, 172,  10}}
  };
  updateShoulder(180);
  updateElbow(0);
  delay(1500);
  updateFinger(matrix[row][col][2]);
  updateShoulder(matrix[row][col][0]);
  updateElbow(matrix[row][col][1]);
  delay(2800);
}