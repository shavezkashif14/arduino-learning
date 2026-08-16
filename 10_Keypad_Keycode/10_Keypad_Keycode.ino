#include <Keypad.h>

int code = 0;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
  {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };

  byte rowPins[ROWS] = {2, 3, 4, 5};
  byte colPins[COLS] = {6, 7, 8, 9};

  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
  {
    Serial.begin(9600);
  }

void loop()
  {
    char key = keypad.getKey();

    if (key)
      {
        if (key >= '0' && key <= '9')
          {
            code = code * 10 + (key - '0');
            Serial.print(key);

            if (code > 9999)
              {
                Serial.println("");
                Serial.println("Invalid Code");
                code = 0;
              }
          }

        else if (key == '#')
          {
            Serial.println("");

            if (code == 1234)
              {
                Serial.println("Correct Code");
              }
            else
              {
                Serial.println("Incorrect Code");
              }

            code = 0;
          }
        else
          {
            Serial.println("");
            Serial.println("Invalid Code");
            code = 0;
          }
      }
  }