#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

LiquidCrystal lcd(12,11,5,4,3,2);
AltSoftSerial altSerial;

SoftwareSerial softserial(7,6);//6 RX , 7 TX
byte buffer[4];
float num;
void setup(){
  num=0;
  lcd.begin(16 ,2);               
  Serial.begin(9600);
  altSerial.begin(9600);
  lcd.setCursor ( 0 , 1 ); 
}
void loop(){
 
  lcd.clear();
  
  if(Serial.available()>0){
     for(int i=0;i<4;i++){
       buffer[i]=Serial.read();
      }
     
    }     
   float x = *((float*)(buffer));
    lcd.println(x);


      delay(100); 

}