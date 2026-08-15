int led = 9;

int VRx = A0;
int VRy = A1;
int button = 2;

void setup()
  {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLUP);
  }

void loop()
  {
    int xValue = analogRead(VRx);
    int yValue = analogRead(VRy);

    //CENTER
    if (xValue >= 450 && xValue <= 570 && yValue >= 450 && yValue <= 570)
      {
        analogWrite(led, 0);
      }

    //UP
    else if (yValue < 450)
      {
        analogWrite(led, 255);
      }

    //DOWN
    else if (yValue > 570)
      {
        analogWrite(led, 0);
      }

    //RIGHT
    else if (xValue > 570)
      {
        analogWrite(led, 128);
      }

    //LEFT
    else if (xValue < 450)
      {
        analogWrite(led, 50);
      }

    //PRESS JOYSTICK
    if (digitalRead(button) == LOW)
      {
        analogWrite(led, 255);
      }
  }