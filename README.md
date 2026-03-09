# ESP32 Projects Collection
> ESP32 | IoT | Embedded Systems | C++ / Arduino

## Overview
A collection of mini-projects built on the ESP32 microcontroller, covering Bluetooth, Wi-Fi, sensors, displays, voice recognition, and offline AI. Each folder is a standalone project.

## Projects

| Folder | Description |
|---|---|
| esp-bt-led | Control an LED over Bluetooth from a mobile app |
| esp-clap-switch | Clap-activated switch using sound sensor |
| esp-fire-alert_email | Fire/smoke sensor triggers an email alert via Wi-Fi |
| esp-inbuilt-neopixel | Control the ESP32-S3 onboard NeoPixel LED |
| esp-now-receiver | ESP-NOW wireless receiver node |
| esp-now-sender | ESP-NOW wireless sender node |
| esp-offline-hardcode-chatbot | Offline chatbot with hardcoded responses (no internet needed) |
| esp-shake-dice | Shake to roll a dice using an accelerometer |
| esp-touch-switch | Capacitive touch sensor used as a switch |
| esp-touch_display | Touch input on a connected display |
| esp-voice-recognition | Voice command recognition on the ESP32 |
| esp-webserver | Host a web server on the ESP32 to control GPIO via browser |
| esp32-chatgpt | ChatGPT integration via Wi-Fi API call |

## Hardware
- **Microcontroller**: ESP32 / ESP32-S3
- **IDE**: Arduino IDE or PlatformIO
- **Language**: C++ (Arduino framework)

## Getting Started

### Requirements
- Arduino IDE with ESP32 board support installed
- ESP32 board added via Board Manager: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`

### Running a Project
1. Open the desired project folder in Arduino IDE
2. Select your ESP32 board and COM port
3. Install any required libraries (listed in each project's folder)
4. Upload to the board

## Notes
- Each project is self-contained — no shared dependencies between folders
- Wi-Fi credentials (SSID/password) are hardcoded in relevant sketches — update before uploading
- ESP-NOW projects must be run in pairs (sender + receiver)

## Project Status
Collection actively growing — new ESP32 experiments added regularly.
