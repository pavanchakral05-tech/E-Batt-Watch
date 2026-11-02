
# E-Batt Watch – Project Documentation

## 1. Introduction

E-Batt Watch is an IoT-based Electric Vehicle Battery Monitoring System designed to monitor battery voltage, current and temperature in real time using ESP32 and suitable sensors.

## 2. Objectives

- Monitor battery voltage.
- Measure battery current.
- Monitor battery temperature.
- Display readings on OLED.
- Upload sensor data to ThingSpeak.
- Analyze historical battery parameters.
- Identify abnormal operating conditions.

## 3. Problem Statement

Battery operating conditions are important for the reliable operation of electric vehicles. Manual monitoring makes continuous observation difficult. This project proposes an affordable IoT-based solution for remote battery parameter monitoring.

## 4. Proposed Methodology

1. Connect the 12V, 7Ah battery to the monitoring circuit.
2. Measure voltage and current using INA226.
3. Measure surface temperature using DS18B20.
4. Process sensor data using ESP32.
5. Display readings on OLED.
6. Transmit measurements through Wi-Fi.
7. Visualize historical readings using ThingSpeak.

## 5. Working Principle

The INA226 measures battery voltage and current, while the DS18B20 monitors battery surface temperature. The ESP32 collects the readings and transmits them to the ThingSpeak cloud platform. Users can observe battery operating conditions remotely.

## 6. Applications

- Educational EV battery monitoring.
- Small-scale electric vehicles.
- Battery testing laboratories.
- IoT-based energy monitoring.
- Embedded systems projects.

## 7. Limitations

- Designed for low-voltage educational applications.
- Does not replace a certified Battery Management System.
- Requires Wi-Fi for cloud data transmission.
- Does not directly estimate battery SOH or SOC.

## 8. Future Scope

- Battery State of Charge estimation.
- Battery State of Health analysis.
- Discharge-cycle monitoring.
- Mobile application integration.
- Predictive battery maintenance.
- Advanced BMS integration.

## 9. Conclusion

E-Batt Watch demonstrates the integration of embedded systems and IoT technology for real-time EV battery monitoring. The prototype provides an affordable approach to measuring and visualizing battery voltage, current and temperature.
