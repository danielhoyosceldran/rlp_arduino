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
  if (Serial.available() > 0) {
    String command = Serial.readString();
    Serial.println(command);
    if (command == "hola") {
      setStatusLed(1);
      delay(1000);
      setStatusLed(0);
    }
  }
}