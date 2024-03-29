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
#include "TPaveLabel.h" //Eric ADDDED
using namespace std;

void initRootStyle();
void BinLogX(TH1*);

const double MU = 59.92;


void RPDWEIGHTSGEANT_count_v_fC_QBLoop(int runnumber=326776){
  initRootStyle();
 
  //CUTOFF VALUE FOR GENERATING fC VS TS HISTOS SET BELOW//
  double CutOff = .8;////
  //CUTOFF VALUE FOR GENERATING fC VS TS HISTOS SET ABOVE//
  cout << "Running SOFTWARE: RPDWEIGHTSGEANT_count_v_fC_QBLoop.C 4/3/19 3:06" << endl;
  cout << "Dataset=" << " AOD_zdc_digi_tree_326776_many_3" << endl;
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
 //float RPDCorrect[NSIDE][NRPD] = {{11.0, 15.0, 2.0, 6.0, 8.0, 12.0, 1.0, 5.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0}, //neg =0
//								 {11.0, 15.0, 2.0, 5.0, 8.0, 12.0, 1.0, 6.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0}}; //pos =1
								 
 float RPDCorrect[NSIDE][NRPD] = {{11.0, 15.0, 2.0, 6.0, 8.0, 12.0, 1.0, 5.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0}, //neg =0
								 {11.0, 15.0, 2.0, 5.0, 8.0, 12.0, 1.0, 6.0, 9.0, 13.0, 0.0, 4.0, 10.0, 14.0, 3.0, 7.0}}; //pos =1
 
float RPDweigths[NSIDE][NRPD] = {{0.2292, 0.4652, 0.0147, 0.1123, 0.0238, 0.0246, 0.0068, 0.0118, 0.0046, 0.0050, 0.0037, 0.0027, 0.0370, 0.0341, 0.0159, 0.0086}, //neg
                                 {0.2292, 0.4652, 0.0147, 0.1123, 0.0238, 0.0068, 0.0246, 0.0118, 0.0046, 0.0050, 0.0037, 0.0027, 0.0370, 0.0341, 0.0159, 0.0086}}; //pos //these weights are cnstructed from jeffs geant code output for x position + 1 cm and y position 0 approximating the measured beam position of 9.4 and 9.6 cm (side based)
											
 /////////////////////////////////////////
 //DECLARING HISTOGRAMS FOR fC VERSUS TS//
 //////////////////////////////////////// 
   TH1F* fC_RPD[2][16];
   TH1F* fC_RPD_Pure[2][16];
   //THStack* hsZDC[2][2][5]; ///
   THStack* hsRPD[2][16]; ///

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 16; j++){
		  
		  fC_RPD[i][j] = new TH1F(Form("327560 fC RPD%s ch %d",stit[i],j+1),Form("RPD%s channel %d 327560;TS [25 ns];Q [fC]",stit[i],j+1),101,0,500);//
		}
	}
	 

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 16; j++){
		  
		  fC_RPD_Pure[i][j] = new TH1F(Form("327560 fC RPD%s ch %d Pure",stit[i],j+1),Form("RPD%s Pure channel %d 327560;TS [25 ns];Q [fC]",stit[i],j+1),101,0,500);//
		}
	}
