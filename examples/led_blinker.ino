#include <Arduino.h>

// Define LED pin
constexpr uint8_t LED_PIN = 27;

void setup() {
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Initialize the LED to off
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  // Wait for 1 second
  delay(1000);

  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  // Wait for 1 second
  delay(1000);
}
