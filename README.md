<div align="center">
  <img src="https://github.com/larocquel/Arduino/blob/fe871e484d31df125b23e78e442d746bb24b400c/documents/banner_arduino.png" alt="42 Projects Banner" width="100%" />
</div>

<br>

# Arduino UNO R3: From Blink to Autonomous Car

A structured, beginner-friendly learning journey to build and program a 2WD robot car using an Arduino UNO R3 starter kit. This repository documents every step of the progression — from blinking a single LED to building a fully autonomous obstacle-avoiding and line-following robot.

> **Philosophy:** Before wheels spin, we learn how the Arduino "talks" to components. Each phase builds directly on the last, so no step is skipped.

---

## Creator

<div align="left">
  <a href="https://github.com/larocquel">
    <img src="https://avatars.githubusercontent.com/larocquel?size=100" width="100">
  </a>
  <br><br>
  <b><a href="https://github.com/larocquel">Leonardo La Rocque</a></b>
</div>

---

## Content

- [About the Project](#about-the-project)
- [Hardware & Components](#hardware--components)
- [Software Requirements](#software-requirements)
- [Repository Structure](#repository-structure)
- [Learning Progression](#learning-progression)
  - [Phase 1 — Electronics Basics](#phase-1--electronics-basics-the-hello-world)
  - [Phase 2 — Robot Senses (Sensors)](#phase-2--robot-senses-sensors)
  - [Phase 3 — Robot Muscles (Motors & L298N)](#phase-3--robot-muscles-motors--l298n)
  - [Phase 4 — Assembly & Integration](#phase-4--assembly--integration)
  - [Phase 5 — Autonomy (The Final Challenge)](#phase-5--autonomy-the-final-challenge)
- [Wiring Diagrams](#wiring-diagrams)
- [How to Upload Code](#how-to-upload-code)
- [Contributing](#contributing)
- [License](#license)

---

## About the Project

This project is a personal learning log and codebase for building a 2WD robot car from scratch using an Arduino UNO R3 starter kit. It is aimed at absolute beginners who want a clear, step-by-step path — from understanding basic electronics to writing autonomous robot behavior.

Each folder in this repository corresponds to a step in the progression plan below, containing the sketch (`.ino` file), any relevant wiring notes, and a short description of what was learned.

---

## Hardware & Components

| Component | Description |
|---|---|
| Arduino UNO R3 | The main microcontroller board |
| L298N Motor Driver Module | Drives the two DC motors (the Arduino alone can't power them) |
| 2× DC Gear Motors | The "muscles" — one per side |
| 2× Wheels + 1× Caster Wheel | 2WD chassis movement |
| Acrylic / Wood / Metal Chassis | The car's frame |
| HC-SR04 Ultrasonic Sensor (Grove) | Detects distance to obstacles (the robot's "eyes") |
| IR Sensor Module(s) | Detects black/white surfaces for line following |
| Breadboard | For prototyping circuits without soldering |
| LEDs (Red, Yellow, Green) | Used in early learning steps |
| Resistors (220Ω – 1kΩ) | Protect LEDs and other components from excess current |
| Push Button | Digital input device |
| Dupont Jumper Wires (M-M, M-F) | Connect components together |
| Battery Holder + Batteries | Powers the motors via the L298N |
| USB Type-B Cable | Uploads code from computer to Arduino |

---

## Software Requirements

- **Arduino IDE** (v1.8.x or v2.x) — [Download here](https://www.arduino.cc/en/software)
- **USB Drivers** — Usually installed automatically; on Linux (Ubuntu), you may need to add your user to the `dialout` group:
  ```bash
  sudo usermod -a -G dialout $USER
  ```
  Then log out and back in.
- **Libraries** (install via Arduino IDE → Sketch → Include Library → Manage Libraries):
  - `NewPing` — for the HC-SR04 ultrasonic sensor (optional but recommended)

---

## Repository Structure

```
arduino-2wd-robot/
│
├── 1_basics
│   ├── 1_builtin_led
│   ├── 2_external_led
│   ├── 3_button_input
│   ├── 4_traffic_light
│   └── 5_interactive_traffic_light
├── 2_sensors
│   ├── 4_ultrasonic_sensor
│   └── 5_ir_sensor
├── 3_motors
│   ├── 6_l298n_intro
│   ├── 7_single_motor
│   └── 8_speed_control_pwm
├── 4_assembly
│   ├── 10_wiring
│   ├── 11_movement_blocks
│   └── 9_physical_assembly
├── 5_autonomy
│   ├── 12_obstacle_avoidance
│   └── 13_line_follower
├── documents
└── README.md
```

---

## Learning Progression

### Phase 1 — Electronics Basics: The "Hello World"

> Before the wheels turn, we need to understand how the Arduino communicates with components.

---

#### Step 1 — Built-in LED Blink

**Goal:** Upload the very first piece of code. Make the small LED already soldered onto the Arduino board blink, confirming the computer can successfully send code to the board.

**Concepts:** `setup()`, `loop()`, `digitalWrite()`, `delay()`, `OUTPUT`

---

#### Step 2 — Breadboard, External LEDs & Resistors

**Goal:** Take the components out of the box. Learn how to use the breadboard to connect an external LED. Understand why resistors are essential to prevent burning out components.

**Concepts:** Breadboard layout (rails, rows), Ohm's Law basics, current limiting resistors

---

#### Step 3 — Digital Input (Push Button)

**Goal:** Instead of the Arduino only *sending* power (Output), teach it to *read* power (Input). Use a button to toggle an LED on and off. Introduction to the **Serial Monitor** — the Arduino sends text messages back to the computer screen.

**Concepts:** `INPUT_PULLUP`, `digitalRead()`, `Serial.begin()`, `Serial.println()`

---

#### Step 4 — Traffic Light (Multiple LEDs)

**Goal:** Connect Red, Yellow, and Green LEDs (each with its own resistor) and program the timed traffic light sequence: Green on → wait → off; Yellow on → wait → off; Red on → wait → off.

**Concepts:** Multiple digital outputs, timing logic, clean code organization

---

#### Step 5 — Interactive Traffic Light

**Goal:** Combine Steps 3 and 4. The light stays green for cars, but when someone presses the button, the code triggers the yellow → red sequence so pedestrians can cross.

**Concepts:** Combining inputs and outputs, event-driven logic, real-world simulation

---

### Phase 2 — Robot Senses (Sensors)

> Now we test the "advanced" components individually.

---

#### Step 4 — Ultrasonic Sensor (HC-SR04 / Grove Module)

**Goal:** Connect the sensor (which looks like two little "eyes") and program the Arduino to measure the distance to an object on the desk. This is how the robot will avoid walls later.

**Concepts:** `pulseIn()`, time-to-distance conversion, `NewPing` library, Serial Monitor output

---

#### Step 5 — Infrared (IR) Sensor

**Goal:** Connect the IR sensor module and observe how it reacts when pointed at a white surface versus a black surface. This is the foundation for line following.

**Concepts:** Analog vs digital IR output, surface reflectivity, threshold calibration

---

### Phase 3 — Robot Muscles (Motors & L298N)

> Things start moving here! The Arduino alone doesn't have enough electrical power to drive motors — that's why we need the L298N module.

---

#### Step 6 — Understanding the L298N

**Goal:** Identify each terminal on the L298N: where battery power enters, where motors connect, and where the Arduino control pins plug in.

**Concepts:** H-bridge topology, power separation (logic vs motor power), pin mapping

---

#### Step 7 — Spin a Motor

**Goal:** Write code to make one motor spin forward, stop, and then spin in reverse.

**Concepts:** `digitalWrite()` on L298N IN pins, motor direction control

---

#### Step 8 — Speed Control (PWM)

**Goal:** Learn to make the motor spin slower or faster using PWM (Pulse Width Modulation).

**Concepts:** `analogWrite()`, PWM pins on Arduino UNO (~), duty cycle, `analogWrite(ENA, 0–255)`

---

### Phase 4 — Assembly & Integration

> The mechanical and engineering phase — the robot is born!

---

#### Step 9 — Physical Assembly

**Goal:** Assemble the acrylic (or wood/metal) chassis: screw in the motors, attach the wheels, and mount the battery holder.

**Notes:** Take photos at each stage! They're useful for troubleshooting and for this repository.

---

#### Step 10 — Full Wiring

**Goal:** Mount the Arduino and L298N on top of the car and make all final connections using Dupont jumper wires (M-M).

> ⚠️ **Double-check polarity before connecting the battery. Reversed polarity can damage the L298N and motors.**

---

#### Step 11 — Movement Blocks (Basic Choreography)

**Goal:** Create clean, reusable code functions for each direction: `moveForward()`, `moveBackward()`, `turnLeft()`, `turnRight()`, `stopMotors()`. Test each one.

**Concepts:** Functions/subroutines, code reusability, timing-based turns

---

### Phase 5 — Autonomy (The Final Challenge)

> Give intelligence to the car by combining everything learned so far.

---

#### Step 12 — Obstacle-Avoiding Robot

**Goal:** The car drives on its own, uses the ultrasonic sensor to detect a wall, stops, turns, and continues exploring the environment.

**Logic:**
```
loop:
  measure distance
  if distance < threshold → stop → turn → continue
  else → move forward
```

---

#### Step 13 — Line-Following Robot

**Goal:** Use the IR sensors to follow a track made of black electrical tape on the floor.

**Logic:**
```
if left_sensor = black AND right_sensor = black → forward
if left_sensor = black AND right_sensor = white → turn right
if left_sensor = white AND right_sensor = black → turn left
if left_sensor = white AND right_sensor = white → stop (end of line)
```

---

## Wiring Diagrams

Diagrams for each phase are stored in the `/diagrams` folder. Tools used:
- [Fritzing](https://fritzing.org/) for breadboard-style diagrams
- Photos of physical setups

---

## How to Upload Code

1. Open the `.ino` file for the relevant step in **Arduino IDE**.
2. Connect the Arduino UNO to your computer via USB.
3. Go to **Tools → Board** and select `Arduino UNO`.
4. Go to **Tools → Port** and select the correct port (e.g., `/dev/ttyACM0` on Linux).
5. Click the **Upload** button (→).
6. Open **Tools → Serial Monitor** (baud rate: `9600`) to view debug messages where applicable.

---

## Contributing

This is a personal learning project, but suggestions, corrections, and improvements are welcome! Feel free to open an **Issue** or submit a **Pull Request**.

---

## License

This project is licensed under the [MIT License](LICENSE) — feel free to use, adapt, and share.

---

*Happy building!*
