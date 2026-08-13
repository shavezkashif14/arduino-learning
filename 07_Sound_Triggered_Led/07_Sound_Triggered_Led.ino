int redLed = 9;

unsigned long previousTime = 0;

int upperThreshold = 800;
int lowerThreshold = 600;

bool ledOn = false;

void setup()
  {
    pinMode(redLed, OUTPUT);
  }

void loop()
  {
    int mic = analogRead(A0);

    if (mic >= upperThreshold)
      {
        ledOn = true;

        previousTime = millis();
      }

    if (ledOn)
      {
        digitalWrite(redLed, HIGH);
        
        if (millis() - previousTime >= 1000)
          {
            if (mic <= lowerThreshold)
              {
                ledOn = false;
              }

            previousTime = millis();
          }
      }
    else if (ledOn == false)
      {
        digitalWrite(redLed, LOW);
      }
  }