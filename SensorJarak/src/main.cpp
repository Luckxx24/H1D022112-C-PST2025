#include <Arduino.h>

int echoPin = D0;
int trigPin = D1;
int ledPin = D2;
long waktu;
int jarak;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Generate ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response time
  waktu = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters
  jarak = waktu*0.034/2;
  
  // Print the distance
  Serial.print("jarak: ");
  Serial.print(jarak);
  Serial.println(" CM");
  
  // Control LED based on distance
  if(jarak <= 10){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(1000);
}