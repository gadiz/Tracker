// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
#include <Narcoleptic.h>
//#include "LowPower.h"
/* 
A library that allows you to send the microcontroller in standby
in times of inactivity (delay), saving a lot of energy.
You can not possibly use (in this case must be replaced
the last statement Narcoleptic.delay (15) with delay (15).
*/
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 90;    // variable to store the servo position 

#define SERVO_D 8

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(SERVO_D);  // attaches the servo on pin 9 to the servo object 
} 
 
int countPrint = 0; 
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
  float left = analogRead(A0);
  float right = analogRead(A1);
  float delta = fabs(left-right);
  if (delta > 2){
//    myservo.detach();
 // else{
  //  myservo.attach(SERVO_D); 
    if (left > right){
      pos += min(20 , delta/2);
      if (pos > 160)
        pos = 160;
      else 
        myservo.write(pos);
    }else{
      pos -= min(20  , delta/2);
      if (pos < 10)
        pos = 10;
       else
         myservo.write(pos);  
    }
  }
  ///Narcoleptic.delay (100);
   // Sleep for 8 s with ADC module and BOD module off
//    LowPower.powerDown(SLEEP_8S, ADC_CONTROL_OFF, BOD_OFF);
//    See more at: http://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/#sthash.noeikouj.dpuf
  delay (100);
  

     //myservo.write(50);
     //delay(2000);
     //myservo.write(60);
     //delay(2000);
     countPrint++;
     if (countPrint%100 == 0){
       Serial.print(left);
       Serial.print(right);
       Serial.print("\n\r");
     }
} 
