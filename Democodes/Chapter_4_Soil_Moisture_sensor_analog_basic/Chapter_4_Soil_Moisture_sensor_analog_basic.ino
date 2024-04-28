// Define analog sensor pins
const int raindropSensorPin = A0;
const int soilMoistureSensorPin = A1;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Read analog sensor values
  int raindropValue = analogRead(raindropSensorPin);
  int soilMoistureValue = analogRead(soilMoistureSensorPin);
  
  // Print sensor values to serial monitor
  Serial.print("Raindrop Sensor Value: ");
  Serial.println(raindropValue);
  Serial.print("Soil Moisture Sensor Value: ");
  Serial.println(soilMoistureValue);
  
  // Add your logic based on sensor readings here
  // Example: if (raindropValue > threshold) { // Do something }
  
  delay(1000); // Delay for stability
}


