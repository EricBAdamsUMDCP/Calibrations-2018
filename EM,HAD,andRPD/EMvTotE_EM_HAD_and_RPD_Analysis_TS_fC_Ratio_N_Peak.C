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
#include "/home/ebadams/CMSSW_10_3_3/src/ZDC/analyzeZDCTree/Calibrations/RunWeightHeader/EM_Beam_Position_returns_Value_function.h"

using namespace std;

//void initRootStyle();

/*void BinLogX(TH1*);
double fit_noise(double*, double*);
Double_t sumOfGauss(Double_t*, Double_t*);

TH1F* spectrum_noise;*/


void EM_HAD_and_RPD_Analysis_TS_fC_Ratio_N_Peak(int runnumber=326776){
 
  //initRootStyle();

  int iPeriod = 0;

 
//THE BLOB SEEN WHEN TS 5 IS INCLUDED IS LIKELY FROM AN OUT OF TIME SIGNAL.

  TH1::SetDefaultSumw2();

  
  cout << "running software EM_HAD_and_RPD_Analysis_TS_fC_Ratio_N_Peak.C 6/25/2019 11:49:20 AM" << endl;

  // Name of directory to plot
  //TFile *f = new TFile(Form("digitree_%d.root",runnumber)); // opening the root file
  
  TFile* f = new TFile("/home/ebadams/Merged_Root_Files_PbPb2018/MB_2/326776/PbPb2018_AOD_MinBias2_326776_RPDZDC_merged.root"); // opening root fie (only have 1 uncommented)

  //TFile *f = new TFile("/home/ebadams/CMSSW_10_3_1/src/ZDC/analyzeZDCTree/AOD_zdc_digi_tree_326776_many_3.root"); // opening the root file
  
  //TTree *ZDCRecTree = (TTree*)f->Get("ZDCRecTree"); // reading ZDC rec tree
  TTree *ZDCDigiTree = (TTree*)f->Get("analyzer/zdcdigi"); // reading ZDC digi tree
  const int NSIDE=2; const char* stit[NSIDE] = {"#minus","#plus"};  const char* stit2[NSIDE] = {"neg","pos"};
  const int NTYPE=2; const char* ttit[NTYPE] = {"EM","HAD"};
  const int NCH=5; const char* ctit[NTYPE][NCH] = {
                                                    {"1","2","3","4","5"}, //HD sections run only 1-4
                                                    {"1","2","3","4","5"} //EM sections run 1-5
                                                  };
  double EMmultiplicativevalue = 0.19; 
  double RPDmultiplicativevalue = 0.0; //BASICALLY ABSORBS NO ENERGY
  double P_ratiovalue = 7.0; //used to be 6
  double N_ratiovalue = 4.0; //used to be 3
  //ratio value for pos is 6 and for neg is 3
  int cutoff = 70; //cutoff of 70 appears to be good
  int graphMaxPos = 50000; //was 5000 this is for coloration test
  int graphMaxNeg = 60000;
  int graphMinPos = 3000;
  int graphMinNeg = 4000;

  TH1F* em[2][5];
  TH1F* emfC[2][5];
  TH1F* HAD[2][4];
  TH1F* HADfC[2][4];
  TH1F* P_HADSUM;
  TH1F* N_HADSUM;
  /*TH1F* RATIOemfC_OnetoThree[2];
  TH1F* RATIOemfC_TwotoThree[2];
  TH1F* RATIOemfC_FourtoThree[2];
  TH1F* RATIOemfC_FivetoThree[2];
  TH2F* RATIOPN_OnetoThree;
  TH2F* RATIOPN_TwotoThree;
  TH2F* RATIOPN_FourtoThree;
  TH2F* RATIOPN_FivetoThree;*/
  TH2F* PEMvTotalE;
  TH2F* NEMvTotalE;
  TH2F* P_45vTotalE;
  TH2F* N_45vTotalE;

  for(int iside = 0; iside < 2; iside++){
    for(int ich = 0; ich < 5; ich++){
      em[iside][ich]   = new TH1F(Form("em %s %d",stit2[iside],ich+1), Form("EM%s channel %d",stit[iside],ich+1),10,0,9);
      //emfC[iside][ich] = new TH1F(Form("emfC %s %d",stit2[iside],ich+1),Form("EMfC%s channel %d fC",stit[iside],ich+1),500,0,2000);
    }
  }

  P_HADSUM = new TH1F(Form("SUMHADP"),Form("P_SUMHAD %d; P_SumHADfC + %f*P_SumEMfC + %f*P_SumRPDfC", runnumber, EMmultiplicativevalue, RPDmultiplicativevalue),200,0,40000);
  N_HADSUM = new TH1F(Form("SUMHADN"),Form("N_SUMHAD %d; N_SumHADfC + %f*N_SumEMfC + %f*N_SumRPDfC", runnumber, EMmultiplicativevalue, RPDmultiplicativevalue),200,0,40000);

  for(int iside = 0; iside < 2; iside++){
    for(int ich = 0; ich < 4; ich++){
      HAD[iside][ich]   = new TH1F(Form("HAD %s %d",stit2[iside],ich+1),Form("HAD%s channel %d",stit[iside],ich+1),10,0,9);
      HADfC[iside][ich] = new TH1F(Form("HADfC %s %d",stit2[iside],ich+1),Form("HADfC%s channel %d fC",stit[iside],ich+1),300,0,400000);
    }
  }

  /*for(int iside = 0; iside < 2; iside++){
        RATIOemfC_OnetoThree[iside]  = new TH1F(Form("emfCRATIO %s 1/3",stit2[iside]),Form("EMfC%s channels 1/3 fC",stit[iside]),40,0,2);
        RATIOemfC_TwotoThree[iside]  = new TH1F(Form("emfCRATIO %s 2/3",stit2[iside]),Form("EMfC%s channels 2/3 fC",stit[iside]),40,0,2);
        RATIOemfC_FourtoThree[iside] = new TH1F(Form("emfCRATIO %s 4/3",stit2[iside]),Form("EMfC%s channels 4/3 fC",stit[iside]),40,0,2);
        RATIOemfC_FivetoThree[iside] = new TH1F(Form("emfCRATIO %s 5/3",stit2[iside]),Form("EMfC%s channels 5/3 fC",stit[iside]),40,0,2);
    }

  RATIOPN_OnetoThree  = new TH2F(("RATIOPN_OnetoThree "),("RATIOPN_OnetoThree; Pos; Neg"),  40, 0, 2, 40, 0, 2);
  RATIOPN_TwotoThree  = new TH2F(("RATIOPN_TwotoThree "),("RATIOPN_TwotoThree; Pos; Neg"),  40, 0, 2, 40, 0, 2);
  RATIOPN_FourtoThree = new TH2F(("RATIOPN_FourtoThree"),("RATIOPN_FourtoThree; Pos; Neg"), 40, 0, 2, 40, 0, 2);
  RATIOPN_FivetoThree = new TH2F(("RATIOPN_FivetoThree"),("RATIOPN_FivetoThree; Pos; Neg"), 40, 0, 2, 40, 0, 2);*/


  PEMvTotalE = new TH2F(Form("PEMvTotalE"),Form("PEMvTotalE ts 4; Sum HAD + %f * EM (fC) + %f*RPD (fC); EM (fC)", EMmultiplicativevalue, RPDmultiplicativevalue), 100, 40, 60000, 100, 50, 80000); //used to be 50
  NEMvTotalE = new TH2F(Form("NEMvTotalE"),Form("NEMvTotalE TS 4; Sum HAD + %f * EM (fC) + %f*RPD (fC); EM (fC)", EMmultiplicativevalue, RPDmultiplicativevalue), 100, 40, 60000, 100, 50, 80000); //nin used to be 700


  P_45vTotalE = new TH2F(Form("P_45vTotalE"),Form("ts4/5 em and had vTotalE ts 4; Sum HAD + %f * EM (fC) + %f*RPD (fC); ts4/5 em and had vTotalE ts 4 (fC)", EMmultiplicativevalue, RPDmultiplicativevalue), 60, 50, 20000, 60, 0, 200);
  N_45vTotalE = new TH2F(Form("N_45vTotalE"),Form("ts4/5 em and had vTotalE TS 4; Sum HAD + %f * EM (fC) + %f*RPD (fC); ts4/5 em and had vTotalE ts 4 (fC)", EMmultiplicativevalue, RPDmultiplicativevalue), 60, 50, 20000, 60, 0, 200);

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

    double EM_TS_45[NSIDE][5] = {0}; //actually just 4
    double HAD_TS_45[NSIDE][4] = {0}; // actually just 4
    double RPD_TS_45[NSIDE][16] = {16}; //4 & 5

    double EM4v5array[2][5] = {0};
    double HAD4v5array[2][4] = {0};

    for(int n = 0; n < 50; n++){
      int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
      int type = (int)(sectionLeaf->GetValue(n))-1;
      int channel = (int)(channelLeaf->GetValue(n))-1;
     

        double TS_fC[NTS] = {(fCleaf[0]->GetValue(n) < cutoff) ? 0 : (fCleaf[0]->GetValue(n)), (fCleaf[1]->GetValue(n) < cutoff) ? 0 : (fCleaf[1]->GetValue(n)),
        (fCleaf[2]->GetValue(n) < cutoff) ? 0 : (fCleaf[2]->GetValue(n)), (fCleaf[3]->GetValue(n) < cutoff) ? 0 : (fCleaf[3]->GetValue(n)), (fCleaf[4]->GetValue(n) < cutoff) ? 0 : (fCleaf[4]->GetValue(n)), 
        (fCleaf[5]->GetValue(n) < cutoff) ? 0 : (fCleaf[5]->GetValue(n)), (fCleaf[6]->GetValue(n) < cutoff) ? 0 : (fCleaf[6]->GetValue(n)), (fCleaf[7]->GetValue(n) < cutoff) ? 0 : (fCleaf[7]->GetValue(n)), 
        (fCleaf[8]->GetValue(n) < cutoff) ? 0 : (fCleaf[8]->GetValue(n)), (fCleaf[9]->GetValue(n) < cutoff) ? 0 : (fCleaf[9]->GetValue(n))};
         

         ///////////////////////////////////////
      //  REMOVING TS 5 FROM THE CODE AS REQUESTEDD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //////////////////////////////////////////////////////////
      
      if (type == 0){
        
        if (side == 0){
          if (TS_fC[4]/TS_fC[5] > N_ratiovalue ){
          EM_TS_45[side][channel] = TS_fC[4]/* + TS_fC[5]*/;
          }
          EM4v5array[side][channel] = TS_fC[4]/TS_fC[5];
          if (TS_fC[4]/TS_fC[5] > N_ratiovalue){
            for(int iTS = 0; iTS < 10; iTS++){
               em[side][channel]->Fill(iTS, TS_fC[iTS]); 
               //emfC[side][channel]->Fill(TS_fC[iTS]);
            }
          }
        }
        else if (side == 1){
          if (TS_fC[4]/TS_fC[5] > P_ratiovalue ){
          EM_TS_45[side][channel] = TS_fC[4]/* + TS_fC[5]*/;
          }
          EM4v5array[side][channel] = TS_fC[4]/TS_fC[5];
          if (TS_fC[4]/TS_fC[5] > P_ratiovalue){
            for(int iTS = 0; iTS < 10; iTS++){
               em[side][channel]->Fill(iTS, TS_fC[iTS]); 
               //emfC[side][channel]->Fill(TS_fC[iTS]);
            }
          }
        }
      }
      if (type == 1){ //HAD
        if (side == 0){
          if (TS_fC[4]/TS_fC[5] > N_ratiovalue){
          HAD_TS_45[side][channel] = TS_fC[4]/* + TS_fC[5]*/;
          }
          HAD4v5array[side][channel] = TS_fC[4]/TS_fC[5];
          for(int iTS = 0; iTS < 10; iTS++){
            if (TS_fC[4]/TS_fC[5] > N_ratiovalue){
              HAD[side][channel]->Fill(iTS, TS_fC[iTS]);
            }
             //HADfC[side][channel]->Fill(TS_fC[iTS]);
          }
        }
        else if (side == 1){
          if (TS_fC[4]/TS_fC[5] > P_ratiovalue){
          HAD_TS_45[side][channel] = TS_fC[4]/* + TS_fC[5]*/;
          }
          HAD4v5array[side][channel] = TS_fC[4]/TS_fC[5];
          if (TS_fC[4]/TS_fC[5] > P_ratiovalue){
            for(int iTS = 0; iTS < 10; iTS++){
               HAD[side][channel]->Fill(iTS, TS_fC[iTS]); 
               //HADfC[side][channel]->Fill(TS_fC[iTS]);
            }
          }
        }
      }
      if (type == 3){
        if (( (TS_fC[4] + TS_fC[5] + TS_fC[6]) > 40) && ( ((TS_fC[4] + TS_fC[5])/(TS_fC[4] + TS_fC[5] + TS_fC[6])) > .8) && (TS_fC[7] <= TS_fC[5]) && 
        (TS_fC[1] / TS_fC[0] < 1000) && (TS_fC[0] != 0)){

          if (side == 0){
            RPD_TS_45[NSIDE][channel] = TS_fC[4] + TS_fC[5];
          }
          else if (side == 1){
            RPD_TS_45[NSIDE][channel] = TS_fC[4] + TS_fC[5];
          }
        }
      }
    }
    //channel 3 is decided to be comparator

////////////////Begin EM/////////////////////////////////////////////////////////////////////////////////////////
  double P_SumEMfC = EM_TS_45[1][0] + EM_TS_45[1][1] + EM_TS_45[1][2] + EM_TS_45[1][3] + EM_TS_45[1][4];
  double N_SumEMfC = EM_TS_45[0][0] + EM_TS_45[0][1] + EM_TS_45[0][2] + EM_TS_45[0][3] + EM_TS_45[0][4];
  double P_sumEM4v5 = EM4v5array[1][0] + EM4v5array[1][1] + EM4v5array[1][2] + EM4v5array[1][3] + EM4v5array[1][4];
  double N_sumEM4v5 = EM4v5array[0][0] + EM4v5array[0][1] + EM4v5array[0][2] + EM4v5array[0][3] + EM4v5array[0][4];
/*  double P_OnetoThree  = (EM_TS_45[1][0]/EM_TS_45[1][2]);
  double P_TwotoThree  = (EM_TS_45[1][1]/EM_TS_45[1][2]);
  double P_FourtoThree = (EM_TS_45[1][3]/EM_TS_45[1][2]);
  double P_FivetoThree = (EM_TS_45[1][4]/EM_TS_45[1][2]);

  if (P_OnetoThree != 1){RATIOemfC_OnetoThree[1]->Fill(P_OnetoThree);}
  if (P_TwotoThree != 1){RATIOemfC_TwotoThree[1]->Fill(P_TwotoThree);}
  if (P_FourtoThree != 1){RATIOemfC_FourtoThree[1]->Fill(P_FourtoThree);}
  if (P_FivetoThree != 1){RATIOemfC_FivetoThree[1]->Fill(P_FivetoThree);}

  double N_OnetoThree  = (EM_TS_45[0][0]/EM_TS_45[0][2]);
  double N_TwotoThree  = (EM_TS_45[0][1]/EM_TS_45[0][2]);
  double N_FourtoThree = (EM_TS_45[0][3]/EM_TS_45[0][2]);
  double N_FivetoThree = (EM_TS_45[0][4]/EM_TS_45[0][2]);
   
  if (N_OnetoThree != 1){RATIOemfC_OnetoThree[0]->Fill(N_OnetoThree);}
  if (N_TwotoThree != 1){RATIOemfC_TwotoThree[0]->Fill(N_TwotoThree);}
  if (N_FourtoThree != 1){RATIOemfC_FourtoThree[0]->Fill(N_FourtoThree);}
  if (N_FivetoThree != 1){RATIOemfC_FivetoThree[0]->Fill(N_FivetoThree);}


  if (P_OnetoThree != 1 && N_OnetoThree != 1)  {RATIOPN_OnetoThree->Fill(P_OnetoThree, N_OnetoThree);}
  if (P_TwotoThree != 1 && N_TwotoThree != 1)  {RATIOPN_TwotoThree->Fill(P_TwotoThree, N_TwotoThree);}
  if (P_FourtoThree != 1 && N_FourtoThree != 1){RATIOPN_FourtoThree->Fill(P_FourtoThree,N_FourtoThree);}
  if (P_FivetoThree != 1 && N_FivetoThree != 1){RATIOPN_FivetoThree->Fill(P_FivetoThree,N_FivetoThree);}*/
  ////////////End EM////////////////////////////////////////////////////////////////////////////////////////////

  ////////////Begin RPD ////////////////////////////////////////////////////////////////////////////////////////
  double P_SumRPDfC = 0;
  for (int i = 0; i <16; i++) {
  P_SumRPDfC += RPD_TS_45[1][i]; 
  }
  
  double N_SumRPDfC = 0;
  for (int i = 0; i <16; i++) {
  N_SumRPDfC += RPD_TS_45[0][i];
  }

  ////////////End RPD //////////////////////////////////////////////////////////////////////////////////////////

  ////////////Begin HAD/////////////////////////////////////////////////////////////////////////////////////////

  double P_SumHADfC = HAD_TS_45[1][0] + HAD_TS_45[1][1] + HAD_TS_45[1][2] + HAD_TS_45[1][3];
  double N_SumHADfC = HAD_TS_45[0][0] + HAD_TS_45[0][1] + HAD_TS_45[0][2] + HAD_TS_45[0][3];
  double P_sumHAD4v5 = HAD4v5array[1][0] + HAD4v5array[1][1] + HAD4v5array[1][2] + HAD4v5array[1][3];
  double N_sumHAD4v5 = HAD4v5array[0][0] + HAD4v5array[0][1] + HAD4v5array[0][2] + HAD4v5array[0][3];

  ////////////End HAD//////////////////////////////////////////////////////////////////////////////////////////

  ////////////Begin HAD and EM (only if both are used)/////////////////////////////////////////////////////////
  
  double N_SUM = N_SumHADfC + EMmultiplicativevalue*N_SumEMfC + N_SumRPDfC*RPDmultiplicativevalue;
  double P_SUM = P_SumHADfC + EMmultiplicativevalue*P_SumEMfC + P_SumRPDfC*RPDmultiplicativevalue;

  if (graphMaxPos > P_SUM && P_SUM > graphMinPos){
    PEMvTotalE->Fill((P_SUM), P_SumEMfC); //0.005
    P_HADSUM->Fill((P_SUM));
    P_45vTotalE->Fill((P_SUM), (P_sumEM4v5 + P_sumHAD4v5));
  }
  
  if ( graphMaxNeg > N_SUM && N_SUM > graphMinNeg){
    NEMvTotalE->Fill((N_SUM), N_SumEMfC); //0.005
    N_HADSUM->Fill((N_SUM));
    N_45vTotalE->Fill((N_SUM), (N_sumEM4v5 + N_sumHAD4v5));
  }
/*
  if (P_SumHADfC > 100){
  P_HADSUM->Fill((P_SumHADfC + .1*P_SumEMfC));
  }
  if (N_SumHADfC > 100){
  N_HADSUM->Fill((N_SumHADfC + .1*N_SumEMfC));
  }*/

  ////////////End HAD and EM (only if both are used)//////////////////////////////////////////////////////////

    if(i % 100000 == 0) std::cout << i << " events are processed." << std::endl;
  }

  ///////////////////////////////////////
  // Formatting and drawing histograms //
  ///////////////////////////////////////


  

  TFile f2("em.root","RECREATE"); 


  
  TCanvas* c2 = new TCanvas(Form("c2"), Form("RUN_%d", runnumber), 2000, 2000);
  
  //TCanvas* c3 = new TCanvas(Form("c3"), Form("RUN_%d", runnumber), 2000, 2000);
  //c3->SetLogy();
 

  c2->SetLogz();
  PEMvTotalE->Draw("Colz");
  c2->SaveAs(Form("ZDC_figures/EM_HAD/PEMvTotalE_%d.png",runnumber));
  NEMvTotalE->Draw("Colz");
  c2->SaveAs(Form("ZDC_figures/EM_HAD/NEMvTotalE_%d.png",runnumber));
  P_45vTotalE->Draw("Colz");
  c2->SaveAs(Form("ZDC_figures/EM_HAD/P_45vTotalE_%d.png",runnumber));
  N_45vTotalE->Draw("Colz");
  c2->SaveAs(Form("ZDC_figures/EM_HAD/N_45vTotalE_%d.png",runnumber));
  
  //c2->SetLogy();

  P_HADSUM->Draw("HIST L");
  c2->SaveAs(Form("ZDC_figures/had/SUMHAD_%s_%d.png", stit2[1],runnumber));
  // TCanvas* c4 = new TCanvas(Form("c4"), Form("RUN_%d", runnumber), 2000, 2000);
  // c4->SetLogy();
  N_HADSUM->Draw("HIST L");
  c2->SaveAs(Form("ZDC_figures/had/SUMHAD_%s_%d.png", stit2[0],runnumber));



 /* for(int iside = 0; iside < 2; iside++) //uncomment to get graphs
    for(int ich = 0; ich < 5; ich++){
      
      em[iside][ich]->SetLineColor(4);
      em[iside][ich]->Draw("hist e");
      c2->SaveAs(Form("ZDC_figures/em/em_%s_channel_%d_%d.png",stit2[iside],ich+1,runnumber));
      //f2.Write();
    }*/
