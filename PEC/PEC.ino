#define STATUS_LED 8
#define BUZZER 11

int value;
int lastValue;
bool semaphore;

const int maxValues = 4;
int values[maxValues];
int currentValueIndex = 0;

void setup() {
  tone(BUZZER, 600, 200);
  pinMode(STATUS_LED, OUTPUT);

  lastValue = -1;
  value = 0;
  semaphore = true;

  Serial.begin(9600);
  delay(1000);

  setup_servos();
  setToZero();
}

void loop() {
  String command = readSerial();
  setStatusLed(2);
  int* logicalCoordinates = parseMessage(command);
  int* realCoordinates = logicalToRealCoordinates(logicalCoordinates);
  // NO ES PODEN CARREGAR LES COORDENADES, PER ALGUN MOTIU
  delay(1000);
  moveTo(23, 23);
}