#include <Servo.h>

class Leg
{
public:
  // ctor
  Leg(){}

  void up();
  void down();
  void rotate(int angle);

  void move(int a, int b, int c)
  {
	  hip.write(a);
	  thigh.write(b);
	  foot.write(c);
  }

  void activate(int hipPin, int thighPin, int footPin){
    hip.attach(hipPin);
    thigh.attach(thighPin);
    foot.attach(footPin);
    hip.write(90);
    delay(200);
    thigh.write(90);
    delay(200);
    foot.write(90);
    delay(200);
  }
  // Member Functions
  void wave(){
    for(int i = 0; i < 180; ++i)
    {
      thigh.write(i);
      foot.write(i);
      delay(20);
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
  // thigh = 0
  // foot = 70
  void stand(){
    char hipStart = hip.read();
    char footStart = foot.read();
    char thighStart = thigh.read();
    if(hipStart < 90){
      for(int i = hipStart; i < 90; ++i)
      {
        hip.write(i);
        delay(20);
      }
    }else{
      for(int i = hipStart; i > 90; --i)
      {
        hip.write(i);
        delay(20);
      }
    }
    if(footStart < 30){
      for(int i = footStart; i < 70; ++i)
      {
        foot.write(i);
        delay(20);
      }
    }else{
      for(int i = footStart; i > 70; --i)
      {
        foot.write(i);
        delay(20);
      }
    }
    for(int i = thighStart; i > 0; --i)
    {
      thigh.write(i);
      delay(20);
    }
  }

  // Sends legs to low crouch position
  // hip = 90
  // thigh = ??
  // foot = ??
  void crouch(){
    
    char hipStart = hip.read();
    char footStart = foot.read();
    char thighStart = thigh.read();
    if(hipStart < 90){
      for(int i = hipStart; i < 90; ++i)
      {
        hip.write(i);
        delay(20);
      }
    }else{
      for(int i = hipStart; i > 90; --i)
      {
        hip.write(i);
        delay(20);
      }
    }
    if(footStart < 30){
      for(int i = footStart; i < 70; ++i)
      {
        foot.write(i);
        delay(20);
      }
    }else{
      for(int i = footStart; i > 70; --i)
      {
        foot.write(i);
        delay(20);
      }
    }
    for(int i = thighStart; i > 0; --i)
    {
      thigh.write(i);
      delay(20);
    }
  }
  }

  // Private Data Members
private:
  /*char hipMax;
  char hipMin;
  char thighMax;
  char thighMin;
  char footMax;
  char footMin;
  Servo hip;*/
  char hipOffset;
  char thighOffset;
  char footOffset;
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
  legOne.activate(13,10,9);
  legTwo.activate(8,7,6);
  legThree.activate(5,4,3);
  legFour.activate(26,28,30);
  legFive.activate(15,16,17);
  legSix.activate(18,19,20);
  Serial.println("Setup Complete");
}

void loop() {
  Serial.println("Leg one and two standing");
  legOne.stand();
  legTwo.stand();
  delay(2000);
  Serial.println("Leg three and four standing");
  legThree.stand();
  legFour.stand();
  delay(2000);
  Serial.println("Leg five and six standing");
  legFive.stand();
  legSix.stand();
  
  Serial.println("Leg one Waves");
  legOne.wave();
  delay(1000);
}


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
}