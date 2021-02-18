
/**
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
 * @copyright Copyright (c) 2021 Ricardo Lima CarattiRicardo Lima Caratti
 */

#include "pu2clr_PCF8574.h"

#include <Wire.h>

/** @defgroup group01 PCF8574 functions */

/**
 * @ingroup group01
 * @brief Look for PCF8574 device I2C Address
 * @details This method will look for a valid PCF8574 device adress between 0x20 and 0x27 
 * @return uint8_t the I2C address of the first PCF8574 device connect in the I2C bus
 */
uint8_t PCF::lookForDevice()
{
    int err = 0;
    Wire.begin();
    for (int addr = 0x20; addr <= 0x27; addr++)
    {
        Wire.beginTransmission(addr);
        err = Wire.endTransmission();
        if (err == 0)
            return addr;
    }
    // Any PCF8574 device was found
    return 0;
}

/**
 * @ingroup group01
 * @brief Starts the PCF8574 
 * @details Starts the PCF8574 and sets the default values. 
 * @param i2c I2C address 
 * @param reset_pin if you want to control the reset, select an Arduino pin to do that.  
 */
void PCF::setup(uint8_t i2c)
{
    Wire.begin(); //creates a Wire object
    this->i2c_address = i2c;
}

/**
 * @ingroup group01
 * @brief Gets the corrent register information. 
 * @details Gets the current register content. 
 * @return uint8_t current gpio value
 */
uint8_t PCF::read()
{
    this->io_error = false;
    Wire.requestFrom((int) this->i2c_address, 1);
    if (!Wire.available()) this->io_error =  true;
    return Wire.read();
}

/**
 * @ingroup group01
 * @brief Sets a value to a given register
 * @details Sets a given 8 bit value to a given register.  
 * @param value value (8 bits)
 */
void PCF::write(uint8_t value)
{
    int error;
    this->io_error = false;
    Wire.beginTransmission(this->i2c_address);
    Wire.write(value);
    error = Wire.endTransmission(); //ends communication with the device
    if (error != 0) this->io_error = true;
}


/**
 * @brief Reads a given port content (HIGH or LOW)
 * @details Returns the value or the bit in a given pin (port)
 * @param port 
 * @return uint8_t 
 */
uint8_t PCF::digitalRead(uint8_t port) {
    return this->read() & (1 << port);
}

/**
 * @brief Writes HIGH or LOW in a given port (pin)
 * @details Turns a given port High or LOW
 * @param port 
 * @param value 
 */
void PCF::digitalWrite(uint8_t port, uint8_t value) {
    uint8_t currentPorts = this->read();
    this->write((currentPorts & ~(1 << port)) | (value << port));
}

