// Header file for the screen functions

#ifndef SCREEN_H
#define SCREEN_H

#include <TFT_eSPI.h>
#include <PNGdec.h>
#include <SPIFFS.h>

// Defining the structure for the buttons
struct Button {
    // Defining the x, y, width and height
    int x, y, w, h;

    // Defining the color
    uint16_t color;

    // Defining label 
    const char* label; // Can be text or PNG file path
};

// Creating global variables
extern TFT_eSPI tft;       // Defined in screen.cpp
extern PNG png;
extern const int NUM_BUTTONS;
extern Button buttons[];

// Function Prototypes
void initScreen();
void drawButton(const Button &btn);
int pngDraw(PNGDRAW *pDraw);
void drawAllButtons();
int checkButtonPress(int xTouch, int yTouch);
void flashButton(int index);

#endif
