int led = D7;

void setup() {
	pinMode(led, OUTPUT);
}

void loop() {
	digitalWrite(led, LOW);  // Added this line
    delayMicroseconds(10); // Added this line
    digitalWrite(led, HIGH);
    delayMicroseconds(10); // Added this line
}