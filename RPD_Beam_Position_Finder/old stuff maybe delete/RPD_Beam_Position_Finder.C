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
#include "CMS_lumi.h" // make a file path for all software
#include "THStack.h" // ERIC ADDED
#include "TPaveLabel.h" //Eric ADDDED
#include <cstring> //colin added
#include <string> // Eric Added
using namespace std;

// I am a chemist not an englishist I cant spell

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!TS456 are not channels BUT TIME SLICES SO THIS IS TIME SLICES 4, 5, & 6 fC SUMMED !!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//function headers
void initRootStyle();
///home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/RPD_Beam_Position_Finder/*AOD_zdc_digi_tree_326776_many_3*/AOD_zdc_digi_tree_327126_many
//main function macro
void RPD_Beam_Position_Finder(int runnumber = 326776 ){
	initRootStyle();
	string Dataset = "AOD_zdc_digi_tree_326776_many_3";
	cout << "Running SOFTWARE: RPD_Beam_Position_Finder 4/10/19 6:15" << endl;
	cout << "Dataset = " << Dataset << ".root"<< endl;


	TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
	TTree* ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree


	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		  int NumberofProcessedRPDEvents = 0;
	const int MinimumBias = 2;
	const int MinXTH2F = -4;
	const int MaxXTH2F = 4;
	const int MinYTH2F = -4;
	const int MaxYTH2F = 4;
	const int NumberOfBins = 64; //number of bins in TH1F histograms produced by this code
	const int NChannels = 50;
	const int NTS = 10;// number of timeslices
	const int NRPD = 16;
	const int NRPDColnRow = 4;
	const int NSIDE = 2; const char* stit[NSIDE] = { "#minus","#plus" };  const char* stit2[NSIDE] = { "neg","pos" };
	const int NTYPE = 2; const char* ttit[NTYPE] = { "EM","HAD" };
	const int NCH = 5; const char* ctit[NTYPE][NCH] = {
														{"1","2","3","4","5"}, //HD sections run only 1-4
														{"1","2","3","4","5"} //EM sections run 1-5
	};
	double AxisRPD[4] = {-3.0, -1.0, 1.0, 3.0};

	/////////////////////////////////////////////
	//Begin ARRAY declaration for RPD constants//
	/////////////////////////////////////////////
	int RPDCorrectBlockOrder[NSIDE][NRPD] = {
											 {11, 15, 2, 6, 8, 12, 1, 5, 9, 13, 0, 4, 10, 14, 3, 7}, //neg =0
											 {11, 15, 2, 5, 8, 12, 1, 6, 9, 13, 0, 4, 10, 14, 3, 7}  //pos =1
	};

	//RPD + 3/8/19
   //12, 16, 3 , 6
	//9, 13, 2 , 7
   //10, 14, 1 , 5
	//11, 15, 4, 8

	//RPD - 3/8/19 //note 7 & 6 flipped between the two bc RPD + had misswiring
   //12, 16, 3 , 7
	//9, 13, 2 , 6
   //10, 14, 1 , 5
	//11, 15, 4, 8


	int RPDCorrectBlockOrderFORPLOTTING[NSIDE][NRPD] = { /// made plots look much better but still have questions
														{11, 7, 3, 15, 12, 4, 8, 16, 5, 9, 13, 1, 6, 10, 14, 2}, //neg =0
														{11, 7, 3, 15, 12, 8, 4, 16, 5, 9, 13, 1, 6, 10, 14, 2}  //pos =1
	};


	//WEIGHTS ARE FROM JEFFS GEANT 10_0 .txt (or something like that)
	float Jeffsweights[NSIDE][NRPD] = {
									   {0.2292, 0.4652, 0.0147, 0.1123, 0.0238, 0.0246, 0.0068, 0.0118, 0.0046, 0.0050, 0.0037, 0.0027, 0.0370, 0.0341, 0.0159, 0.0086}, //neg
									   {0.2292, 0.4652, 0.0147, 0.1123, 0.0238, 0.0068, 0.0246, 0.0118, 0.0046, 0.0050, 0.0037, 0.0027, 0.0370, 0.0341, 0.0159, 0.0086}  //pos 
	}; //these weights are constructed from jeffs geant code output for x position + 1 cm and y position 0 approximating the measured beam position of 9.4 and 9.6 cm (side based)

	float DATAWeightsFromRun_326776[NSIDE][NRPD] = { //data weights from run 326776 v3 many
													{3.47739, 6.60942, 0.247125, 2.27794, 0.300449, 0.335989, 0.103448, 0.204801, 0.0670038, 0.0731469, 0.054854, 0.0500585, 0.677206, 0.601912, 0.272565, 0.168236}, //neg
													{3.66906, 8.89194, 0.20407, 1.65145, 0.428617, 0.105179, 0.321009, 0.159772, 0.09413, 0.0873638, 0.0664756, 0.0505492, 0.564331, 0.50565, 0.249457, 0.137384} //pos
	};


	float RPD_COL_P[NRPDColnRow];
	float RPD_ROW_P[NRPDColnRow];
	float RPD_COL_N[NRPDColnRow];
	float RPD_ROW_N[NRPDColnRow];


	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////
	//DECLARING HISTOGRAMS FOR fC VERSUS TS//
	///////////////////////////////////////// 

	TH2F* RPD_P_BEAM;
	TH2F* RPD_N_BEAM;
	TH1F* RPD_P_BEAM_X1D;
	TH1F* RPD_N_BEAM_X1D;
	
	//THStack* hsRPD[2][16](EXAMPLE);


	RPD_P_BEAM = new TH2F(Form("RPD_P_BEAM %d", runnumber), Form("RPD_P_BEAM_POSITION_%d_NBins_%d_MB_2; cm; cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinYTH2F, MaxYTH2F);
	RPD_N_BEAM = new TH2F(Form("RPD_N_BEAM %d", runnumber), Form("RPD_N_BEAM_POSITION_%d_NBins_%d_MB_2; cm; cm", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F, NumberOfBins, MinYTH2F, MaxYTH2F);
	RPD_P_BEAM_X1D = new TH1F(Form("RPD_P_BEAM_X1D %d", runnumber), Form("RPD_P_BEAM_X1D_%d_NBins_%d_MB_2; cm; counts", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);
	RPD_N_BEAM_X1D = new TH1F(Form("RPD_N_BEAM_X1D %d", runnumber), Form("RPD_N_BEAM_X1D_%d_NBins_%d_MB_2; cm; counts", runnumber, NumberOfBins), NumberOfBins, MinXTH2F, MaxXTH2F);

	//DECLARING NEW THStack FOR PLOTTING MANY HISTOS ON SAME PAD//
	//THStack* hs = new THStack("tHIS ONE", "");

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


	for (int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
		//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
	}

	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin filling variables with DATA/fC LOOP https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////

	for (int i = 0; i < ZDCDigiTree->GetEntries(); i++) {
		ZDCDigiTree->GetEntry(i);
		
		//void * memset ( void * ptr, int value, size_t num );
		memset(RPD_COL_P, 0, sizeof(RPD_COL_P)); //every event reinitialize array to 0 ON THE BYTE LEVEL (Logic will not work for values other than 0)!!!
		memset(RPD_ROW_P, 0, sizeof(RPD_ROW_P));
		memset(RPD_COL_N, 0, sizeof(RPD_COL_N));
        memset(RPD_ROW_N, 0, sizeof(RPD_ROW_N));

		for (int n = 0; n < NChannels; n++) { //iterates through all channels of both ZDC + and -
			int side = (int)((zsideLeaf->GetValue(n) + 1) / 2.0);
			int type = (int)(sectionLeaf->GetValue(n)) - 1;
			int channel = (int)(channelLeaf->GetValue(n)) - 1;
			

			/// Begin filling timeslices with fC (discrimination is by channel number iteration)

			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			//this is used below to keep values at 0 or greater
			//50 fC nosie cuttoff

			double TS_Zero  = (fCleaf[0]->GetValue(n) < 50) ? 0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) < 50) ? 0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) < 50) ? 0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) < 50) ? 0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) < 50) ? 0 : (fCleaf[4]->GetValue(n));
			double TS_Five  = (fCleaf[5]->GetValue(n) < 50) ? 0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) < 50) ? 0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) < 50) ? 0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) < 50) ? 0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) < 50) ? 0 : (fCleaf[9]->GetValue(n));

			/// END filling timeslices with fC (discrimination is by channel number iteration)

			// Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
			double fC_of_TS45_Summed = TS_Four + TS_Five;
			double fC_of_TS456_Summed = TS_Four + TS_Five + TS_Six;

			if ((fC_of_TS456_Summed > 50) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (TS_Seven <= TS_Five) && (TS_One / TS_Zero < 1000) && (TS_Zero != 0)) {
				NumberofProcessedRPDEvents++;
				if (type == 3) {
					if (side == 0){
						
					/// should i use histogram bins instead here because it will be the same data as upposed to 2 different ????
						if (channel == 11 || channel == 15 || channel == 2 || channel == 6) {RPD_ROW_N[0] += fC_of_TS456_Summed;}
						if (channel ==  8 || channel == 12 || channel == 1 || channel == 5) {RPD_ROW_N[1] += fC_of_TS456_Summed;}
						if (channel ==  9 || channel == 13 || channel == 0 || channel == 4) {RPD_ROW_N[2] += fC_of_TS456_Summed;}
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) {RPD_ROW_N[3] += fC_of_TS456_Summed;}			//R0
																																			//R1
						if (channel == 10 ||  channel == 9 ||  channel == 8 || channel == 11) {RPD_COL_N[3] += fC_of_TS456_Summed;}			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) {RPD_COL_N[2] += fC_of_TS456_Summed;}			//R3							
						if (channel ==  3 || channel ==  0 ||  channel == 1 || channel ==  2) {RPD_COL_N[1] += fC_of_TS456_Summed;}			  //C3 C2 C1 C0					
						if (channel ==  7 ||  channel == 4 ||  channel == 5 || channel ==  6) {RPD_COL_N[0] += fC_of_TS456_Summed;}											
					}
					else{
						if (channel == 11 || channel == 15 || channel == 2 || channel == 5) {RPD_ROW_P[0] += fC_of_TS456_Summed;}
						if (channel ==  8 || channel == 12 || channel == 1 || channel == 6) {RPD_ROW_P[1] += fC_of_TS456_Summed;}
						if (channel ==  9 || channel == 13 || channel == 0 || channel == 4) {RPD_ROW_P[2] += fC_of_TS456_Summed;}
						if (channel == 10 || channel == 14 || channel == 3 || channel == 7) {RPD_ROW_P[3] += fC_of_TS456_Summed;}			//R0
																																			//R1
						if (channel == 10 ||  channel == 9 ||  channel == 8 || channel == 11) {RPD_COL_P[3] += fC_of_TS456_Summed;}			//R2             
						if (channel == 14 || channel == 13 || channel == 12 || channel == 15) {RPD_COL_P[2] += fC_of_TS456_Summed;}			//R3							
						if (channel ==  3 || channel ==  0 ||  channel == 1 || channel ==  2) {RPD_COL_P[1] += fC_of_TS456_Summed;}			  //C3 C2 C1 C0					
						if (channel ==  7 ||  channel == 4 ||  channel == 6 || channel ==  5) {RPD_COL_P[0] += fC_of_TS456_Summed;}									
					}
				}	
			}
		}
		double sumWeightRPD_P_X, sumRPD_P_X, sumWeightRPD_P_Y, sumRPD_P_Y, sumWeightRPD_N_X, sumRPD_N_X, sumWeightRPD_N_Y, sumRPD_N_Y;
		//weights for channel 1 2 3 4 but change them to position
		if ( RPD_COL_P[0] > 0 && RPD_COL_P[1] > 0 && RPD_COL_P[2] > 0 && RPD_COL_P[3] > 0 ){
			sumWeightRPD_P_X = (RPD_COL_P[0] * AxisRPD[0]) + (RPD_COL_P[1] * AxisRPD[1]) + (RPD_COL_P[2] * AxisRPD[2]) + (RPD_COL_P[3] * AxisRPD[3]);
			sumRPD_P_X = (RPD_COL_P[0]) + (RPD_COL_P[1]) + (RPD_COL_P[2]) + (RPD_COL_P[3]);
		}
		if ( RPD_ROW_P[0] > 0 && RPD_ROW_P[1] > 0 && RPD_ROW_P[2] > 0 && RPD_ROW_P[3] > 0 ){
			sumWeightRPD_P_Y = (RPD_ROW_P[0] * AxisRPD[0]) + (RPD_ROW_P[1] * AxisRPD[1]) + (RPD_ROW_P[2] * AxisRPD[2]) + (RPD_ROW_P[3] * AxisRPD[3]);
			sumRPD_P_Y = (RPD_ROW_P[0]) + (RPD_ROW_P[1]) + (RPD_ROW_P[2]) + (RPD_ROW_P[3]);
		}
		if ( RPD_COL_N[0] > 0 && RPD_COL_N[1] > 0 && RPD_COL_N[2] > 0 && RPD_COL_N[3] > 0 ){
			sumWeightRPD_N_X = (RPD_COL_N[0] * AxisRPD[0]) + (RPD_COL_N[1] * AxisRPD[1]) + (RPD_COL_N[2] * AxisRPD[2]) + (RPD_COL_N[3] * AxisRPD[3]);
			sumRPD_N_X = (RPD_COL_N[0]) + (RPD_COL_N[1]) + (RPD_COL_N[2]) + (RPD_COL_N[3]);
		}
		if ( RPD_ROW_N[0] > 0 && RPD_ROW_N[1] > 0 && RPD_ROW_N[2] > 0 && RPD_ROW_N[3] > 0 ){
			sumWeightRPD_N_Y = (RPD_ROW_N[0] * AxisRPD[0]) + (RPD_ROW_N[1] * AxisRPD[1]) + (RPD_ROW_N[2] * AxisRPD[2]) + (RPD_ROW_N[3] * AxisRPD[3]);
			sumRPD_N_Y = (RPD_ROW_N[0]) + (RPD_ROW_N[1]) + (RPD_ROW_N[2]) + (RPD_ROW_N[3]);
		}




