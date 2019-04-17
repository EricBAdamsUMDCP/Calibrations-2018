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
#include <string> //ERIC added in this 

using namespace std;

void initRootStyle();
void BinLogX(TH1*);
double fit_noise(double*, double*);
Double_t sumOfGauss(Double_t*, Double_t*);

TH1F* spectrum_noise;

const double MU = 59.92;

void QBcorrect_basic_dist1DimAddition(int runnumber=286178){
  initRootStyle();

  std::cout << "running SOFTWARE: QBcorrect_basic_dist1DimAddition 3/13/19 10:00" <<  endl;

  writeExtraText = true;       // if extra text
  extraText  = "Preliminary";  // default extra text is "Preliminary"
  lumi_sqrtS = "PbPb 5.02 TeV";       // used with iPeriod = 0, e.g. for simulation-only plots (default is an empty string)
  int iPeriod = 0;

  //TCanvas *c1 = new TCanvas();
  TH1::SetDefaultSumw2();

  // Name of directory to plot
  //TFile *f = new TFile(Form("digitree_%d.root",runnumber)); // opening the root file
  TFile *f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_327560_many.root"); // opening the root file
  //TTree *ZDCRecTree = (TTree*)f->Get("ZDCRecTree"); // reading ZDC rec tree
  TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
  const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
  const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
  const int NCH=5; const char* ctit[NTYPE][NCH] = {
                                                    {"1","2","3","4","5"}, //HD sections run only 1-4   //ERIC NOTE I REMOVED 5 FOR THE HAD THIS MIGHT BREAK THINGS!?!?!
                                                    {"1","2","3","4","5"} //EM sections run 1-5
                                                  };
  
 // TH2F* adc_ZDC[2][2][5];
 // TH2F* adc_RPD[2][16];

  //TH2F* fC_ZDC[2][2][5];
  //TH2F* fC_RPD[2][16];
  // ERIC ADDED ALL THIF* stuff
    TH1F* fC_ZDC[2][2][5];
   TH1F* fC_RPD[2][16];
   

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++)
		  for(int k = 0; k < 5; k++){
		   
			fC_ZDC[i][j][k] = new TH1F(Form("fC ZDC %s%s channel %d",ttit[j],stit[i],k+1),Form("ZDC %s%s channel %d;TS [25 ns];Q [fC]",ttit[j],stit[i],k+1),10,-0.5,9.5); 
		  }

		for(int j = 0; j < 16; j++){
		  
		  fC_RPD[i][j] = new TH1F(Form("fC RPD%s channel %d",stit[i],j+1),Form("RPD%s channel %d;TS [25 ns];Q [fC]",stit[i],j+1),10,-0.5,9.5);
		}

	  }


  const int NTS=10;            // number of timeslices
  TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
  TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
  TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
  TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
  //TLeaf* minbias = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_PAL1MinimumBiasHF_AND_v1");
  TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
  TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
  TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");
  
  TLeaf* adcLeaf[NTS];
  TLeaf* fCleaf[NTS];

