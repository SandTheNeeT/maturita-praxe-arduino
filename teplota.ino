#include "DHT.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BUTTON_PIN 7

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT test!");
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  delay(2000);

    if (digitalRead(BUTTON_PIN) == HIGH) {

      float h = dht.readHumidity();
      float t = dht.readTemperature();

      Serial.print("Humidity: "); 
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: "); 
      Serial.print(t);
      Serial.print(" *C ");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Temp: ");
      lcd.print(t);
      lcd.print("*C") ;
 
      lcd.setCursor(0,1);
      lcd.print("Humi: ");
      lcd.print(h);
      lcd.print("%") ;
  }

  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Petr Sedlak");
    lcd.setCursor(0,1);
    lcd.print("Vsichni smrdite");
  }
}
