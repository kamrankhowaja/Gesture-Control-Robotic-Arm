/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */

#define ledPin 13

int state = 0;
int potValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 //Serial.print(state);
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  delay(1000);
  digitalWrite(ledPin, LOW); // LED OFF
  delay(1000);
 }
 else {
  digitalWrite(ledPin, LOW); // LED ON
 }
 // Reading the potentiometer
// potValue = analogRead(A0);
// int potValueMapped = map(potValue, 0, 1023, 0, 255);
 int kamran=1;
 Serial.write(kamran); // Sends potValue to servo motor
 delay(10);
}
