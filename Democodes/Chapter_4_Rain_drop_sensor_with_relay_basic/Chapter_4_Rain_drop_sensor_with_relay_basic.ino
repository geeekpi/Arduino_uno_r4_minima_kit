#define SIGNAL_PIN A5    // Define the output signal
#define RELAY_PIN 2     // Define the RELAY pin

int value = 0; // variable to store the sensor value
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);   // configure D2 pin as an OUTPUT
}

void loop() {
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  Serial.println(value);
  if(value > 800){        //If the value is greater than 800, we can consider it's dry
    Serial.println(" dry!!! ");    
    digitalWrite(RELAY_PIN, LOW);  // turn RELAY OFF
  }else {     //else, we can consider it's raining
    Serial.println(" raining!!! ");
    digitalWrite(RELAY_PIN, HIGH);  // turn RELAY ON
  }
  delay(1000);
}


