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
  // Constrain speeds to max limits
  leftSpeed = constrain(leftSpeed, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
  rightSpeed = constrain(rightSpeed, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);

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
  ledcWrite(PWM_LEFT, abs(leftSpeed));
  ledcWrite(PWM_RIGHT, abs(rightSpeed));
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
  ledcAttach(PWM_LEFT, PWMFreq, PWMResolution);
  ledcAttach(PWM_RIGHT, PWMFreq, PWMResolution);
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
