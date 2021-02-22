
#include <pu2clr_pcf8574.h>

PCF pcf;
void setup()
{
    Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
    while (!Serial);    // Waiting for Serial Monitor
    
    pcf.setup(0x20); 
    pcf.write(0B00000000); // Turns all pins/ports LOW
    Serial.print("Press a button or make one of the ports 4, 5, 6 or 7 HIGH (VCC)\n"); 

}

void loop()
{
  for (uint8_t i = 4; i < 8; i++ ) {
    if ( pcf.digitalRead(i) == HIGH) {
      Serial.print("\nThe port ");
      Serial.print(i);
      Serial.print(" is HIGH (button pressed)");
    }
  }
}
