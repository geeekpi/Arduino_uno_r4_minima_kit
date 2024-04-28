#include <SD.h>

// Define chip select pin for the TF card reader module
const int chipSelectPin = 10;

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
    // Record data to TF card
    File dataFile = SD.open("data.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.println("Hello, TF card!");  // Write data to TF card
        dataFile.close();  // Close the file
        Serial.println("Data recorded to TF card.");
    } else {
        Serial.println("Error opening data.txt");
    }
    delay(1000);  // Delay for stability

    // Read data from TF card
    dataFile = SD.open("data.txt");
    if (dataFile) {
        Serial.println("Reading data.txt:");
        while (dataFile.available()) {
            Serial.write(dataFile.read());  // Read data from TF card and print to serial monitor
        }
        dataFile.close();  // Close the file
    } else {
        Serial.println("Error opening data.txt");
    }
    delay(5000);  // Delay for stability
}