//END Histos for fC versus TS//

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//45456 are not channels BUT TIME SLICES SO THIS IS TIME LICES 4 & 5 DIVIDED BY TS 4, 5 , &6!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

	
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
    
	
	// https://i.kym-cdn.com/photos/images/newsfeed/001/393/650/27f.jpg
	//For loop for filling signal 45
    for(int n = 0; n < 50; n++){
      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0); /// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;
		
		//cout << channel << endl;
		
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
	//  double signal456Weight = Four + Five + Six;
	  double signal456Unweight = Four + Five + Six;
      double signal45 = Four + Five;
	  double signal456 = Four + Five + Six;
	
	  

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*for(int iTS = 0; iTS < 10; iTS++){																														//PURE uncut RPD AND ZDC HISTOS
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
        //  fC_RPD_Pure[side][channel]->Fill(signal456Unweight);
        }
      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/	//Fillig ZDC and RPD fC versus TS values// RPD trigger
	if((signal45/signal456 > CutOff) && (Seven  <= Five) && (One/Zero < 1000 && Zero != 0)){ //selecting good event


			if(type == 3){ // RPD section
			  //float signal456Weighted = (signal456Unweight * RPDweigths[side][channel]);
			  //cout << (signal456Weighted / signal456Unweight) << endl;
			  //double WeightedSignal456 = (signal456Weighted); /// /////////////
				
				//fC_RPD[side][channel]->Fill(signal456Weighted);
				fC_RPD[side][channel]->Fill(signal456Unweight, RPDweigths[side][channel]);
			  
				fC_RPD_Pure[side][channel]->Fill(signal456Unweight);
			  
			  ///should be good make 4x4 for both rpds and rearrange channels to correct x and y position
			}
	}
	
	
	//Fillig ZDC and RPD fC versus TS values// HAD Trigger 
	
	
    }


	

    if(i % 1000000 /*added a zero*/== 0) std::cout << i << " events are processed." << std::endl;
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////

  //c1->SetLogy(); // enabeled log scale.

  TFile f2("ratio.root","RECREATE"); 

    
			//RPD + 3/8/19
			//12, 16, 3 ,6
			//9, 13, 2 ,7
		   //10, 14, 1 ,5
		   //11, 15, 4, 8
	
			//RPD - 3/8/19
			//12, 16, 3 ,7
			//9, 13, 2 ,6
		   //10, 14, 1 ,5
		   //11, 15, 4, 8
			
////////////////////////////////////////////////////////////////////////////////////////////////
//CREATING HISTOGRAMS FOR 4x4 and 5x5 for RPD pos and neg and ZDC pos and neg for fC versus TS//
////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *c4 = new TCanvas("c4", "RUN 326776", 2000, 1500);
        gPad-> SetLogy();
		c4->Divide(4,4,0.0001,0.0001); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
			//subtract 1 from all channel value bc start at 0
			int A = 4;
			int B = 2;
			cout << "line before loop" << endl;
			auto* lt = new TLatex();
		
			for(int i =0; i < 2; i++){ //problem for loop refuses to stop
				cout << "line after pos neg loop" << endl;
					for(int j=0 ; j < 16; j++){
								//cout << "A" << endl;
								int v = (RPDCorrect[i][j]);
								c4->cd(RPDCorrect[i][j] + 1);
								 	cout << RPDCorrect[i][j] << endl;						//cout << "A.1" << endl;
								gPad->SetLogy();
								hsRPD[i][j] = new THStack("hsRPD","");
															//cout << "A.2" << endl;
								fC_RPD[i][j/*-1*/]->SetLineColor(B);
															//cout << "B" << endl;
								//fC_RPD[i][j-1]->SetFillStyle(3001);
								//fC_RPD[i][j-1]->SetFillColorAlpha(kRed, 0.35);
								hsRPD[i][j]->Add(fC_RPD[i][j/*-1*/]);
															//cout << "b.1" << endl;
								fC_RPD_Pure[i][j/*-1*/]->SetLineColor(A);
															//cout << "C" << endl;
								//fC_RPD_Pure[i][j-1]->SetFillStyle(3001);
								//fC_RPD_Pure[i][j-1]->SetFillColorAlpha(kBlue, 0.35);
								hsRPD[i][j]->Add(fC_RPD_Pure[i][j/*-1*/]); //->Draw("hist e");
								hsRPD[i][j]->Draw("hist c"); //->Draw("same");
								
								
								
								lt->DrawLatexNDC(0.1,0.5, Form("Channel_%d", j));
								//hs->SetTitle(Form("Channel_%d", j + 1));
					}
					TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
newpad->SetFillStyle(4000);
newpad->Draw();
newpad->cd();
TPaveLabel *title = new TPaveLabel(0.1,0.94,0.9,0.98, Form("%s_%d_RPD_histograms", stit2[i], runnumber));
title->SetFillColor(16);
title->SetTextFont(52);
title->Draw();
				c4->SaveAs(Form("ZDC_figures/GEANT_WEIGHTS/RPD_GEANT_Weights_10_0_%s_ALLQB_%d.png",stit2[i], runnumber));// this is the culprit and caused the loop to keep going
				}
				
			f2.Write();
			cout << "D" << endl;
/*TCanvas *c5 = new TCanvas("c5", "RUN 326776", 2000, 1500);
gPad-> SetLogy();
fC_RPD_Pure[0][8]->Draw("hist c"); //C++ STARS AT ZERO

fC_RPD[0][8]->Draw("same");*/

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

