# BluePad
This repository showcases my personal project the BluePad. Inspired by the Stream Deck and to have easy access to shortcuts for my Computer.

**Description:**

Unlike a commercial Stream Deck, this project was designed to be a low-cost, fully customizable alternative using an ESP32 and TFT touchscreen. The purpose of this project was to create a touchscreen interface that could send hotkeys and shortcuts to a PC over Bluetooth Low Energy. The goals for the project were to:

1. Develop a touchscreen interface with multiple customizable buttons
2. Send keyboard shortcuts wirelessly to a PC using BLE
3. Provide an easy way to trigger hotkeys for productivity, gaming, or streaming
4. Create a portable, standalone device without the need for additional software
5. Design a custom PCB and 3D-printed housing for a polished, integrated final product

**Features:**

The features this project utilized were an ESP32 running the BLE Keyboard Arduino library to emulate a wireless keyboard. I programmed the touchscreen interface to allow users to interact with different buttons that trigger specific commands on the PC. What makes this project unique is the ability to create a fully customizable stream deck without relying on expensive hardware, while also incorporating custom hardware and enclosure design for a professional finish.

The peripherals utlized were:
  * ESP32 Microcontroller
  * TFT Touchscreen Display

**Programming Language:** C++

**Libraries/Frameworks:** ESP32 BLE Keyboard,
                          AsyncTCP,
                          PNGdec,
                          TFT_eSPI

**Environment:**  PlatformIO with VS Code,
                  AutoDesk Fusion360; for 3d Modeling,
                  KiCad; PCB Creation

Pictures of Project Design:
*In Progress*
