/* AIone.h - Library for AIone robot
 * Author:Mijaz Mukundan
 */

#ifndef AIone_h
#define AIone_h

#include "Arduino.h"
 
class MotorDrive{
  
  int _motor_left[2];
  int _motor_right[2];

public:

   void leftMotor(int left_0,int left_1);
   void rightMotor(int right_0,int right_1);
   void driveForward();
   void driveBackward();
   void turnLeft();
   void turnRight();
   void stopMotor();
 
};

class SingleMotorDrive{
  
  int _motor[2];


public:

   SingleMotorDrive(int left_0,int left_1);
   void driveForward();
   void driveBackward();
   void stopMotor();

 
};

#endif

