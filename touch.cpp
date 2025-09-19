// This file is where all the logic and the functions
// for the touch detection occurs

#include <Arduino.h>
#include "touch.h"

// Touch Pins
#define XP  25 // X+
#define XM  26 // X-
#define YP  32 // Y+
#define YM  33 // Y-

// Intializing the touch functionality
void initTouch() {
    pinMode(XP, INPUT);
    pinMode(XM, INPUT);
    pinMode(YP, INPUT);
    pinMode(YM, INPUT);
}

// Function for reading the touch coordinates
bool readTouch(int *x, int *y) {
    // Read X Position
    pinMode(YP, OUTPUT);
    digitalWrite(YP, HIGH);
    pinMode(YM, OUTPUT);
    digitalWrite(YM, LOW);
    pinMode(XP, INPUT);
    pinMode(XM, INPUT);
    delay(10);
    int RawX = analogRead(XP);

    // Read Y Position
    pinMode(XP, OUTPUT);
    digitalWrite(XP, HIGH);
    pinMode(XM, OUTPUT);
    digitalWrite(XM, LOW);
    pinMode(YP, INPUT);
    pinMode(YM, INPUT);
    delay(10);
    int RawY = analogRead(YP);

    // Noise Check
    if ((abs(RawX) < 100) || (abs(RawY) < 100) || (RawX > 3900) || (RawY > 3900)) return false;

    // Rescaling X/Y 
    *x = map(RawX, 300, 3329, 0, 480); // 480px wide
    *y = map(RawY, 2977, 645, 0, 320); // 320px high
    
    return true;
}