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
float sum;
int address;
byte buffer[4];
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
  else address=10;
}

void loop() {
  for(int j=0;j<4;j++){
    generateAddress();
    sendAddress();
    Wire.requestFrom(110,1);
    
    buffer[j]=Wire.read();
    //Serial.println(buffer[j]);
  }

  float x = *((float*)(buffer));

 // Serial.printsssln(x);
  for(int j=0;j<4;j++){
    generateAddress();
    sendAddress();
    Wire.requestFrom(110,1);
    buffer[j]=Wire.read();
   // Serial.println(buffer[j]);
  }

  float y = *((float*)(buffer));
  
  sum =pow(x,2) +pow(y,2);
//  Serial.print(sum);
 // char * b = (char *) &sum;
  // floatAsBytes.fval = sum;
  // Serial.println(floatAsBytes.bval[3]);
  // Serial.println(floatAsBytes.bval[2]);
  // Serial.println(floatAsBytes.bval[1]);
   byte * b = (byte *) &sum;
   Serial.write(b[0]);
   Serial.write(b[1]);
   Serial.write(b[2]);
   Serial.write(b[3]);
   delay(100);
}