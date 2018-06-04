#include <C:\Users\daehy\OneDrive\Documents\Arduino\libraries\src\QRM3100.h>
#include <C:\Users\daehy\OneDrive\Documents\Arduino\libraries\src\QRM3100.cpp>
#include <Wire.h>

QRM3100 mag;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Check REVID register first, should return 0x22.
  if (mag.readRegister(0x36) != 0x22)
  {
    Serial.println("REVID NOT CORRECT!");
    Serial.print("REVID: ");
    Serial.println(mag.readRegister(0x36), HEX);
  }
  else
  {
    Serial.println("RM3100 Detected Properly");
    Serial.print("REVID: ");
    Serial.println(mag.readRegister(0x36), HEX);
  }
}

void loop()
{

  int32_t x, y, z; // variables to store results

  // poll the RM3100 for a single measurement
  mag.writeRegister(0x00, 0x70);

  delay(500); // delay to help monitor DRDY pin on eval board

  // Check if DRDY went high and wait unit high before reading results
  while ((mag.readRegister(0x34) & 0x80) != 0x80) {} 

  // Read results, this will cause DRDY to go low
  uint8_t mx2 = mag.readRegister(0x24);
  uint8_t mx1 = mag.readRegister(0x25);
  uint8_t mx0 = mag.readRegister(0x26);
  uint8_t my2 = mag.readRegister(0x27);
  uint8_t my1 = mag.readRegister(0x28);
  uint8_t my0 = mag.readRegister(0x29);
  uint8_t mz2 = mag.readRegister(0x2A);
  uint8_t mz1 = mag.readRegister(0x2B);
  uint8_t mz0 = mag.readRegister(0x2C);

  // Format results
  x = ((int32_t)(mx2 * 256 * 256) | (mx1 * 256) | mx0)/75;
  y = ((int32_t)(my2 * 256 * 256) | (my1 * 256) | my0)/75;
  z = ((int32_t)(mz2 * 256 * 256) | (mz1 * 256) | mz0)/75;

  // Print results
  Serial.print("M:  ");
  Serial.print(x);
  Serial.print("   ");
  Serial.print(y);
  Serial.print("   ");
  Serial.println(z);

  delay(500);  // delay to help monitor DRDY pin on eval board
  
}
