#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>


LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial softserial(7,6);//6 RX , 7 TX
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
  
  if(Serial.available()>0){
     for(int i=0;i<4;i++){
       buffer[i]=Serial.read();
      }
     
    }     
      float x = *((float*)(buffer));
    lcd.println(x);


  softserial.listen();
  if(softserial.available()){
    char data;
    while(true){
      data = softserial.read();
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