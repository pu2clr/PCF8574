#include <pu2clr_pcf8574.h>

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
    uint8_t i;
    Serial.print("\nAlternating ports 0, 1, 2 and 3 (High and Low)");
    for (i = 0; i < 5; i++)
    {
        pcf.write(0B00001111); // Turns ports 0, 1, 2 and 3 HIGH
        delay(1000);           // Time to mensure the device ports (pins)
        pcf.write(0B00000000);  // Turns ports 0, 1, 2 and 3 LOW
        delay(1000);           // Time to mensure the device ports (pins)
    }
    Serial.print("\nHandling ports 0, 1, 2 and 3 one by one");
    for (i = 0; i < 4; i++)
    {
        pcf.digitalWrite(i, HIGH); // Turns the pin(i) HIGH
        delay(1000);               //
        pcf.digitalWrite(i, LOW);  // Turns the pin(i) LOW
        delay(1000);               //
    }
    pcf.write(0B00000000);  // Turns all pins LOW
    delay(5000);
}
