int leftSeat = A0;
int rightSeat = A1;
int backbonePin = A3;
double cm, left, right;

void setup() {
    pinMode(leftSeat, INPUT);
	pinMode(rightSeat, INPUT);
	pinMode(backbonePin, INPUT);
	Spark.variable("left", &left, DOUBLE);
	Spark.variable("right", &right, DOUBLE);
	Spark.variable("cm", &cm, DOUBLE);
}

void loop() {
	left = analogRead(leftSeat);
	right = analogRead(rightSeat);
	cm = analogRead(backbonePin);
	delay(400);
}