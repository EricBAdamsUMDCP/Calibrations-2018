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
#include "TMath.h"
#include "TStyle.h"
#include "TLegend.h"

using namespace std;

#ifndef M_PI
#define M_PI       3.14159265358979323846264338328
#endif

void initRootStyle();

void eventplane(const char* filename="minbias_326483.root", int maxevents = -1){
  initRootStyle();

  TCanvas *c1 = new TCanvas("c1","c1",1600,1600);
  TH1::SetDefaultSumw2();

  const char* figdir = "~/www/zdc/rpddist/";

  // Name of directory to plot
  TFile *f = new TFile(filename); // opening the root file
  TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
  const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
  //const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
  //const int NCH=5; const char* ctit[NTYPE][NCH] = {
  //                                                  {"1","2","3","4","5"}, //HD sections run only 1-4
  //                                                  {"1","2","3","4","5"} //EM sections run 1-5
  //                                                };
  const int NTS=10;            // number of timeslices
  const int NRPD=16;           // number of RPD channels
  float RPDposx[NSIDE][NRPD] = {{ 1, 1, 1, 1,
                                  3, 3, 3, 3,
                                 -3,-3,-3,-3,
                                 -1,-1,-1,-1},{
                                 -1,-1,-1,-1,
                                 -3,-3,-3,-3,
                                  1, 1, 1, 1,
                                  3, 3, 3, 3}};
  float RPDposy[NSIDE][NRPD] = {{-1, 1, 3,-3,
                                 -1, 1, 3,-3,
                                  1,-1,-3, 3,
                                  1,-1,-3, 3},{
                                 -1, 1, 3,-3,
                                 -1, 3, 1,-3,
                                  1,-1,-3, 3,
                                  1,-1,-3, 3}} ;
  float RPDphi[NSIDE][NRPD] = {{0}};
  for(int iside=0;iside<NSIDE;iside++)
    for(int irpd=0;irpd<NRPD;irpd++)
      RPDphi[iside][irpd] = atan2(RPDposy[iside][irpd],RPDposx[iside][irpd]);
  // group gain matching by units of four, within one cable set 
  //float RPDweigths[NSIDE][NRPD] = {{1.56,1.56,1.56,1.56,2.70,2.70,2.70,2.70,0.67,0.67,0.67,0.67,0.67,0.67,0.67,0.67},
  //                                 {0.82,0.82,0.82,0.82,0.80,0.80,0.80,0.80,1.73,1.73,1.73,1.73,1.05,1.05,1.05,1.05}};
  // matching of inner, medium and outer tiles
  float RPDweigths[NSIDE][NRPD] = {{1.33,1.80,1.97,2.20,2.70,2.52,2.83,1.81,0.64,0.50,0.44,1.19,0.89,0.64,0.58,1.01},
                                   {3.78,0.42,1.01,0.64,3.59,2.16,0.48,0.53,2.03,1.15,1.43,2.13,1.16,0.96,0.69,4.73}}; 
  const int NXY = 2; // 2: x,y
  // for recentering calibration, from Qobs distributions
  /*
  float Qobs1_mean[NSIDE][NXY] = {{0}};
  float Qobs2_mean[NSIDE][NXY] = {{0}};
  float Qobs1_sigm[NSIDE][NXY] = {{1}};
  float Qobs2_sigm[NSIDE][NXY] = {{1}};
  */
  float Qobs1_mean[NSIDE][NXY] = {{-0.0462651,0.0724619},{-0.0021875,0.00143645}};
  float Qobs2_mean[NSIDE][NXY] = {{0.0445878,-0.0298416},{-0.00264485,-0.00628399}};
  float Qobs1_sigm[NSIDE][NXY] = {{0.207699,0.150302},{0.201779,0.109041}};
  float Qobs2_sigm[NSIDE][NXY] = {{0.105443,0.131843},{0.118577,0.108464}};

  //TLeaf* bxidLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("bxid");
  TLeaf* zsideLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("zside");
  TLeaf* sectionLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("section");
  TLeaf* channelLeaf = (TLeaf*) ZDCDigiTree->GetLeaf("channel");
  //TLeaf* minbias = (TLeaf*) ZDCDigiTree->GetLeaf("HLT_PAL1MinimumBiasHF_AND_v1");
  //TLeaf* ntrk = (TLeaf*) ZDCDigiTree->GetLeaf("nTrack");
  //TLeaf* nHFneg = (TLeaf*) ZDCDigiTree->GetLeaf("nHFneg");
  //TLeaf* nHFpos = (TLeaf*) ZDCDigiTree->GetLeaf("nHFpos");
  
  TLeaf* adcLeaf[NTS];
  TLeaf* fCleaf[NTS];

  TH1F* EP1dist[NSIDE];
  TH1F* EP2dist[NSIDE];
  TH1F* Qobs1[NSIDE][NXY];
  TH1F* Qobs2[NSIDE][NXY];
  const char* xytit[NXY] = {"x","y"};
  for(int iside=0;iside<NSIDE;iside++)
  {
    EP1dist[iside] = new TH1F(Form("EP1dist_%s",stit2[iside]),"EP_{1} distribution;#Psi_{1};[a.u.]",100,-M_PI,M_PI);
    EP2dist[iside] = new TH1F(Form("EP2dist_%s",stit2[iside]),"EP_{2} distribution;#Psi_{2};[a.u.]",100,-M_PI/2,M_PI/2);
    for(int ixy=0;ixy<2;ixy++)
    {
      Qobs1[iside][ixy] = new TH1F(Form("Qobs1dist_%s_%s",stit2[iside],xytit[ixy]),Form("Q^{obs}_{1,%s}%s distribution;Q^{obs}_{1,%s};[a.u.]",xytit[ixy],stit[iside],xytit[ixy]),100,-6,6);
      Qobs2[iside][ixy] = new TH1F(Form("Qobs2dist_%s_%s",stit2[iside],xytit[ixy]),Form("Q^{obs}_{2,%s}%s distribution;Q^{obs}_{2,%s};[a.u.]",xytit[ixy],stit[iside],xytit[ixy]),100,-6,6);
    }
  }
  TH2F* EP1corr = new TH2F("EP1corr","1st order Event Plane correlation;#Psi_{1,RPD#plus};#Psi_{1,RPD#minus}",100,-M_PI,M_PI,100,-M_PI,M_PI);
  TH2F* EP2corr = new TH2F("EP2corr","2nd order Event Plane correlation;#Psi_{2,RPD#plus};#Psi_{2,RPD#minus}",100,-M_PI/2,M_PI/2,100,-M_PI/2,M_PI/2);

  for(int iTS = 0; iTS < NTS; iTS++){
    adcLeaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("adc%d",iTS));
    fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  int allevents = ZDCDigiTree->GetEntries();
  if(maxevents>allevents || maxevents<1) maxevents = allevents;
  cerr << "Running on " << maxevents << " events (out of " << allevents << ")" << endl;
  for(int i = 0; i < maxevents; i++){
    ZDCDigiTree->GetEntry(i);

    if(i%10000==0 && i>0) cerr << ".";
    if(i%100000==0 && i>0) cerr << " " << i << " events processed." << endl;

    float RPDsignal[NSIDE][NRPD] = {{0}};

    for(int n = 0; n < 50; n++){

      int iside = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int itype = (int)(sectionLeaf->GetValue(n))-1;
      int ichannel = (int)(channelLeaf->GetValue(n))-1;

      if(itype==3)
      {
        RPDsignal[iside][ichannel] = fCleaf[4]->GetValue(n) + fCleaf[5]->GetValue(n);
        if(RPDsignal[iside][ichannel]<0) RPDsignal[iside][ichannel]=0;
        RPDsignal[iside][ichannel] *= RPDweigths[iside][ichannel];
      }
    }
    double EP1psi[NSIDE] = {0};
    double EP2psi[NSIDE] = {0};
    float RPDtotsignal[NSIDE] = {0};
    for(int iside=0;iside<NSIDE;iside++)
    {
      float cos1av = 0;
      float sin1av = 0;
      float cos2av = 0;
      float sin2av = 0;
      for(int irpd=0;irpd<NRPD;irpd++)
      {
        cos1av += cos(1*RPDphi[iside][irpd])*RPDsignal[iside][irpd];
        sin1av += sin(1*RPDphi[iside][irpd])*RPDsignal[iside][irpd];
        cos2av += cos(2*RPDphi[iside][irpd])*RPDsignal[iside][irpd];
        sin2av += sin(2*RPDphi[iside][irpd])*RPDsignal[iside][irpd];
        RPDtotsignal[iside] += RPDsignal[iside][irpd];
      }
      if(RPDtotsignal[iside]>2000)
      {
        float Q1xcorr = (cos1av/RPDtotsignal[iside]-Qobs1_mean[iside][0])/Qobs1_sigm[iside][0];
        float Q1ycorr = (sin1av/RPDtotsignal[iside]-Qobs1_mean[iside][1])/Qobs1_sigm[iside][1];
        float Q2xcorr = (cos2av/RPDtotsignal[iside]-Qobs2_mean[iside][0])/Qobs2_sigm[iside][0];
        float Q2ycorr = (sin2av/RPDtotsignal[iside]-Qobs2_mean[iside][1])/Qobs2_sigm[iside][1];
        Qobs1[iside][0]->Fill(Q1xcorr);
        Qobs1[iside][1]->Fill(Q1ycorr);
        Qobs2[iside][0]->Fill(Q2xcorr);
        Qobs2[iside][1]->Fill(Q2ycorr);
        //RECENTERING
        EP1psi[iside] = atan2(Q1ycorr,Q1xcorr);
        EP2psi[iside] = atan2(Q2ycorr,Q2xcorr)/2;
        EP1dist[iside]->Fill(EP1psi[iside]);
        EP2dist[iside]->Fill(EP2psi[iside]);
      }
    }
    if(RPDtotsignal[0]>2000 && RPDtotsignal[1]>2000)
    {
      EP1corr->Fill(EP1psi[0],EP1psi[1]);
      EP2corr->Fill(EP2psi[0],EP2psi[1]);
    }
  }
  cerr << endl;
  for(int iside=0;iside<NSIDE;iside++)
    for(int ixy=0;ixy<2;ixy++)
    {
      cerr << "Qobs 1 " << xytit[ixy] << " " << stit2[iside] << ": " << Qobs1[iside][ixy]->GetMean() << "\t" << Qobs1[iside][ixy]->GetRMS() << endl;
      cerr << "Qobs 2 " << xytit[ixy] << " " << stit2[iside] << ": " << Qobs2[iside][ixy]->GetMean() << "\t" << Qobs2[iside][ixy]->GetRMS() << endl;
    }


  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////
  c1->Divide(2,2,0.001,0.001);
  c1->cd(1);
  EP1dist[1]->Scale(EP1dist[0]->GetMaximum()/EP1dist[1]->GetMaximum());
  EP1dist[0]->SetMinimum(0);
  EP1dist[0]->Draw();
  EP1dist[1]->SetLineColor(kRed);
  EP1dist[1]->Draw("same");
  c1->cd(3);
  gPad->SetLogz(1);
  EP1corr->Draw("colz");
  c1->cd(2);
  EP2dist[1]->Scale(EP2dist[0]->GetMaximum()/EP2dist[1]->GetMaximum());
  EP2dist[0]->SetMinimum(0);
  EP2dist[0]->Draw();
  EP2dist[1]->SetLineColor(kRed);
  EP2dist[1]->Draw("same");
  c1->cd(4);
  gPad->SetLogz(1);
  EP2corr->Draw("colz");
  c1->Print(Form("%s/eventplane12.png",figdir));

  c1->cd(1);
  Qobs1[0][0]->Draw();
  c1->cd(2);
  Qobs1[0][1]->Draw();
  c1->cd(3);
  Qobs1[1][0]->Draw();
  c1->cd(4);
  Qobs1[1][1]->Draw();
  c1->Print(Form("%s/Qobs1dist.png",figdir));

  c1->cd(1);
  Qobs2[0][0]->Draw();
  c1->cd(2);
  Qobs2[0][1]->Draw();
  c1->cd(3);
  Qobs2[1][0]->Draw();
  c1->cd(4);
  Qobs2[1][1]->Draw();
  c1->Print(Form("%s/Qobs2dist.png",figdir));
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

  cout << "ROOT style loaded." << endl;
}


