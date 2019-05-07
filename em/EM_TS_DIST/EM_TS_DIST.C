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

using namespace std;

void initRootStyle();
void BinLogX(TH1*);
double fit_noise(double*, double*);
Double_t sumOfGauss(Double_t*, Double_t*);

TH1F* spectrum_noise;


void EM_TS_DIST(int runnumber=326776){
  initRootStyle();

  int iPeriod = 0;

 
  TH1::SetDefaultSumw2();

cout << "running software EM_TS_DIST.C 5/7/2019 12:30:42 PM" << endl;

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
 
  

  TH1F* em[2][5];
  TH1F* emfC[2][5];

  for(int iside = 0; iside < 2; iside++){
    for(int ich = 0; ich < 5; ich++){
      em[iside][ich]   = new TH1F(Form("em %s %d",stit2[iside],ich+1),Form("EM%s channel %d",stit[iside],ich+1),10,0,9);
      emfC[iside][ich] = new TH1F(Form("emfC %s %d",stit2[iside],ich+1),Form("EMfC%s channel %d",stit[iside],ich+1),500,0,2000);
    }
  }


  const int NTS=10;            // number of timeslices
  TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
  TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
  TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
  TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
  TLeaf* random = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_HIRandom_v1");
  TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
  TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
  TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");
  
  TLeaf* adcLeaf[NTS];
  TLeaf* fCleaf[NTS];

  double w[2][2][5] = {
    {{1.0,1.0,1.0,1.0,1.0},{1.0,0.617/0.4,0.315/0.23,0.259/0.17,0.0}},  // negative side
    {{1.0,1.0,1.0,1.0,1.0},{1.0,0.618,0.315/0.5,0.259/0.33,0.0}}}; // positive side

  for(int iTS = 0; iTS < NTS; iTS++){
    fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  for(int i = 0; i < ZDCDigiTree->GetEntries(); i++){
    ZDCDigiTree->GetEntry(i);


    for(int n = 0; n < 50; n++){
      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;
      if (type == 0){

      double TS_fC[NTS] = {(fCleaf[0]->GetValue(n) <= 0) ? 0 : (fCleaf[0]->GetValue(n)), (fCleaf[1]->GetValue(n) <= 0) ? 0 : (fCleaf[1]->GetValue(n)),
      (fCleaf[2]->GetValue(n) <= 0) ? 0 : (fCleaf[2]->GetValue(n)), (fCleaf[3]->GetValue(n) <= 0) ? 0 : (fCleaf[3]->GetValue(n)), (fCleaf[4]->GetValue(n) <= 0) ? 0 : (fCleaf[4]->GetValue(n)), 
      (fCleaf[5]->GetValue(n) <= 0) ? 0 : (fCleaf[5]->GetValue(n)), (fCleaf[6]->GetValue(n) <= 0) ? 0 : (fCleaf[6]->GetValue(n)), (fCleaf[7]->GetValue(n) <= 0) ? 0 : (fCleaf[7]->GetValue(n)), 
      (fCleaf[8]->GetValue(n) <= 0) ? 0 : (fCleaf[8]->GetValue(n)), (fCleaf[9]->GetValue(n) <= 0) ? 0 : (fCleaf[9]->GetValue(n))};
       

      
        if (side == 0){
          for(int iTS = 0; iTS < 10; iTS++){
             em[side][channel]->Fill(iTS, TS_fC[iTS]); 
             emfC[side][channel]->Fill(TS_fC[iTS]);
          }
        }
        else if (side == 1){
          for(int iTS = 0; iTS < 10; iTS++){
             em[side][channel]->Fill(iTS, TS_fC[iTS]); 
             emfC[side][channel]->Fill(TS_fC[iTS]);
          }
        }
      }
    }

    if(i % 100000 == 0) std::cout << i << " events are processed." << std::endl;
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////


  

  TFile f2("em.root","RECREATE"); 


  TCanvas* c3 = new TCanvas(Form("c3"), Form("RUN_%d", runnumber), 2000, 2000);
  TCanvas* c2 = new TCanvas(Form("c2"), Form("RUN_%d", runnumber), 2000, 2000);

  c2->SetLogy();

  for(int iside = 0; iside < 2; iside++)
    for(int ich = 0; ich < 5; ich++){
      c3->SetLogy();
      em[iside][ich]->SetLineColor(4);
      em[iside][ich]->Draw("hist e");
      c3->SaveAs(Form("ZDC_figures/em/em_%s_channel_%d_%d.png",stit2[iside],ich+1,runnumber));
      f2.Write();
    }
  for(int iside = 0; iside < 2; iside++)
    for(int ich = 0; ich < 5; ich++){
      c2->SetLogy();
      emfC[iside][ich]->SetLineColor(4);
      emfC[iside][ich]->Draw("hist e");
      c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channel_%d_%d.png",stit2[iside],ich+1,runnumber));
      f2.Write();
    }



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

/*void BinLogX(TH1* h){
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
*/
