# 💡 ESP32 Intelligent Light Switch

An automated lighting control system that adjusts brightness based on ambient light levels, designed for efficiency and reliability in IoT environments.

## 🚀 Overview
This project uses an **ESP32** and an **LDR (Light Dependent Resistor)** sensor to create a "smart" switch. The system monitors real-time lux levels and triggers a LED when the environment becomes too dark.

## ✨ Key Features
* **Real-time Light Monitoring**: Continuous sampling of ambient light via a 12-bit ADC.
* **Hysteresis Logic**: Implemented two-point thresholding (2500 ON / 1500 OFF) to provide **Noise Immunity** and prevent LED flickering during sunset/sunrise transitions.
* **Hardware-Software Integration**: Demonstrates low-level hardware control using C++ and the Arduino framework.

## 🛠️ Hardware Components
* **Microcontroller**: ESP32 DevKit V1
* **Sensor**: Photoresistor (LDR) Module with Analog Output
* **Output**: Red LED + 220Ω Resistor
* **Platform**: Prototyped using the [**Wokwi**](https://wokwi.com/) simulator.

## 🔌 Circuit Connection (Pinout)
| Component | ESP32 Pin | Connection Type |
| :--- | :--- | :--- |
| LDR AO | GPIO 34 | Analog Input (ADC) |
| LED | GPIO 5 | Digital Output |
| VCC | 3V3 | Power |
| GND | GND | Ground |



## 💻 How to Run
1. Clone this repository.
2. Open the project in **Arduino IDE** or **VS Code (PlatformIO)**.
3. Select the `DOIT ESP32 DEVKIT V1` board.
4. Flash the code and open the **Serial Monitor** at `115200` baud.
* *Alternatively: Open the simulation in [Wokwi](https://wokwi.com/projects/457863159923373057) to run it in your browser.*
