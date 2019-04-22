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
//last edited(if I didn't forget to change this..): 4/22/2019 6:22:58 PM

#include <iostream>
#include <cstdio>

#ifndef EM_Beam_Position_Cut_and_Value_Header
#define EM_Beam_Position_Cut_and_Value_Header //when making a header headerr name must be different than function name


/*ERIC notes I dont know if this osftware will store the value after each N increase as intended.... because it will relaunch the function and the values are inside of the scope....*/




double EM_Beam_Position_Cut_and_Value(double TS_Four, double TS_Five, int n, int side, int type, int channel, double EM_CUT_P_Xmin, double EM_CUT_P_Xmax, double EM_CUT_N_Xmin, double EM_CUT_N_Xmax, int P, int N) {
	// every time this function is called the variables are not set, right....?
	const int NCH = 5;
	const int NSIDE = 2;
	float EM[NCH] = { -4,-2,0,2,4 };
	
	float EMweigths[NSIDE][NCH] = {
								   {1, 1, 1, 1, 1/* 1.45,1.64,1.00,0.72,0.76 */},
                                   {1, 1, 1, 1, 1/* 2.39,1.73,1.00,0.70,0.63 */}
								  };
	
	

	static double EMChannelP[NCH];
	static double EMChannelN[NCH];
	double sumEMPos, sumEMNeg, sumWeightEMPos, sumWeightEMNeg;
	int	   P_EM_Return = 0;
	int	   N_EM_Return = 0;
	
	if (n == 0) { // this says if we have just restarted at channel 0 (out of 49) set all values for the EM channels to zero, this is so we don't sum over many events
		for (int k = 0; k < NCH; k++) {
			EMChannelN[k] = 0;
			EMChannelP[k] = 0;
		}
	}
	
	if (type == 0) { // EM section		//EM section ends at n = 13 rpd begins later so this EM will run first
		if (side == 1) { //pos side
			switch (channel) {
			case 0:										// potential bug that shouldnt occour if same loop holding this function is used, assmuing each channel only called once per event
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelP[0] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 1:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelP[1] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 2:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelP[2] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 3:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelP[3] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 4:
				if (TS_Four > 100 && TS_Five > 100) {  //currently as this stands if the TS fC condition is not met the code will leave a un filled memeory location for one of the variables may scrwew up beam position
					EMChannelP[4] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			}
		}
		else { //neg side
			switch (channel) {
			case 0:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelN[0] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 1:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelN[1] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 2:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelN[2] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 3:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelN[3] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			case 4:
				if (TS_Four > 100 && TS_Five > 100) {
					EMChannelN[4] = (TS_Four + TS_Five) * EMweigths[side][channel];
				}
				break;
			}
		}
	}
	
	
	
	if (type == 3 /*RPD*/) {
		if (EMChannelP[0] != 0 && EMChannelP[1] != 0 && EMChannelP[2] != 0 && EMChannelP[3] != 0 && EMChannelP[4] != 0 && EMChannelN[0] != 0 && EMChannelN[1] != 0 && EMChannelN[2] != 0 && EMChannelN[3] != 0 && EMChannelN[4] != 0){
			double WeightedAvg_Pos;
			double WeightedAvg_Neg;
			
			sumEMPos = (EMChannelP[0] + EMChannelP[1] + EMChannelP[2] + EMChannelP[3] + EMChannelP[4]);
			sumWeightEMPos = ((EMChannelP[0] * EM[0]) + (EMChannelP[1] * EM[1]) + (EMChannelP[2] * EM[2]) + (EMChannelP[3] * EM[3]) + (EMChannelP[4] * EM[4]));
			WeightedAvg_Pos = (sumWeightEMPos / sumEMPos);
			//cout << "EMChannelP[0], EMChannelP[1], EMChannelP[2],  EMChannelP[3],  EMChannelP[4] " << EMChannelP[0] << " " << EMChannelP[1] << " " << EMChannelP[2] << " " << EMChannelP[3] << " " << EMChannelP[4];
		
		
			sumEMNeg = (EMChannelN[0] + EMChannelN[1] + EMChannelN[2] + EMChannelN[3] + EMChannelN[4]);
			sumWeightEMNeg = ((EMChannelN[0] * EM[0]) + (EMChannelN[1] * EM[1]) + (EMChannelN[2] * EM[2]) + (EMChannelN[3] * EM[3]) + (EMChannelN[4] * EM[4]));
			WeightedAvg_Neg = (sumWeightEMNeg / sumEMNeg);
			//cout << "EMChannelN[0], EMChannelN[1], EMChannelN[2],  EMChannelN[3],  EMChannelN[4] " << EMChannelN[0] << " " << EMChannelN[1] << " " << EMChannelN[2] << " " << EMChannelN[3] << " " << EMChannelN[4];
		
		
	
			//cout << "WeightedAvg_Pos " << WeightedAvg_Pos << endl;
			//cout << "WeightedAvg_Neg " << WeightedAvg_Neg << endl;
			//cout << "n" << n << endl;
			
			
			
			
			if ((EM_CUT_N_Xmin < WeightedAvg_Neg) && (WeightedAvg_Neg < EM_CUT_N_Xmax)) { N_EM_Return = 1; }
			if ((EM_CUT_P_Xmin < WeightedAvg_Pos) && (WeightedAvg_Pos < EM_CUT_P_Xmax)) { P_EM_Return = 1; }
			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			if (N != 1 && P != 1) {
				if (P_EM_Return == 1 && N_EM_Return == 1) {
					//cout << "conditions are met!" << endl;
					return 1;
				} // software outputs value of one if both beams are in acceptable windows
			}
			else if (P_EM_Return == 1 && N_EM_Return == 1) {
				if (N == 1 && P != 1) {
					return WeightedAvg_Neg;
				} //if N input is 1 returns EM neg side beam position
				if (P == 1 && N != 1) {
					return WeightedAvg_Pos;
				} //if P input is 1 returns EM pos side beam position
			}
			/// note: The program will preferentially select N input = 1 over P input!!!
		}
		else {
			return -10; // -10 is the standard bad value or event return number if the function returns this something was wrong and the other functions will act accordingly
		}
	
	}	///spits our weighted position for either Neg or Pos side

	
}


#endif
