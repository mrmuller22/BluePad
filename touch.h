// Header file for the touch features

#ifndef TOUCH_H
#define TOUCH_H

// Defining TOuchscreen analog pin mappings
#define XP  25 // X+
#define XM  26 // X-
#define YP  32 // Y+
#define YM  33 // Y-

// Function Prototypes
void initTouch();
bool readTouch(int *x, int *y);

#endif