// Parser
#define COMMAND_LENGHT 4
int* parseMessage(String command) {
  int coordinates[COMMAND_LENGHT];
  for (int i = 0; i < command.length(); i++) {
    char coordinateChar = command.charAt(i);
    int coordinate = coordinateChar - '0';
    coordinates[i] = coordinate;
  }
  return coordinates;
}

int logicalToRealCoordinates(int* logicalCoordinates) {
  int realCoordinates[COMMAND_LENGHT];
  for (int i = 0; i < COMMAND_LENGHT; i++) {
    realCoordinates[i] = 23;
  }
  return realCoordinates;
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