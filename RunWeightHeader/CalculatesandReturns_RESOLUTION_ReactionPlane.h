#include <cmath>

#ifndef OutputsReactionPlaneResolution
#define OutputsReactionPlaneResolution

double Outputs_Resolution_ReactionPlane_to_Mean( double EventPlane_POS, double EventPlane_NEG, double (&Output_ReactionPlaneResolution_All_mustbeMeaned)){

	if (EventPlane_POS != -10 && EventPlane_NEG != -10){

		Output_ReactionPlaneResolution_All_mustbeMeaned = sqrt(cos(abs(EventPlane_POS - EventPlane_NEG))); //IDK if it matters wether neg or pos is first
		//slide 14 https://www.phenix.bnl.gov/phenix/WWW/intro/detectors/focus/focus_rxnp.pdf
		//ths calculates the individual differences the resolution is an average over all events, use a root histogram to store values and the take mean function
	}
	else{
		return Output_ReactionPlaneResolution_All_mustbeMeaned = -10;
	}
}


#endif