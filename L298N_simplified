//#include "L298N_BLE.h"

#define in1 A5                       //in_1 L298N full bridge
#define in2 A4                       //in_2 L298N full bridge
#define in3 A3                       //in_3 L298N full bridge
#define in4 A2                       //in_4 L298N full bridge
#define in5 A1                       //in_5 L298N full bridge
#define in6 A0                       //in_6 L298N full bridge
#define in7 2                        //in_7 L298N full bridge
#define in8 4                        //in_8 L298N full bridge
#define spdpin1 3                    //pulse with moudulation ENA_1 and ENB_1 L298N full bridge
#define spdpin2 5                    //pulse with moudulation ENA_2 and ENB_2 L298N full bridge
#define spdpin3 6                    //pulse with moudulation ENA_3 and ENB_3 L298N full bridge
#define spdpin4 9                    //pulse with moudulation ENA_4 and ENB_4 L298N full bridge
//FourWD car;                        //Create an object of class car
int key;                         //Key for the switch case
int Speed = 255;
  
void setup()
{

  Serial.begin(9600);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);
  pinMode(spdpin1,OUTPUT);
  pinMode(spdpin2,OUTPUT);
  pinMode(spdpin3,OUTPUT);
  pinMode(spdpin4,OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {  
    key=Serial.read();
    Stp();
    switch(key)
    {
      case 'F':
      {
        front();
        Serial.println("Foreward: "+Speed);
        break;
      }
      case 'B':
      {
        back();
        Serial.println("Backward: "+Speed);
        break;
      }
      case 'L'
      {
        leftTurn();
        Serial.println("Left: "+Speed);
        break;
      }
      case 'R':
      {
        rightTurn();
        Serial.println("Right: "+Speed);
        break;
      }
      case '0':
      {
        Speed = 115;
        //Serial.println("car.Speed = 115");
        break;
      }
      case '1':
      {
        Speed = 130;
        //Serial.println("car.Speed = 130");
        break;
      }
      case '2':
      {
        Speed = 143;
        //Serial.println("car.Speed = 143");
        break;
      }
      case '3':
      {
        Speed = 157;
        //Serial.println("car.Speed = 157");
        break;
      }
      case '4':
      {
        Speed = 170;
        //Serial.println("car.Speed = 170");
        break;
      }
      case '5':
      {
        Speed = 185;
        //Serial.println("car.Speed = 185");
        break;
      }
      case '6':
      {
        Speed = 200;
        //Serial.println("car.Speed = 200");
        break;
      }
      case '7':
      {
        Speed = 213;
        //Serial.println("car.Speed = 213");
        break;
      }
      case '8':
      {
        Speed = 227;
        //Serial.println("car.Speed = 227");
        break;
      }
      case '9':
      {
        Speed = 240;
        //Serial.println("car.Speed = 240");
        break;
      }
      case 'q':
      {
        Speed = 255;
        //Serial.println("car.Speed = 255");
        break;
      }
  }
}
void Stp()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void front()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void back()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void leftTurn()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void rightTurn()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}
