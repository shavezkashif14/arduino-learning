int redLed = 9;

int lowerThreshold = 400;
int upperThreshold = 600;

int stage = 1;

void setup()
  {
    pinMode(redLed, OUTPUT);
  }

void loop()
  {
    int lightSensor = analogRead(A0);

    if (stage == 1)
      {
        digitalWrite(redLed, LOW);
      }
    else if (stage == 2)
      {
        digitalWrite(redLed, HIGH);
      }

    if (lightSensor >= upperThreshold)
      {
        stage = 2;
      }
    else if (lightSensor <= lowerThreshold)
      {
        stage = 1;
      }
  }