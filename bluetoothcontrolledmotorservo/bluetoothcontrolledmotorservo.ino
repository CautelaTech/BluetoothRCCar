//  Demo function:The application method to drive the DC motor.
//  Author:Frankie.Chu
//  Date:20 November, 2012

#include "MotorDriver.h"
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position
int motor = 0;

int bluetoothTx = 2;
int bluetoothRx = 3;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
	/*Configure the motor A to control the wheel at the left side.*/
	/*Configure the motor B to control the wheel at the right side.*/
	motordriver.init();
	motordriver.setSpeed(200,MOTORB);
	motordriver.setSpeed(200,MOTORA);
        myservo.attach(9);  // attaches the servo on pin 9 to the servo object
        //Setup usb serial connection to computer
            Serial.begin(9600);

        //Setup Bluetooth serial connection to android
        bluetooth.begin(115200);
            bluetooth.print("$$$");
          delay(100);
        bluetooth.println("U,9600,N");
        bluetooth.begin(9600);

}
 
void loop()
{
  //Read from bluetooth and write to usb serial 
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    Serial.print(toSend);


    // After the android device sends the data the arduino takes the information and reads it as a char,
    // This code is here to read that data and turn it into actions for the motors.
    if(toSend == 'f'){
      motordriver.goForward();
    } 
    if(toSend == 'b'){
      motordriver.goBackward();
    }
    if (toSend == 's'){
      motordriver.stop();
    }
    if (toSend == 'l')(
     myservo.write(180));

     if (toSend == 'r')(
     myservo.write(0));


     
      
      
    } 

}



