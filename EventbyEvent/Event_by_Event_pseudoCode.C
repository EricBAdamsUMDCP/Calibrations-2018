get EM beam position

weight jeffs weights based on EM beam position e.g. if  EM reads 1.4 and jeff has 1 and 1.5
take 20% of 1 and 80% of 1.5 then sum them.


double x = -2.4

int Value = std::round (x)
-2

double Weightedjeffsweights[16];
double jeffsweights_N40_0;
double jeffsweights_N30_0;
double jeffsweights_N20_0;
double jeffsweights_N10_0;
double jeffsweights_00_0;
double jeffsweights_P10_0;
double jeffsweights_P20_0;
double jeffsweights_P30_0;
double jeffsweights_P40_0;

// how the heck do i make a fucntion return an array
switch (Value){
	case -3:
		double y = -1*(x +3);
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_N40_0[0]*z + jeffsweights_N30_0[0]*y;
			}
	break;
	case -2:
		double y = -1*(x +2);
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_N30_0[0]*z + jeffsweights_N20_0[0]*y;
			}
	break;
	case -1:
		double y = -1*(x +1);
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_N20_0[0]*z + jeffsweights_N10_0[0]*y;
			}
			jeffs weights -2 and -1
	break;
	case 0: (how does this work for the neg to pos transition)
		if (x < 0){
			double y = -1*(x);
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[0] = jeffsweights_N10_0[0]*z + jeffsweights_N00_0[0]*y;
				}
				jeffs weights -1 and 0
		break;
		}
		if (x > 0){
			double y = x;
			double z =  (1 - y); 
				for ( int i = 0; i < 16; i++){
					Weightedjeffsweights[0] = jeffsweights_P00_0[0]*z + jeffsweights_P10_0[0]*y;
				}
		jeffs weights 1 and 0
		break;
		}
	
	case 1:
		double y = x - 1;
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_P10_0[0]*z + jeffsweights_P20_0[0]*y;
			}// FOR THE POS SIDE SWITCH Y AND Z
	jeffs weights 1 and 2
	break;
	case 2:
		double y = x - 2;
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_P20_0[0]*z + jeffsweights_P30_0[0]*y;
			}
	jeffs weights 3 and 2
	break;
	case 3:
		double y = x - 3;
		double z =  (1 - y); 
			for ( int i = 0; i < 16; i++){
				Weightedjeffsweights[0] = jeffsweights_P30_0[0]*z + jeffsweights_P40_0[0]*y;
			}
	jeffs weights 3 and 2
	break;
	
}
	

Weightedjeffsweights = jeffsweights*q + jeffsweights*w


use the new jeffs weights to solve for the data weights event by event

apply the event by event weights to the data (make sure the ordering is correct)

then store these weighted values

solve for y axis

