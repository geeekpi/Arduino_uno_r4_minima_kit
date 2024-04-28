#include <Arduino_CAN.h>

 
static uint32_t const CAN_ID = 0x20;

const int raindropPin = A0;   // Analog pin for raindrop sensor
const int moisturePin = A1;   // Analog pin for soil moisture sensor

int raindropValue = 0;        // Variable for storing raindrop sensor value
int moistureValue = 0;        // Variable for storing soil moisture sensor value

void setup() {
   
  Serial.begin(115200);
  while (!Serial) {} 
  
  // Initialize CAN bus
   if (!CAN.begin(CanBitRate::BR_250k))
  {
    Serial.println("CAN.begin(...) failed.");
    for (;;) {}
  }
}


void loop()
{
  raindropValue = analogRead(raindropPin); // Read raindrop sensor value 
  moistureValue = analogRead(moisturePin); // Read soil moisture sensor value

  Serial.print("raindrop value: ");
  Serial.print(int(raindropValue));
  Serial.print("\tMoisture value: ");
  Serial.println(int(moistureValue));
     
  uint8_t const msg_data[] = {raindropValue, moistureValue, 0,0,0,0,0,0,0,0}; // create a 4 bytes data
  CanMsg const msg(CanStandardId(CAN_ID), sizeof(msg_data), msg_data); 

  /* Transmit the CAN message, capture and display an
   * error core in case of failure.
   */
  if (int const rc = CAN.write(msg); rc < 0)
  {
    Serial.print  ("CAN.write(...) failed with error code ");
    Serial.println(rc);
    for (;;) { }
  }
  /* Only send one message per second. */
  delay(1000);
}

