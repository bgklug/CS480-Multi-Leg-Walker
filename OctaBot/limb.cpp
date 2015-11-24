// 
// 
// 

#include "limb.h"
#include <algorithm>

//Initializing call. Get offsets, limits, addresses.
//Also inverts direction of the servos that need it.
Limb::Limb(int address[SIZE])
{

	int limitTemp[SIZE*2];
	
	//Get the servo array adress
	copy(_servoAddresses, _servoAddresses + SERVOS/2, address);
	

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
	jointOne.attach(_servoAddresses[0]);
	jointTwo.attach(_servoAddresses[1]);
	jointThree.attach(_servoAddresses[2]);



}


void Limb::limb(int move[5])
{
	jointOne.move(move[0]);
	jointTwo.move(move[1]);
	jointThree.move(move[2]);
	
}

void Limb::adjLimb(int adj[5])
{
	jointOne.adjCenter(adj[1]);
	jointTwo.adjCenter(adj[2]);
	jointThree.adjCenter(adj[3]);
}
