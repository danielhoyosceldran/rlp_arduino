#include <Servo.h>

// Crear un objecte Servo
Servo s_espatlla;
Servo s_colze;
Servo s_dit;

// Pin on està connectat el servo
const int dit = 2;
const int espatlla = 9;
const int colze = 10;

void setup() {
  Serial.begin(9600);
  // Assignar el pin del servo
  s_espatlla.attach(espatlla);
  s_colze.attach(colze);
  s_dit.attach(dit);


  // buzzer
  tone(11, 600, 200);

  // led
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  s_dit.write(5);
  s_espatlla.write(90);
  s_colze.write(180);
  delay(500);

  digitalWrite(8, LOW);
}

void loop() {
  int x = Serial.parseInt();
  int y = Serial.parseInt();
  

}
