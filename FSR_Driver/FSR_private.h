/****************************************************/
/* Author   : Hamdy Osama Mohamed                   */
/* Date     : 25/8/2020                             */
/* Version  : V01                                   */
/* File     : FSR Driver                            */
/****************************************************/
#ifndef FSR_PRIVATE_H
#define FSR_PRIVATE_H

static float Calculate_Force(float FSR_Resistance,short FSR_Finger);      //used to calculate force based on specific sensor curve fitting
static float Filter_Force(float FSR_Force,short FSR_Finger);              //used to increment filtered force variable based on specific sensor

#endif
