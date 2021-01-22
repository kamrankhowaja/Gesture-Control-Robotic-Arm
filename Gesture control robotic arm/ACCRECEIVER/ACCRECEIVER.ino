/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == SLAVE CODE ==
 */
 
#include <Servo.h>

Servo myServo;
Servo myServo1;
int state,state1,state2,state3,state4,state5 ;
int valuey,valuez,valuea,valueb;
int valuex =0;
void setup() {
 // pinMode(button, INPUT);
  myServo.attach(9);
  myServo1.attach(10);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
 while(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
     if(state==88)
 {
 
  state1 = Serial.read();
  valuex=state1;
  Serial.print("valuex = ");
  myServo.write(valuex);
   Serial.println(valuex);
   delay(100);
  }
  else if(state==89)
 {
//   delay(100);
  state2 = Serial.read();
  valuey=state2;
  Serial.print("valuey = ");
  myServo1.write(valuey);
   Serial.println(valuey);
    delay(100);
  }
   else if(state==90)
 {
//   delay(100);
  state3= Serial.read();
  valuez=state3;
  //Serial.print("valuez = ");
   //Serial.println(valuez);
  }
   else if(state==65)
 {
  state4 = Serial.read();
  valuea=state4;
  //Serial.print("valuea = ");
   //Serial.println(valuea);
  }
   else if(state==66)
 {
  state5 = Serial.read();
  valueb=state5;
  //Serial.print("valueb = ");
   //Serial.println(valueb);
  }
// Serial.write(state);
 
 }
 
 //Serial.println(state);
 delay(100);
 
}
