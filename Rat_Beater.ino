#include <Servo.h> 

int ledPin = 10;
int trigPin = 7;
int echoPin = 6;
int servo1Pin = 3;
int servo2Pin = 4;
Servo servoUp;
Servo servoDown;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoUp.attach(servo1Pin);
  servoDown.attach(servo2Pin);
}

void loop() {
  
  servoDown.write(90);
  servoUp.write(0);
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2;

  if (distance <= 25){
    digitalWrite(ledPin, HIGH);
    servoUp.write(90);
    delay(500);
    servoDown.write(0);
    delay(500);
    servoUp.write(0);
    delay(500);
    servoDown.write(90);
  } else {
    digitalWrite(ledPin, LOW);
    servoDown.write(90);
    servoUp.write(0);
  }
  
  delay(200);
}
