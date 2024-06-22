#include <Math.h>

// Longitudes de los segmentos del brazo
const float L1 = 15.0;
const float L2 = 26.0;

// Función para calcular la cinemática inversa
void inverseKinematics_0(float x, float y, float &theta1, float &theta2) {
  // Calcular d
  float d = (x * x + y * y - L1 * L1 - L2 * L2) / (2 * L1 * L2);
  
  // Verificar si d está dentro del rango válido (-1 <= d <= 1)
  if (d < -1.0 || d > 1.0) {
    Serial.println("La posición (x, y) no es alcanzable con las longitudes dadas.");
    return;
  }

  // Calcular θ2 usando arctan2 para tener en cuenta los cuadrantes correctos
  theta2 = atan2(sqrt(1 - d * d), d);  // Solución "codo arriba"
  
  // Calcular k1 y k2
  float k1 = L1 + L2 * cos(theta2);
  float k2 = L2 * sin(theta2);
  
  // Calcular θ1 usando arctan2 para tener en cuenta los cuadrantes correctos
  theta1 = atan2(y, x) - atan2(k2, k1);
  
  // Convertir los ángulos a grados para mejor interpretación
  theta1 = theta1 * 180.0 / PI;
  theta2 = theta2 * 180.0 / PI;
}

double largo1 = 15;
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
double distance(double x, double y) {
  return sqrt(x*x + y*y);
}


double radiansToDegrees(double radianes)
{
  return radianes * 180.0 / Pi;
}

// x i y, posicions; a1 i a2, angles (els passem com a 0)
void inverseKinematics_1(double x, double y, double& a1, double& a2)
{
  double dist = distance(x, y);
  // Si estem fora del rang d'acció, el braç ens dona l'esquena.
  if (dist < 20 && dist > 40) {
    a1 = 0;
    a2 = 90;
    return;
  }

  Serial.print("dist: "); Serial.println(dist);
  double D1 = atan2(y, x);
  Serial.print("D1: "); Serial.println(D1);
  double D2 = cos(dist, largo1, largo2);
  Serial.print("D2: "); Serial.println(D2);
  double a1Radianes = D1 + D2;
  Serial.print("a1Radianes: "); Serial.println(a1Radianes);
  double a2Radianes = cos(largo1, largo2, dist);
  Serial.print("a2Radianes: "); Serial.println(a2Radianes);
 
  a1 = radiansToDegrees(a1Radianes);
  a2 = radiansToDegrees(a2Radianes);
}