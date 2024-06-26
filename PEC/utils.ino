// Parser
void parseMessage(String command, int* coordinates) {
  for (int i = 0; i < command.length(); i++) {
    char coordinateChar = command.charAt(i);
    int coordinate = coordinateChar - '0';
    coordinates[i] = coordinate;
  }
}

bool parseDoubles(String input, double &num1, double &num2) {
  int separatorIndex = input.indexOf(';');
  
  if (separatorIndex == -1) {
    return false;  // No hi ha separador ';'
  }

  String firstPart = input.substring(0, separatorIndex);
  String secondPart = input.substring(separatorIndex + 1);

  num1 = firstPart.toDouble();
  num2 = secondPart.toDouble();

  return true;
}

void commandParser(String command) {
  int coordinates[COMMAND_LENGHT];
  parseMessage(command, coordinates);
  moves(coordinates[0], coordinates[1]);
  moves(coordinates[2], coordinates[3]);
}

// Serial Reader
String readSerial() {
  String command = "";

  while (command.length() < 4) {
    while (Serial.available() > 0) {
      char inChar = (char)Serial.read();
      if (isDigit(inChar)) {
        command += inChar;
      }
      if (command.length() == 4) {
        break;
      }
    }
  }

  while (Serial.available() > 0) {
    Serial.read();
  }

  return command;
}

String readSerial2() {
  Serial.println("hola");
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Llegeix la cadena fins al final de línia
    Serial.println(input);
    double num1, num2;
    if (parseDoubles(input, num1, num2)) {
      Serial.print("Primer número: ");
      Serial.println(num1, 2);  // 2 decimals per mostrar
      Serial.print("Segon número: ");
      Serial.println(num2, 2);  // 2 decimals per mostrar
    } else {
      Serial.println("Error en la cadena d'entrada.");
    }
  }
}

// leds
void setStatusLed(int status) {
  switch(status) {
    case 0: digitalWrite(8, LOW);
    break;
    case 1: digitalWrite(8, HIGH);
    break;
    case 2: 
      digitalWrite(8, HIGH);
      delay(200);
      digitalWrite(8, LOW);
      delay(200);
      digitalWrite(8, HIGH);
      delay(200);
      digitalWrite(8, LOW);
    break;
  }
}

void choiceMove(char move, double a, double b) {
  if (move == "p") {
    moveTo(a, b);
  } else if (move == "a") {
    updateShoulder(14.47);
    updateElbow(44.77); 
  }
}