# Hardware

## Bill of Materials

| Component                 | Qty | Notes                          |
|----------------------------|-----|---------------------------------|
| Arduino Uno / Nano          | 1   | Any 5V AVR board works          |
| HC-SR04 Ultrasonic Sensor   | 1   |                                  |
| SG90 Servo Motor            | 1   | Mounts the sensor for sweeping  |
| Buzzer (active)             | 1   |                                  |
| Jumper wires                | —   |                                  |
| Breadboard / mount          | 1   | For prototyping or final mount  |

## Wiring

| Arduino Pin | Component            |
|-------------|------------------------|
| 4           | HC-SR04 `TRIG`         |
| 5           | HC-SR04 `ECHO`         |
| 8           | Buzzer (+)             |
| 10          | Servo signal           |
| 5V / GND    | Sensor & servo power   |

> A wiring diagram / Fritzing schematic can be added here as
> `hardware/wiring-diagram.png` (see roadmap in the main README).

## Assembly Notes

- Mount the HC-SR04 on the servo horn so it sweeps with the servo.
- Keep servo and sensor power on the 5V rail; if using multiple servos or a
  higher-torque motor, power the servo from a separate 5V supply with a
  shared ground to avoid brownouts resetting the Arduino.
- The buzzer can be driven directly from a digital pin (as wired above) for
  a small piezo buzzer; use a transistor driver for higher-current buzzers.
