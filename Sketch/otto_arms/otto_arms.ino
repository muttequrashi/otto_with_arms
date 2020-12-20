
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                     Otto With Arms Custom Code                                                                        //
//                                                                    Developed By: Mutte Ur Rehman                                                                      //
//                                                                         Robotics Engineer                                                                             //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Include Library
#include <Otto9Humanoid.h>
Otto9Humanoid Otto;

#define PIN_YL 2 // left leg, servo[0]
#define PIN_YR 3 // right leg, servo[1]
#define PIN_RL 4 // left foot, servo[2]
#define PIN_RR 5 // right foot, servo[3]
#define PIN_LA 6 //servo[4]  Left arm
#define PIN_RA 7 //servo[5]  Right arm
#define PIN_Trigger 8 // ultrasound
#define PIN_Echo 9 // ultrasound
#define PIN_NoiseSensor A6
#define PIN_Buzzer  13 //buzzer

const char data[] = "VARIABLE#";
unsigned long int matrix;

#define DIN_PIN A3
#define CS_PIN A2
#define CLK_PIN A1
#define LED_DIRECTION 1

void setup() {
  
  Otto.initHUMANOID(PIN_YL, PIN_YR, PIN_RL, PIN_RR, PIN_LA, PIN_RA, true, PIN_NoiseSensor, PIN_Buzzer, PIN_Trigger, PIN_Echo);
  Otto.initMATRIX(DIN_PIN,CS_PIN,CLK_PIN,LED_DIRECTION);
  Otto.putMouth(xMouth);
  //Otto.home(); 
  
  //delay(1000);
} 

void loop() {
  
  while(Otto.getDistance() >10){
    Otto.putMouth(xMouth);
    Otto.walk_custom(1,1000,1);
    
  }
  Otto.putMouth(27);
  Otto.home();
  Otto.jump(1,2000);
  Otto.turn_custom(1,1000,-1);
  
}
