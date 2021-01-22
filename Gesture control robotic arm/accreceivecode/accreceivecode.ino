/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == SLAVE CODE ==
 */
 
#include <Servo.h>
#define button 8
Servo myServo;
int state ;
int buttonState = 0;
void setup() {
  pinMode(button, INPUT);
  myServo.attach(9);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
 while(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
//   Serial.write(state);
  
 }
  Serial.println(state);
 // Controlling the servo motor
 myServo.write(state);
 delay(10);
 
 // Reading the button
 buttonState = digitalRead(button);
// if (buttonState == HIGH) {
   //Serial.write('1'); // Sends '1' to the master to turn on LED
 //}
 //else {
   //Serial.write('0');
 //}  
}
