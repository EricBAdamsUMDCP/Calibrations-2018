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
double fit_noise(double*, double*);
Double_t sumOfGauss(Double_t*, Double_t*);

TH1F* spectrum_noise;

const double MU = 59.92;

void Weighted_EM_average(int runnumber=326776){
  initRootStyle();
  cout << "Running SOFTWARE: Weighted_EM_average.C 3/15/19 3:49" << endl;
  cout << "Runnumber=" << runnumber << " many 3" << endl;
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
  
  TH1F* Weighted_average_EM[2][2];
  //TH1F* average_RPD[2][16];

  for(int iside = 0; iside < 2; iside++)
    for(int itype = 0; itype < 2; itype++){
        Weighted_average_EM[iside][itype] = new TH1F(Form("Weighted_average_%s%s",ttit[itype],stit2[iside]),Form("%s%s_%d; Channel ;Entries",ttit[itype],stit[iside],runnumber),500,1,5); // was 0 and 6 before
      }

    //for(int ich = 0; ich < 16; ich++){
    //  average_RPD[iside][ich] = new TH1F(Form("average_RPD%s_channel_%d",stit[iside],ich+1),Form("RPD%s channel %d;#bar{T} [ns];Entries",stit[iside],ich+1),500,3,8);
   // }

  double EMChannel0P, EMChannel1P, EMChannel2P, EMChannel3P, EMChannel4P;
  double EMChannel0N, EMChannel1N, EMChannel2N, EMChannel3N, EMChannel4N;

  TH1F* event = new TH1F("",";EM ch_%d; Q [fC]",10,1,5); //was 0 and 6 before

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

  for(int iTS = 0; iTS < NTS; iTS++){
    adcLeaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("adc%d",iTS));
    fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  for(int i = 0; i < ZDCDigiTree->GetEntries(); i++){
    ZDCDigiTree->GetEntry(i);
	EMChannel4P = 0;/////
    if(i % 100000 == 0){
      std::cerr << std::endl;
      std::cerr << i << " events are processed.";
    }
    if(i % 10000 == 0) std::cerr << ".";

    for(int n = 0; n < 50; n++){

      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;

	  double sumEMPos = 0.0, SumEMNeg = 0.0, sumWeightEMPos = 0.0, sumWeightEMNeg = 0.0;
	  double Four = fCleaf[4]->GetValue(n); 
	  double Five = fCleaf[5]->GetValue(n);
		//if(Four<0) {Four = 0.0;}
		//if(Five<0) {Five = 0.0;}

      if(type == 0){ // EM section
        if(side == 1){
			switch(channel){
				case 0:
					if( Four >100 && Five > 100){
					EMChannel0P =  Four + Five;}
					break;
				case 1:
					if( Four >100 && Five > 100){
					EMChannel1P =  Four + Five;}
					break;
				case 2:
					if( Four >100 && Five > 100){
					EMChannel2P =  Four + Five;}
					break;
				case 3:
					if( Four >100 && Five > 100){
					EMChannel3P =  Four + Five;}
					break;
				case 4:
					if( Four >100 && Five > 100){
					EMChannel4P =  Four + Five;}
					break;
			}
		}
		else {
			switch(channel){
				case 0:
					if( Four >100 && Five > 100){
					EMChannel0N=  Four + Five;}
					break;
				case 1:
					if( Four >100 && Five > 100){
					EMChannel1N =  Four + Five;}
					break;
				case 2:
					if( Four >100 && Five > 100){
					EMChannel2N =  Four + Five;}
					break;
				case 3:
					if( Four >100 && Five > 100){
					EMChannel3N =  Four + Five;}
					break;
				case 4:
					if( Four >100 && Five > 100){
					EMChannel4N =  Four + Five;}
					break;
			}
		}
				 
		
       }
	}
			double sumEMPos = EMChannel0P + EMChannel1P + EMChannel2P + EMChannel3P + EMChannel4P;
			double sumEMNeg = EMChannel0N + EMChannel1N + EMChannel2N + EMChannel3N + EMChannel4N;
			double sumWeightEMPos =  (EMChannel0P*1) + (EMChannel1P*2) + (EMChannel2P*3) + (EMChannel3P*4) + (EMChannel4P*5);
			double sumWeightEMNeg =  (EMChannel0N*1) + (EMChannel1N*2) + (EMChannel2N*3) + (EMChannel3N*4) + (EMChannel4N*5);
			Weighted_average_EM[1][0]-> Fill(sumWeightEMPos/sumEMPos);
			Weighted_average_EM[0][0]-> Fill(sumWeightEMNeg/sumEMNeg);
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////


  TFile f2("average.root","RECREATE");
  f2.cd();

  //c1->SetLogy();
 // c1->SetLogz();

 /* TF1* gauss = new TF1("gauss","gaus(0)",0,6);
  gauss->SetParLimits(0,0,10000);
  gauss->SetParLimits(1,4,6);
 
  gauss->SetLineWidth(2);
  gauss->SetLineColor(2);
  gauss->SetLineStyle(1);
  */

  for(int iside = 0; iside < 2; iside++)
    for(int itype = 0; itype < 2; itype++){
        Weighted_average_EM[iside][itype]->SetMarkerColor(1);
        Weighted_average_EM[iside][itype]->SetMarkerSize(0.75);
        Weighted_average_EM[iside][itype]->SetMarkerStyle(20);

       // Weighted_average_EM[iside][0]->Fit("gauss","0 R");
       // Weighted_average_EM[iside][0]->Draw("p e");
    //    gauss->Draw("l same");
		if(iside == 0){
        Weighted_average_EM[0][0]->Fit("gauss","0 R");
        Weighted_average_EM[0][0]->Draw("p e");
		c1->SaveAs(Form("ZDC_figures/average/average_ZDC_%s_%s.png",ttit[0],stit2[0]));
        Weighted_average_EM[0][0]->Write();}
		
		
		/*if(iside == 1){
			TCanvas *c2 = new TCanvas(); /////////////////////////////////////////UNCOMMENT THIS TO GET POS IM GETTING 2 GRAPHS FOR + I DONT KNOW WHY
			 Weighted_average_EM[1][0]->Fit("gauss","0 R");
			 Weighted_average_EM[1][0]->Draw("p e");
			 c2->SaveAs(Form("ZDC_figures/average/average_ZDC_%s_%s.png",ttit[1],stit2[0]));
			 Weighted_average_EM[1][0]->Write();}*/
        f2.Write();
        
        TLegend* leg2 = new TLegend(0.50,0.65,0.70,0.85);
        leg2->SetTextFont(42);
        leg2->SetTextSize(0.033);
        //leg2->AddEntry((TObject*)0,Form("#mu_{n} = %lf",gauss->GetParameter(1)),"0");
      //  leg2->AddEntry((TObject*)0,Form("#sigma_{n} = %lf",gauss->GetParameter(2)),"0");

        leg2->Draw("same");

        delete leg2;
      }

 /* for(int iside = 0; iside < 2; iside++)
    for(int ich = 0; ich < 16; ich++){
      average_RPD[iside][ich]->SetMarkerColor(1);
      average_RPD[iside][ich]->SetMarkerSize(0.75);
      average_RPD[iside][ich]->SetMarkerStyle(20);
      
      average_RPD[iside][ich]->Fit("gauss","0 R");
      average_RPD[iside][ich]->Draw("p e");
      gauss->Draw("l same");
      
      c1->SaveAs(Form("ZDC_figures/average/average_RPD_%s_channel_%d.png",stit2[iside],ich+1));
      average_RPD[iside][ich]->Write();
      f2.Write();

      TLegend* leg2 = new TLegend(0.50,0.65,0.70,0.85);
      leg2->SetTextFont(42);
      leg2->SetTextSize(0.033);
      leg2->AddEntry((TObject*)0,Form("#mu_{n} = %lf",gauss->GetParameter(1)),"0");
      leg2->AddEntry((TObject*)0,Form("#sigma_{n} = %lf",gauss->GetParameter(2)),"0");

      leg2->Draw("same");

      delete leg2;
    }
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
  gStyle->SetOptStat(1);
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

