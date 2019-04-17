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
#include "CMS_lumi.h"
#include "THStack.h" // ERIC ADDED
using namespace std;

void initRootStyle();
void BinLogX(TH1*);

const double MU = 59.92;


void Uncut_v_Cut_HADcut_RPDcut_ALLpulse_QBLoop(int runnumber=326776){
  initRootStyle();
 
  //CUTOFF VALUE FOR GENERATING fC VS TS HISTOS SET BELOW//
  double CutOff = .8;////
  //CUTOFF VALUE FOR GENERATING fC VS TS HISTOS SET ABOVE//
  cout << "Running SOFTWARE: Uncut_v_Cut_HADcut_RPDcut_ALLpulse_QBLoop.C 3/14/19 5:43" << endl;
  cout << "Runnumber=" << runnumber << " many" << endl;
  cout << "CutOff 45 456 = " << CutOff << endl;
  
  writeExtraText = true;       // if extra text
  extraText  = "Preliminary";  // default extra text is "Preliminary"
  lumi_sqrtS = "PbPb 5.02 TeV";       // used with iPeriod = 0, e.g. for simulation-only plots (default is an empty string)
  int iPeriod = 0;

  TCanvas *c1 = new TCanvas();
  TH1::SetDefaultSumw2();

  // Name of directory to plot
  //TFile *f = new TFile(Form("digitree_%d.root",runnumber)); // opening the root file
  TFile *f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
  //TTree *ZDCRecTree = (TTree*)f->Get("ZDCRecTree"); // reading ZDC rec tree
  TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
  const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
  const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
  const int NCH=5; const char* ctit[NTYPE][NCH] = {
                                                    {"1","2","3","4","5"}, //HD sections run only 1-4
                                                    {"1","2","3","4","5"} //EM sections run 1-5
  
                                                };
  const int NRPD=16; 
  float RPDCorrect[NSIDE][NRPD] = {{11.0, 15.0, 2.0, 5.0, 8.0, 12.0, 1.0, 6.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0},
 {11.0, 15.0, 2.0, 6.0, 8.0, 12.0, 1.0, 5.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0}};
 /////////////////////////////////////////
 //DECLARING HISTOGRAMS FOR fC VERSUS TS//
 //////////////////////////////////////// 
   TH1F* fC_ZDC[2][2][5];
   TH1F* fC_RPD[2][16];
   THStack* hsZDC[2][2][5]; ///
   THStack* hsRPD[2][16]; ///

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
		  for(int k = 0; k < 5; k++){
		   
			fC_ZDC[i][j][k] = new TH1F(Form("327560 fC ZDC %s%s ch %d",ttit[j],stit[i],k+1),Form("ZDC %s%s channel %d 327560;TS [25 ns];Q [fC]",ttit[j],stit[i],k+1),10,-0.5,9.5); 
		  }

		for(int j = 0; j < 16; j++){
		  
		  fC_RPD[i][j] = new TH1F(Form("327560 fC RPD%s ch %d",stit[i],j+1),Form("RPD%s channel %d 327560;TS [25 ns];Q [fC]",stit[i],j+1),10,-0.5,9.5);
		}

	  }
	  
	  TH1F* fC_ZDCHT[2][2][5]; //HT stands for HAD Trigger
	  TH1F* fC_RPDHT[2][16];
		
		for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
		  for(int k = 0; k < 5; k++){
		   
			fC_ZDCHT[i][j][k] = new TH1F(Form("327560 fC ZDCHT %s%s ch %d",ttit[j],stit[i],k+1),Form("ZDCHT %s%s channel %d 327560;TS [25 ns];Q [fC]",ttit[j],stit[i],k+1),10,-0.5,9.5); 
		  }

		for(int j = 0; j < 16; j++){
		  
		  fC_RPDHT[i][j] = new TH1F(Form("327560 fC RPDHT%s ch %d",stit[i],j+1),Form("RPDHT%s channel %d;TS [25 ns] 327560;Q [fC]",stit[i],j+1),10,-0.5,9.5);
		}

	  }
	  
	  
	  
	  
	TH1F* fC_ZDC_Pure[2][2][5]; //for UNCUT HISTOGRAMS FOR COMPARISON
    TH1F* fC_RPD_Pure[2][16];

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
		  for(int k = 0; k < 5; k++){
		  
		  fC_ZDC_Pure[i][j][k] = new TH1F(Form("327560 fC ZDC%s%s ch %d Pure",ttit[j],stit[i],k+1),Form("ZDC Pure %s%s channel %d 327560;TS [25 ns];Q [fC]",ttit[j],stit[i],k+1),10,-0.5,9.5); 
		  }

		for(int j = 0; j < 16; j++){
		  
		  fC_RPD_Pure[i][j] = new TH1F(Form("327560 fC RPD%s ch %d Pure",stit[i],j+1),Form("RPD%s Pure channel %d 327560;TS [25 ns];Q [fC]",stit[i],j+1),10,-0.5,9.5);
		}
	}
