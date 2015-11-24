#include "limb.h"
#include "rServo.h"

using namespace std;


//Makes the servo line up better 
int offSetList[16] = { -6,7,-6,4,0,5,6,7,8,9,10,2,-2,-2,-9,-9 };

//{footMin, footMax, shinMin, shingMax, ....., hipMin, hipMax}
int hardLegLimits[5 * 2] = { -25, 15, -40, 80, -40, 80, -40, 80, -15, 70 };

int rightOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };
int leftOffSetList[10] = { -25, 15, -40, 80, -80, 45, -40, 80, -15, 70 };

//Useful for setting leg to center
int ZERO_A[5] = { 0 };


//Leg is init. leg moves the servoes
int limbAddress[3] = { 13, 10, 9 };


Limb limb(limbAddress);

void setup() {

	//Lets me know the code has started
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH); //LED pin

}

void loop() 
{
	
}
