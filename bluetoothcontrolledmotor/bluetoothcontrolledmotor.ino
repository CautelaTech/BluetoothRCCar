#include "MotorDriver.h"
#include <Wire.h>
#include <SoftwareSerial.h>

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

}


}
