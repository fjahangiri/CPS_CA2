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

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
 // Serial.println(" cm" );
  sensorValue = float(analogRead(analogPin)) * 110 / 1024;
  // output data to serial monitor
  //Serial.print("temp: ");
  // print only one decimal place
  //Serial.print(sensorValue, 1);
  //Serial.println("degrees C");
  
  delay(100);
}