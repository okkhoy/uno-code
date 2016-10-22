// Using push button
// Making the LED on the board to blink when button is pushed

// Pin 13 on the digital out is connected to the on board LED.
// We make it blink!
// Pin 12 is used as the input now

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  //digitalRead(<pin>); // To read the push button switch.
  // when pressed, it returns HIGH, else it returns LOW

  if(digitalRead(12) == HIGH) {
    digitalWrite(13, HIGH);
    digitalWrite(8, LOW);
    delay(1500);
    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    delay(500);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
  }
  
}
