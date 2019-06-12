/*REACTION PLANE CALCULATOR 

This code uses the reaction plane detector to generate the event plane

it needs the fC of all 16 blocks in a RPD the weights by which to calibrate the data a user input of pos or neg and this code outputs and array of weighter fC with their respective x y distributions

//Thanks to Oliver and Mate for their code which I used as a reference to something I hope has no bugs in geenrating the event plane

Eric Adams

this software IS SIMILAR TO CalculatesandReturnsReactionPlane.h but is >>>>NOT<<<< identical. This softrware is used to calcualte the recentering values to be used by CalculatesandReturnsReactionPlane.h to recenter the beam EVENT BY EVENT.
This software must run over the entire data set then pass its output to CalculatesandReturnsReactionPlane.h for a succesful reaction plane to be caluclated.

TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS<< "\n"; in the winter.

4/12/19 */

// last edited (if I remebered to change this... 6/11/2019 11:48:17 AM)


#include <string>
#include <stdexcept>
#include <cmath> //for atan2 as it is a math fu c could also use tmath but i want to avoid any root outside of plotting

#ifndef CalculatesandReturnsQObsforRecentering
#define CalculatesandReturnsQObsforRecentering

void CalculatesandReturns_Q_ObsforRecentering(double RawDataRPD[2][16][10], double Input_Weightedjeffsweights[16], const std::string& PosorNeg, double &Output_Q_Observed_V1_X, double &Output_Q_Observed_V1_Y, double &Output_Q_Observed_V2_X, double &Output_Q_Observed_V2_Y){
	//errors
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 4 , RPD_Beam_Position_Finder.h");
	}

	//if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {}	
	if (Input_Weightedjeffsweights[15] != -10 && Input_Weightedjeffsweights[0] != -10){ // -10 is the value returned by functions if a bad event was measured and the functions are designed to ignore bad evets
	//decleration of constants and arrays
		const int NSIDE = 2;
		const int NRPD = 16;
		const int NXY = 2;
		const char* xytit[NXY] = {"x","y"};
		float  RPDSignalSummed[NSIDE] = {0};
		float  cosv1RPDsum[NSIDE] = {0};
		float  sinv1RPDsum[NSIDE] = {0};
		float  cosv2RPDsum[NSIDE] = {0};
		float  sinv2RPDsum[NSIDE] = {0};
		//look up tables for RPD positions created by EBA 5/15/19 
		double X_position_cm[2][16] = {{1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1},  //neg
								   	   {1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1}}; //pos
	
		double Y_position_cm[2][16] = {{-1, 1, 3, -3, -1, 1, 3, -3, 1, -1, -3, 3, 1, -1, -3, 3},  //neg
									   {-1, 1, 3, -3, -1, 3, 1, -3, 1, -1, -3, 3, 1, -1, -3, 3}}; //pos 
	
		// for recentering calibration, from Qobs distributions.
 		
		//HINT: Q is the flow >vector< look it up, the RPD measures a flow vector.

 		float Qobs1_mean[NXY] = {0};
 		float Qobs2_mean[NXY] = {0};
 		float Qobs1_sigma[NXY] = {1};
 		float Qobs2_sigma[NXY] = {1};
 		

		//BEGIN PLOTS: the plots are used so root can store then later take a mean and sigma
 		/*TH1F* Qobs1[NXY];
		TH1F* Qobs2[NXY];

		for(int ixy=0;ixy<2;ixy++)
    		{
    		  Qobs1[ixy] = new TH1F(Form("Qobs1dist_%s_%s", PosorNeg, xytit[ixy]),Form("Q^{obs}_{1,%s}%s distribution;Q^{obs}_{1,%s};[a.u.]",xytit[ixy],PosorNeg,xytit[ixy]),100,-6,6);
    		  Qobs2[ixy] = new TH1F(Form("Qobs2dist_%s_%s", PosorNeg, xytit[ixy]),Form("Q^{obs}_{2,%s}%s distribution;Q^{obs}_{2,%s};[a.u.]",xytit[ixy],PosorNeg,xytit[ixy]),100,-6,6);
    		}
    	//END PLOTS*/
	
		///THIS SEEMS LIKE A POTENTIAL MEMORY LEAK, THESE PLOTS THAT APPEAR THEN ARE NOT DEALLOCATED BC ROOT IS DUMB, BASED ON HOW THE FUNCTION WORKS

		// Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
		double fC_of_TS45_Summed = 0;
		double fC_of_TS456_Summed = 0;
	
	
			//DOUBLE CHECK THESE NUMBERS AND MAKE SURE THEY MATCH THEIR RESPECTIVE QB POSITION THEY WERE CALCULATED SORT OF SLOPPLY ean 6/3/19 4 PM						   
		float RPDBlocksInPhi[NSIDE][NRPD] = {{-0.785398, 0.785398, 1.24905, -1.24905, -0.321751, 0.321751, 0.785398, -0.785398, 2.81984, -2.81984, -2.35619, 2.35619, 2.35619, -2.35619, -1.89255, 1.89255}, //NEG
		 									 {-0.785398, 0.785398, 1.24905, -1.24905, -0.321751, 0.785398, 0.321751, -0.785398, 2.81984, -2.81984, -2.35619, 2.35619, 2.35619, -2.35619, -1.89255, 1.89255}};
	
  	
  		if (PosorNeg == "Pos"){

		    /*for(int RPD=0; RPD < NRPD; RPD++){
		    	//generates blocks as polar coordinates
		    	RPDBlocksInPhi[1][RPD] = atan2(Y_position_cm[1][RPD],X_position_cm[1][RPD]);
		    }*/
  			for (int channel = 0; channel < NRPD; channel++){
		    	fC_of_TS45_Summed  = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5];
				fC_of_TS456_Summed = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5] + RawDataRPD[1][channel][6];

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[1][channel][7] <= RawDataRPD[1][channel][5]) && (RawDataRPD[1][channel][1] / RawDataRPD[1][channel][0] < 1000) && (RawDataRPD[1][channel][0] != 0)) {
					RPDSignalSummed[1] += fC_of_TS456_Summed;
					
					cosv1RPDsum[1] += cos(1*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 					sinv1RPDsum[1] += sin(1*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 					cosv2RPDsum[1] += cos(2*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
 					sinv2RPDsum[1] += sin(2*RPDBlocksInPhi[1][channel])*fC_of_TS456_Summed;
					

					//ask alice how recentering works


				}
			}

			Output_Q_Observed_V1_X = (cosv1RPDsum[1]/RPDSignalSummed[1]-Qobs1_mean[0])/Qobs1_sigma[0]; //note these are not actually recontered bc we dont have the mean or sigma yet
			Output_Q_Observed_V1_Y = (sinv1RPDsum[1]/RPDSignalSummed[1]-Qobs1_mean[1])/Qobs1_sigma[1];
			Output_Q_Observed_V2_X = (cosv2RPDsum[1]/RPDSignalSummed[1]-Qobs2_mean[0])/Qobs2_sigma[0];
			Output_Q_Observed_V2_Y = (sinv2RPDsum[1]/RPDSignalSummed[1]-Qobs2_mean[1])/Qobs2_sigma[1];

			/*Qobs1[0]->Fill(Q1xRecentered);
			Qobs1[1]->Fill(Q1yRecentered);
			Qobs2[0]->Fill(Q2xRecentered);
			Qobs2[1]->Fill(Q2yRecentered);*/

			//THIS IS GETTING WEIRD IF THIS FUNCTION IS IN A LOOPIT WILL JYST CONTINUALLY MNAKE HISTOGRAMS I THINK THE MEAN HAS TO BE TAKEN OUTSIDE OF THIS FUNCTION
		}
		else if (PosorNeg == "Neg"){
			/*for(int RPD=0; RPD < NRPD; RPD++){
		    	//generates blocks as polar coordinates
		    	RPDBlocksInPhi[1][RPD] = atan2(Y_position_cm[1][RPD],X_position_cm[1][RPD]);
		    }*/

		    for (int channel = 0; channel < NRPD; channel++){
				//remeber TS start at 0 DONT SUBTRACT
				fC_of_TS45_Summed  = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5];
				fC_of_TS456_Summed = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5] + RawDataRPD[0][channel][6];

				if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {
					RPDSignalSummed[0] += fC_of_TS456_Summed;
					//here im creating the components of the flow vector
					cosv1RPDsum[0] += cos(1*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					sinv1RPDsum[0] += sin(1*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					cosv2RPDsum[0] += cos(2*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					sinv2RPDsum[0] += sin(2*RPDBlocksInPhi[0][channel])*fC_of_TS456_Summed;
					
				}
			}

			Output_Q_Observed_V1_X = (cosv1RPDsum[0]/RPDSignalSummed[0]-Qobs1_mean[0])/Qobs1_sigma[0];
			Output_Q_Observed_V1_Y = (sinv1RPDsum[0]/RPDSignalSummed[0]-Qobs1_mean[1])/Qobs1_sigma[1];
			Output_Q_Observed_V2_X = (cosv2RPDsum[0]/RPDSignalSummed[0]-Qobs2_mean[0])/Qobs2_sigma[0];
			Output_Q_Observed_V2_Y = (sinv2RPDsum[0]/RPDSignalSummed[0]-Qobs2_mean[1])/Qobs2_sigma[1];
			
		}
		
	}
	else{
		Output_Q_Observed_V1_X = -10; Output_Q_Observed_V1_Y = -10; Output_Q_Observed_V2_X = -10; Output_Q_Observed_V2_Y = -10; //-10 is the bad data or processing warning number informing functions they should skip the event and move onto the next one
	//make sure to code the histogram to skip filling if any of them return -10
	}

}


#endif 