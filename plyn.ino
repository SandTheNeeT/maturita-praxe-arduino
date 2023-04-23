#include <MQ2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);

int Analog_Input = A0;
int lpg, co, smoke;

#define BUTTON_PIN 7

MQ2 mq2(Analog_Input);

void setup(){
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  mq2.begin();
}
void loop(){
  if (digitalRead(BUTTON_PIN) == LOW) {
    lcd.setCursor(0,0);
    lcd.print("SEDLAK PETR     ");
    lcd.print(co);
    lcd.setCursor(0,1);
    lcd.print("PUSH FOR VALUES ");
    delay(100);
  }
  else {
    lpg = mq2.readLPG();
    co = mq2.readCO();
    smoke = mq2.readSmoke();
    lcd.setCursor(0,0);
    lcd.print("LPG:");
    lcd.print(lpg);
    lcd.print(" CO:");
    lcd.print(co);
    lcd.print("    ");
    lcd.setCursor(0,1);
    lcd.print("SMOKE:");
    lcd.print((smoke*100)/1000000);
    lcd.print(" %      ");
    delay(1000);
  }
  
}
