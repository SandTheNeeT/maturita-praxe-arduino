#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,20,4) for 20x4 LCD.

#define RED_LED 13
#define GRE_LED 12
#define BLU_LED 11

void setup(){
  
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

  pinMode(RED_LED, OUTPUT);
  pinMode(GRE_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);

  Serial.begin(9600);
  while (!Serial);
  Serial.println("COMMANDS:");
  Serial.println("1. Red LED ON");
  Serial.println("2. Red LED OFF");
  Serial.println("3. Green LED ON");
  Serial.println("4. Green LED OFF");
  Serial.println("5. Blue LED ON");
  Serial.println("6. Blue LED OFF");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Petr Sedlak");
  lcd.setCursor(0,1);
  lcd.print("yes.");
}

void loop() {
  
  if (Serial.available()){
  int state = Serial.parseInt();
  
    if (state == 1) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Red is ON");
      
      digitalWrite(RED_LED, HIGH);
      Serial.println("Red LED turned ON");
    }
    else if (state == 2) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Red is OFF");
      
      digitalWrite(RED_LED, LOW);
      Serial.println("Red LED turned OFF");

    }
    else if (state == 3) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Green is ON");
      
      digitalWrite(GRE_LED, HIGH);
      Serial.println("Green LED turned ON");

    }
    else if (state == 4) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Green is OFF");
      
      digitalWrite(GRE_LED, LOW);
      Serial.println("Green LED turned OFF");

    }
    else if (state == 5) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Blue is ON");
      
      digitalWrite(BLU_LED, HIGH);
      Serial.println("Blue LED turned ON");

    }
    else if (state == 6) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Blue is OFF");
      
      digitalWrite(BLU_LED, LOW);
      Serial.println("Blue LED turned OFF");

    }
  }
}
