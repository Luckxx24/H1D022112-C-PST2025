#include <Arduino.h>
#include <Servo.h>

Servo myservo;

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
  myservo.attach(D3); //nambahin servo
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  waktu = pulseIn(echoPin, HIGH);
  
 
  jarak = waktu*0.034/2;
  
  
  Serial.print("jarak: ");
  Serial.print(jarak);
  Serial.println(" CM");
  
  
  if(jarak >= 14 && jarak <=17 ){ //karena jarak sekitar 15cm maka dibuat perkiraan jarak antara 14-17cm 
    myservo.write(90);
  } else {
    myservo.write(0);
  }
  
  delay(1000);
}