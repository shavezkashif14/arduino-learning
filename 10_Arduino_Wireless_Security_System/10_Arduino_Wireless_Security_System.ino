#include <IRremote.hpp>

int redLed = 2;
int greenLed = 4;
int receiver = 7;

int value = 10000;
int stage = 0;
int code = 0;
int key = -1;

void setup() 
  {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);

    IrReceiver.begin(receiver, ENABLE_LED_FEEDBACK);

    Serial.begin(9600);
    Serial.println("");
    Serial.print("Enter your pin: ");
  }

void loop() 
  {
    if (IrReceiver.decode())
      {
        int signal = IrReceiver.decodedIRData.command;

        if (signal == 12)
          {
            key = 1;
          }
        else if (signal == 13)
          {
            key = 0;
          }
        else if (signal == 24)
          {
            key = 2;
          }
        else if (signal == 94)
          {
            key = 3;
          }
        else if (signal == 8)
          {
            key = 4;
          }
        else if (signal == 28)
          {
            key = 5;
          }
        else if (signal == 90)
          {
            key = 6;
          }
        else if (signal == 66)
          {
            key = 7;
          }
        else if (signal == 82)
          {
            key = 8;
          }
        else if (signal == 74)
          {
            key = 9;
          }
        else if (signal == 9)
          {
            key = 10;
          }
        else if (signal == 69)
          {
            key = 11;
          }

        if (stage == 0)
          {
            if (key >= 0 && key <= 9)
              {
                code = key + (code * 10);
                Serial.print(key);

                key = -1;

                if (code > 9999)
                  {
                    Serial.println("");
                    Serial.println("Invalid Code");
                    digitalWrite(redLed, HIGH);
                    delay(500);
                    digitalWrite(redLed, LOW);

                    code = 0;
                  }
              }
            else if (key == 10)
              {
                if (code == 1234)
                  {
                    stage = 1;

                    Serial.println("");
                    Serial.println("Welcome Sir!");
                    digitalWrite(greenLed, HIGH);
                    delay(500);
                    digitalWrite(greenLed, LOW);

                    code = 0;
                  }
                else
                  {
                    Serial.println("");
                    Serial.println("Incorrect Code");
                    digitalWrite(redLed, HIGH);
                    delay(500);
                    digitalWrite(redLed, LOW);

                    code = 0;
                  }

                key = -1;
              }
          }

        delay(100);
        IrReceiver.resume();
      }

    if (stage == 1)
      {
        if (key == 11)
          {
            stage = 0;
            key = -1;

            Serial.print("Enter Your Pin: ");
          }
        else
          {
            Serial.print("Light :");
            Serial.println(analogRead(A1));
            delay(500);
          }

        if (analogRead(A1) >= 450)
          {
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
          }
        else if (analogRead(A1) <= 150)
          {
            digitalWrite(redLed, LOW);
            digitalWrite(greenLed, HIGH);
          }
      }
  }
