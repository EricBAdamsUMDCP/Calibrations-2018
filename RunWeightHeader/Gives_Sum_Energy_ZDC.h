
//used to get sum of energies usually for n peaks but in this case is used for making energy cuts


#ifndef Sum_Energy_ZDC
#define Sum_Energy_ZDC



void Gives_Sum_Energy_ZDC( double RawDataEM[2][5][10], double RawDataHAD[2][4][10], double &Output_N_SUM, double &Output_P_SUM){

	double EMmultiplicativevalue = 0.19;
	const int NSIDE = 2;
	double P_ratiovalue = 7.0; //used to be 6
	double N_ratiovalue = 4.0; //used to be 3
	double EM_TS_45[NSIDE][5] = {0}; //actually just 4
	double HAD_TS_45[NSIDE][4] = {0}; // actually just 4
	//the rpd is not used as it appears to have a negligable effect on energy, this makes sense
	double ratiovalue = 0;
	
	for (int s = 0; s < 2; s++){
	
	  if (s == 0){
	    ratiovalue = N_ratiovalue;
	  }
	  else{
	    ratiovalue = P_ratiovalue;
	  }
	
	  for (int c = 0; c < 5; c++){
	    if (RawDataEM[s][c][4]/RawDataEM[s][c][5] > ratiovalue ){
	     EM_TS_45[s][c] = RawDataEM[s][c][4]/* + TS_fC[5]*/;
	    }
	  }
	
	  for ( int c = 0; c < 4; c++){
	    if (RawDataHAD[s][c][4] /RawDataHAD[s][c][5]  > ratiovalue){
	    HAD_TS_45[s][c] = RawDataHAD[s][c][4] /* + TS_fC[5]*/;
	    }
	  }
	}
	  
	    //channel 3 is decided to be comparator
	
	////////////////Begin EM/////////////////////////////////////////////////////////////////////////////////////////
	  double P_SumEMfC = EM_TS_45[1][0] + EM_TS_45[1][1] + EM_TS_45[1][2] + EM_TS_45[1][3] + EM_TS_45[1][4];
	  double N_SumEMfC = EM_TS_45[0][0] + EM_TS_45[0][1] + EM_TS_45[0][2] + EM_TS_45[0][3] + EM_TS_45[0][4];
	 
	  ////////////End EM////////////////////////////////////////////////////////////////////////////////////////////
	
	  ////////////Begin HAD/////////////////////////////////////////////////////////////////////////////////////////
	
	  double P_SumHADfC = HAD_TS_45[1][0] + HAD_TS_45[1][1] + HAD_TS_45[1][2] + HAD_TS_45[1][3];
	  double N_SumHADfC = HAD_TS_45[0][0] + HAD_TS_45[0][1] + HAD_TS_45[0][2] + HAD_TS_45[0][3];
	
	  ////////////End HAD//////////////////////////////////////////////////////////////////////////////////////////
	
	  ////////////Begin HAD and EM (only if both are used)/////////////////////////////////////////////////////////
	  
	  Output_N_SUM = N_SumHADfC + EMmultiplicativevalue*N_SumEMfC;
	  Output_P_SUM = P_SumHADfC + EMmultiplicativevalue*P_SumEMfC;
	
	
	 // int Neg_EM_fC_CUT = 350000;
	 // int Pos_EM_fC_CUT = 250000;
}

#endif