/*   ~ Simple Arduino - xBee Transmitter sketch ~

  Read an analog value from potentiometer, then convert it to PWM and finally send it through serial port to xBee.
  The xBee serial module will send it to another xBee (resiver) and an Arduino will turn on (fade) an LED.
  The sending message starts with '<' and closes with '>' symbol. 
  
  Dev: Michalis Vasilakis // Date:2/3/2016 // Info: www.ardumotive.com // Licence: CC BY-NC-SA                    */
//#include<SoftwareSerial.h>
//Constants: 
//const int potPin = A0; //Pot at Arduino A0 pin 
//Variables:
int value ; //Value from pot
//SoftwareSerial xbee(10,11); //(RX,TX)
void setup() {

  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
//xbee.begin(9600);
}

void loop() {
    
    //Read the analog value from pot and store it to "value" variable
    //value = analogRead(A0);
    //Map the analog value to pwm value
    value=1;
    //value = map (value, 0, 1023, 0, 255);
  //Send the message:
  Serial.print('<');  //Starting symbol
  Serial.print("Hello");//Value from 0 to 255
  Serial.println('>');//Ending symbol
 Serial.write('<');  //Starting symbol
  Serial.write(value);//Value from 0 to 255
  Serial.write('>');//Ending symbol
  Serial.write('\n');//Ending symbol

}
  
