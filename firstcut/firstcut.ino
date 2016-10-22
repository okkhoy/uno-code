// The hello world! of IOT.
// making the LED on the board to blink

// Pin 13 on the digital out is connected to the on board LED.
// We make it blink!

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}
