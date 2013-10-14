// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 90;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
 /* for(pos = 0; pos < 180; pos += 10)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(150);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=10)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(150);                       // waits 15ms for the servo to reach the position 
  }
 */
  float a = analogRead(A0);
  float b = analogRead(A1);
  float delta = fabs(a-b);
  if (delta > 3){
    int boost = 0;
    if (delta > 10)
      boost = 10;
    if (a > b){
      pos += (1 + boost);
      if (pos > 150)
        pos = 150;
      else 
        myservo.write(pos);
    }else{
      pos -= (1 + boost);
      if (pos < 30)
        pos = 30;
       else
         myservo.write(pos);  
    }
  }
  delay (100);
  

     //myservo.write(50);
     //delay(2000);
     //myservo.write(60);
     //delay(2000);
     Serial.print(a);
     Serial.print(b);
     Serial.print("\n\r");
} 
