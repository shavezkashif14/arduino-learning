int buzzer = 8;
int button = 2;

void setup()
  {
    pinMode(buzzer, OUTPUT);
    pinMode(button, INPUT_PULLUP);
  }

void loop()
  {
    if (digitalRead(button) == LOW)
      {
        tone(buzzer, 2000);
        delay(1);

        if (digitalRead(button) == HIGH)
          {
            tone(buzzer, 1000);
            delay(700);
          }
      }
    else
      {
        noTone(buzzer);
      }
  }