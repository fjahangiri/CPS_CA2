#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>


LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial softserial(6,7);//6 RX , 7 TX
byte buffer[4];
float num;
void setup(){
  num=0;
  lcd.begin(16 ,2);               
  Serial.begin(9600);
  softserial.begin(9600);
  lcd.setCursor ( 0 , 1 ); 
}
void loop(){
  
  lcd.clear();
  if(softserial.available()>3){
      for(int i=0;i<4;i++){
        buffer[i]=softserial.read();
      }
    }     
    num = *((float*)(buffer));
  
      lcd.println(num);
    delay(600); 

  
  // if(Serial.available()){
  //   char data;
  //   while(true){
  //     data = Serial.read();
  //     if(data == 'e'){
  //       break;
  //     }
  //     if(data == 'u'){
  //       lcd.print("cm");
  //       lcd.println();
  //     }
  //     else{
  //       //softserial.print(data);
  //       lcd.print(data);
  //     }
  //   }
  //   lcd.print("`c");
  //   lcd.println(); 
  //}
}