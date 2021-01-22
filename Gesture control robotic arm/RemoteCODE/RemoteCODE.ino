#define rc2 A0 
#define rc1 A1
int ch2; 
int ch1;
const int dirPin11 = 6; //Forward
const int dirPin12 = 3; //Backward
const int dirPin21 = 4; //Forward
const int dirPin22 = 5; //Backward

void Forward()
{
  digitalWrite(dirPin11,1);
  digitalWrite(dirPin12,0);
  digitalWrite(dirPin21,1);
  digitalWrite(dirPin22,0);
  }
void Backward()
{
  digitalWrite(dirPin11,0);
  digitalWrite(dirPin12,1);
  digitalWrite(dirPin21,0);
  digitalWrite(dirPin22,1);
  }
void Left()
{
  digitalWrite(dirPin11,1);
  digitalWrite(dirPin12,0);
  digitalWrite(dirPin21,0);
  digitalWrite(dirPin22,1);
  }
void Right()
{
  digitalWrite(dirPin11,0);
  digitalWrite(dirPin12,1);
  digitalWrite(dirPin21,1);
  digitalWrite(dirPin22,0);
  }
void STOP()
{
  digitalWrite(dirPin11,0);
  digitalWrite(dirPin12,0);
  digitalWrite(dirPin21,0);
  digitalWrite(dirPin22,0);
  }
 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  pinMode(dirPin11,OUTPUT);
  pinMode(dirPin12,OUTPUT);
  pinMode(dirPin21,OUTPUT);
  pinMode(dirPin22,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
       ch2 = pulseIn(rc2, HIGH);
     Serial.print("Channel 2 :");
     Serial.println(ch2);
     
     ch1 = pulseIn(rc1, HIGH);
     Serial.print("Channel 1 :");
     Serial.println(ch1);
    
    if (ch1>1350 && ch1<1500 && ch2>1650 &&ch2<1900) 
          {
              Serial.println("Remote Ka straight");
              Forward();
          }
    else  if (ch1 > 1350 && ch1 <1500 && ch2 > 1050 && ch2<1300)
     {
      
      Backward();      
      Serial.println("Remote Ka backward");
      
      }
     else if(ch1 > 1700 && ch1 < 1900 && ch2 >1300 && ch2 <1500)
     {
      Right();
      Serial.println("Sharp Right haina?");
      }
     else if(ch1>1050 && ch1<1250 && ch2>1300 && ch2<1500)
     {
      Serial.println("Sharp Left Haina");
      Left();
      }
      else if (ch1>1700 && ch1<1900 && ch2>1650 && ch2<1850)
     {
      Serial.println("Right drift");
      Right();
      }
      else  if (ch1>1050 && ch1<1250 && ch2>1650 && ch2<1850)
      {
      Serial.println(" Left Drift");
      Left();
      }

      else if(ch1 > 1750 && ch1 < 1900 && ch2>1050 && ch2<1250)
     {
      Right();
      Serial.println("Back right");
      }
      else if(ch1 > 1000 && ch1 < 1150 && ch2>1050 && ch2<1250)
     {
      Serial.println("Back left");
      Left();
      }
      else{
        Serial.println("Remote toh chalo bhai??");
        STOP();
        }
}
