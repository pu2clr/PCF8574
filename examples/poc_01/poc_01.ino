#include <pu2clr_pcf8574.h> 


PCF pcf;

void setup() {
    pcf.setup();           // Starts the device with 0X20 I2C address (default)
    pcf.write(0B11111111); // Turns all pins HIGH
    delay(10000);          // Time to mensure the device ports (pins)
    pcf.read(0B00000000);  // Turns all pins LOW
    delay(10000);          // Time to mensure the device ports (pins)
}

void loop() {

}