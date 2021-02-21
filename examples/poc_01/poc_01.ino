#include <pu2clr_pcf8574.h>

PCF pcf;

void setup()
{
    uint8_t i2cAddr;
    Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
    while (!Serial);    // Waiting for Serial Monitor
    // Looking for I2C Adress
    if ((i2cAddr = pcf.lookForDevice()) != 0)
    {
        Serial.print("\nI2C Buss Address: ");
        Serial.print(i2cAddr, HEX);
    }
    else
    {
        Serial.print("\nNo device found");
        while (true);
    }
    pcf.setup(i2cAddr); // Starts the device with the found I2C address
}

void loop()
{
    int i;
    Serial.print("\nAlternating all ports (High and Low)");
    for (i = 0; i < 3; i++)
    {
        pcf.write(0B11111111); // Turns all pins HIGH
        delay(3000);           // Time to mensure the device ports (pins)
        pcf.write(0B00000000);  // Turns all pins LOW
        delay(3000);           // Time to mensure the device ports (pins)
    }
    Serial.print("\nHandling port by port");
    for (i = 0; i < 8; i++)
    {
        pcf.digitalWrite(i, HIGH); // Turns the pin(i) HIGH
        delay(1000);               //
        pcf.digitalWrite(i, LOW);  // Turns the pin(i) LOW
        delay(1000);               //
    }
    Serial.print("\nTurns a random pin HIGH");
    pcf.digitalWrite((uint8_t)(millis() % 7), HIGH);
    for (i = 0; i < 8; i++)
    {
        if (pcf.digitalRead(i) == HIGH)
        {
            Serial.print("\nThe port ");
            Serial.print(i);
            Serial.print(" is HIGH: ");
            Serial.print(pcf.read(),BIN);
        }
    }
}
