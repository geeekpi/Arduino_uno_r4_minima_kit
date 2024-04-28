const int raindropPin = A0; // Analog pin connected to the raindrop sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int raindropValue = analogRead(raindropPin); // Read analog value from the sensor
  Serial.print("Raindrop Value: ");
  Serial.println(raindropValue); // Print the value to the serial monitor
  delay(1000); // Delay for stability
}
