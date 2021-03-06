/* AIone.h - Library for AIone robot
 * Author:Mijaz Mukundan(mijazm.app@gmail.com)
 * Licence: MIT licence,A copy is provided in the library root folder
 * DATE:Saturday 20 February 2016
 */

#ifndef AIone_h
#define AIone_h

#include "Arduino.h"
 
class MotorDrive{
  
  int _motor_left[2];
  int _motor_right[2];
  int _enable_pin_left;
  int _enable_pin_right;

public:

   void leftMotor(int left_0,int left_1,int enable_pin,int speed);
   void rightMotor(int right_0,int right_1,int enable_pin,int speed);
   void driveForward();
   void driveBackward();
   void turnLeft();
   void turnRight();
   void stopMotor();
   void setSpeed(int speed);
 
};

class SingleMotorDrive{
  
  int _motor[2];
  int _enable_pin;


public:

   SingleMotorDrive(int left_0,int left_1,int enable_pin,int speed);
   void driveForward();
   void driveBackward();
   void stopMotor();
   void setSpeed(int speed);

 
};

#endif