/*  for(int iside = 0; iside < 2; iside++) //uncomment to get graphs
    for(int ich = 0; ich < 5; ich++){
      c2->SetLogy();
      emfC[iside][ich]->SetLineColor(4);
      emfC[iside][ich]->Draw("hist e");
      c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channel_%d_%d.png",stit2[iside],ich+1,runnumber));
      f2.Write();
    }
*/

                                       /*RATIOemfC_OnetoThree[1]->Draw("hist e"); //uncomment to get graphs
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels1by3_%d.png", "Pos",runnumber));
                                       RATIOemfC_TwotoThree[1]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels2by3_%d.png", "Pos",runnumber));
                                       RATIOemfC_FourtoThree[1]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels4by3_%d.png", "Pos",runnumber));
                                       RATIOemfC_FivetoThree[1]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels5by3_%d.png", "Pos",runnumber));


                                       RATIOemfC_OnetoThree[0]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels1by3_%d.png", "Neg",runnumber));
                                       RATIOemfC_TwotoThree[0]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels2by3_%d.png", "Neg",runnumber));
                                       RATIOemfC_FourtoThree[0]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels4by3_%d.png", "Neg",runnumber));
                                       RATIOemfC_FivetoThree[0]->Draw("hist e");
                                       c2->SaveAs(Form("ZDC_figures/em/emfC_%s_channels5by3_%d.png", "Neg",runnumber));

                                       RATIOPN_OnetoThree->Draw("colz");
                                       c2->SaveAs(Form("ZDC_figures/em/RATIOPN_OnetoThree_%d.png",runnumber));
                                       RATIOPN_TwotoThree->Draw("colz");
                                       c2->SaveAs(Form("ZDC_figures/em/RATIOPN_TwotoThree_%d.png",runnumber));
                                       RATIOPN_FourtoThree->Draw("colz");
                                       c2->SaveAs(Form("ZDC_figures/em/RATIOPN_FourtoThree_%d.png",runnumber));
                                       RATIOPN_FivetoThree->Draw("colz");
                                       c2->SaveAs(Form("ZDC_figures/em/RATIOPN_FivetoThree_%d.png",runnumber));
                                      */

