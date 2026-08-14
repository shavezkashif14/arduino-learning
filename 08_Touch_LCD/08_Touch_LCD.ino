#include <LiquidCrystal.h>

int touchSensor = 7;

int stage = 1;
bool tapped = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
  {
    pinMode(touchSensor, INPUT);

    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    lcd.print("Welcome!");

    lcd.setCursor(0, 1);
    lcd.print("Tap to begin!");
  }

void loop()
  {
    if (stage == 1 && digitalRead(touchSensor) == HIGH)
      {
        tapped = true;
        stage = 0;
      }

    if (tapped)
      {
        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Day 8");
        
        lcd.setCursor(0, 1);
        lcd.print("Completed!");
        
        tapped = false;
      }
  } 