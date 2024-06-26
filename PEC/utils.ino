// Parser
void parseMessage(String command, int* coordinates) {
  for (int i = 0; i < command.length(); i++) {
    char coordinateChar = command.charAt(i);
    int coordinate = coordinateChar - '0';
    coordinates[i] = coordinate;
  }
}

void parseMessageDegrees(String command, double &alpha, double &beta) {
  for (int i = 0; i < command.length(); i++) {
    
  }
}

void logicalToRealCoordinates(int* coordinates, double* realCoordinates) {
/*  double equivalnces[8][8] = 
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [], 
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [],
    [], [], [], [], [], [], [], [];*/

    realCoordinates[0] = 23;
    realCoordinates[1] = 23;
    realCoordinates[2] = -23;
    realCoordinates[3] = 23;
}

void commandParser(String command, double* realCoordinates) {
  int coordinates[COMMAND_LENGHT];
  parseMessage(command, coordinates);

  logicalToRealCoordinates(coordinates, realCoordinates);
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