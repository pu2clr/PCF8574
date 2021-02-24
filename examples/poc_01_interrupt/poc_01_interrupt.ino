/**
 * This sketch controls two LEDs (ports 0 and 1)  and 4 buttons (ports 4 ,5, 6 and 7)
 * The LEDs are connected to the +VCC via 1K resistor and the ports 0 and 1 of the device.  
 * 
 * The PCF8574 INT pin is connected to the Arduino Nano pin 2 (with support to interrupt). 
 * When any port chanes their status (from LOW to HIGH or HIGH to LOW), an interrupt is fired. 
 * 
 * When you press a button the LEDS will blinks in different ways.
 * 
 * 
 *   Circuit Arduino and PCF8574 setup
 *
 *  | Device   | PCF8574  | Description                               |
 *  | -------- | -------- | ----------------------------------------- |
 *  | Arduino  |          |                                           |
 *  |    A5    | SCL (14) | I2C Clock                                 |
 *  |    A4    | SDA (15) | I2C Data                                  |
 *  |    D2    | INT (13) | Arduino Interrupt pin                     |
 *  | -------- |          |                                           |
 *  | Buttons  |          |                                           |
 *  |   B0     |  PORT 4  | Button connected to the GND               |
 *  |   B1     |  PORT 5  | Button connected to the GND               |
 *  |   B2     |  PORT 6  | Button connected to the GND               |
 *  |   B3     |  PORT 7  | Button connected to the GND               |
 *  | -------- |          |                                           |
 *  | L E D s  |          |                                           |
 *  |  LED 0   |  PORT 0  | LED eonnected to the +VCC via 1K resistor |
 *  |  LED 1   |  PORT 1  | LED eonnected to the +VCC via 1K resistor |
 * 
 */

#include <pu2clr_pcf8574.h>

#define ARDUINO_INTERRUPT_PIN 2

volatile int interrupt_count = 0;
volatile bool pcf_event =  false;

PCF pcf;

void setup()
{
    Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
    while (!Serial);    // Waiting for Serial Monitor
    pcf.setup(); // The defaul I2C address is 0x20. Check your PCF8574 device A0, A1 and A2 pins
    pcf.write(0B11111111); // Turns all PCF8574 ports HIGH   

    pinMode(ARDUINO_INTERRUPT_PIN, INPUT_PULLUP); // Set Arduino internal pull up resistor to ARDUINO_INTERRUPT_PIN
    attachInterrupt(digitalPinToInterrupt(ARDUINO_INTERRUPT_PIN), checkInterrupt, FALLING); // Will call checkInterrupt when PCF8574 INT pin is LOW

    Serial.print("\nStarting. \nPress the buttons (P04~P07) and check the LEDs blinking time\n");
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

void blinkLED(int delay_value) {
  for ( int i = 0; i < 2; i ++ ) {
    pcf.digitalWrite(0,LOW);
    delay(delay_value / 2);
    pcf.digitalWrite(0,HIGH);
    delay(delay_value);
    pcf.digitalWrite(1,LOW);
    delay(delay_value / 2);
    pcf.digitalWrite(1,HIGH);   
    delay(delay_value); 
  }
        
}

void loop()
{
  if ( pcf_event ) {
    // Checks what port is LOW
    for ( uint8_t i = 4; i < 8; i++) {
      if ( pcf.digitalRead(i) == LOW ) {
         Serial.print("\nThe button pressed was: ");
         Serial.print(i);
         blinkLED(i * i * i * i); // calculates  different times to each button 
      }
    }
    pcf.write(0B11111111); // Turns all ports HIGH
    pcf_event = false; // Cleans the interrupt status
  }  

}
