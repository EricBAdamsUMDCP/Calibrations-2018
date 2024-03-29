#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TLeaf.h"
#include "TROOT.h"
#include <sstream>
#include <iostream>
#include <cstdio>
#include "TStyle.h"
#include "TLegend.h"
//#include "THStack.h" // ERIC ADDED
//#include "TPaveLabel.h" //Eric ADDDED
#include "TLine.h" //ERIC Added
#include <cstring> //colin added
#include <string> // Eric Added
#include <unordered_map> //colin added
#include <utility> //colin added
#include <cmath>

//function headers
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/EM_Beam_Position_returns_Value_function.h" // custom header writte by Eric A
//#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/RunWeighted_RPD_Beam_Position_Finder.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/JeffWeighter3000.h" //custom header written by Eric A to measure RPD beam postion in X and Y
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/CalculatesandReturns_Q_Obs_FOR_RECENTERING.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/CalculatesandReturnsReactionPlane.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/CalculatesandReturns_RESOLUTION_ReactionPlane.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/CalculatesandReturnsCORRECTEDReactionPlane.h"
using namespace std;

#ifndef M_PI
#define M_PI       3.14159265358979323846264338328
#endif

//struct for storing associated negative and positive RXN plane values
struct RXNP_ValuePair {
	double RXNP_Neg;
	double RXNP_Pos;
};

const char* figdir = "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/ProtoypeCodeforEMtoRXNplane/ZDC_figures/REACTION PLANE 326776";

// I am a chemist not an englishist I cant spell



//put error in above bc need to chnage rpd beam position finder for neg to invert like we observe now and MUST CHANGE JEFF WEIGHTER OR MAYBE CHNAGE INPUT DATA

void initRootStyle();
///home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/RPD_Beam_Position_Finder/*AOD_zdc_digi_tree_326776_many_3*/AOD_zdc_digi_tree_327126_many

int runnumber = 326776;

