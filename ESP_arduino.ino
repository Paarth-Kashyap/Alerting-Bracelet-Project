int ledPin = 13;
const int buttonPin = 2; // Button connected to pin 2
const int motorPin = 9;  // Vibrating motor connected to pin 9
int buttonState = 0;     // Variable to store button state


void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn on LED
  delay(2000); // Wait for 2 seconds
  digitalWrite(ledPin, LOW); // Turn off LED
  delay(2000); // Wait for 2 seconds
}
