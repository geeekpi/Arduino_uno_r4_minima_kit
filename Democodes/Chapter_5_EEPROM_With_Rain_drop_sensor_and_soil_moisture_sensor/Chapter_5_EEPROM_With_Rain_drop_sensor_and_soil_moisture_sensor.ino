#include <Wire.h>
#include <EEPROM.h>

// Define EEPROM memory address
#define EEPROM_ADDRESS 0x50  // EEPROM I2C address

// Define analog sensor pins
const int raindropSensorPin = A0;
const int soilMoistureSensorPin = A1;

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    Wire.begin();        // Initialize I2C communication
}

void loop() {
    // Read analog sensor values
    int raindropValue = analogRead(raindropSensorPin);
    int soilMoistureValue = analogRead(soilMoistureSensorPin);

    // Write sensor readings to EEPROM
    writeEEPROM(raindropValue, soilMoistureValue);
    delay(1000);  // Delay for stability

    // Read sensor readings from EEPROM and print to serial monitor
    readEEPROM();
    delay(5000);  // Delay for stability
}

void writeEEPROM(int raindropValue, int soilMoistureValue) {
    // Write sensor readings to EEPROM
    Wire.beginTransmission(EEPROM_ADDRESS);  // Begin transmission to EEPROM
    Wire.write(0);                            // Set memory address pointer to 0
    Wire.write((byte)(raindropValue >> 8));   // Write high byte of raindropValue
    Wire.write((byte)(raindropValue & 0xFF)); // Write low byte of raindropValue
    Wire.write((byte)(soilMoistureValue >> 8));   // Write high byte of soilMoistureValue
    Wire.write((byte)(soilMoistureValue & 0xFF)); // Write low byte of soilMoistureValue
    Wire.endTransmission();                   // End transmission
}

void readEEPROM() {
    // Read sensor readings from EEPROM and print to serial monitor
    int raindropValue, soilMoistureValue;
    Wire.beginTransmission(EEPROM_ADDRESS);  // Begin transmission to EEPROM
    Wire.write(0);                            // Set memory address pointer to 0
    Wire.endTransmission();                   // End transmission

    Wire.requestFrom(EEPROM_ADDRESS, 4);      // Request four bytes from EEPROM
    if (Wire.available() >= 4) {
        raindropValue = (Wire.read() << 8) | Wire.read();  // Combine high and low bytes for raindropValue
        soilMoistureValue = (Wire.read() << 8) | Wire.read();  // Combine high and low bytes for soilMoistureValue
        Serial.print("Raindrop Sensor Value: ");
        Serial.println(raindropValue);
        Serial.print("Soil Moisture Sensor Value: ");
        Serial.println(soilMoistureValue);
    }
}

