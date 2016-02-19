
/*
 * This Example program uses AIone Libray to control a single motor using Arduino and L293D chip
 * 
 * This program can be used to check if the connections made are correct. 
 * 
 * The "AIone library" is made specifically for the AIone robot, however the user can
 * use the code for any project involving motor driving using L293D chip.
 */
#include <AIone.h>//this is the header file for AIone library

SingleMotorDrive motor(7,8);//This object is used to control a SINGLE motor by defining the control pins of arduino
                            //you can control as motors as you like by 
                           //defining more objects of SingleMotorDrive class

                          //if you want to conrol a two wheel drive used in robotics ,use MotorDrive class
                          //(see "MultiMotorDrive" in examples)
void setup() {
  
  Serial.begin(9600);//begin serial communication
}

void loop() {

Serial.println("Driving forward");
motor.driveForward();// use this function to move both motors forward
delay(2000);
motor.stopMotor();//use this to stop the motors

Serial.println("Driving backward");
motor.driveBackward();//use this function to move both motors backwards
delay(2000);
motor.stopMotor();

}
