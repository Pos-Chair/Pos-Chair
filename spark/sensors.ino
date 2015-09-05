int backL = A0;
int backR = A1;
int seatL = A2;
int seatM = A3;
int seatR = A4;
double bl,br,sl,sm,sr;

void setup() {
    pinMode(backL, INPUT);
	pinMode(backR, INPUT);
	pinMode(seatL, INPUT);
	pinMode(seatM, INPUT);
	pinMode(seatR, INPUT);
	Spark.variable("backL", &bl, DOUBLE);
	Spark.variable("backR", &br, DOUBLE);
	Spark.variable("seatL", &sl, DOUBLE);
	Spark.variable("seatM", &sm, DOUBLE);
	Spark.variable("seatR", &sr, DOUBLE);
}

void loop() {
	bl = analogRead(backL);
	br = analogRead(backR);
	sl = analogRead(seatL);
	sm = analogRead(seatM);
	sr = analogRead(seatR);
}