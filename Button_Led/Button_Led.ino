void setup()
{
    pinMode(7, OUTPUT);
    pinMode(2, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(2) == LOW)
    {
        digitalWrite(7, LOW);
    }
    else
    {
        digitalWrite(7, HIGH);
    }
}