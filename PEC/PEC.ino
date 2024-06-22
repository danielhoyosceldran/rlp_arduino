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
  float y = 40;
  float theta1 = 0, theta2 = 0;

  // Calcular los ángulos
  inverseKinematics_0(x, y, theta1, theta2);
  
  // Imprimir los resultados
  Serial.println("0: ")
  Serial.print("θ1: "); Serial.print(theta1);
  Serial.print("θ2: "); Serial.print(theta2);
  
  // Calcular los ángulos
  inverseKinematics_1(x, y, theta1, theta2);
  
  // Imprimir los resultados
  Serial.println("1: ")
  Serial.print("θ1: "); Serial.print(theta1);
  Serial.print("θ2: "); Serial.print(theta2);
}

void loop() {
  
}