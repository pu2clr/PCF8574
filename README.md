# [PU2CLR - PCF8574 Arduino Library](https://pu2clr.github.io/PCF8574/)

It is an Arduino Library to control the PCF8574 8-Bit I/O Expander. 

The PCF8574 device provides 8-bit, general purpose, parallel I/O expansion. It can be controlled via I²C bus applications. It is a great and inexpensive device that allow you to add more peripherals to be controlled by your Arduino board via I²C protocol.

Some Arduino projects may require more pins than the Arduino actually has. In these cases, you can use up to 8 PCF8574 devices using only the I²C bus (two Arduino pins) and add up to 64 input / output ports to your project. 


This Arduino library implements the most important functions available on PCF8574 device  and can be freely distributed using the MIT Free Software model. 

[Copyright (c) 2021 Ricardo Lima Caratti](https://pu2clr.github.io/PCF8574/#mit-license).

## Contents

1. [License Copyright](https://pu2clr.github.io/PCF8574/#mit-license)
2. [Thanks](https://pu2clr.github.io/PCF8574/#thanks)
3. [Labrary Features](https://pu2clr.github.io/PCF8574/#labrary-features)
4. [Library Installation](https://pu2clr.github.io/PCF8574/#library-installation)
5. [Other Arduino Libraries developed by the Author](https://pu2clr.github.io/PCF8574/)
6. [API documentation](https://pu2clr.github.io/PCF8574/extras/apidoc/html/)
7. [Basic Schematic](https://pu2clr.github.io/PCF8574/#basic-schematic)
8. [Internal Interrupt setup](https://pu2clr.github.io/PCF8574/#internal-interrupt-setup) 
9.  [PCF8574 reset control](https://pu2clr.github.io/PCF8574/#PCF8574-reset-control)
10. [References](https://pu2clr.github.io/PCF8574/#references)


## MIT License 

Copyright (c) 2019 Ricardo Lima Caratti

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE ARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Thanks


## Labrary Features

This library uses the I²C communication protocol and implements most important functions offered by PCF8574 device from MicroChip. It also has primitive functions that make it easier to implement commands that may not have been implemented yet. The main features implemented can be seen below:

* GPIO/PORT individual control (8 I/O pins)
* I²C address customization (from 0x20 to 0x27)
* Internal Interrupt feature setup


## Demo video 



## Library Installation

__Under construction..__ 

You can install this library on your Arduino environment using different methods. The best ways to do that are described below.  

### Installing via Arduino IDE

This is the easiest method to install this library.

On Arduino IDE, select the __"Manager Libraries..."__ iten and look for PCF8574. Finally select "PU2CLR PCF8574". The images below show the installation process. 


#### Going to Manager libraries...

![Basic Schematic with LEDs](extras/images/install_lib_01.png)


#### Looking for PCF8574



#### Checking the PU2CLR_PCF8574 examples




#### More information

See also [Installing an Arduino Library ](https://learn.sparkfun.com/tutorials/installing-an-arduino-library/using-the-arduino-library-manager)



### Installing via this repository 

First, you have to [download](https://github.com/pu2clr/PCF8574/archive/main.zip) this library in zip format. 
After, unzip the PCF8574-master.zip file in your Arduino Library folder. 

* On __Windows__: "My Documents\Arduino\libraries"
* On __MAC OS__: ˜/Documents/Arduino/libraries
* On __Linux__: ˜/Documents/Arduino/libraries

With that approach, you will have the __most current version__ of the library. However, __it may not be the most stable version__. This is because the current version is always in development. [Prefer releases](https://github.com/pu2clr/PCF8574/releases).
Do you need some old version (release) of this library?  If yes, [check here](https://github.com/pu2clr/PCF8574/releases). 


## Other Arduino Libraries developed by the Author

* [PU2CLR Si4735 Library for Arduino](https://pu2clr.github.io/SI4735/). This library was built based on “Si47XX PROGRAMMING GUIDE; AN332” and it has support to FM, AM and SSB modes (LW, MW and SW). It also can be used on all members of the SI47XX family respecting, of course, the features available for each IC version;
* [PU2CLR SI4844 Arduino Library](https://github.com/pu2clr/SI4844). This is an Arduino library for the SI4844, BROADCAST ANALOG TUNING DIGITAL DISPLAY AM/FM/SW RADIO RECEIVER,  IC from Silicon Labs.  It is available on Arduino IDE. This library is intended to provide an easier interface for controlling the SI4844.
* [PU2CLR AKC695X Arduino Library](https://pu2clr.github.io/AKC695X/). The AKC695X is a family of IC DSP receiver from AKC technology. The AKC6955 and AKC6959sx support AM and FM modes. On AM mode the AKC6955 and AKC6959sx work on LW, MW and SW. On FM mode they work from 64MHz to 222MHz.
* [PU2CLR KT0915 Arduino Library](https://pu2clr.github.io/KT0915/). The KT0915 is a full band AM (LW, MW and SW) and FM DSP receiver that can provide you a easy way to build a high quality radio with low cost.
* [PU2CLR BK108X](https://pu2clr.github.io/BK108X/). The BK1086 and BK1088 are DSP receivers from BAKEN. The BK1088 is a BROADCAST FM and AM (LW, MW and ) RECEIVER and BK1086 is a subset of the BK1088 (it does not have LW and SW acording to the Datasheet).
* [PU2CLR RDA5807 Arduino Library](https://pu2clr.github.io/RDA5807/). The RDA5807 is a FM DSP integrated circuit receiver (50 to 115MHz) with low noise amplifier support. This device requires very few external components if compared with other similar devices. It also supports RDS/RBDS functionalities, direct auto gain control (AGC) and real time adaptive noise cancellation function.
* [PU2CLR SI470X Arduino Library](https://pu2clr.github.io/SI470X/). It is a Silicon Labs device family that integrates the complete functionalities for FM receivers, including RDS (Si4703).
* [PU2CLR MCP23008](https://pu2clr.github.io/MCP23008/). It is an Arduino Library to control the MCP23008 8-Bit I/O Expander. The MCP23008 device provides 8-bit, general purpose, parallel I/O expansion. It can be controlled via I2C bus applications. It is a great and inexpensive device that allow you to add more devices to be controlled by your Arduino board via I2C protocol.

## Basic schematic

The image below shows a basic PCF8574 application with LED. You can control up to 8 LEDs. The I²C bus address is set to 0x20. You can select another I²C address by dealing with the A0,A1 and A2 pins (from ????). This circuit uses the PCF8574 GPIO PINs as output.   

### GPIO as output setup




#### Arduino setup suggestion



#### Output setup example



### GPIO as input setup


![Basic Schematic with LEDs](extras/images/basic_schematic_input.png)


#### Arduino setup suggestion



### GPIO as input and output setup



## Prototype 


## Internal Interrupt setup



## PCF8574 reset control



## References 









