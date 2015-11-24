#ifndef _LIMB_h
#define _LIMB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "rServo.h"

const int SIZE = 3;

//Read by the init funciton of the leg and offsets are automatic
extern int offSetList[16];
//Automatic reads in the hard leg limits
extern int rightOffSetList[10];
extern int leftOffSetList[10];

class Limb
{
public:
	//Declare servo address and create rServo objects for leg
	Limb(int address[SIZE]);

	//leg is the movement cure for the class. therfore moving the right leg looks like
	//right.leg(int move[5]);
	void limb(int move[SIZE]);

	//Functions for playing the given routines
	//first element of the array, array end element 
	void routine(int *first, int *last);

	//return leg to all center
	//void center() { leg(int zero[5] = { 0 }); }


	//rServo parts of the leg
	rServo jointOne;
	rServo jointTwo;
	rServo jointThree;

private:

	//Adjust the offsets for the servos. Only accesed at statup.
	//If you want each servo is public so you could ajust them one by one.
	void adjLimb(int adj[SIZE]);

	int _servoAddresses[SIZE];

	bool _isRightLeg;
};

#endif

