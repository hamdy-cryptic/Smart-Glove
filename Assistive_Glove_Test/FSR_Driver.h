/****************************************************/
/* Author   : Hamdy Osama Mohamed                   */
/* Date     : 25/8/2020                             */
/* Version  : V01                                   */
/* File     : FSR Driver                            */
/****************************************************/
#ifndef FSR_DRIVER_H
#define FSR_DRIVER_H

/*Function Prototypes*/
int FSR_Pin_Reading(short FSR_Pin);      /*used to get average voltage reading from Force Sensor*/
float FSR_Resistance(short FSR_Pin);       /*used to get Sensor Resistance value*/ 
float FSR_Force(short FSR_Pin);            /*used to get predicted force on sensor from model*/

/*Driver Configuration*/
//Choose number of sensor readings to take average on
/*Options: Write positive number to determine # of readings
           Default Value = 10     range (1:255)
           Note that larger # of readings will cause slower system
 */
 #define NUMBER_OF_READINGS    40

//Choose Resistance Value in Voltage divider configuration (Vanalog to Ground)
/*Options: Write Value of Resistance in Ohms
           Default Value of 10KOHM =   10000           
*/
 #define CONSTANT_RESISTANCE   50000

float filtered_force;
float correction_factor=1;
 
/*Function Declaration*/
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
  if (CONSTANT_RESISTANCE>0){                          /*Check Configuration*/
    return CONSTANT_RESISTANCE*((1/((float)Reading/1023))-1);
  }
  else{
    Serial.println("Wrong Constant resistance value set in Configuration");
    return -1;                                         /*Error State*/  
  }
}


float FSR_Force(short FSR_Pin){
  float force;
  float resistance=FSR_Resistance(FSR_Pin);
  if ((resistance)<(105000*correction_factor*correction_factor))   //Average Sensor Sensitivity
  {
  force=2.309*pow(10,10)*pow(resistance,-1.752)+383.3; //Based on Force Curve Fitting
  force*=correction_factor;
  filtered_force=(0.2846*filtered_force + 0.7154*force); //Low Pass Filter
  return filtered_force;
  }
  force=0; 
  filtered_force=(0.2846*filtered_force + 0.7154*force); //Low Pass Filter
  return filtered_force;
}

#endif