/* 		double sumWeightRPD_P_X = (RPD_COL_P[0] * AxisRPD[0]) + (RPD_COL_P[1] * AxisRPD[1]) + (RPD_COL_P[2] * AxisRPD[2]) + (RPD_COL_P[3] * AxisRPD[3]);
		double sumRPD_P_X = (RPD_COL_P[0]) + (RPD_COL_P[1]) + (RPD_COL_P[2]) + (RPD_COL_P[3]);
		double sumWeightRPD_P_Y = (RPD_ROW_P[0] * AxisRPD[0]) + (RPD_ROW_P[1] * AxisRPD[1]) + (RPD_ROW_P[2] * AxisRPD[2]) + (RPD_ROW_P[3] * AxisRPD[3]);
		double sumRPD_P_Y = (RPD_ROW_P[0]) + (RPD_ROW_P[1]) + (RPD_ROW_P[2]) + (RPD_ROW_P[3]);
		
		double sumWeightRPD_N_X = (RPD_COL_N[0] * AxisRPD[0]) + (RPD_COL_N[1] * AxisRPD[1]) + (RPD_COL_N[2] * AxisRPD[2]) + (RPD_COL_N[3] * AxisRPD[3]);
		double sumRPD_N_X = (RPD_COL_N[0]) + (RPD_COL_N[1]) + (RPD_COL_N[2]) + (RPD_COL_N[3]);
		double sumWeightRPD_N_Y = (RPD_ROW_N[0] * AxisRPD[0]) + (RPD_ROW_N[1] * AxisRPD[1]) + (RPD_ROW_N[2] * AxisRPD[2]) + (RPD_ROW_N[3] * AxisRPD[3]);
		double sumRPD_N_Y = (RPD_ROW_N[0]) + (RPD_ROW_N[1]) + (RPD_ROW_N[2]) + (RPD_ROW_N[3]);
 */
		//2D
		RPD_P_BEAM->Fill( (sumWeightRPD_P_X/sumRPD_P_X), (sumWeightRPD_P_Y/sumRPD_P_Y));
		RPD_N_BEAM->Fill( (sumWeightRPD_N_X/sumRPD_N_X), (sumWeightRPD_N_Y/sumRPD_N_Y));	
		
		if((sumWeightRPD_N_X/sumRPD_N_X) == -1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == -3.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 1.0 || (sumWeightRPD_N_X/sumRPD_N_X) == 3.0){
		cout <<  "sumWeightRPD_P_X " <<  sumWeightRPD_P_X << endl;
		cout << (RPD_COL_P[0] * AxisRPD[0]) << "  " << (RPD_COL_P[1] * AxisRPD[1]) << "  " << (RPD_COL_P[2] * AxisRPD[2]) << "  " << (RPD_COL_P[3] * AxisRPD[3]) << endl;
		cout << "sumRPD_P_X " << sumRPD_P_X << endl;
		cout << (RPD_COL_P[0]) << "  " << (RPD_COL_P[1]) << "  " << (RPD_COL_P[2]) << "  " << (RPD_COL_P[3]) << endl;
		}
		
		
		//1D
		//if ( -.9 < sumWeightRPD_N_Y/sumRPD_N_Y && sumWeightRPD_N_Y/sumRPD_N_Y < 1){
			RPD_N_BEAM_X1D->Fill((sumWeightRPD_N_X/sumRPD_N_X));
			
		//}
		//if ( -.9 < sumWeightRPD_P_Y/sumRPD_P_Y && sumWeightRPD_P_Y/sumRPD_P_Y < 1){
			RPD_P_BEAM_X1D->Fill((sumWeightRPD_P_X/sumRPD_P_X));
		//}
		
		
		
		if (i % 100000 == 0) cout << i << " events are processed." << endl;
	}

	
		


	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << NumberofProcessedRPDEvents << " of Qualified RPD Events were Processed" << endl;


	/// Begin filling sums with data put into histograms (reasoning behind this is I know what I'm putting in my calculations as I can see it, was getting weird bugs before)



	/// END filling sums with data put into histograms...


	//////////////////////////////////////////
	//CREATING NORMALIZATION OF REAL WEIGHTS//
	//////////////////////////////////////////





	///////////////////////////////////////
	// Formatting and drawing histograms //
	///////////////////////////////////////

