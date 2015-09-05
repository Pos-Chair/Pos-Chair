#define trigPin 9
#define echoPin 5
#define corePin A0

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(corePin, OUTPUT);
}

void loop() {
  double duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    analogWrite(corePin, -1);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    analogWrite(corePin, distance*100); //in 0.1 mm
  }
  delay(200);
}
