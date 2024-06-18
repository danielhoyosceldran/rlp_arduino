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
}

void loop() {
  readSerial_coordinates();
}
