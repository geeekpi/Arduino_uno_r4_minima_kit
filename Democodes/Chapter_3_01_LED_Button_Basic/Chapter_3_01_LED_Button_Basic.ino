const int buttonPin = 7; // Pin connected to the pushbutton
const int ledPin = 2;   // Pin connected to the LED

int buttonState = 0;     // Variable for storing the button's state

void setup() {
  pinMode(ledPin, OUTPUT);    // Set the LED pin as an output
  pinMode(buttonPin, INPUT);  // Set the button pin as an input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button

  if (buttonState == HIGH) { // If button is pressed
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }
}

