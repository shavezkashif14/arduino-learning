void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int water = analogRead(A0);

    Serial.println(water);

    delay(100);
}