#include <Arduino.h>

// Define motor pins
constexpr uint8_t PWM_LEFT = 26;
constexpr uint8_t LEFT1 = 16;
constexpr uint8_t LEFT2 = 17;
constexpr uint8_t PWM_RIGHT = 25;
constexpr uint8_t RIGHT1 = 13;
constexpr uint8_t RIGHT2 = 14;
constexpr uint8_t LED = 27;
constexpr uint8_t START_BUTTON = 4;

const int PWMFreq = 1000; // 1 KHz
const int PWMResolution = 8;
const int MAX_MOTOR_SPEED = 200;

// Function to control motors
void controlMotors(int leftSpeed, int rightSpeed) {
  // Control left motor direction
  if (leftSpeed > 0) {
    digitalWrite(LEFT1, HIGH);
    digitalWrite(LEFT2, LOW);
  } else if (leftSpeed < 0) {
    digitalWrite(LEFT1, LOW);
    digitalWrite(LEFT2, HIGH);
  } else {
    digitalWrite(LEFT1, LOW);
    digitalWrite(LEFT2, LOW);
  }

  // Control right motor direction
  if (rightSpeed > 0) {
    digitalWrite(RIGHT1, HIGH);
    digitalWrite(RIGHT2, LOW);
  } else if (rightSpeed < 0) {
    digitalWrite(RIGHT1, LOW);
    digitalWrite(RIGHT2, HIGH);
  } else {
    digitalWrite(RIGHT1, LOW);
    digitalWrite(RIGHT2, LOW);
  }

  // Set motor speeds
  ledcWrite(0, abs(leftSpeed));
  ledcWrite(1, abs(rightSpeed));
}

void setup() {
  // Set pin modes
  pinMode(PWM_LEFT, OUTPUT);
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(PWM_RIGHT, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(START_BUTTON, INPUT_PULLUP);

  // Set up PWM channels
  ledcSetup(0, PWMFreq, PWMResolution);
  ledcSetup(1, PWMFreq, PWMResolution);
  ledcAttachPin(PWM_LEFT, 0);
  ledcAttachPin(PWM_RIGHT, 1);
}

void loop() {
  // Move forward for 5 seconds
  controlMotors(MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
  delay(5000);

  // Move backward for 5 seconds
  controlMotors(-MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
  delay(5000);

  // Spin (left forward, right backward) for 5 seconds
  controlMotors(MAX_MOTOR_SPEED, -MAX_MOTOR_SPEED);
  delay(5000);

  // Stop motors
  controlMotors(0, 0);
  delay(5000);
}
