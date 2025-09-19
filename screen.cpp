// This file is where all the functions related to the screen
// are stored. This is where I create the buttons from the button structure
// I interface with the Arduino TFT_eSPI library since the screen I used is
// TFT Display. To draw the PNG imgs in the buttons I utlized the "PNGdec.h"
// Library.

#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <PNGdec.h>
#include <SPIFFS.h>
#include <FS.h>
#include "screen.h"

// Defining Pins specific for the tft screen
#define TFT_CS  5 
#define TFT_DC  4
#define TFT_RST 2

// Sets rendering line buffer lengths, adjust for your images
#define MAX_IMAGE_WIDTH 480 

// Creating Screen Object
TFT_eSPI tft = TFT_eSPI();

// Creating PNG Object
PNG png;

// Creating Global Variables xpos, ypos
int16_t xpos;
int16_t ypos;

// Layout Settings for screen
const int screen_width = 480;
const int screen_height = 320;

// Spacing Variables
const int top_padding = 20;
const int side_padding = 10;
const int button_spacing = 10;
const int num_cols = 4;
const int num_rows = 2;

// Button Height and Width Calculations
const int button_width = (screen_width - (side_padding * 2) - (button_spacing * (num_cols - 1))) / num_cols;
const int button_height = (screen_height - (top_padding * 2) - (button_spacing * (num_rows - 1))) / num_rows;

// Defining 8 buttons
Button buttons[] = {
    {side_padding + (button_width + button_spacing) * 0, top_padding + (button_height + button_spacing) * 0, button_width, button_height, TFT_CYAN,     "/macro1.png"},
    {side_padding + (button_width + button_spacing) * 1, top_padding + (button_height + button_spacing) * 0, button_width, button_height, TFT_CYAN,    "/macro2.png"},
    {side_padding + (button_width + button_spacing) * 2, top_padding + (button_height + button_spacing) * 0, button_width, button_height, TFT_CYAN,   "/macro3.png"},
    {side_padding + (button_width + button_spacing) * 3, top_padding + (button_height + button_spacing) * 0, button_width, button_height, TFT_CYAN,  "/macro4.png"},
    {side_padding + (button_width + button_spacing) * 0, top_padding + (button_height + button_spacing) * 1, button_width, button_height, TFT_CYAN,  "/macro5.png"},
    {side_padding + (button_width + button_spacing) * 1, top_padding + (button_height + button_spacing) * 1, button_width, button_height, TFT_CYAN,    "/macro6.png"},
    {side_padding + (button_width + button_spacing) * 2, top_padding + (button_height + button_spacing) * 1, button_width, button_height, TFT_CYAN,  "/macro7.png"},
    {side_padding + (button_width + button_spacing) * 3, top_padding + (button_height + button_spacing) * 1, button_width, button_height, TFT_CYAN, "/macro8.png"},
};

// Calculating Number of Buttons
const int NUM_BUTTONS = sizeof(buttons) / sizeof(Button);

// Function to Initialize the Screen
void initScreen() {
    tft.begin();
    tft.setRotation(3); // Landscape
    tft.fillScreen(TFT_BLACK);

    // Function to Draw the Buttons
    drawAllButtons();
}

// Function 
int pngDraw(PNGDRAW *pDraw) {
    static uint16_t lineBuffer[MAX_IMAGE_WIDTH];
    static uint8_t maskBuffer[1 + (MAX_IMAGE_WIDTH / 8)];

    png.getLineAsRGB565(pDraw, lineBuffer, PNG_RGB565_LITTLE_ENDIAN, 0);

    if (png.getAlphaMask(pDraw, maskBuffer, 1)) {
        tft.pushMaskedImage(xpos, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer, maskBuffer);
    } else {
        tft.pushImage(xpos, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer);
    }

    return 1;
}

// Function to draw each button
void drawButton(const Button& btn) {
    const int radius = 12;

    // Draw button background (cyan fill + white border)
    tft.fillRoundRect(btn.x, btn.y, btn.w, btn.h, radius, btn.color);
    tft.drawRoundRect(btn.x, btn.y, btn.w, btn.h, radius, TFT_WHITE);

    // Open PNG
    auto file = SPIFFS.open(btn.label, "r");

    // Test if PNG can open
    if (!file) {
        Serial.printf("Failed to open %s\n", btn.label);
        return;
    }

    // Creating fileSize variable
    size_t fileSize = file.size();
    
    // Buffer variable of img
    uint8_t *buf = (uint8_t*)malloc(fileSize);

    // Testing if allocating buffer
    if (!buf) {
        Serial.println("PNG buffer alloc failed!");
        file.close();
        return;
    }

    // Reading the img with buffer and size
    file.read(buf, fileSize);
    file.close();

    // If statement to draw the img within the center of button
    if (png.openRAM(buf, fileSize, pngDraw) == PNG_SUCCESS) {
        // Center the PNG inside the button
        xpos = btn.x + (btn.w - png.getWidth()) / 2;
        ypos = btn.y + (btn.h - png.getHeight()) / 2;
        png.decode(NULL, 0);
    }

    free(buf);
}

// Function to draw all the buttons
void drawAllButtons(){
    for(int i = 0; i < NUM_BUTTONS; i++){
        drawButton(buttons[i]);
    }
}

// Function to check if button has been pressed 
// via the X and Y Coordinates 
int checkButtonPress(int xTouch, int yTouch){

    // Loop over the number of buttons 
    for (int i = 0; i < NUM_BUTTONS; i++){
        // Checking the X and Y coordinates 
        if (xTouch >= buttons[i].x &&
            xTouch <= buttons[i].x + buttons[i].w &&
            yTouch >= buttons[i].y &&
            yTouch <= buttons[i].y + buttons[i].h) {
                return i; // Return button index
        }
    }
    return -1; // No Button Pressed
}

// Function to flash the button when pressed by user
void flashButton(int index) {
    const int flash_radius = 12; // Rounded Corner Radius

    if (index < 0 || index >= NUM_BUTTONS) return; // Safety Check

    // Fil Button with flash color
    tft.fillRoundRect(
        buttons[index].x, 
        buttons[index].y, 
        buttons[index].w, 
        buttons[index].h, 
        flash_radius, 
        TFT_WHITE // Flash to white color
    );

    // Redrawing button after flash
    tft.setTextColor(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(buttons[index].label, buttons[index].x + buttons[index].w / 2, buttons[index].y + buttons[index].h / 2, 2);

    // Hold flash for 150ms
    delay(150); 

    // Redraw original button
    drawButton(buttons[index]);
}