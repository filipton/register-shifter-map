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

// generated
int decDigits[10] = {246,6,117,87,135,211,243,70,247,215};
int dotMod = 8;

void loop() {
    for(int i = 0; i < 10; i++) {
        digitalWrite(STCP, LOW);
        shiftOut(DS, SHCP, LSBFIRST, ~decDigits[i] ^ dotMod);
        //         XOR dotMod into digit ----------^

        digitalWrite(STCP, HIGH);
        delay(500);
    }
}
