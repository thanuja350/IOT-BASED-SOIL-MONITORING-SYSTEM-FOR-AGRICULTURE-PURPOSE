# 🌱 IoT-Based Soil Monitoring System for Agriculture

This project is an **IoT-based soil monitoring system** designed to assist farmers and gardeners in monitoring soil and environmental conditions.  
It measures **temperature, humidity, soil moisture, light intensity, and soil pH**, then provides feedback on whether certain plants can grow under those conditions.

---

## 🚀 Features
- Monitors:
  - 🌡️ Temperature  
  - 💧 Humidity  
  - 🌱 Soil Moisture  
  - ☀️ Light Intensity  
  - ⚗️ Soil pH  
- Displays data on **16x2 I2C LCD**  
- Serial Monitor output for debugging  
- Decision-making: suggests if specific plants (Tomato, Cactus, Tulip, etc.) can grow  
- Simple and extendable for IoT/cloud integration  

---

## 🛠️ Hardware Requirements
1. **Arduino Uno / Mega / Nano**  
2. **DHT11 / DHT22 sensor** (temperature & humidity)  
3. **Soil Moisture Sensor**  
4. **LDR (Light Dependent Resistor)**  
5. **pH Sensor**  
6. **16x2 LCD Display with I2C module**  
7. Jumper wires, breadboard, power supply  

---

## 💻 Software Requirements
- Arduino IDE  
- Libraries:  
  - `DHT.h` (DHT sensor library)  
  - `Wire.h` (I2C communication)  
  - `LiquidCrystal_I2C.h` (LCD control)  

---

## ⚡ Circuit Connections
- **DHT11** → Digital Pin 2  
- **Soil Moisture Sensor** → A0  
- **LDR** → A1  
- **pH Sensor** → A2  
- **LCD (I2C)** → SDA/SCL pins  

---

## 📜 Code Overview
- Reads values from DHT, Soil Moisture, LDR, and pH sensors  
- Converts sensor data into meaningful values (e.g., °C, %, pH)  
- Displays readings on LCD and Serial Monitor  
- Makes decisions based on pH & soil moisture:  
  - ✅ Tomato can grow  
  - ✅ Cactus can grow  
  - ✅ Tulip can grow  
  - ❌ No suitable plant  

---

## ▶️ Uploading & Running
1. Install required libraries in Arduino IDE.  
2. Connect all hardware as per the circuit.  
3. Copy the code into Arduino IDE and upload to the board.  
4. Open the Serial Monitor (`9600 baud`) to see live readings.  
5. Check LCD for real-time plant growth suggestions.  

---

## 📊 Example Output (Serial Monitor)
