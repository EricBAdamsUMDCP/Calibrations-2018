/*REACTION PLANE CALCULATOR PSEUDO CODE 

consumes ReturnsWeightedQBArray and side*/

#ifndef CalculatesandReturnsReactionPlane
#define CalculatesandReturnsReactionPlane

double CalculatesandReturnsRXN_Plane(double ReturnsWeightedQBArray[16], int side){
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