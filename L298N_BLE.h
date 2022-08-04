#ifndef L298N_BLE_H
#define L298N_BLE_H

#include "Arduino.h"

class FourWD
{
  private:
    
      uint8_t in1;                       //in_1 L298N full bridge
      uint8_t in2;                       //in_2 L298N full bridge
      uint8_t in3;                       //in_3 L298N full bridge
      uint8_t in4;                       //in_4 L298N full bridge
      uint8_t in5;                       //in_5 L298N full bridge
      uint8_t in6;                       //in_6 L298N full bridge
      uint8_t in7;                       //in_7 L298N full bridge
      uint8_t in8;                       //in_8 L298N full bridge
      uint8_t spdpin1;                   //pulse with moudulation ENA_1 and ENB_1 L298N full bridge
      uint8_t spdpin2;                   //pulse with moudulation ENA_2 and ENB_2 L298N full bridge
      uint8_t spdpin3;                   //pulse with moudulation ENA_3 and ENB_3 L298N full bridge
      uint8_t spdpin4;                   //pulse with moudulation ENA_4 and ENB_4 L298N full bridge
    
  public:

      uint8_t Speed;                     //Speed control variable
      
      inline FourWD() __attribute__((always_inline));
      inline void Stp() __attribute__((always_inline));
      inline void front() __attribute__((always_inline));
      inline void back() __attribute__((always_inline));
      inline void leftturn() __attribute__((always_inline));
      inline void rightturn() __attribute__((always_inline));
      inline void rightShift() __attribute__((always_inline));
      inline void leftShift() __attribute__((always_inline));
      inline void leftDiagonalFront() __attribute__((always_inline));
      inline void rightDiagonalBack() __attribute__((always_inline));
      inline void leftDiagonalBack() __attribute__((always_inline));
      inline void rightBackPivot() __attribute__((always_inline));
      inline void leftBackPivot() __attribute__((always_inline));
};

FourWD::FourWD()
{
    this->in1 = A5;
    this->in2 = A4;
    this->in3 = A3;
    this->in4 = A2;
    this->in5 = A1;
    this->in6 = A0;
    this->in7 = 2;
    this->in8 = 4;
    this->spdpin1 = 3;
    this->spdpin2 = 5;
    this->spdpin3 = 6;
    this->spdpin4 = 9;
    this->Speed = 255;

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

void FourWD::Stp()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,0);
    analogWrite(spdpin2,0);
    analogWrite(spdpin3,0);
    analogWrite(spdpin4,0);
}

void FourWD::front()
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

void FourWD::back()
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

void FourWD::leftturn()
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

void FourWD::rightturn()
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

void FourWD::rightShift()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void FourWD::leftShift()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}
void FourWD::leftDiagonalFront()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void FourWD::rightDiagonalBack()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void FourWD::leftDiagonalBack()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}


void FourWD::rightBackPivot()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}

void FourWD::leftBackPivot()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
    analogWrite(spdpin3,Speed);
    analogWrite(spdpin4,Speed);
}
#endif
