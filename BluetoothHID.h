// Header File for Bluetooth feature

#ifndef BLUETOOTHHID_H
#define BLUETOOTHHID_H

#include <BleKeyboard.h>

// Extern Declaration so it can be shared
extern BleKeyboard bleKeyboard;

// Function Prototypes
void setupBluetooth();
bool isConnected();
void sendText(const char* text);
void sendKey(uint8_t keycode);
void sendKey(const uint8_t* keycode);
void sendCombo(uint8_t key1, uint8_t key2);
void release();

#endif