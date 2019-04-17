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
using namespace std;

// I am a chemist not an englishist I cant spell

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!TS456 are not channels BUT TIME SLICES SO THIS IS TIME SLICES 4, 5, & 6 fC SUMMED !!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//function headers
void initRootStyle();

//main function macro
void ThreeTwoSixSevenSevenSixWeights_Fixed_RPDWEIGHTGEANT_AND_REALWEIGHTS_counts_v_fC_QBLoop(int runnumber=326776)
{
	initRootStyle();
	
	cout << "Running SOFTWARE: Fixed_RPDWEIGHTSGEANT_&_REALWEIGHTS_count_v_fC_QBLoop.C 4/8/19 5:49" << endl;
	cout << "Dataset=" << " AOD_zdc_digi_tree_326776_many_3" << endl;
	
	
	TFile *f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
	TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
	
	
	/// Begin Variable and constant decleration//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		  int NumberofProcessedRPDEvents = 0;
	const double MinXTH1F = 0.0;
	const int MaxXTH1F = 70000000 /*removed 0 zeros*/;
	const int NumberOfBins = 10001; //number of bins in TH1F histograms produced by this code
	const int NChannels = 50;
	const int NTS=10;// number of timeslices
	const int NRPD=16; 
	const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
	const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
	const int NCH=5; const char* ctit[NTYPE][NCH] = {
	                                                    {"1","2","3","4","5"}, //HD sections run only 1-4
	                                                    {"1","2","3","4","5"} //EM sections run 1-5
	                                                };
	
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

	double RPD_Pos_TS456[NRPD] = {0}; //initializing all values to 0
	double RPD_Neg_TS456[NRPD] = {0}; //initializing all values to 0
	
	double RPD_Pos_TS456_ChannelSum = 0;
	double RPD_Neg_TS456_ChannelSum = 0;
	
	/// END Variable and constant declaration ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Begin Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////
	//DECLARING HISTOGRAMS FOR fC VERSUS TS//
	///////////////////////////////////////// 
	
	TH1F* fC_RPD[2][16];
	TH1F* fC_RPD_Pure[2][16];
	
	THStack* hsRPD[2][16];
	
	for( int s = 0; s < 2; s++){ 
	//s stands for side
		for( int c = 0; c < 16; c++){
		//c stands for channel
			fC_RPD[s][c]      = new TH1F(Form("fC RPD%s channel %d %d", stit[s], c+1, runnumber),Form("RPD%s channel %d %d;TS [25 ns];Q [fC]",stit[s],c+1, runnumber),NumberOfBins,MinXTH1F,MaxXTH1F);
			fC_RPD_Pure[s][c] = new TH1F(Form("fC RPD%s Pure channel %d %d", stit[s], c+1, runnumber),Form("RPD%s Pure channel %d %d;TS [25 ns];Q [fC]",stit[s],c+1, runnumber),NumberOfBins,MinXTH1F,MaxXTH1F);
	
		}
	}
	
	//DECLARING NEW THStack FOR PLOTTING MANY HISTOS ON SAME PAD//
	THStack *hs = new THStack("StackRPD","test");
	
	/// END Histogram Declaration ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/// Begin Declaring TLeaf for giving root/c++ the ability to call parts of the root tree/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	TLeaf* fCleaf[NTS];
	TLeaf* fCPureleaf[NTS];
	
	// For c++ root tree interface ////////////////////////
	TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
	TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
	TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
	TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
	TLeaf* random = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
	TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
	TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
	TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");

	
	for( int iTS = 0; iTS < NTS; iTS++) {
		fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
		fCPureleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
	}
	
	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/// Begin filling variables with DATA/fC LOOP https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////
	
	for( int i = 0;  i < ZDCDigiTree->GetEntries(); i++){
		ZDCDigiTree->GetEntry(i);
		
		for( int n = 0; n < NChannels; n++){ //iterates through all channels of both ZDC + and -
			int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
			int type = (int)(sectionLeaf->GetValue(n))-1;
			int channel = (int)(channelLeaf->GetValue(n))-1;
			
			//cout << "n  " << n << " side  " << side << " channel  " << channel << endl;
			
			/// Begin filling timeslices with fC (discrimination is by channel number iteration)
			
			//ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
			//this is used below to keep values at 0 or greater
			double TS_Zero  = (fCleaf[0]->GetValue(n) < 0) ? 0 : (fCleaf[0]->GetValue(n));
			double TS_One   = (fCleaf[1]->GetValue(n) < 0) ? 0 : (fCleaf[1]->GetValue(n));
			double TS_Two   = (fCleaf[2]->GetValue(n) < 0) ? 0 : (fCleaf[2]->GetValue(n));
			double TS_Three = (fCleaf[3]->GetValue(n) < 0) ? 0 : (fCleaf[3]->GetValue(n));
			double TS_Four  = (fCleaf[4]->GetValue(n) < 0) ? 0 : (fCleaf[4]->GetValue(n)); 
			double TS_Five  = (fCleaf[5]->GetValue(n) < 0) ? 0 : (fCleaf[5]->GetValue(n));
			double TS_Six   = (fCleaf[6]->GetValue(n) < 0) ? 0 : (fCleaf[6]->GetValue(n));
			double TS_Seven = (fCleaf[7]->GetValue(n) < 0) ? 0 : (fCleaf[7]->GetValue(n));
			double TS_Eight = (fCleaf[8]->GetValue(n) < 0) ? 0 : (fCleaf[8]->GetValue(n));
			double TS_Nine  = (fCleaf[9]->GetValue(n) < 0) ? 0 : (fCleaf[9]->GetValue(n));
			
			/// END filling timeslices with fC (discrimination is by channel number iteration)
			
			// Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)
			double fC_of_TS45_Summed  = TS_Four + TS_Five;
			double fC_of_TS456_Summed = TS_Four + TS_Five + TS_Six;
			
			if ((fC_of_TS456_Summed > 50) && (fC_of_TS45_Summed/fC_of_TS456_Summed > .8) && (TS_Seven <= TS_Five) && (TS_One/TS_Zero < 1000) && (TS_Zero != 0)){
				NumberofProcessedRPDEvents++;
				if (type == 3){
					/* if (side == 1){
						RPD_Pos_TS456[channel] = fC_of_TS456_Summed;
					}
					else {
						RPD_Neg_TS456[channel] = fC_of_TS456_Summed;
					} */
					//equivalent to line below
					/* (side == 1 ? RPD_Pos_TS456 : RPD_Neg_TS456)[channel] = fC_of_TS456_Summed; */
					
					fC_RPD[side][channel]->Fill((fC_of_TS456_Summed * DATAWeightsFromRun_326776[side][channel] * 100 /* 100 is to make sure all weights are not fractions that reduce while others increase #*/)/*Jeffsweights[side][channel]*/); 
					fC_RPD_Pure[side][channel]->Fill(fC_of_TS456_Summed * 100); /// DELETE THE 100!!!!!!!!!!!!!!!!
					
					/* if (18 <= n && n < 34) {  //RPDNEGchannel#s// fill RPD_Neg_TS456_ChannelSum with the fC values from all of the RPD channels for ratio calculations
						RPD_Neg_TS456_ChannelSum += RPD_Neg_TS456[channel];
					}
					else if (34 <= n && n < 50) {  //RPDPoschannel#s// fill RPD_Pos_TS456_ChannelSum with the fC values from all of the RPD channels for ratio calculations
						RPD_Pos_TS456_ChannelSum += RPD_Pos_TS456[channel];
					} */
				}
			}
		}
	
		if(i % 100000 == 0) cout << i << " events are processed." << endl;
	}
	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << NumberofProcessedRPDEvents << " of Qualified RPD Events were Processed" << endl;
	
	
	/// Begin filling sums with data put into histograms (reasoning behind this is I know what I'm putting in my calculations as I can see it, was getting weird bugs before)
	for ( int NBin = 0; NBin < NumberOfBins; NBin++) { //pos
		RPD_Pos_TS456_ChannelSum += ( fC_RPD_Pure[1][0]->GetBinContent(NBin) + fC_RPD_Pure[1][1]->GetBinContent(NBin) + fC_RPD_Pure[1][2]->GetBinContent(NBin) + fC_RPD_Pure[1][3]->GetBinContent(NBin)
									+ fC_RPD_Pure[1][4]->GetBinContent(NBin) + fC_RPD_Pure[1][5]->GetBinContent(NBin) + fC_RPD_Pure[1][6]->GetBinContent(NBin) + fC_RPD_Pure[1][7]->GetBinContent(NBin)
									+ fC_RPD_Pure[1][8]->GetBinContent(NBin) + fC_RPD_Pure[1][9]->GetBinContent(NBin) + fC_RPD_Pure[1][10]->GetBinContent(NBin) + fC_RPD_Pure[1][11]->GetBinContent(NBin)
									+ fC_RPD_Pure[1][12]->GetBinContent(NBin) + fC_RPD_Pure[1][13]->GetBinContent(NBin) + fC_RPD_Pure[1][14]->GetBinContent(NBin) + fC_RPD_Pure[1][15]->GetBinContent(NBin));
	}
	
	for ( int NBin = 0; NBin < NumberOfBins; NBin++) { //neg
		RPD_Neg_TS456_ChannelSum += ( fC_RPD_Pure[0][0]->GetBinContent(NBin) + fC_RPD_Pure[0][1]->GetBinContent(NBin) + fC_RPD_Pure[0][2]->GetBinContent(NBin) + fC_RPD_Pure[0][3]->GetBinContent(NBin)
									+ fC_RPD_Pure[0][4]->GetBinContent(NBin) + fC_RPD_Pure[0][5]->GetBinContent(NBin) + fC_RPD_Pure[0][6]->GetBinContent(NBin) + fC_RPD_Pure[0][7]->GetBinContent(NBin)
									+ fC_RPD_Pure[0][8]->GetBinContent(NBin) + fC_RPD_Pure[0][9]->GetBinContent(NBin) + fC_RPD_Pure[0][10]->GetBinContent(NBin) + fC_RPD_Pure[0][11]->GetBinContent(NBin)
									+ fC_RPD_Pure[0][12]->GetBinContent(NBin) + fC_RPD_Pure[0][13]->GetBinContent(NBin) + fC_RPD_Pure[0][14]->GetBinContent(NBin) + fC_RPD_Pure[0][15]->GetBinContent(NBin));
	}
	
	for ( int c = 0; c < 16; c++){
		for ( int NBin = 0; NBin < NumberOfBins; NBin++) { //pos
		RPD_Pos_TS456[c] += fC_RPD_Pure[1][c]->GetBinContent(NBin); /// check to make sure QB order is working intended way
		}
	}
	
	for ( int c = 0; c < 16; c++){
		for ( int NBin = 0; NBin < NumberOfBins; NBin++) { //neg
		RPD_Neg_TS456[c] += fC_RPD_Pure[0][c]->GetBinContent(NBin); /// check to make sure QB order is working intended way
		}
	}
	/// END filling sums with data put into histograms...
	
	/* for ( int i = 0; i < NRPD; i++){ // fill RPD_???_TS456_ChannelSum with the fC values from all of the RPD channels for ratio calculations
		RPD_Neg_TS456_ChannelSum += RPD_Neg_TS456[i];
		RPD_Pos_TS456_ChannelSum += RPD_Pos_TS456[i];
	} */
	cout << "RPD_Neg_TS456_ChannelSum=" << RPD_Neg_TS456_ChannelSum << endl;
	cout << "RPD_Pos_TS456_ChannelSum=" << RPD_Pos_TS456_ChannelSum << endl;
	
	//////////////////////////////////////////
    //CREATING NORMALIZATION OF REAL WEIGHTS//
    //////////////////////////////////////////
	
	//MATH: jeffsweight = N * RPDDataWeight ---> R = Jeffs weight/DataWeight // here N represents the number being calculated
	
	cout << "Jeffsweights = N * RPDDataWeight" << endl;
	
	cout << endl;
	
	for ( int c = 0; c < NRPD; c++){ // c stands for channel
	//NEG = 0
		int QuartzBlockOrdering = RPDCorrectBlockOrder[0][c];
		double RPDDataWeight = (RPD_Neg_TS456[QuartzBlockOrdering]/RPD_Neg_TS456_ChannelSum); // was typo here RPDCorrectBlockOrder was not implemented
		double N = (Jeffsweights[0][c]/RPDDataWeight);
		cout << "Neg Channel RPDDataWeight " << QuartzBlockOrdering+1 << ":  " << RPDDataWeight << "  Calculated N: " << N << " Jeffsweight" << Jeffsweights[0][c] << endl; /// check to make sure QB order is working intended way
	}
	
	cout << endl;
	
	for ( int c = 0; c < NRPD; c++){ // c stands for channel
	//Pos = 1
		int QuartzBlockOrdering = RPDCorrectBlockOrder[1][c];
		double RPDDataWeight = (RPD_Pos_TS456[QuartzBlockOrdering]/RPD_Pos_TS456_ChannelSum);  // was typo here RPDCorrectBlockOrder was not implemented
		double N = (Jeffsweights[1][c]/RPDDataWeight);
		cout << "Pos Channel RPDDataWeight " << QuartzBlockOrdering+1 << ":  " << RPDDataWeight << "  Calculated N: " << N << " Jeffsweight" << Jeffsweights[1][c] << endl; /// check to make sure QB order is working intended way
	}
	
	cout << endl;
	
	///////////////////////////////////////
    // Formatting and drawing histograms //
    ///////////////////////////////////////
	
	TFile f2("ROOT_Fixed_RPDWEIGHTGEANT_AND_REALWEIGHTS_counts_v_fC_QBLoop.root","RECREATE");

	////////////////////////////////////////////////////////////////////////////////////////////////
	//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
	////////////////////////////////////////////////////////////////////////////////////////////////
	TCanvas *c4 = new TCanvas("c4", "RUN 326776", 2000, 1500);
	gPad-> SetLogy();
	c4->Divide(4,4,0.0001,0.0001); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
	//subtract 1 from all channel value bc start at 0
	
	auto* lt = new TLatex();
	
	int A = 4;
	int B = 2;
	//int Value =0; was used for debugging correct quartz block order
	
	for(int i =0; i < 2; i++){ 
		for(int j=0 ; j < 16; j++){
			//block order output correct checked 4/8/19 4:42 (as best as I could but 99.99 % sure correct)
			c4->cd(RPDCorrectBlockOrderFORPLOTTING[i][j]); //MAY NEED TO CHANGE TO RIGHT cd !!!
			cout << (RPDCorrectBlockOrderFORPLOTTING[i][j]) << endl;
			gPad->SetLogy();
			hsRPD[i][j] = new THStack("hsRPD","");
			fC_RPD[i][j/*-1*/]->SetLineColor(B);
			/*
			fC_RPD[i][j-1]->SetFillStyle(3001);
			fC_RPD[i][j-1]->SetFillColorAlpha(kRed, 0.35);*/
			hsRPD[i][j]->Add(fC_RPD[i][j/*-1*/]);
			fC_RPD_Pure[i][j/*-1*/]->SetLineColor(A);
			/*
			fC_RPD_Pure[i][j-1]->SetFillStyle(3001);
			fC_RPD_Pure[i][j-1]->SetFillColorAlpha(kBlue, 0.35); */
			hsRPD[i][j]->Add(fC_RPD_Pure[i][j/*-1*/]);
			
			/* gROOT->SetStyle("Plain");   
			gStyle->SetPalette(1); /////// CRITICAL THIS DOES NOTHING OTHER THAN SLOW DOWN THE FILLING OF THE DIVIDED HISTO SO YOU CAN SEE WHAT ORDER IT IS FILLING IN, IT IS FILLING IN CORRECTLY AS STATED BY THE ARRAY
			gStyle->SetOptStat(1);
			gStyle->SetOptTitle(1);
			gStyle->SetOptFit(0);  */
			
			hsRPD[i][j]->Draw("hist c"); //->Draw("same");
			//lt->DrawLatexNDC(0.5,0.5, Form("Channel_%d", j+1) ); // maay cause bug be wary
			//hs->SetTitle(Form("Channel_%d", j + 1));
			
			TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
			newpad->SetFillStyle(4000);
			newpad->Draw();
			newpad->cd();
			TPaveLabel *title = new TPaveLabel(0.1,0.94,0.9,0.98, Form("%s_%d_RPD_Channel_%d_Xmax_%d", stit2[i], runnumber, j+1, MaxXTH1F));
			title->SetFillColor(16);
			//title->SetTextFont(72);
			title->SetTextSize(2);
			title->Draw();
			/* Value++;
			cout << "Value" << Value << endl; was used for debugging correct quartz block order
			 */
		} 
		
		//c4->cd(12);
		//lt->DrawLatexNDC(0.5,0.5, "Twelve");
		
		/* TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
		newpad->SetFillStyle(4000);
		newpad->Draw();
		newpad->cd();
		TPaveLabel *title = new TPaveLabel(0.1,0.94,0.9,0.98, Form("%s_%d_RPD_histograms", stit2[i], runnumber));
		title->SetFillColor(16);
		title->SetTextFont(52);
		title->Draw(); */
		
		c4->SaveAs(Form("ZDC_figures/Data_Weights326776/RPD_Data_Weights_326776_10_0_%s_ALLQB_%d.png",stit2[i], runnumber));// this is the culprit and caused the loop to keep going
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