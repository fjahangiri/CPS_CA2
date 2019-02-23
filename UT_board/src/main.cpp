/*#include <Arduino.h>

#include <Wire.h>
boolean start=true;
int address;
void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
  generateAddress();
  sendAddress();
  Wire.requestFrom(110,1);
  int c=Wire.read();
  Serial.println(c);
  delay(100);
}*/

#include <Arduino.h>
#include <Wire.h>
boolean start=true;
int sum;
int address;
union {
    float f;
    byte b[4];
} u;
union {
    float fval;
    byte bval[4];
} floatAsBytes;

void setup() {
  Wire.begin();
  Wire.beginTransmission(110);
  Wire.write(0);
  Wire.write(1);
  Wire.endTransmission();
  address=9;    
  sum =0;  
  Serial.begin(9600);  
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
  for(int j=3;j>=0;j--){
    generateAddress();
    sendAddress();
    Wire.requestFrom(110,1);
    u.b[j]=Wire.read();
  }
  float x=u.f;
  for(int j=3;j>=0;j--){
    generateAddress();
    sendAddress();
    Wire.requestFrom(110,1);
    u.b[j]=Wire.read();

  }
  float y=u.f;
  Serial.println(y);
  sum += pow(2,pow(x,2)) +y;
  
  floatAsBytes.fval = sum;
  Serial.println(floatAsBytes.bval[3]);
  Serial.println(floatAsBytes.bval[2]);
  Serial.println(floatAsBytes.bval[1]);
  Serial.println(floatAsBytes.bval[0]);
  delay(100);
}