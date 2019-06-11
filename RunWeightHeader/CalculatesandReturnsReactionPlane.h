/*REACTION PLANE CALCULATOR 

This code uses the reaction plane detector to generate the event plane

it needs the fC of all 16 blocks in a RPD the weights by which to calibrate the data a user input of pos or neg and this code outputs and array of weighter fC with their respective x y distributions

//Thanks to Oliver and Mate for their code which I used as a reference to something I hope has no bugs in geenrating the event plane

Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS<< "\n"; in the winter.

4/12/19 */

// last edited (if I remebered to change this... 6/11/2019 11:48:11 AM)


#include <string>
#include <stdexcept>
#include <math.h> //for atan2 as it is a math fu c could also use tmath but i want to avoid any root outside of plotting

#ifndef CalculatesandReturnsReactionPlane
#define CalculatesandReturnsReactionPlane

void CalculatesandReturnsRXN_Plane(double RawDataRPD[2][16][10], double Input_Weightedjeffsweights[16], const std::string& PosorNeg, const std::string& V1orV2, double INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[2], double INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[2], double (&OutPut_RPDfC_X_Y_coord)[16], double (&OutPut_RPD_Event_Plane_Psi)){
	//errors ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////array is as follows [X, Y]
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 3, CalculatesandReturnsReactionPlane.h");
	}

	if (V1orV2 != "V1" && V1orV2 != "V2") {
		throw std::runtime_error("ERROR: V1orV2 must be set to V1 or V2, input variable 4 , CalculatesandReturnsReactionPlane.h");
	}

	//if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {}	
	if ( Input_Weightedjeffsweights[15] != -10 && Input_Weightedjeffsweights[0] != -10){ // -10 is the value returned by functions if a bad event was measured and the functions are designed to ignore bad evets
	//decleration of constants and arrays
		const int NSIDE = 2;
		const int NRPD = 16;
		float  RPDSignalSummed[NSIDE] = {0};
		
		float  cosv1RPDsum[NSIDE] = {0};
		float  sinv1RPDsum[NSIDE] = {0};
		float Recentered_Q_Observed_V1_X = 0;
		float Recentered_Q_Observed_V1_Y = 0;

		float  cosv2RPDsum[NSIDE] = {0};
		float  sinv2RPDsum[NSIDE] = {0};
		float Recentered_Q_Observed_V2_X = 0;
		float Recentered_Q_Observed_V2_Y = 0;
		//look up tables for RPD positions created by EBA 5/15/19 
		double X_position_cm[2][16] = {{1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1},  //neg
								   	   {1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1}}; //pos
	
		double Y_position_cm[2][16] = {{-1, 1, 3, -3, -1, 1, 3, -3, 1, -1, -3, 3, 1, -1, -3, 3},  //neg
									   {-1, 1, 3, -3, -1, 3, 1, -3, 1, -1, -3, 3, 1, -1, -3, 3}}; //pos 
	
		// for recentering calibration, from Qobs distributions
	
	
		// Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
		double fC_of_TS45_Summed = 0;
		double fC_of_TS456_Summed = 0;
	
	
			//DOUBLE CHECK THESE NUMBERS AND MAKE SURE THEY MATCH THEIR RESPECTIVE QB POSITION THEY WERE CALCULATED SORT OF SLOPPLY ean 6/3/19 4 PM						   
		float RPDBlocksInPhi[NSIDE][NRPD] = {{-0.785398, 0.785398, 1.24905, -1.24905, -0.321751, 0.321751, 0.785398, -0.785398, 2.81984, -2.81984, -2.35619, 2.35619, 2.35619, -2.35619, -1.89255, 1.89255}, //NEG
		 									 {-0.785398, 0.785398, 1.24905, -1.24905, -0.321751, 0.785398, 0.321751, -0.785398, 2.81984, -2.81984, -2.35619, 2.35619, 2.35619, -2.35619, -1.89255, 1.89255}};
	
  	
  		if (PosorNeg == "Pos"){

  			for (int channel = 0; channel < NRPD; channel++){
		    	fC_of_TS45_Summed  = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5];
				fC_of_TS456_Summed = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5] + RawDataRPD[1][channel][6];

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[1][channel][7] <= RawDataRPD[1][channel][5]) && (RawDataRPD[1][channel][1] / RawDataRPD[1][channel][0] < 1000) && (RawDataRPD[1][channel][0] != 0)) {
					RPDSignalSummed[1] += fC_of_TS456_Summed;
					
					if (V1orV2 == "V1"){
						cosv1RPDsum[1] += cos(1*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 						sinv1RPDsum[1] += sin(1*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 					}
 					else{
 						cosv2RPDsum[1] += cos(2*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 						sinv2RPDsum[1] += sin(2*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
					}

					//ask alice how recentering works


				}
			}

			if (V1orV2 == "V1"){
				Recentered_Q_Observed_V1_X = (cosv1RPDsum[1]/RPDSignalSummed[1]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[0])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[0]; 
				Recentered_Q_Observed_V1_Y = (sinv1RPDsum[1]/RPDSignalSummed[1]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[1])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[1];
			
				OutPut_RPD_Event_Plane_Psi = atan2(Recentered_Q_Observed_V1_Y, Recentered_Q_Observed_V1_X); // FOR V1
			}
			else{
				Recentered_Q_Observed_V2_X = (cosv2RPDsum[1]/RPDSignalSummed[1]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[0])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[0];
				Recentered_Q_Observed_V2_Y = (sinv2RPDsum[1]/RPDSignalSummed[1]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[1])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[1];
				
				OutPut_RPD_Event_Plane_Psi = atan2(Recentered_Q_Observed_V2_Y, Recentered_Q_Observed_V2_X)/2; // FOR V2
			}
		}
		else{

		    for (int channel = 0; channel < NRPD; channel++){
				//remeber TS start at 0 DONT SUBTRACT
				fC_of_TS45_Summed  = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5];
				fC_of_TS456_Summed = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5] + RawDataRPD[0][channel][6];

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {
					RPDSignalSummed[0] += fC_of_TS456_Summed;
					//here im creating the components of the flow vector
					
					if (V1orV2 == "V1"){
						cosv1RPDsum[0] += cos(1*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
						sinv1RPDsum[0] += sin(1*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					}
					else{
						cosv2RPDsum[0] += cos(2*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
						sinv2RPDsum[0] += sin(2*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					}
				}
			}

			if (V1orV2 == "V1"){
				Recentered_Q_Observed_V1_X = (cosv1RPDsum[0]/RPDSignalSummed[0]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[0])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[0]; 
				Recentered_Q_Observed_V1_Y = (sinv1RPDsum[0]/RPDSignalSummed[0]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[1])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[1];
				
				OutPut_RPD_Event_Plane_Psi = atan2(Recentered_Q_Observed_V1_Y, Recentered_Q_Observed_V1_X); // FOR V1
			}
			else{
				Recentered_Q_Observed_V2_X = (cosv2RPDsum[0]/RPDSignalSummed[0]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[0])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[0];
				Recentered_Q_Observed_V2_Y = (sinv2RPDsum[0]/RPDSignalSummed[0]-INPUT_V1orV2_MEAN_X_Y_FOR_Recentering[1])/INPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[1];
				
				OutPut_RPD_Event_Plane_Psi = atan2(Recentered_Q_Observed_V2_Y, Recentered_Q_Observed_V2_X)/2; // FOR V2
			}
		}

				/// I NEED TO THINK ABOUT HOW TO WRITE THIS CODE FOR EASE OF CALIBRATIO NBY WHICH I MEAN EVENT PLANE FLATTENING...
				
				/// I NEED TOSEPERATE OUT THE RECENTERING FROM THIS HEADER SO RECENTERING AND RESOLUTION CAN BE RUN LATER AND THEREFORE NOT REQUIRE MANUAL INTERVENTION
				/// create seperate reaction plane resolution funtion
				/// I CAN HAVE THE OUTPT OF THIS GO INTO MAKING Q OBS PLOTS WHICH CAN THEN HAVE THE MEAN AND SIGMA AUTOMATICALLY CALLED BY ROOT THEN PASSED ONTO THE RECENTERING AND RESOLUTION FUNCTION
		
	}
	else{
		OutPut_RPD_Event_Plane_Psi = -10;
	}

}


#endif 