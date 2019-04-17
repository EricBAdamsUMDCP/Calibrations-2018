/* EM Beam Position Code
This header file is used to insert a function which will measure a weighted average
of the beam position using the 5 channels of the EM section per each EM.

It is currently set up to only return values if the type being operated on is RPD, type == 3. This can be added to with && type == 1 for a HAD condition.

This code does rely on variables NOT INSIDE OF THIS FUNCTION NAMELY

"NCH" is undefined, "type" is undefined, "side" is undefined, "channel" is undefined,
"TS_Four" is undefined, "TS_Five" is undefined

These are defined in the code(s) designed to use this header file.

Adjust this as necessary

Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS in the winter.

4/9/19 */

#include <iostream>
#include <cstdio>
#include <cstring> //colin added
#include <string> // Eric Added

#ifndef EM_Beam_Position_Cut_and_Value_Header
#define EM_Beam_Position_Cut_and_Value_Header //when making a header headerr name must be different than function name


/*ERIC notes I dont know if this software will store the value after each N increase as intended.... because it will relaunch the function and the values are inside of the scope....*/




double EM_Beam_Position_Cut_and_Value(double TS_Four, double TS_Five, int n, int side, int type, int channel, double EM_CUT_Xmin, double EM_CUT_Xmax, const std::string& PosorNeg, const std::string& CheckorGive) {
	if ( n > 18) { //only operates on EM and HAD sections	(hjad bc they are there and to much coding to remove
		//ERROR MESSAGES
		if (EM_CUT_Xmin < -4.0 || EM_CUT_Xmax > 4.0) {
			throw std::runtime_error("ERROR: EM bounds Max and Min must not exceed 4 or be inferior to -4 (the bounds of the EM section centers), input variables 7-10, EM_Beam_Position_Cut_and_Value_function.h");
		}
		if ( TS_Four < 0 || TS_Five < 0){
			throw std::runtime_error("ERROR: One of the passed timeslices had a negative value... thats unphysical, TS inputs, EM_Beam_Position_Cut_and_Value_function.h");
		}
		if (n > 49) {
			throw std::runtime_error("Hey they were only 49 channels in the 2018 PbPb run, this will throw off the clock cycle ARE YOU SURE YOU WANT A VALUE GREATER THAN 50???, INPUT VARIABLE 3, EM_Beam_Position_Cut_and_Value_function.h");
		}
		if (n < 0) {
			throw std::runtime_error("n cannot be less than zero, you cannot have a negative number of channels..., input variable 3, EM_Beam_Position_Cut_and_Value_function.h");
		}
		
		// every time this function is called the variables are not set, right....? 
		const int NCH = 5;
		float EM[NCH] = { -4,-2,0,2,4 };
	
	
	
		static double EMChannelP[NCH];
		static double EMChannelN[NCH];
		//double sumEMPos, SumEMNeg, sumWeightEMPos, sumWeightEMNeg;
	
		if (n == 0) { // this says if we have just restarted at channel 0 (out of 49) set all values for the EM channels to zero, this is so we don't sum over many events
			for (int k = 0; k < NCH; k++) {
				EMChannelN[k] = 0;
				EMChannelP[k] = 0;
			}
		}
	
		if (type == 0) { // EM section		//EM section ends at n = 13 rpd begins later so this EM will run first
			if (side == 1) { //pos side
				if (PosorNeg  == "Pos"){
					switch (channel) {
					case 0:										// potential bug that shouldnt occour if same loop holding this function is used, assmuing each channel only called once per event
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelP[0] = TS_Four + TS_Five;
						}
						break;
					case 1:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelP[1] = TS_Four + TS_Five;
						}
						break;
					case 2:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelP[2] = TS_Four + TS_Five;
						}
						break;
					case 3:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelP[3] = TS_Four + TS_Five;
						}
						break;
					case 4:
						if (TS_Four > 100 && TS_Five > 100) {  //currently as this stands if the TS fC condition is not met the code will leave a un filled memeory location for one of the variables may scrwew up beam position
							EMChannelP[4] = TS_Four + TS_Five;
						}
						break;
					}
				}
			}
			else { //neg side
				if (PosorNeg  == "Neg"){
					switch (channel) {
					case 0:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelN[0] = TS_Four + TS_Five;
						}
						break;
					case 1:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelN[1] = TS_Four + TS_Five;
						}
						break;
					case 2:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelN[2] = TS_Four + TS_Five;
						}
						break;
					case 3:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelN[3] = TS_Four + TS_Five;
						}
						break;
					case 4:
						if (TS_Four > 100 && TS_Five > 100) {
							EMChannelN[4] = TS_Four + TS_Five;
						}
						break;
					}
				}
			}
		}
		
		double sumEMPos;
		double sumEMNeg;
		double sumWeightEMPos; 
		double sumWeightEMNeg;
		double WeightedAvg_Pos;
		double WeightedAvg_Neg;
		
		//if (n == 17) { //only does calculations once per event after all em channels have been analyzed
			if ( PosorNeg == "Pos"){
				sumEMPos = (EMChannelP[0] + EMChannelP[1] + EMChannelP[2] + EMChannelP[3] + EMChannelP[4]);
				sumWeightEMPos = ((EMChannelP[0] * EM[0]) + (EMChannelP[1] * EM[1]) + (EMChannelP[2] * EM[2]) + (EMChannelP[3] * EM[3]) + (EMChannelP[4] * EM[4]));
				WeightedAvg_Pos = (sumWeightEMPos / sumEMPos);
				
				if ((EM_CUT_Xmin < WeightedAvg_Pos) && (WeightedAvg_Pos < EM_CUT_Xmax)) { 
					if ( CheckorGive == "Check") {
						return 1;
					}
					if ( CheckorGive == "Give") {
						return WeightedAvg_Pos;
					}
				}		
			}
			if ( PosorNeg == "Neg"){
				sumEMNeg = (EMChannelN[0] + EMChannelN[1] + EMChannelN[2] + EMChannelN[3] + EMChannelN[4]);
				sumWeightEMNeg = ((EMChannelN[0] * EM[0]) + (EMChannelN[1] * EM[1]) + (EMChannelN[2] * EM[2]) + (EMChannelN[3] * EM[3]) + (EMChannelN[4] * EM[4]));
				WeightedAvg_Neg = (sumWeightEMNeg / sumEMNeg);
			
				if ((EM_CUT_Xmin < WeightedAvg_Neg) && (WeightedAvg_Neg < EM_CUT_Xmax)) { 
					if ( CheckorGive == "Check"){
						return 1;
					}
					if ( CheckorGive == "Give"){
						return WeightedAvg_Neg;
					}
				}
			}
		}	
	//}
}

#endif