//commented out below lines as I believe they fill the actual fc and adc values the section below this one, I believe fills counts
//ERIC NOTE AFTER COMMENTING OUT BELOW DECLARE VARIABLES HERE UNCOMMENTING TO RESOLVE ISSUES
  for(int iTS = 0; iTS < NTS; iTS++){ //REMEMBER TO MODIFY TS DISTRIBUTION FOR ANALYSIS LATER ON SHOULDNT MATTER HERE AS WE WANT TO LOOK AT ALL TIME SLICES
   adcLeaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("adc%d",iTS));
   fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  for(int i = 0; i < ZDCDigiTree->GetEntries(); i++){ //ATTENTION!!!!!!!!!!!! THIS PART IS WHAT GIVES COUNTS THIS IS WHAT I WANT
    ZDCDigiTree->GetEntry(i);
    
    for(int n = 0; n < 50; n++){

      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;

      //int max = 0;
 
      for(int iTS = 0; iTS < 10; iTS++){
        if(type != 3){ // EM or HAD section
				double value = fCleaf[iTS]->GetValue(n);
				if(value < 0){  //!!!! I AM CORRECT THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
          //adc_ZDC[side][type][channel]->Fill(/*iTS,*/adcLeaf[iTS]->GetValue(n)); //filling counts? commented out iTS
				fC_ZDC[side][type][channel]->Fill(iTS,value);          
    //      event->SetBinContent(iTS+1,fCleaf[iTS]->GetValue(n));
        }
        else{ // RPD section
          //if(adcLeaf[iTS]->GetValue(n) > max)
          //  max = adcLeaf[iTS]->GetValue(n);
				double value = fCleaf[iTS]->GetValue(n);
				if(value < 0){  //!!!! I AM CORRECT THIS IF STATEMENT REMOVES NEGATIVE VALUES!!! 
				value = 0;}
          //adc_RPD[side][channel]->Fill(/*iTS,*/adcLeaf[iTS]->GetValue(n)); //filling counts?
				fC_RPD[side][channel]->Fill(iTS,value);
        }
      }

    }

    if(i % 100000 == 0) std::cout << i << " events are processed." << std::endl; 
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////


  TFile f2("basic_dist.root","RECREATE"); //ATTENTION I BELIEVE f2 IS MERELY A VARIABLE NAME AND HAS NO RELATION TO 2 D HISTOGRAMS
  f2.cd();
 

		TCanvas *c1 = new TCanvas("c1", "RUN 327560", 2000, 2000);
		c1->Divide(5,4,0.0001,0.0001); //x=5 y =2 i think this allows for row 1 = em r2 = had 
			
			//gPad-> SetLogy();											//for(int iside = 0; iside < 2; iside++)
			//////////////////	
			//NEG EM AND HAD//
			//////////////////
		      //I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 1; i < 6; i++){//I dont think code will care about this line
					c1->cd(i); 
					//gPad->SetLogy();
					 
					fC_ZDC[0][0][i-1]->Draw("hist e"); //EM?
				  }
				 // for(int ich = 0; ich < 5; ich++)
				  for(int i = 6; i < 11; i++){//I dont think code will care about this line
					c1->cd(i); 
					//gPad->SetLogy();
					fC_ZDC[0][1][i-6]->Draw("hist e"); //HAD?
				 	}
					TLegend* leg2 = new TLegend(0.50,0.65,0.70,0.85);
					leg2->SetTextFont(42);
					  leg2->SetTextSize(0.033);
					  leg2->AddEntry(Form("Data, run: %d",runnumber));
					  leg2->AddEntry("Sum of Gaussians:");
					  leg2->AddEntry((TObject*)0,"#mu_{n} = n #mu_{0}","0");
					  leg2->AddEntry((TObject*)0,"#sigma_{n} = #sqrt{n} #sigma_{0}","0");

						leg2->Draw("same");
						CMS_lumi(c1,0);
			c1->Update();  
			c1->SaveAs(Form("ZDC_figures/QBcorrect_basic_dist1DimAddition/fC_ZDC_NegativeALL327560.png"));

			//////////////////	
			//Pos EM AND HAD//
			//////////////////
			//I believe itype 0 is EM										//for(int itype = 0; itype < 2; itype++)
			  //for(int ich = 0; ich < 5; ich++)
				  for(int i = 11; i < 16; i++){//I dont think code will care about this line
					c1->cd(i); 
				//	gPad->SetLogy();
					fC_ZDC[1][0][i-11]->Draw("hist e"); //EM?
				  }
				  for(int i = 16; i < 21; i++){//I dont think code will care about this line
					c1->cd(i); 
					//gPad->SetLogy();
					fC_ZDC[1][1][i-16]->Draw("hist e"); //HAD?
				  }
			c1->Update();  
			c1->SaveAs(Form("ZDC_figures/QBcorrect_basic_dist1DimAddition/fC_ZDC_PositiveALL327560.png"));


		TCanvas *c4 = new TCanvas("c4", "RUN 327560", 2000, 1500);
        gPad-> SetLogy();
		c4->Divide(4,4,0.0001,0.0001); //assumes canvas is called c1 and creates a different canvas c2 then divides canvas into p by p matrix
			//subtract 1 from all channel value bc start at 0
 
  // RPD- channels separately
			c4->cd(1);
			//gPad->SetLogy();
			fC_RPD[0][11]->Draw("hist e");
			c4->cd(2);
			//gPad->SetLogy();
			fC_RPD[0][15]->Draw("hist e");
			c4->cd(3);
			//gPad->SetLogy();
			fC_RPD[0][2]->Draw("hist e");
			c4->cd(4);
			//gPad->SetLogy();
			fC_RPD[0][6]->Draw("hist e");
			c4->cd(5);
			//gPad->SetLogy();
			fC_RPD[0][8]->Draw("hist e");
			c4->cd(6);
			//gPad->SetLogy();
			fC_RPD[0][12]->Draw("hist e");
			c4->cd(7);
			//gPad->SetLogy();
			fC_RPD[0][2]->Draw("hist e");
			c4->cd(8);
			//gPad->SetLogy();
			fC_RPD[0][5]->Draw("hist e");
			c4->cd(9);
			//gPad->SetLogy();
			fC_RPD[0][9]->Draw("hist e");
			c4->cd(10);
			//gPad->SetLogy();
			fC_RPD[0][13]->Draw("hist e");
			c4->cd(11);
			//gPad->SetLogy();
			fC_RPD[0][0]->Draw("hist e");
			c4->cd(12);
			//gPad->SetLogy();
			fC_RPD[0][4]->Draw("hist e");
			c4->cd(13);
			//gPad->SetLogy();
			fC_RPD[0][10]->Draw("hist e");
			c4->cd(14);
			//gPad->SetLogy();
			fC_RPD[0][14]->Draw("hist e");
			c4->cd(15);
			//gPad->SetLogy();
			fC_RPD[0][3]->Draw("hist e");
			c4->cd(16);
			//gPad->SetLogy();
			fC_RPD[0][7]->Draw("hist e");
			  /* for(int i = 1; i < 17; i++){
				c4->cd(i); //(this sets the current canvas division to canvas divsion i) assumes loop variable is i, and inputs them into the canvas from left to right then down on row
				 fC_RPD[1][i-1]->Draw();
				 c4->Update(); 
			   }*/
			   c4->SaveAs(Form("ZDC_figures/QBcorrect_basic_dist1DimAddition/CORRECTQBLAYOUT_fC_RPD_Minus_channel_ALL_327560.png"));
 
  // RPD+ channels separately
			c4->cd(1);
			//gPad->SetLogy();
			fC_RPD[1][11]->Draw("hist e");
			c4->cd(2);
			//gPad->SetLogy();
			fC_RPD[1][15]->Draw("hist e");
			c4->cd(3);
			//gPad->SetLogy();
			fC_RPD[1][2]->Draw("hist e");
			c4->cd(4);
			//gPad->SetLogy();
			fC_RPD[1][5]->Draw("hist e"); // 5 and 6 are reversed in pos bc of a hardware mis cabling of WLSFibers
			c4->cd(5);
			//gPad->SetLogy();
			fC_RPD[1][8]->Draw("hist e");
			c4->cd(6);
			//gPad->SetLogy();
			fC_RPD[1][12]->Draw("hist e");
			c4->cd(7);
			//gPad->SetLogy();
			fC_RPD[1][2]->Draw("hist e");
			c4->cd(8);
			//gPad->SetLogy();
			fC_RPD[1][6]->Draw("hist e");
			c4->cd(9);
			//gPad->SetLogy();
			fC_RPD[1][9]->Draw("hist e");
			c4->cd(10);
			//gPad->SetLogy();
			fC_RPD[1][13]->Draw("hist e");
			c4->cd(11);
			//gPad->SetLogy();
			fC_RPD[1][0]->Draw("hist e");
			c4->cd(12);
			//gPad->SetLogy();
			fC_RPD[1][4]->Draw("hist e");
			c4->cd(13);
			//gPad->SetLogy();
			fC_RPD[1][10]->Draw("hist e");
			c4->cd(14);
			//gPad->SetLogy();
			fC_RPD[1][14]->Draw("hist e");
			c4->cd(15);
		//	gPad->SetLogy();
			fC_RPD[1][3]->Draw("hist e");
			c4->cd(16);
			//gPad->SetLogy();
			fC_RPD[1][7]->Draw("hist e");
			   /*//4x4 for RPD + <-------------!!!!!!!
			   for(int i = 1; i < 17; i++){
				c4->cd(i); //(this sets the current canvas division to canvas divsion i) assumes loop variable is i, and inputs them into the canvas from left to right then down on row
				 fC_RPD[0][i-1]->Draw();
				 c4->Update(); 
			   }*/
			   c4->SaveAs(Form("ZDC_figures/QBcorrect_basic_dist1DimAddition/CORRECTQBLAYOUT_fC_RPD_Plus_channel_ALL_327560.png"));
			   
 
// ERIC turned on so legend appears

 /* TLegend* leg2 = new TLegend(0.50,0.65,0.70,0.85);
  leg2->SetTextFont(42);
  leg2->SetTextSize(0.033);
  leg2->AddEntry(Form("Data, run: %d",runnumber));
  leg2->AddEntry("Sum of Gaussians:");
  leg2->AddEntry((TObject*)0,"#mu_{n} = n #mu_{0}","0");
  leg2->AddEntry((TObject*)0,"#sigma_{n} = #sqrt{n} #sigma_{0}","0");

  leg2->Draw("same");
  
  CMS_lumi(c1,0);
*/
  return;
}

double fit_noise(double* x, double* p){
  int N = 10;
  double f = 0.0;

  for(int i = 1; i < N; i++)
    f += p[i+2] * TMath::Gaus(x[0],i*p[1],sqrt(i)*p[2],kTRUE);
  
  return p[0]*f + spectrum_noise->Interpolate(x[0]);
}

Double_t sumOfGauss(Double_t* x, Double_t* p){
  int N = 100;
  double f = 0.0;

  for(int i = 1; i < N; i++)
    f += p[i+1] * TMath::Gaus(x[0],i*p[0],sqrt(i)*p[1],kTRUE);
  
  return f;
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
  gStyle->SetCanvasDefW(600);
/*
  gStyle->SetStatX(0.92); // 0.36
  gStyle->SetStatY(0.92);
*/
  //gStyle->SetHistMinimumZero(kTRUE);

  //gStyle->SetErrorX(0); //disable if you want to draw horizontal error bars, e.g. when having variable bin size
  //gStyle->SetEndErrorSize(1); ERIC COmmented out ERROR bars

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

