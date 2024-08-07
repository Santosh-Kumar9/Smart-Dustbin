#include <Servo.h>

int trig = 6;
int echo = A0;
int servo = 9;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myServo.attach(9);
  myServo.write(0);
}

void loop() {
  long duration_us, distance_cm;

  // Trigger the sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Listen for the echo
  duration_us = pulseIn(echo, HIGH);

  // Calculate the distance
  distance_cm = (duration_us/2) / 29.1;

  // Move the servo
  if (distance_cm < 20) {
    myServo.write(90);
    delay(5000);
  } else {
    myServo.write(0); 
  }

  // Print the distance to the serial monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Delay for 500 milliseconds
  delay(500);
}
