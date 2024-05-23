# 🚀 KitLab

<img align="left" src="https://github.com/RAS-IEEE-Universidad-de-Guanajuato/KitLab/assets/84588180/e64f0dec-2b29-4dd2-8158-4d3a021f3979" width="100">

Welcome to the KitLab repository! This kit provides everything you need to get started with building and programming a simple two-wheel robot using an ESP32 microcontroller. Perfect for students and hobbyists alike, this kit helps you explore the basics of robotics.

---

## 📦 Contents of the Kit

- **ESP32 Development Board**: The brain of the robot.
- **H-Bridge Motor Driver**: For controlling the direction and speed of the motors.
- **Two DC Motors**: To drive the wheels.
- **Wheels**: For the motors.
- **Chassis**: To hold everything together.
- **Push Button**: For user input.
- **LED**: For visual feedback.

## 📝 Repository Contents

This repository includes various example codes to help you get started:

1. **LED Blinker**: A simple LED blinking example.
2. **Button and LED**: Understand how to interact with a push button and control an LED.
3. **Basic Motor Control**: Learn how to control the motors.

## 📖 How to Use

1. **Set Up Your Kit**: Assemble the hardware components according to the provided instructions.
2. **Connect the ESP32**: Ensure all connections match the pinout diagram.
3. **Upload the Code**: Use the Arduino IDE to upload the example codes to your ESP32.

### Pinout Diagram

<p align="center">
  <img width="600" src="https://github.com/RAS-IEEE-Universidad-de-Guanajuato/KitLab/assets/84588180/c453041f-ed3d-412f-99be-b922f5d6133d">
</p>

- **PWM_LEFT (26)**: Left PWM pin
- **LEFT1 (16)**: Left Motor Direction Pin 1
- **LEFT2 (17)**: Left Motor Direction Pin 2
- **PWM_RIGHT (25)**: Right PWM pin
- **RIGHT1 (13)**: Right Motor Direction Pin 1
- **RIGHT2 (14)**: Right Motor Direction Pin 2
- **LED (27)**: LED pin
- **START_BUTTON (4)**: Start button pin

#### Open Pins

We've also left room for open pins for any additional uses you may need. The following pins are free to use:

- **GPIO 12**
- **GPIO 32**
- **GPIO 33**
- **GPIO 34**
- **GPIO 35**