void EMtoRXNPlanetoV1_PlayGround(){
	initRootStyle();
	

	TFile* f = new TFile("/home/ebadams/Merged_Root_Files_PbPb2018/MB_2/326776/PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root"); string Dataset = "PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root";// opening root fie (only have 1 uncommented)
	
	//TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); string Dataset = "AOD_zdc_digi_tree_326776_many_3"; // opening the root file

	//TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/TracksMaybeAOD_zdc_digi_tree_326776_many_5.root"); string Dataset = "TracksMaybeAOD_zdc_digi_tree_326776_many_5.root"; 	
	
	cout << "Running SOFTWARE: EMtoRXNPlanePrototype_PlayGround.C 6/21/2019 6:42:22 PM" << endl;
	cout << "Dataset = " << Dataset << ".root"<< endl;

	
	
	TTree* ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree	

	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const int MinimumBias = 2;
	const int MinXTH2D = -4;
	const int MaxXTH2D = 4;
	const int MinYTH2D = -4;
	const int MaxYTH2D = 4;
	const int NumberOfBins = 64; //number of bins in TH1D histograms produced by this code
	const int NChannels = 50;
	const int NTS = 10;// number of timeslices
	const int NRPD = 16;
	const int NEM = 5;
	const int NHAD = 4;
	const int NRPDColnRow = 4;
	const int NSIDE = 2; const char* stit[NSIDE] = { "#minus","#plus" };  const char* stit2[NSIDE] = { "neg","pos" };
	const int NXY = 2;
		  int NumberofZDCTreeEntries = 0;

	double RPDXmin = -3;
	double RPDXmax = 3;
	double RPDYMin = -3;
	double RPDYMax = 3;
	double EM_CUT_Xmin = -4;
	double EM_CUT_Xmax = 4;
	

	double neg10_NEG = 0; //for figuring out quantity of bad events
	double neg10_POS = 0;

	double EM = 0;
	double HAD = 1;
	double RPD = 3;

	int INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[NRPD] = {13, 12, 15, 14, 9, 11, 8, 10, 5, 4, 7, 6, 1, 0, 3, 2}; //tenative needs to be checked
													  //{14, 13, 16, 15, 10, 12, 9, 11, 6, 5, 8, 7, 2, 1, 4, 3} // old bfopr noticed out of bounmds array issue and subtracted 1 kept for reference

/////////////these arrays serve the purpoose of storing data so it can be stored later and used event by event//////////////////////////////////////////////////////////////////////			
    double   RawDataEM[NSIDE][NEM][NTS] = {{{0}, {0}, {0}, {0}, {0}},   //neg
										   {{0}, {0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataHAD[NSIDE][NHAD][NTS] = {{{0}, {0}, {0}, {0}},   //neg
	                                       {{0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
										    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos
	

	double X_position_cm[2][16] = {{1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1},  //neg
							   	   {1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1}}; //pos
	
	double Y_position_cm[2][16] = {{-1, 1, 3, -3, -1, 1, 3, -3, 1, -1, -3, 3, 1, -1, -3, 3},  //neg
								   {-1, 1, 3, -3, -1, 3, 1, -3, 1, -1, -3, 3, 1, -1, -3, 3}}; //pos 

	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////
	//DECLARING HISTOGRAMS//
	////////////////////////

	TH1D* EM_P_BEAM;
	TH1D* EM_N_BEAM;
	TH1D* RPDX_P_BEAM;
	TH1D* RPDX_N_BEAM;
	TH1D* EP1dist[NSIDE];
	TH1D* EP2dist[NSIDE];
	TH1D* Qobs1[NSIDE][NXY];
	TH1D* Qobs2[NSIDE][NXY];
	TH1D* RXN_Plane_Resolution_Histo;
	TH1D* RXNP_means_sin[2];
	TH1D* RXNP_means_cos[2];

	TH2D* EMPvEMN;
	TH2D* RPD_Pos_w_RXN_Plane; //4x4 plot
	TH2D* RPD_Neg_w_RXN_Plane; //4x4 plot
/*	TH2D* Pos_EMX_v_RPDX;
	TH2D* Neg_EMX_v_RPDX;
	TH2D* Pos_RPDvRPD;
	TH2D* Neg_RPDvRPD;
	TH2D* RPDXP_v_RPDXN;
	TH2D* RPDYP_v_RPDYN;*/

	//TH2D* RPD_v_EM_P_BEAM;
	//TH2D* RPD_v_EM_N_BEAM;

	
	const char* xytit[NXY] = {"x","y"};
	for(int iside=0;iside<NSIDE;iside++)
	{
	  EP1dist[iside] = new TH1D(Form("EP1dist_%s",stit2[iside]),"EP_{1} distribution;#Psi_{1};[a.u.]",100,-M_PI,M_PI);
	  EP2dist[iside] = new TH1D(Form("EP2dist_%s",stit2[iside]),"EP_{2} distribution;#Psi_{2};[a.u.]",100,-M_PI/2,M_PI/2);
	  for(int ixy=0;ixy<2;ixy++)
	  {
	    Qobs1[iside][ixy] = new TH1D(Form("Qobs1dist_%s_%s",stit2[iside],xytit[ixy]),Form("Q^{obs}_{1,%s}%s distribution;Q^{obs}_{1,%s};[a.u.]",xytit[ixy],stit[iside],xytit[ixy]),100,6,0);
	    Qobs2[iside][ixy] = new TH1D(Form("Qobs2dist_%s_%s",stit2[iside],xytit[ixy]),Form("Q^{obs}_{2,%s}%s distribution;Q^{obs}_{2,%s};[a.u.]",xytit[ixy],stit[iside],xytit[ixy]),100,6,0);
	  }
	}
	
	//create mean histograms
	for (int i = 0; i < 2; i++) {
		RXNP_means_sin[i] = new TH1D(Form("MEANS_SIN_%d", i), Form("MEANS_SIN_%d", i), 1000, 1, 0);
		RXNP_means_cos[i] = new TH1D(Form("MEANS_COS_%d", i), Form("MEANS_COS_%d", i), 1000, 1, 0);
	}

	RXN_Plane_Resolution_Histo = new TH1D(Form("RXNPRes"),"RXN Plane Resolution;Resolution;[a.u.]",100,-M_PI,M_PI);

	///4x4plot
	RPD_Pos_w_RXN_Plane = new TH2D(Form("RPD_Pos %d", runnumber), Form("RPD_Pos_w_RXN_Plane%d", runnumber), 4, -4, 4, 4, -4, 4);

	RPD_Pos_w_RXN_Plane->GetXaxis()->SetNdivisions(4);
	RPD_Pos_w_RXN_Plane->GetYaxis()->SetNdivisions(4);
	
	RPD_Neg_w_RXN_Plane = new TH2D(Form("RPD_Neg %d", runnumber), Form("RPD_Neg_w_RXN_Plane%d", runnumber), 4, -4, 4, 4, -4, 4);
	
	RPD_Neg_w_RXN_Plane->GetXaxis()->SetNdivisions(4);
	RPD_Neg_w_RXN_Plane->GetYaxis()->SetNdivisions(4);
	/// 4x4plot


	TCanvas* c3 = new TCanvas(Form("c3"), Form("RUN_%d", runnumber), 2000, 2000);/// for 4x4 declared early so not in a loop and must be before all histos are made

	EM_P_BEAM = new TH1D(Form("EM_P_BEAM %d", runnumber), Form("P_EM_%d_NBins_%d_MB_2_10fC; EM cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D);
	EM_N_BEAM = new TH1D(Form("EM_N_BEAM %d", runnumber), Form("N_EM_%d_NBins_%d_MB_2_10fC; EM cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D);

	/*RPDX_P_BEAM = new TH1D(Form("RPDX_P_BEAM %d", runnumber), Form("P_RPDX_%d_NBins_%d_MB_2; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D);
	RPDX_N_BEAM = new TH1D(Form("RPDX_N_BEAM %d", runnumber), Form("N_RPDX_%d_NBins_%d_MB_2; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D);
*/
	EMPvEMN = new TH2D(Form("EMPvEMN %d", runnumber), Form("EMPvEMN_%d_NBins_%d_MB_2; EMP cm; EMN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);

	/*Pos_EMX_v_RPDX = new TH2D(Form("XRPD_EM_P_BEAM %d", runnumber), Form("P_RPDX_EM_%d_NBins_%d_MB_2; EM cm; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);
	Neg_EMX_v_RPDX = new TH2D(Form("XRPD_EM_N_BEAM %d", runnumber), Form("N_RPDX_EM_%d_NBins_%d_MB_2; EM cm; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);

	Pos_RPDvRPD = new TH2D(Form("Pos_RPDvRPD %d", runnumber), Form("Pos_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);
	Neg_RPDvRPD = new TH2D(Form("Neg_RPDvRPD %d", runnumber), Form("Neg_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);

	RPDXP_v_RPDXN = new TH2D(Form("RPDXP_v_RPDXN %d", runnumber), Form("RPDXP_v_RPDXN_%d_NBins_%d_MB_2; RPDXP cm; RPDXN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);
	RPDYP_v_RPDYN = new TH2D(Form("RPDYP_v_RPDYN %d", runnumber), Form("RPDYP_v_RPDYN_%d_NBins_%d_MB_2; RPDYP cm; RPDYN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinXTH2D, MaxXTH2D);
*/

	//RPD_v_EM_P_BEAM = new TH2D(Form("RPD_P_BEAM %d", runnumber), Form("RPD_P_BEAM_POSITION_v_EM_%d_NBins_%d_MB_2; EM cm; RPD cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinYTH2D, MaxYTH2D);
	//RPD_v_EM_N_BEAM = new TH2D(Form("RPD_N_BEAM %d", runnumber), Form("RPD_N_BEAM_POSITION_v_EM_%d_NBins_%d_MB_2; EM cm; RPD cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2D, MaxXTH2D, NumberOfBins, MinYTH2D, MaxYTH2D);

	/// END Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Declaring TLeaf for giving root/c++ the ability to call parts of the root tree/////////////////////////////////////////////////////////////////////////////////////////////////////

	TLeaf* fCleaf[NTS];
	//TLeaf* fCPureleaf[NTS];

	// For c++ root tree interface ////////////////////////
	TLeaf* bxidLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("bxid");
	TLeaf* eventLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("event");
	TLeaf* zsideLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("zside");
	TLeaf* sectionLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("section");
	TLeaf* channelLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("channel");
	TLeaf* random = (TLeaf*)ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
	TLeaf* ntracks = (TLeaf*)ZDCDigiTree->GetLeaf("nTrack");
	TLeaf* phi = (TLeaf*)ZDCDigiTree->GetLeaf("phi");
	
	TLeaf* nHFneg = (TLeaf*)ZDCDigiTree->GetLeaf("nHFneg");
	TLeaf* nHFpos = (TLeaf*)ZDCDigiTree->GetLeaf("nHFpos");
	
	NumberofZDCTreeEntries = ZDCDigiTree->GetEntries(); // main purpose of this is to create the array size for storing the rxn plane values for correction/flattening of the event planes

	double PXG = 0;
	double NXG = 0;
	
	double PEMG = 0;
	double NEMG = 0;
	
	double OutPut_WeightedjeffsweightsPos[NRPD] = {0}; //{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	double OutPut_WeightedjeffsweightsNeg[NRPD] = {0}; //{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};// change back to zero they are set to one for testing purposes

	double Pos_Output_Q_Observed_V1_X = 0;
	double Pos_Output_Q_Observed_V1_Y = 0;
	double Pos_Output_Q_Observed_V2_X = 0;
	double Pos_Output_Q_Observed_V2_Y = 0;

	double Neg_Output_Q_Observed_V1_X = 0;
	double Neg_Output_Q_Observed_V1_Y = 0;
	double Neg_Output_Q_Observed_V2_X = 0;
	double Neg_Output_Q_Observed_V2_Y = 0;


/*	double P_RPD_Beam_Position_Value_X = 0;
	double N_RPD_Beam_Position_Value_X = 0;

	double P_RPD_Beam_Position_Value_Y = 0;
	double N_RPD_Beam_Position_Value_Y = 0;
*/

	for (int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
		//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
	}

	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin filling variables with DATA/fC LOOP 
	// https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////

	/*double numtracks = 0;
	double PHI = 0;*/
	
	for (int i = 0; i < NumberofZDCTreeEntries /*ZDCDigiTree->GetEntries()*/; i++) {
		ZDCDigiTree->GetEntry(i);

/*		numtracks = ntracks->GetValue();
		cout << "n" << numtracks << endl;
		
		if (numtracks >6){
			for (int r = 1; r < numtracks; r++){
			PHI = phi->GetValue(r);
			cout << "PHI" << PHI << endl;
			}
		}*/

		for (int n = 0; n < NChannels; n++) { //iterates through all channels of both ZDC + and -
			int side = (int)((zsideLeaf->GetValue(n) + 1) / 2.0);
			int type = (int)(sectionLeaf->GetValue(n)) - 1;
			int channel = (int)(channelLeaf->GetValue(n)) - 1;
	
			/// Begin filling timeslices with fC (discrimination is by channel number iteration)
	
			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			//this is used below to keep values at 0 or greater
			//40 fC nosie cuttoff 
	
			double TS_Zero  = (fCleaf[0]->GetValue(n) <= 0) ? 0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) <= 0) ? 0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) <= 0) ? 0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) <= 0) ? 0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) <= 0) ? 0 : (fCleaf[4]->GetValue(n));
			double TS_Five  = (fCleaf[5]->GetValue(n) <= 0) ? 0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) <= 0) ? 0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) <= 0) ? 0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) <= 0) ? 0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) <= 0) ? 0 : (fCleaf[9]->GetValue(n));
	
			//// RESEARCH CONTINUE STATEMENT SO I CAN SKIP ENTIRE EVENTS THAT HAVE A ts OF 0????
	
			double TS_ARRAY[NTS] = { TS_Zero, TS_One, TS_Two, TS_Three, TS_Four, TS_Five, TS_Six, TS_Seven, TS_Eight, TS_Nine};
	
			// filling arrays with the data per channel side and timeslice for use in the functions that are called. Allows for easier function use and greater efficiency
	
			if (type == EM){
				for (int TS = 0; TS < NTS; TS++){
					RawDataEM[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE EM DATA FOR THAT EVENT
				}
			}
			/*else if (type == HAD){ //figure out what cutoff for HAD
				for (int TS = 0; TS < NTS; TS++){
					RawDataHAD[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE HAD DATA FOR THAT EVENT
				}
			}*/
			else if (type == RPD){ // make sure to set cuttoff to 40 fC for RPD
				for (int TS = 0; TS < NTS; TS++){
					if (side == 0){
						RawDataRPD[side][INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[channel]][TS] = TS_ARRAY[TS];
					}
					else{
						RawDataRPD[side][channel][TS] = TS_ARRAY[TS];
					}	  //USE THIS ARRAY IF YOU WANT THE RPD DATA FOR THAT EVENT
					//	THERE MUST BE A TRTANSLATOR AS RPD CHANNEL # DOES NOT EQUAL REAL CHANNEL NUMBER!!!
				}
			}
		}
	
		PEMG = EM_Beam_Position_Value( RawDataEM, "Pos");
		NEMG = EM_Beam_Position_Value( RawDataEM, "Neg");
		// bug test this to see if its running when neg for pos and pos for neg

		JeffWeighter3000_OutputsArray( NEMG, 0, OutPut_WeightedjeffsweightsNeg); //uncomment this to reactivate jeff weighter theese are deactivated to look for bugs in otehr software
		JeffWeighter3000_OutputsArray( PEMG, 1, OutPut_WeightedjeffsweightsPos);
		
		CalculatesandReturns_Q_ObsforRecentering(RawDataRPD, OutPut_WeightedjeffsweightsPos, "Pos", Pos_Output_Q_Observed_V1_X, Pos_Output_Q_Observed_V1_Y, Pos_Output_Q_Observed_V2_X, Pos_Output_Q_Observed_V2_Y);
		CalculatesandReturns_Q_ObsforRecentering(RawDataRPD, OutPut_WeightedjeffsweightsNeg, "Neg", Neg_Output_Q_Observed_V1_X, Neg_Output_Q_Observed_V1_Y, Neg_Output_Q_Observed_V2_X, Neg_Output_Q_Observed_V2_Y);
	
		if (Pos_Output_Q_Observed_V1_X != -10 && Pos_Output_Q_Observed_V1_Y != -10 && Neg_Output_Q_Observed_V1_X != -10 && Neg_Output_Q_Observed_V1_Y != -10){

			//these are filled to be used later for getting values for recentering
			Qobs1[0][0]->Fill(Pos_Output_Q_Observed_V1_X);
			Qobs1[0][1]->Fill(Pos_Output_Q_Observed_V1_Y);
			Qobs1[1][0]->Fill(Neg_Output_Q_Observed_V1_X);
			Qobs1[1][1]->Fill(Neg_Output_Q_Observed_V1_Y);
		}
		
		
		if (i % 100000 == 0) cout << i << " (PART 1) events are processed." << endl;
	}

	//>>>THIS IS PART 2 THE PURPOSE IS AFTER WEVE GOTTEN THE INFORATION TO RECENTER FROM THE RXN PLANE CALCULATER FUNCTION WE NEED TO USE THAT INFORMATION TO RECENTER
	
	/////////////Begin computations for recentering////////////////////

	//pos
	double Mean_X_Pos = Qobs1[1][0]->GetMean(); //x
	double  RMS_X_Pos = Qobs1[1][0]->GetRMS(); 
	double Mean_Y_Pos = Qobs1[1][1]->GetMean(); //y
	double  RMS_Y_Pos = Qobs1[1][1]->GetRMS(); 

	double PosINPUT_V1orV2_MEAN_X_Y_FOR_Recentering[2] = { Mean_X_Pos, Mean_Y_Pos};
	double PosINPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[2] = { RMS_X_Pos, RMS_Y_Pos};

	 double Mean_X_Neg = Qobs1[0][0]->GetMean(); //neg
	double  RMS_X_Neg = Qobs1[0][0]->GetRMS();
	double Mean_Y_Neg = Qobs1[0][1]->GetMean();
	double  RMS_Y_Neg = Qobs1[0][1]->GetRMS();

	double NegINPUT_V1orV2_MEAN_X_Y_FOR_Recentering[2] = { Mean_X_Neg, Mean_Y_Neg};
	double NegINPUT_V1orV2_SIGMA_X_Y_FOR_Recentering[2] = { RMS_X_Neg,  RMS_Y_Neg};


	/// END math for recentering///////////////////////////////////////////////////////
	double event = 0;
	double POS_OutPut_RPD_Event_Plane_Psi = 0;
	double NEG_OutPut_RPD_Event_Plane_Psi = 0;
	double POS_OutPut_RPDfC_X_Y_coord[16] = {0};
	double NEG_OutPut_RPDfC_X_Y_coord[16] = {0};
	double Output_ReactionPlaneResolution_All_mustbeMeaned = 0;

																	//double INPUT_Event_Plane[NumberofZDCTreeEntries] = {0}; //for the rxn plane correction function so it doesnt have to calculate the rxn plane a 2nd time
																	
	///////////////////////////////////////////////////////////////////////////////////////////	
	//map for storing events and their associated negative and positive RXN plane values
	std::unordered_map<int, RXNP_ValuePair> RXNP_Event_Map;
	///////////////////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < NumberofZDCTreeEntries /*ZDCDigiTree->GetEntries()*/; i++) {
		ZDCDigiTree->GetEntry(i);
		
		event = eventLeaf->GetValue();
		
		for (int n = 0; n < NChannels; n++) { //iterates through all channels of both ZDC + and -
			int side = (int)((zsideLeaf->GetValue(n) + 1) / 2.0);
			int type = (int)(sectionLeaf->GetValue(n)) - 1;
			int channel = (int)(channelLeaf->GetValue(n)) - 1;
	
			/// Begin filling timeslices with fC (discrimination is by channel number iteration)
	
			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			//this is used below to keep values at 0 or greater
	
			double TS_Zero  = (fCleaf[0]->GetValue(n) <= 0) ? 0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) <= 0) ? 0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) <= 0) ? 0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) <= 0) ? 0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) <= 0) ? 0 : (fCleaf[4]->GetValue(n));
			double TS_Five  = (fCleaf[5]->GetValue(n) <= 0) ? 0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) <= 0) ? 0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) <= 0) ? 0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) <= 0) ? 0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) <= 0) ? 0 : (fCleaf[9]->GetValue(n));
	
			//// RESEARCH CONTINUE STATEMENT SO I CAN SKIP ENTIRE EVENTS THAT HAVE A ts OF 0????
	
			double TS_ARRAY[NTS] = { TS_Zero, TS_One, TS_Two, TS_Three, TS_Four, TS_Five, TS_Six, TS_Seven, TS_Eight, TS_Nine};
	
			// filling arrays with the data per channel side and timeslice for use in the functions that are called. Allows for easier function use and greater efficiency
	
			if (type == EM){
				for (int TS = 0; TS < NTS; TS++){
					RawDataEM[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE EM DATA FOR THAT EVENT
				}
			}
			/*else if (type == HAD){ //figure out what cutoff for HAD
				for (int TS = 0; TS < NTS; TS++){
					RawDataHAD[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE HAD DATA FOR THAT EVENT
				}
			}*/
			else if (type == RPD){ // make sure to set cuttoff to 40 fC for RPD
				for (int TS = 0; TS < NTS; TS++){
					if (side == 0){
						RawDataRPD[side][INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[channel]][TS] = TS_ARRAY[TS];
					}
					else{
						RawDataRPD[side][channel][TS] = TS_ARRAY[TS];
					}	  //USE THIS ARRAY IF YOU WANT THE RPD DATA FOR THAT EVENT
					//	THERE MUST BE A TRTANSLATOR AS RPD CHANNEL # DOES NOT EQUAL REAL CHANNEL NUMBER!!!
				}
			}
		}

		PEMG = EM_Beam_Position_Value( RawDataEM, "Pos");
		NEMG = EM_Beam_Position_Value( RawDataEM, "Neg");
		// bug test this to see if its running when neg for pos and pos for neg
		
		JeffWeighter3000_OutputsArray( NEMG, 0, OutPut_WeightedjeffsweightsNeg);
		JeffWeighter3000_OutputsArray( PEMG, 1, OutPut_WeightedjeffsweightsPos); 
	
		CalculatesandReturnsRXN_Plane( RawDataRPD,  OutPut_WeightedjeffsweightsPos, "Pos", "V1", PosINPUT_V1orV2_MEAN_X_Y_FOR_Recentering, PosINPUT_V1orV2_SIGMA_X_Y_FOR_Recentering, POS_OutPut_RPDfC_X_Y_coord, POS_OutPut_RPD_Event_Plane_Psi);
		CalculatesandReturnsRXN_Plane( RawDataRPD,  OutPut_WeightedjeffsweightsNeg, "Neg", "V1", NegINPUT_V1orV2_MEAN_X_Y_FOR_Recentering, NegINPUT_V1orV2_SIGMA_X_Y_FOR_Recentering, NEG_OutPut_RPDfC_X_Y_coord, NEG_OutPut_RPD_Event_Plane_Psi);
		
		//insert RXN plane values into map, indexed by their event number (these values will be corrected and filtered later)
		//if both plane values are -10 (i.e. both invalid), don't insert an entry at all. pairs for which one value is -10 will need to be filtered later
		if (!(NEG_OutPut_RPD_Event_Plane_Psi == -10 && POS_OutPut_RPD_Event_Plane_Psi == -10)) {
			if (RXNP_Event_Map.count(event) != 0) {
				std::cout << "DUPLICATE EVENT DETECTED: " << event << std::endl;
			}
			
			RXNP_Event_Map.insert({
				event,
				RXNP_ValuePair({NEG_OutPut_RPD_Event_Plane_Psi, POS_OutPut_RPD_Event_Plane_Psi})
			});
		}

		int plot_frequency = 9000000; //change this back to 2000

		if (i % plot_frequency /*1000000*/ == 0 && i != 0){ //for every one millition event do the thing
			
			int Bin_Order_Neg[16] = {15, 21, 27, 9, 16, 28, 22, 10, 19, 13, 7, 25, 20, 14, 8, 26}; //Neg order of BINS
	 		int Bin_Order_Pos[16] = {15, 21, 27, 9, 16, 22, 28, 10, 19, 13, 7, 25, 20, 14, 8, 26}; //Pos order of BINS

	 		// the bin order is seemingly non sensical but this is because root is non sensical. // the binning starts at 7 and increases by 4 then skips 2 bins and starts again at 13 //the binning ordering is designed to accomodate the order in which the channels are read out.
				
	 		int number = i/plot_frequency /*1000000*/; //controls frequency quartz block energy histo is drawn

			// this fills a 2d histo with each quartz block so the user can se th actual energy deposition distribution
			if ( NEG_OutPut_RPD_Event_Plane_Psi != -10){
				for (int i = 0; i < 16; i++){
					int bin = Bin_Order_Neg[i];
					RPD_Neg_w_RXN_Plane->SetBinContent(bin, (NEG_OutPut_RPDfC_X_Y_coord[i])); 
				}

				RPD_Neg_w_RXN_Plane->Draw("colz");
				TLine *lineNeg = new TLine(0,0,(cos(NEG_OutPut_RPD_Event_Plane_Psi)*2),(sin(NEG_OutPut_RPD_Event_Plane_Psi)*2) ); 
				lineNeg->SetLineWidth(6);
				lineNeg->Draw(); 	//the lines are drawings of the rxn plane on the quartz block histo
				c3->Print(Form("%s/RPDwRXNP_NEG_%d.png",figdir, number));
			}
			else if ( POS_OutPut_RPD_Event_Plane_Psi != -10){
				for (int i = 0; i < 16; i++){
					int bin = Bin_Order_Pos[i];
					RPD_Pos_w_RXN_Plane->SetBinContent(bin, (POS_OutPut_RPDfC_X_Y_coord[i])); //it might be the other way around idk
				}

				RPD_Pos_w_RXN_Plane->Draw("colz");
				TLine *linePos = new TLine(0,0,(cos(POS_OutPut_RPD_Event_Plane_Psi)*2),(sin(POS_OutPut_RPD_Event_Plane_Psi)*2)); 
				linePos->SetLineWidth(6);
				linePos->Draw();	//the lines are drawings of the rxn plane on the quartz block histo
				c3->Print(Form("%s/RPDwRXNP_POS_%d.png",figdir, number));
				//  https://root.cern.ch/root/roottalk/roottalk01/0493.html	
			}
		}

	/*	if ( POS_OutPut_RPD_Event_Plane_Psi != -10){
			neg10_POS += 1;
			EP1dist[1]->Fill(POS_OutPut_RPD_Event_Plane_Psi);
		}
		//cout << "POS_OutPut_RPD_Event_Plane_Psi" << POS_OutPut_RPD_Event_Plane_Psi << endl;

		if ( NEG_OutPut_RPD_Event_Plane_Psi != -10){
			neg10_NEG += 1;
			EP1dist[0]->Fill(NEG_OutPut_RPD_Event_Plane_Psi);
		}
		//cout << "NEG_OutPut_RPD_Event_Plane_Psi" << NEG_OutPut_RPD_Event_Plane_Psi << endl;


		if ( POS_OutPut_RPD_Event_Plane_Psi != -10 && NEG_OutPut_RPD_Event_Plane_Psi != -10){
			RXN_Plane_Resolution_Histo->Fill(Output_ReactionPlaneResolution_All_mustbeMeaned);
		}
	*/

		//part 2 can grab stuff saved to a root tree instead of redoing calculation may make it faster??? eg rxn plane of em position??
		
		if (i % 100000 == 0) cout << i << " (PART 2) events are processed." << endl;
	}
	
	// PERFORM CORRECTION ON PLANE VALUES WITHIN MAP //
	//calculate mean values of reaction plane angle components
	//populate histograms
	for (auto& RXNP_Event_Pair : RXNP_Event_Map) {
		RXNP_ValuePair& value_pair = RXNP_Event_Pair.second;
		double& RXNP_Neg = value_pair.RXNP_Neg;
		double& RXNP_Pos = value_pair.RXNP_Pos;
		
		//negatives
		if (RXNP_Neg != -10) {
			RXNP_means_sin[0]->Fill(sin(RXNP_Neg));
			RXNP_means_cos[0]->Fill(cos(RXNP_Neg));
		}
		
		//positive
		if (RXNP_Pos != -10) {
			RXNP_means_sin[1]->Fill(sin(RXNP_Pos));
			RXNP_means_cos[1]->Fill(cos(RXNP_Pos));
		}
	}
	
	//calculate means using histograms
	double RXNP_neg_mean_sin = RXNP_means_sin[0]->GetMean();
	double RXNP_neg_mean_cos = RXNP_means_cos[0]->GetMean();
	double RXNP_pos_mean_sin = RXNP_means_sin[1]->GetMean();
	double RXNP_pos_mean_cos = RXNP_means_cos[1]->GetMean();
	
	//iterate over map values for correction
	for (auto& RXNP_Event_Pair : RXNP_Event_Map) {
		RXNP_ValuePair& value_pair = RXNP_Event_Pair.second;
		double& RXNP_Neg = value_pair.RXNP_Neg;
		double& RXNP_Pos = value_pair.RXNP_Pos;
		
		
		if (RXNP_Neg != -10) {
			RXNP_Neg = CalculatesandReturns_I_CORRECTED_I_ReactionPlane("Neg", 2, RXNP_Neg, RXNP_neg_mean_sin, RXNP_neg_mean_cos);
			EP1dist[0]->Fill(RXNP_Neg); //populate reaction neg plane histogram
		}
		
		if (RXNP_Pos != -10) {
			RXNP_Pos = CalculatesandReturns_I_CORRECTED_I_ReactionPlane("Pos", 2, RXNP_Pos, RXNP_pos_mean_sin, RXNP_pos_mean_cos);
			EP1dist[1]->Fill(RXNP_Pos); //populate reaction pos plane histogram
		}
	}

	//Outputs_Resolution_ReactionPlane_to_Mean( POS_OutPut_RPD_Event_Plane_Psi, NEG_OutPut_RPD_Event_Plane_Psi, Output_ReactionPlaneResolution_All_mustbeMeaned);
	
	cout << "NumberofZDCTreeEntries" << NumberofZDCTreeEntries << endl;
	
	double RXN_Plane_Resolution = RXN_Plane_Resolution_Histo->GetMean();

		//cout << "RXN_Plane_Resolution" << RXN_Plane_Resolution << endl;


	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	/// Begin filling sums with data put into histograms (reasoning behind this is I know what I'm putting in my calculations as I can see it, was getting weird bugs before)



	/// END filling sums with data put into histograms...


	///////////////////////////////////////
	// Formatting and drawing histograms //
	///////////////////////////////////////

	TFile f2("ROOT_RPD_Beam_Position_Finder.root", "RECREATE");
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
	////////////////////////////////////////////////////////////////////////////////////////////////
	TCanvas* c1 = new TCanvas(Form("c1"), Form("RUN_%d", runnumber), 2000, 2000);

	Qobs1[0][0]->Draw("hist e");
	c1->Print(Form("%s/Qobs1dist_Neg_X.png",figdir));
	Qobs1[0][1]->Draw("hist e");
	c1->Print(Form("%s/Qobs1dist_Neg_Y.png",figdir));
	Qobs1[1][0]->Draw("hist e");
	c1->Print(Form("%s/Qobs1dist_Pos_X.png",figdir));
	Qobs1[1][1]->Draw("hist e");
	c1->Print(Form("%s/Qobs1dist_Pos_Y.png",figdir));

	TCanvas* c2 = new TCanvas(Form("c2"), Form("RUN_%d", runnumber), 2000, 2000);

	EP1dist[1]->Draw("hist e");
	c2->Print(Form("%s/EP1dist_V1_Pos.png",figdir));

	EP1dist[0]->Draw("hist e");
	c2->Print(Form("%s/EP1dist_V1_Neg.png",figdir));

	//  https://root.cern.ch/root/roottalk/roottalk01/0493.html
	 

