int backL = A0;
int backR = A1;
int seatL = A2;
int seatR = A3;
double bl,br,sl,sr;

void setup() {
    pinMode(backL, INPUT);
	pinMode(backR, INPUT);
	pinMode(seatL, INPUT);
	pinMode(seatR, INPUT);
	Spark.variable("backL", &bl, DOUBLE);
	Spark.variable("backR", &br, DOUBLE);
	Spark.variable("seatL", &sl, DOUBLE);
	Spark.variable("seatR", &sr, DOUBLE);
}

void loop() {
	bl = analogRead(backL);
	br = analogRead(backR);
	sl = analogRead(seatL);
	sr = analogRead(seatR);
}