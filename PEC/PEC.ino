int value;
int lastValue;
bool semaphore;

const int maxValues = 4;
int values[maxValues];
int currentValueIndex = 0;

void setup() {
  Serial.begin(9600);

  lastValue = -1;
  value = 0;
  semaphore = true;
  
  setToZero();
  pinMode(7, OUTPUT);

  // Inicializar la comunicación serial
  Serial.begin(9600);
  
  // Valores de prueba
  float x = 0.0;
  float y = 8.0;
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
  
}