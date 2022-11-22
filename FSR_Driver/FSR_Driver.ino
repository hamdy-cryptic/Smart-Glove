#include "FSR_interface.h"

#define THUMB_FSR   A0
#define INDEX_FSR   A1
#define MIDDLE_FSR  A2
#define RING_FSR    A3
#define PINKY_FSR   A4

float glove_force_readings[5]={0};
short glove_force_pins[5]={THUMB_FSR,INDEX_FSR,MIDDLE_FSR,RING_FSR,PINKY_FSR};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(THUMB_FSR,INPUT);
  pinMode(INDEX_FSR,INPUT);
  pinMode(MIDDLE_FSR,INPUT);
  pinMode(RING_FSR,INPUT);
  pinMode(PINKY_FSR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.print(FSR_Pin_Reading(THUMB_FSR));
//Serial.print(" ");
//Serial.println(FSR_Resistance(INDEX_FSR));
Serial.println(FSR_Force(THUMB_FSR,4));
//delay(25);
//for (short i=0;i<5;i++){                                                 //Read All Sensors and Store Values
//  glove_force_readings[i]=FSR_Force(glove_force_pins[i],i);
//}
//for (short i=0;i<5;i++){                                                //Send All values stored before overwriting new values
//  Serial.print(glove_force_readings[i]);
//  Serial.print(" , ");  
//}
//Serial.println();


}
