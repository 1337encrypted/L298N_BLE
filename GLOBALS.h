#include <L298N.h>
#include <BUZZER.h>
#include <LED.h>

/* 
 * Debug on and off enables code optimization
 * DEBUG 0 will ignore all Serial.print functions
 * DEBUG 1 will will add back Serial.print functions back to the code
 */
 
#define DEBUG 0

#if DEBUG == 1
  #define debug(x) Serial.print(x)
  #define debugln(x) Serial.println(x)
#else
  #define debug(x)
  #define debugln(x) 
#endif

//Led definition section
constexpr uint8_t redLedPin = 12;  //use between 150 ohms to 330 ohms resistor
constexpr uint8_t blueLedPin = 13;

//Buzzer definition section
#define buzzpin 11 //Active buzzer use 100 ohms resistor

//L298N motor driver 1 full bridge pin definitions
constexpr uint8_t in1 = A5;  
constexpr uint8_t in2 = A4;
constexpr uint8_t in3 = A3;       
constexpr uint8_t in4 = A2;
constexpr uint8_t pwm1 = 9;    //PWM 980hz
constexpr uint8_t pwm2 = 5;    //PWM 980hz

//L298N motor driver 2 full bridge pin definitions
constexpr uint8_t in5 = 2;  
constexpr uint8_t in6 = 4;
constexpr uint8_t in7 = 6;       
constexpr uint8_t in8 = 7;
constexpr uint8_t pwm3 = 3;    //PWM 980hz
constexpr uint8_t pwm4 = 10;    //PWM 980hz

/*=====================================================  Object declaration=============================================================*/
dual_L298N motor1(in1,in2,in3,in4,pwm1,pwm2);                           //Create an object of class motor1
dual_L298N motor2(in5,in6,in7,in8,pwm3,pwm4);                           //Create an object of class motor2
led redLed(redLedPin);                                                  //Create object for red led
led blueLed(blueLedPin);                                                //Create object for blue led
buzzer buzz(buzzpin);                                                   //Create object for buzzer

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++MOTOR STATES++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

enum class motorStates : uint8_t
{
   FRONT = 'F',
   BACK = 'B',
   LEFT = 'L',
   RIGHT = 'R',
   LEFTSHIFT = 'G',
   RIGHTSHIFT = 'I',
   BACKLEFT = 'H',
   BACKRIGHT = 'J',
   STOP = 'S',
   STOPALL = 'D',
   FRONTLIGHTSON = 'W',
   FRONTLIGHTSOFF = 'w',
   BACKLIGHTSON = 'U',
   BACKLIGHTSOFF = 'u',
   HORNON = 'V',
   HORNOFF = 'v',
   EXTRAON = 'X',
   EXTRAOFF = 'x',
   SPEED0 = '0',
   SPEED1 = '1',
   SPEED2 = '2',
   SPEED3 = '3',
   SPEED4 = '4',
   SPEED5 = '5',
   SPEED6 = '6',
   SPEED7 = '7',
   SPEED8 = '8',
   SPEED9 = '9',
   MAXSPEED = 'q'
};

enum class buzzStates : uint8_t
{
  OFF,
  ON,
  PASS
};

enum class ledStates : uint8_t
{
  STOP,
  RUN,
  PASS
};

motorStates motorStatus = motorStates::STOPALL;                   //State variable set to STOP initially
//motorStates motorPrevStatus;                                    //Previous motor state
buzzStates buzzStatus = buzzStates::PASS;                         //Buzzer state initilally is set to pass
ledStates ledStatus = ledStates::PASS;                            //Led state initilally is set to pass

/*==================================================Function prototyping section========================================================*/
inline void initSystem() __attribute__((always_inline));
inline void standbySystem() __attribute__((always_inline));

/*======================================================================================================================================*/

void initSystem()
{
  debugln("System initlized, waiting for bluetooth connection...");
  blueLed.on();                                                    //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  buzz.initBuzzer();                                               //puts the buzzer on
  delay(2);
  blueLed.off();                                                   //Turns the blue led on
  redLed.on();                                                     //Turns the red led on
  motorStatus = motorStates::STOP;                                 //State variable set to STOP initially
  buzzStates buzzStatus = buzzStates::PASS;                        //Buzzer state initilally is set to pass
  ledStates ledStatus = ledStates::STOP;                           //Led state initilally is set to pass 
}

void standbySystem()
{
  debugln("Bluetooth disconnected...");
  blueLed.off();  redLed.off();
  buzz.deinitBuzzer();  
}

//namespaces here
