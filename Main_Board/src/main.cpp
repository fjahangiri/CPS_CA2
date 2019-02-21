#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("hello");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.println("thanks");
  // put your main code here, to run repeatedly:
}