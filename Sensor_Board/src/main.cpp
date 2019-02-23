#include <Ultrasonic.h>
#include <LM35.h>

Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)
const int analogPin = 0;
// the variable for the data
float sensorValue = 0;


void setup() {
  Serial.begin(9600);
  
  analogReference(INTERNAL);
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode
}

void loop(){
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
 // Serial.print(" cm" );
  sensorValue = float(analogRead(analogPin)) * 110 / 1024;
  //Serial.print("temp: ");
  Serial.print(sensorValue, 1);
  //Serial.print("degrees C");
  delay(100);
}