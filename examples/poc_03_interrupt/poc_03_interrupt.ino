
/**
 * This sketch uses an LED connected to the +VCC via a 1K resistor and the PFC8574 port 0. 
 * When the port 0 is HIGH, the LED turns OFF; When the port 0 is LOW, the LED turns ON. Also an interrupt will be fied.
 * When any port goes to LOW (via a button for example), an interrupt will be fired and a message will appear on Serial MOnitor (console)
 * 
 * Author: Ricardo Lima Caratti.
 * 
 */
#include <pu2clr_pcf8574.h>

#define LED_PIN 0
#define ARDUINO_INTERRUPT_PIN 2

volatile int interrupt_count = 0;
volatile bool pcf_event =  false;

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

    pcf.setup(i2cAddr);

    pcf.digitalWrite(0,LOW); // Turns the LED ON - LED connect to +VCC via 1k resistor 
    delay(3000);
    pcf.digitalWrite(0,HIGH); // Turns the LED ON
  
    pinMode(ARDUINO_INTERRUPT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ARDUINO_INTERRUPT_PIN), checkInterrupt, FALLING);    

    pcf.write(0B11111111); // Turns all port HIGH

}

/**
   Proccess the PCF8574 event
   This function is called when any port of the PCF8574 is changed from HIGH to LOW and LOW to HIGH.
   The PCF8574 INT pin goes to LOW when any port status is changed. 
*/
void checkInterrupt()
{
  pcf_event = true;
  interrupt_count++;
}


void loop()
{
  if ( pcf_event ) {
    Serial.print("\nInterrupr: ");
    Serial.print(interrupt_count);
    // Checks what port is LOW
    for ( uint8_t i = 0; i < 8; i++) {
      uint8_t port;
      port = pcf.digitalRead(i);
      if ( port == LOW ) {
        Serial.print(" - the port LOW is ");
        Serial.println(i);
        break;
      }
    }
    pcf_event = false; // Cleans the interrupt status
  }
}
