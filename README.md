# 📡 Smart Radar System

An Arduino-based ultrasonic radar system that scans its surroundings with a servo-mounted HC-SR04 sensor, streams live distance data over serial, and renders it as a real-time sweeping radar display using Processing. A buzzer gives audible proximity alerts for detected objects.

![Platform](https://img.shields.io/badge/platform-Arduino-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/visualizer-Processing-1a1a1a?logo=processing&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)
![Build](https://img.shields.io/badge/build-PlatformIO-orange?logo=platformio)

---

## ✨ Features

- 180° sweep scanning using a servo motor
- Distance measurement via HC-SR04 ultrasonic sensor
- Noise-filtered readings (median of 3 samples per angle)
- Debounced buzzer alerts with distance-based pitch (close / near / in-range)
- Live radar-style visualization in Processing (classic green sweep display)
- Auto-detects the Arduino's serial port (Linux `ttyACM`/`ttyUSB`, with fallback)

---

## 🎥 Demo

See [`video/demo-link.md`]( https://youtube.com/shorts/AxBbinlzzF8?si=7KXWETVOZmPvtYAb ) for the demo video.

<p align="center">
  <em>Add a photo or GIF of your build/visualizer here: <code>docs/images/</code></em>
</p>

---

## 📂 Repository Structure

```
Smart-Radar/
├── docs/                       # Documentation & images
│   ├── images/
│   └── wiring/                 # Wiring diagram / schematic (see roadmap)
├── firmware/                   # Arduino firmware
│   ├── RadarSystem/
│   │   └── v1.0.0/
│   │       └── RadarSystem.ino       # Sensor, servo & buzzer logic
│   └── RadarVisualizer/
│       └── v1.0.0/
│           └── RadarVisualizer.pde   # Processing sketch: live radar display
├── hardware/                   # Bill of materials, wiring & assembly notes
│   └── README.md
├── software/
│   └── RadarVisualizer.pde     # Visualizer source (mirrors firmware/RadarVisualizer)
├── src/
│   └── RadarSystem.ino         # Firmware source (mirrors firmware/RadarSystem)
├── tests/                      # Firmware logic & visualizer tests
│   ├── README.md
│   └── test_median_filter.cpp
├── video/
│   └── demo-link.md            # Link to the demo video
├── CHANGELOG.md
├── CITATION.cff
├── CONTRIBUTING.md
├── LICENSE
├── platformio.ini              # PlatformIO build config for the firmware
├── README.md
└── SECURITY.md
```

---

## 🧰 Hardware Required

See [`hardware/README.md`](hardware/README.md) for the full bill of materials and wiring table.

| Component              | Qty |
|-------------------------|-----|
| Arduino Uno / Nano      | 1   |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 Servo Motor        | 1   |
| Buzzer                  | 1   |
| Jumper wires            | —   |
| Breadboard / mount      | 1   |

---

## 🚀 Getting Started

### 1. Flash the firmware

**Option A — PlatformIO (recommended):**
```bash
pio run -e uno            # build
pio run -e uno -t upload  # flash
```

**Option B — Arduino IDE:**
1. Open `firmware/RadarSystem/v1.0.0/RadarSystem.ino`.
2. Install the **Servo** library (bundled with the IDE by default).
3. Select your board and port, then upload.

### 2. Run the visualizer
1. Install [Processing](https://processing.org/download).
2. Open `firmware/RadarVisualizer/v1.0.0/RadarVisualizer.pde`.
3. Make sure the `Serial` library is available (built-in).
4. Run the sketch — it auto-detects the Arduino's serial port. If it picks the wrong one, check the console output and hardcode `portName` manually.
5. Close the Arduino IDE's Serial Monitor first — only one program can hold the port at a time.

---

## ⚙️ Configuration

Key tunables live at the top of `firmware/RadarSystem/v1.0.0/RadarSystem.ino`:

| Constant           | Default | Description                              |
|--------------------|---------|-------------------------------------------|
| `ALERT_RANGE_CM`    | 40      | Max distance the buzzer/visualizer reacts to |
| `CLOSE_CM`          | 15      | Below this → fast/high-pitch beep         |
| `NEAR_CM`           | 30      | Below this → medium beep                  |
| `DEBOUNCE_COUNT`    | 2       | Consecutive close readings before alerting |

---

## 🧪 Testing

See [`tests/README.md`](tests/README.md) for the firmware logic test setup and manual hardware/visualizer smoke tests.

---

## 🗺️ Roadmap

- [ ] Add wiring diagram / Fritzing schematic to `hardware/`
- [ ] Support configurable sweep range and speed
- [ ] Log detections to file for later analysis
- [ ] Add native PlatformIO unit tests for the median filter and buzzer logic

---

## 🤝 Contributing

See [`CONTRIBUTING.md`](CONTRIBUTING.md). Issues and pull requests are welcome — for major changes, please open an issue first to discuss what you'd like to change.

## 🔒 Security

See [`SECURITY.md`](SECURITY.md) for how to report issues.

## 📄 Citation

If you use this project in your own work, please cite it — see [`CITATION.cff`](CITATION.cff).

## 📄 License

Distributed under the MIT License. See [`LICENSE`](LICENSE) for details.

## 📝 Changelog

See [`CHANGELOG.md`](CHANGELOG.md) for release history.
