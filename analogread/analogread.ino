// Analog read
// we print the values of the ldr on console for this one

// we use designated pins indicated by variables.

int ledPin = 9;
int ldrPin = 10;
int digitalInputSwitch = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(digitalInputSwitch, INPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Current value is \n");// %f", analogRead(ldrPin));
  
}

