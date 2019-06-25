

#ifndef Fiber_Ridge_Subtractor
#define Fiber_Ridge_Subtractor

void Fiber_Ridge_Subtractor_Outputs_Array( double RawDataRPD[2][16][10], double Percentage_Subtracted, double &Ridge_Subtracted_RPD_Data[2][16]){


	double TS45Array[2][16] = {0}; //ignore warnings from this line
	double TS456Array[2][16] = {0}; //ignore warnings from this line
	
	for (int s = 0; s < 2; s++){ //s=side
		for (int c = 0; c < 16; c++){ //c = channel
			TS45Array[s][c] = RawDataRPD[s][c][4] + RawDataRPD[s][c][5];
			TS456Array[s][c] = TS45Array[s][c] + RawDataRPD[s][c][6];
	
			if ((TS456Array[s][c] < 40) || (TS45Array[s][c] / TS456Array[s][c] < .8) || //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
			 (RawDataRPD[s][c][7] >= RawDataRPD[s][c][5]) || (RawDataRPD[s][c][1] / RawDataRPD[s][c][0] > 1000) //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
			  || (RawDataRPD[s][c][0] = 0)){ //WARNING THIS IS CUTTING FOR BAD EVENTS!!!!!!!!!!!!!!!!!!!!!!!
				for (int i = 0; i < 2; i++){
					for (int j = 0; j < 16; j++){
						Ridge_Subtracted_RPD_Data[i][j] = -10;
					}
				}
				return;
			}
		}
	}
				//Row, side, col RPD
	int LookUpTable[4][2][4] = {{{6, 2, 15, 11}, /*neg*/ {11, 15, 2, 5}},  /*Pos*/
							    {{5, 1, 12, 8}, /*neg*/  { 8, 12, 1, 6}},  /*Pos*/
							    {{4, 0, 13, 9}, /*neg*/  { 9, 13, 0, 4}},  /*Pos*/
							    {{7, 3, 14, 10}, /*neg*/ {10, 14, 3, 7}}}; /*Pos*/


	for (int r = 0; r < 4; r++){
		for (int s = 0; s < 2; s++){
			for (int c = 0; c < 4; c++){
				//make it so that 10% gets subtracted from each row except the first and take 10% from the previous row
				//were removing the ridge
				//this loop is for using the loop of table so we can do 4 blocks at once 
			}
		}
	}

}

#endif