# 🔋 E-Batt Watch
### IoT-Based Electric Vehicle Battery Monitoring System

![ESP32](https://img.shields.io/badge/Controller-ESP32-blue)
![IoT](https://img.shields.io/badge/Platform-ThingSpeak-green)
![Language](https://img.shields.io/badge/Language-Embedded%20C%2B%2B-orange)
![Battery](https://img.shields.io/badge/Battery-12V%207Ah-yellow)
![Status](https://img.shields.io/badge/Status-Under%20Development-blue)

## 📌 Project Overview

E-Batt Watch is an IoT-based Electric Vehicle (EV) Battery Monitoring System designed to monitor battery voltage, current, and temperature in real time.

The system uses an ESP32 microcontroller integrated with an INA226 voltage and current sensor and a DS18B20 temperature sensor. The collected data is processed by the ESP32 and transmitted to the ThingSpeak IoT cloud platform through Wi-Fi.

The system provides real-time battery parameter monitoring, local visualization through an OLED display, and historical data analysis through an online dashboard.

## 🎯 Project Objectives

- Monitor battery voltage in real time.
- Measure battery charging and discharging current.
- Monitor battery surface temperature.
- Display battery readings on an OLED.
- Transmit sensor data to ThingSpeak.
- Enable remote battery monitoring.
- Identify abnormal operating conditions.

## ⚙️ Hardware Components

| Component | Specification |
|---|---|
| Microcontroller | ESP32 DevKit V1 |
| Battery | 12V, 7Ah |
| Voltage Sensor | INA226 |
| Current Sensor | INA226 |
| Temperature Sensor | DS18B20 |
| Display | OLED SSD1306 0.96" |
| Power Supply | LM2596 Buck Converter |
| IoT Platform | ThingSpeak |

## 🧠 Working Principle

1. The battery supplies power to the connected DC load.
2. INA226 measures battery voltage and current.
3. DS18B20 measures battery surface temperature.
4. ESP32 collects and processes sensor readings.
5. OLED displays the measured parameters.
6. Wi-Fi transmits data to ThingSpeak.
7. ThingSpeak stores and visualizes historical readings.

## 🏗️ System Architecture

```text
       12V / 7Ah BATTERY
               |
            INA226
          /         \
      Voltage      Current
          \         /
             ESP32
               |
           DS18B20
               |
          OLED Display
               |
             Wi-Fi
               |
          ThingSpeak
               |
         IoT Dashboard
```

## 🔌 Circuit Connections

| Sensor | ESP32 Pin |
|---|---|
| INA226 SDA | GPIO 21 |
| INA226 SCL | GPIO 22 |
| INA226 VCC | 3.3V |
| INA226 GND | GND |
| DS18B20 DATA | GPIO 4 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |

A 4.7kΩ pull-up resistor is used for DS18B20 DATA.

## ☁️ ThingSpeak Dashboard

The system transmits three battery parameters:

| Field | Parameter | Unit |
|---|---|---|
| Field 1 | Battery Voltage | V |
| Field 2 | Battery Current | A |
| Field 3 | Battery Temperature | °C |

Dashboard: https://thingspeak.mathworks.com/

## 💻 Software Requirements

- Arduino IDE
- Embedded C/C++
- ESP32 Board Package
- ThingSpeak IoT Platform

### Libraries

- INA226_WE
- OneWire
- DallasTemperature
- ThingSpeak
- Adafruit GFX
- Adafruit SSD1306

## 📂 Repository Structure

```text
E-Batt-Watch/
│
├── README.md
├── LICENSE
│
├── Arduino_Code/
│   └── E_Batt_Watch.ino
│
├── Circuit_Diagram/
│   └── circuit_notes.md
│
├── Hardware/
│   └── components.md
│
├── Dashboard/
│   └── thingspeak_setup.md
│
└── Documentation/
    └── project_details.md
```

## 💰 Estimated Project Cost

| Description | Cost |
|---|---:|
| ESP32 and Sensors | ₹800 |
| Display and Power Supply | ₹230 |
| Battery | ₹1,100 |
| PCB and Wiring | ₹300 |
| Enclosure and Fabrication | ₹250 |
| Protection and Testing | ₹210 |
| Miscellaneous | ₹105 |
| **Total** | **₹2,995** |

*Estimated prices; actual costs may vary.*

## 🚀 Future Scope

- Battery State of Charge (SOC) estimation.
- Battery State of Health (SOH) analysis.
- Discharge-cycle monitoring.
- Mobile application integration.
- Predictive battery maintenance.
- Advanced BMS integration.

## ⚠️ Safety Note

This is an educational battery-monitoring prototype and does not replace a certified Battery Management System (BMS) or battery protection circuit.

## 📄 License

This project is distributed under the MIT License.

## 👨‍💻 Project Information

**Project:** E-Batt Watch  
**Domain:** Embedded Systems and IoT  
**Controller:** ESP32  
**Programming:** Embedded C/C++  
**Cloud:** ThingSpeak  
**Battery:** 12V, 7Ah

---

⭐ If you find this project interesting, consider starring this repository!

**E-Batt Watch – Smart Monitoring for Smarter Electric Mobility.**
