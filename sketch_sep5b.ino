/*
  Arduino Night Light with 5 LEDs and Timed Light Check

  This program controls 5 LEDs based on the ambient light detected by a photoresistor (LDR).
  The light level is checked periodically (every 20 seconds) to save power and prevent
  frequent state changes.

  Wiring Instructions:
  1.  LEDs: Connect a single 220 Ohm resistor from Digital Pin 2 to the anodes (longer legs)
      of all five LEDs. Connect the cathodes (shorter legs) of all five LEDs to an
      Arduino GND pin.

  2.  LDR (Photoresistor): Connect one leg of the LDR to Arduino's 5V pin. Connect the other
      leg of the LDR to Analog Pin A0. Connect a 10k Ohm resistor from the LDR leg at A0
      to Arduino's GND pin.

  How it Works:
  - The photoresistor's resistance changes with light, which is read by Analog Pin A0.
  - The 'thresholdValue' determines the light level at which the LEDs turn ON or OFF.
    - If 'lightValue' < 'thresholdValue', it's considered dark, and LEDs turn ON.
    - If 'lightValue' >= 'thresholdValue', it's considered light, and LEDs turn OFF.
  - The light check is performed every 'interval' (20 seconds) using 'millis()'
    for non-blocking timing.
  - Serial Monitor output helps in debugging and finding the optimal 'thresholdValue'.
*/

// --- Pin Definitions ---
const int photoresistorPin = A0; // Analog pin connected to the photoresistor
const int ledPin = 2;            // Digital pin connected to all 5 LEDs

// --- Configuration Parameters ---
// Adjust this value based on your room's actual lighting conditions.
// Use the Serial Monitor (Tools > Serial Monitor) to observe 'Light Value' readings
// in both dark and light conditions, then pick a 'thresholdValue' in between.
int thresholdValue = 500; // Default example value; adjust as needed

// --- Timed Check Variables ---
unsigned long previousMillis = 0; // Stores the last time the light check was performed
const long interval = 20000;      // Interval for light check (20 seconds = 20000 milliseconds)

// --- Setup Function ---
void setup() {
  // Initialize serial communication at 9600 baud rate for debugging output.
  Serial.begin(9600);
  Serial.println("Arduino Night Light Initializing...");

  // Set the LED pin as an OUTPUT and ensure it is initially OFF.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Turn off LEDs initially

  // Perform an initial light check immediately when the Arduino starts.
  checkLightAndControlLEDs();
  // Record the current time to start the 20-second interval timer.
  previousMillis = millis();
}

// --- Loop Function ---
void loop() {
  // Get the current time in milliseconds since the Arduino started.
  unsigned long currentMillis = millis();

  // Check if the 'interval' has passed since the last light check.
  // This uses 'millis()' for non-blocking timing.
  if (currentMillis - previousMillis >= interval) {
    // If the interval has passed, update 'previousMillis' to the current time.
    previousMillis = currentMillis;

    // Call the function to read the light sensor and control the LEDs.
    checkLightAndControlLEDs();
  }
}

// --- Custom Function to Read Light and Control LEDs ---
void checkLightAndControlLEDs() {
  // Read the analog value from the photoresistor (0-1023).
  int lightValue = analogRead(photoresistorPin);

  // Print the current light value to the Serial Monitor for observation and debugging.
  Serial.print("Current Light Value: ");
  Serial.println(lightValue);

  // Compare the read light value with the predefined threshold.
  if (lightValue < thresholdValue) {
    // If it's darker than the threshold, turn all LEDs ON.
    digitalWrite(ledPin, HIGH);
    Serial.println("Condition: DARK -> LEDs ON");
  } else {
    // If it's lighter than or equal to the threshold, turn all LEDs OFF.
    digitalWrite(ledPin, LOW);
    Serial.println("Condition: LIGHT -> LEDs OFF");
  }
}
