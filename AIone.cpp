/* AIone.cpp - Library for AIone robot
 * Author:Mijaz Mukundan(mijazm.app@gmail.com)
 * Licence: MIT licence,A copy is provided in the library root folder
 * DATE:Saturday 20 February 2016
 */

#include "Arduino.h"
#include "AIone.h"

/*
 * Functions for SingleMotorDrive class
 */

//constructor for initalizing
SingleMotorDrive::SingleMotorDrive(int motor_0,int motor_1,int enable_pin,int speed=255)
{
   pinMode(motor_0,OUTPUT);
   pinMode(motor_1,OUTPUT);
   pinMode(enable_pin,OUTPUT);
   
  _motor[0] = motor_0;
  _motor[1] = motor_1;
  _enable_pin = enable_pin;
  
  speed=(speed<0)?0:speed;
  speed=(speed>255)?255:speed;

  analogWrite(_enable_pin,speed);
}

//function for driving forward
void SingleMotorDrive::driveForward()
{
  digitalWrite(_motor[0], HIGH); 
  digitalWrite(_motor[1], LOW); 
}

//function for driving backward
void SingleMotorDrive::driveBackward()
{
  digitalWrite(_motor[0], LOW); 
  digitalWrite(_motor[1], HIGH); 
  
}

//function for stopping motor
void SingleMotorDrive::stopMotor()
{
  digitalWrite(_motor[0], LOW); 
  digitalWrite(_motor[1], LOW); 
  delay(25);
}

//function for setting speed dynamically
void SingleMotorDrive::setSpeed(int speed)
{
  speed=(speed<0)?0:speed;
  speed=(speed>255)?255:speed;	
  
  analogWrite(_enable_pin,speed);
}


/*
 * Functions for MotorDrive class
 */

//for initializing pin for left motor
void MotorDrive::leftMotor(int left_0,int left_1,int enable_pin,int speed=255)
{
  pinMode(left_0,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(enable_pin,OUTPUT);
  
  _enable_pin_left = enable_pin;
  _motor_left[0] = left_0;
  _motor_left[1] = left_1;
  
  speed=(speed<0)?0:speed;
  speed=(speed>255)?255:speed;

  analogWrite(_enable_pin_left,speed);
}

//for initiallizing pin for right motor
void MotorDrive::rightMotor(int right_0,int right_1,int enable_pin,int speed)
{
  pinMode(right_0,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(enable_pin,OUTPUT);
  
  _motor_right[0] = right_0;
  _motor_right[1] = right_1;
  _enable_pin_right = enable_pin;

  speed=(speed<0)?0:speed;
  speed=(speed>255)?255:speed;

  analogWrite(_enable_pin_right,speed);
}

//for driving motor in forward direction
void MotorDrive::driveForward()
{ 
  digitalWrite(_motor_left[0], HIGH); 
  digitalWrite(_motor_left[1], LOW); 

  digitalWrite(_motor_right[0], HIGH); 
  digitalWrite(_motor_right[1], LOW); 
}

//for driving motor in backward direction
void MotorDrive::driveBackward()
{
  digitalWrite(_motor_left[0], LOW); 
  digitalWrite(_motor_left[1], HIGH); 

  digitalWrite(_motor_right[0], LOW); 
  digitalWrite(_motor_right[1], HIGH); 
  
}

//for turning left

void MotorDrive::turnLeft()
{
  digitalWrite(_motor_left[0], LOW); 
  digitalWrite(_motor_left[1], HIGH); 

  digitalWrite(_motor_right[0], HIGH); 
  digitalWrite(_motor_right[1], LOW);
}

//for turning right

void MotorDrive::turnRight()
{
  digitalWrite(_motor_left[0], HIGH); 
  digitalWrite(_motor_left[1], LOW); 

  digitalWrite(_motor_right[0], LOW); 
  digitalWrite(_motor_right[1], HIGH); 
}

//to stop the motor

void MotorDrive::stopMotor()
{
  digitalWrite(_motor_left[0], LOW); 
  digitalWrite(_motor_left[1], LOW); 

  digitalWrite(_motor_right[0], LOW); 
  digitalWrite(_motor_right[1], LOW);
  delay(25);
}

//to set speed dynamically
void MotorDrive::setSpeed(int speed)
{
	  speed=(speed<0)?0:speed;
          speed=(speed>255)?255:speed;
           
          analogWrite(_enable_pin_left,speed);
          analogWrite(_enable_pin_right,speed);
}

