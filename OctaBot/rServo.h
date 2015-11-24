/*
** Base Level Servo control
** r for Robot not to be confused with arduio servo library
*/


#ifndef _RSERVO_h
#define _RSERVO_h

#include <Arduino.h>
#include <C:\Program Files (x86)\Arduino\libraries\Servo\src\Servo.h>

Servo myServo;

class rServo
{
public:
	//Contructor
	rServo();

	//Attach servos no need with the control board but still declares position
	void attach(int ServoNumber);

	//Moves the servo up and down from 0. -90 would is down and 90 is up, all from netrual.
	void move(int pos);
	//Center the servo
	void center() { move(0); }

	//Used to adjust the center of the servo and store that value
	void adjCenter(int r);		
	//Used to set hard limits that the servo should not go past 
	void adjLimit(int min, int max);
	//Inverse the direction of the called servo
	void reverseDirection();

	//Returns the position the servo is moved to given the angle
	int position(int angle);

	
private:
	//Keeps the servo inside the hard limits
	int limitPos(int angle);

	//_variable for class
	short _servoAddress; //Pin number on arduino
	int _servoOffest; //Positive for a positive offSet
	bool _reverseDirection = false;
	int _servoMinPos = -90;
	int _servoMaxPos = 90;
	
};

#endif