/*  for(int iside = 0; iside < 2; iside++){ //uncomment to get graphs
    for(int ich = 0; ich < 4; ich++){
      HAD[iside][ich]->Draw("");
      c2->SaveAs(Form("ZDC_figures/had/HAD_%s_TS_%d_%d.png", stit2[iside], ich+1,runnumber));
      HADfC[iside][ich]->Draw("");
      c2->SaveAs(Form("ZDC_figures/had/HAD_%s_fC_%d_%d.png", stit2[iside], ich+1,runnumber));
    }
  }*/

 





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
/*
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
*/
// void initRootStyle(){
//   //  using namespace RooFit ;
// 
//   gROOT->SetStyle("Plain");
//   gStyle->SetPalette(1);
//   gStyle->SetOptStat(1);
//   gStyle->SetOptTitle(1);
//   gStyle->SetOptFit(1);
// 
//   gStyle->SetTitleBorderSize(0);
//   gStyle->SetTitleFillColor(0);
//   gStyle->SetStatColor(0);
// 
//   gStyle->SetFrameBorderMode(0);
//   gStyle->SetFrameFillColor(0);
//   gStyle->SetFrameLineColor(kBlack);
// 
//   gStyle->SetCanvasColor(0);
//   gStyle->SetCanvasBorderMode(0);
//   gStyle->SetCanvasBorderSize(0);
// 
//   gStyle->SetPadColor(0);
//   gStyle->SetPadBorderMode(0);
//   gStyle->SetPadBorderSize(0);
// 
//   gStyle->SetLegendBorderSize(0);
//   //gStyle->SetTextSize(0.04);
//   gStyle->SetTextFont(42);
//   gStyle->SetLabelFont(42,"xyz");
//   gStyle->SetTitleFont(42,"xyz");
//   gStyle->SetTitleSize(0.05,"xyz");
//   gStyle->SetPadBottomMargin(0.13);
//   gStyle->SetPadTopMargin(0.10);
//   gStyle->SetPadRightMargin(0.12); // 0.10
//   gStyle->SetPadLeftMargin(0.15); // 0.12
// 
//   gStyle->SetTitleXOffset(1.1);
//   gStyle->SetTitleYOffset(1.5); // 1.2
// 
//   gStyle->SetPadTickX(1);
//   gStyle->SetPadTickY(1);
// 
//   gStyle->SetCanvasDefH(600);
//   gStyle->SetCanvasDefW(1200);
// /*
//   gStyle->SetStatX(0.92); // 0.36
//   gStyle->SetStatY(0.92);
// */
//   //gStyle->SetHistMinimumZero(kTRUE);
// 
//   //gStyle->SetErrorX(0); //disable if you want to draw horizontal error bars, e.g. when having variable bin size
//   gStyle->SetEndErrorSize(1);
// 
//   gStyle->SetMarkerStyle(20);
//   gStyle->SetMarkerColor(2);
//   gStyle->SetMarkerSize(0.2);
// 
//   //gROOT->ForceStyle();
// 
//   std::cout << "ROOT style loaded." << std::endl;
// }

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