TFile f2("ROOT_RPD_Beam_Position_Finder.root", "RECREATE");

////////////////////////////////////////////////////////////////////////////////////////////////
//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
////////////////////////////////////////////////////////////////////////////////////////////////
TCanvas* c1 = new TCanvas(Form("c1"), Form("RUN_%d", runnumber), 2000, 1500);
//TPad* newpad = new TPad("newpad", "a transparent pad", 0, 0, 1, 1);
//newpad->SetFillStyle(4000);
//newpad->Draw();
RPD_P_BEAM->Draw("colz");
//TPaveLabel* title = new TPaveLabel(0.1, 0.94, 0.9, 0.98, Form("%s_RPD_%d", stit2[1], runnumber));
//title->SetFillColor(16);
//title->SetTextSize(2);
//title->Draw();
c1->SaveAs(Form("ZDC_figures/RPD_Beam_Position_Finder_%d/RPD_%s_Beam_Position_%d.png", runnumber, stit2[1], runnumber));

TCanvas* c2 = new TCanvas(Form("c2"), Form("RUN_%d", runnumber), 2000, 1500);
RPD_N_BEAM->Draw("colz");
/* TPaveLabel* title2 = new TPaveLabel(0.1, 0.94, 0.9, 0.98, Form("%s_RPD_%d", stit2[0], runnumber));
title2->SetFillColor(16);
title2->SetTextSize(2);
title2->Draw(); */
c2->SaveAs(Form("ZDC_figures/RPD_Beam_Position_Finder_%d/RPD_%s_Beam_Position_%d.png", runnumber, stit2[0], runnumber));

TCanvas* c3 = new TCanvas(Form("c3"), Form("RUN_%d", runnumber), 2000, 1500);
RPD_P_BEAM_X1D->Draw("hist e");
c3->SaveAs(Form("ZDC_figures/RPD_Beam_Position_Finder_%d/Xaxis_RPD_%s_Beam_Position_%d.png", runnumber, stit2[1], runnumber));

TCanvas* c4 = new TCanvas(Form("c4"), Form("RUN_%d", runnumber), 2000, 1500);
RPD_N_BEAM_X1D->Draw("hist e");
c4->SaveAs(Form("ZDC_figures/RPD_Beam_Position_Finder_%d/Xaxis_RPD_%s_Beam_Position_%d.png", runnumber, stit2[0], runnumber));

f2.Write();

return;
}


void initRootStyle()
{
	//  using namespace RooFit ;

	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1);
	gStyle->SetOptStat(1); /////////////////////////SHOWS THE STATES BOX WHICH CONTAINS THE NUMBER OF ENTRIES///// 0 IS OFF
	gStyle->SetOptTitle(1);
	gStyle->SetOptFit(0);

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