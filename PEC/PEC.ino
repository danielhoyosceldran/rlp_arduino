#define STATUS_LED 8
#define BUZZER 11

#define COMMAND_LENGHT 4

const int maxValues = 4;
int values[maxValues];
int currentValueIndex = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
/*
  tone(BUZZER, 600, 200);
  pinMode(STATUS_LED, OUTPUT);

  setup_servos();
  setToZero();
  moveFinger(0);
  delay(1000);
  moveTo(23, 0);*/
  
  setup_servos();
  delay(500);
  double a1 = 98;
  double a2 = 37;
  updateShoulder(a1);
  updateElbow(a2);
  double x = 0;
  double y = 0;
  kinematics(a1, a2, x, y);
  Serial.println("");
  Serial.print("a1: "); Serial.println(a1);
  Serial.print("a2: "); Serial.println(a2);
  Serial.print("x: "); Serial.println(x);
  Serial.print("y: "); Serial.println(y);

  a1 = 0;
  a2 = 0;

  inverseKinematics(0, 0, a1, a2);
  Serial.println("inverse:");
  Serial.print("a1: "); Serial.println(a1);
  Serial.print("a2: "); Serial.println(a2);

}

void loop() {
  /*String command = readSerial();
  double realCoordinates[COMMAND_LENGHT];
  commandParser(command, realCoordinates);
  
  // NO ES PODEN CARREGAR LES COORDENADES, PER ALGUN MOTIU
  delay(1000);
  moveTo(realCoordinates[0], realCoordinates[1]);
  delay(1000);
  moveTo(realCoordinates[2], realCoordinates[3]);*/


}