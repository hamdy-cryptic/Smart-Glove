#include "FLEX_interface.h"

#define EXAMPLE   A0


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EXAMPLE,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//Serial.print(FLEX_Resistance(EXAMPLE));
//Serial.print(" ");

Serial.println(FLEX_Angle(EXAMPLE,FLEX42R));

}
