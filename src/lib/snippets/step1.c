#include <Arduino.h>

#define DS <pin>
#define STCP <pin>
#define SHCP <pin>

void setup() {
    pinMode(DS, OUTPUT);
    pinMode(STCP, OUTPUT);
    pinMode(SHCP, OUTPUT);

    // clear display
    digitalWrite(STCP, LOW);
    shiftOut(DS, SHCP, LSBFIRST, ~(255));
    digitalWrite(STCP, HIGH);

    delay(1000);
}

int decDigits[10] = { 1, 2, 4, 8, 16, 32, 64, 128 };
void loop() {
    for(int i = 0; i < 10; i++) {
        digitalWrite(STCP, LOW);
        shiftOut(DS, SHCP, LSBFIRST, ~decDigits[i]);
        digitalWrite(STCP, HIGH);
        delay(500);
    }
}
