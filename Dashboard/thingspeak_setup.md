
# E-Batt Watch – ThingSpeak IoT Dashboard

## 1. Overview

E-Batt Watch uses the ThingSpeak IoT cloud platform to monitor battery parameters remotely.

The ESP32 collects sensor readings and transmits them through Wi-Fi to ThingSpeak.

## 2. Platform

- IoT Platform: ThingSpeak
- Controller: ESP32
- Communication: Wi-Fi
- Update Interval: 20 seconds

Website: https://thingspeak.mathworks.com/

## 3. Channel Configuration

Channel Name: E-Batt Watch

| Field | Parameter | Unit |
|---|---|---|
| Field 1 | Battery Voltage | V |
| Field 2 | Battery Current | A |
| Field 3 | Battery Temperature | °C |

## 4. Data Transmission

The ESP32 sends the following measurements:

1. Battery voltage using INA226.
2. Battery current using INA226.
3. Battery temperature using DS18B20.

The ThingSpeak library uploads the readings using the channel Write API Key.

## 5. Dashboard Visualization

The dashboard contains three graphs:

- Battery Voltage vs Time
- Battery Current vs Time
- Battery Temperature vs Time

## 6. Monitoring Features

- Remote battery monitoring.
- Historical data visualization.
- Voltage variation analysis.
- Current variation analysis.
- Temperature monitoring.

## 7. Security

- Keep the Write API Key private.
- Never publish Wi-Fi credentials.
- Do not upload secrets.h to a public repository.
- Regenerate exposed API keys.

## 8. Expected Result

The ThingSpeak dashboard provides online visualization and historical storage of battery voltage, current and temperature measurements.
