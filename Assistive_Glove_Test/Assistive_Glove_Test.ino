#include "FSR_Driver.h"
#define INDEX_FSR  A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(INDEX_FSR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(FSR_Pin_Reading(INDEX_FSR));
//Serial.print(" ");
//Serial.println(FSR_Resistance(INDEX_FSR));
Serial.println(FSR_Force(INDEX_FSR));
//delay(25);
}
