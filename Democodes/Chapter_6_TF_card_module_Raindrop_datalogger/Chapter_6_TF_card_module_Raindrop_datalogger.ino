#include <SD.h>

// Define chip select pin for the TF card reader module
const int chipSelectPin = 10;
const int raindropSensorPin = A0;

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    pinMode(chipSelectPin, OUTPUT);  // Set chip select pin as output
    
    // Initialize TF card
    if (!SD.begin(chipSelectPin)) {
        Serial.println("TF card initialization failed!");
        return;
    }
    Serial.println("TF card initialized.");
}

void loop() {
    // Read data from raindrop sensor
    int raindropValue = analogRead(raindropSensorPin);

    // Record data to TF card
    File dataFile = SD.open("newdata.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.print(millis());  // Record current time
        dataFile.print(", ");
        dataFile.println(raindropValue);  // Record raindrop sensor value
        dataFile.close();  // Close the file
        Serial.println("Data recorded to TF card.");
    } else {
        Serial.println("Error opening newdata.txt");
    }
    delay(5000);  // Delay for stability
}
