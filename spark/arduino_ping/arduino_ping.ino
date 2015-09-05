#include <SoftwareSerial.h>
#include <String.h>

#define trigPin 9
#define echoPin 5

SoftwareSerial ser(0,1);

char s[10];

void setup() {
  Serial.begin (9600);
  ser.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  double duration, distance;
  float maxDis = 30.00;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance >= maxDis || distance <= 0){
    ser.write(-1);
  }
  else {
    char *c = (char *) &distance;
    strncpy(s, c, 8);
    s[8] = '!';
    s[9] = '\0';
    ser.write(s);
    Serial.println(distance);
    Serial.println(s);
  }
  delay(400);
}
