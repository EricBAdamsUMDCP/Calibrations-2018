//this code dynamically returns an array of weights from jeffs weigths, to weight the real data EVENT BY EVENT in real time


//This software is dependent, externally, on ...\Calibrations\RunWeightHeader\EM_Beam_Position_Cut_and_Value_Header.h
// for a EM beam position for it to calculate weights


//last edited (if I didn't forget to change this...): 4/22/2019 6:23:19 PM

#ifndef SamWeighter
#define SamWeighter


//I am a chemist not an englishist I can't spell

void SamWeighter_OutputsArray( double EM_Beam_Position_OUTPUT, int side, double (&OutPut_SamsWeights)[16]){ // make sure you enter the right side for what u want
	
/// PUT IN THING TO KILL OFF THE OLD MEMEORY ADRESSES

	// note if YOU PASS IN AN ARRAY >>>NOT EQUAL TO 16 GOD HELP YOU<<< WITH WHATEVER STRANGENESS HAPPENS, YOU'LL LIKELY GET A SEG FAULT... IF YOU'RE LUCKY.

	// The side can be set y the user or automated by the code it is nested inide

		//THIS IS A HACK... THE FUNCTION WILL FILL WHATEVER ARRAY YOU PASS IN WITH THE APPROPRIATE VALUES

	/* EXAMPLE CODE
		void THE_MACRO_FUNCTION_NAME(){
		other stuff for things...
	
		outside of the main loop: double OutPut_SamsWeightsPos[16]={0};

		EM_Beam_Position_Cut_and_Value_OUTPUT = EM_Beam_Position_Cut_and_Value( TS_Four, TS_Five, n, side, type, channel, EM_CUT_Xmin, EM_CUT_Xmax, -3, 3, 1, 0); // pos side
		
		// you must use the 
	
		double OutPut_SamsWeights[16];
		JeffWeighter3000_OutputsArray( EM_Beam_Position_Cut_and_Value_OUTPUT, side, OutPut_SamsWeights[16])
		
		//can now access filled array (ith eleemnt)

		OutPut_SamsWeights[i]
		}
	*/

	if ( EM_Beam_Position_OUTPUT != -10 && EM_Beam_Position_OUTPUT <= 4 && EM_Beam_Position_OUTPUT >= -4 ){
		const int NRPD = 16;
		const int NSIDE = 2;
	
		double x = EM_Beam_Position_OUTPUT;
		
		int Value = x; // this is used to truncate the value for decision making
		
		
		// double OutPut_SamsWeights[NRPD];
		/// Jeffs weights are organized to REAL RPD (2018 PbPb) Quartz block ordering is 1,2,3,4,5,..., 16, (x,y) Y is always zero assuming beam is generally there in mm
		/// >>HEY YOU, YEAH YOU DONT EDIT THESE NUMBERS IN THE ARRAYS THEY SHOULD NEVER CHANGE FOR THE 2018 PbPb RUN IF YOU DO YOU WILL PERMNENTLY DISTORT RESULTS >:(
	////////////////////////////////////////////////    1       2      3       4       5       6       7       8       9     10      11     12     13       14    15      16    ////////    1       2      3        4      5       6       7      8        9     10      11     12     13       14    15      16
		double 	 SamsWeights_N40_0[NSIDE][NRPD] = {{  4491,   4022,  2541,   2934,   1514,   1198,   970,   1236, 391656, 187702, 65034, 21804,  20809,  21185, 13565,  8300}/*Neg*/, {  4491,   4022,  2541,   1236,   1514,   1198,   970,   2934, 391656,  187702, 65034, 21804,  20809,  21185, 13565,  8300}/*Pos*/};                                                                                                                                           
		double 	 SamsWeights_N30_0[NSIDE][NRPD] = {{  4198,   4373,  2476,   3050,   1265,   1347,   810,    999, 410585, 180889, 74520, 14740,  29299,  26589, 13392,  7591}/*Neg*/, {  4198,   4373,  2476,    999,   1265,   1347,   810,   3050, 410585,  180889, 74520, 14740,  29299,  26589, 13392,  7591}/*Pos*/};                                                                                                                                              
		double 	 SamsWeights_N20_0[NSIDE][NRPD] = {{ 13614,  14416,  6422,   9358,   2925,   3069,  2795,   2379, 353382, 164174, 58673, 20048, 222865, 142157, 51889, 19460}/*Neg*/, { 13614,  14416,  6422,   2379,   2925,   3069,  2795,   9358, 353382,  164174, 58673, 20048, 222865, 142157, 51889, 19460}/*Pos*/};       
		double 	 SamsWeights_N10_0[NSIDE][NRPD] = {{ 41182,  45157, 12745,  20024,   7043,   6479,  3806,   4779,  54520,  48583, 23613, 13052,  66799,  30855, 12862, 24023}/*Neg*/, { 41182,  45157, 12745,   4779,   7043,   6479,  3806,  20024,  54520,   48583, 23613, 13052,  66799,  30855, 12862, 24023}/*Pos*/};          
		double 	 SamsWeights_00_0[NSIDE][NRPD]  = {{116326, 163756, 18167,  44959,  12981,  13337,  6553,   9039,  17087,  18142, 10791,  7160, 383073, 173109, 62431, 19796}/*Neg*/, {116326, 163756, 18167,   9039,  12981,  13337,  6553,  44959,  17087,   18142, 10791,  7160, 383073, 173109, 62431, 19796}/*Pos*/};
		double 	 SamsWeights_P10_0[NSIDE][NRPD] = {{435144, 875722, 29511, 211035,  42513,  49521, 13891,  22630,   8902, 	 9541,  6823,  5381,  74226,  64984, 30527, 15799}/*Neg*/, {435144, 875722, 29511,  22630,  42513,  49521, 13891, 211035,   8902, 	 9541,  6823,  5381,  74226,  64984, 30527, 15799}/*Pos*/};    
		double 	 SamsWeights_P20_0[NSIDE][NRPD] = {{301851, 829880, 28266, 112083, 151396, 214680, 23237,  57628,   5141, 	 5473,  4308,  2940,  24892,  26862, 14709,  9673}/*Neg*/, {301851, 829880, 28266,  57628, 151396, 214680, 23237, 112083,   5141, 	 5473,  4308,  2940,  24892,  26862, 14709,  9673}/*Pos*/};  
		double 	 SamsWeights_P30_0[NSIDE][NRPD] = {{ 69665,  74945, 14314,  30043, 332891, 649645, 26981, 138881,   2584, 	 2531,  2070,  2151,   9351,   9573,  5833,  4622}/*Neg*/, { 69665,  74945, 14314, 138881, 332891, 649645, 26981,  30043,   2584, 	 2531,  2070,  2151,   9351,   9573,  5833,  4622}/*Pos*/};            
		double 	 SamsWeights_P40_0[NSIDE][NRPD] = {{ 24628,  25680,  9801,  14050, 256842, 560669, 22983, 103692,   1404, 	 1346,  1397,  1227,   4591,   5171,  3876,  2869}/*Neg*/, { 24628,  25680,  9801, 103692, 256842, 560669, 22983,  14050,   1404, 	 1346,  1397,  1227,   4591,   5171,  3876,  2869}/*Pos*/};              
		
		for ( int i = 0; i < 16; i++){
			OutPut_SamsWeights[i] = 0; // sets all of weighted jeffs weights to zero and prevents bad values from being passed and just kills the data in defense
		}
	
		double y;
		double z;
		
		// how the heck do i make a fucntion return an array
		switch (Value){
			case -3:
				y = -1*(x +3);
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_N40_0[side][i]*y + SamsWeights_N30_0[side][i]*z;
					}
			break;
			case -2:
				y = -1*(x +2);
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_N30_0[side][i]*y + SamsWeights_N20_0[side][i]*z;
					}
			break;
			case -1:
				y = -1*(x +1);
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_N20_0[side][i]*y + SamsWeights_N10_0[side][i]*z;
					}
			break;
			case 0:
				if (x < 0){
					y = -1*(x);
					z =  (1 - y); 
						for ( int i = 0; i < 16; i++){
							OutPut_SamsWeights[i] = SamsWeights_N10_0[side][i]*y + SamsWeights_00_0[side][i]*z;
						}
				break;
					}
				if (x == 0){
						for ( int i = 0; i < 16; i++){
							OutPut_SamsWeights[i] = SamsWeights_00_0[side][i];
						}
				break;
				}
				if (x > 0){
					y = x;
					z =  (1 - y); 
						for ( int i = 0; i < 16; i++){
							OutPut_SamsWeights[i] = SamsWeights_00_0[side][i]*z + SamsWeights_P10_0[side][i]*y;
						}
				break;
				}
			
			case 1:
				y = x - 1;
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_P10_0[side][i]*z + SamsWeights_P20_0[side][i]*y;
					}// FOR THE POS SIDE SWITCH Y AND Z
			break;
			case 2:
				y = x - 2;
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_P20_0[side][i]*z + SamsWeights_P30_0[side][i]*y;
					}
			break;
			case 3:
				y = x - 3;
				z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = SamsWeights_P30_0[side][i]*z + SamsWeights_P40_0[side][i]*y;
					}
			break;
	
			default:
				for ( int i = 0; i < 16; i++){
						OutPut_SamsWeights[i] = 0; //this default case wipes any event in which the Em beam position failed to return a value and sets it as 0
						// the idea is this will zero the RPD fC values and nothing will be recorded
					}
		}
	}
	else{
		for ( int i = 0; i < 16; i++){ // a value of negative 10 means the software rejected the event or something was wrong, ergo all the software is designed to detect a value of -10 and if so to skip its process
						OutPut_SamsWeights[i] = -10;
		}
	}
}


#endif

/* OutPut_SamsWeights = SamsWeights*q + SamsWeights*w


use the new jeffs weights to solve for the data weights event by event

apply the event by event weights to the data (make sure the ordering is correct)

then store these weighted values

solve for y axis

 */