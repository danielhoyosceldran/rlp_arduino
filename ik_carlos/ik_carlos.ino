#include <Servo.h>
#include <math.h>

double largo1 = 20;
double largo2 = 20;
double angulo1,angulo2;
double Pi = 3.14159;


// Funcion LeyDelCoseno
// esta función trigonometrica implementa la ley del coseno (trigonometria)
// entradas:
// A: angulo del primer lado
// B: angulo del segundo lado
// C: angulo del lado que está al frente del ángulo
// retorna: angulo que está al frente del lado C
double cos(double A, double B, double C)
{
  double div = (A*A + B*B - C*C) / (2*A*B);
  if (div < -1.0)
    div = -1.0;
  if(div > 1.0)
    div = 1.0;
 
  return acos(div);
 
}

// Funcion Distancia
// Calcula la distancia de un punto al origen (eje del robot) con el teorema de Pitagoras
// x: distancia en el eje x
// y: distancia en el eje y
double distance(double x, double y)
{
  return sqrt(x*x + y*y);
}

// esta funcion convierte angulos en radianes a grados
double radiansToDegrees(double radianes)
{
  return radianes * 180.0 / Pi;
}

// Funcion angulosMotores
// Esta funcion calcula lso valores de los motores (a1, a2) para mover el brazo a la posición x,y
// x: posicion objetivo (eje x)
// y: posición objetivo (eje y)
// a1: valor donde se guardara el resultado del angulo 1. Angulo en grados
// a2: valor donde se guardara el resultado del angulo 2. Angulo en grados
void angulosMotores(double x, double y, double& a1, double& a2)
{
  double dist = distance(x, y);
  // Si estem fora del rang d'acció, el braç ens dona l'esquena.
  if (dist < 29 && dist > 40) {
    a1 = 0;
    a2 = 90;
    return;
  } 
  Serial.print("dist: ");
  Serial.println(dist);
  double D1 = atan2(y, x);
  Serial.print("D1: ");
  Serial.println(D1);
  double D2 = cos(dist, largo1, largo2);
  Serial.print("D2: ");
  Serial.println(D2);
  double a1Radianes = D1 + D2;
  Serial.print("a1Radianes: ");
  Serial.println(a1Radianes);
  double a2Radianes = cos(largo1, largo2, dist);
  Serial.print("a2Radianes: ");
  Serial.println(a2Radianes);
 
  // ahora guardamos los valores en grados en a1 y a2
  a1 = radiansToDegrees(a1Radianes);
  a2 = radiansToDegrees(a2Radianes);
}



// codigo de arduino
void setup()
{
  Serial.begin(9600);
  // configurar todo lo necesario para mover motores servo
}

void loop()
{
  // hacer todo lo necesario
 
  // EJEMPLO:
  
  double X = -25;
  double Y = 25;
  double angulo1 = 0;
  double angulo2 = 0;
  angulosMotores(X,Y, angulo1, angulo2);
 
  // ahora angulo1 y angulo2 ya no valen 0, sino los valores para mover el brazo a la posición X=15, Y=10
  // podemos comprobarlo con Serial.print
  Serial.print("Angulo1: ");
  Serial.print(180-angulo1);
  Serial.print(",  Angulo2: ");
  Serial.println(180-angulo2);
 
}
