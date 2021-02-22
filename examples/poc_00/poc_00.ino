/**
 *  This sketch checks if the status of the ports 4, 5, 6 or  7 is LOW (button pressed)  
 *  Use the serial monitor to check the results.
 *   
 *  Circuit Arduino and PCF8574 setup
 *  
 *  | Device   | PCF8574  | Description                               |
 *  | -------- | -------- | ----------------------------------------- |
 *  | Arduino  |          |                                           |
 *  |    A5    | SCL (14) | I2C Clock                                 |
 *  |    A4    | SDA (15) | I2C Data                                  |
 *  | -------- |          |                                           |
 *  | Buttons  |          |                                           |
 *  |   B0     |  PORT 4  | Button connected to the GND               |
 *  |   B1     |  PORT 5  | Button connected to the GND               |
 *  |   B2     |  PORT 6  | Button connected to the GND               |
 *  |   B3     |  PORT 7  | Button connected to the GND               |

 *  
 *  Author: Ricardo LIma Caratti, 2021.
 */
#include <pu2clr_pcf8574.h>

PCF pcf;
void setup()
{
    Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
    while (!Serial);    // Waiting for Serial Monitor
    
    pcf.setup(0x20);    // The PCF8574 is configured to 0x20 I2C address. Check A0, A1 and A2 pins of the device.
    pcf.write(0B11111111); // Turns all pins/ports HIGH
    Serial.print("Press a button or make one of the ports 4, 5, 6 or 7 LOW (GND)\n"); 

}

void loop()
{
  for (uint8_t i = 4; i < 8; i++ ) {
    if ( pcf.digitalRead(i) == LOW) {
      Serial.print("\nThe port ");
      Serial.print(i);
      Serial.print(" is LOW (button pressed)");
    }
  }
}
