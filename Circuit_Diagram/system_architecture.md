
# E-Batt Watch – System Architecture

## Hardware Architecture

```text
       12V / 7Ah BATTERY
               |
          INLINE FUSE
               |
            INA226
          /         \
      Voltage      Current
          \         /
             ESP32
          /    |    \
     DS18B20 OLED  Wi-Fi
                   |
               ThingSpeak
                   |
              IoT Dashboard
```

## Communication Interfaces

- INA226: I2C
- OLED: I2C
- DS18B20: One-Wire
- ESP32: Wi-Fi
- ThingSpeak: Cloud monitoring

## Power Supply

12V battery → LM2596 buck converter → regulated 5V → ESP32 VIN.
