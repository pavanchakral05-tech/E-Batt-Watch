
# E-Batt Watch – Circuit Diagram & Wiring

## 1. Hardware Configuration

- Microcontroller: ESP32 DevKit V1
- Battery: 12V, 7Ah
- Voltage and Current Sensor: INA226
- Temperature Sensor: DS18B20
- Display: OLED SSD1306 (0.96 inch)
- Power Supply: LM2596 Buck Converter

## 2. INA226 to ESP32 Connections

| INA226 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

INA226 measures battery voltage and current through its
high-side shunt measurement arrangement.

## 3. DS18B20 to ESP32 Connections

| DS18B20 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

A 4.7kΩ pull-up resistor is connected between DATA and 3.3V.

## 4. OLED to ESP32 Connections

| OLED Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## 5. Battery and Power Supply

- Battery positive passes through an appropriately rated fuse.
- INA226 is connected in series with the battery positive line.
- The DC load is connected after the INA226.
- Battery voltage is supplied to the LM2596 input.
- LM2596 output is adjusted to 5V.
- Regulated 5V powers the ESP32 VIN/5V input.

## 6. Communication

- INA226: I2C
- OLED: I2C
- DS18B20: One-Wire
- ESP32 to ThingSpeak: Wi-Fi

## 7. Safety Precautions

- Verify INA226 shunt rating and calibration.
- Check polarity before powering the circuit.
- Never connect 12V directly to ESP32.
- Use an inline battery fuse.
- Keep the battery separate from the electronics enclosure.
- Use the correct charger and battery protection.
