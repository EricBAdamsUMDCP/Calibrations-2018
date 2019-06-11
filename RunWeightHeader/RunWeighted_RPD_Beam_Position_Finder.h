/* RPD Beam Position Code
This header file is used to insert a function which will measure a weighted average
of the beam position using the 16 channels of the RPD. The channels are aggregated by groups of 4 into rows and columns this is how the weighted average is calcualted to return a position.

It is currently set up to only return values if the type being operated on is RPD, type == 3. This can be added to with && type == 1 for a HAD condition.

This code does rely on variables NOT INSIDE OF THIS FUNCTION NAMELY

"NCH" is undefined, "type" is undefined, "side" is undefined, "channel" is undefined,
"TS_Zero" "TS_One" "TS_Four" "TS_Five" "TS_Six" "TS_Seven" are undefined

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

// last edited (if I remebered to change this... 5/7/2019 11:49:39 AM)

#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring> //colin added
#include <string> // Eric Added

#include <stdexcept>
//#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/RunWeights.h"
// I am a chemist not an englishist I cant spell

#ifndef RunWeighted_RPD_Beam_Position_Finder_Function
#define RunWeighted_RPD_Beam_Position_Finder_Function

double RPD_Beam_Position_Value_X_or_Y(double RawDataRPD[2][16][10], double Input_Weightedjeffsweights[16], double EM_BEAM_POSITION, const std::string& PosorNeg, const std::string& XorY) {
	// >>>>>>>> remove TEST_ from TEST_Input_Weightedjeffsweights[16]

	//double Input_Weightedjeffsweights[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; //activate for debugging

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////-3 min///////////3 max/////////-3 min///////////3 max// Pos does Pos side...// X gives X axis of that side.../////Give = return actual value // 
		/// ERROR MESSAGES////
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 15, RPD_Beam_Position_Finder.h");
	}
	if (XorY != "X" && XorY != "Y") {
		throw std::runtime_error("ERROR: XorY must be set to X or Y, input variable 16, RPD_Beam_Position_Finder.h");
	}
	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const int NRPD = 16;
	const int NRPDColnRow = 4;
	//const int NSIDE = 2;
	double AxisRPD[NRPDColnRow] = { -3.0, -1.0, 1.0, 3.0 };
	double valuereturned = -10;
	/////////////////////////////////////////////
	//Begin ARRAY declaration for RPD constants//
	/////////////////////////////////////////////
	/*int RPDCorrectBlockOrder[NSIDE][NRPD] = {
											 {11, 15, 2, 6, 8, 12, 1, 5, 9, 13, 0, 4, 10, 14, 3, 7}, //neg =0
											 {11, 15, 2, 5, 8, 12, 1, 6, 9, 13, 0, 4, 10, 14, 3, 7}  //pos =1
	};

	//RPD + 3/8/19
	//12, 16, 3 , 6
	//9, 13, 2 , 7
	//10, 14, 1 , 5
	//11, 15, 4, 8

	//RPD - 3/8/19 //note 7 & 6 flipped between the two bc RPD + had misswiring
	//12, 16, 3 , 7
	//9, 13, 2 , 6
	//10, 14, 1 , 5
	//11, 15, 4, 8


	int RPDCorrectBlockOrderFORPLOTTING[NSIDE][NRPD] = { /// made plots look much better but still have questions
														{11, 7, 3, 15, 12, 4, 8, 16, 5, 9, 13, 1, 6, 10, 14, 2}, //neg =0
														{11, 7, 3, 15, 12, 8, 4, 16, 5, 9, 13, 1, 6, 10, 14, 2}  //pos =1
	};*/



	float RPD_COL_P[NRPDColnRow];
	float RPD_ROW_P[NRPDColnRow];
	float RPD_COL_N[NRPDColnRow];
	float RPD_ROW_N[NRPDColnRow];


	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (EM_BEAM_POSITION != -10 && Input_Weightedjeffsweights[15] != -10 && Input_Weightedjeffsweights[0] != -10){ // -10  is the value returned by function if something is wrong with the data. This indicates it should skip an event
	
		//iterates through all channels of both ZDC + and -
	
	
		   // Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
		double fC_of_TS45_Summed = 0;
		double fC_of_TS456_Summed = 0;
	
	
	
	//// neeed TO INCLUDE AND WRITE A TRANSLATOR TO TURN INPUT RAW DATA INTO CORRECT BLOCK ORDER
		
		if (PosorNeg == "Neg") {
			for (int channel = 0; channel < NRPD; channel++){
				//remeber TS start at 0 DONT SUBTRACT
				fC_of_TS45_Summed  = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5];
				fC_of_TS456_Summed = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5] + RawDataRPD[0][channel][6];

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {
					if (XorY == "Y"){

						if (channel == 11 || channel == 15 || channel == 2 || channel == 6) { RPD_ROW_N[0]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 8  || channel == 12 || channel == 1 || channel == 5) { RPD_ROW_N[1]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 9  || channel == 13 || channel == 0 || channel == 4) { RPD_ROW_N[2]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) { RPD_ROW_N[3]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}			//R0
					}		///////////////////////////////////////////////// IS THE ORDERING OF THE OUTPUT JEFF ARRAYS MATH DATA??																									 										//R1
					else if (XorY == "X"){

						if (channel == 10 || channel == 9  || channel == 8  || channel == 11) { RPD_COL_N[0] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_N[1] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			//R3							
						if (channel == 3  || channel == 0  || channel == 1  || channel == 2)  { RPD_COL_N[2] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			  //C3 C2 C1 C0					
						if (channel == 7  || channel == 4  || channel == 5  || channel == 6)  { RPD_COL_N[3] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}
					}
				}
			}
		}                                                                                                                                            
		else if (PosorNeg == "Pos") { 
			for (int channel = 0; channel < NRPD; channel++){

				fC_of_TS45_Summed  = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5];
				fC_of_TS456_Summed = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5] + RawDataRPD[1][channel][6];  

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[1][channel][7] <= RawDataRPD[1][channel][5]) && (RawDataRPD[1][channel][1] / RawDataRPD[1][channel][0] < 1000) && (RawDataRPD[1][channel][0] != 0)) {
					if (XorY == "Y"){

						if (channel == 11 || channel == 15 || channel == 2 || channel == 5) { RPD_ROW_P[0]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 8  || channel == 12 || channel == 1 || channel == 6) { RPD_ROW_P[1]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 9  || channel == 13 || channel == 0 || channel == 4) { RPD_ROW_P[2]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) { RPD_ROW_P[3]   += fC_of_TS456_Summed /* * Input_Weightedjeffsweights[channel]*/;}			//R0
					}	
					else if (XorY == "X"){	
																															 							                 	//R1
						if (channel == 10 || channel == 9  || channel == 8  || channel == 11) { RPD_COL_P[0] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_P[1] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			//R3							
						if (channel == 3  || channel == 0  || channel == 1  || channel == 2)  { RPD_COL_P[2] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}			  //C3 C2 C1 C0					
						if (channel == 7  || channel == 4  || channel == 6  || channel == 5)  { RPD_COL_P[3] += fC_of_TS456_Summed * Input_Weightedjeffsweights[channel];}
					}
				}
			}
		}
		
		double WeightedAverageRPD_P_X;
		double WeightedAverageRPD_P_Y;
		double WeightedAverageRPD_N_X;
		double WeightedAverageRPD_N_Y;
		double sumWeightRPD_P_X, sumRPD_P_X, sumWeightRPD_P_Y, sumRPD_P_Y, sumWeightRPD_N_X, sumRPD_N_X, sumWeightRPD_N_Y, sumRPD_N_Y;
	
		if (PosorNeg == "Pos"){
			if (XorY == "X"){
				if (RPD_COL_P[0] != 0.0 && RPD_COL_P[1] != 0.0 && RPD_COL_P[2] != 0.0 && RPD_COL_P[3] != 0.0) {
			
					sumWeightRPD_P_X = (RPD_COL_P[0] * AxisRPD[0]) + (RPD_COL_P[1] * AxisRPD[1]) + (RPD_COL_P[2] * AxisRPD[2]) + (RPD_COL_P[3] * AxisRPD[3]);
					sumRPD_P_X = (RPD_COL_P[0]) + (RPD_COL_P[1]) + (RPD_COL_P[2]) + (RPD_COL_P[3]);
	
					WeightedAverageRPD_P_X = (sumWeightRPD_P_X / sumRPD_P_X);
	
					valuereturned = WeightedAverageRPD_P_X;
				}
				else {
					valuereturned = -101;
				}
			}
			else if (XorY == "Y"){
				if (RPD_ROW_P[0] != 0.0 && RPD_ROW_P[1] != 0.0 && RPD_ROW_P[2] != 0.0 && RPD_ROW_P[3] != 0.0) {
			
					sumWeightRPD_P_Y = (RPD_ROW_P[0] * AxisRPD[3]) + (RPD_ROW_P[1] * AxisRPD[2]) + (RPD_ROW_P[2] * AxisRPD[1]) + (RPD_ROW_P[3] * AxisRPD[0]);
					sumRPD_P_Y = (RPD_ROW_P[0]) + (RPD_ROW_P[1]) + (RPD_ROW_P[2]) + (RPD_ROW_P[3]);
	
					WeightedAverageRPD_P_Y = (sumWeightRPD_P_Y / sumRPD_P_Y);
	
					valuereturned = WeightedAverageRPD_P_Y;
				}
				else{
					valuereturned = -102;
				}
			}
		}
		else if (PosorNeg == "Neg"){
			if (XorY == "X"){
				if (RPD_COL_N[0] != 0.0 && RPD_COL_N[1] != 0.0 && RPD_COL_N[2] != 0.0 && RPD_COL_N[3] != 0.0) {
			
					sumWeightRPD_N_X = (RPD_COL_N[0] * AxisRPD[0]) + (RPD_COL_N[1] * AxisRPD[1]) + (RPD_COL_N[2] * AxisRPD[2]) + (RPD_COL_N[3] * AxisRPD[3]);
					sumRPD_N_X = (RPD_COL_N[0]) + (RPD_COL_N[1]) + (RPD_COL_N[2]) + (RPD_COL_N[3]);
	
					WeightedAverageRPD_N_X = (sumWeightRPD_N_X / sumRPD_N_X);
	
					valuereturned = WeightedAverageRPD_N_X;
				}
				else{
					valuereturned = -103;
				}
			}
			else if (XorY == "Y"){
				if (RPD_ROW_N[0] != 0.0 && RPD_ROW_N[1] != 0.0 && RPD_ROW_N[2] != 0.0 && RPD_ROW_N[3] != 0.0) {
			
					sumWeightRPD_N_Y = (RPD_ROW_N[0] * AxisRPD[3]) + (RPD_ROW_N[1] * AxisRPD[2]) + (RPD_ROW_N[2] * AxisRPD[1]) + (RPD_ROW_N[3] * AxisRPD[0]);
					sumRPD_N_Y = (RPD_ROW_N[0]) + (RPD_ROW_N[1]) + (RPD_ROW_N[2]) + (RPD_ROW_N[3]);
	
					WeightedAverageRPD_N_Y = (sumWeightRPD_N_Y / sumRPD_N_Y);
	
					valuereturned = WeightedAverageRPD_N_Y;
				}
				else{
					valuereturned = -104;
				}
			}
		}

		/// below used for debugging purposes
		/* if((sumWeightRPD_N_X/sumRPD_N_X) == -1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == -3.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 3.0){ //couts to let user know if any zeros are returned
		cout <<  "sumWeightRPD_P_X " <<  sumWeightRPD_P_X << endl;
		cout << (RPD_COL_P[0] * AxisRPD[0]) << "  " << (RPD_COL_P[1] * AxisRPD[1]) << "  " << (RPD_COL_P[2] * AxisRPD[2]) << "  " << (RPD_COL_P[3] * AxisRPD[3]) << endl;
		cout << "sumRPD_P_X " << sumRPD_P_X << endl;
		cout << (RPD_COL_P[0]) << "  " << (RPD_COL_P[1]) << "  " << (RPD_COL_P[2]) << "  " << (RPD_COL_P[3]) << endl;
		} */
		/// above used for debugging purposes
	}
	else if (EM_BEAM_POSITION == -10 || Input_Weightedjeffsweights[15] == -10 || Input_Weightedjeffsweights[0] == -10){
		valuereturned = -105;
	}

	return valuereturned;
}

#endif

