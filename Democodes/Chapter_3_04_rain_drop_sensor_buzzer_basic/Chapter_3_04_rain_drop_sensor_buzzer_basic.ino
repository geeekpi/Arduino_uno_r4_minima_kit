#define SIGNAL_PIN 7     // Define the output signal
int buzzer = 8;         
int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);   // configure D7 pin as an OUTPUT
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  value = digitalRead(SIGNAL_PIN);    // read the analog value from sensor
  Serial.print("Digital Output: ");   // Print output to the serial port
  Serial.println(value);

  if(value == 1){                   // The high level is dry
  Serial.println("dry");
  digitalWrite(buzzer, LOW);
  }
  else{      // The low level is wet
  Serial.println("raining!!");
  digitalWrite(buzzer, HIGH); //Make a sound
  }
  delay(1000);
}

