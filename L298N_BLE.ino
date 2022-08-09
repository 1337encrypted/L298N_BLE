#include "L298N_BLE.h"

FourWD car;                                   //Create an object of class car
char key;                                  //Key for the switch case
  
void setup(){
  Serial.begin(9600);
}

void loop()
{
  car.Stp();
  if (Serial.available())
  {  
    key=Serial.read();
    case 'F':
    {
      car.front();
      Serial.println("Foreward: "+car.Speed);
    }
    case 'B':
    {
      car.back();
      Serial.println("Backward: "+car.Speed);
    }
    case 'L':
    {
      car.leftturn();
      Serial.println("Left: "+car.Speed);
    }
    case 'R':
    {
      car.rightturn();
      Serial.println("Right: "+car.Speed);
    }
    case 'I':
    {
      car.rightShift();
      Serial.println("Right Shift: "+car.Speed);
    }
    case 'G':
    {
      car.leftShift();
      Serial.println("Left Shift: "+car.Speed);
    }
    case '0':
    {
      car.Speed = 115;
      //Serial.println("car.Speed = 115");
    }
    case '1':
    {
      car.Speed = 130;
      //Serial.println("car.Speed = 130");
    }
    case '2':
    {
      car.Speed = 143;
      //Serial.println("car.Speed = 143");
    }
    case '3':
    {
      car.Speed = 157;
      //Serial.println("car.Speed = 157");
    }
    case '4':
    {
      car.Speed = 170;
      //Serial.println("car.Speed = 170");
    }
    case '5':
    {
      car.Speed = 185;
      //Serial.println("car.Speed = 185");
    }
    case '6':
    {
      car.Speed = 200;
      //Serial.println("car.Speed = 200");
    }
    case '7':
    {
      car.Speed = 213;
      //Serial.println("car.Speed = 213");
    }
    case '8':
    {
      car.Speed = 227;
      //Serial.println("car.Speed = 227");
    }
    case '9':
    {
      car.Speed = 240;
      //Serial.println("car.Speed = 240");
    }
    case 'q':
    {
      car.Speed = 255;
      //Serial.println("car.Speed = 255");
    }
    default:
    {
      car.Stp();
      Serial.println("stop"+Speed);
    }
  }
}
