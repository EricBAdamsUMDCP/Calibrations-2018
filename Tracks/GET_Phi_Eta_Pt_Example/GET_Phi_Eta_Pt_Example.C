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
//#include "CMS_lumi.h" // custom header make a file path for all software
#include "THStack.h" // ERIC ADDED
#include "TPaveLabel.h" //Eric ADDDED

using namespace std;

// I am a chemist not an englishist I cant spell

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!TS456 are not channels BUT TIME SLICES SO THIS IS TIME SLICES 4, 5, & 6 fC SUMMED !!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//!!!!!!!!!!!!!!!!!!!! turned off weighting 


//function headers
void initRootStyle();

//main function macro
void GET_Phi_Eta_Pt_Example(int runnumber=326776){
	initRootStyle();
	
	cout << "Running SOFTWARE: GET_Phi_Eta_Pt_Example.C  Edited: 7/2/2019 3:46:06 PM" << endl;
	
	
	
	//TFile* f = new TFile("/home/ebadams/Merged_Root_Files_PbPb2018/MB_2/326776/PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root"); cout << "Dataset=" << " PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root" << endl;

	TFile *f = new TFile("/home/ebadams/CMSSW_10_3_3/src/ZDC/analyzeZDCTree/Track_AOD_zdc_digi_tree_326776_kevin2.root"); cout << "Dataset=" << " Track_AOD_zdc_digi_tree_326776_kevin2.root" << endl; // opening the root file
	
	TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
	
	
	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		  int NumberofProcessedRPDEvents = 0;	
	const int NumberOfBins = 500; //number of bins in TH1F histograms produced by this code
		 // double ArrayNumberofBins[16] = { 100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,  100}; /// this is for the plots not for the calcualtions
	const int NChannels = 50;
	const int NTS=10;// number of timeslices
	const int NRPD=16; 
	const int NEM = 5;
	const int NHAD = 4;
	const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
	const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
	const int NCH=5; const char* ctit[NTYPE][NCH] = {
	                                                    {"1","2","3","4","5"}, //HD sections run only 1-4
	                                                    {"1","2","3","4","5"} //EM sections run 1-5
	                                                };
	


	int INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[NRPD] = {13, 12, 15, 14, 9, 11, 8, 10, 5, 4, 7, 6, 1, 0, 3, 2}; //tenative needs to be checked
													 //{14, 13, 16, 15, 10, 12, 9, 11, 6, 5, 8, 7, 2, 1, 4, 3} // old bfopr noticed out of bounmds array issue and subtracted 1 kept for reference
      
	//END constant are for the function	from header file EM_Beam_Position_Cut_and_Value		  
	
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
											


	double RPD_Pos_TS456[NRPD] = {0}; //initializing all values to 0
	double RPD_Neg_TS456[NRPD] = {0}; //initializing all values to 0
	
	double RPD_Pos_TS456_ChannelSum = 0;
	double RPD_Neg_TS456_ChannelSum = 0;
	
	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////
	//DECLARING HISTOGRAMS FOR fC VERSUS TS//
	///////////////////////////////////////// 

	int Check_Eta = false;
	int Check_Pt = false;
	int Check_Phi = true;
	
	TH1D* PtDist;
	TH1D* EtaDist;
	TH1D* PhiDist;

	if (Check_Pt){
		
		PtDist = new TH1D("PtDist", "PtDist",1000,0, 10000);
	}
	if (Check_Eta){
		
		EtaDist = new TH1D("EtaDist", "EtaDist",100,-5, 5);
	}
	if (Check_Phi){
		
		PhiDist = new TH1D("PhiDist", "PhiDist",100,-10, 10);
	}


	/// END Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/// Begin Declaring TLeaf for giving root/c++ the ability to call parts of the root tree/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	TLeaf* fCleaf[NTS];
	TLeaf* fCPureleaf[NTS];
	Double_t nTrack = 0;
	TBranch* b_nTrack;

	std::vector<double>* phi = 0;
	std::vector<double>* eta = 0;
	std::vector<double>* Pt = 0;
	// For c++ root tree interface ////////////////////////
	TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
	TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
	TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
	TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
	TLeaf* random = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
	TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
	//ZDCDigiTree->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
	TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
	TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");
	TLeaf* Phi = (TLeaf*) ZDCDigiTree->GetLeaf("phi");
	ZDCDigiTree->SetBranchAddress("phi", &phi);
	ZDCDigiTree->SetBranchAddress("eta", &eta);
	ZDCDigiTree->SetBranchAddress("Pt", &Pt);


	for( int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
		fCPureleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
	}
	

	double  RawDataEM[NSIDE][NEM][NTS] = {{{0}, {0}, {0}, {0}, {0}},   //neg
								      	  {{0}, {0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataHAD[NSIDE][NHAD][NTS] = {{{0}, {0}, {0}, {0}},   //neg
	                                       {{0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
										    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos

	int EM = 0;
	int HAD = 1;
	int RPD = 3;

	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/// Begin filling variables with DATA/fC LOOP https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////
	
	for ( int i = 0;  i < ZDCDigiTree->GetEntries(); i++ ){
		ZDCDigiTree->GetEntry(i);
		
		double NumberofTracks = ntrk->GetValue();
		//double NumberofTracks = nTrack;
		//cout << "ntrk" << NumberofTracks << endl;
		for (int k = 0; k < NumberofTracks; k++){
			double PhiValues = phi->at(k);
			double EtaValues = eta->at(k);
			double PtValues = Pt->at(k);
			//cout << "phi " << k << ": " << PhiValues << endl;
			//cout << "eta " << k << ": " << EtaValues << endl;
			//cout << " Pt " << k << ": " << PtValues << endl;
			
			if (Check_Pt){
				PtDist->Fill(PtValues);
			}
			if (Check_Eta){
				EtaDist->Fill(EtaValues);
			}
			if (Check_Phi){
				PhiDist->Fill(PhiValues);
			}
			
		}

		for ( int n = 0; n < NChannels; n++ ){ //iterates through all channels of both ZDC + and -
			int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
			int type = (int)(sectionLeaf->GetValue(n))-1;
			int channel = (int)(channelLeaf->GetValue(n))-1;
			
			
			/// Begin filling timeslices with fC (discrimination is by channel number iteration)
			
			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			//this is used below to keep values at 0 or greater
			double TS_Zero  = (fCleaf[0]->GetValue(n) < 0) ? 0.0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) < 0) ? 0.0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) < 0) ? 0.0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) < 0) ? 0.0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) < 0) ? 0.0 : (fCleaf[4]->GetValue(n)); 
			double TS_Five  = (fCleaf[5]->GetValue(n) < 0) ? 0.0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) < 0) ? 0.0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) < 0) ? 0.0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) < 0) ? 0.0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) < 0) ? 0.0 : (fCleaf[9]->GetValue(n));
			
			/// END filling timeslices with fC (discrimination is by channel number iteration)
			
			// Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
			
			
		
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
		} //end channel loop

		//put functions and code here <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


		if(i % 100000 == 0) cout << i << " events are processed." << endl;
	}
	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//cout << NumberofProcessedRPDEvents << " of Qualified RPD Events were Processed" << endl;
	
	
	///////////////////////////////////////
    // Formatting and drawing histograms //
    ///////////////////////////////////////
	
	TFile f2("ROOT_fc_dist_RPD.root","RECREATE");

	////////////////////////////////////////////////////////////////////////////////////////////////
	//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
	////////////////////////////////////////////////////////////////////////////////////////////////
	TCanvas *c4 = new TCanvas("c4", "RUN 326776", 2000, 1500);
	gPad-> SetLogy();
	
	if (Check_Pt){
		PtDist->Draw("HIST E");
	}
	if (Check_Eta){
		EtaDist->Draw("HIST E");
	}
	if (Check_Phi){
		PhiDist->Draw("HIST E");
	}


	
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
  gStyle->SetLabelFont(42,"xyz");
  gStyle->SetTitleFont(42,"xyz");
  gStyle->SetTitleSize(0.05,"xyz");
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

