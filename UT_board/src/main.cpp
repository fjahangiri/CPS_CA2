#include <Arduino.h>
#include <Wire.h>
boolean start=true;
int address;
union {
    float f;
    uchar b[4];
} u;
void setup() {
  Wire.begin();
  Wire.beginTransmission(110);
  Wire.write(0);
  Wire.write(1);
  Wire.endTransmission();
  address=9;      // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}
void sendAddress(){
  Wire.beginTransmission(110);
  Wire.write(address);
  Wire.endTransmission();
}
void generateAddress(){
  if(address<13)address=address+1;
  else if(address==13)address=40;
  else if(address<43)address=address+1;
  else address=13;
}
void 


void loop() {
  generateAddress();
  sendAddress();
  Wire.requestFrom(110,1);
  u.b[3]=Wire.read();
  generateAddress();
  sendAddress();
  Wire.requestFrom(110,1);
  u.b[3]=Wire.read();
generateAddress();
  sendAddress();
  Wire.requestFrom(110,1);
  u.b[3]=Wire.read();

  union {sdfasf
    float f;
    uchar b[4];
  } u;
  u.b[3] = b0;
  u.b[2] = b1;sadfaegfsf
  u.b[1] = b2;
  u.b[0] = b3;
  return u.f;
  Serial.println(c);
  delay(500);
}