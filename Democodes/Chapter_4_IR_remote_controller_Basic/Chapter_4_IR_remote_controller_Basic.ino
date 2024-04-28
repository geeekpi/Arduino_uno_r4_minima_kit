#include <IRremote.h>
#define RELAY_PIN  2     // the Arduino pin, which connects to the IN pin of relay module
int RECV_PIN = 3;     //define input pin on Arduino

IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup()
{
pinMode(RELAY_PIN, OUTPUT);  // initialize digital pin as an output.
Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
}
void loop() {
if (irrecv.decode()) {
 if (irrecv.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
      // We have an unknown protocol here, print extended info
      irrecv.printIRResultRawFormatted(&Serial, true);
      irrecv.resume();  // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
    } else {
      irrecv.resume();  // Early enable receiving of the next IR frame
      irrecv.printIRResultShort(&Serial);
      irrecv.printIRSendUsage(&Serial);
    }
    Serial.println();
    Serial.println(irrecv.decodedIRData.command);
    if (irrecv.decodedIRData.command == 0x45) {  // 1 Change status
      toggleRelay();
      delay(300);
    }else if(irrecv.decodedIRData.command == 0x46){  // 2 turn on the relay
      digitalWrite(RELAY_PIN, HIGH);
    }else if(irrecv.decodedIRData.command == 0x47){   // 3 turn off the relay
      digitalWrite(RELAY_PIN, LOW);
    }
  }
}
void toggleRelay() {
  digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN)); // change the status 
}

