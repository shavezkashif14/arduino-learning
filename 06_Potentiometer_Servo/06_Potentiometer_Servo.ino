#include <Servo.h>

Servo myServo;

void setup()
{
    myServo.attach(9);
}

void loop()
{
  int value = analogRead(A0);

  myServo.write(map(value, 0, 1023, 0, 180));
}