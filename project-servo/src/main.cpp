#include <Arduino.h>
#include <Servo.h>


// put function declarations here:

Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(D0);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 /* for (int pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(10);
  }
  for (int pos = 180; pos >= 0; pos--){
    myservo.write(pos);
    delay(10);
   
  } */

  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  
  
}

// put function definitions here:
