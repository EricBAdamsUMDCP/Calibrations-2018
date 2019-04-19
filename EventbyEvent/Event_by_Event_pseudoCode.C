//this pseudo code dynamically returns an array of weights to weight the real data EVENT BY EVENT in real time


//get EM beam position

//weight jeffs weights based on EM beam position e.g. if  EM reads 1.4 and jeff has 1 and 1.5
//take 20% of 1 and 80% of 1.5 then sum them.

//This software is dependent, externally, on ...\Calibrations\RunWeightHeader\EM_Beam_Position_Cut_and_Value_Header.h
// for a EM beam position for it to calculate weights

#ifndef JeffWeighter3000
#define JeffWeighter3000

JeffWeighter3000_OutputsArray( double EM_Beam_Position_Cut_and_Value_OUTPUT){ // make sure you enter the right side for what u want
	
	double x = EM_Beam_Position_Cut_and_Value_OutPut;
	
	int Value = std::round(x);
	
	const int NRPD = 16;
	
	double Weightedjeffsweights[NRPD];
	/// Quartz block ordering is 1,2,3,4,5,..., 16
	double 	 jeffsweights_N40_0[NRPD] = {filler up};
	double 	 jeffsweights_N30_0[NRPD] = {filler up};
	double 	 jeffsweights_N20_0[NRPD] = {filler up};
	double 	 jeffsweights_N10_0[NRPD] = {filler up};
	double 	  jeffsweights_00_0[NRPD] = {filler up};
	double 	 jeffsweights_P10_0[NRPD] = {filler up};
	double 	 jeffsweights_P20_0[NRPD] = {filler up};
	double 	 jeffsweights_P30_0[NRPD] = {filler up};
	double 	 jeffsweights_P40_0[NRPD] = {filler up};
	
	for ( int i = 0; i < 16; i++){
		Weightedjeffsweights[i] = 0; // sets all of weighted jeffs weights to zero
	}
	
	// how the heck do i make a fucntion return an array
	switch (Value){
		case -3:
			double y = -1*(x +3);
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_N40_0[i]*y + jeffsweights_N30_0[i]*z;
				}
		break;
		case -2:
			double y = -1*(x +2);
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_N30_0[i]*y + jeffsweights_N20_0[i]*z;
				}
		break;
		case -1:
			double y = -1*(x +1);
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_N20_0[i]*y + jeffsweights_N10_0[i]*z;
				}
		break;
		case 0:
			if (x < 0){
				double y = -1*(x);
				double z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						Weightedjeffsweights[i] = jeffsweights_N10_0[i]*y + jeffsweights_N00_0[i]*z;
					}
			break;
			}
			if (x > 0){
				double y = x;
				double z =  (1 - y); 
					for ( int i = 0; i < 16; i++){
						Weightedjeffsweights[i] = jeffsweights_P00_0[i]*z + jeffsweights_P10_0[i]*y;
					}
			break;
			}
		
		case 1:
			double y = x - 1;
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_P10_0[i]*z + jeffsweights_P20_0[i]*y;
				}// FOR THE POS SIDE SWITCH Y AND Z
		jeffs weights 1 and 2
		break;
		case 2:
			double y = x - 2;
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_P20_0[i]*z + jeffsweights_P30_0[i]*y;
				}
		break;
		case 3:
			double y = x - 3;
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[i] = jeffsweights_P30_0[i]*z + jeffsweights_P40_0[i]*y;
				}
		break;
		
	}
	
	// RETURN ARRAY HERE WITH FANCY C++
}	

#endif

/* Weightedjeffsweights = jeffsweights*q + jeffsweights*w


use the new jeffs weights to solve for the data weights event by event

apply the event by event weights to the data (make sure the ordering is correct)

then store these weighted values

solve for y axis

 */