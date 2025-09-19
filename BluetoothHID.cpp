// This file is where all the functions related to the Bluetooth
// feature are stored. To integrate the ESP32 with PC I have 
// utilized the "BLEKeyboard" library. 

#include <BleKeyboard.h>
#include <Arduino.h>

// Creating Keyboard Object
BleKeyboard bleKeyboard("TouchDeck", "M^2", 100);

// Function to start the BLE Keyboard connection to PC
void setupBluetooth() {
  Serial.println("Starting BLE Keyboard...");
  bleKeyboard.begin();
}

// Function to check if there is a BLE Connection
bool isConnected() {
  return bleKeyboard.isConnected();
}

// Function to Send Text to PC over BLE
void sendText(const char* text) {
  if (bleKeyboard.isConnected()) {
    bleKeyboard.print(text);
  }
}

// Function to send Keyboard Key to PC over BLE
void sendKey(uint8_t keycode) {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(keycode);
    }
}

// Function to send Keyboard Key to PC over BLE
// with a pointer argument
void sendKey(const uint8_t* keycode) {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.write(keycode);
    }
}

// Function to send a combonation of keys to PC via BLE
void sendCombo(uint8_t key1, uint8_t key2) {
    if (bleKeyboard.isConnected()) {
        bleKeyboard.press(key1);
        bleKeyboard.press(key2);
        bleKeyboard.releaseAll();
    }
}

// Function to release the keys "pressed"
void release(){
  bleKeyboard.releaseAll();
}