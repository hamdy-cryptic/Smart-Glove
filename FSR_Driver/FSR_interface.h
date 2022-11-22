/****************************************************/
/* Author   : Hamdy Osama Mohamed                   */
/* Date     : 25/8/2020                             */
/* Version  : V01                                   */
/* File     : FSR Driver                            */
/****************************************************/
#ifndef FSR_INTERFACE_H
#define FSR_INTERFACE_H

/*Function Prototypes*/
int FSR_Pin_Reading(short FSR_Pin);      					/*used to get average voltage reading from Force Sensor*/
float FSR_Resistance(short FSR_Pin);       					/*used to get Sensor Resistance value*/ 
float FSR_Force(short FSR_Pin,short FSR_Finger);            /*used to get predicted force on sensor from model*/


/*Interface Definitions:*/
//FSR_Finger Options

#define THUMB     0
#define INDEX     1
#define MIDDLE    2
#define RING      3
#define PINKY     4




#endif
