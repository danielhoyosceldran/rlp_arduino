#define COMMAND_LENGHT 4

void parseMessage(String command, int* coordinates) {
  for (int i = 0; i < command.length(); i++) {
    char coordinateChar = command.charAt(i);
    int coordinate = coordinateChar - '0';
    coordinates[i] = coordinate;
  }
}

void setup() {
  Serial.begin(9600);
  int coordinates[COMMAND_LENGHT];
  parseMessage("1234", coordinates);
  Serial.println(coordinates[1]);

}

void loop() {
  // put your main code here, to run repeatedly:

}
