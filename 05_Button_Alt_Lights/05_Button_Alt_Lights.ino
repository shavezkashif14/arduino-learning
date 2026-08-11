int redLed = 7;
int greenLed = 8;
int button = 2;


void setup() 
  {
    pinMode(2, INPUT_PULLUP);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
  }

void loop() 
  {
    if (digitalRead(button) == HIGH)
      {
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, HIGH);
      }
    else
      {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
      }
  }
