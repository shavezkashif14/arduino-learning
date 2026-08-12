int redLed = 9;

void setup() 
  {
    pinMode(redLed, OUTPUT);
  }

void loop() 
  {
    int value = analogRead(A0);

    if (value >= 512)
      {
        analogWrite(redLed, map(value, 512, 1023, 0, 255));
      }
    else 
      {
        analogWrite(redLed, 0);
      }
  }
