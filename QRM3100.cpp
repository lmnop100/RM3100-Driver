#include "Arduino.h"
#include "QRM3100.h"
#include <Wire.h>
#include <math.h>

#define CALIBRATION_TIMEOUT 5000 //timeout in milliseconds
#define DEG_PER_RAD (180.0/3.14159265358979)


uint8_t QRM3100::readRegister(uint8_t address){
  uint8_t output;

  Wire.beginTransmission(QRM3100_I2C_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();

  delayMicroseconds(2);

  Wire.requestFrom(QRM3100_I2C_ADDRESS, 1);
  while(Wire.available())
  {
	output = Wire.read();
  }

  return output;
}


void QRM3100::writeRegister(uint8_t address, uint8_t value){
  Wire.beginTransmission(QRM3100_I2C_ADDRESS);
  Wire.write(address);
  Wire.write(value);
  Wire.endTransmission();
}
