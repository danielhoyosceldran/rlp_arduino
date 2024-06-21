#include <Servo.h>

// Crear un objecte Servo
Servo s_espatlla;
Servo s_colze;

// Pin on està connectat el servo
const int espatlla = 9;
const int colze = 10;

void setup() {
  // Assignar el pin del servo
  s_espatlla.attach(espatlla);
  s_colze.attach(colze);

  // buzzer
  tone(11, 600, 200);

  // led
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  s_espatlla.write(90);
  s_colze.write(90);
  delay(3000);
  s_espatlla.write(0);
  //s_colze.write(180);
  delay(500);

  digitalWrite(8, LOW);
}

void loop() {
  

}
