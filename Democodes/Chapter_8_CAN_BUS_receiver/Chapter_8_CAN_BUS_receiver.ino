#include <Arduino_CAN.h>
  
void setup() {

  if (!CAN.begin(CanBitRate::BR_250k)) {
    Serial.println("CAN.begin(...) failed.");
    for (;;) {}
  }

  // init serial port
  Serial.begin(9600);
  while (!Serial) {
      ;  // wait for serial port to connect. Needed for native USB port only
    }
}

void loop() {
  if (CAN.available())
  {
    CanMsg const msg = CAN.read();
    // read data from sender part
    int raindropValue = (int) msg.data[0];
    int moistureValue = (int) msg.data[1];
   
    Serial.print("Received data: ");
    Serial.print("Rain drop sensor: ");
    Serial.print(raindropValue);
    Serial.print("\tSoil Moisture sensor: ");
    Serial.println(moistureValue);
    delay(1000);
  }
}

