# BluePad
This repository showcases my personal project the BluePad v1.1. Inspired by the Stream Deck and to have easy access to shortcuts for my Computer.

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

**Pictures of Project Design:**
<br>
**Schematic:**
<img width="1185" height="741" alt="Screenshot 2025-10-27 202051" src="https://github.com/user-attachments/assets/8d0503db-6c63-4cea-907c-16c1000e8b07" />

**Circuit Board:**
<br>
 Front:
<img width="3933" height="2230" alt="touchpad pcb pictures-1" src="https://github.com/user-attachments/assets/b88deffe-b39b-4a6b-88e2-94427f681392" />

 Back:
<img width="4015" height="2198" alt="touchpad pcb pictures-2" src="https://github.com/user-attachments/assets/0a83060f-f7cc-4bf1-a634-b4b0354e5243" />

Cad Model:
<img width="1049" height="716" alt="touchpadCadFile" src="https://github.com/user-attachments/assets/e90ae437-38f1-45c1-8503-37ef6e4af867" />

Finished Product:
![IMG_0307](https://github.com/user-attachments/assets/5fd05b62-6ec9-4fe9-b3cb-414815326d14)

# Come Back for V2!