/*	EM_P_BEAM->Draw("hist e");

	c1->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_Beam_Position_EM_%d_10fC.png", runnumber, stit2[1], runnumber));

	EM_N_BEAM->Draw("hist e");

	c1->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_Beam_Position_EM_%d_10fC.png", runnumber, stit2[0], runnumber));
	
	
	TCanvas* c2 = new TCanvas(Form("c2"), Form("RUN_%d", runnumber), 2000, 2000);
	
	EMPvEMN->Draw("colz");
	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/EMPvsEMN%d.png", runnumber, runnumber));

	Pos_EMX_v_RPDX->Draw("colz");
	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XRPD_Beam_Position_v_EM_%d.png", runnumber, stit2[1], runnumber));

	Neg_EMX_v_RPDX->Draw("colz");
	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XRPD_Beam_Position_v_EM_%d.png", runnumber, stit2[0], runnumber));

	RPDX_P_BEAM->Draw("hist e");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XRPD_Beam_Position_%d.png", runnumber, stit2[1], runnumber));

	RPDX_N_BEAM->Draw("hist e");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XRPD_Beam_Position_%d.png", runnumber, stit2[0], runnumber));

	Pos_RPDvRPD->Draw("colz");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XvYRPD_Beam_Position_%d.png", runnumber, stit2[1], runnumber));

	Neg_RPDvRPD->Draw("colz");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_XvYRPD_Beam_Position_%d.png", runnumber, stit2[0], runnumber));

	RPDYP_v_RPDYN->Draw("colz");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/RPDYP_v_RPDYN_%d.png", runnumber, runnumber));

	RPDXP_v_RPDXN->Draw("colz");

	c2->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/RPDXP_v_RPDXN_%d.png", runnumber, runnumber));
	*/
	f2.Write();
}

	void initRootStyle()
	{
	//  using namespace RooFit ;

	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1);
	gStyle->SetOptStat(1); /////////////////////////SHOWS THE STATES BOX WHICH CONTAINS THE NUMBER OF ENTRIES///// 0 IS OFF
	gStyle->SetOptTitle(1);
	gStyle->SetOptFit(1);

	gStyle->SetTitleBorderSize(0);
	gStyle->SetTitleFillColor(0);
	gStyle->SetStatColor(0);

	gStyle->SetFrameBorderMode(0);
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameLineColor(kBlack);

	gStyle->SetCanvasColor(0);
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetCanvasBorderSize(0);

	gStyle->SetPadColor(0);
	gStyle->SetPadBorderMode(0);
	gStyle->SetPadBorderSize(0);

	gStyle->SetLegendBorderSize(0);
	//gStyle->SetTextSize(0.04);
	gStyle->SetTextFont(42);
	gStyle->SetLabelFont(42, "xyz");
	gStyle->SetTitleFont(42, "xyz");
	gStyle->SetTitleSize(0.05, "xyz");
	gStyle->SetPadBottomMargin(0.13);
	gStyle->SetPadTopMargin(0.10);
	gStyle->SetPadRightMargin(0.12); // 0.10
	gStyle->SetPadLeftMargin(0.15); // 0.12

	gStyle->SetTitleXOffset(1.1);
	gStyle->SetTitleYOffset(1.5); // 1.2

	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);

	gStyle->SetCanvasDefH(600);
	gStyle->SetCanvasDefW(1200);
	/*
	  gStyle->SetStatX(0.92); // 0.36
	  gStyle->SetStatY(0.92);
	*/
	//gStyle->SetHistMinimumZero(kTRUE);

	//gStyle->SetErrorX(0); //disable if you want to draw horizontal error bars, e.g. when having variable bin size
	gStyle->SetEndErrorSize(1);

	gStyle->SetMarkerStyle(20);
	gStyle->SetMarkerColor(2);
	gStyle->SetMarkerSize(0.2);

	//gROOT->ForceStyle();

	std::cout << "ROOT style loaded." << std::endl;
}