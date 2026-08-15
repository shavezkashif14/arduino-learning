#include <IRremote.hpp>

int redLed = 9;
int receiver = 2;

unsigned long previousTime = 0;
int previousButton = 10000; // 10000 means nothing pressed yet

int value = 10000;
bool ledState = false;

void setup()
{
    pinMode(redLed, OUTPUT);
    IrReceiver.begin(receiver, ENABLE_LED_FEEDBACK);
}

void loop()
{
    if (IrReceiver.decode())
    {
        value = IrReceiver.decodedIRData.command;

        if (value == 12)
        {
            previousButton = 1;
        }
        else if (value == 13)
        {
            previousButton = 0;
        }
        else if (value == 24)
        {
            previousButton = 2;
            previousTime = millis();
            ledState = true;
            digitalWrite(redLed, HIGH);
        }
        else if (value == 94)
        {
            previousButton = 3;
        }
        else if (value == 8)
        {
            previousButton = 4;
        }

        IrReceiver.resume();
    }

    if (previousButton == 1)
    {
        digitalWrite(redLed, HIGH);
        previousButton = 10000;
    }
    else if (previousButton == 0)
    {
        digitalWrite(redLed, LOW);
        previousButton = 10000;
    }
    else if (previousButton == 2)
    {
        if (millis() - previousTime >= 1000)
        {
            previousTime = millis();

            ledState = !ledState;
            digitalWrite(redLed, ledState);
        }
    }
    else if (previousButton == 3)
    {
        analogWrite(redLed, 70);
        previousButton = 10000;
    }
    else if (previousButton == 4)
    {
        analogWrite(redLed, 20);
        previousButton = 10000;
    }
}