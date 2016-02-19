
/*
 * This Example program uses AIone Libray to control two motors using Arduino and L293D chip
 * 
 * This program can be used to check if the connections made are correct and to accertain that 
 * all manuvers namely going forward/backward,turning left/right are working properly. 
 * 
 * The "AIone library" is made specifically for the AIone robot, however the user can
 * use the code for any project involving motor driving using L293D chip.
 */

#include <AIone.h> //this is the header file for AIone library

MotorDrive motor; //This object is used to control TWO motors
                  //you can control as many pairs of motor as you like by 
                  //defining more objects of MotorDrive class

                  //if you want to conrol a single motor only, use SingleMotor class
                  //(see "SingleMotorDrive" in examples)

void setup() {
  Serial.begin(9600);      //open the serial port for communication
  
  motor.leftMotor(7,8);   //assign the pins used to control the LEFT motor
 
  motor.rightMotor(14,16);//assign the pins used to control the RIGHT motor
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

Serial.println("Turning Left");
motor.turnLeft();//use this funcion to turn your robot left(NOT available for SingleMotor class)
delay(1000);
motor.stopMotor();

Serial.println("Turning Right");
motor.turnRight();//use this funcion to turn your robot right(NOT available for SingleMotor class)
delay(1000);
motor.stopMotor();

/*NOTE: if you see that the wheels of the robot are not turning correctly 
 * (going left instead of right,forward instead of backward etc) try changing
 * the connection of motor made to the l293d chip
 */
}
