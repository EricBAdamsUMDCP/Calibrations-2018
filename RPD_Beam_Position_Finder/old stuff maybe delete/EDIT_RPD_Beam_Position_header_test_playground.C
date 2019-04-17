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
//#include "EM_Beam_Position_Cut_and_Value_Header.h" //custom header written by Eric A to measure beam position
#include "RPD_Beam_Position_Finder.h" //custom header written by Eric A to measure RPD beam postion in X and Y
using namespace std;

// I am a chemist not an englishist I cant spell

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!TS456 are not channels BUT TIME SLICES SO THIS IS TIME SLICES 4, 5, & 6 fC SUMMED !!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//function headers
void initRootStyle();
///home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/RPD_Beam_Position_Finder/*AOD_zdc_digi_tree_326776_many_3*/AOD_zdc_digi_tree_327126_many
//main function macro
void EDIT_RPD_Beam_Position_header_test_playground(int runnumber = 326776 ){
	initRootStyle();
	string Dataset = "AOD_zdc_digi_tree_326776_many_3";
	cout << "Running SOFTWARE: RPD_Beam_Position_header_test_playground.C 4/12/19 5:15" << endl;
	cout << "Dataset = " << Dataset << ".root"<< endl;


	TFile* f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
	TTree* ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree


	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		  //int NumberofProcessedRPDEvents = 0;
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

	double RPDXmin = -3;
	double RPDXmax = 3;
	double RPDYMin = -3;
	double RPDYMax = 3;
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
	
	
	double PXC;
	double PYC;
	double NXC;
	double NYC;
	          
	double PXG;
	double PYG;
	double NXG;
	double NYG;
	          
	
	for (int i = 0; i < ZDCDigiTree->GetEntries(); i++) {
		ZDCDigiTree->GetEntry(i);


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
			
			double Pos_EM_Beam_Position = 0;
			double Neg_EM_Beam_Position = 0;
			
			//RPD_Beam_Position_Finder(double TS_Zero, double TS_One, double TS_Four, double TS_Five, double TS_Six, double TS_Seven, int n, int side, int type, int channel, double RPDXmin, double RPDXmax, double RPDYMin, double RPDYMax, const std::string& PosorNeg, const std::string& XorY, const std::string& CheckorGive);
			PXC = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "X", "Check");
			PYC = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "Y", "Check");
			NXC = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "X", "Check");
			NYC = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "Y", "Check");
			                                                                                                                                                        
			PXG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "X", "Give");
			PYG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Pos", "Y", "Give");
			NXG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "X", "Give");
			NYG = RPD_Beam_Position_Finder( TS_Zero, TS_One, TS_Four, TS_Five, TS_Six, TS_Seven, n, side, type, channel, RPDXmin, RPDXmax, RPDYMin, RPDYMax, "Neg", "Y", "Give");
			
			
			cout << "NXC " << NXC << endl;
			cout << "NYC " << NYC << endl;
			cout << "NXG " << NXG << endl;
			cout << "NYG " << NYG << endl;
			
			if ( n == 49){
				if(PXC == 1){
					RPD_P_BEAM_X1D->Fill(PXG);
					if(PYC == 1){
						RPD_P_BEAM->Fill( PXG, PYG);
					}
				}
			}
			if ( n == 33){
				if(NXC ==1){
					RPD_N_BEAM_X1D->Fill(NXG);
					if(NYC == 1){
						RPD_N_BEAM->Fill( NXG, NYG);	
					}
				}
			}		
		}
		
		/* if(PXC == 1){
				RPD_P_BEAM_X1D->Fill(PXG);
				if(PYC == 1){
					RPD_P_BEAM->Fill( PXG, PYG);
				}
			}
			
		if(NXC ==1){
			RPD_N_BEAM_X1D->Fill(NXG);
			if(NYC == 1){
				RPD_N_BEAM->Fill( NXG, NYG);	
			} */
		//}
	
		if (i % 100000 == 0) cout << i << " events are processed." << endl;
	}

	
		


	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//std::cout << NumberofProcessedRPDEvents << " of Qualified RPD Events were Processed" << endl;


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