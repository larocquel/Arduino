# UNO_R3 – Learning to Build a 2WD Smart Car

This repository is organized as a step-by-step path for learning electronics fundamentals first, then building a 2WD Arduino UNO R3 car using:
- Ultrasonic distance sensor
- Infrared sensor(s)

## Goal
Build confidence in circuits (voltage, current, resistors, LEDs, buttons, basic sensor reading) before integrating motors and autonomous behavior.

## Suggested Learning Path

### Phase 1 — Electronics Basics (1–2 weeks)
1. Learn voltage/current/resistance and Ohm's law
2. Practice with breadboard, LED + resistor, button input
3. Read analog values (potentiometer/LDR)
4. Understand pull-up/pull-down resistors

Track your progress in: `docs/electronics-basics-checklist.md`

### Phase 2 — Arduino + Modules (1 week)
1. Test ultrasonic sensor alone
2. Test infrared sensor alone
3. Learn serial debugging and calibration

Track your progress in: `docs/sensors-checklist.md`

### Phase 3 — Motors + Chassis (1 week)
1. Assemble 2WD chassis
2. Wire motor driver + battery + UNO safely
3. Control each motor independently

Track your progress in: `docs/car-assembly-checklist.md`

### Phase 4 — Integration (1–2 weeks)
1. Obstacle avoidance using ultrasonic sensor
2. Line following/object detection with IR sensor
3. Combine movement + sensing logic into one sketch

## Repo Structure

- `docs/` — checklists and build planning
- `sketches/` — Arduino experiments and final car code

## Recommended Folder Convention for Sketches

Create one folder per experiment, for example:

- `sketches/01_led_resistor_test/`
- `sketches/02_button_input/`
- `sketches/10_ultrasonic_test/`
- `sketches/11_infrared_test/`
- `sketches/20_motor_driver_test/`
- `sketches/30_2wd_car_integration/`

## Components Checklist

Core components (typical starter setup):
- Arduino UNO R3 + USB cable
- Breadboard + jumper wires
- LEDs + resistors (220Ω, 1kΩ, 10kΩ)
- Buttons + potentiometer
- Ultrasonic sensor (HC-SR04)
- Infrared sensor module(s)
- 2WD chassis kit (motors, wheels, caster)
- Motor driver (L298N/L293D or equivalent)
- Battery pack suitable for motors

## Safety Notes

- Do **not** power motors directly from UNO 5V pins.
- Share GND between UNO, motor driver, and sensors.
- Disconnect power before rewiring.

## Next Step
Start with `docs/electronics-basics-checklist.md` and complete every item before moving to motor integration.
