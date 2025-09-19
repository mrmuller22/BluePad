// Header File for the Wifi Feature

#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <ESPAsyncWebServer.h>

// Defining Global Variables
extern AsyncWebServer server;
extern bool configMode;

// Function Prototypes
void initWiFi();
void setupWebServer();

#endif
