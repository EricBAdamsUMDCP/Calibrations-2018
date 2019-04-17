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

using namespace std;

void initRootStyle();
void BinLogX(TH1*);

const double MU = 59.92;

void RPD_TS_RATIOS_45_456(int runnumber=286178){
  initRootStyle();

  writeExtraText = true;       // if extra text
  extraText  = "Preliminary";  // default extra text is "Preliminary"
  lumi_sqrtS = "PbPb 5.02 TeV";       // used with iPeriod = 0, e.g. for simulation-only plots (default is an empty string)
  int iPeriod = 0;

  TCanvas *c1 = new TCanvas();
  TH1::SetDefaultSumw2();

  // Name of directory to plot
  //TFile *f = new TFile(Form("digitree_%d.root",runnumber)); // opening the root file
  TFile *f = new TFile("AOD_zdc_digi_tree_327560_many.root"); // opening the root file
  //TTree *ZDCRecTree = (TTree*)f->Get("ZDCRecTree"); // reading ZDC rec tree
  TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
  const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
  const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
  const int NCH=5; const char* ctit[NTYPE][NCH] = {
                                                    {"1","2","3","4","5"}, //HD sections run only 1-4
                                                    {"1","2","3","4","5"} //EM sections run 1-5
                                                  };
 

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
 //END declaring histograms 


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


  for(int iTS=0; iTS < NTS; iTS++){
    //adcLeaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("adc%d",iTS));
    fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  
  for(int i = 0; i < ZDCDigiTree->GetEntries(); i++){
    ZDCDigiTree->GetEntry(i);
//declaring variables to hold channel charge for 45 and 456 for all RPD pos and neg
    //Pos
	double RPD_Pos_1_45, RPD_Pos_2_45, RPD_Pos_3_45, RPD_Pos_4_45, RPD_Pos_5_45, RPD_Pos_6_45, RPD_Pos_7_45, RPD_Pos_8_45, RPD_Pos_9_45, RPD_Pos_10_45, RPD_Pos_11_45, RPD_Pos_12_45, RPD_Pos_13_45, RPD_Pos_14_45, RPD_Pos_15_45, RPD_Pos_16_45;
	double RPD_Pos_1_456, RPD_Pos_2_456, RPD_Pos_3_456, RPD_Pos_4_456, RPD_Pos_5_456, RPD_Pos_6_456, RPD_Pos_7_456, RPD_Pos_8_456, RPD_Pos_9_456, RPD_Pos_10_456, RPD_Pos_11_456, RPD_Pos_12_456, RPD_Pos_13_456, RPD_Pos_14_456, RPD_Pos_15_456, RPD_Pos_16_456;
	//Neg
    double RPD_Neg_1_45, RPD_Neg_2_45, RPD_Neg_3_45, RPD_Neg_4_45, RPD_Neg_5_45, RPD_Neg_6_45, RPD_Neg_7_45, RPD_Neg_8_45, RPD_Neg_9_45, RPD_Neg_10_45, RPD_Neg_11_45, RPD_Neg_12_45, RPD_Neg_13_45, RPD_Neg_14_45, RPD_Neg_15_45, RPD_Neg_16_45;
	double RPD_Neg_1_456, RPD_Neg_2_456, RPD_Neg_3_456, RPD_Neg_4_456, RPD_Neg_5_456, RPD_Neg_6_456, RPD_Neg_7_456, RPD_Neg_8_456, RPD_Neg_9_456, RPD_Neg_10_456, RPD_Neg_11_456, RPD_Neg_12_456, RPD_Neg_13_456, RPD_Neg_14_456, RPD_Neg_15_456, RPD_Neg_16_456;
    
	//For loop for filling signal 45
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
		  double signal45 = fCleaf[4]->GetValue(n) + fCleaf[5]->GetValue(n);
		  double signal456 = fCleaf[4]->GetValue(n) + fCleaf[5]->GetValue(n) + fCleaf[6]->GetValue(n);

		  
		  if(type == 3){ // RPD section // only for signal456
			if(side == 1){
			  switch(channel){ //may have a channel issue only go up to 5? EA 3/6/19 3:09
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
	//end filling histogram pointers

    if(i % 100000 == 0) std::cout << i << " events are processed." << std::endl;
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////

  //c1->SetLogy();

  TFile f2("ratio.root","RECREATE"); 

    //pos drawing and saving histos
		RPD45456_CH1_Pos->SetLineColor(4);
		RPD45456_CH1_Pos->Draw("hist e");
		RPD45456_CH1_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH1_Pos.png");
		
		RPD45456_CH2_Pos->SetLineColor(4);
		RPD45456_CH2_Pos->Draw("hist e");
		RPD45456_CH2_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH2_Pos.png");
		
		RPD45456_CH3_Pos->SetLineColor(4);
		RPD45456_CH3_Pos->Draw("hist e");
		RPD45456_CH3_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH3_Pos.png");
		
		RPD45456_CH4_Pos->SetLineColor(4);
		RPD45456_CH4_Pos->Draw("hist e");
		RPD45456_CH4_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH4_Pos.png");
		
		RPD45456_CH5_Pos->SetLineColor(4);
		RPD45456_CH5_Pos->Draw("hist e");
		RPD45456_CH5_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH5_Pos.png");
		
		RPD45456_CH6_Pos->SetLineColor(4);
		RPD45456_CH6_Pos->Draw("hist e");
		RPD45456_CH6_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH6_Pos.png");
		
		RPD45456_CH7_Pos->SetLineColor(4);
		RPD45456_CH7_Pos->Draw("hist e");
		RPD45456_CH7_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH7_Pos.png");
		
		RPD45456_CH8_Pos->SetLineColor(4);
		RPD45456_CH8_Pos->Draw("hist e");
		RPD45456_CH8_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH8_Pos.png");
		
		RPD45456_CH9_Pos->SetLineColor(4);
		RPD45456_CH9_Pos->Draw("hist e");
		RPD45456_CH9_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH9_Pos.png");
		
		RPD45456_CH10_Pos->SetLineColor(4);
		RPD45456_CH10_Pos->Draw("hist e");
		RPD45456_CH10_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH10_Pos.png");
		
		RPD45456_CH11_Pos->SetLineColor(4);
		RPD45456_CH11_Pos->Draw("hist e");
		RPD45456_CH11_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH11_Pos.png");
		
		RPD45456_CH12_Pos->SetLineColor(4);
		RPD45456_CH12_Pos->Draw("hist e");
		RPD45456_CH12_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH12_Pos.png");
		
		RPD45456_CH13_Pos->SetLineColor(4);
		RPD45456_CH13_Pos->Draw("hist e");
		RPD45456_CH13_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH13_Pos.png");
		
		RPD45456_CH14_Pos->SetLineColor(4);
		RPD45456_CH14_Pos->Draw("hist e");
		RPD45456_CH14_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH14_Pos.png");
		
		RPD45456_CH15_Pos->SetLineColor(4);
		RPD45456_CH15_Pos->Draw("hist e");
		RPD45456_CH15_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH15_Pos.png");
		
		RPD45456_CH16_Pos->SetLineColor(4);
		RPD45456_CH16_Pos->Draw("hist e");
		RPD45456_CH16_Pos->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH16_Pos.png");
	
	/////////////////////////////////
	//Neg drawing and saving histos//
	/////////////////////////////////
	
		RPD45456_CH1_Neg->SetLineColor(4);
		RPD45456_CH1_Neg->Draw("hist e");
		RPD45456_CH1_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH1_Neg.png");
		
		RPD45456_CH2_Neg->SetLineColor(4);
		RPD45456_CH2_Neg->Draw("hist e");
		RPD45456_CH2_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH2_Neg.png");
		
		RPD45456_CH3_Neg->SetLineColor(4);
		RPD45456_CH3_Neg->Draw("hist e");
		RPD45456_CH3_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH3_Neg.png");
		
		RPD45456_CH4_Neg->SetLineColor(4);
		RPD45456_CH4_Neg->Draw("hist e");
		RPD45456_CH4_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH4_Neg.png");
		
		RPD45456_CH5_Neg->SetLineColor(4);
		RPD45456_CH5_Neg->Draw("hist e");
		RPD45456_CH5_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH5_Neg.png");
		
		RPD45456_CH6_Neg->SetLineColor(4);
		RPD45456_CH6_Neg->Draw("hist e");
		RPD45456_CH6_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH6_Neg.png");
		
		RPD45456_CH7_Neg->SetLineColor(4);
		RPD45456_CH7_Neg->Draw("hist e");
		RPD45456_CH7_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH7_Neg.png");
		
		RPD45456_CH8_Neg->SetLineColor(4);
		RPD45456_CH8_Neg->Draw("hist e");
		RPD45456_CH8_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH8_Neg.png");
		
		RPD45456_CH9_Neg->SetLineColor(4);
		RPD45456_CH9_Neg->Draw("hist e");
		RPD45456_CH9_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH9_Neg.png");
		
		RPD45456_CH10_Neg->SetLineColor(4);
		RPD45456_CH10_Neg->Draw("hist e");
		RPD45456_CH10_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH10_Neg.png");
		
		RPD45456_CH11_Neg->SetLineColor(4);
		RPD45456_CH11_Neg->Draw("hist e");
		RPD45456_CH11_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH11_Neg.png");
		
		RPD45456_CH12_Neg->SetLineColor(4);
		RPD45456_CH12_Neg->Draw("hist e");
		RPD45456_CH12_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH12_Neg.png");
		
		RPD45456_CH13_Neg->SetLineColor(4);
		RPD45456_CH13_Neg->Draw("hist e");
		RPD45456_CH13_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH13_Neg.png");
		
		RPD45456_CH14_Neg->SetLineColor(4);
		RPD45456_CH14_Neg->Draw("hist e");
		RPD45456_CH14_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH14_Neg.png");
		
		RPD45456_CH15_Neg->SetLineColor(4);
		RPD45456_CH15_Neg->Draw("hist e");
		RPD45456_CH15_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH15_Neg.png");
		
		RPD45456_CH16_Neg->SetLineColor(4);
		RPD45456_CH16_Neg->Draw("hist e");
		RPD45456_CH16_Neg->Write();
		c1->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CH16_Neg.png");
	
	//now add to 4x4 note this is not a loop to be edited later to accomodate the true ordering of the quartz blocks
	
	//Now adding in division canvas and does not need a histogram but will be saved as an image
	TCanvas *c2 = new TCanvas("c2", ";45/456 ALL Pos RUN 327560;");
	c2->Divide(4,4); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
		c2->cd(1);
			RPD45456_CH1_Pos->Draw("hist e");
			c2->cd(2);
			RPD45456_CH2_Pos->Draw("hist e");
			c2->cd(3);
			RPD45456_CH3_Pos->Draw("hist e");
			c2->cd(4);
			RPD45456_CH4_Pos->Draw("hist e");
			c2->cd(5);
			RPD45456_CH5_Pos->Draw("hist e");
			c2->cd(6);
			RPD45456_CH6_Pos->Draw("hist e");
			c2->cd(7);
			RPD45456_CH7_Pos->Draw("hist e");
			c2->cd(8);
			RPD45456_CH8_Pos->Draw("hist e");
			c2->cd(9);
			RPD45456_CH9_Pos->Draw("hist e");
			c2->cd(10);
			RPD45456_CH10_Pos->Draw("hist e");
			c2->cd(11);
			RPD45456_CH11_Pos->Draw("hist e");
			c2->cd(12);
			RPD45456_CH12_Pos->Draw("hist e");
			c2->cd(13);
			RPD45456_CH13_Pos->Draw("hist e");
			c2->cd(14);
			RPD45456_CH14_Pos->Draw("hist e");
			c2->cd(15);
			RPD45456_CH15_Pos->Draw("hist e");
			c2->cd(16);
			RPD45456_CH16_Pos->Draw("hist e");
			c2->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CHALL_Pos.png");

	//neg
	TCanvas *c3 = new TCanvas("c3", ";45/456 ALL Neg RUN 327560;"); // because we are not declaring histograms it is necessary to add a 3rd canvas
		c3->Divide(4,4);
			c3->cd(1);
			RPD45456_CH1_Neg->Draw("hist e");
			c3->cd(2);
			RPD45456_CH2_Neg->Draw("hist e");
			c3->cd(3);
			RPD45456_CH3_Neg->Draw("hist e");
			c3->cd(4);
			RPD45456_CH4_Neg->Draw("hist e");
			c3->cd(5);
			RPD45456_CH5_Neg->Draw("hist e");
			c3->cd(6);
			RPD45456_CH6_Neg->Draw("hist e");
			c3->cd(7);
			RPD45456_CH7_Neg->Draw("hist e");
			c3->cd(8);
			RPD45456_CH8_Neg->Draw("hist e");
			c3->cd(9);
			RPD45456_CH9_Neg->Draw("hist e");
			c3->cd(10);
			RPD45456_CH10_Neg->Draw("hist e");
			c3->cd(11);
			RPD45456_CH11_Neg->Draw("hist e");
			c3->cd(12);
			RPD45456_CH12_Neg->Draw("hist e");
			c3->cd(13);
			RPD45456_CH13_Neg->Draw("hist e");
			c3->cd(14);
			RPD45456_CH14_Neg->Draw("hist e");
			c3->cd(15);
			RPD45456_CH15_Neg->Draw("hist e");
			c3->cd(16);
			RPD45456_CH16_Neg->Draw("hist e");
			c3->SaveAs("ZDC_figures/RPD_45456_Ratio_Run/RPD45456_CHALL_Neg.png");

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
  gStyle->SetOptStat(0);
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