//END Histos for fC versus TS//

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//45456 are not channels BUT TIME SLICES SO THIS IS TIME LICES 4 & 5 DIVIDED BY TS 4, 5 , &6!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

 ////DELCARING POS HISTOGRAMS/////
	TH1F* RPD45456_CH1_Pos = new TH1F("RPD 45456 CH1 Pos",";CH1 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH2_Pos = new TH1F("RPD 45456 CH2 Pos",";CH2 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH3_Pos = new TH1F("RPD 45456 CH3 Pos",";CH3 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH4_Pos = new TH1F("RPD 45456 CH4 Pos",";CH4 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH5_Pos = new TH1F("RPD 45456 CH5 Pos",";CH5 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH6_Pos = new TH1F("RPD 45456 CH6 Pos",";CH6 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH7_Pos = new TH1F("RPD 45456 CH7 Pos",";CH7 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH8_Pos = new TH1F("RPD 45456 CH8 Pos",";CH8 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH9_Pos = new TH1F("RPD 45456 CH9 Pos",";CH9 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH10_Pos = new TH1F("RPD 45456 CH10 Pos",";CH10 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH11_Pos = new TH1F("RPD 45456 CH11 Pos",";CH11 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH12_Pos = new TH1F("RPD 45456 CH12 Pos",";CH12 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH13_Pos = new TH1F("RPD 45456 CH13 Pos",";CH13 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH14_Pos = new TH1F("RPD 45456 CH14 Pos",";CH14 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH15_Pos = new TH1F("RPD 45456 CH15 Pos",";CH15 45/456 TS Pos;",100,0.0,2.0);
	TH1F* RPD45456_CH16_Pos = new TH1F("RPD 45456 CH16 Pos",";CH16 45/456 TS Pos;",100,0.0,2.0);
	/*HAD*/TH1F* HAD112_CH1_Pos = new TH1F("HAD 112 CH1 Pos","; HAD CH1 1/(1+2) TS Pos;",100,0.0,2.0);
 ////DECLARING NEG HISTOGRAMS////
	TH1F* RPD45456_CH1_Neg = new TH1F("RPD 45456 CH1 Neg",";CH1 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH2_Neg = new TH1F("RPD 45456 CH2 Neg",";CH2 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH3_Neg = new TH1F("RPD 45456 CH3 Neg",";CH3 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH4_Neg = new TH1F("RPD 45456 CH4 Neg",";CH4 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH5_Neg = new TH1F("RPD 45456 CH5 Neg",";CH5 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH6_Neg = new TH1F("RPD 45456 CH6 Neg",";CH6 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH7_Neg = new TH1F("RPD 45456 CH7 Neg",";CH7 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH8_Neg = new TH1F("RPD 45456 CH8 Neg",";CH8 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH9_Neg = new TH1F("RPD 45456 CH9 Neg",";CH9 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH10_Neg = new TH1F("RPD 45456 CH10 Neg",";CH10 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH11_Neg = new TH1F("RPD 45456 CH11 Neg",";CH11 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH12_Neg = new TH1F("RPD 45456 CH12 Neg",";CH12 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH13_Neg = new TH1F("RPD 45456 CH13 Neg",";CH13 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH14_Neg = new TH1F("RPD 45456 CH14 Neg",";CH14 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH15_Neg = new TH1F("RPD 45456 CH15 Neg",";CH15 45/456 TS Neg;",100,0.0,2.0);
	TH1F* RPD45456_CH16_Neg = new TH1F("RPD 45456 CH16 Neg",";CH16 45/456 TS Neg;",100,0.0,2.0);
	/*HAD*/TH1F* HAD112_CH1_Neg = new TH1F("HAD 112 CH1 Neg","; HAD CH1 1/(1+2) TS Neg;",100,0.0,2.0);
 //END declaring histograms 

/////////////////////////////////////////////////////////////////////////////////////////////////////
					//DECLARING NEW THStack FOR PLOTTING MANY HISTOS ON SAME PAD//
						 THStack *hs = new THStack("hs","");
////////////////////////////////////////////////////////////////////////////////////////////////////
 
 const int NTS=10;            // number of timeslices
  TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
  TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
  TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
  TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
  TLeaf* random = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
  TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
  TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
  TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");
  
 // TLeaf* adcLeaf[NTS];
  TLeaf* fCleaf[NTS];
  TLeaf* fCvTSleaf[NTS]; //declared to seperate TS variable to prevent the loops from messing each other up
  TLeaf* fCPureleaf[NTS];
  for(int iTS=0; iTS < NTS; iTS++){ //declaring Tleaves have 2 seperate to avoid confusion
    //adcLeaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("adc%d",iTS));
       fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
	fCvTSleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
	fCPureleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));	//calling t leaves of different value my be pointless and cause slow down or root to F up
  }
  
  
  for(int i = 0; i < ZDCDigiTree->GetEntries(); i++){
    ZDCDigiTree->GetEntry(i);
//declaring variables to hold channel charge for 45 and 456 for all RPD pos and neg
    //Pos
	double RPD_Pos_1_45, RPD_Pos_2_45, RPD_Pos_3_45, RPD_Pos_4_45, RPD_Pos_5_45, RPD_Pos_6_45, RPD_Pos_7_45, RPD_Pos_8_45, RPD_Pos_9_45, RPD_Pos_10_45, RPD_Pos_11_45, RPD_Pos_12_45, RPD_Pos_13_45, RPD_Pos_14_45, RPD_Pos_15_45, RPD_Pos_16_45;
	double RPD_Pos_1_456, RPD_Pos_2_456, RPD_Pos_3_456, RPD_Pos_4_456, RPD_Pos_5_456, RPD_Pos_6_456, RPD_Pos_7_456, RPD_Pos_8_456, RPD_Pos_9_456, RPD_Pos_10_456, RPD_Pos_11_456, RPD_Pos_12_456, RPD_Pos_13_456, RPD_Pos_14_456, RPD_Pos_15_456, RPD_Pos_16_456;
	double HAD_Pos_1_1;
	double HAD_Pos_1_2;
	//Neg
    double RPD_Neg_1_45, RPD_Neg_2_45, RPD_Neg_3_45, RPD_Neg_4_45, RPD_Neg_5_45, RPD_Neg_6_45, RPD_Neg_7_45, RPD_Neg_8_45, RPD_Neg_9_45, RPD_Neg_10_45, RPD_Neg_11_45, RPD_Neg_12_45, RPD_Neg_13_45, RPD_Neg_14_45, RPD_Neg_15_45, RPD_Neg_16_45;
	double RPD_Neg_1_456, RPD_Neg_2_456, RPD_Neg_3_456, RPD_Neg_4_456, RPD_Neg_5_456, RPD_Neg_6_456, RPD_Neg_7_456, RPD_Neg_8_456, RPD_Neg_9_456, RPD_Neg_10_456, RPD_Neg_11_456, RPD_Neg_12_456, RPD_Neg_13_456, RPD_Neg_14_456, RPD_Neg_15_456, RPD_Neg_16_456;
    double HAD_Neg_1_1;
	double HAD_Neg_1_2;
	//the ratio of HAD1 1/02 is used to identify what may be prefires
	
	// https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg
	//For loop for filling signal 45
    for(int n = 0; n < 50; n++){
      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;
	  
	  double Zero = fCleaf[0]->GetValue(n);
 	  double One = fCleaf[1]->GetValue(n);
	  double Two = fCleaf[2]->GetValue(n);
	  double Three = fCleaf[3]->GetValue(n);
	  double Four = fCleaf[4]->GetValue(n); 
	  double Five = fCleaf[5]->GetValue(n);
	  double Six =  fCleaf[6]->GetValue(n);
	  double Seven = fCleaf[7]->GetValue(n);
	  double Eight = fCleaf[8]->GetValue(n);
	  double Nine = fCleaf[9]->GetValue(n);
		if(Zero<0) {Zero = 0.0;}
		if(One<0) {One = 0.0;}
		if(Two<0) {Two = 0.0;}
		if(Three<0) {Three = 0.0;} // NOTE FROM 3/13/19 FOUND TS 3 IS USUALLY A NEGATIVE NUMBER KEEP THIS IN MIND WHEN MAKING TRIGGERS
		if(Four<0) {Four = 0.0;}
		if(Five<0) {Five = 0.0;}
		if(Six<0)  {Six  = 0.0;}
		if(Seven<0) {Seven = 0.0;}
		if(Eight<0) {Eight = 0.0;}
		if(Nine<0) {Nine = 0.0;}
		
      double signal45 = Four + Five;
	  double signal456 = Four + Five + Six;
	  double signal1 = One;
	  double signal2= Two; //!!!!!!!!!!!!!!!!!!!
	  

	//Filling had 1 unbiased by RPD selection
	if(type == 1){ //had
		if(side == 1){ //filling had 1 pos
			if(channel == 1){
				HAD_Pos_1_1 = signal1;
				HAD_Pos_1_2 = signal2;
			}
		}
	} 
	
	if(type == 1){ //had
		if(side == 0){// filling had 1 neg
			if(channel == 1){
				HAD_Neg_1_1 = signal1;
				HAD_Neg_1_2 = signal2;
			}
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(int iTS = 0; iTS < 10; iTS++){																														//PURE uncut RPD AND ZDC HISTOS
        if(type != 3){ // EM or HAD section
				double value = fCPureleaf[iTS]->GetValue(n);
				if(value < 0){  //THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
          
          fC_ZDC_Pure[side][type][channel]->Fill(iTS,value);          
        }
        else{ // RPD section
				double value = fCPureleaf[iTS]->GetValue(n);
				if(value < 0){  //THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
          fC_RPD_Pure[side][channel]->Fill(iTS,value);
        }
      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Fillig ZDC and RPD fC versus TS values// RPD trigger
	if((signal45/signal456 < CutOff) || (Seven >= Five) || (One/Zero > 1000 && Zero != 0) /*|| (Three > .5*Four)*/){ //include bad 
	for(int iTS = 0; iTS < 10; iTS++){
			if(type != 3){ // EM or HAD section
			  double value = fCvTSleaf[iTS]->GetValue(n);
				if(value < 0){  //THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
			  
			  fC_ZDC[side][type][channel]->Fill(iTS,value);    //uncommenting TS to see what happens      
		//      event->SetBinContent(iTS+1,fCleaf[iTS]->GetValue(n));
			}
			else{ // RPD section
			  double value = fCvTSleaf[iTS]->GetValue(n);
				if(value < 0){  //THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
			  
			  fC_RPD[side][channel]->Fill(iTS,value);
			  
			  ///should be good make 4x4 for both rpds and rearrange channels to correct x and y position
			}
		}
	}
	
	//Fillig ZDC and RPD fC versus TS values// HAD Trigger 
	
	/// //////////////////////////////////////////////////////////////////////////////////
	/// HAD IS CUT TO MAXIMIZE BAD SIGNALS and the search for SHITTY RPD AND THE CAUSE?///
	/// //////////////////////////////////////////////////////////////////////////////////
	
	if(signal1/signal2 > 200){ //range is peak of HAD ratio excluding 0 and 1 ratio peaks as this implies either there is little prepulse of the prepulse is equal in 0 and 1. Our observations have shown the prepulse is generally veryy large in TS 1 and minimal in TS 2
	for(int iTS = 0; iTS < 10; iTS++){
			if(type != 3){ // EM or HAD section
				double value = fCvTSleaf[iTS]->GetValue(n);
				if(value < 0){  //!!!! I AM CORRECT THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
				
			  fC_ZDCHT[side][type][channel]->Fill(iTS,value);     
		//      event->SetBinContent(iTS+1,fCleaf[iTS]->GetValue(n));
				
			}
			else{ // RPD section
			  //if(adcLeaf[iTS]->GetValue(n) > max)
			  //  max = adcLeaf[iTS]->GetValue(n);
			  double value = fCvTSleaf[iTS]->GetValue(n);
				if(value < 0){ //!!!! I AM CORRECT THIS IF STATEMENT REMOVES NEGATIVE VALUES!!!
				value = 0;}
			  
			  fC_RPDHT[side][channel]->Fill(iTS,value);
			  
			  ///should be good make 4x4 for both rpds and rearrange channels to correct x and y position
			}
		}
	}
      

      if(type == 3){ // RPD section // only for signal45 next loop 456
        if(side == 1){
          switch(channel){ //16 channels ergo 0 -15
            case 0:
              RPD_Pos_1_45 = signal45;
              break;
            case 1:
              RPD_Pos_2_45 = signal45;
              break;
            case 2:
              RPD_Pos_3_45 = signal45;
              break;
            case 3:
              RPD_Pos_4_45 = signal45;
			  break;
			case 4:
              RPD_Pos_5_45 = signal45;
              break;
            case 5:
              RPD_Pos_6_45 = signal45;
              break;
            case 6:
              RPD_Pos_7_45 = signal45;
              break;
            case 7:
              RPD_Pos_8_45 = signal45;
              break;
			case 8:
              RPD_Pos_9_45 = signal45;
              break;
            case 9:
              RPD_Pos_10_45 = signal45;
              break;
            case 10:
              RPD_Pos_11_45 = signal45;
              break;
            case 11:
              RPD_Pos_12_45 = signal45;
			  break;
			case 12:
              RPD_Pos_13_45 = signal45;
              break;
            case 13:
              RPD_Pos_14_45 = signal45;
              break;
            case 14:
              RPD_Pos_15_45 = signal45;
              break;
            case 15:
              RPD_Pos_16_45 = signal45;
              break;
          }
        }
        else{
           switch(channel){
            case 0:
              RPD_Neg_1_45 = signal45;
              break;
            case 1:
              RPD_Neg_2_45 = signal45;
              break;
            case 2:
              RPD_Neg_3_45 = signal45;
              break;
            case 3:
              RPD_Neg_4_45 = signal45;
			  break;
			case 4:
              RPD_Neg_5_45 = signal45;
              break;
            case 5:
              RPD_Neg_6_45 = signal45;
              break;
            case 6:
              RPD_Neg_7_45 = signal45;
              break;
            case 7:
              RPD_Neg_8_45 = signal45;
              break;
			case 8:
              RPD_Neg_9_45 = signal45;
              break;
            case 9:
              RPD_Neg_10_45 = signal45;
              break;
            case 10:
              RPD_Neg_11_45 = signal45;
              break;
            case 11:
              RPD_Neg_12_45 = signal45;
			  break;
			case 12:
              RPD_Neg_13_45 = signal45;
              break;
            case 13:
              RPD_Neg_14_45 = signal45;
              break;
            case 14:
              RPD_Neg_15_45 = signal45;
              break;
            case 15:
              RPD_Neg_16_45 = signal45;
              break;
           }
        }
      }
    }
	//////////////////////////////////
	//For loop for filling signal 456//
	//////////////////////////////////
	for(int n = 0; n < 50; n++){
		  int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
		  int type = (int)(sectionLeaf->GetValue(n))-1;
		  int channel = (int)(channelLeaf->GetValue(n))-1;
		  double Four = fCleaf[4]->GetValue(n); 
		  double Five = fCleaf[5]->GetValue(n);
	      double Six =  fCleaf[6]->GetValue(n);
		
		  if(Four<0) {Four = 0.0;}
		  if(Five<0) {Five = 0.0;}
		  if(Six<0)  {Six  = 0.0;}
		
		
          double signal45 = Four + Five;
	      double signal456 = Four + Five + Six;
		  
		  if(type == 3){ // RPD section // only for signal456
			if(side == 1){
			  switch(channel){ 
				case 0:
				  RPD_Pos_1_456 = signal456;
				  break;
				case 1:
				  RPD_Pos_2_456 = signal456;
				  break;
				case 2:
				  RPD_Pos_3_456 = signal456;
				  break;
				case 3:
				  RPD_Pos_4_456 = signal456;
				  break;
				case 4:
				  RPD_Pos_5_456 = signal456;
				  break;
				case 5:
				  RPD_Pos_6_456 = signal456;
				  break;
				case 6:
				  RPD_Pos_7_456 = signal456;
				  break;
				case 7:
				  RPD_Pos_8_456 = signal456;
				  break;
				case 8:
				  RPD_Pos_9_456 = signal456;
				  break;
				case 9:
				  RPD_Pos_10_456 = signal456;
				  break;
				case 10:
				  RPD_Pos_11_456 = signal456;
				  break;
				case 11:
				  RPD_Pos_12_456 = signal456;
				  break;
				case 12:
				  RPD_Pos_13_456 = signal456;
				  break;
				case 13:
				  RPD_Pos_14_456 = signal456;
				  break;
				case 14:
				  RPD_Pos_15_456 = signal456;
				  break;
				case 15:
				  RPD_Pos_16_456 = signal456;
				  break;
			  }
			}
			else{
			   switch(channel){
				case 0:
				  RPD_Neg_1_456 = signal456;
				  break;
				case 1:
				  RPD_Neg_2_456 = signal456;
				  break;
				case 2:
				  RPD_Neg_3_456 = signal456;
				  break;
				case 3:
				  RPD_Neg_4_456 = signal456;
				  break;
				case 4:
				  RPD_Neg_5_456 = signal456;
				  break;
				case 5:
				  RPD_Neg_6_456 = signal456;
				  break;
				case 6:
				  RPD_Neg_7_456 = signal456;
				  break;
				case 7:
				  RPD_Neg_8_456 = signal456;
				  break;
				case 8:
				  RPD_Neg_9_456 = signal456;
				  break;
				case 9:
				  RPD_Neg_10_456 = signal456;
				  break;
				case 10:
				  RPD_Neg_11_456 = signal456;
				  break;
				case 11:
				  RPD_Neg_12_456 = signal456;
				  break;
				case 12:
				  RPD_Neg_13_456 = signal456;
				  break;
				case 13:
				  RPD_Neg_14_456 = signal456;
				  break;
				case 14:
				  RPD_Neg_15_456 = signal456;
				  break;
				case 15:
				  RPD_Neg_16_456 = signal456;
				  break;
			   }
			}
		  }
		}

	//filling histogram pointers
	//pos/////////////////////////////////////////////////
		RPD45456_CH1_Pos->Fill(RPD_Pos_1_45/RPD_Pos_1_456);
		RPD45456_CH2_Pos->Fill(RPD_Pos_2_45/RPD_Pos_2_456);
		RPD45456_CH3_Pos->Fill(RPD_Pos_3_45/RPD_Pos_3_456);
		RPD45456_CH4_Pos->Fill(RPD_Pos_4_45/RPD_Pos_4_456);
		RPD45456_CH5_Pos->Fill(RPD_Pos_5_45/RPD_Pos_5_456);
		RPD45456_CH6_Pos->Fill(RPD_Pos_6_45/RPD_Pos_6_456);
		RPD45456_CH7_Pos->Fill(RPD_Pos_7_45/RPD_Pos_7_456);
		RPD45456_CH8_Pos->Fill(RPD_Pos_8_45/RPD_Pos_8_456);
		RPD45456_CH9_Pos->Fill(RPD_Pos_9_45/RPD_Pos_9_456);
		RPD45456_CH10_Pos->Fill(RPD_Pos_10_45/RPD_Pos_10_456);
		RPD45456_CH11_Pos->Fill(RPD_Pos_11_45/RPD_Pos_11_456);
		RPD45456_CH12_Pos->Fill(RPD_Pos_12_45/RPD_Pos_12_456);
		RPD45456_CH13_Pos->Fill(RPD_Pos_13_45/RPD_Pos_13_456);
		RPD45456_CH14_Pos->Fill(RPD_Pos_14_45/RPD_Pos_14_456);
		RPD45456_CH15_Pos->Fill(RPD_Pos_15_45/RPD_Pos_15_456);
		RPD45456_CH16_Pos->Fill(RPD_Pos_16_45/RPD_Pos_16_456);
		/*HAD*/HAD112_CH1_Pos->Fill(HAD_Pos_1_1/HAD_Pos_1_2);
		
	//neg
	//////////////////////////////////////////////////////
		RPD45456_CH1_Neg->Fill(RPD_Neg_1_45/RPD_Neg_1_456);
		RPD45456_CH2_Neg->Fill(RPD_Neg_2_45/RPD_Neg_2_456);
		RPD45456_CH3_Neg->Fill(RPD_Neg_3_45/RPD_Neg_3_456);
		RPD45456_CH4_Neg->Fill(RPD_Neg_4_45/RPD_Neg_4_456);
		RPD45456_CH5_Neg->Fill(RPD_Neg_5_45/RPD_Neg_5_456);
		RPD45456_CH6_Neg->Fill(RPD_Neg_6_45/RPD_Neg_6_456);
		RPD45456_CH7_Neg->Fill(RPD_Neg_7_45/RPD_Neg_7_456);
		RPD45456_CH8_Neg->Fill(RPD_Neg_8_45/RPD_Neg_8_456);
		RPD45456_CH9_Neg->Fill(RPD_Neg_9_45/RPD_Neg_9_456);
		RPD45456_CH10_Neg->Fill(RPD_Neg_10_45/RPD_Neg_10_456);
		RPD45456_CH11_Neg->Fill(RPD_Neg_11_45/RPD_Neg_11_456);
		RPD45456_CH12_Neg->Fill(RPD_Neg_12_45/RPD_Neg_12_456);
		RPD45456_CH13_Neg->Fill(RPD_Neg_13_45/RPD_Neg_13_456);
		RPD45456_CH14_Neg->Fill(RPD_Neg_14_45/RPD_Neg_14_456);
		RPD45456_CH15_Neg->Fill(RPD_Neg_15_45/RPD_Neg_15_456);
		RPD45456_CH16_Neg->Fill(RPD_Neg_16_45/RPD_Neg_16_456);
		/*HAD*/HAD112_CH1_Neg->Fill(HAD_Neg_1_1/HAD_Neg_1_2);
	//end filling histogram pointers

    if(i % 100000 == 0) std::cout << i << " events are processed." << std::endl;
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////

  //c1->SetLogy(); // enabeled log scale.

  TFile f2("ratio.root","RECREATE"); 

    //pos drawing and saving histos
		/*		HAD112_CH1_Pos->SetLineColor(4);
				HAD112_CH1_Pos->Draw("hist e");
				HAD112_CH1_Pos->Write();
				c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/HAD112_CH1_Pos.png");
	*/
	
	/*
		RPD45456_CH1_Pos->SetLineColor(4);
		RPD45456_CH1_Pos->Draw("hist e");
		RPD45456_CH1_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH1_Pos.png");
		
		RPD45456_CH2_Pos->SetLineColor(4);
		RPD45456_CH2_Pos->Draw("hist e");
		RPD45456_CH2_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH2_Pos.png");
		
		RPD45456_CH3_Pos->SetLineColor(4);
		RPD45456_CH3_Pos->Draw("hist e");
		RPD45456_CH3_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH3_Pos.png");
		
		RPD45456_CH4_Pos->SetLineColor(4);
		RPD45456_CH4_Pos->Draw("hist e");
		RPD45456_CH4_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH4_Pos.png");
		
		RPD45456_CH5_Pos->SetLineColor(4);
		RPD45456_CH5_Pos->Draw("hist e");
		RPD45456_CH5_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH5_Pos.png");
		
		RPD45456_CH6_Pos->SetLineColor(4);
		RPD45456_CH6_Pos->Draw("hist e");
		RPD45456_CH6_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH6_Pos.png");
		
		RPD45456_CH7_Pos->SetLineColor(4);
		RPD45456_CH7_Pos->Draw("hist e");
		RPD45456_CH7_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH7_Pos.png");
		
		RPD45456_CH8_Pos->SetLineColor(4);
		RPD45456_CH8_Pos->Draw("hist e");
		RPD45456_CH8_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH8_Pos.png");
		
		RPD45456_CH9_Pos->SetLineColor(4);
		RPD45456_CH9_Pos->Draw("hist e");
		RPD45456_CH9_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH9_Pos.png");
		
		RPD45456_CH10_Pos->SetLineColor(4);
		RPD45456_CH10_Pos->Draw("hist e");
		RPD45456_CH10_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH10_Pos.png");
		
		RPD45456_CH11_Pos->SetLineColor(4);
		RPD45456_CH11_Pos->Draw("hist e");
		RPD45456_CH11_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH11_Pos.png");
		
		RPD45456_CH12_Pos->SetLineColor(4);
		RPD45456_CH12_Pos->Draw("hist e");
		RPD45456_CH12_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH12_Pos.png");
		
		RPD45456_CH13_Pos->SetLineColor(4);
		RPD45456_CH13_Pos->Draw("hist e");
		RPD45456_CH13_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH13_Pos.png");
		
		RPD45456_CH14_Pos->SetLineColor(4);
		RPD45456_CH14_Pos->Draw("hist e");
		RPD45456_CH14_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH14_Pos.png");
		
		RPD45456_CH15_Pos->SetLineColor(4);
		RPD45456_CH15_Pos->Draw("hist e");
		RPD45456_CH15_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH15_Pos.png");
		
		RPD45456_CH16_Pos->SetLineColor(4);
		RPD45456_CH16_Pos->Draw("hist e");
		RPD45456_CH16_Pos->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH16_Pos.png");
	*/
	
	/////////////////////////////////
	//Neg drawing and saving histos//
	/////////////////////////////////
	/*
		HAD112_CH1_Neg->SetLineColor(4); // blue
				HAD112_CH1_Neg->SetFillColorAlpha(kBlue, 0.35);
				HAD112_CH1_Neg->SetFillStyle(3001);
				//HAD112_CH1_Neg->Draw("hist e");
				hs->Add(HAD112_CH1_Neg);
				HAD112_CH1_Pos->SetLineColor(2);//Red//green
				HAD112_CH1_Pos->SetFillColorAlpha(kRed, 0.35);
				HAD112_CH1_Pos->SetFillStyle(3001);
				//HAD112_CH1_Pos->Draw("same");
				hs->Add(HAD112_CH1_Pos);
				hs->Draw("hist e");
				HAD112_CH1_Neg->Write();
				c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/HAD112_CH1_Neg.png");
	
*/
	/*			
		RPD45456_CH1_Neg->SetLineColor(4);
		RPD45456_CH1_Neg->Draw("hist e");
		RPD45456_CH1_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH1_Neg.png");
		
		RPD45456_CH2_Neg->SetLineColor(4);
		RPD45456_CH2_Neg->Draw("hist e");
		RPD45456_CH2_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH2_Neg.png");
		
		RPD45456_CH3_Neg->SetLineColor(4);
		RPD45456_CH3_Neg->Draw("hist e");
		RPD45456_CH3_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH3_Neg.png");
		
		RPD45456_CH4_Neg->SetLineColor(4);
		RPD45456_CH4_Neg->Draw("hist e");
		RPD45456_CH4_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH4_Neg.png");
		
		RPD45456_CH5_Neg->SetLineColor(4);
		RPD45456_CH5_Neg->Draw("hist e");
		RPD45456_CH5_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH5_Neg.png");
		
		RPD45456_CH6_Neg->SetLineColor(4);
		RPD45456_CH6_Neg->Draw("hist e");
		RPD45456_CH6_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH6_Neg.png");
		
		RPD45456_CH7_Neg->SetLineColor(4);
		RPD45456_CH7_Neg->Draw("hist e");
		RPD45456_CH7_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH7_Neg.png");
		
		RPD45456_CH8_Neg->SetLineColor(4);
		RPD45456_CH8_Neg->Draw("hist e");
		RPD45456_CH8_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH8_Neg.png");
		
		RPD45456_CH9_Neg->SetLineColor(4);
		RPD45456_CH9_Neg->Draw("hist e");
		RPD45456_CH9_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH9_Neg.png");
		
		RPD45456_CH10_Neg->SetLineColor(4);
		RPD45456_CH10_Neg->Draw("hist e");
		RPD45456_CH10_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH10_Neg.png");
		
		RPD45456_CH11_Neg->SetLineColor(4);
		RPD45456_CH11_Neg->Draw("hist e");
		RPD45456_CH11_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH11_Neg.png");
		
		RPD45456_CH12_Neg->SetLineColor(4);
		RPD45456_CH12_Neg->Draw("hist e");
		RPD45456_CH12_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH12_Neg.png");
		
		RPD45456_CH13_Neg->SetLineColor(4);
		RPD45456_CH13_Neg->Draw("hist e");
		RPD45456_CH13_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH13_Neg.png");
		
		RPD45456_CH14_Neg->SetLineColor(4);
		RPD45456_CH14_Neg->Draw("hist e");
		RPD45456_CH14_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH14_Neg.png");
		
		RPD45456_CH15_Neg->SetLineColor(4);
		RPD45456_CH15_Neg->Draw("hist e");
		RPD45456_CH15_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH15_Neg.png");
		
		RPD45456_CH16_Neg->SetLineColor(4);
		RPD45456_CH16_Neg->Draw("hist e");
		RPD45456_CH16_Neg->Write();
		c1->SaveAs("ZDC_figures/HAD_BadSignalSearch_RPD_45456_Ratio_Run/RPD45456_CH16_Neg.png");
	*/
	
	//now add to 4x4 note this is not a loop to be edited later to accomodate the true ordering of the quartz blocks
	
	//Now adding in division canvas and does not need a histogram but will be saved as an image
	
/*	
	TCanvas *c2 = new TCanvas("c2", ";45/456 ALL Pos RUN 327560;, 2000, 1500");
			
			c2->Divide(4,4,0.0001,0.0001); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
			c2->cd(1);
			gPad-> SetLogy();
			RPD45456_CH12_Pos->Draw("hist e");
			c2->cd(2);
			gPad-> SetLogy();
			RPD45456_CH16_Pos->Draw("hist e");
			c2->cd(3);
			gPad-> SetLogy();
			RPD45456_CH3_Pos->Draw("hist e");
			c2->cd(4);
			gPad-> SetLogy();
			RPD45456_CH6_Pos->Draw("hist e");
			c2->cd(5);
			gPad-> SetLogy();
			RPD45456_CH9_Pos->Draw("hist e");
			c2->cd(6);
			gPad-> SetLogy();
			RPD45456_CH13_Pos->Draw("hist e");
			c2->cd(7);
			gPad-> SetLogy();
			RPD45456_CH2_Pos->Draw("hist e");
			c2->cd(8);
			gPad-> SetLogy();
			RPD45456_CH7_Pos->Draw("hist e");
			c2->cd(9);
			gPad-> SetLogy();
			RPD45456_CH10_Pos->Draw("hist e");
			c2->cd(10);
			gPad-> SetLogy();
			RPD45456_CH14_Pos->Draw("hist e");
			c2->cd(11);
			gPad-> SetLogy();
			RPD45456_CH1_Pos->Draw("hist e");
			c2->cd(12);
			gPad-> SetLogy();
			RPD45456_CH5_Pos->Draw("hist e");
			c2->cd(13);
			gPad-> SetLogy();
			RPD45456_CH11_Pos->Draw("hist e");
			c2->cd(14);
			gPad-> SetLogy();
			RPD45456_CH15_Pos->Draw("hist e");
			c2->cd(15);
			gPad-> SetLogy();
			RPD45456_CH4_Pos->Draw("hist e");
			c2->cd(16);
			gPad-> SetLogy();
			RPD45456_CH8_Pos->Draw("hist e");
			c2->SaveAs("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/CORRECTQBLAYOUT_RPD45456_CHALL_Pos.png");
			//RPD + 3/8/19
			//12, 16, 3 ,6
			//9, 13, 2 ,7
		   //10, 14, 1 ,5
		   //11, 15, 4, 8
		

	//neg
	TCanvas *c3 = new TCanvas("c3", ";45/456 ALL Neg RUN 327560;, 2000, 1500"); // because we are not declaring histograms it is necessary to add a 3rd canvas
		//gPad-> SetLogy();
		
		c3->Divide(4,4,0.0001,0.0001);
			c3->cd(1);
			gPad->SetLogy();
			RPD45456_CH12_Neg->Draw("hist e");
			c3->cd(2);
			gPad->SetLogy();
			RPD45456_CH16_Neg->Draw("hist e");
			c3->cd(3);
			gPad->SetLogy();
			RPD45456_CH3_Neg->Draw("hist e");
			c3->cd(4);
			gPad->SetLogy();
			RPD45456_CH7_Neg->Draw("hist e");
			c3->cd(5);
			gPad->SetLogy();
			RPD45456_CH9_Neg->Draw("hist e");
			c3->cd(6);
			gPad->SetLogy();
			RPD45456_CH13_Neg->Draw("hist e");
			c3->cd(7);
			gPad->SetLogy();
			RPD45456_CH2_Neg->Draw("hist e");
			c3->cd(8);
			gPad->SetLogy();
			RPD45456_CH6_Neg->Draw("hist e");
			c3->cd(9);
			gPad->SetLogy();
			RPD45456_CH10_Neg->Draw("hist e");
			c3->cd(10);
			gPad->SetLogy();
			RPD45456_CH14_Neg->Draw("hist e");
			c3->cd(11);
			gPad->SetLogy();
			RPD45456_CH1_Neg->Draw("hist e");
			c3->cd(12);
			gPad->SetLogy();
			RPD45456_CH5_Neg->Draw("hist e");
			c3->cd(13);
			gPad->SetLogy();
			RPD45456_CH11_Neg->Draw("hist e");
			c3->cd(14);
			gPad->SetLogy();
			RPD45456_CH15_Neg->Draw("hist e");
			c3->cd(15);
			gPad->SetLogy();
			RPD45456_CH4_Neg->Draw("hist e");
			c3->cd(16);
			gPad->SetLogy();
			RPD45456_CH8_Neg->Draw("hist e");
			c3->SaveAs("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/CORRECTQBLAYOUT_RPD45456_CHALL_Neg.png");
			//RPD - 3/8/19
			//12, 16, 3 ,7
			//9, 13, 2 ,6
		   //10, 14, 1 ,5
		   //11, 15, 4, 8
*/
			
////////////////////////////////////////////////////////////////////////////////////////////////
//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
////////////////////////////////////////////////////////////////////////////////////////////////
   TCanvas *c4 = new TCanvas("c4", "RUN 327560", 2000, 1500);
        gPad-> SetLogy();
		c4->Divide(4,4,0.0001,0.0001); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
			//subtract 1 from all channel value bc start at 0
			int A = 4;
			int B = 2;
			cout << "line before loop" << endl;
		
			for(int i =0; i < 2; i++){ //problem for loop refuses to stop
				cout << "line after pos neg loop" << endl;
					for(int j=0 ; j < 16; j++){

	
								c4->cd(RPDCorrect[i][j] + 1);
								cout << "line after cd="<< (RPDCorrect[i][j] + 1) << endl; // this is working
								cout << "j" << j << endl; 
								cout << "i" << i << endl;
								gPad->SetLogy();
								hsRPD[i][j] = new THStack("hsRPD","");
								cout << "line after making THstack" << endl;
								fC_RPD[i][j-1]->SetLineColor(B);
								fC_RPD[i][j-1]->SetFillStyle(3001);
								fC_RPD[i][j-1]->SetFillColorAlpha(kRed, 0.35);
								cout << "line before add to hsRPD" << endl;
								hsRPD[i][j]->Add(fC_RPD[i][j-1]);
								cout << "line after add to hsRPD" << endl;
								fC_RPD_Pure[i][j-1]->SetLineColor(A);
								fC_RPD_Pure[i][j-1]->SetFillStyle(3001);
								cout << "line  after set fill style" << endl;
								fC_RPD_Pure[i][j-1]->SetFillColorAlpha(kBlue, 0.35);
								cout << "line after set fill color" << endl;
								hsRPD[i][j]->Add(fC_RPD_Pure[i][j-1]); //->Draw("hist e");
								cout << "line  after add rpd pure" << endl;
								hsRPD[i][j]->Draw("hist e"); //->Draw("same");
								cout << "line after draw hist e" << endl;             
					}
				c4->SaveAs(Form("ZDC_figures/basic_dist/fC_ZDC_%s_ALL_%d.png",stit2[i], runnumber));// this is the culprit and caused the loop to keep going
				}
		
		
		/// OBSOLETE BY LOOP ABOVE :)
			/*c4->cd(1);
			gPad->SetLogy();
			//fC_RPD[1][11]->Draw("hist e");
			fC_RPD_Pure[1][11]->SetLineColor(A);
			fC_RPD_Pure[1][11]->SetFillStyle(3001);
			fC_RPD_Pure[1][11]->SetFillColorAlpha(kBlue, 0.35);
			hs->Add(fC_RPD_Pure[1][11]); //->Draw("hist e");
			fC_RPD[1][11]->SetLineColor(B);
			fC_RPD[1][11]->SetFillStyle(3001);
			fC_RPD[1][11]->SetFillColorAlpha(kRed, 0.35);
			hs->Add(fC_RPD[1][11]);
			//hs->Draw("hist e"); //->Draw("same");
			c4->cd(2);
			gPad->SetLogy();
			//fC_RPD[1][15]->Draw("hist e");
			fC_RPD_Pure[1][15]->SetLineColor(A);
			//fC_RPD_Pure[1][15]->SetFillStyle(3001);
			fC_RPD_Pure[1][15]->SetFillColorAlpha(kBlue, 0.35);
			hs->Add(fC_RPD_Pure[1][15]); //->Draw("hist e");
			fC_RPD[1][15]->SetLineColor(B);
			//fC_RPD[1][15]->SetFillStyle(3001);
			fC_RPD[1][15]->SetFillColorAlpha(kRed, 0.35);
			hs->Add(fC_RPD[1][15]);
			hs->Draw("hist e"); //->Draw("same");
			c4->cd(3);
			gPad->SetLogy();
			//fC_RPD[1][2]->Draw("hist e");
			fC_RPD_Pure[1][2]->SetLineColor(4);
			fC_RPD[1][2]->SetLineColor(B);
			fC_RPD_Pure[1][2]->Draw("hist e");
			fC_RPD[1][2]->Draw("same");
			c4->cd(4);
			gPad->SetLogy();
			//fC_RPD[1][5]->Draw("hist e"); // 5 and 6 are reversed in pos bc of a hardware mis cabling of WLSFibers
			fC_RPD_Pure[1][5]->SetLineColor(4);
			fC_RPD[1][5]->SetLineColor(B);
			fC_RPD_Pure[1][5]->Draw("hist e");
			fC_RPD[1][5]->Draw("same");
			c4->cd(5);
			gPad->SetLogy();
			//fC_RPD[1][8]->Draw("hist e");
			fC_RPD_Pure[1][8]->SetLineColor(4);
			fC_RPD[1][8]->SetLineColor(B);
			fC_RPD_Pure[1][8]->Draw("hist e");
			fC_RPD[1][8]->Draw("same");
			c4->cd(6);
			gPad->SetLogy();
			//fC_RPD[1][12]->Draw("hist e");
			fC_RPD_Pure[1][12]->SetLineColor(4);
			fC_RPD[1][12]->SetLineColor(B);
			fC_RPD_Pure[1][12]->Draw("hist e");
			fC_RPD[1][12]->Draw("same");
			c4->cd(7);
			gPad->SetLogy();
			//fC_RPD[1][2]->Draw("hist e");
			fC_RPD_Pure[1][2]->SetLineColor(4);
			fC_RPD[1][2]->SetLineColor(B);
			fC_RPD_Pure[1][2]->Draw("hist e");
			fC_RPD[1][2]->Draw("same");
			c4->cd(8);
			gPad->SetLogy();
			//fC_RPD[1][6]->Draw("hist e");
			fC_RPD_Pure[1][6]->SetLineColor(4);
			fC_RPD[1][6]->SetLineColor(B);
			fC_RPD_Pure[1][6]->Draw("hist e");
			fC_RPD[1][6]->Draw("same");
			c4->cd(9);
			gPad->SetLogy();
			//fC_RPD[1][9]->Draw("hist e");
			fC_RPD_Pure[1][9]->SetLineColor(4);
			fC_RPD[1][9]->SetLineColor(B);
			fC_RPD_Pure[1][9]->Draw("hist e");
			fC_RPD[1][9]->Draw("same");
			c4->cd(10);
			gPad->SetLogy();
			//fC_RPD[1][13]->Draw("hist e");
			fC_RPD_Pure[1][13]->SetLineColor(4);
			fC_RPD[1][13]->SetLineColor(B);
			fC_RPD_Pure[1][13]->Draw("hist e");
			fC_RPD[1][13]->Draw("same");
			c4->cd(11);
			gPad->SetLogy();
			//fC_RPD[1][0]->Draw("hist e");
			fC_RPD_Pure[1][0]->SetLineColor(4);
			fC_RPD[1][0]->SetLineColor(B);
			fC_RPD_Pure[1][0]->Draw("hist e");
			fC_RPD[1][0]->Draw("same");
			c4->cd(12);
			gPad->SetLogy();
			//fC_RPD[1][4]->Draw("hist e");
			fC_RPD_Pure[1][4]->SetLineColor(4);
			fC_RPD[1][4]->SetLineColor(B);
			fC_RPD_Pure[1][4]->Draw("hist e");
			fC_RPD[1][4]->Draw("same");
			c4->cd(13);
			gPad->SetLogy();
			//fC_RPD[1][10]->Draw("hist e");
			fC_RPD_Pure[1][10]->SetLineColor(4);
			fC_RPD[1][10]->SetLineColor(B);
			fC_RPD_Pure[1][10]->Draw("hist e");
			fC_RPD[1][10]->Draw("same");
			c4->cd(14);
			gPad->SetLogy();
			//fC_RPD[1][14]->Draw("hist e");
			fC_RPD_Pure[1][14]->SetLineColor(4);
			fC_RPD[1][14]->SetLineColor(B);
			fC_RPD_Pure[1][14]->Draw("hist e");
			fC_RPD[1][14]->Draw("same");
			c4->cd(15);
			gPad->SetLogy();
			//fC_RPD[1][3]->Draw("hist e");
			fC_RPD_Pure[1][3]->SetLineColor(4);
			fC_RPD[1][3]->SetLineColor(B);
			fC_RPD_Pure[1][3]->Draw("hist e");
			fC_RPD[1][3]->Draw("same");
			c4->cd(16);
			gPad->SetLogy();
			//fC_RPD[1][7]->Draw("hist e");
			fC_RPD_Pure[1][7]->SetLineColor(4);
			fC_RPD[1][7]->SetLineColor(B);
			fC_RPD_Pure[1][7]->Draw("hist e");
			fC_RPD[1][7]->Draw("same");
			  
			   c4->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_CORRECTQBLAYOUT_fC_RPD_Plus_channel_ALL_327560.png"));
			   
			   //4x4 for RPD - <--------------!!!!!!!!
			c4->cd(1);
			gPad->SetLogy();
			THStack *hsn1 = new THStack("hsn1","");
			fC_RPD_Pure[0][11]->SetLineColor(4);////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			fC_RPD[0][11]->SetLineColor(B);
			fC_RPD_Pure[0][11]->Draw("hist e");
			fC_RPD[0][11]->Draw("same");
			c4->cd(2);
			gPad->SetLogy();
			THStack* hsn2 = new THStack("hsn2",""); ///
			fC_RPD[0][15]->SetLineColor(B);
			fC_RPD[0][15]->SetFillStyle(3001);
			fC_RPD[0][15]->SetFillColorAlpha(kRed, 0.35);
			hsn2->Add(fC_RPD[0][15]);
			fC_RPD_Pure[0][15]->SetLineColor(A);
			fC_RPD_Pure[0][15]->SetFillStyle(3001);
			fC_RPD_Pure[0][15]->SetFillColorAlpha(kBlue, 0.35);
			hsn2->Add(fC_RPD_Pure[0][15]); //->Draw("hist e");
			hsn2->Draw("hist e"); //->Draw("same");
			c4->cd(3);
			gPad->SetLogy();
			//fC_RPD[0][2]->Draw("hist e");
			fC_RPD_Pure[0][2]->SetLineColor(4);
			fC_RPD[0][2]->SetLineColor(B);
			fC_RPD_Pure[0][2]->Draw("hist e");
			fC_RPD[0][2]->Draw("same");
			c4->cd(4);
			gPad->SetLogy();
			//fC_RPD[0][6]->Draw("hist e");
			fC_RPD_Pure[0][6]->SetLineColor(4);
			fC_RPD[0][6]->SetLineColor(B);
			fC_RPD_Pure[0][6]->Draw("hist e");
			fC_RPD[0][6]->Draw("same");
			c4->cd(5);
			gPad->SetLogy();
			//fC_RPD[0][8]->Draw("hist e");
			fC_RPD_Pure[0][8]->SetLineColor(4);
			fC_RPD[0][8]->SetLineColor(B);
			fC_RPD_Pure[0][8]->Draw("hist e");
			fC_RPD[0][8]->Draw("same");
			c4->cd(6);
			gPad->SetLogy();
			//fC_RPD[0][12]->Draw("hist e");
			fC_RPD_Pure[0][12]->SetLineColor(4);
			fC_RPD[0][12]->SetLineColor(B);
			fC_RPD_Pure[0][12]->Draw("hist e");
			fC_RPD[0][12]->Draw("same");
			c4->cd(7);
			gPad->SetLogy();
			//fC_RPD[0][2]->Draw("hist e");
			fC_RPD_Pure[0][2]->SetLineColor(4);
			fC_RPD[0][2]->SetLineColor(B);
			fC_RPD_Pure[0][2]->Draw("hist e");
			fC_RPD[0][2]->Draw("same");
			c4->cd(8);
			gPad->SetLogy();
			//fC_RPD[0][5]->Draw("hist e");
			fC_RPD_Pure[0][5]->SetLineColor(4);
			fC_RPD[0][5]->SetLineColor(B);
			fC_RPD_Pure[0][5]->Draw("hist e");
			fC_RPD[0][5]->Draw("same");
			c4->cd(9);
			gPad->SetLogy();
			//fC_RPD[0][9]->Draw("hist e");
			fC_RPD_Pure[0][9]->SetLineColor(4);
			fC_RPD[0][9]->SetLineColor(B);
			fC_RPD_Pure[0][9]->Draw("hist e");
			fC_RPD[0][9]->Draw("same");
			c4->cd(10);
			gPad->SetLogy();
			//fC_RPD[0][13]->Draw("hist e");
			fC_RPD_Pure[0][13]->SetLineColor(4);
			fC_RPD[0][13]->SetLineColor(B);
			fC_RPD_Pure[0][13]->Draw("hist e");
			fC_RPD[0][13]->Draw("same");
			c4->cd(11);
			gPad->SetLogy();
			//fC_RPD[0][0]->Draw("hist e");
			fC_RPD_Pure[0][0]->SetLineColor(4);
			fC_RPD[0][0]->SetLineColor(B);
			fC_RPD_Pure[0][0]->Draw("hist e");
			fC_RPD[0][0]->Draw("same");
			c4->cd(12);
			gPad->SetLogy();
			//fC_RPD[0][4]->Draw("hist e");
			fC_RPD_Pure[0][4]->SetLineColor(4);
			fC_RPD[0][4]->SetLineColor(B);
			fC_RPD_Pure[0][4]->Draw("hist e");
			fC_RPD[0][4]->Draw("same");
			c4->cd(13);
			gPad->SetLogy();
			//fC_RPD[0][10]->Draw("hist e");
			fC_RPD_Pure[0][10]->SetLineColor(4);
			fC_RPD[0][10]->SetLineColor(B);
			fC_RPD_Pure[0][10]->Draw("hist e");
			fC_RPD[0][10]->Draw("same");
			c4->cd(14);
			gPad->SetLogy();
			//fC_RPD[0][14]->Draw("hist e");
			fC_RPD_Pure[0][14]->SetLineColor(4);
			fC_RPD[0][14]->SetLineColor(B);
			fC_RPD_Pure[0][14]->Draw("hist e");
			fC_RPD[0][14]->Draw("same");
			c4->cd(15);
			gPad->SetLogy();
			//fC_RPD[0][3]->Draw("hist e");
			fC_RPD_Pure[0][3]->SetLineColor(4);
			fC_RPD[0][3]->SetLineColor(B);
			fC_RPD_Pure[0][3]->Draw("hist e");
			fC_RPD[0][3]->Draw("same");
			c4->cd(16);
			gPad->SetLogy();
			//fC_RPD[0][7]->Draw("hist e");
			fC_RPD_Pure[0][7]->SetLineColor(4);
			fC_RPD[0][7]->SetLineColor(B);
			fC_RPD_Pure[0][7]->Draw("hist e");
			fC_RPD[0][7]->Draw("same");

*/ 

//c4->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_CORRECTQBLAYOUT_fC_RPD_Plus_channel_ALL_327560.png"));

//c4->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_CORRECTQBLAYOUT_fC_RPD_Minus_channel_ALL_327560.png"));

	      	//////////////////////
			//HAD TRIGGER Histos//
			//////////////////////

			c4->cd(1);
			gPad->SetLogy();
			fC_RPDHT[1][11]->Draw("hist e");
			c4->cd(2);
			gPad->SetLogy();
			fC_RPDHT[1][15]->Draw("hist e");
			c4->cd(3);
			gPad->SetLogy();
			fC_RPDHT[1][2]->Draw("hist e");
			c4->cd(4);
			gPad->SetLogy();
			fC_RPDHT[1][5]->Draw("hist e"); // 5 and 6 are reversed in pos bc of a hardware mis cabling of WLSFibers
			c4->cd(5);
			gPad->SetLogy();
			fC_RPDHT[1][8]->Draw("hist e");
			c4->cd(6);
			gPad->SetLogy();
			fC_RPDHT[1][12]->Draw("hist e");
			c4->cd(7);
			gPad->SetLogy();
			fC_RPDHT[1][2]->Draw("hist e");
			c4->cd(8);
			gPad->SetLogy();
			fC_RPDHT[1][6]->Draw("hist e");
			c4->cd(9);
			gPad->SetLogy();
			fC_RPDHT[1][9]->Draw("hist e");
			c4->cd(10);
			gPad->SetLogy();
			fC_RPDHT[1][13]->Draw("hist e");
			c4->cd(11);
			gPad->SetLogy();
			fC_RPDHT[1][0]->Draw("hist e");
			c4->cd(12);
			gPad->SetLogy();
			fC_RPDHT[1][4]->Draw("hist e");
			c4->cd(13);
			gPad->SetLogy();
			fC_RPDHT[1][10]->Draw("hist e");
			c4->cd(14);
			gPad->SetLogy();
			fC_RPDHT[1][14]->Draw("hist e");
			c4->cd(15);
			gPad->SetLogy();
			fC_RPDHT[1][3]->Draw("hist e");
			c4->cd(16);
			gPad->SetLogy();
			fC_RPDHT[1][7]->Draw("hist e");
			  // 4x4 for RPD + <-------------!!!!!!!
			  // for(int i = 1; i < 17; i++){
			//	c4->cd(i); //(this sets the current canvas division to canvas divsion i) assumes loop variable is i, and inputs them into the canvas from left to right then down on row
			//	 fC_RPD[0][i-1]->Draw();
			//	 c4->Update(); runumber
			  // }
			   c4->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_CORRECTQBLAYOUT_fC_RPDHT_Plus_channel_ALL_%d.png", runnumber));
			   
			   //4x4 for RPD - <--------------!!!!!!!!
			c4->cd(1);
			gPad->SetLogy();
			fC_RPDHT[0][11]->Draw("hist e");
			c4->cd(2);
			gPad->SetLogy();
			fC_RPDHT[0][15]->Draw("hist e");
			c4->cd(3);
			gPad->SetLogy();
			fC_RPDHT[0][2]->Draw("hist e");
			c4->cd(4);
			gPad->SetLogy();
			fC_RPDHT[0][6]->Draw("hist e");
			c4->cd(5);
			gPad->SetLogy();
			fC_RPDHT[0][8]->Draw("hist e");
			c4->cd(6);
			gPad->SetLogy();
			fC_RPDHT[0][12]->Draw("hist e");
			c4->cd(7);
			gPad->SetLogy();
			fC_RPDHT[0][2]->Draw("hist e");
			c4->cd(8);
			gPad->SetLogy();
			fC_RPDHT[0][5]->Draw("hist e");
			c4->cd(9);
			gPad->SetLogy();
			fC_RPDHT[0][9]->Draw("hist e");
			c4->cd(10);
			gPad->SetLogy();
			fC_RPDHT[0][13]->Draw("hist e");
			c4->cd(11);
			gPad->SetLogy();
			fC_RPDHT[0][0]->Draw("hist e");
			c4->cd(12);
			gPad->SetLogy();
			fC_RPDHT[0][4]->Draw("hist e");
			c4->cd(13);
			gPad->SetLogy();
			fC_RPDHT[0][10]->Draw("hist e");
			c4->cd(14);
			gPad->SetLogy();
			fC_RPDHT[0][14]->Draw("hist e");
			c4->cd(15);
			gPad->SetLogy();
			fC_RPDHT[0][3]->Draw("hist e");
			c4->cd(16);
			gPad->SetLogy();
			fC_RPDHT[0][7]->Draw("hist e");
			  // for(int i = 1; i < 17; i++){
				//c4->cd(i); //(this sets the current canvas division to canvas divsion i) assumes loop variable is i, and inputs them into the canvas from left to right then down on row
				// fC_RPD[1][i-1]->Draw();
				// c4->Update(); 
			  // }
			   c4->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_CORRECTQBLAYOUT_fC_RPDHT_Minus_channel_ALL_%d.png", runnumber));



	TCanvas *c5 = new TCanvas("c5", "RUN 327560", 2000, 2000);
		c5->Divide(5,4,0.0001,0.0001); //x=5 y =2 i think this allows for row 1 = em r2 = had 
			
			gPad-> SetLogy();											//for(int iside = 0; iside < 2; iside++)
			//////////////////	
			//NEG EM AND HAD//
			//////////////////
			 // ERIC NOTE I CAN PROBABLY SHRINK THIS WITH A SWItCH STATEMENT FOR DETECTOR TYPE
		      //I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 1; i < 6; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDC[0][0][i-1]->Draw(); //EM?
				  }
				 // for(int ich = 0; ich < 5; ich++)
				  for(int i = 6; i < 11; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDC[0][1][i-6]->Draw(); //HAD?
				  }
			c5->Update();  
			c5->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_fC_ZDC_Negative_%d.png", runnumber));
																					//c5->SaveAs(Form("ZDC_figures/RPD_45456_Ratio_Run/fC_ZDC_%s_%s_channel_%d.png",ttit[itype],stit2[iside],ich+1));
			//////////////////	
			//Pos EM AND HAD//
			//////////////////
			//I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 11; i < 16; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDC[1][0][i-11]->Draw(); //EM?
				  }
				  for(int i = 16; i < 21; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDC[1][1][i-16]->Draw(); //HAD?
				  }
			c5->Update();  
			c5->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_fC_ZDC_Positive_%d.png", runnumber));
			
			/////////////////////////////			
			// HAD TRIGGER HISTOGRAMS////
			/////////////////////////////		
			//////////////////	
			//NEG EM AND HAD//
			//////////////////
			 // ERIC NOTE I CAN PROBABLY SHRINK THIS WITH A SWItCH STATEMENT FOR DETECTOR TYPE
		      //I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 1; i < 6; i++){//I dont think code will care about this line
					c5->cd(i);
					gPad->SetLogy();					
					fC_ZDCHT[0][0][i-1]->Draw(); //EM?
				  }
				 // for(int ich = 0; ich < 5; ich++)
				  for(int i = 6; i < 11; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDCHT[0][1][i-6]->Draw(); //HAD?
				  }
			c5->Update();  
			c5->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_fC_ZDCHT_Negative_%d.png", runnumber));
																					//c5->SaveAs(Form("ZDC_figures/RPD_45456_Ratio_Run/fC_ZDC_%s_%s_channel_%d.png",ttit[itype],stit2[iside],ich+1));
			//////////////////	
			//Pos EM AND HAD//
			//////////////////
			//I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 11; i < 16; i++){//I dont think code will care about this line
					c5->cd(i); 
					gPad->SetLogy();
					fC_ZDCHT[1][0][i-11]->Draw(); //EM?
				  }
				  for(int i = 16; i < 21; i++){//I dont think code will care about this line
					c5->cd(i);
					gPad->SetLogy();					
					fC_ZDCHT[1][1][i-16]->Draw(); //HAD?
				  }
			c5->Update();  
			c5->SaveAs(Form("ZDC_figures/Uncut_v_Cut_HADcut_RPDcut_QBC_327560/HAD_BadSignalSearch_fC_ZDCHT_Positive_%d.png", runnumber));

			f2.Write();

  /*TLegend* leg2 = new TLegend(0.50,0.65,0.70,0.85);
  leg2->SetTextFont(42);
  leg2->SetTextSize(0.033);
  leg2->AddEntry(spectrum,Form("Data, run: %d",runnumber));
  leg2->AddEntry(fit,"Sum of Gaussians:");
  leg2->AddEntry((TObject*)0,"#mu_{n} = n #mu_{0}","0");
  leg2->AddEntry((TObject*)0,"#sigma_{n} = #sqrt{n} #sigma_{0}","0");

  leg2->Draw("same");

  CMS_lumi(c1,0);*/

  return;
}

void initRootStyle(){
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

void BinLogX(TH1* h){
  TAxis *axis = h->GetXaxis();
  int bins = axis->GetNbins();

  Axis_t from = axis->GetXmin();
  Axis_t to = axis->GetXmax();
  Axis_t width = (to - from) / (double) bins;
  Axis_t *new_bins = new Axis_t[bins + 1];

  for (int i = 0; i <= bins; i++){
    new_bins[i] = TMath::Power(10, from + i * width);
  }
  axis->Set(bins, new_bins);
  delete new_bins;
}

