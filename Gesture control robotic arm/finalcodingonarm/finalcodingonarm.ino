//#include <Servo.h>
//
//Servo myservo;
//Servo myservo1;
int flex1=A0; // shoulder
int flex2=A1; // elbow
int acc1=A2; // shoulder
int acc2=A3; // twist
int flex3=A5; //ndeffecto 
int a,b,c,d,e,new_a,new_b,new_c,new_d,new_e;
int i=0,j=0,k=0,l=0,m=0;
char x,y,z,a1,b1;
int newval,plus,minus;
int newval2,plus2,minus2;
int newval3,plus3,minus3;
int newval4,plus4,minus4;
int newval1,plus1,minus1;
int sw=8;
///////////////////////////////////////////////////////////
int functionacc3()
{
  if(c<270)
{
  c=270;
  }
else if(c>320)
{
  c=320;
  }
new_c=map(c,267,320,180,90);

if(i==0)
{
newval=new_c;
plus=new_c+7;
minus=new_c-7;
i=i+1 ;
  }
if(new_c<=minus || new_c>=plus )
{
  i=i-1;
  return (new_c);
  }
else{
  return (newval);
  }
  
  }
//////////////////////////////////////////////////////////////////
int functionacc2()
{
  if(b>415)
{
  b=415;
  }
else if(b<280)
{
  b=280;
  }

new_b=map(b,415,280,0,180);
if(j==0)
{
newval1=new_b;
plus1=new_b+6;
minus1=new_b-6;
j=j+1 ;
  }
if(new_b<=minus1 || new_b>=plus1 )
{
  j=j-1;
//  myservo.write(new_b);
//  myservo1.write(new_b);
//  Serial.println(new_b);
  return (new_b);
  }
else{
//  myservo1.write(newval1);
//  myservo.write(newval1);
//  Serial.println(newval1);
  return (newval1);
  }
  
  }
///////////////////////////////////////////////////////// 
int functionflex2()
{
  
  if(d<580)
{
  d=580;
  }
else if(d>720)
{
  d=720;
  }
//Serial.println(a);

new_d=map(d,580,720,0,90);

if(l==0)
{
newval3=new_d;
plus3=new_d+6;
minus3=new_d-6;
l=l+1;
  }
if(new_d<=minus3 || new_d>=plus3 )
{
  l=l-1;
  return (new_d);
  }
else{
  return (newval3);
  }
  
  }
/////////////////////////////////////////////////////////////////////////////////////////////
int functionflex3()
{
  
  if(e<490)
{
  e=490;
  }
else if(e>670)
{
  e=670;
  }

new_e=map(e,490,670,0,180);

if(m==0)
{
newval4=new_e;
plus4=new_e+2;
minus4=new_e-2;
m=m+1 ;
  }
if(new_e<=minus4 || new_e>=plus4 )
{
  m=m-1;
  return (new_e);
  }
else{
  return (newval4);
  }
  
  }
/////////////////////////////////////////////////////////////////////
int functionflex1()
{
  
  if(a<607)
{
  a=607;
  }
else if(a>720)
{
  a=720;
  }
//Serial.println(a);

new_a=map(a,607,720,0,90);

if(k==0)
{
newval2=new_a;
plus2=new_a+6;
minus2=new_a-6;
k=k+1 ;
  }
if(new_a<=minus2 || new_a>=plus2 )
{
  k=k-1;
  return (new_a);
  }
else{
  return (newval2);
  }
  
  }
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
// myservo.attach(5);
 //myservo1.attach(6);
 pinMode(sw,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 x = 'X';
 y = 'Y';
 z = 'Z';
 a1 = 'A';
 b1 = 'B';
a=analogRead(flex1);
b=analogRead(acc1);
c=analogRead(acc2);
d=analogRead(flex2);
e=analogRead(flex3);
//Serial.println(e);
//Serial.println(b);

int final_acc3=functionacc3();
int final_acc2=functionacc2();
int final_flex1=functionflex1();
int final_flex2=functionflex2();
int final_flex3=functionflex3();

if (final_flex3>=0 &&final_flex3<=70)
{
  final_flex3=120;
  }
else{
  final_flex3=180;
  }

//Serial.print("\t");
//if(digitalRead(sw)==1)
//{
// Serial.println(digitalRead(sw));
//Serial.print(final_flex1);
//Serial.print("\t");
//Serial.print(final_flex2);
//Serial.print("\t");
//Serial.print(final_flex3);
//Serial.print("\t");
//Serial.print(final_acc2);
//Serial.print("\t");
//Serial.println(final_acc3);
//}
int arr1[5]={ final_flex1, final_acc2 , final_flex2 , final_acc3 , final_flex3};                                                                      
char arr2[5]= {x,y,z,a1,b1};

if(digitalRead(sw)==1)
{
for(int i=0; i<=4; i++)
   {
   Serial.write(arr2[i]);
   delay(100);
   Serial.write(arr1[i]);
   delay(100);}
}





}
