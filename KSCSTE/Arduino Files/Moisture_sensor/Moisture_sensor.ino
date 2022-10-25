int sensorPin = A0;    
int sensorValue = 0;  

int digitalPin = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  Serial.print("Analog: "); Serial.print(sensorValue);
}
