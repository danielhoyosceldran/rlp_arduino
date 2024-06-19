// Parser
void parseStringToIntArray(String str, char delimiter, int* arr, int arrSize) {
  int currentIndex = 0;
  int previousIndex = 0;
  int arrIndex = 0;

  while (currentIndex < str.length() && arrIndex < arrSize) {
    currentIndex = str.indexOf(delimiter, previousIndex);
    if (currentIndex == -1) {
      currentIndex = str.length();
    }
    String part = str.substring(previousIndex, currentIndex);
    arr[arrIndex] = part.toInt();
    previousIndex = currentIndex + 1;
    arrIndex++;
  }
}

int* parseStringToArray(String input) {
  static int resultArray[4];  // Array estático para almacenar los resultados
  parseStringToIntArray(input, ',', resultArray, 4);
  return resultArray;
}

// Serial Reader
void readSerial() {
  // Check if there are values inside the buffer.
  if (Serial.available() > 0) {
    // Read numeric values till a non numeric value.
    int value = Serial.parseInt();

    // Clean the buffer of non numeric values
    while (Serial.available() > 0) {
      char c = Serial.read(); // read all extra values
      if (c == '\n' || c == '\r') {
        break; // exit when an "end of line" found.
      }
    }

    if (value != lastValue) {
      // usage of a new value
      Serial.print("Value: ");
      Serial.println(value);
      lastValue = value;
    }
  }
}

void readSerial_coordinates() {
  if (Serial.available() > 0) {
    // Lee la cadena completa hasta el salto de línea
    String input = Serial.readStringUntil('\n');
    
    // Inicializa las variables para el procesamiento
    int value = 0;
    bool newValue = false;

    // Recorre cada carácter de la cadena
    for (int i = 0; i < input.length() && currentValueIndex < maxValues; i++) {
      char c = input.charAt(i);

      // Si el carácter es un dígito, actualiza el valor actual
      if (isDigit(c)) {
        value = value * 10 + (c - '0');
        newValue = true;
      } else if (c == ',' && newValue) {
        // Si el carácter es una coma y hay un nuevo valor, guárdalo en el array
        values[currentValueIndex++] = value;
        value = 0;
        newValue = false;
      }
    }

    // Agrega el último valor si hay uno
    if (newValue && currentValueIndex < maxValues) {
      values[currentValueIndex++] = value;
    }

    // Imprime los valores obtenidos
    Serial.print("Values: ");
    for (int i = 0; i < currentValueIndex; i++) {
      Serial.print(values[i]);
      Serial.print(" ");
    }
    Serial.println();

    // Reinicia el índice para la próxima lectura
    currentValueIndex = 0;
  }
}
