/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */

int state = 0;
int potValue = 0;
int valuex,valuey,valuez,valuea,valueb;
char x,y,z,a,b;
#define ADC_ref 5.0

#define zero_x 1.569

#define zero_y 1.569

#define zero_z 1.569

#define sensitivity_x 0.3

#define sensitivity_y 0.3

#define sensitivity_z 0.3

unsigned int value_x;
unsigned int value_y;
unsigned int value_z;

unsigned int value_x1;
unsigned int value_y1;
unsigned int value_z1;

float xv;
float yv;
float zv;

float xv1;
float yv1;
float zv1;

int angle_x;
int angle_y;
int angle_z;

float angle_x1;
float angle_y1;
float angle_z1;
#define servo1 2
int i=1;
int newval;
int plus;
int minus;
void valueXX()
{
  
xv=(value_x/1024.0*ADC_ref-zero_x)/sensitivity_x;
xv1=(value_x1/1024.0*ADC_ref-zero_x)/sensitivity_x;
yv=(value_y/1024.0*ADC_ref-zero_y)/sensitivity_y;
yv1=(value_y1/1024.0*ADC_ref-zero_y)/sensitivity_y;
zv=(value_z/1024.0*ADC_ref-zero_z)/sensitivity_z;
zv1=(value_z1/1024.0*ADC_ref-zero_z)/sensitivity_z;
angle_x =atan2(-yv,-zv)*57.2957795+180;
Serial.println(angle_x);
angle_x1 =atan2(-yv1,-zv1)*57.2957795+180;
angle_y =atan2(-xv,-zv)*57.2957795+180;
angle_y1 =atan2(-xv1,-zv1)*57.2957795+180;
Serial.println(angle_y1);

  }
void setup() {
 analogReference(ADC_ref);

Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  value_x = analogRead(A0);
value_y = analogRead(A1);
value_z = analogRead(A2);
value_x1 = analogRead(A3);
value_y1 = analogRead(A4);
value_z1 = analogRead(A5);

valueXX();
//valuex =100;
// valuey=101;
// valuez=102;
// valuea=103;
// valueb=104;
 x = 'X';
 y = 'Y';
 z = 'Z';
 a = 'A';
 b = 'B';
 if(i==0)
{
newval=angle_x;
plus=angle_x+5;
minus=angle_x-5;
i=i+1;
  }
if(angle_x<=minus || angle_x>=plus )
{
  i=i-1;
  int arr1[5]={ angle_x, angle_y1 , angle_x1, angle_y , value_y1};
 char arr2[5]= {x,y,z,a,b};
 //potValue = 125;
// int potValueMapped = map(potValue, 0, 1023, 0, 255);
   for(int i=0; i<=4; i++)
   {//Serial.write(arr1[i]);// Sends potValue to servo motor
   Serial.write(arr2[i]);
   delay(100);
   Serial.write(arr1[i]);
//   Serial.println(arr2[i]);
//   Serial.println(arr1[i]);
   delay(100);}
  }
else{
//myservo.write(newval);
int arr1[5]={ newval, angle_y , angle_x1, angle_y1 , value_y1};
 char arr2[5]= {x,y,z,a,b};
 //potValue = 125;
// int potValueMapped = map(potValue, 0, 1023, 0, 255);
   for(int i=0; i<=4; i++)
   {//Serial.write(arr1[i]);// Sends potValue to servo motor
   Serial.write(arr2[i]);
   delay(100);
   Serial.write(arr1[i]);
//   Serial.println(arr2[i]);
//   Serial.println(arr1[i]);
   delay(100);}
}
 
}
