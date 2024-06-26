#define STATUS_LED 8
#define BUZZER 11

#define COMMAND_LENGHT 4

const int maxValues = 4;
int values[maxValues];
int currentValueIndex = 0;

void setup() {
  Serial.begin(9600);
  delay(100);

  //tone(BUZZER, 600, 200);
  //pinMode(STATUS_LED, OUTPUT);
  setup_servos();
  delay(500);
}

void loop() {
  String command = readSerial();
  commandParser(command);

  
  /*if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Llegeix la cadena fins al final de línia
    Serial.println(input);
    double num1, num2;
    if (parseDoubles(input, num1, num2)) {
      Serial.print("Primer número: ");
      Serial.println(num1, 2);  // 2 decimals per mostrar
      Serial.print("Segon número: ");
      Serial.println(num2, 2);  // 2 decimals per mostrar
      updateShoulder(num1);
      updateElbow(num2);
    } else {
      Serial.println("Error en la cadena d'entrada.");
    }
  }*/
}