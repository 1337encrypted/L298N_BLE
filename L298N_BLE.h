/*
 * BTS7960.h - Library for controlling a brushed DC motor using the BTS7960 43amp motor driver.
 * Created by Yash Herekar, September 9, 2022.
 * Released into the public domain.
 * Copyright [2022] [Yash Herekar]
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 */

/*Cannot create a .cpp file as inline prototypes need the function to be present in the same file*/

#ifndef L298N_H
#define L298N_H

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

class L298N
{
  private:
    
  uint8_t in1;                       //in_1 L298N full bridge
  uint8_t in2;                       //in_2 L298N full bridge
  uint8_t pwm1;                      //pulse with moudulation ENA L298N full bridge
      
  public:

  uint8_t pwm;                      //pwm control variable
      
  inline L298N() __attribute__((always_inline));
  inline L298N(uint8_t,uint8_t,uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void run() __attribute__((always_inline));
  inline void stop() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
};

class dual_L298N: public L298N
{
  private:
    
  uint8_t in3;                       //in_1 L298N full bridge
  uint8_t in4;                       //in_2 L298N full bridge
  uint8_t pwm2;                      //pulse with moudulation ENA L298N full bridge
      
  public:
      
  inline dual_L298N() __attribute__((always_inline));
  inline dual_L298N(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t) __attribute__((always_inline));
  inline dual_L298N(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void run() __attribute__((always_inline));
  inline void stop() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
};

/*===============================================================L298N==================================================================*/

L298N::L298N()
{
  this->in1 = A5;
  this->in2 = A4;
  this->pwm1 = 3;
}

L298N::L298N(uint8_t in1, uint8_t in2, uint8_t pwm1) 
{
  this->in1 = in1;
  this->in2 = in2;
  this->pwm1 = pwm1;
}

void L298N::begin()
{
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  
  this->pwm = 255;
}

void L298N::stop()
{
  analogWrite(pwm1,0);
}

void L298N::front()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}

void L298N::back()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}

void L298N::run()
{
  analogWrite(pwm1,pwm);
}

/*=============================================================dual_L298N==============================================================*/

dual_L298N::dual_L298N()
{
  L298N();
  this->in3 = A3;
  this->in4 = A2;
  this->pwm2 = 5;
}

dual_L298N::dual_L298N(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t pwm1) 
{
  L298N(in1,in2,pwm1);
  this->in3 = in3;
  this->in4 = in4;
}

dual_L298N::dual_L298N(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t pwm1, uint8_t pwm2) 
{
  L298N(in1,in2,pwm1);
  this->in3 = in3;
  this->in4 = in4;
  this->pwm2 = pwm2;
}

void dual_L298N::begin()
{
  L298N::begin();
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(pwm2,OUTPUT);
}

void dual_L298N::run()
{
  L298N::run();
  analogWrite(pwm2,pwm);
}

void dual_L298N::stop()
{
  L298N::stop();
  analogWrite(pwm2,0);
}

void dual_L298N::front()
{
  L298N::front();
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void dual_L298N::back()
{
  L298N::back();
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
#endif
