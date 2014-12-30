#include <Servo.h>
 
Servo myservo; // create servo object to control a servo
 
int potpin = A0; // analog pin used to connect the potentiometer
int servopin = 2; // digital pin used for the servo motor
int rotation = 1; // variable to determine the car's steering (0 = left, 1 = ahead, 2 = right)
 
void setup() {
  myservo.attach(servopin); // attaches the servo on pin 2 to the servo object
  myservo.write(90); // align the servo ahead
}
 
void loop() {
  int currentRotation = getRotation( analogRead(potpin) );
 
  // change the car's steering if the steering wheel's rotation has changed
  if (rotation != currentRotation) {
 
    if (currentRotation == 0)
      myservo.write(45); // align the servor left
 
    else if (currentRotation == 1)
      myservo.write(90); // align the servor ahead
 
    else if (currentRotation == 2)
      myservo.write(125); // align the servor right
  }
 
  rotation = currentRotation;
}
 
// check the rotation of the steering wheel
int getRotation(int potentiometerValue) {
  if ( potentiometerValue <= 256 )
    return 0;
 
  else if ( potentiometerValue <= 768 )
    return 1;
 
  else
    return 2;
}
