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

#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring> //colin added
#include <string> // Eric Added

#include <stdexcept>
// I am a chemist not an englishist I cant spell

#ifndef RPD_Beam_Position_Finder_Function
#define RPD_Beam_Position_Finder_Function

double RPD_Beam_Position_Finder(double TS_Zero, double TS_One, double TS_Four, double TS_Five, double TS_Six, double TS_Seven, int n, 
                                int side, int type, int channel, double RPDXmin, double RPDXmax, double RPDYmin, double RPDYmax,
                                const std::string& PosorNeg, const std::string& XorY, const std::string& CheckorGive) {
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////-3 min///////////3 max/////////-3 min///////////3 max// Pos does Pos side...// X gives X axis of that side.../////Give = return actual value // 
		/// ERROR MESSAGES////
	
	if (CheckorGive != "Check" && CheckorGive != "Give") {
		throw std::runtime_error("ERROR: CheckorGive must be set to Check or Give, input variable 17, RPD_Beam_Position_Finder.h");
	}
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 15, RPD_Beam_Position_Finder.h");
	}
	if (XorY != "X" && XorY != "Y") {
		throw std::runtime_error("ERROR: XorY must be set to X or Y, input variable 16, RPD_Beam_Position_Finder.h");
	}
	if (RPDXmin < -3.0 || RPDXmax > 3.0 || RPDYmin < -3.0 || RPDYmax > 3.0) {
		throw std::runtime_error("ERROR: RPD bounds Max and Min must not exceed 3 or be inferior to -3 (the bounds of the RPD quartz block centers), input variables 11-14, RPD_Beam_Position_Finder.h");
	}
	if ( TS_Zero < 0 || TS_One < 0 || TS_Four < 0 || TS_Five < 0 || TS_Six < 0 || TS_Seven < 0){
		throw std::runtime_error("ERROR: One of the passed timeslices had a negative value... thats unphysical, TS inputs, RPD_Beam_Position_Finder.h");
	}
	if (n > 49) {
		throw std::runtime_error("Hey they were only 49 channels in the 2018 PbPb run, this will throw off the clock cycle ARE YOU SURE YOU WANT A VALUE GREATER THAN 50???, INPUT VARIABLE 7, RPD_Beam_Position_Finder.h");
	}
	if (n < 0) {
		throw std::runtime_error("n cannot be less than zero, you cannot have a negative number of channels..., input variable 7, RPD_Beam_Position_Finder.h");
	}
	

	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const int NChannels = 50;
	const int NTS = 10;// number of timeslices
	const int NRPD = 16;
	const int NRPDColnRow = 4;
	const int NSIDE = 2;
	double AxisRPD[NRPDColnRow] = { -3.0, -1.0, 1.0, 3.0 };

	double WeightedAverageRPD_P_Y;
	double WeightedAverageRPD_P_X;
	                             ;
	double WeightedAverageRPD_N_Y;
	double WeightedAverageRPD_N_X;
	

	float RPD_COL_P[NRPDColnRow];
	float RPD_ROW_P[NRPDColnRow];
	float RPD_COL_N[NRPDColnRow];
	float RPD_ROW_N[NRPDColnRow];


	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	//void * memset ( void * ptr, int value, size_t num );
	if (n == 0) {
		memset(RPD_COL_P, 0, sizeof(RPD_COL_P)); //every event reinitialize array to 0 ON THE BYTE LEVEL (Logic will not work for values other than 0)!!!
		memset(RPD_ROW_P, 0, sizeof(RPD_ROW_P));
		memset(RPD_COL_N, 0, sizeof(RPD_COL_N));
		memset(RPD_ROW_N, 0, sizeof(RPD_ROW_N));
	}

	//iterates through all channels of both ZDC + and -


	   // Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
	double fC_of_TS45_Summed = TS_Four + TS_Five;
	double fC_of_TS456_Summed = TS_Four + TS_Five + TS_Six;




	if (type == 3) {
		if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (TS_Seven <= TS_Five) && (TS_One / TS_Zero < 1000) && (TS_Zero != 0)) {
			if (side == 0) {
				//if (PosorNeg == "Neg"){
					//if (XorY == "Y") {
						/// should i use histogram bins instead here because it will be the same data as upposed to 2 different ????
						if (channel == 11 || channel == 15 || channel == 2 || channel == 6) { RPD_ROW_N[0] += fC_of_TS456_Summed; }
						if (channel ==  8 || channel == 12 || channel == 1 || channel == 5) { RPD_ROW_N[1] += fC_of_TS456_Summed; }
						if (channel ==  9 || channel == 13 || channel == 0 || channel == 4) { RPD_ROW_N[2] += fC_of_TS456_Summed; }
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) { RPD_ROW_N[3] += fC_of_TS456_Summed; }	
				//	}																															//R0
					//if (XorY == "X") {																											//R1
						if (channel == 10 || channel ==  9 || channel ==  8 || channel == 11) { RPD_COL_N[3] += fC_of_TS456_Summed; }			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_N[2] += fC_of_TS456_Summed; }			//R3							
						if (channel ==  3 || channel ==  0 || channel ==  1 || channel ==  2) { RPD_COL_N[1] += fC_of_TS456_Summed; }			  //C3 C2 C1 C0					
						if (channel ==  7 || channel ==  4 || channel ==  5 || channel ==  6) { RPD_COL_N[0] += fC_of_TS456_Summed; }
					//}
				//}
			}
			else {
				//if (PosorNeg == "Pos"){
					//if (XorY == "Y") {
						if (channel == 11 || channel == 15 || channel == 2 || channel == 5) { RPD_ROW_P[0] += fC_of_TS456_Summed; }
						if (channel ==  8 || channel == 12 || channel == 1 || channel == 6) { RPD_ROW_P[1] += fC_of_TS456_Summed; }
						if (channel ==  9 || channel == 13 || channel == 0 || channel == 4) { RPD_ROW_P[2] += fC_of_TS456_Summed; }
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) { RPD_ROW_P[3] += fC_of_TS456_Summed; }			   
					//}																															//R0
					//if (XorY == "X") {																											//R1
						if (channel == 10 || channel ==  9 || channel ==  8 || channel == 11) { RPD_COL_P[3] += fC_of_TS456_Summed; }			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_P[2] += fC_of_TS456_Summed; }			//R3							
						if (channel ==  3 || channel ==  0 || channel ==  1 || channel ==  2) { RPD_COL_P[1] += fC_of_TS456_Summed; }			  //C3 C2 C1 C0					
						if (channel ==  7 || channel ==  4 || channel ==  6 || channel ==  5) { RPD_COL_P[0] += fC_of_TS456_Summed; }
					//}
				//}
			}
		}
	}

	double sumWeightRPD_P_X, sumRPD_P_X, sumWeightRPD_P_Y, sumRPD_P_Y, sumWeightRPD_N_X, sumRPD_N_X, sumWeightRPD_N_Y, sumRPD_N_Y;
	
	 // last channel of Neg RPD
		//if (PosorNeg == "Neg") {	
			//if (XorY == "X"){
				if (RPD_COL_N[0] > 0 && RPD_COL_N[1] > 0 && RPD_COL_N[2] > 0 && RPD_COL_N[3] > 0) {
			
					sumWeightRPD_N_X = (RPD_COL_N[0] * AxisRPD[0]) + (RPD_COL_N[1] * AxisRPD[1]) + (RPD_COL_N[2] * AxisRPD[2]) + (RPD_COL_N[3] * AxisRPD[3]);
					sumRPD_N_X = (RPD_COL_N[0]) + (RPD_COL_N[1]) + (RPD_COL_N[2]) + (RPD_COL_N[3]);
				}
			//}
			//if (XorY == "Y"){
				if (RPD_ROW_N[0] > 0 && RPD_ROW_N[1] > 0 && RPD_ROW_N[2] > 0 && RPD_ROW_N[3] > 0) {
			
					sumWeightRPD_N_Y = (RPD_ROW_N[0] * AxisRPD[3]) + (RPD_ROW_N[1] * AxisRPD[2]) + (RPD_ROW_N[2] * AxisRPD[1]) + (RPD_ROW_N[3] * AxisRPD[0]);
					sumRPD_N_Y = (RPD_ROW_N[0]) + (RPD_ROW_N[1]) + (RPD_ROW_N[2]) + (RPD_ROW_N[3]);
				}
			//}
		//}
	
	
		//if (PosorNeg == "Pos"){ // last channel of Pos RPD
			//if (XorY == "X") {
				if (RPD_COL_P[0] > 0 && RPD_COL_P[1] > 0 && RPD_COL_P[2] > 0 && RPD_COL_P[3] > 0) {
			
					sumWeightRPD_P_X = (RPD_COL_P[0] * AxisRPD[0]) + (RPD_COL_P[1] * AxisRPD[1]) + (RPD_COL_P[2] * AxisRPD[2]) + (RPD_COL_P[3] * AxisRPD[3]);
					sumRPD_P_X = (RPD_COL_P[0]) + (RPD_COL_P[1]) + (RPD_COL_P[2]) + (RPD_COL_P[3]);
				}
			//}
			//if (XorY == "Y") {
				if (RPD_ROW_P[0] > 0 && RPD_ROW_P[1] > 0 && RPD_ROW_P[2] > 0 && RPD_ROW_P[3] > 0) {
			
					sumWeightRPD_P_Y = (RPD_ROW_P[0] * AxisRPD[3]) + (RPD_ROW_P[1] * AxisRPD[2]) + (RPD_ROW_P[2] * AxisRPD[1]) + (RPD_ROW_P[3] * AxisRPD[0]);
					sumRPD_P_Y = (RPD_ROW_P[0]) + (RPD_ROW_P[1]) + (RPD_ROW_P[2]) + (RPD_ROW_P[3]);
				}
		//	}
	//	}
	
	
	
	WeightedAverageRPD_P_Y = (sumWeightRPD_P_Y / sumRPD_P_Y);
	WeightedAverageRPD_P_X = (sumWeightRPD_P_X / sumRPD_P_X);
	
	WeightedAverageRPD_N_Y = (sumWeightRPD_N_Y / sumRPD_N_Y);
	WeightedAverageRPD_N_X = (sumWeightRPD_N_X / sumRPD_N_X);
	
	

	/// below used for debugging purposes
	/* if((sumWeightRPD_N_X/sumRPD_N_X) == -1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == -3.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 3.0){ //couts to let user know if any zeros are returned
	cout <<  "sumWeightRPD_P_X " <<  sumWeightRPD_P_X << endl;
	cout << (RPD_COL_P[0] * AxisRPD[0]) << "  " << (RPD_COL_P[1] * AxisRPD[1]) << "  " << (RPD_COL_P[2] * AxisRPD[2]) << "  " << (RPD_COL_P[3] * AxisRPD[3]) << endl;
	cout << "sumRPD_P_X " << sumRPD_P_X << endl;
	cout << (RPD_COL_P[0]) << "  " << (RPD_COL_P[1]) << "  " << (RPD_COL_P[2]) << "  " << (RPD_COL_P[3]) << endl;
	} */
	/// above used for debugging purposes


	if (PosorNeg == "Pos") {
		if (XorY == "X") {
			if (RPDXmin < WeightedAverageRPD_P_X && WeightedAverageRPD_P_X < RPDXmax) {
				if (CheckorGive == "Check") {
					return 1;
				}
				if (CheckorGive == "Give") {
					return  WeightedAverageRPD_P_X;
				}
			}
		}
		if (XorY == "Y") {
			if (RPDYmin < WeightedAverageRPD_P_Y && WeightedAverageRPD_P_Y < RPDYmax) {
				if (CheckorGive == "Check") {
					return 1;
				}
				if (CheckorGive == "Give") {
					return  WeightedAverageRPD_P_Y;
				}
			}
		}
	}
	if (PosorNeg == "Neg") {
		if (XorY == "X") {
			if (RPDXmin < WeightedAverageRPD_N_X && WeightedAverageRPD_N_X < RPDXmax) {
				if (CheckorGive == "Check") {
					return 1;
				}
				if (CheckorGive == "Give") {
					return WeightedAverageRPD_N_X;
				}
			}
		}
		if (XorY == "Y") {
			if (RPDYmin < WeightedAverageRPD_N_Y && WeightedAverageRPD_N_Y < RPDYmax) {
				if (CheckorGive == "Check") {
					return 1;
				}
				if (CheckorGive == "Give") {
					return WeightedAverageRPD_N_Y;
				}
			}
		}
	}
}

#endif

