#include <Servo.h>

class Leg{
public:
  // ctor
  Leg(){}

  // Member Functions
  void activate(int hipPin, int thighPin, int footPin, int hOff, int tOff, int fOff){
    hip.attach(hipPin);
    thigh.attach(thighPin);
    foot.attach(footPin);
    hipOffset = hOff;
    thighOffset = tOff;
    footOffset = fOff;
    //stand();
    moveHip(90);
    moveThigh(90);
    moveFoot(90);
  }

  void moveL(int a, int b, int c){
    hip.write(a+hipOffset);
    thigh.write(b+thighOffset);
    foot.write(c+footOffset);
    hipPos = a;
    thighPos = b;
    footPos = c;
    delay(50);
  }

  void moveHip(int pos){
    int var = pos + hipOffset;
    hip.write(var);
    delay(5);
    hipPos = pos;
  }

  void moveThigh(int pos){
    int var = pos + thighOffset;
    thigh.write(var);
    delay(5);
    thighPos = pos;
  }

  void moveFoot(int pos){
    int var = pos + footOffset;
    foot.write(var);
    delay(5);
    footPos = pos;
  }  

  void lift(){
    moveL(hipPos,thighPos + 20, footPos + 20);
  }

  void set(){
    moveL(hipPos,thighPos - 20, footPos - 20);
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
     moveL(90,30,90);
     Serial.println("standing");
  }

  // Sends legs to low crouch position
  // hip = 90
  // thigh = 150
  // foot = 180
  void crouch(){
     moveL(90,150,180);
     Serial.println("crouching");
     delay(50);
  }

  // Private Data Members
private:
  int hipOffset;
  int thighOffset;
  int footOffset;
  int footPos;
  int hipPos;
  int thighPos;
  Servo hip;
  Servo thigh;
  Servo foot;
};

class Robot{
public:
  Robot(){}

  void activate(){
    legOne.activate(13,10,9,0,19,0);
    legTwo.activate(8,7,6,-10,2,-24);
    legThree.activate(5,4,3,-10,9,-21);
    legFour.activate(26,28,30,12,0,-4);
    legFive.activate(18,19,20,-12,15,-9);
    legSix.activate(15,16,17,10,7,-3);
    legOne.crouch();
    legTwo.crouch();
    legThree.crouch();
    legFour.crouch();
    legFive.crouch();
    legSix.crouch();
  }
  
  void crouch(){
    legOne.crouch();
    legTwo.crouch();
    legThree.crouch();
    legFour.crouch();
    legFive.crouch();
    legSix.crouch();
  }

  void stand(){
    legOne.stand();
    legTwo.stand();
    legThree.stand();
    legFour.stand();
    legFive.stand();
    legSix.stand();
  }

  void walk(Leg legA, Leg legB, Leg legC, Leg legD, Leg legE, Leg legF){
    legA.lift();
    legC.lift();
    legE.lift();
    delay(50);

    legB.moveHip(60);
    legD.moveHip(120);
    delay(50);

    legA.set();
    legC.set();
    legE.set();
    delay(50);

    legB.lift();
    legD.lift();
    legF.lift();
    delay(50);

    legB.moveHip(90);
    legD.moveHip(90);
    delay(50);

    legB.set();
    legD.set();
    legF.set();
    delay(50);
  }

  void walkF(){
    walk(legOne, legTwo, legThree, legFour, legFive, legSix);
  }

  void walkR(){
    walk(legTwo, legThree, legFour, legFive, legSix, legOne);
  }

  void walkL(){
    walk(legSix, legOne, legTwo, legThree, legFour, legFive);
  }
private:
Leg legOne;
Leg legTwo;
Leg legThree;
Leg legFour;
Leg legFive;
Leg legSix;
};

Robot hex;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Set up");
  hex.activate();
  hex.stand();
  Serial.println("Setup Complete");
}

void loop() {
  char buff[1];
  if(Serial.available() > 0){
    Serial.readBytes(buff, 1);
    Serial.println(buff);
    switch(buff[0]){
      case 'w':
        hex.walkF();
        break;
      case 'a':
        hex.walkL();
        break;
      case 'd':
        hex.walkR();
        break;
      case 'c':
        hex.crouch();
        break;
      case 's':
        hex.stand();
        break;
      default:
        break;
    delay(50);
    }
  }
  
}

