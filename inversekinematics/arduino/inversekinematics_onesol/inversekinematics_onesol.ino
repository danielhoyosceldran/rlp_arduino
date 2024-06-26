#include <Math.h>

// Longitudes de los segmentos del brazo
const float L1 = 3.0;
const float L2 = 2.0;

// Función para calcular la cinemática inversa
void inverseKinematics(float x, float y, float &theta1, float &theta2) {
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

void setup() {
  // Inicializar la comunicación serial
  Serial.begin(9600);
  
  // Valores de prueba
  float x = 3.0;
  float y = 4.0;
  float theta1, theta2;
  
  // Calcular los ángulos
  inverseKinematics(x, y, theta1, theta2);
  
  // Imprimir los resultados
  Serial.print("θ1: ");
  Serial.print(theta1);
  Serial.println(" grados");
  
  Serial.print("θ2: ");
  Serial.print(theta2);
  Serial.println(" grados");
}

void loop() {
  // No se necesita código en el loop
}
