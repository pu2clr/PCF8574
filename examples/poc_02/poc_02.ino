
/**
 * This sketch uses two LEDs connected to the +VCC via a 1K resistor. 
 * When the ports the the LEDs are  HIGH, the LED turns OFF; When the ports are LOW, the LED turns ON. 
 * This sketch detects the I2C bus address automatically. See the Serial Monitor to check that.
 * 
 *   Circuit Arduino and PCF8574 setup
 *
 *  | Device   | PCF8574  | Description                               |
 *  | -------- | -------- | ----------------------------------------- |
 *  | Arduino  |          |                                           |
 *  |    A5    | SCL (14) | I2C Clock                                 |
 *  |    A4    | SDA (15) | I2C Data                                  |
 *  | -------- |          |                                           |
 *  | L E D s  |          |                                           |
 *  |  LED 0   |  PORT 0  | LED eonnected to the +VCC via 1K resistor |
 *  |  LED 1   |  PORT 1  | LED eonnected to the +VCC via 1K resistor |
 * 
 * 
 *  Author: Ricardo LIma Caratti, 2021
 * 
 */
#include <pu2clr_pcf8574.h>

#define LED1 0
#define LED2 1

PCF pcf;

void setup()
{
    uint8_t i2cAddr = 0x20;
    Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
    while (!Serial);    // Waiting for Serial Monitor
    Serial.print("\nStarting\n");
    // Looking for I2C Adress
    if ((i2cAddr = pcf.lookForDevice()) != 0)
    {
        Serial.print("\nI2C Buss Address: ");
        Serial.print(i2cAddr, HEX);
    }
    else
    {
        Serial.print("\nNo device found");
        Serial.flush();
        while (true);
    }
    
    pcf.setup(i2cAddr); // Starts the device with the found I2C address


}

void loop()
{
  // Turns the LEDS ON
  pcf.digitalWrite(LED1,LOW);
  delay(250);
  pcf.digitalWrite(LED2,LOW);
  
  delay(500);
  // Turns the LEDs OFF
  pcf.digitalWrite(LED1,HIGH);
  delay(250);
  pcf.digitalWrite(LED2,HIGH);
  
  delay(1000); 
}
