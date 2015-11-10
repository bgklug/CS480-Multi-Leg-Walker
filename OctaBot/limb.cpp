// 
// 
// 

#include "limb.h"

//Initializing call. Get offsets, limits, addresses.
//Also inverts direction of the servos that need it.
Limb::Limb(int address[5] , bool rightL)
{
	//set the Right leg status
	_isRightLeg = rightL;

	int limitTemp[10];
	
	//Get the servo array adress
	copy(_servoAddresses, _servoAddresses + SERVOS/2, address);

	//copy the limit positions of the servos
	if (rightL) 
	{
		copy(limitTemp, limitTemp + SERVOS, rightOffSetList);
	}
	else {
		copy(limitTemp, limitTemp + SERVOS, leftOffSetList);
	}
	

	/*
	for (int i = 0; i < 5; i++) {
		//Declare servo in order of foot to hip.
		servoAddresses[i] = address[i];
	}	
	
	for (int i = 0; i < 10; i++) {
		//create limit array
		if (_isRightLeg) {
			limitTemp[i] = rightOffSetList[i];
		}
		else {
			limitTemp[i] = leftOffSetList[i];
		}
	}
	*/
	//Initalize the parts of the leg foot to hip again
	ankle.attach(_servoAddresses[0], offSetList[_servoAddresses[0]],limitTemp[0],limitTemp[1]);
	shin.attach(_servoAddresses[1], offSetList[_servoAddresses[1]], limitTemp[2], limitTemp[3]);
	knee.attach(_servoAddresses[2], offSetList[_servoAddresses[2]], limitTemp[4], limitTemp[5]);
	thigh.attach(_servoAddresses[3], offSetList[_servoAddresses[3]], limitTemp[6], limitTemp[7]);
	hip.attach(_servoAddresses[4], offSetList[_servoAddresses[4]], limitTemp[8], limitTemp[9]);



	//inverts the servos conditionaly on the leg
	if (_isRightLeg)
	{
		ankle.reverseDirection();
		shin.reverseDirection();
		knee.reverseDirection();
	}
	else {
		thigh.reverseDirection();
		hip.reverseDirection();
	}


}


void Leg::leg(int move[5])
{
	ankle.move(move[0]);
	shin.move(move[1]);
	knee.move(move[2]);
	thigh.move(move[3]);
	hip.move(move[4]);
	
}

void Leg::adjLeg(int adj[5])
{
	ankle.adjCenter(adj[1]);
	shin.adjCenter(adj[2]);
	knee.adjCenter(adj[3]);
	thigh.adjCenter(adj[4]);
	hip.adjCenter(adj[5]);
}
