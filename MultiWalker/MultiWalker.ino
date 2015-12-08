#include <Servo.h>

class Leg
{
public:
  // ctor
  Leg(int hipPin, int thighPin, int footPin){
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
      delay(100);
    }
    for(int i = 0; i < 180; ++i)
    {
      thigh.write(180 - i);
      foot.write(180 - i);
      delay(100);
    }
    for(int i = 0; i < 30; ++i)
    {
      thigh.write(i);
      foot.write(i);
      delay(100);
    }
  }
  
  void stand(){
    char hipStart = hip.read();
    char footStart = foot.read();
    char thighStart = thigh.read();
    if(hipStart < 90){
      for(int i = hipStart; i < 90; ++i)
      {
        hip.write(i);
        delay(500);
      }
    }else{
      for(int i = hipStart; i > 90; --i)
      {
        hip.write(i);
        delay(500);
      }
    }
    if(footStart < 30){
      for(int i = footStart; i < 30; ++i)
      {
        foot.write(i);
        delay(500);
      }
    }else{
      for(int i = footStart; i > 30; --i)
      {
        foot.write(i);
        delay(500);
      }
    }
    for(int i = thighStart; i > 0; --i)
    {
      thigh.write(i);
      delay(500);
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

Leg legOne(13,10,9);
/*Leg legTwo(8,7,6);
Leg legThree(5,4,3);
Leg legFour(2,1,0);
Leg legFive(15,16,17);
Leg legSix(18,19,20);*/

void setup() {
  legOne.stand();
  /*legTwo.stand();
  delay(2000);
  legThree.stand();
  legFour.stand();
  delay(2000);
  legFive.stand();
  legSix.stand();
  delay(2000);*/
}

void loop() {
 /* legOne.stand();
  legTwo.stand();
  delay(2000);
  legThree.stand();
  legFour.stand();
  delay(2000);
  legFive.stand();
  legSix.stand();
  delay(2000);*/

  legOne.wave();
  delay(1000);
}
