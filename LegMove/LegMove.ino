#include <Servo.h> 
 
Servo foot;
Servo arm;
Servo twist;
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  foot.attach(9); // larger value goes in
  arm.attach(10);// larger value goes down
  twist.attach(11);
} 

void forward()
{
  for(pos = 0; pos <= 30; pos += 1) 
  {                                  
    arm.write(140+pos);
    foot.write(130-pos);             
    delay(20);                       
  } 
  for(pos = 30; pos>=0; pos-=1)     
  {
    twist.write(90 + pos);
    delay(20); 
  }
  for(pos = 30; pos>=0; pos-=1)     
  {                                
    arm.write(140+pos);
    foot.write(130-pos);              
    delay(20);                        
  } 
  for(pos = 0; pos <= 30; pos += 1)    
  {
    twist.write(90 + pos);
    delay(20); 
  }
}

void crab()
{
   arm.write(110);
  //foot pull
   for(pos = 0; pos <= 60; pos+=1)     
  {                                
    foot.write(130-pos);              
    delay(20);                        
  } 
  //arm lift
   for(pos = 0; pos <= 50; pos+=1)     
  {                                
    arm.write(110+pos);            
    delay(20);                        
  } 
  //foot reach
   for(pos = 60; pos>=0; pos-=1)     
  {                   
    foot.write(130-pos);              
    delay(20);                        
  } 
  //arm set down
   for(pos = 50; pos>=0; pos-=1)     
  {                                
    arm.write(110+pos);              
    delay(20);                        
  } 
}
 
void loop() 
{ 
  
} 

