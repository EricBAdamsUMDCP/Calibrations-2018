
#ifndef RunWeights
#define RunWeights


float RunWeightsReturnValue( int runnumber, int side, int channel){
	const int NSIDE = 2;
	const int NRPD = 16;
	
	//place run number weights here inbetween me /// QB order: 1 2 3 4 5 6 7 ....
	float DATAWeightsFromRun_326776[NSIDE][NRPD] = {///testing new weights might actually be correct due too quartz block ordering issue
													/// making weights identical for pos and neg to see what happens
													{3.39726  ,7.07844	,0.247214 ,1.92548	,0.44108 ,0.426838 ,0.137877 ,0.230744 ,0.0580657,0.0727995,0.0677315,0.0409478,0.505317 ,0.499022 ,0.280635 ,0.122337},
													{4.11798  ,6.0687 	,0.204047 ,1.76127 ,0.445609 ,0.10001 ,0.332942, 0.18884 ,0.0828367,0.102349 ,0.0564283,0.0432092,0.572129,0.595776,0.235725 ,0.164413}
												   };
	
	// and me
	
	if (runnumber == 326776){
		return DATAWeightsFromRun_326776[side][channel];
	}
}

#endif
	