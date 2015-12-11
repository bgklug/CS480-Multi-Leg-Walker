

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

                // twelve servo objects can be created on most boards
int testServo = 17;
int pos;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  Serial.println("Starting up");
  pos = 90;
  myservo.attach(testServo);  // attaches the servo on pin 9 to the servo object 
  myservo.write(pos); 
  delay(200);
  Serial.println("Setup Finished");
} 
 
void loop() 
{ 
  if(Serial.available() > 0){
    int go = Serial.parseInt();
    Serial.println(go);
    if(pos < go){
      for(pos; pos <= go; ++pos)  
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(1);                       // waits 15ms for the servo to reach the position 
      } 
    }else{
      for(pos; pos >= go; --pos) 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(1);                       // waits 15ms for the servo to reach the position 
      }
    }
  }
   
} 

