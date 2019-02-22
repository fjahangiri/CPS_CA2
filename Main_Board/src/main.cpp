#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial softserial(6,7);//6 RX , 7 TX

void setup(){
  
  lcd.begin(16 ,2);               // initialize the lcd
  Serial.begin(9600);
  softserial.begin(9600);
  lcd.setCursor ( 0 , 1 ); // go to position
}

void loop(){
  // Do a little animation
  if(Serial.available()){
    char data= Serial.read();
    softserial.print(data);
    lcd.print(data);
    char data1= Serial.read();
    softserial.print(data1);
    lcd.print(data1);
    delay(1000); // wait so it can be seen
  }
}

