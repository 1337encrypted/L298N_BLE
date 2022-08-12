#include <Servo.h> 
Servo xaxis;
Servo yaxis;
#define servoPin1 6
#define servoPin2 9
#define in1 A5                       //in_1 L298N 
#define in2 A4                       //in_2 L298N 
#define in3 A3                       //in_3 L298N 
#define in4 A2                       //in_4 L298N 
#define in5 A1                       //Fire extinguisher in_5 L298N
#define in6 A0                       //Fire extinguisher in_5 L298N
#define ENA1 3                       //pulse with moudulation ENA_1 and ENB_1 L298N 
#define ENA2 5                       //pulse with moudulation ENA_2 and ENB_2 L298N  
char key;                             //Key for the switch case
int Speed = 255;
int xval=90, yval=90; 
void setup()
{
  Serial.begin(9600);
  xaxis.attach(servoPin1);yaxis.attach(servoPin2); 
  pinMode(in1,OUTPUT);    pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);    pinMode(in4,OUTPUT);
  pinMode(ENA1,OUTPUT);   pinMode(ENA2,OUTPUT);
  digitalWrite(in1,LOW);  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);  digitalWrite(in4,LOW);
  xaxis.write(90);        yaxis.write(90);
}

void loop()
{
  if (Serial.available())
  {  
    key=Serial.read();
    switch(key)
    {
      case 'F':
      {
        digitalWrite(in1,HIGH);digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);digitalWrite(in4,LOW);
        Serial.println("Foreward: "+Speed);
        break;
      }
      case 'B':
      {
        digitalWrite(in1,LOW);digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);digitalWrite(in4,HIGH);
        Serial.println("Backward: "+Speed);
        break;
      }
      case 'L':
      {
        digitalWrite(in1,LOW);digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);digitalWrite(in4,HIGH);
        Serial.println("Left: "+Speed);
        break;
      }
      case 'R':
      {
        digitalWrite(in1,HIGH);digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);digitalWrite(in4,LOW);
        Serial.println("Right: "+Speed);
        break;
      }
      case 'G':
      {
        xval=xval+15;
        if(xval>=180)
          xval=180;
        xaxis.write(xval);  
      }
      case 'I':
      {
        xval=xval-15;
        if(xval<=0)
          xval=0;
        xaxis.write(xval);
      }
      case 'H':
      {
        yval=yval+15;
        if(yval>=180)
          yval=180;
        yaxis.write(yval);
      }
      case 'J':
      {
        yval=yval-15;
        if(yval<=0)
          yval=0;
        yaxis.write(yval);
      }
      case 'X':
      {
        //Reset the servo
        xaxis.write(90);
        yaxis.write(90);  
      }
      case 'x':
      {
        //Reset the servo
        xaxis.write(90);
        yaxis.write(90);  
      }
      case 'W':
      {
        digitalWrite(in5,HIGH);digitalWrite(in6,LOW);
        Serial.println("FireExtinguisher: 255");
        break;
      }
      case 'w':
      {
        digitalWrite(in5,LOW);digitalWrite(in6,LOW);
        Serial.println("FireExtinguisher: 0");
        break;
      }
      case 'U':
      {
        digitalWrite(in5,LOW);digitalWrite(in6,HIGH);    
        Serial.println("FireExtinguisher: 255");
        break;
      }
      case 'u':
      {
        digitalWrite(in5,LOW);digitalWrite(in6,LOW);
        Serial.println("FireExtinguisher: 0");
        break;
      }
      case '0':
      {
        Speed = 115;
        break;
      }
      case '1':
      {
        Speed = 130;
        break;
      }
      case '2':
      {
        Speed = 143;
        break;
      }
      case '3':
      {
        Speed = 157;
        break;
      }
      case '4':
      {
        Speed = 170;
        break;
      }
      case '5':
      {
        Speed = 185;
        break;
      }
      case '6':
      {
        Speed = 200;
        break;
      }
      case '7':
      {
        Speed = 213;
        break;
      }
      case '8':
      {
        Speed = 227;
        break;
      }
      case '9':
      {
        Speed = 240;
        break;
      }
      case 'q':
      {
        Speed = 255;
        break;
      }
    }
  analogWrite(ENA1,Speed);analogWrite(ENA2,Speed);
  }
  else
  {
    digitalWrite(in1,LOW);digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);digitalWrite(in4,LOW);  
  }
}