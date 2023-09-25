#include <SoftwareSerial.h>
#include <Servo.h>
//Create object named esc of the class Servo
Servo esc5;
// Create object named bt of the class SoftwareSerial
SoftwareSerial bt (0,1); // (Rx, Ix)
void setup()
{
  //code for motor
  esc5.attach (5, 900, 2000);
  esc5.writeMicroseconds (900); //initialize the signal to 900
  delay(1000);
//code for bluetooth communication
  bt.begin(9600);
  Serial.begin(9600);
}
void loop()
{
  int val; //creating a variable for data from bluetooth input
  if (bt.available()) //if data is available from bluetooth device
  {
    val = bt.read(); //data received to be put in variable val (int)
    //val is restricted to the value from 0-1023
    val= map (val, 48, 60, 1000, 2000); //mapping val to minimum and maximum
    esc5.writeMicroseconds (val);
    delay (2000);
  }
}