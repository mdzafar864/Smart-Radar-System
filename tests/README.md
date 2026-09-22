# Tests

This project is hardware-in-the-loop (a servo, an ultrasonic sensor, and a
serial link), so testing is split into two layers:

## 1. Firmware logic tests (host-side, no hardware required)

Pure logic — like the median filter and the buzzer debounce/pitch
selection — can be extracted and unit-tested on a PC using
[PlatformIO's native test runner](https://docs.platformio.org/en/latest/plus/unit-testing.html):

```bash
pio test -e native
```

`test_median_filter.cpp` and `test_buzzer_alert.cpp` are placeholders for
these logic tests — copy the relevant pure functions out of
`firmware/RadarSystem/RadarSystem.ino` into a testable header/source pair as
the firmware grows.

## 2. Visualizer parsing tests (Processing / manual)

`RadarVisualizer.pde`'s `serialEvent()` already guards against null,
malformed, and empty serial data (see the `---- FIX ----` comments in the
source). To manually verify this:

1. Run the visualizer without the Arduino connected — it should print
   "No serial ports found" without crashing.
2. Connect the Arduino, then briefly unplug the USB cable mid-sweep — the
   visualizer should print an error and keep running.

## 3. Hardware smoke test

1. Flash the firmware and open the Arduino IDE Serial Monitor at 9600 baud —
   you should see comma-separated `angle,distance.` pairs streaming as the
   servo sweeps.
2. Wave a hand in front of the sensor at <15 cm, <30 cm, and >40 cm to
   confirm the buzzer pitch changes accordingly.
