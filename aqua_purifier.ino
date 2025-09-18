// Project: IoT-Based Aqua Water Purifier with Level Control
// This code manages a water pump for a purification system based on water levels
// in an input (raw water) container and an output (purified water) container.
// It's designed for an Arduino Nano.

// --- Pin Definitions ---
// Digital pin to control the motor driver/relay for the water pump.
// IMPORTANT: Connect your motor to a motor driver (e.g., L298N, relay module, MOSFET).
// DO NOT connect the motor directly to the Arduino pin, as it can draw too much current.
const int motorControlPin = 2;

// Digital pin for the water level sensor in the input (raw water) container.
// This sensor should be placed at the desired "start pumping" level.
// It is assumed to output HIGH when water is at or above this level.
const int inputLevelPin = 3;

// Digital pin for the water level sensor in the output (purified water) container.
// This sensor should be placed near the top of the output container.
// It is assumed to output HIGH when the container is NOT yet full (i.e., there's space).
// If your sensor outputs LOW when full, adjust the logic in the loop() function.
const int outputLevelPin = 4;

// An optional LED to visually indicate when the pump is running.
// Connect with a current-limiting resistor (e.g., 220 Ohm) to GND.
const int statusLedPin = 13; // Often the built-in LED on Arduino boards

// --- Setup Function ---
// This function runs once when the Arduino board starts up or is reset.
void setup() {
  // Set the pin modes for all connected components.
  // motorControlPin is an OUTPUT to send control signals to the motor driver.
  pinMode(motorControlPin, OUTPUT);
  // inputLevelPin and outputLevelPin are INPUTs to read sensor states.
  pinMode(inputLevelPin, INPUT);
  pinMode(outputLevelPin, INPUT);
  // statusLedPin is an OUTPUT to control the LED.
  pinMode(statusLedPin, OUTPUT);

  // Ensure the motor and status LED are off when the Arduino starts.
  digitalWrite(motorControlPin, LOW);
  digitalWrite(statusLedPin, LOW);

  // Initialize serial communication for debugging and status messages.
  Serial.begin(9600); // Sets the baud rate for serial communication.
  Serial.println("Water Purifier System Initialized.");
  Serial.println("Monitoring water levels and controlling pump.");
}

// --- Loop Function ---
// This function runs repeatedly as long as the Arduino is powered.
void loop() {
  // Read the current state of the water level sensors.
  // digitalRead() returns HIGH (1) or LOW (0).
  int inputLevelState = digitalRead(inputLevelPin);
  int outputLevelState = digitalRead(outputLevelPin);

  // --- Pumping Logic ---
  // The water pump should run ONLY if both of these conditions are true:
  // 1. The input container has water (enough to start pumping).
  // 2. The output container is NOT yet full (there's space to pump into).
  if (inputLevelState == HIGH && outputLevelState == HIGH) {
    // Both conditions are met: input has water AND output has space.
    // So, turn the pump ON.
    if (digitalRead(motorControlPin) == LOW) { // Check if pump is currently OFF to avoid redundant messages
      Serial.println("Input water level sufficient, output not full. Pumping started.");
    }
    digitalWrite(motorControlPin, HIGH); // Turn the motor ON
    digitalWrite(statusLedPin, HIGH);    // Turn the status LED ON
  } else {
    // If either condition is NOT met, the pump should be OFF.
    if (digitalRead(motorControlPin) == HIGH) { // Check if pump is currently ON to avoid redundant messages
      if (inputLevelState == LOW) {
        Serial.println("Input container is empty. Pumping stopped.");
      }
      if (outputLevelState == LOW) {
        Serial.println("Output container is full. Pumping stopped.");
      }
      Serial.println("Pumping stopped.");
    }
    digitalWrite(motorControlPin, LOW); // Turn the motor OFF
    digitalWrite(statusLedPin, LOW);    // Turn the status LED OFF
  }

  // Small delay to prevent the loop from running too fast.
  // This helps stabilize sensor readings and serial output, and reduces CPU usage.
  delay(500); // Wait for 500 milliseconds before the next loop iteration.
}
