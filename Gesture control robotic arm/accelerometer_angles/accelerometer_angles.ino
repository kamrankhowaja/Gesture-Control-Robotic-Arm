// Simple angle meter using ADXL335 accelerometer
//from electronicsblog.net/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
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
angle_x1 =atan2(-yv1,-zv1)*57.2957795+180;
angle_y =atan2(-xv,-zv)*57.2957795+180;
angle_y1 =atan2(-xv1,-zv1)*57.2957795+180;

  }
void setup()   {

analogReference(ADC_ref);

Serial.begin(9600);
myservo.attach(servo1);

}

void loop() {

value_x = analogRead(A0);
value_y = analogRead(A1);
value_z = analogRead(A2);
value_x1 = analogRead(A3);
value_y1 = analogRead(A4);
value_z1 = analogRead(A5);

valueXX();

//Serial.print ("x= ");
//Serial.print (xv);
//Serial.print(" g ");
//Serial.print ("y= ");
//Serial.print (yv);
//Serial.print(" g ");
//Serial.print ("z= ");
//Serial.print (zv);
//Serial.print(" g ");

Serial.print("\n");

Serial.print("Rotation ");
Serial.println(newval);
//Serial.print("x= ");
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
  myservo.write(angle_x);
  }
else{
myservo.write(newval);
}
Serial.print(angle_x);
Serial.print(" deg");
Serial.print("\t");
Serial.print(angle_x1);
Serial.println(" deg");
//Serial.print("y= ");
//Serial.print(angle_y);
//Serial.print(" deg");
//Serial.print(" ");
//Serial.print("z= ");
//Serial.print(angle_z);
//Serial.print(" deg");
//Serial.print("\n");

delay(100);
}
