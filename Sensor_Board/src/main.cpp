#include <Arduino.h>

int val;
int tempPin=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  val=analogRead(tempPin);
  float mv= (val/1024.0)*5000;
  float cell=mv/10;

  Serial.print("ttt");
  Serial.print(cell);
  Serial.println();
  delay(1000);
  // put your main code here, to run repeatedly:
}