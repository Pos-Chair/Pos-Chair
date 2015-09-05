int leftSeat = A0;
int rightSeat = A1;
int trigPin = D3;
int echoPin = D2;
int led = D7;
double left, right;
volatile bool echo_flag = false;
unsigned long start = 0;
volatile unsigned long duration = 0;
char s[30];

void setup() {
    pinMode(leftSeat, INPUT);
	pinMode(rightSeat, INPUT);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(led, OUTPUT);
	Spark.variable("left", &left, DOUBLE);
	Spark.variable("right", &right, DOUBLE);
	attachInterrupt(echoPin, pub, RISING);
}

void loop() {
	left = analogRead(leftSeat);
	right = analogRead(rightSeat);
	digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); // Added this line
    if(echo_flag) {
        sprintf(s, "Duration is %0.2f ms", duration);
	    Spark.publish("Duration Event",s);
	    echo_flag = false;
    }
	digitalWrite(led, LOW);
    start = millis();
}

void pub(){
    digitalWrite(led, HIGH);
    echo_flag = true;
    volatile unsigned long end = millis();
    duration = end - start;
}