   /* EM Beam Position Code
This header file is used to insert a function which will measure a weighted average
of the beam position using the 5 channels of the EM section per each EM.

this code consume the EM data matrix feed it that matrix or it will fail remeber that 3 is 4 and 4 is 5 in arrays as we start from 0!!!

These are defined in the code(s) designed to use this header file.

Adjust this as necessary

Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS in the winter.

4/9/19 */
//last edited(if I didn't forget to change this...): 5/16/2019 10:47:07 AM

//#include <iostream>
//#include <cstdio>
#include <string>
#include <stdexcept>

#ifndef EM_Beam_Position_returns_Value
#define EM_Beam_Position_returns_Value //when making a header header name must be different than function name


/*ERIC notes I dont know if this osftware will store the value after each N increase as intended.... because it will relaunch the function and the values are inside of the scope....*/


 
/////////////////////////////////////////////////////Side/Ch/TS////
double EM_Beam_Position_Value(double RawDataEM[2][5][10], const std::string& PosorNeg) {
	//errors
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 2, EM_Beam_Position_returns_Value.h");
	}


	/// every time this function is called the variables are not set, right....?
	const int NCH = 5;
	float EM[NCH] = { -3.6,-1.8,0,1.8,3.6};
	static double EMChannelP[NCH] = {0};
	static double EMChannelN[NCH] = {0};
	double sumEMPos, sumEMNeg, sumWeightEMPos, sumWeightEMNeg;
	double valuereturned = -10; // -10 is the bad vthing happened value all the other code sees a value of -10 and knows to skip the event


	//ternary operators (look them up)

	// says if the value of TS 4 and 5 are independently greater than 100 fC then sum Ts 4 and TS 5 and set it equal to that array memebr if theyy are not set that array member to 0!
	EMChannelP[0] = (RawDataEM[1][0][4] > 10 && RawDataEM[1][0][5] > 10) ? (RawDataEM[1][0][4] + RawDataEM[1][0][5]) : 0.0;
	EMChannelP[1] = (RawDataEM[1][1][4] > 10 && RawDataEM[1][1][5] > 10) ? (RawDataEM[1][1][4] + RawDataEM[1][1][5]) : 0.0;
	EMChannelP[2] = (RawDataEM[1][2][4] > 10 && RawDataEM[1][2][5] > 10) ? (RawDataEM[1][2][4] + RawDataEM[1][2][5]) : 0.0;
	EMChannelP[3] = (RawDataEM[1][3][4] > 10 && RawDataEM[1][3][5] > 10) ? (RawDataEM[1][3][4] + RawDataEM[1][3][5]) : 0.0;
	EMChannelP[4] = (RawDataEM[1][4][4] > 10 && RawDataEM[1][4][5] > 10) ? (RawDataEM[1][4][4] + RawDataEM[1][4][5]) : 0.0; 
 
	EMChannelN[0] = (RawDataEM[0][0][4] > 10 && RawDataEM[0][0][5] > 10) ? (RawDataEM[0][0][4] + RawDataEM[0][0][5]) : 0.0;
	EMChannelN[1] = (RawDataEM[0][1][4] > 10 && RawDataEM[0][1][5] > 10) ? (RawDataEM[0][1][4] + RawDataEM[0][1][5]) : 0.0;
	EMChannelN[2] = (RawDataEM[0][2][4] > 10 && RawDataEM[0][2][5] > 10) ? (RawDataEM[0][2][4] + RawDataEM[0][2][5]) : 0.0;
	EMChannelN[3] = (RawDataEM[0][3][4] > 10 && RawDataEM[0][3][5] > 10) ? (RawDataEM[0][3][4] + RawDataEM[0][3][5]) : 0.0;
	EMChannelN[4] = (RawDataEM[0][4][4] > 10 && RawDataEM[0][4][5] > 10) ? (RawDataEM[0][4][4] + RawDataEM[0][4][5]) : 0.0;



	//this if statement is looking for funky events with bad signals the ternary staements set bad stuff to 0 and any zerro is seen as bad and a value of - 10 is returned
	if ( PosorNeg == "Pos"){
		if (EMChannelP[0] != 0.0 && EMChannelP[1] != 0.0 && EMChannelP[2] != 0.0 && EMChannelP[3] != 0.0 && EMChannelP[4] != 0.0){
			double WeightedAvg_Pos = -10; //incase doesnt fill properly returns standard bad value
			
			sumEMPos = (EMChannelP[0] + EMChannelP[1] + EMChannelP[2] + EMChannelP[3] + EMChannelP[4]);
			sumWeightEMPos = ((EMChannelP[0] * EM[0]) + (EMChannelP[1] * EM[1]) + (EMChannelP[2] * EM[2]) + (EMChannelP[3] * EM[3]) + (EMChannelP[4] * EM[4]));
			WeightedAvg_Pos = (sumWeightEMPos / sumEMPos);

			valuereturned = WeightedAvg_Pos;
			
		}
	}
	else if ( PosorNeg == "Neg"){
		if (EMChannelN[0] != 0.0 && EMChannelN[1] != 0.0 && EMChannelN[2] != 0.0 && EMChannelN[3] != 0.0 && EMChannelN[4] != 0.0){
		
			double WeightedAvg_Neg = -10; //incase doesnt fill properly returns standard bad value
	
			sumEMNeg = (EMChannelN[0] + EMChannelN[1] + EMChannelN[2] + EMChannelN[3] + EMChannelN[4]);
			sumWeightEMNeg = ((EMChannelN[0] * EM[0]) + (EMChannelN[1] * EM[1]) + (EMChannelN[2] * EM[2]) + (EMChannelN[3] * EM[3]) + (EMChannelN[4] * EM[4]));
			WeightedAvg_Neg = (sumWeightEMNeg / sumEMNeg);
		
			valuereturned = WeightedAvg_Neg;
		}
	}

	return  valuereturned; 
}


#endif
