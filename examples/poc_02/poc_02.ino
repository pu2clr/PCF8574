
/**
 * This sketch uses an LED connected to the +VCC via a 1K resistor. 
 * When the port 0 is HIGH, the LED turns OFF; When the port 0 is LOW, the LED turns ON. 
 */
#include <pu2clr_pcf8574.h>

#define LED_PIN 0

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
    pcf.write(0B11111110); // Sets all ports to HIGH. Except port 0.
    delay(5000);
    pcf.digitalWrite(LED_PIN,HIGH);
    delay(5000);

}

void loop()
{
  pcf.digitalWrite(LED_PIN,LOW); 
  delay(500);
  pcf.digitalWrite(LED_PIN,HIGH);
  delay(1000); 
}
