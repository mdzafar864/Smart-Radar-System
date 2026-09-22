# Contributing to Smart Radar

Thanks for your interest in improving this project! Contributions of all
sizes — bug reports, docs fixes, new features — are welcome.

## Before You Start

For anything beyond a small fix, please open an issue first to discuss what
you'd like to change. This avoids duplicate work and helps align on
approach before you invest time in a pull request.

## Development Setup

### Firmware (Arduino)
1. Install [PlatformIO](https://platformio.org/) (CLI or the VS Code extension), or use the Arduino IDE directly.
2. With PlatformIO: `pio run -e uno` to build, `pio run -e uno -t upload` to flash.
3. With Arduino IDE: open `firmware/RadarSystem/RadarSystem.ino`, install the **Servo** library, select your board/port, and upload.

### Visualizer (Processing)
1. Install [Processing](https://processing.org/download).
2. Open `src/RadarVisualizer/RadarVisualizer.pde` and run it with the board connected.

## Making Changes

1. Fork the repo and create a branch from `main`:
   `git checkout -b feature/short-description`
2. Keep commits focused and write clear commit messages.
3. Update `docs/` if your change affects wiring, configuration, or usage.
4. Add or update tests in `tests/` where applicable.
5. Update `CHANGELOG.md` under an `[Unreleased]` section.

## Pull Requests

1. Ensure the firmware builds (`pio run`) and the visualizer runs without errors.
2. Describe **what** changed and **why** in the PR description.
3. Link any related issues.
4. Be responsive to review feedback — small follow-up commits are fine.

## Code Style

- Firmware: standard Arduino/C++ conventions, descriptive constant names, comments for non-obvious logic.
- Processing: keep drawing functions (`drawRadar`, `drawLine`, `drawObject`, `drawText`) focused on a single responsibility.

## Reporting Bugs

Open an issue with:
- Hardware used (board, sensor, servo)
- Steps to reproduce
- Expected vs. actual behavior
- Serial monitor output or a screenshot of the visualizer, if relevant

## Code of Conduct

Be respectful and constructive. Harassment or discriminatory language will
not be tolerated.
