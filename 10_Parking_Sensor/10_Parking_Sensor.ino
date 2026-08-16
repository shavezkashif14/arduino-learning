int buzzer = 10;

int trig = 8;
int echo = 7;

void setup()
  {
    pinMode(buzzer, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    Serial.begin(9600);
  }

void loop()
  {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig, LOW);

    unsigned long duration = pulseIn(echo, HIGH);

    float distance = (duration * 0.0323) / 2;

    Serial.println(distance);

    if (distance <= 20 && distance > 15)
      {
        tone(buzzer, 1000);
      }
    else if (distance <= 15 && distance > 8)
      {
        tone(buzzer, 1500);
      }
    else if (distance <= 8 && distance != 0)
      {
        tone(buzzer, 2000);
      }
    else
      {
        noTone(buzzer);
      }  
  } 