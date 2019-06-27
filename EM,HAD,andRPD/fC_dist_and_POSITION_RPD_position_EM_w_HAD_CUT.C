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

#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/EM_Beam_Position_returns_Value_function.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/X_Y_P_N_RPD_Beam_Position_Calculator.h"
#include "/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/Fiber_Ridge_Subtractor.h"
//#include "EM_Beam_Position_Cut_and_Value_Header.h" //custom header written by Eric A to measure beam position

using namespace std;

// I am a chemist not an englishist I cant spell

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!TS456 are not channels BUT TIME SLICES SO THIS IS TIME SLICES 4, 5, & 6 fC SUMMED !!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//!!!!!!!!!!!!!!!!!!!! turned off weighting 


//function headers
void initRootStyle();

//main function macro
void fC_dist_and_POSITION_RPD_position_EM_w_HAD_CUT(int runnumber=326776){
	initRootStyle();
	
	cout << "Running SOFTWARE: fC_dist_and_POSITION_RPD_position_EM_w_HAD_CUT.C  Edited: 6/25/2019 4:14:21 PM" << endl;
	
	
	
	//TFile* f = new TFile("/home/ebadams/Merged_Root_Files_PbPb2018/MB_2/326776/PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root"); cout << "Dataset=" << " PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root" << endl;

	TFile *f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); cout << "Dataset=" << " AOD_zdc_digi_tree_326776_many_3" << endl; // opening the root file
	
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
	
	TH1F* fC_RPD[2][16];
	TH1F* fC_RPD_Pure[2][16];
	TH1F* fC_RPD_Array_Plot[2][16];
	TH1F* fC_RPD_Pure_Array_Plot[2][16];
	TH1D* EM_B_Position[2];
	TH2D* Pos_RPDvRPD;
	TH2D* Neg_RPDvRPD;
	TH2D* Pos_RPDvEM;
	TH2D* Neg_RPDvEM;
	TH2D* X_RPDvRPD;
	TH2D* Y_RPDvRPD;

	THStack* hsRPD[2][16];
	THStack* hsRPD_Array_Plot[2][16];
	
	for( int s = 0; s < 2; s++){ 
	//s stands for side
		EM_B_Position[s] = new TH1D(Form("EM%s Beam Position %d", stit[s], runnumber),Form("EM_B_Position %s %d; cm; counts",stit[s], runnumber), 200,-4.5, 4.5 );
		for( int c = 0; c < 16; c++){
		//c stands for channel
			fC_RPD[s][c]      = new TH1F(Form("fC RPD%s channel %d %d", stit[s], c+1, runnumber),Form("326776Weighted_RPD%s channel %d %d;TS [25 ns];Q [fC]",stit[s],c+1, runnumber),NumberOfBins,0/* MinXTH1F */,300000 /* ArrayMaxXTH1F[s][c] */); /// lower bound is set higher than upper bound bc when rene burn designed this thing HE MADE THAT THE ONLY GOD DAMN WAY FOR IT TO AUTOFIT THE AXES .....
			fC_RPD_Pure[s][c] = new TH1F(Form("fC RPD%s Pure channel %d %d", stit[s], c+1, runnumber),Form("RPD%s Pure channel %d %d;TS [25 ns];Q [fC]",stit[s],c+1, runnumber),NumberOfBins,0,300000);
		}
	}
	
	Pos_RPDvRPD = new TH2D(Form("Pos_RPDvRPD %d", runnumber), Form("Pos_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, 1000), 1000, -4, 4, 1000, -4, 4);
	Neg_RPDvRPD = new TH2D(Form("Neg_RPDvRPD %d", runnumber), Form("Neg_RPDvRPD_%d_NBins_%d_MB_2; RPDX cm; RPDY cm", runnumber, 1000), 1000, -4, 4, 1000, -4, 4);

	Pos_RPDvEM = new TH2D(Form("Pos_RPDvEM %d", runnumber), Form("Pos_RPDvEM_%d_NBins_%d_MB_2; RPDX cm; EMY cm", runnumber, 1000), 1000, -4, 4, 1000, -4.5, 4.5);
	Neg_RPDvEM = new TH2D(Form("Neg_RPDvEM %d", runnumber), Form("Neg_RPDvEM_%d_NBins_%d_MB_2; RPDX cm; EMY cm", runnumber, 1000), 1000, -4, 4, 1000, -4.5, 4.5);

	X_RPDvRPD = new TH2D(Form("X_RPDvRPD %d", runnumber), Form("X_RPDvRPD_%d_NBins_%d_MB_2; RPDX POS cm; RPDX NEG cm", runnumber, 1000), 1000, -4, 4, 1000, -4, 4);
	Y_RPDvRPD = new TH2D(Form("Y_RPDvRPD %d", runnumber), Form("Y_RPDvRPD_%d_NBins_%d_MB_2; RPDY POS cm; RPDY NEG cm", runnumber, 1000), 1000, -4, 4, 1000, -4, 4);



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
	

	double  RawDataEM[NSIDE][NEM][NTS] = {{{0}, {0}, {0}, {0}, {0}},   //neg
								      	  {{0}, {0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataHAD[NSIDE][NHAD][NTS] = {{{0}, {0}, {0}, {0}},   //neg
	                                       {{0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

	double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
										    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos
	
	double Ridge_Subtracted_RPD_Data[2][16] = {0};

	double HAD_TS_BLOB_Ratios[2][4] = {0};

	int HADvaluePos = 0;
	int HADvalueNeg = 0;
	
	int PassedHADCheckPos = 0;
	int PassedHADCheckNeg = 0;

	double RPDXP = 0;
	double RPDYP = 0;
	double RPDXN = 0;
	double RPDYN = 0;

	int EM = 0;
	int HAD = 1;
	int RPD = 3;

	double cutEMPos = 0;
	double cutEMNeg = 0;


	double NumNeg = 0;
	/// END Declaring TLeaf... /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/// Begin filling variables with DATA/fC LOOP https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg /////////////////////////////////////////////
	
	for ( int i = 0;  i < ZDCDigiTree->GetEntries(); i++ ){
		ZDCDigiTree->GetEntry(i);
		
		
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

		double testvalue = 0;

	/*	
		Fiber_Ridge_Subtractor_Outputs_Array( RawDataRPD, testvalue, 0.05, Ridge_Subtracted_RPD_Data);

		//cout << "testvalue" << testvalue << endl;

		for (int s = 0; s < 2; s++){
			for (int c = 0; c < 16; c++){
				//cout << "side " << s << " channel " << c << " Data: " << Ridge_Subtracted_RPD_Data[s][c] << endl;
				if (Ridge_Subtracted_RPD_Data[s][c] < 0 && Ridge_Subtracted_RPD_Data[s][c] != -10){
					NumNeg += 1;
					break;
				}
			}
		}
*/



		for ( int s = 0; s < 2; s++){
			for (int c = 0; c < 4; c++){
			HAD_TS_BLOB_Ratios[s][c] = (RawDataHAD[s][c][4]/RawDataHAD[s][c][5]);
			}
		}

		int HADvalue = 0;

		if (false){ //logic dictates the EM position function tells us beam position and then a cut is applied	
			for (int s = 0; s < 2; s++){
				if (s == 0) {
					HADvalue = 4;
				}
				else{
					HADvalue = 7;
				}
				if (HAD_TS_BLOB_Ratios[s][0] > HADvalue && HAD_TS_BLOB_Ratios[s][1] > HADvalue && HAD_TS_BLOB_Ratios[s][2] > HADvalue && HAD_TS_BLOB_Ratios[s][3] > HADvalue){
					for (int c = 0; c < 16; c++){
						double fC_of_TS456_Summed = RawDataRPD[s][c][4] + RawDataRPD[s][c][5] + RawDataRPD[s][c][6];
						double fC_of_TS45_Summed  = RawDataRPD[s][c][4] + RawDataRPD[s][c][5];
		
						if ( (RawDataRPD[s][c][4] > RawDataRPD[s][c][6]) && (RawDataRPD[s][c][4] > RawDataRPD[s][c][7])){
							NumberofProcessedRPDEvents++;	
							///for math calcualting values use histograms as u KNOW EXACTLY WHAT the weights are coming from!!
							fC_RPD[s][c]->Fill(fC_of_TS456_Summed); 
							fC_RPD_Pure[s][c]->Fill(fC_of_TS456_Summed); 
				
						}
					}
				}
			}	
		}
	
		PassedHADCheckPos = 0;
		PassedHADCheckNeg = 0;
		
		HADvaluePos = 7;
		HADvalueNeg = 4;

		double POS_EM_BEAM_POSITION = EM_Beam_Position_Value( RawDataEM, "Pos");
		double NEG_EM_BEAM_POSITION = EM_Beam_Position_Value( RawDataEM, "Neg");
		//cout << "EMPos" << POS_EM_BEAM_POSITION << endl;
		
		if (true){
			if (RawDataEM[1][2][4]/RawDataEM[1][2][5] > 8){
				EM_B_Position[1]->Fill(POS_EM_BEAM_POSITION);
				cutEMPos = POS_EM_BEAM_POSITION; // making so em vs rpd plot retains cuts from other plots
			}
			if (RawDataEM[0][2][4]/RawDataEM[0][2][5] > 3){
				EM_B_Position[0]->Fill(NEG_EM_BEAM_POSITION);
				cutEMNeg = NEG_EM_BEAM_POSITION;
			}
		}

		double InputJeffWeighter[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

		if (HAD_TS_BLOB_Ratios[1][0] > HADvaluePos && HAD_TS_BLOB_Ratios[1][1] > HADvaluePos && HAD_TS_BLOB_Ratios[1][2] > HADvaluePos && HAD_TS_BLOB_Ratios[1][3] > HADvaluePos &&
		 HAD_TS_BLOB_Ratios[0][0] > HADvalueNeg && HAD_TS_BLOB_Ratios[0][1] > HADvalueNeg && HAD_TS_BLOB_Ratios[0][2] > HADvalueNeg && HAD_TS_BLOB_Ratios[0][3] > HADvalueNeg){
			Returns_X_Y_P_N_RPD_Beam_Position(RawDataRPD,  "Off", InputJeffWeighter, RPDXP, RPDYP, RPDXN, RPDYN);
		
		
			cout << "RDPXP" << RPDXP << endl;
			cout << "RDPYP" << RPDYP << endl;
			cout << "RDPXN" << RPDXN << endl;
			cout << "RDPYN" << RPDYN << endl;
			if (RPDXP != -10 && RPDYP != -10 && RPDXP != -10 && RPDYP != -10){
				Pos_RPDvRPD->Fill(RPDXP, RPDYP);
				Neg_RPDvRPD->Fill(RPDXN,RPDYN);
				PassedHADCheckPos = 1; //ensuring cuts were satisfied for rpd cuts neg v pos
				PassedHADCheckNeg = 1;
			}
		}

		if (PassedHADCheckNeg == 1 && PassedHADCheckPos == 1){
			X_RPDvRPD->Fill(RPDXP, RPDXN);
			Y_RPDvRPD->Fill(RPDYP, RPDYN);
			if (cutEMPos != 0 && cutEMNeg != 0){ //ensuring all cuts are applied
				Pos_RPDvEM->Fill(RPDXP, cutEMPos);
				Neg_RPDvEM->Fill(RPDXN, cutEMNeg);
			}
		}

		if(i % 100000 == 0) cout << i << " events are processed." << endl;
	}
	/// END filling variables with DATA/fC LOOP///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//cout << NumberofProcessedRPDEvents << " of Qualified RPD Events were Processed" << endl;
	cout << "NumNeg" << NumNeg << endl;
	
	///////////////////////////////////////
    // Formatting and drawing histograms //
    ///////////////////////////////////////
	
	TFile f2("ROOT_fc_dist_RPD.root","RECREATE");

	////////////////////////////////////////////////////////////////////////////////////////////////
	//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
	////////////////////////////////////////////////////////////////////////////////////////////////
	TCanvas *c4 = new TCanvas("c4", "RUN 326776", 2000, 1500);
	//gPad-> SetLogy();
	if (true){
		EM_B_Position[1]->Draw("HIST E");
		c4->SaveAs(Form("ZDC_figures/EM_position_beam/EM_BEAM_%s__%d.png", stit2[1], runnumber));
		EM_B_Position[0]->Draw("HIST E");
		c4->SaveAs(Form("ZDC_figures/EM_position_beam/EM_BEAM_%s__%d.png", stit2[0], runnumber));

		Pos_RPDvEM->Draw("COLZ");
		c4->SaveAs(Form("ZDC_figures/RPDvEM_position_beam/RPDvEM_BEAM_%s__%d.png", stit2[1], runnumber));
		Neg_RPDvEM->Draw("COLZ");
		c4->SaveAs(Form("ZDC_figures/RPDvEM_position_beam/RPDvEM_BEAM_%s__%d.png", stit2[0], runnumber));


		Pos_RPDvRPD->Draw("colz");
		c4->SaveAs(Form("ZDC_figures/RPD_position_beam/RPD_BEAM_%s__%d.png", stit2[1], runnumber));
		Neg_RPDvRPD->Draw("colz");
		c4->SaveAs(Form("ZDC_figures/RPD_position_beam/RPD_BEAM_%s__%d.png", stit2[0], runnumber));

		X_RPDvRPD->Draw("colz");
		c4->SaveAs(Form("ZDC_figures/RPD_position_beam/RPD_XvX_%d.png", runnumber));
		Y_RPDvRPD->Draw("colz");
		c4->SaveAs(Form("ZDC_figures/RPD_position_beam/RPD_YvY_%d.png", runnumber));
	}

	int A = 4;
	int B = 2;
	//int Value =0; was used for debugging correct quartz block order
	//cout << "here2" << endl;
	if (false)	{
		for(int i =0; i < 2; i++){ 
			for(int j=0 ; j < 16; j++){
				c4->cd(); /// this resets and clears the canvas idky blame rene burn...
				gPad->SetLogy();
	
				fC_RPD[i][j/*-1*/]->SetLineColor(B);
				fC_RPD[i][j]->Draw("hist e"); //->Draw("same");
	
				
				
	
				 
				 c4->SaveAs(Form("ZDC_figures/fC_Dist_SOLO/Solo_RPD_%d_Weighted_10_0_%s_fCvCounts_%d.png", j+1, stit2[i], runnumber)); // potential bug area
			} 
			
			 for(int j=0 ; j < 16; j++){
				
				c4->cd(); /// this resets and clears the canvas idky blame rene burn...
				gPad->SetLogy();
				
				hsRPD[i][j] = new THStack("hsRPD","");
				fC_RPD[i][j/*-1*/]->SetLineColor(B);
				
				hsRPD[i][j]->Add(fC_RPD[i][j/*-1*/]);
				fC_RPD_Pure[i][j/*-1*/]->SetLineColor(A);
			
				hsRPD[i][j]->Add(fC_RPD_Pure[i][j/*-1*/]);
			
				hsRPD[i][j]->Draw("hist c"); 
				
				TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
				newpad->SetFillStyle(4000);
				newpad->Draw();
				newpad->cd();
				//TPaveLabel *title = new TPaveLabel(0.1,0.94,0.9,0.98, Form("%s_%d_RPD_Channel_%d_Xmax_%d", stit2[i], runnumber, j+1, MaxXTH1F));
			
				 c4->SaveAs(Form("ZDC_figures/fC_DIST_COMPARE/RPD_%d_Weighted_10_0_%s_fCvCounts_%d.png", j+1, stit2[i], runnumber)); // potential bug area
			}  
			
			//c4->SaveAs(Form("ZDC_figures/Data_Weights326776/RPD_Data_Weights_326776_10_0_%s_ALLQB_%d.png",stit2[i], runnumber));// this is the culprit and caused the loop to keep going
			
		}//
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

