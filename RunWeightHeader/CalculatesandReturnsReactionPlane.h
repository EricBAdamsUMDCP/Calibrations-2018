/*REACTION PLANE CALCULATOR 

This code uses the reaction plane detector to generate the event plane

it needs the fC of all 16 blocks in a RPD the weights by which to calibrate the data a user input of pos or neg and this code outputs and array of weighter fC with their respective x y distributions

//Thanks to Oliver and Mate for their code which I used as a reference to something I hope has no bugs in geenrating the event plane

Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS in the winter.

4/12/19 */

// last edited (if I remebered to change this... 5/7/2019 11:49:39 AM)


#include <string>
#include <stdexcept>

#ifndef CalculatesandReturnsReactionPlane
#define CalculatesandReturnsReactionPlane

double CalculatesandReturnsRXN_Plane(double ReturnsWeightedQBArray[16], double OutPut_Weightedjeffsweights[16], const std::string& PosorNeg, double (&OutPut_RPDfC_X_Y_coord)[16]){
	//errors
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 3 , RPD_Beam_Position_Finder.h");
	}	

	//decleration of constants and arrays
	const int NSIDE = 2;
	const int NRPD = 16;


	//look up tables for RPD positions created by EBA 5/15/19
	//these tables are organized FOR THE DATA TO BE FED IN BY CHANNEL NUMBER AND NO THER WAY
	double X_position_cm[2][16] = {{1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1},  //neg
							   	   {1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1}}; //pos

	double Y_position_cm[2][16] = {{-1, 1, 3, -3, -1, 1, 3, -3, 1, -1, -3, 3, 1, -1, -3, 3},  //neg
								   {-1, 1, 3, -3, -1, 3, 1, -3, 1, -1, -3, 3, 1, -1, -3, 3}}; //pos
 

	float RPDBlocksInphi[NSIDE][NRPD] = {{0}};

  	for(int Side=0; Side < NSIDE; Side++){
    	for(int RPD=0; RPD < NRPD; RPD++){
    	//generates blocks as polar coordinates
     	 RPDBlocksInphi[Side][RPD] = atan2(Y_position_cm[Side][RPD],X_position_cm[Side][RPD]);
    	}
    }

	if (ReturnsWeightedQBArray[0] != -10 && ReturnsWeightedQBArray[15] != -10){ // -10 is the value returned by functions if a bad event was measured and the functions are designed to ignore bad evets


		//convert quartz blocks into polar coordinates.. I think this should be something I calculate once and store as a permanent array I can make this with what olivers code does

		// do i need to calculate q mean and q sigma?? yes to caulculate the q coreelation vectors

		//calcualte Q psi 

		// NEED to sit down the week of the 29th abd break down liver/mates event plane code and figure out what is good and what I need after discussing with alice
		//to properly calculate the event plane


		/// I NEED TO THINK ABOUT HOW TO WRITE THIS CODE FOR EASE OF CALIBRATIO NBY WHICH I MEAN EVENT PLANE FLATTENING...
		


	}
	else{
		return -10;
	}

}

#endif 