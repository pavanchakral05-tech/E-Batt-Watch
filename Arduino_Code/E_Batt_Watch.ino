
/*
  ==========================================
             E-BATT WATCH
  IoT-Based EV Battery Monitoring System
  ==========================================

  Controller  : ESP32 DevKit V1
  Battery     : 12V, 7Ah
  Voltage     : INA226
  Current     : INA226
  Temperature : DS18B20
  Display     : OLED SSD1306
  IoT Cloud   : ThingSpeak
*/

#include <WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <INA226_WE.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "secrets.h"

// ========== PIN CONFIGURATION ==========

#define SDA_PIN 21
#define SCL_PIN 22
#define TEMP_PIN 4

#define INA226_ADDRESS 0x40
#define OLED_ADDRESS 0x3C

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// ========== SENSOR OBJECTS ==========

INA226_WE ina226(INA226_ADDRESS);

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

WiFiClient client;

// ========== SENSOR CALIBRATION ==========

// Verify these values against your actual INA226 board.
const float SHUNT_RESISTANCE = 0.1;
const float MAX_CURRENT = 3.2;

// ========== TIMING ==========

const unsigned long READ_INTERVAL = 1000;
const unsigned long UPLOAD_INTERVAL = 20000;

unsigned long lastRead = 0;
unsigned long lastUpload = 0;

// ========== BATTERY DATA ==========

float voltage = 0.0;
float current = 0.0;
float temperature = 0.0;

bool temperatureValid = false;

// ========== WIFI CONNECTION ==========

void connectWiFi() {

  if (WiFi.status() == WL_CONNECTED) {
    return;
  }

  Serial.println("Connecting to WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - startTime < 15000) {

    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("\nWiFi Connected!");

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

  } else {

    Serial.println("\nWiFi Connection Failed!");
  }
}

// ========== INA226 INITIALIZATION ==========

void initializeINA226() {

  if (!ina226.init()) {

    Serial.println("ERROR: INA226 not detected!");

    while (true) {
      delay(1000);
    }
  }

  ina226.setResistorRange(
    SHUNT_RESISTANCE,
    MAX_CURRENT
  );

  Serial.println("INA226 Initialized!");
}

// ========== SENSOR INITIALIZATION ==========

void initializeSensors() {

  tempSensor.begin();

  Serial.println("DS18B20 Initialized!");

  if (!display.begin(
      SSD1306_SWITCHCAPVCC,
      OLED_ADDRESS)) {

    Serial.println("ERROR: OLED not detected!");

    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("E-BATT WATCH");
  display.println("System Starting...");
  display.display();

  Serial.println("OLED Initialized!");
}

// ========== READ BATTERY PARAMETERS ==========

void readBatteryData() {

  voltage = ina226.getBusVoltage_V();

  current = ina226.getCurrent_mA() / 1000.0;

  // Retain the signed current reading.
  // Confirm its direction during testing.

  tempSensor.requestTemperatures();

  float measuredTemp = tempSensor.getTempCByIndex(0);

  temperatureValid =
    measuredTemp != DEVICE_DISCONNECTED_C &&
    measuredTemp >= -55.0 &&
    measuredTemp <= 125.0;

  if (temperatureValid) {
    temperature = measuredTemp;
  }

  Serial.println("\n===== E-BATT WATCH =====");

  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current, 3);
  Serial.println(" A");

  Serial.print("Temperature: ");

  if (temperatureValid) {
    Serial.print(temperature, 1);
    Serial.println(" C");
  } else {
    Serial.println("Sensor Error");
  }

  Serial.println("========================");
}

// ========== OLED DISPLAY ==========

void updateDisplay() {

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("E-BATT WATCH");

  display.drawLine(0, 11, 128, 11, SSD1306_WHITE);

  display.setCursor(0, 18);
  display.print("Voltage: ");
  display.print(voltage, 2);
  display.println(" V");

  display.setCursor(0, 31);
  display.print("Current: ");
  display.print(current, 3);
  display.println(" A");

  display.setCursor(0, 44);
  display.print("Temp: ");

  if (temperatureValid) {
    display.print(temperature, 1);
    display.println(" C");
  } else {
    display.println("Sensor Error");
  }

  display.setCursor(0, 57);

  if (WiFi.status() == WL_CONNECTED) {
    display.print("WiFi: Connected");
  } else {
    display.print("WiFi: Offline");
  }

  display.display();
}

// ========== THINGSPEAK CLOUD UPLOAD ==========

void uploadToThingSpeak() {

  if (!temperatureValid) {

    Serial.println("Upload skipped: Invalid temperature");

    return;
  }

  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  if (WiFi.status() != WL_CONNECTED) {

    Serial.println("Upload failed: WiFi unavailable");

    return;
  }

  ThingSpeak.setField(1, voltage);
  ThingSpeak.setField(2, current);
  ThingSpeak.setField(3, temperature);

  int response = ThingSpeak.writeFields(
    CHANNEL_ID,
    WRITE_API_KEY
  );

  if (response == 200) {

    Serial.println("ThingSpeak Upload Successful!");

  } else {

    Serial.print("ThingSpeak Error: ");
    Serial.println(response);
  }
}

// ========== SETUP ==========

void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println("\nStarting E-Batt Watch...");

  Wire.begin(SDA_PIN, SCL_PIN);

  initializeINA226();

  initializeSensors();

  connectWiFi();

  ThingSpeak.begin(client);

  Serial.println("\nE-Batt Watch Ready!");
}

// ========== MAIN LOOP ==========

void loop() {

  unsigned long currentMillis = millis();

  // Read sensors every second.

  if (currentMillis - lastRead >= READ_INTERVAL) {

    lastRead = currentMillis;

    readBatteryData();

    updateDisplay();
  }

  // Upload data every 20 seconds.

  if (currentMillis - lastUpload >= UPLOAD_INTERVAL) {

    lastUpload = currentMillis;

    uploadToThingSpeak();
  }
}
