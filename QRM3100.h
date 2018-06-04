#ifndef QRM3100_h
#define QRM3100_h

#include "Arduino.h"
#include "Wire.h"

#define QRM3100_CMM  		0x01 //initiates continuous measurement mode
#define QRM3100_CCXMSB  		0x04 //cycle count regsiter for x-axis (most significant bit)
#define QRM3100_CCXLSB			0x05
#define QRM3100_CCYMSB  		0x06 // ... for y-axis
#define QRM3100_CCYLSB  		0x07
#define QRM3100_CCZMSB  		0x08 // ... for z-axis
#define QRM3100_CCZLSB  		0x09
#define QRM3100_NOS_REG			0x0A
#define QRM3100_TMRC 		0x0B //sets continuous measurement mode data rate

#define QRM3100_MX2   		0xA4 // measurement results for x-axis
#define QRM3100_MX1   		0xA5
#define QRM3100_MX0   		0xA6
#define QRM3100_MY2   		0xA7 // measurement results for y-axis
#define QRM3100_MY1   		0xA8
#define QRM3100_MY0   		0xA9
#define QRM3100_MZ2   		0xAA // measurement results for z-axis
#define QRM3100_MZ1   		0xAB
#define QRM3100_MZ0   		0xAC
#define QRM3100_STATUS_REG   	0xB4 //status of DRDY
#define QRM3100_I2C_ADDRESS   	0x20 //Address of slave device
#define QRM3100_POLL		0x00 //poll

class QRM3100 // create a class
{ 	
	public:
	uint8_t readRegister(uint8_t address); //function to read register values
	void writeRegister(uint8_t address, uint8_t value); //function to write to a register

  
};

#endif