#include "L298N_BLE.h"

FourWD car;                                   //Create an object of class car
uint8_t key;                                  //Key for the switch case
  
void setup(){
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available() > 0)
  {  
    key=Serial.read();
    
    if(key == 'F')
    {
      car.front();
      Serial.println("Foreward: "+car.Speed);
    }
    else if(key == 'B')
    {
      car.back();
      Serial.println("Backward: "+car.Speed);
    }
    else if(key == 'L')
    {
      car.leftturn();
      Serial.println("Left: "+car.Speed);
    }
    else if(key == 'R')
    {
      car.rightturn();
      Serial.println("Right: "+car.Speed);
    }
    else if(key == 'I')
    {
      car.rightShift();
      Serial.println("Right Shift: "+car.Speed);
    }
    else if(key == 'G')
    {
      car.leftShift();
      Serial.println("Left Shift: "+car.Speed);
    }
    else if(key == '0')
    {
      car.Speed = 115;
      //Serial.println("car.Speed = 115");
    }
    else if(key == '1')
    {
      car.Speed = 130;
      //Serial.println("car.Speed = 130");
    }
    else if(key == '2')
    {
      car.Speed = 143;
      //Serial.println("car.Speed = 143");
    }
    else if(key == '3')
    {
      car.Speed = 157;
      //Serial.println("car.Speed = 157");
    }
    else if(key == '4')
    {
      car.Speed = 170;
      //Serial.println("car.Speed = 170");
    }
    else if(key == '5')
    {
      car.Speed = 185;
      //Serial.println("car.Speed = 185");
    }
    else if(key == '6')
    {
      car.Speed = 200;
      //Serial.println("car.Speed = 200");
    }
    else if(key == '7')
    {
      car.Speed = 213;
      //Serial.println("car.Speed = 213");
    }
    else if(key == '8')
    {
      car.Speed = 227;
      //Serial.println("car.Speed = 227");
    }
    else if(key == '9')
    {
      car.Speed = 240;
      //Serial.println("car.Speed = 240");
    }
    else if(key == 'q')
    {
      car.Speed = 255;
      //Serial.println("car.Speed = 255");
    }
    else
    {
      car.Stp();
      Serial.println("Stop: "+0); 
    }
  }
}
