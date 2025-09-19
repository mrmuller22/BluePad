#include <Arduino.h>
#include <WiFi.h>
#include <BleKeyboard.h>
#include "screen.h"
#include "touch.h"
#include "BluetoothHID.h"
#include "WiFiManager.h"
#include "SPIFFS.h"

// touch variables
int x, y;

// Function to Set up System
void setup() {

  Serial.begin(115200);

  // Setting Up SPIFFS
  SPIFFS.begin(true);
  
  // Testing if File System has been set up
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Setting Pin 22 to Output
  // Controls Backlight of screen
  pinMode(22, OUTPUT);

  delay(1000);

  // Initializing screen and touch
  initScreen();
  initTouch();

  // Initializing Bluetooth Connection
  Serial.println("Setting Up Bluetooth");
  setupBluetooth();
  Serial.println("Bluetooth Initialized");

  Serial.println("System Ready");
  Serial.println("________________________________________");
  
}

// Main Function 
void loop() {

  // Testing if device is connected to PC
  if(isConnected()){

    // Setting Pin 22 High
    digitalWrite(22, HIGH);

    // Reading if touch input and the coordinates
    if (readTouch(&x, &y)) {

      // Checking which button has been pressed from the
      // X and Y Coordinates and setting it to pressed
      int pressed = checkButtonPress(x, y);

      // If press is on a button
      if (pressed != -1) {

        // Flashing button to user
        flashButton(pressed);

        // Printing which button pressed in serial
        Serial.printf("Button %d pressed\n", pressed);

        // Switch case to check which button
        switch(pressed) {

          // Button 0
          case 0:
            Serial.printf("Turning Vol Up\n");

            // Sending volume up cmd to PC
            sendKey(KEY_MEDIA_VOLUME_UP);
            break;

          // Button 1
          case 1:
            Serial.printf("Locking Machine\n");

            // Sending Lock cmd to PC
            sendCombo(KEY_RIGHT_GUI, 'l');
            break;

          // Button 2
          case 2:
            Serial.printf("Opening VS Code\n");

            // Command to open VS Code
            sendKey(KEY_LEFT_GUI);
            release();
            delay(300);
            sendText("Visual Studio Code");
            delay(300);
            sendKey(KEY_RETURN);

            break;

          // Button 3
          case 3:
            Serial.printf("Opening Fusion360\n");

            // Command to open Fusion360
            sendKey(KEY_LEFT_GUI);
            release();
            delay(300);
            sendText("Autodesk Fusion");
            delay(300);
            sendKey(KEY_RETURN);

            break;

          // Button 4
          case 4:
            Serial.printf("Turning Vol Down\n");

            // Command to Turn Volume Down
            sendKey(KEY_MEDIA_VOLUME_DOWN);
            break;

          // Button 5
          case 5:
            Serial.printf("Toggle Media\n");

            // Command to Toggle Media
            sendKey(KEY_MEDIA_PLAY_PAUSE);
            break;

          // Button 6
          case 6:
            Serial.printf("Opening Local Send\n");

            // Command to Open Local Send
            sendKey(KEY_LEFT_GUI);
            release();
            delay(300);
            sendText("LocalSend");
            delay(300);
            sendKey(KEY_RETURN);

            break;

          // Button 7
          case 7:
            Serial.printf("Opening Bambu Studio\n");

            // Command to Open Bambu Studio
            sendKey(KEY_LEFT_GUI);
            release();
            delay(300);
            sendText("Bambu Studio");
            delay(300);
            sendKey(KEY_RETURN);

            break;
          
          // Default Case
          default:
            Serial.printf("Error, Please Try Again...\n");
            break;
        }
      }
      // Delay for Input
      delay(200);
    } 

    // Else Statement to turn screen backlight off 
    // when not connected to PC
    else {
      Serial.printf("Host disconnected, entering sleep mode");
      digitalWrite(22, LOW);
    }
  }
}