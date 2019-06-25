/* RPD Beam Position Code
This header file is used to insert a function which will measure a weighted average
of the beam position using the 16 channels of the RPD. The channels are aggregated by groups of 4 into rows and columns this is how the weighted average is calcualted to return a position.

These are defined in the code(s) designed to use this header file.

Adjust this as necessary

Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS in the winter.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!THERE IS A LESS THAN 40 fC cut in this code!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4/12/19 */

// last edited (if I remebered to change this... 6/25/2019 2:36:20 PM)

//IF YOU ARE SETTING THINGS TO 1 TO MAKE IT SO NO WEIGHTS ARE APPLIED REATE INDIVIDUAL ARRAYS FOR EACH INDEPENDENT FUNCTION OTHERWISE THE CODE READS OUTSIDE OF THE ARRAY

#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring> //colin added
#include <string> // Eric Added

#include <stdexcept>

// I am a chemist not an englishist I cant spell

#ifndef X_Y_P_N_RPD_Beam_Position_Calculator
#define X_Y_P_N_RPD_Beam_Position_Calculator

void Returns_X_Y_P_N_RPD_Beam_Position(double RawDataRPD[2][16][10],  const std::string& OnorOff, double InputJeffWeighter[16], double &Output_PosX, double &Output_PosY, double &Output_NegX, double &Output_NegY){
//EM_BEAM_POSITION[ NEG, POS]

	if (OnorOff != "On" && OnorOff != "Off") {
			throw std::runtime_error("ERROR: OnorOFF must be set to On or Off, input variable 3, X_Y_P_N_RPD_Beam_Position_Calculator.h");
	}


	if (OnorOff == "Off"){
		for (int i = 0; i < 16; i++){
			InputJeffWeighter[i] = 1;
		}
	}
	
	const int NRPD = 16;
	const int NRPDColnRow = 4;
	double AxisRPD[NRPDColnRow] = { -3.0, -1.0, 1.0, 3.0 };
	float RPD_COL_P[NRPD];
	float RPD_ROW_P[NRPD];
	float RPD_COL_N[NRPD];
	float RPD_ROW_N[NRPD];

	double sumWeightRPD_P_X = 0;
	double sumRPD_P_X = 0;
	double sumWeightRPD_P_Y = 0;
	double sumRPD_P_Y = 0;
	double sumWeightRPD_N_X = 0;
	double sumRPD_N_X = 0;
	double sumWeightRPD_N_Y = 0;
	double sumRPD_N_Y = 0;




	double TS45Array[2][16] = {0}; //ignore warnings from this line
	double TS456Array[2][16] = {0}; //ignore warnings from this line
	
	for (int s = 0; s < 2; s++){ //s=side
		for (int c = 0; c < 16; c++){ //c = channel
			TS45Array[s][c] = RawDataRPD[s][c][4] + RawDataRPD[s][c][5];
			TS456Array[s][c] = TS45Array[s][c] + RawDataRPD[s][c][6];
	
			if ((TS456Array[s][c] < 40) || (TS45Array[s][c] / TS456Array[s][c] < .8) || //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
			 (RawDataRPD[s][c][7] >= RawDataRPD[s][c][5]) || (RawDataRPD[s][c][1] / RawDataRPD[s][c][0] > 1000) //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
			  || (RawDataRPD[s][c][0] = 0)){ //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
				
				//exit logic if bad
				Output_NegX = -10;
				Output_NegY = -10;
				Output_PosX = -10;
				Output_PosY = -10;
				return;
			}


			if (s == 0) { //Neg columns and rows
				for (int c = 0; c < 16; c++){
					//Y
					if (c == 11 || c == 15 || c == 2 || c == 6) { RPD_ROW_N[0]   += TS456Array[s][c];}
					if (c == 8  || c == 12 || c == 1 || c == 5) { RPD_ROW_N[1]   += TS456Array[s][c];}
					if (c == 9  || c == 13 || c == 0 || c == 4) { RPD_ROW_N[2]   += TS456Array[s][c];}
					if (c == 10 || c == 14 || c == 3 || c == 7) { RPD_ROW_N[3]   += TS456Array[s][c];}											//R0
						///////////////////////////////////////////////// IS THE ORDERING OF THE OUTPUT JEFF ARRAYS MATH DATA??																									 										//R1
																																				//R1
					// X
					if (c == 10 || c == 9  || c == 8  || c == 11) { RPD_COL_N[0] += TS456Array[s][c] * InputJeffWeighter[c];}			//R2             
					if (c == 14 || c == 13 || c == 12 || c == 15) { RPD_COL_N[1] += TS456Array[s][c] * InputJeffWeighter[c];}			//R3							
					if (c == 3  || c == 0  || c == 1  || c == 2)  { RPD_COL_N[2] += TS456Array[s][c] * InputJeffWeighter[c];}			  //C3 C2 C1 C0					
					if (c == 7  || c == 4  || c == 5  || c == 6)  { RPD_COL_N[3] += TS456Array[s][c] * InputJeffWeighter[c];}
				}
			}
	                                                                                                                                           
			else { //Pos columns and rows
				for (int c = 0; c < 16; c++){
		
					// Y
					if (c == 11 || c == 15 || c == 2 || c == 5) { RPD_ROW_P[0]   += TS456Array[s][c];}
					if (c == 8  || c == 12 || c == 1 || c == 6) { RPD_ROW_P[1]   += TS456Array[s][c];}
					if (c == 9  || c == 13 || c == 0 || c == 4) { RPD_ROW_P[2]   += TS456Array[s][c];}
					if (c == 10 || c == 14 || c == 3 || c == 7) { RPD_ROW_P[3]   += TS456Array[s][c];}											//R0
																																				//R1
					// X																									 							                 	//R1
					if (c == 10 || c == 9  || c == 8  || c == 11) { RPD_COL_P[0] += TS456Array[s][c] * InputJeffWeighter[c];}			//R2             
					if (c == 14 || c == 13 || c == 12 || c == 15) { RPD_COL_P[1] += TS456Array[s][c] * InputJeffWeighter[c];}			//R3							
					if (c == 3  || c == 0  || c == 1  || c == 2)  { RPD_COL_P[2] += TS456Array[s][c] * InputJeffWeighter[c];}			  //C3 C2 C1 C0					
					if (c == 7  || c == 4  || c == 6  || c == 5)  { RPD_COL_P[3] += TS456Array[s][c] * InputJeffWeighter[c];}
					
				}
			}

			//getting mean values that are the ouputs
			sumWeightRPD_P_X = (RPD_COL_P[0] * AxisRPD[0]) + (RPD_COL_P[1] * AxisRPD[1]) + (RPD_COL_P[2] * AxisRPD[2]) + (RPD_COL_P[3] * AxisRPD[3]);
			sumRPD_P_X = (RPD_COL_P[0]) + (RPD_COL_P[1]) + (RPD_COL_P[2]) + (RPD_COL_P[3]);

			sumWeightRPD_P_Y = (RPD_ROW_P[0] * AxisRPD[3]) + (RPD_ROW_P[1] * AxisRPD[2]) + (RPD_ROW_P[2] * AxisRPD[1]) + (RPD_ROW_P[3] * AxisRPD[0]);
			sumRPD_P_Y = (RPD_ROW_P[0]) + (RPD_ROW_P[1]) + (RPD_ROW_P[2]) + (RPD_ROW_P[3]);
			
			sumWeightRPD_N_X = (RPD_COL_N[0] * AxisRPD[0]) + (RPD_COL_N[1] * AxisRPD[1]) + (RPD_COL_N[2] * AxisRPD[2]) + (RPD_COL_N[3] * AxisRPD[3]);
			sumRPD_N_X = (RPD_COL_N[0]) + (RPD_COL_N[1]) + (RPD_COL_N[2]) + (RPD_COL_N[3]);
	
			sumWeightRPD_N_Y = (RPD_ROW_N[0] * AxisRPD[3]) + (RPD_ROW_N[1] * AxisRPD[2]) + (RPD_ROW_N[2] * AxisRPD[1]) + (RPD_ROW_N[3] * AxisRPD[0]);
			sumRPD_N_Y = (RPD_ROW_N[0]) + (RPD_ROW_N[1]) + (RPD_ROW_N[2]) + (RPD_ROW_N[3]);
	
			Output_PosX = (sumWeightRPD_P_X / sumRPD_P_X);
			Output_PosY = (sumWeightRPD_P_Y / sumRPD_P_Y);
			Output_NegX = (sumWeightRPD_N_X / sumRPD_N_X); 
			Output_NegY = (sumWeightRPD_N_Y / sumRPD_N_Y);  
		}
	}		

}

#endif