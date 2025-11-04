# 🌡️ Smart Temperature Alert System

An IoT-based project built using **ESP32**, **DHT22**, and **ThingSpeak** to monitor temperature and humidity in real-time with live data visualization through a web dashboard.

---

## 🚀 Features

- 🌤️ Real-time temperature & humidity monitoring  
- ☁️ Automatic data logging to **ThingSpeak Cloud**  
- 📊 Live charts for visualization  
- 💡 LED alert for high temperature threshold  
- 🧠 Built on **Wokwi Simulator** for hardware emulation  

---

## 🛠️ Tech Stack

| Component | Description |
|------------|-------------|
| **ESP32** | Wi-Fi-enabled microcontroller for IoT communication |
| **DHT22 Sensor** | Measures temperature and humidity |
| **ThingSpeak** | Cloud IoT platform for data visualization |
| **HTML, CSS, JS** | Web dashboard displaying real-time values |
| **Wokwi** | Online simulator for ESP32 hardware setup |

---

## ⚙️ System Workflow

1. The **ESP32** reads data from the **DHT22 sensor**.  
2. Sensor readings are sent to **ThingSpeak Cloud**.  
3. Data is visualized as charts on ThingSpeak and mirrored on a custom **HTML dashboard**.  
4. The LED on ESP32 glows when temperature exceeds the threshold.

---

## 🧠 Developer

**👨‍💻 Mukhil Venkatachalam**  
