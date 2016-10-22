// Analog write
// making the LED go on a wave using a for loop

// we use designated pins indicated by variables.

int ledPin = 9;
int digitalInputSwitch = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(digitalInputSwitch, INPUT);
}

void loop() {
  if(digitalRead(digitalInputSwitch) == HIGH) {
    for(int i = 0; i < 250; i+= 5) {
      analogWrite(ledPin, i);
      delay(25); // need to wait to see the effect
    }
  } else {
    analogWrite(ledPin,0);
  }
  
}

