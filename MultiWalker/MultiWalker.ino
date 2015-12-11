#include <Servo.h>

class Leg
{
public:
  // ctor
  Leg(){}

  /*void up();
  void down();
  void rotate(int angle);
  */
 

  void activate(int hipPin, int thighPin, int footPin, char hOff, char tOff, char fOff){
    hip.attach(hipPin);
    thigh.attach(thighPin);
    foot.attach(footPin);
    hipOffset = hOff;
    thighOffset = tOff;
    footOffset = fOff;
    footPos = foot.read();
    thighPos = thigh.read();
    hipPos = hip.read();
    //stand();
    moveHip(90);
    moveThigh(90);
    moveFoot(90);
  
  }
  // Member Functions
   void move(int a, int b, int c)
  {
    hip.write(a+(int)hipOffset);
    thigh.write(b+(int)thighOffset);
    foot.write(c+(int)footOffset);
  }

  void moveHip(char pos){
    
    int var = (int) pos + (int) hipOffset;
    hip.write(var);
    delay(5);
    /*
    if((hipPos) < pos){
      for(hipPos; (hipPos) < pos; ++hipPos)
      {
        hip.write(hipPos+hipOffset);
        //delay(15);
      }
    }else{
      for(hipPos; (hipPos) > pos; --hipPos)
      {
        hip.write(hipPos+hipOffset);
        //delay(15);
      }
    }*/
  }

  void moveThigh(char pos){
    int var = (int) pos + (int) thighOffset;
    thigh.write(var);
    delay(5);
    /*
    if((thighPos) < pos){
      for(thighPos; (thighPos) < pos; ++thighPos)
      {
        thigh.write(thighPos+thighOffset);
        delay(1);
      }
    }else{
      for(thighPos; (thighPos) > pos; --thighPos)
      {
        thigh.write(thighPos+thighOffset);
       delay(1);
      }
    }*/
  }

  void moveFoot(char pos){
    int var = (int) pos + (int)footOffset;
    foot.write(var);
    delay(50);
    /*
    if((footPos) < pos){
      for(footPos; (footPos) < pos; ++footPos)
      {
        foot.write(footPos+footOffset);
        delay(1);
      }
    }else{
      for(footPos; (footPos) > pos; --footPos)
      {
        foot.write(footPos+footOffset);
        delay(1);
      }
    }*/
  }  
  
  void wave(){
    for(int i = 0; i < 180; ++i)
    {
      thigh.write(i);
      foot.write(i);
      delay(50);
    }
    for(int i = 0; i < 180; ++i)
    {
      thigh.write(180 - i);
      foot.write(180 - i);
      delay(20);
    }
    for(int i = 0; i < 70; ++i)
    {
      thigh.write(i);
      foot.write(i);
      delay(20);
    }
  }

  // Sends legs to high standing
  // hip = 90
  // thigh = 30
  // foot = 70
  void stand(){
      move(90,30,90);
     Serial.println("standing");
     delay(50);
  }

  // Sends legs to low crouch position
  // hip = 90
  // thigh = ??
  // foot = ??
  void crouch(){
     move(90,150,180);
     Serial.println("crouching");
     delay(50);
  }

  // Private Data Members
private:
  char hipOffset;
  char thighOffset;
  char footOffset;
  char footPos;
  char hipPos;
  char thighPos;
  Servo hip;
  Servo thigh;
  Servo foot;
};

Leg legOne;
Leg legTwo;
Leg legThree;
Leg legFour;
Leg legFive;
Leg legSix;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Set up");
  legOne.activate(13,10,9,0,19,0);
  legTwo.activate(8,7,6,-10,2,-24);
  legThree.activate(5,4,3,-10,9,-21);
  legFour.activate(26,28,30,12,0,-4);
  legFive.activate(18,19,20,-12,15,-9);
  legSix.activate(15,16,17,10,7,-3);

 

  
  Serial.println("Setup Complete");
}

void loop() {
  
  Serial.println("Leg one and two standing");
  legOne.stand();
  legTwo.stand();
  //delay(2000);
  Serial.println("Leg three and four standing");
  legThree.stand();
  legFour.stand();
  //delay(2000);
  Serial.println("Leg five and six standing");
  legFive.stand();
  legSix.stand();
  delay(2000);
  Serial.println("Leg one and two crouching");
  legOne.crouch();
  legTwo.crouch();
  //delay(2000);
  Serial.println("Leg three and four crouching");
  legThree.crouch();
  legFour.crouch();
  //delay(2000);
  Serial.println("Leg five and six crouching");
  legFive.crouch();
  legSix.crouch();
  delay(2000);
  
// legOne.move(90,30,90);
// Serial.println("standing");
// delay(2000);
// legOne.move(90,150,180);
// Serial.println("croushing");
// delay(2000);
}

/*
void step(int angle)
{
	//lifts three legs
	legOne.up();
	legThree.up();
	legFive.up();

	//rotate the down legs in the direction
	legTwo.rotate(angle);
	legFour.rotate(angle);
	legSix.rotate(angle);

	//Brings the up legs back down
	legOne.down();
	legThree.down();
	legFive.down();

	//REPAT THE ABOVE BUT FOR THE OTHER LEGS
	//lifts three legs
	legTwo.up();
	legFour.up();
	legSix.up();

	//rotate the down legs in the direction
	legOne.rotate(angle);
	legThree.rotate(angle);
	legFive.rotate(angle);

	//Brings the up legs back down
	legTwo.down();
	legFour.down();
	legSix.down();
}



//Servo hip;
//Servo thigh;
//Servo foot;

void Leg::up()
{
	//Dont know these angles ATM
	//Pleasre adjust for a good amount of clearance;
	int thighLift = 50;
	int footLift = 50;

	thigh.write(thighLift);
	foot.write(footLift);
	
}

void Leg::down()
{
	//This should be whatever the home position of the servo is
	int thighNetural = 50;
	int footNetural = 50;

	thigh.write(thighNetural);
	foot.write(footNetural);
}
 
void Leg::rotate(int angle)
{
	hip.write(angle);
}*/
