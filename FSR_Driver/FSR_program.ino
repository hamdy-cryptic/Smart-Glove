/****************************************************/
/* Author   : Hamdy Osama Mohamed                   */
/* Date     : 25/8/2020                             */
/* Version  : V02                                   */
/* File     : FSR Driver                            */
/****************************************************/
#include "FSR_interface.h"
#include "FSR_config.h"
#include "FSR_private.h"


/*Global Variables*/
float filtered_force0=0;
float filtered_force1=0;
float filtered_force2=0;
float filtered_force3=0;
float filtered_force4=0;
 
/*Function Implementation*/
int FSR_Pin_Reading(short FSR_Pin){
  long Sum=0;                                           /*used to store all pin readings addition*/
  if(NUMBER_OF_READINGS<=0){                           /*Check Configurations*/
    Serial.println("Wrong Number of Readings set in Configuration");
    return -1;                                         /*Error State*/ 
  }
  else {
    for (short i=0;i<NUMBER_OF_READINGS;i++){          /*Add all readings to help return average*/
      Sum+=analogRead(FSR_Pin);
     // delay(1);
    }
  }
  return Sum/NUMBER_OF_READINGS;                       /*Return Average*/
}

float FSR_Resistance(short FSR_Pin){
  int Reading=FSR_Pin_Reading(FSR_Pin);              /*Get Average Pin Reading*/
  /*Calculate FSR Resistance based on Voltage Divider Configuration*/
  if (CONSTANT_RESISTANCE>0){                          /*Check Configurations*/
    return CONSTANT_RESISTANCE*((1/((float)Reading/1023))-1);
  }
  else{
    Serial.println("Wrong Constant resistance value set in Configuration");
    return -1;                                         /*Error State*/  
  }
}


float FSR_Force(short FSR_Pin,short FSR_Finger){
  float force;
  float filtered_force;
  float resistance=FSR_Resistance(FSR_Pin);
  force=Calculate_Force(resistance,FSR_Finger);          //Start Calculating Force based on sensor curve
  //return force;
  if (force>=400){                                        //Average Sensor Force Sensitivity
  filtered_force=Filter_Force(force,FSR_Finger); //Low Pass Filter
  return filtered_force;
  }
  force=0; 
  filtered_force=Filter_Force(force,FSR_Finger); //Low Pass Filter
  return filtered_force;
}



static float Calculate_Force(float FSR_Resistance,short FSR_Finger){
	if (FSR_Finger==0)
		return 2.309*pow(10,10)*pow(FSR_Resistance,-1.752)+383.3; //Based on Force-Resistance Curve Fitting
	else if (FSR_Finger==1)
		return 9.002*pow(10,8)*pow(FSR_Resistance,-1.382)+300;  //Based on Force-Resistance Curve Fitting
	else if (FSR_Finger==2)
		return 6.36*pow(10,8)*pow(FSR_Resistance,-1.366)+264.9;   //Based on Force-Resistance Curve Fitting
	else if (FSR_Finger==3)
		return 5.027*pow(10,9)*pow(FSR_Resistance,-1.629)+267.6; //Based on Force-Resistance Curve Fitting
	else if (FSR_Finger==4)
		return 1.206*pow(10,10)*pow(FSR_Resistance,-1.689)+268.7;      //Based on Force-Resistance Curve Fitting
	else
		return -1;  //	ERROR STATE
}

static float Filter_Force(float FSR_Force,short FSR_Finger){
  if (FSR_Finger==0){
    filtered_force0=(0.5335*filtered_force0 + 0.4665*FSR_Force);    //Low Pass Filter
    return filtered_force0;
  }
  else if (FSR_Finger==1){
    filtered_force1=(0.5335*filtered_force1 + 0.4665*FSR_Force);    //Low Pass Filter
    return filtered_force1;
  }
  else if (FSR_Finger==2){
    filtered_force2=(0.5335*filtered_force2 + 0.4665*FSR_Force);    //Low Pass Filter
    return filtered_force2;
  }
  else if (FSR_Finger==3){
    filtered_force3=(0.5335*filtered_force3 + 0.4665*FSR_Force);    //Low Pass Filter
    return filtered_force3;
  }
  else if (FSR_Finger==4){
    filtered_force4=(0.5335*filtered_force4 + 0.4665*FSR_Force);    //Low Pass Filter
    return filtered_force4;
  }
  else{
    return -1; //ERROR STATE
  }
}
