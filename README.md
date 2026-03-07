# 💡 ESP32 Intelligent Light Switch

An automated lighting control system designed for efficiency and reliability. The system intelligently adjusts LED brightness based on ambient light levels, solving the common problem of flickering in simple sensor-based switches.

---

## 📋 Table of Contents
- [Overview](#-overview)
- [Key Features](#-key-features)
- [Hardware Configuration](#-hardware-configuration)
- [Technical Implementation](#-technical-implementation)
- [How to Run](#-how-to-run)

---

## 🚀 Overview
This project utilizes an **ESP32** and an **LDR (Light Dependent Resistor)** to create a smart lighting solution. Unlike standard "on/off" controllers, this system mimics modern smart-home devices by providing smooth transitions and environmental awareness.

## ✨ Key Features
- **Real-time Monitoring**: Continuous 12-bit ADC sampling of ambient light.
- **Hysteresis Logic**: Dual-threshold system (2500 ON / 1500 OFF) to ensure **Noise Immunity**.
- **Adaptive Brightness**: PWM-based dimming for natural light transitions.
- **Industrial Standards**: Implementation of "deadbands" to extend hardware lifespan.

## 🛠️ Hardware Configuration

### Components
- **MCU**: ESP32 DevKit V1
- **Sensor**: LDR Module (Analog Output)
- **Output**: Red LED + 220Ω Resistor
- **Platform**: Prototyped in [Wokwi](https://wokwi.com/)

### Pinout Mapping
| Component | ESP32 Pin | Mode | Description |
| :--- | :--- | :--- | :--- |
| **LDR AO** | GPIO 34 | ADC | Analog light level input |
| **LED** | GPIO 5 | PWM | Adaptive brightness output |
| **VCC** | 3V3 | Power | 3.3V Supply |
| **GND** | GND | Ground | Common Ground |

---

## ⚙️ Technical Implementation

### Signal Transformation & Mapping
To provide a seamless experience, the raw sensor data is mapped to an 8-bit PWM signal. This allows the LED to increase its intensity as the room gets darker.

The transition follows this linear mapping logic:
$$f(x) = \text{constrain}\left(\text{map}(x, 2500, 4095, 0, 255), 0, 255\right)$$

- **x**: Raw ADC value ($0$ - $4095$)
- **Lower Bound (2500)**: LED starts at 0% brightness.
- **Upper Bound (4095)**: LED reaches 100% brightness ($255$).

### Hysteresis (Noise Immunity)
To prevent "flickering" when the light level is exactly at the threshold, the system uses a **Hysteresis Loop**. The light will only turn on when it gets darker than 2500, but will not turn off until the level drops below 1500. This mimics the behavior of professional industrial thermostats and sensors.

---

## 💻 How to Run

1. **Clone the repository**:
   ```bash
   git clone [https://github.com/Kubuzer/esp32-intelligent-light-switch](https://github.com/Kubuzer/esp32-intelligent-light-switch)
