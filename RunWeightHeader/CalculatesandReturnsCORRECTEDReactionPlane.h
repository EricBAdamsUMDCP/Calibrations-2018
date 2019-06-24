/*REACTION PLANE CALCULATOR 

This code uses the reaction plane from reaction plane detector to generate a corrected/flattened event plane


Eric Adams


TO THE FUTURE PERSON WHO READS THIS,
IF YOU FIND THE CODE HARD OR THIS CONFUSNG...

>> GIT GUD

You can do it, attend LPC CMS DAS<< "\n"; in the winter.

4/12/19 */

// last edited (if I remebered to change this... 6/11/2019 11:48:11 AM)

#include <string>
#include <stdexcept>
#include <cmath>

#ifndef CalculatesandReturnsCORRECTEDReactionPlane
#define CalculatesandReturnsCORRECTEDReactionPlane

double CalculatesandReturns_I_CORRECTED_I_ReactionPlane(const std::string& PosorNeg, int INPUT_Flattening_Order, double INPUT_Event_Plane, double INPUT_Meaned_SinRXN_Plane, double INPUT_Meaned_CosRXN_Plane){

	//the software expects an array with millions of values it can pull the rxn plane from previously. I reccomend you initialize this double array (for 7 mill values a double array is 56 Mb not bad but not great) based on the number of events. NOTE this array will be millions long!!!
	//make sure you put this header function in a look over the number of good events
	//errors //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (PosorNeg != "Pos" && PosorNeg != "Neg") {
		throw std::runtime_error("ERROR: PosorNeg must be set to Pos or Neg, input variable 3, CalculatesandReturnsReactionPlane.h");
	}
	/// pos or neg are irrelevant to this calculation and software, they are implemented so the user is forcibly reminded to keep pos and neg values from previous seperate.
	/// the check above uses extra CPU cycles, so it may be removed later if it proves to be too expensive
	if (INPUT_Flattening_Order <= 0) {
		throw std::runtime_error("ERROR: The flattening order must be 1 (e.g. V1 is 1) or greater (it is not reccomended to exceed 6), input variable 2 , CalculatesandReturnsCORRECTEDReactionPlane.h");
	}

	//equation used is A5 @ https://journals.aps.org/prc/pdf/10.1103/PhysRevC.56.3254

	double Summed_Flattening_Equation_Component = 0;

	double Flattening_Order_x_INPUT_Event_Plane = (INPUT_Flattening_Order * INPUT_Event_Plane);

	for ( int order = 1; order <= INPUT_Flattening_Order; order++){
		Summed_Flattening_Equation_Component += ( (2/order)*(-1*INPUT_Meaned_SinRXN_Plane*cos(Flattening_Order_x_INPUT_Event_Plane) + INPUT_Meaned_CosRXN_Plane*sin(Flattening_Order_x_INPUT_Event_Plane)) );
	}

	double OutPut_CORRECTED_RPD_Event_Plane_Psi = INPUT_Event_Plane + Summed_Flattening_Equation_Component;
	return OutPut_CORRECTED_RPD_Event_Plane_Psi;
}

#endif
