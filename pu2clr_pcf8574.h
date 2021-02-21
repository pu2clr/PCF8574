/**
 * @mainpage PCF8574 Arduino Library implementation 
 * @details This library was built based on the Datasheet "PCF8574 8-Bit I/O Expander with Serial Interface" from Microchip
 * @details The PCF8574 device provides 8-bit, general purpose, parallel I/O expansion. It can be controlled via I²C bus applications. It is a great and inexpensive device that allow you to add more peripherals to be controlled by your Arduino board via I²C protocol.
 * @details Some Arduino projects may require more pins than the Arduino actually has. In these cases, you can use up to 8 PCF8574 devices using only the I²C bus (two Arduino pins) and add up to 64 input / output ports to your project. 
 * @details This library can be freely distributed using the MIT Free Software model.
 * @details This library uses the I²C communication protocol and implements most important functions offered by PCF8574 device from MicroChip. It also has primitive functions that make it easier to implement commands that may not have been implemented yet. The main features implemented can be seen below:
 * @details 1) GPIO individual control (8 I/O pins)
 * @details 2) I²C address customization 
 * @author Ricardo LIma Caratti (pu2clr@gmail.com)
 * @brief It is a Library to control the PCF8574 device.
 * @date 2021-01-20
 * @copyright Copyright (c) 2021 Ricardo Lima Caratti
 */

#include <Arduino.h>

#define DEFAULT_I2C_ADDRESS 0x20 // Default I2C Address

#define PCF_GPIO0 0
#define PCF_GPIO1 1
#define PCF_GPIO2 2
#define PCF_GPIO3 3
#define PCF_GPIO4 4
#define PCF_GPIO5 5
#define PCF_GPIO6 6
#define PCF_GPIO7 7

#define CHECK_BIT_HIGH(x, y) (x & (1 << y)) //!< Check if a bit is high. Returns 0 or != 0

class PCF
{
protected:
   uint8_t i2c_address = DEFAULT_I2C_ADDRESS; //!< Default i2c address
   int reset_pin = -1;                        //!< Digital Arduino pin to control the PCF8574 RESET
   bool io_error = false;

public:
   uint8_t lookForDevice();
   void reset();
   void setup(uint8_t i2c = DEFAULT_I2C_ADDRESS);
   void write(uint8_t value);
   uint8_t read();
   uint8_t digitalRead(uint8_t port);
   void digitalWrite(uint8_t port, uint8_t value);
};
