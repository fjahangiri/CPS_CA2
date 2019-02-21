#include <Arduino.h>
#include <Wire.h>
boolean start=true;
int address;
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

void loop() {
  generateAddress();
  sendAddress();
  Wire.requestFrom(110,1);
  int c=Wire.read();
  Serial.println(c);
  delay(500);
}