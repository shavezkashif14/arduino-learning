int redLed = 7;
int yellowLed = 2;
int greenLed = 8;
int button = 12;

unsigned long previousTime = 0;

int stage = 1;

void setup() 
  {
    pinMode(redLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(button, INPUT_PULLUP);
  }

void loop() 
  {
    if (digitalRead(button) == LOW)
      {
        digitalWrite(redLed, HIGH);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, LOW);

        stage = 1;
        previousTime = millis();
      }
    else
      {
        if (stage == 1)
          {
            digitalWrite(redLed, HIGH);
            digitalWrite(yellowLed, LOW);
            digitalWrite(greenLed, LOW);
            
            if (millis() - previousTime >= 3000)
              {
                stage = 2;
                previousTime = millis();
              }
          }
        else if (stage == 2)
          {
            digitalWrite(redLed, LOW);
            digitalWrite(yellowLed, HIGH);
            digitalWrite(greenLed, LOW);

            if (millis() - previousTime >= 1000)
              {
                stage = 3;
                previousTime = millis();
              }
          }
        else if (stage == 3)
          {
            digitalWrite(redLed, LOW);
            digitalWrite(yellowLed, LOW);
            digitalWrite(greenLed, HIGH);

            if (millis() - previousTime >= 3000)
              {
                stage = 4;
                previousTime = millis();
              }
          }
        else if (stage == 4)
          {
            digitalWrite(redLed, LOW);
            digitalWrite(yellowLed, HIGH);
            digitalWrite(greenLed, LOW);

            if (millis() - previousTime >= 1000)
              {
                stage = 1;
                previousTime = millis();
              }
          }
      }
  }
