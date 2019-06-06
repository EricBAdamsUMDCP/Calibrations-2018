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
#include "THStack.h" // ERIC ADDED
#include "TPaveLabel.h" //Eric ADDDED
#include <cstring> //colin added
#include <string> // Eric Added

//function headers
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/EM_Beam_Position_returns_Value_function.h" // custom header writte by Eric A
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/RunWeighted_RPD_Beam_Position_Finder.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/JeffWeighter3000.h" //custom header written by Eric A to measure RPD beam postion in X and Y
using namespace std;

// I am a chemist not an englishist I cant spell



//put error in above bc need to chnage rpd beam position finder for neg to invert like we observe now and MUST CHANGE JEFF WEIGHTER OR MAYBE CHNAGE INPUT DATA

void initRootStyle();
///home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/RPD_Beam_Position_Finder/*AOD_zdc_digi_tree_326776_many_3*/AOD_zdc_digi_tree_327126_many

int runnumber = 326776;

void EMtoRXNPlanePrototype_PlayGround(){
	initRootStyle();
	string Dataset = "AOD_zdc_digi_tree_326776_many_3";
	cout << "Running SOFTWARE: EMtoRXNPlanePrototype_PlayGround.C 6/6/2019 2:20:19 PM" << endl;
	cout << "Dataset = " << Dataset << ".root"<< endl;

	//TFile* f = new TFile("/home/ebadams/Merged_Root_Files_PbPb2018/MB_2/326776/PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root"); // opening root fie (only have 1 uncommented)
	
	TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
	
	TTree* ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree


	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const int MinimumBias = 2;
	const int MinXTH2F = -4;
	const int MaxXTH2F = 4;
	const int MinYTH2F = -4;
	const int MaxYTH2F = 4;
	const int NumberOfBins = 64; //number of bins in TH1F histograms produced by this code
	const int NChannels = 50;
	const int NTS = 10;// number of timeslices
	const int NRPD = 16;
	const int NEM = 5;
	const int NHAD = 4;
	const int NRPDColnRow = 4;
	const int NSIDE = 2; const char* stit[NSIDE] = { "#minus","#plus" };  const char* stit2[NSIDE] = { "neg","pos" };

	double RPDXmin = -3;
	double RPDXmax = 3;
	double RPDYMin = -3;
	double RPDYMax = 3;
	double EM_CUT_Xmin = -4;
	double EM_CUT_Xmax = 4;

	double EM = 0;
	double HAD = 1;
	double RPD = 3;

	int INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[NRPD] = {14, 13, 16, 15, 10, 12, 9, 11, 6, 5, 8, 7, 2, 1, 4, 3}; //tenative needs to be checked
			

/////////////these arrays serve the purpoose of storing data so it can be stored later and used event by event//////////////////////////////////////////////////////////////////////			
    double   RawDataEM[NSIDE][NEM][NTS] = {{{0}, {0}, {0}, {0}, {0}},   //neg
										   {{0}, {0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataHAD[NSIDE][NHAD][NTS] = {{{0}, {0}, {0}, {0}},   //neg
	                                       {{0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
										    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos
	

	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////
	//DECLARING HISTOGRAMS//
	////////////////////////

	TH1F* EM_P_BEAM;
	TH1F* EM_N_BEAM;
	TH1F* RPDX_P_BEAM;
	TH1F* RPDX_N_BEAM;

	TH2F* EMPvEMN;
	TH2F* Pos_EMX_v_RPDX;
	TH2F* Neg_EMX_v_RPDX;
	TH2F* Pos_RPDvRPD;
	TH2F* Neg_RPDvRPD;
	TH2F* RPDXP_v_RPDXN;
	TH2F* RPDYP_v_RPDYN;

	//TH2F* RPD_v_EM_P_BEAM;
	//TH2F* RPD_v_EM_N_BEAM;

	EM_P_BEAM = new TH1F(Form("EM_P_BEAM %d", runnumber), Form("P_EM_%d_NBins_%d_MB_2_10fC; EM cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);
	EM_N_BEAM = new TH1F(Form("EM_N_BEAM %d", runnumber), Form("N_EM_%d_NBins_%d_MB_2_10fC; EM cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);

	RPDX_P_BEAM = new TH1F(Form("RPDX_P_BEAM %d", runnumber), Form("P_RPDX_%d_NBins_%d_MB_2; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);
	RPDX_N_BEAM = new TH1F(Form("RPDX_N_BEAM %d", runnumber), Form("N_RPDX_%d_NBins_%d_MB_2; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);

	EMPvEMN = new TH2F(Form("EMPvEMN %d", runnumber), Form("EMPvEMN_%d_NBins_%d_MB_2; EMP cm; EMN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);

	Pos_EMX_v_RPDX = new TH2F(Form("XRPD_EM_P_BEAM %d", runnumber), Form("P_RPDX_EM_%d_NBins_%d_MB_2; EM cm; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);
	Neg_EMX_v_RPDX = new TH2F(Form("XRPD_EM_N_BEAM %d", runnumber), Form("N_RPDX_EM_%d_NBins_%d_MB_2; EM cm; RPDX cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);

	Pos_RPDvRPD = new TH2F(Form("Pos_RPDvRPD %d", runnumber), Form("Pos_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);
	Neg_RPDvRPD = new TH2F(Form("Neg_RPDvRPD %d", runnumber), Form("Neg_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);

	RPDXP_v_RPDXN = new TH2F(Form("RPDXP_v_RPDXN %d", runnumber), Form("RPDXP_v_RPDXN_%d_NBins_%d_MB_2; RPDXP cm; RPDXN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);
	RPDYP_v_RPDYN = new TH2F(Form("RPDYP_v_RPDYN %d", runnumber), Form("RPDYP_v_RPDYN_%d_NBins_%d_MB_2; RPDYP cm; RPDYN cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinXTH2F, MaxXTH2F);


	//RPD_v_EM_P_BEAM = new TH2F(Form("RPD_P_BEAM %d", runnumber), Form("RPD_P_BEAM_POSITION_v_EM_%d_NBins_%d_MB_2; EM cm; RPD cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinYTH2F, MaxYTH2F);
	//RPD_v_EM_N_BEAM = new TH2F(Form("RPD_N_BEAM %d", runnumber), Form("RPD_N_BEAM_POSITION_v_EM_%d_NBins_%d_MB_2; EM cm; RPD cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinYTH2F, MaxYTH2F);

	/// END Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Declaring TLeaf for giving root/c++ the ability to call parts of the root tree/////////////////////////////////////////////////////////////////////////////////////////////////////

	TLeaf* fCleaf[NTS];
	//TLeaf* fCPureleaf[NTS];

	// For c++ root tree interface ////////////////////////
	TLeaf* bxidLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("bxid");
	TLeaf* zsideLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("zside");
	TLeaf* sectionLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("section");
	TLeaf* channelLeaf = (TLeaf*)ZDCDigiTree->GetLeaf("channel");
	TLeaf* random = (TLeaf*)ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
	TLeaf* ntrk = (TLeaf*)ZDCDigiTree->GetLeaf("nTrack");
	TLeaf* nHFneg = (TLeaf*)ZDCDigiTree->GetLeaf("nHFneg");
	TLeaf* nHFpos = (TLeaf*)ZDCDigiTree->GetLeaf("nHFpos");

	
	double PXG = 0;
	double NXG = 0;
	
	double PEMG = 0;
	double NEMG = 0;
	
	double OutPut_WeightedjeffsweightsPos[NRPD] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//{0};
	double OutPut_WeightedjeffsweightsNeg[NRPD] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//{0}; // change back to zero they are set to one for testing purposes

	double P_RPD_Beam_Position_Value_X = 0;
	double N_RPD_Beam_Position_Value_X = 0;

	double P_RPD_Beam_Position_Value_Y = 0;
	double N_RPD_Beam_Position_Value_Y = 0;


	for (int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
		//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
	}

	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin filling variables with DATA/fC LOOP 
	// https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////


	//for (int h = 0; h < 2; h) { //THIS FOR LOOKS NEEDS TO BE ACTIVATED WHEN PART 2 IS ACTIVATED
		for (int i = 0; i < ZDCDigiTree->GetEntries(); i++) {
			ZDCDigiTree->GetEntry(i);
	
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
				else if (type == HAD){ //figure out what cutoff for HAD
					for (int TS = 0; TS < NTS; TS++){
						RawDataHAD[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE HAD DATA FOR THAT EVENT
					}
				}
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
	
			//	PXG = RPD_Beam_Position_Finder( RawDataRPD, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "X", "Give");
			//	NXG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "X", "Give", 326776);
		
			PEMG = EM_Beam_Position_Value( RawDataEM, "Pos");
			NEMG = EM_Beam_Position_Value( RawDataEM, "Neg");
			// bug test this to see if its running when neg for pos and pos for neg
			
			

			/*JeffWeighter3000_OutputsArray( NEMG, 0, OutPut_WeightedjeffsweightsNeg); //uncomment this to reactivate jeff weighter theese are deactivated to look for bugs in otehr software
			JeffWeighter3000_OutputsArray( PEMG, 1, OutPut_WeightedjeffsweightsPos);*/
	
	
	
			P_RPD_Beam_Position_Value_X = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, PEMG, "Pos", "X");
			N_RPD_Beam_Position_Value_X = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, NEMG, "Neg", "X");
	
			P_RPD_Beam_Position_Value_Y = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, PEMG, "Pos", "Y");
			/*cout << "PEMG" << PEMG << endl; //used for trouble shooting jeffweighter when its off there is a bug but i dont know what
			cout << "P_RPD_Beam_Position_Value_X " << P_RPD_Beam_Position_Value_X << endl;
			cout << "P_RPD_Beam_Position_Value_Y " << P_RPD_Beam_Position_Value_Y << endl;*/
			N_RPD_Beam_Position_Value_Y = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, NEMG, "Neg", "Y");
			/*cout << "NEMG" << NEMG << endl; //used for trouble shooting jeffweighter when its off there is a bug but i dont know what
			cout << "N_RPD_Beam_Position_Value_X " << N_RPD_Beam_Position_Value_X << endl;
			cout << "N_RPD_Beam_Position_Value_Y " << N_RPD_Beam_Position_Value_Y << endl;*/
	
				/// remeber to change the ru nwerighted rpd beam headerr back asxd i chanegd the output vgalues!!!!!!!!!!!!!!!!
	
			if (PEMG != -10 && NEMG != -10){
				EMPvEMN->Fill(PEMG, NEMG);
			}
	
			if (P_RPD_Beam_Position_Value_Y != -10 && N_RPD_Beam_Position_Value_Y != -10){
	
				RPDYP_v_RPDYN->Fill(P_RPD_Beam_Position_Value_Y, N_RPD_Beam_Position_Value_X);
			}
	
			if (P_RPD_Beam_Position_Value_X != -10 && N_RPD_Beam_Position_Value_X != -10){
				RPDXP_v_RPDXN->Fill(P_RPD_Beam_Position_Value_X, N_RPD_Beam_Position_Value_X);
			}
	
			if (P_RPD_Beam_Position_Value_X != -10){
				RPDX_P_BEAM->Fill(P_RPD_Beam_Position_Value_X);
				if (P_RPD_Beam_Position_Value_Y != -10){
					Pos_RPDvRPD->Fill(P_RPD_Beam_Position_Value_X, P_RPD_Beam_Position_Value_Y);
				}
			}
			if(N_RPD_Beam_Position_Value_X != -10){
				RPDX_N_BEAM->Fill(N_RPD_Beam_Position_Value_X);
				if (N_RPD_Beam_Position_Value_Y != -10){
					Neg_RPDvRPD->Fill(N_RPD_Beam_Position_Value_X, N_RPD_Beam_Position_Value_Y);
				}
			}
	
			if ( N_RPD_Beam_Position_Value_X != -10){
				RPDX_N_BEAM->Fill(N_RPD_Beam_Position_Value_X);
			}
	
			if ( PEMG != -10){
				EM_P_BEAM->Fill( PEMG);	
				if (P_RPD_Beam_Position_Value_X != -10){
				
				Pos_EMX_v_RPDX->Fill(PEMG, P_RPD_Beam_Position_Value_X);
				
				}
			}
			if (NEMG != -10){ 
				EM_N_BEAM->Fill( NEMG);
				if(N_RPD_Beam_Position_Value_X != -10){
	
				Neg_EMX_v_RPDX->Fill(NEMG, N_RPD_Beam_Position_Value_X);
				}
			}
	
	
	
			/*for (int i = 0; i <15; i++){
				cout << i << ": " << OutPut_WeightedjeffsweightsPos[i] << " EM: " << PEMG << endl;
			}
*/	
	
	
		/*	if (chicken != -10){
			EM_N_BEAM->Fill( chicken);
			}*/
	
			//cout << "X beam" << " " << chicken << endl;
	
			// PUT IN JEFF WEIGHTER 3000
	
			/*cout << PEMG << endl;
	
			if (PEMG < 0){
				cout << "negative" << endl;
			}
			else if (PEMG > 0){
				cout << "Positive" << endl;
			}
			else {
				cout << "ZERO" << endl;
			}*/
			
			/*JeffWeighter3000_OutputsArray( PEMG, 1, OutPut_WeightedjeffsweightsPos);
		
				//PUT IN THING TO KILL OFF OLD MEMORY ADRESSES
			cout << "event " << i << endl;
			for (int i = 0; i <16; i++){
				cout << "OutPut_WeightedjeffsweightsPos " << i << ": " << OutPut_WeightedjeffsweightsPos[i] << endl;
			}*/
			
			
			if (i % 100000 == 0) cout << i << " events are processed." << endl;
		}

/*		//THIS IS FOR PART 2 THE PURPOSE IS AFTER WEVE GOTTEN THE INFORATION TO RECENTER FROM THE RXN PLANE CALCULATER FUNCTION WE NEED TO USE THAT INFORMATION TO RECENTER

		for (int i = 0; i < ZDCDigiTree->GetEntries(); i++) {
			ZDCDigiTree->GetEntry(i);
	
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
				else if (type == HAD){ //figure out what cutoff for HAD
					for (int TS = 0; TS < NTS; TS++){
						RawDataHAD[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE HAD DATA FOR THAT EVENT
					}
				}
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
	
			//	PXG = RPD_Beam_Position_Finder( RawDataRPD, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "X", "Give");
			//	NXG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "X", "Give", 326776);
		
			PEMG = EM_Beam_Position_Value( RawDataEM, "Pos");
			NEMG = EM_Beam_Position_Value( RawDataEM, "Neg");
			// bug test this to see if its running when neg for pos and pos for neg
			
			JeffWeighter3000_OutputsArray( NEMG, 0, OutPut_WeightedjeffsweightsNeg);
			JeffWeighter3000_OutputsArray( PEMG, 1, OutPut_WeightedjeffsweightsPos);
	
	
	
			P_RPD_Beam_Position_Value_X = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, PEMG, "Pos", "X");
			N_RPD_Beam_Position_Value_X = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, NEMG, "Neg", "X");
	
			P_RPD_Beam_Position_Value_Y = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, PEMG, "Pos", "Y");
			
			N_RPD_Beam_Position_Value_Y = RPD_Beam_Position_Value_X_or_Y(RawDataRPD, OutPut_WeightedjeffsweightsPos, NEMG, "Neg", "Y");

			//part 2 can grab stuff saved to a root tree instead of redoing calculation may make it faster??? eg rxn plane of em position
			
			if (i % 100000 == 0) cout << i << " events are processed." << endl;
		}*/
		
		
	//} //THIS BRAKET IS FOR THE FOR LOOP FOR PART 2 <<<<<-------


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
	//TPad* newpad = new TPad("newpad", "a transparent pad", 0, 0, 1, 1);
	//newpad->SetFillStyle(4000);
	//newpad->Draw();
	EM_P_BEAM->Draw("hist e");
	//TPaveLabel* title = new TPaveLabel(0.1, 0.94, 0.9, 0.98, Form("%s_RPD_%d", stit2[1], runnumber));
	//title->SetFillColor(16);
	//title->SetTextSize(2);
	//title->Draw();
	c1->SaveAs(Form("ZDC_figures/EMtoRXNPlanePrototype_PlayGround_%d/%s_Beam_Position_EM_%d_10fC.png", runnumber, stit2[1], runnumber));

	EM_N_BEAM->Draw("hist e");
	/* TPaveLabel* title2 = new TPaveLabel(0.1, 0.94, 0.9, 0.98, Form("%s_RPD_%d", stit2[0], runnumber));
	title2->SetFillColor(16);
	title2->SetTextSize(2);
	title2->Draw(); */
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