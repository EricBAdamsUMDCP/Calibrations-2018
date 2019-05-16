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

using namespace std;

// I am a chemist not an englishist I cant spell


void initRootStyle();
///home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/RPD_Beam_Position_Finder/*AOD_zdc_digi_tree_326776_many_3*/AOD_zdc_digi_tree_327126_many

int runnumber = 326776;

void EM_and_RPD_dEdX_fc_per_channel_dist(){
	initRootStyle();
	string Dataset = "AOD_zdc_digi_tree_326776_many_3";
	cout << "Running SOFTWARE: EM_and_RPD_dEdX_fc_per_channel_dist.C 5/16/2019 1:32:38 PM" << endl;
	cout << "Dataset = " << Dataset << ".root"<< endl;


	TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
	TTree* ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree


	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const int MinimumBias = 2;


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


	//TH2F* RPD_v_EM_P_BEAM;
	//TH2F* RPD_v_EM_N_BEAM;

	EM_P_BEAM = new TH1F(Form("EM_P_BEAM %d", runnumber), Form("P_EM_%d_NBins_%d_MB_2_10fC; EM cm; fC", runnumber, 5), 5, 0, 5);
	EM_N_BEAM = new TH1F(Form("EM_N_BEAM %d", runnumber), Form("N_EM_%d_NBins_%d_MB_2_10fC; EM cm; fC", runnumber, 5), 5, 0, 5);

	RPDX_P_BEAM = new TH1F(Form("RPDX_P_BEAM %d", runnumber), Form("P_RPDX_%d_NBins_%d_MB_2; RPDX cm; fC", runnumber, 4), 4, 0, 4);
	RPDX_N_BEAM = new TH1F(Form("RPDX_N_BEAM %d", runnumber), Form("N_RPDX_%d_NBins_%d_MB_2; RPDX cm; fC", runnumber, 4), 4, 0, 4);


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

	
	const int NCH = 5;
	float EMX[NCH] = { 0, 1, 2, 3, 4};
	static double EMChannelP[NCH] = {0};
	static double EMChannelN[NCH] = {0};
	float RPD_COL_P[NRPDColnRow] = {0};
	float RPD_COL_N[NRPDColnRow] = {0};
	float RPDX[4] = {0, 1, 2, 3};

	double fC_of_TS45_Summed = 0;
	double fC_of_TS456_Summed = 0;

	for (int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
		//fCPureleaf[iTS] = (TLeaf*)ZDCDigiTree->GetLeaf(Form("nfC%d", iTS));
	}

	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin filling variables with DATA/fC LOOP 
	// https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////

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
					RawDataRPD[side][channel][TS] = TS_ARRAY[TS];  //USE THIS ARRAY IF YOU WANT THE RPD DATA FOR THAT EVENT
					//	THERE MUST BE A TRTANSLATOR AS RPD CHANNEL # DOES NOT EQUAL REAL CHANNEL NUMBER!!!
				}
			}
		}


	//ternary operators (look them up)

	// says if the value of TS 4 and 5 are independently greater than 100 fC then sum Ts 4 and TS 5 and set it equal to that array memebr if theyy are not set that array member to 0!
	EMChannelP[0] = (RawDataEM[1][0][4] > 10 && RawDataEM[1][0][5] > 10) ? (RawDataEM[1][0][4] + RawDataEM[1][0][5]) : 0.0;
	EMChannelP[1] = (RawDataEM[1][1][4] > 10 && RawDataEM[1][1][5] > 10) ? (RawDataEM[1][1][4] + RawDataEM[1][1][5]) : 0.0;
	EMChannelP[2] = (RawDataEM[1][2][4] > 10 && RawDataEM[1][2][5] > 10) ? (RawDataEM[1][2][4] + RawDataEM[1][2][5]) : 0.0;
	EMChannelP[3] = (RawDataEM[1][3][4] > 10 && RawDataEM[1][3][5] > 10) ? (RawDataEM[1][3][4] + RawDataEM[1][3][5]) : 0.0;
	EMChannelP[4] = (RawDataEM[1][4][4] > 10 && RawDataEM[1][4][5] > 10) ? (RawDataEM[1][4][4] + RawDataEM[1][4][5]) : 0.0; 
 
	EMChannelN[0] = (RawDataEM[0][0][4] > 10 && RawDataEM[0][0][5] > 10) ? (RawDataEM[0][0][4] + RawDataEM[0][0][5]) : 0.0;
	EMChannelN[1] = (RawDataEM[0][1][4] > 10 && RawDataEM[0][1][5] > 10) ? (RawDataEM[0][1][4] + RawDataEM[0][1][5]) : 0.0;
	EMChannelN[2] = (RawDataEM[0][2][4] > 10 && RawDataEM[0][2][5] > 10) ? (RawDataEM[0][2][4] + RawDataEM[0][2][5]) : 0.0;
	EMChannelN[3] = (RawDataEM[0][3][4] > 10 && RawDataEM[0][3][5] > 10) ? (RawDataEM[0][3][4] + RawDataEM[0][3][5]) : 0.0;
	EMChannelN[4] = (RawDataEM[0][4][4] > 10 && RawDataEM[0][4][5] > 10) ? (RawDataEM[0][4][4] + RawDataEM[0][4][5]) : 0.0;

	EM_P_BEAM->Fill(EMX[0], EMChannelP[0]);
	EM_P_BEAM->Fill(EMX[1], EMChannelP[1]);
	EM_P_BEAM->Fill(EMX[2], EMChannelP[2]);
	EM_P_BEAM->Fill(EMX[3], EMChannelP[3]);
	EM_P_BEAM->Fill(EMX[4], EMChannelP[4]);
	
	EM_N_BEAM->Fill(EMX[0], EMChannelN[0]);
	EM_N_BEAM->Fill(EMX[1], EMChannelN[1]);
	EM_N_BEAM->Fill(EMX[2], EMChannelN[2]);
	EM_N_BEAM->Fill(EMX[3], EMChannelN[3]);
	EM_N_BEAM->Fill(EMX[4], EMChannelN[4]);

	
	for (int channel = 0; channel < NRPD; channel++){
		//remeber TS start at 0 DONT SUBTRACT
		fC_of_TS45_Summed  = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5];
		fC_of_TS456_Summed = RawDataRPD[0][channel][4] + RawDataRPD[0][channel][5] + RawDataRPD[0][channel][6];

		if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[0][channel][7] <= RawDataRPD[0][channel][5]) && (RawDataRPD[0][channel][1] / RawDataRPD[0][channel][0] < 1000) && (RawDataRPD[0][channel][0] != 0)) {
	

				if (channel == 10 || channel == 9  || channel == 8  || channel == 11) { RPD_COL_N[3] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			//R2             
				if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_N[2] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			//R3							
				if (channel == 3  || channel == 0  || channel == 1  || channel == 2)  { RPD_COL_N[1] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			  //C3 C2 C1 C0					
				if (channel == 7  || channel == 4  || channel == 5  || channel == 6)  { RPD_COL_N[0] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}
		}
	}

	for (int channel = 0; channel < NRPD; channel++){
		//remeber TS start at 0 DONT SUBTRACT
		fC_of_TS45_Summed  = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5];
		fC_of_TS456_Summed = RawDataRPD[1][channel][4] + RawDataRPD[1][channel][5] + RawDataRPD[1][channel][6];

		if ((fC_of_TS456_Summed > 40) && (fC_of_TS45_Summed / fC_of_TS456_Summed > .8) && (RawDataRPD[1][channel][7] <= RawDataRPD[1][channel][5]) && (RawDataRPD[1][channel][1] / RawDataRPD[1][channel][0] < 1000) && (RawDataRPD[1][channel][0] != 0)) {
	

				if (channel == 10 || channel == 9  || channel == 8  || channel == 11) { RPD_COL_P[0] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			//R2             
				if (channel == 14 || channel == 13 || channel == 12 || channel == 15) { RPD_COL_P[1] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			//R3							
				if (channel == 3  || channel == 0  || channel == 1  || channel == 2)  { RPD_COL_P[2] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}			  //C3 C2 C1 C0					
				if (channel == 7  || channel == 4  || channel == 5  || channel == 6)  { RPD_COL_P[3] += fC_of_TS456_Summed /** OutPut_Weightedjeffsweights[channel]*/;}
		}
	}

	RPDX_P_BEAM->Fill(RPDX[0],RPD_COL_P[0]);
	RPDX_P_BEAM->Fill(RPDX[1],RPD_COL_P[1]);
	RPDX_P_BEAM->Fill(RPDX[2],RPD_COL_P[2]);
	RPDX_P_BEAM->Fill(RPDX[3],RPD_COL_P[3]);

	RPDX_N_BEAM->Fill(RPDX[0],RPD_COL_N[0]);
	RPDX_N_BEAM->Fill(RPDX[1],RPD_COL_N[1]);
	RPDX_N_BEAM->Fill(RPDX[2],RPD_COL_N[2]);
	RPDX_N_BEAM->Fill(RPDX[3],RPD_COL_N[3]);

	}

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
	c1->SaveAs(Form("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/EM_vs_RPD/ZDC_figures/EM_and_RPD_dEdX_fc_per_channel_dist_326776/%s_fC_dEdx_EM_%d_10fC.png", stit2[1], runnumber));

	EM_N_BEAM->Draw("hist e");
	/* TPaveLabel* title2 = new TPaveLabel(0.1, 0.94, 0.9, 0.98, Form("%s_RPD_%d", stit2[0], runnumber));
	title2->SetFillColor(16);
	title2->SetTextSize(2);
	title2->Draw(); */
	c1->SaveAs(Form("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/EM_vs_RPD/ZDC_figures/EM_and_RPD_dEdX_fc_per_channel_dist_326776/%s_fC_dEdx_EM_%d_10fC.png", stit2[0], runnumber));

	RPDX_P_BEAM->Draw("hist e");
	c1->SaveAs(Form("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/EM_vs_RPD/ZDC_figures/EM_and_RPD_dEdX_fc_per_channel_dist_326776/%s_fC_dEdx_RPD_%d.png", stit2[1], runnumber));

	RPDX_N_BEAM->Draw("hist e");
	c1->SaveAs(Form("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/EM_vs_RPD/ZDC_figures/EM_and_RPD_dEdX_fc_per_channel_dist_326776/%s_fC_dEdx_RPD_%d.png", stit2[0], runnumber));
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