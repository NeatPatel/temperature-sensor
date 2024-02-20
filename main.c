const int thermistorPin = A0;
const int redLedPin = 2;
const int blueLedPin = 3;
const int greenLedPin = 4;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(thermistorPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog reading to voltage
  float resistance = (5.0 * 10000.0) / voltage - 10000.0; // Calculate resistance of the thermistor
  float temperature = 1.0 / (log(resistance / 10000.0) / 3950.0 + 1.0 / 298.15) - 273.15; // Calculate temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature >= 30) {
    digitalWrite(redLedPin, HIGH); // Red for hot
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  } else if (temperature <= 15) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, HIGH); // Blue for cold
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(greenLedPin, HIGH); // Green for medium
  }
  
  delay(1000); // Delay for readability
}
