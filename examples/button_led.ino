#include <Arduino.h>

// Define LED and button pins
constexpr uint8_t LED_PIN = 27;
constexpr uint8_t BUTTON_PIN = 4;

void setup() {
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  // Set the button pin as an input with an internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initialize the LED to off
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Read the button state
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Button is pressed, turn the LED on
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Button is not pressed, turn the LED off
    digitalWrite(LED_PIN, LOW);
  }
}
