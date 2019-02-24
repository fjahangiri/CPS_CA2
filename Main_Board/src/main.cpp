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
  float x;
  if(Serial.available()>3){
     for(int i=0;i<4;i++){
       buffer[i]=Serial.read();
      }
      x = *((float*)(buffer));
      lcd.print(x);
      lcd.print("utboard data");
      lcd.println();

    }     
  if(altSerial.available()>0){
    char data;
    while(true){
      data = altSerial.read();
      if(data == 'e'){
        break;
      }
      if(data == 'u'){
        lcd.print("cm");
        lcd.println();
      }
      else{
        //softserial.print(data);
        lcd.print(data);
      }
    }
    lcd.print("`c");
    lcd.println();
  }
      delay(100); 

}