# Changelog

All notable changes to this project are documented in this file.

The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project follows [Semantic Versioning](https://semver.org/).

## [Unreleased]
### Added
- Professional repository structure (`hardware/`, `src/`, `tests/`, `video/`).
- `platformio.ini` for building the firmware outside the Arduino IDE.
- `CONTRIBUTING.md`, `SECURITY.md`, and `CITATION.cff`.

### Changed
- Visualizer source moved from `software/RadarVisualizer` to `src/RadarVisualizer`.
- Firmware moved from `firmware/v1.0.0/RadarSystem.ino` to `firmware/RadarSystem/RadarSystem.ino`.

## [1.0.0] - 2026-09-22
### Added
- Initial release: Arduino firmware for servo-mounted HC-SR04 ultrasonic scanning.
- Median-of-3 noise filtering for stable distance readings.
- Debounced buzzer alerts with distance-based pitch (close / near / in-range).
- Processing-based real-time radar sweep visualizer with auto serial port detection.
- MIT License and initial README.
