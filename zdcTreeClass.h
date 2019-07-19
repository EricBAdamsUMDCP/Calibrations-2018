//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jul 19 12:17:32 2019 by ROOT version 6.12/07
// from TTree zdcdigi/v1
// found on file: /store/user/eadams/HIMinimumBias2/merged_rereco_PbPb2018_AOD_MB2_326822/rereco_PbPb2018_AOD_MinBias2_326822_ZDCandTracks_merged.root
//////////////////////////////////////////////////////////

#ifndef zdcTreeClass_h
#define zdcTreeClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

using namespace std;

class zdcTreeClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Int_t           bxid;
   Double_t        Cent;
   Int_t           n;
   Int_t           zside[50];   //[n]
   Int_t           section[50];   //[n]
   Int_t           channel[50];   //[n]
   Int_t           rejected[50];   //[n]
   Int_t           nHF_pos;
   Int_t           nHF_neg;
   Float_t         eHF_pos;
   Float_t         eHF_neg;
   Int_t           nTrack;
   Int_t           nAcceptedTracks;
   Int_t           nPixel;
   vector<double>  *phi;
   vector<double>  *phiError;
   vector<double>  *eta;
   vector<double>  *etaError;
   vector<double>  *Pt;
   vector<double>  *ptError;
   vector<double>  *chi2;
   Int_t           adc0[50];   //[n]
   Float_t         nfC0[50];   //[n]
   Int_t           adc1[50];   //[n]
   Float_t         nfC1[50];   //[n]
   Int_t           adc2[50];   //[n]
   Float_t         nfC2[50];   //[n]
   Int_t           adc3[50];   //[n]
   Float_t         nfC3[50];   //[n]
   Int_t           adc4[50];   //[n]
   Float_t         nfC4[50];   //[n]
   Int_t           adc5[50];   //[n]
   Float_t         nfC5[50];   //[n]
   Int_t           adc6[50];   //[n]
   Float_t         nfC6[50];   //[n]
   Int_t           adc7[50];   //[n]
   Float_t         nfC7[50];   //[n]
   Int_t           adc8[50];   //[n]
   Float_t         nfC8[50];   //[n]
   Int_t           adc9[50];   //[n]
   Float_t         nfC9[50];   //[n]
   Int_t           HLTriggerFirstPath_acc;
   Int_t           HLTriggerFirstPath_psc;
   Int_t           DST_Physics_v7_acc;
   Int_t           DST_Physics_v7_psc;
   Int_t           HLT_EcalCalibration_v4_acc;
   Int_t           HLT_EcalCalibration_v4_psc;
   Int_t           HLT_HcalCalibration_v5_acc;
   Int_t           HLT_HcalCalibration_v5_psc;
   Int_t           HLT_HIPhysics_v1_acc;
   Int_t           HLT_HIPhysics_v1_psc;
   Int_t           HLT_HIPhysicsForZS_v1_acc;
   Int_t           HLT_HIPhysicsForZS_v1_psc;
   Int_t           HLT_HIRandom_v1_acc;
   Int_t           HLT_HIRandom_v1_psc;
   Int_t           AlCa_EcalPhiSymForHI_v1_acc;
   Int_t           AlCa_EcalPhiSymForHI_v1_psc;
   Int_t           HLT_HIHcalNZS_v1_acc;
   Int_t           HLT_HIHcalNZS_v1_psc;
   Int_t           HLT_HIHcalPhiSym_v1_acc;
   Int_t           HLT_HIHcalPhiSym_v1_psc;
   Int_t           AlCa_RPCMuonNormalisationForHI_v1_acc;
   Int_t           AlCa_RPCMuonNormalisationForHI_v1_psc;
   Int_t           AlCa_EcalPi0EBonlyForHI_v1_acc;
   Int_t           AlCa_EcalPi0EBonlyForHI_v1_psc;
   Int_t           AlCa_EcalPi0EEonlyForHI_v1_acc;
   Int_t           AlCa_EcalPi0EEonlyForHI_v1_psc;
   Int_t           AlCa_EcalEtaEBonlyForHI_v1_acc;
   Int_t           AlCa_EcalEtaEBonlyForHI_v1_psc;
   Int_t           AlCa_EcalEtaEEonlyForHI_v1_acc;
   Int_t           AlCa_EcalEtaEEonlyForHI_v1_psc;
   Int_t           HLT_HICentralityVeto_v1_acc;
   Int_t           HLT_HICentralityVeto_v1_psc;
   Int_t           HLT_HICentralityVeto_Beamspot_v1_acc;
   Int_t           HLT_HICentralityVeto_Beamspot_v1_psc;
   Int_t           HLT_HICentralityTag20100_v1_acc;
   Int_t           HLT_HICentralityTag20100_v1_psc;
   Int_t           HLT_HICentralityTag30100_v1_acc;
   Int_t           HLT_HICentralityTag30100_v1_psc;
   Int_t           HLT_HICentralityTag50100_v1_acc;
   Int_t           HLT_HICentralityTag50100_v1_psc;
   Int_t           HLT_HIZeroBias_v1_acc;
   Int_t           HLT_HIZeroBias_v1_psc;
   Int_t           HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_acc;
   Int_t           HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_psc;
   Int_t           HLT_HIMinimumBias_part0_v1_acc;
   Int_t           HLT_HIMinimumBias_part0_v1_psc;
   Int_t           HLT_HIMinimumBias_part1_v1_acc;
   Int_t           HLT_HIMinimumBias_part1_v1_psc;
   Int_t           HLT_HIMinimumBias_part2_v1_acc;
   Int_t           HLT_HIMinimumBias_part2_v1_psc;
   Int_t           HLT_HIMinimumBias_part3_v1_acc;
   Int_t           HLT_HIMinimumBias_part3_v1_psc;
   Int_t           HLT_HIMinimumBias_part4_v1_acc;
   Int_t           HLT_HIMinimumBias_part4_v1_psc;
   Int_t           HLT_HIMinimumBias_part5_v1_acc;
   Int_t           HLT_HIMinimumBias_part5_v1_psc;
   Int_t           HLT_HIMinimumBias_part6_v1_acc;
   Int_t           HLT_HIMinimumBias_part6_v1_psc;
   Int_t           HLT_HIMinimumBias_part7_v1_acc;
   Int_t           HLT_HIMinimumBias_part7_v1_psc;
   Int_t           HLT_HIMinimumBias_part8_v1_acc;
   Int_t           HLT_HIMinimumBias_part8_v1_psc;
   Int_t           HLT_HIMinimumBias_part9_v1_acc;
   Int_t           HLT_HIMinimumBias_part9_v1_psc;
   Int_t           HLT_HIMinimumBias_part10_v1_acc;
   Int_t           HLT_HIMinimumBias_part10_v1_psc;
   Int_t           HLT_HIMinimumBias_part11_v1_acc;
   Int_t           HLT_HIMinimumBias_part11_v1_psc;
   Int_t           HLT_HIMinimumBias_part12_v1_acc;
   Int_t           HLT_HIMinimumBias_part12_v1_psc;
   Int_t           HLT_HIMinimumBias_part13_v1_acc;
   Int_t           HLT_HIMinimumBias_part13_v1_psc;
   Int_t           HLT_HIMinimumBias_part14_v1_acc;
   Int_t           HLT_HIMinimumBias_part14_v1_psc;
   Int_t           HLT_HIMinimumBias_part15_v1_acc;
   Int_t           HLT_HIMinimumBias_part15_v1_psc;
   Int_t           HLT_HIMinimumBias_part16_v1_acc;
   Int_t           HLT_HIMinimumBias_part16_v1_psc;
   Int_t           HLT_HIMinimumBias_part17_v1_acc;
   Int_t           HLT_HIMinimumBias_part17_v1_psc;
   Int_t           HLT_HIMinimumBias_part18_v1_acc;
   Int_t           HLT_HIMinimumBias_part18_v1_psc;
   Int_t           HLT_HIMinimumBias_part19_v1_acc;
   Int_t           HLT_HIMinimumBias_part19_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part0_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part0_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part1_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part1_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part2_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part2_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part3_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part3_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part4_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part4_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part5_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part5_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part6_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part6_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part7_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part7_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part8_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part8_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part9_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part9_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part10_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part10_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part11_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part11_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part12_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part12_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part13_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part13_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part14_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part14_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part15_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part15_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part16_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part16_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part17_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part17_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part18_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part18_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part19_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part19_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part20_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part20_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part21_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part21_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part22_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part22_v1_psc;
   Int_t           HLT_HIMinimumBiasRF_part23_v1_acc;
   Int_t           HLT_HIMinimumBiasRF_part23_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet120Eta5p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet120Eta5p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet40Fwd_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet40Fwd_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Fwd_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Fwd_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Fwd_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Fwd_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Fwd_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Fwd_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet120Fwd_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet120Fwd_v1_psc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton10_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton10_Eta1p5_v1_psc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton20_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton20_Eta1p5_v1_psc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton30_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton30_Eta1p5_v1_psc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton40_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton40_Eta1p5_v1_psc;
   Int_t           HLT_HIIslandPhoton50_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton50_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton50_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton50_Eta1p5_v1_psc;
   Int_t           HLT_HIIslandPhoton60_Eta2p4_v1_acc;
   Int_t           HLT_HIIslandPhoton60_Eta2p4_v1_psc;
   Int_t           HLT_HIIslandPhoton60_Eta1p5_v1_acc;
   Int_t           HLT_HIIslandPhoton60_Eta1p5_v1_psc;
   Int_t           HLT_HIGEDPhoton10_v1_acc;
   Int_t           HLT_HIGEDPhoton10_v1_psc;
   Int_t           HLT_HIGEDPhoton20_v1_acc;
   Int_t           HLT_HIGEDPhoton20_v1_psc;
   Int_t           HLT_HIGEDPhoton30_v1_acc;
   Int_t           HLT_HIGEDPhoton30_v1_psc;
   Int_t           HLT_HIGEDPhoton40_v1_acc;
   Int_t           HLT_HIGEDPhoton40_v1_psc;
   Int_t           HLT_HIGEDPhoton50_v1_acc;
   Int_t           HLT_HIGEDPhoton50_v1_psc;
   Int_t           HLT_HIGEDPhoton60_v1_acc;
   Int_t           HLT_HIGEDPhoton60_v1_psc;
   Int_t           HLT_HIGEDPhoton10_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton10_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton20_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton20_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton30_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton30_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton40_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton40_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton50_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton50_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton60_EB_v1_acc;
   Int_t           HLT_HIGEDPhoton60_EB_v1_psc;
   Int_t           HLT_HIGEDPhoton10_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton10_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton20_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton20_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton30_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton30_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton40_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton40_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton50_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton50_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton60_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton60_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton10_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton10_EB_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton20_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton20_EB_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton30_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton30_EB_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton40_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton40_EB_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton50_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton50_EB_HECut_v1_psc;
   Int_t           HLT_HIGEDPhoton60_EB_HECut_v1_acc;
   Int_t           HLT_HIGEDPhoton60_EB_HECut_v1_psc;
   Int_t           HLT_HIEle10Gsf_v1_acc;
   Int_t           HLT_HIEle10Gsf_v1_psc;
   Int_t           HLT_HIEle15Gsf_v1_acc;
   Int_t           HLT_HIEle15Gsf_v1_psc;
   Int_t           HLT_HIEle20Gsf_v1_acc;
   Int_t           HLT_HIEle20Gsf_v1_psc;
   Int_t           HLT_HIEle30Gsf_v1_acc;
   Int_t           HLT_HIEle30Gsf_v1_psc;
   Int_t           HLT_HIEle40Gsf_v1_acc;
   Int_t           HLT_HIEle40Gsf_v1_psc;
   Int_t           HLT_HIEle50Gsf_v1_acc;
   Int_t           HLT_HIEle50Gsf_v1_psc;
   Int_t           HLT_HIEle15Ele10Gsf_v1_acc;
   Int_t           HLT_HIEle15Ele10Gsf_v1_psc;
   Int_t           HLT_HIEle15Ele10GsfMass50_v1_acc;
   Int_t           HLT_HIEle15Ele10GsfMass50_v1_psc;
   Int_t           HLT_HIDoubleEle10Gsf_v1_acc;
   Int_t           HLT_HIDoubleEle10Gsf_v1_psc;
   Int_t           HLT_HIDoubleEle10GsfMass50_v1_acc;
   Int_t           HLT_HIDoubleEle10GsfMass50_v1_psc;
   Int_t           HLT_HIDoubleEle15Gsf_v1_acc;
   Int_t           HLT_HIDoubleEle15Gsf_v1_psc;
   Int_t           HLT_HIDoubleEle15GsfMass50_v1_acc;
   Int_t           HLT_HIDoubleEle15GsfMass50_v1_psc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_acc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_psc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_acc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_psc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_acc;
   Int_t           HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_psc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_acc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_psc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_acc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_psc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_acc;
   Int_t           HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_psc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_acc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_psc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_acc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_psc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_acc;
   Int_t           HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_psc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_acc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_psc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_acc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_psc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_acc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_psc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_acc;
   Int_t           HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_psc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_acc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_psc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_acc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_psc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_acc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_psc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_acc;
   Int_t           HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_psc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_acc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_psc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_acc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_psc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_acc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_psc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_acc;
   Int_t           HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_psc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_acc;
   Int_t           HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_psc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt20_v1_acc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt20_v1_psc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt30_v1_acc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt30_v1_psc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt40_v1_acc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt40_v1_psc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt50_v1_acc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt50_v1_psc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt60_v1_acc;
   Int_t           HLT_HIDsPPTrackingGlobal_Dpt60_v1_psc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt20_v1_acc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt20_v1_psc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt30_v1_acc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt30_v1_psc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt40_v1_acc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt40_v1_psc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt50_v1_acc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt50_v1_psc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt60_v1_acc;
   Int_t           HLT_HILcPPTrackingGlobal_Dpt60_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt18_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt18_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt24_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt24_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt34_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt34_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt45_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt45_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt56_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt56_v1_psc;
   Int_t           HLT_HIFullTracks2018_HighPt60_v1_acc;
   Int_t           HLT_HIFullTracks2018_HighPt60_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_er1p6_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_er1p6_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_er1p6_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_er1p6_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_psc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_acc;
   Int_t           HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_psc;
   Int_t           HLT_HIL1DoubleMu0_v1_acc;
   Int_t           HLT_HIL1DoubleMu0_v1_psc;
   Int_t           HLT_HIL1DoubleMu10_v1_acc;
   Int_t           HLT_HIL1DoubleMu10_v1_psc;
   Int_t           HLT_HIL2_L1DoubleMu10_v1_acc;
   Int_t           HLT_HIL2_L1DoubleMu10_v1_psc;
   Int_t           HLT_HIL3_L1DoubleMu10_v1_acc;
   Int_t           HLT_HIL3_L1DoubleMu10_v1_psc;
   Int_t           HLT_HIL2DoubleMuOpen_v1_acc;
   Int_t           HLT_HIL2DoubleMuOpen_v1_psc;
   Int_t           HLT_HIL3DoubleMuOpen_v1_acc;
   Int_t           HLT_HIL3DoubleMuOpen_v1_psc;
   Int_t           HLT_HIL3DoubleMuOpen_M60120_v1_acc;
   Int_t           HLT_HIL3DoubleMuOpen_M60120_v1_psc;
   Int_t           HLT_HIL3DoubleMuOpen_JpsiPsi_v1_acc;
   Int_t           HLT_HIL3DoubleMuOpen_JpsiPsi_v1_psc;
   Int_t           HLT_HIL3DoubleMuOpen_Upsi_v1_acc;
   Int_t           HLT_HIL3DoubleMuOpen_Upsi_v1_psc;
   Int_t           HLT_HIL3Mu0_L2Mu0_v1_acc;
   Int_t           HLT_HIL3Mu0_L2Mu0_v1_psc;
   Int_t           HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_acc;
   Int_t           HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_psc;
   Int_t           HLT_HIL1MuOpen_Centrality_70_100_v1_acc;
   Int_t           HLT_HIL1MuOpen_Centrality_70_100_v1_psc;
   Int_t           HLT_HIL1MuOpen_Centrality_80_100_v1_acc;
   Int_t           HLT_HIL1MuOpen_Centrality_80_100_v1_psc;
   Int_t           HLT_HIL2Mu3_NHitQ15_v1_acc;
   Int_t           HLT_HIL2Mu3_NHitQ15_v1_psc;
   Int_t           HLT_HIL2Mu5_NHitQ15_v1_acc;
   Int_t           HLT_HIL2Mu5_NHitQ15_v1_psc;
   Int_t           HLT_HIL2Mu7_NHitQ15_v1_acc;
   Int_t           HLT_HIL2Mu7_NHitQ15_v1_psc;
   Int_t           HLT_HIL3Mu2p5_L1DoubleMu0_v1_acc;
   Int_t           HLT_HIL3Mu2p5_L1DoubleMu0_v1_psc;
   Int_t           HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_acc;
   Int_t           HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_psc;
   Int_t           HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_acc;
   Int_t           HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_psc;
   Int_t           HLT_HIL3Mu3_L1TripleMuOpen_v1_acc;
   Int_t           HLT_HIL3Mu3_L1TripleMuOpen_v1_psc;
   Int_t           HLT_HIL3Mu12_v1_acc;
   Int_t           HLT_HIL3Mu12_v1_psc;
   Int_t           HLT_HIL3Mu15_v1_acc;
   Int_t           HLT_HIL3Mu15_v1_psc;
   Int_t           HLT_HIL3Mu20_v1_acc;
   Int_t           HLT_HIL3Mu20_v1_psc;
   Int_t           HLT_HIL3Mu3_NHitQ10_v1_acc;
   Int_t           HLT_HIL3Mu3_NHitQ10_v1_psc;
   Int_t           HLT_HIL3Mu5_NHitQ10_v1_acc;
   Int_t           HLT_HIL3Mu5_NHitQ10_v1_psc;
   Int_t           HLT_HIL3Mu7_NHitQ10_v1_acc;
   Int_t           HLT_HIL3Mu7_NHitQ10_v1_psc;
   Int_t           HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_acc;
   Int_t           HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_psc;
   Int_t           HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_acc;
   Int_t           HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_psc;
   Int_t           HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc;
   Int_t           HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc;
   Int_t           HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc;
   Int_t           HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF1AND_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF1AND_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity4060_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity4060_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity6080_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity6080_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity80100_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity80100_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity020_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity020_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF1OR_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF1OR_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF2OR_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity020_HF2OR_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_psc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_acc;
   Int_t           HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_psc;
   Int_t           HLT_HIUPC_Mu8_Mu13_v1_acc;
   Int_t           HLT_HIUPC_Mu8_Mu13_v1_psc;
   Int_t           HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_acc;
   Int_t           HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_psc;
   Int_t           HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_acc;
   Int_t           HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_psc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_v1_acc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_v1_psc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_v1_acc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_v1_psc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_v1_acc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_v1_psc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_acc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_psc;
   Int_t           HLT_HICsAK4PFJet120Eta1p5_v1_acc;
   Int_t           HLT_HICsAK4PFJet120Eta1p5_v1_psc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_psc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_psc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_psc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_psc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_psc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_acc;
   Int_t           HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_psc;
   Int_t           HLT_HIL3Mu3_EG10HECut_v1_acc;
   Int_t           HLT_HIL3Mu3_EG10HECut_v1_psc;
   Int_t           HLT_HIL3Mu3_EG15HECut_v1_acc;
   Int_t           HLT_HIL3Mu3_EG15HECut_v1_psc;
   Int_t           HLT_HIL3Mu3_EG20HECut_v1_acc;
   Int_t           HLT_HIL3Mu3_EG20HECut_v1_psc;
   Int_t           HLT_HIL3Mu3_EG30HECut_v1_acc;
   Int_t           HLT_HIL3Mu3_EG30HECut_v1_psc;
   Int_t           HLT_HIL3Mu5_EG10HECut_v1_acc;
   Int_t           HLT_HIL3Mu5_EG10HECut_v1_psc;
   Int_t           HLT_HIL3Mu5_EG15HECut_v1_acc;
   Int_t           HLT_HIL3Mu5_EG15HECut_v1_psc;
   Int_t           HLT_HIL3Mu5_EG20HECut_v1_acc;
   Int_t           HLT_HIL3Mu5_EG20HECut_v1_psc;
   Int_t           HLT_HIL3Mu5_EG30HECut_v1_acc;
   Int_t           HLT_HIL3Mu5_EG30HECut_v1_psc;
   Int_t           HLT_HIL3Mu7_EG10HECut_v1_acc;
   Int_t           HLT_HIL3Mu7_EG10HECut_v1_psc;
   Int_t           HLT_HIL3Mu7_EG15HECut_v1_acc;
   Int_t           HLT_HIL3Mu7_EG15HECut_v1_psc;
   Int_t           HLT_HIL3Mu7_EG20HECut_v1_acc;
   Int_t           HLT_HIL3Mu7_EG20HECut_v1_psc;
   Int_t           HLT_HIL3Mu7_EG30HECut_v1_acc;
   Int_t           HLT_HIL3Mu7_EG30HECut_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc;
   Int_t           HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc;
   Int_t           HLT_HICastor_MediumJet_NotMBHF2AND_v1_acc;
   Int_t           HLT_HICastor_MediumJet_NotMBHF2AND_v1_psc;
   Int_t           HLT_HICastor_MediumJet_NotMBHF2OR_v1_acc;
   Int_t           HLT_HICastor_MediumJet_NotMBHF2OR_v1_psc;
   Int_t           HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_acc;
   Int_t           HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_psc;
   Int_t           HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_acc;
   Int_t           HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_psc;
   Int_t           HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_acc;
   Int_t           HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_psc;
   Int_t           HLT_HICastor_MediumJet_BptxAND_v1_acc;
   Int_t           HLT_HICastor_MediumJet_BptxAND_v1_psc;
   Int_t           HLT_HICastor_MediumJet_v1_acc;
   Int_t           HLT_HICastor_MediumJet_v1_psc;
   Int_t           HLT_HICastor_HighJet_v1_acc;
   Int_t           HLT_HICastor_HighJet_v1_psc;
   Int_t           HLT_HICastor_HighJet_BptxAND_v1_acc;
   Int_t           HLT_HICastor_HighJet_BptxAND_v1_psc;
   Int_t           HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_acc;
   Int_t           HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_psc;
   Int_t           HLT_HICastor_HighJet_NotMBHF2OR_v1_acc;
   Int_t           HLT_HICastor_HighJet_NotMBHF2OR_v1_psc;
   Int_t           HLT_HICastor_HighJet_NotMBHF2AND_v1_acc;
   Int_t           HLT_HICastor_HighJet_NotMBHF2AND_v1_psc;
   Int_t           HLT_HICastor_Muon_v1_acc;
   Int_t           HLT_HICastor_Muon_v1_psc;
   Int_t           HLT_HICastor_Muon_BptxAND_v1_acc;
   Int_t           HLT_HICastor_Muon_BptxAND_v1_psc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_acc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_psc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_acc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_psc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_acc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_psc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_acc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_psc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_acc;
   Int_t           HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_psc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_acc;
   Int_t           HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_psc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_acc;
   Int_t           HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_psc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_acc;
   Int_t           HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_psc;
   Int_t           HLT_HIGEDPhoton10_Cent30_100_v1_acc;
   Int_t           HLT_HIGEDPhoton10_Cent30_100_v1_psc;
   Int_t           HLT_HIGEDPhoton20_Cent30_100_v1_acc;
   Int_t           HLT_HIGEDPhoton20_Cent30_100_v1_psc;
   Int_t           HLT_HIGEDPhoton30_Cent30_100_v1_acc;
   Int_t           HLT_HIGEDPhoton30_Cent30_100_v1_psc;
   Int_t           HLT_HIGEDPhoton40_Cent30_100_v1_acc;
   Int_t           HLT_HIGEDPhoton40_Cent30_100_v1_psc;
   Int_t           HLT_HIGEDPhoton10_Cent50_100_v1_acc;
   Int_t           HLT_HIGEDPhoton10_Cent50_100_v1_psc;
   Int_t           HLT_HIGEDPhoton20_Cent50_100_v1_acc;
   Int_t           HLT_HIGEDPhoton20_Cent50_100_v1_psc;
   Int_t           HLT_HIGEDPhoton30_Cent50_100_v1_acc;
   Int_t           HLT_HIGEDPhoton30_Cent50_100_v1_psc;
   Int_t           HLT_HIGEDPhoton40_Cent50_100_v1_acc;
   Int_t           HLT_HIGEDPhoton40_Cent50_100_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_psc;
   Int_t           HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_acc;
   Int_t           HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_psc;
   Int_t           HLT_HIL1NotBptxOR_v1_acc;
   Int_t           HLT_HIL1NotBptxOR_v1_psc;
   Int_t           HLT_HIL1UnpairedBunchBptxMinus_v1_acc;
   Int_t           HLT_HIL1UnpairedBunchBptxMinus_v1_psc;
   Int_t           HLT_HIL1UnpairedBunchBptxPlus_v1_acc;
   Int_t           HLT_HIL1UnpairedBunchBptxPlus_v1_psc;
   Int_t           HLTriggerFinalPath_acc;
   Int_t           HLTriggerFinalPath_psc;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_bxid;   //!
   TBranch        *b_cent;   //!
   TBranch        *b_n;   //!
   TBranch        *b_zside;   //!
   TBranch        *b_section;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_rejected;   //!
   TBranch        *b_nHF_pos;   //!
   TBranch        *b_nHF_neg;   //!
   TBranch        *b_eHF_pos;   //!
   TBranch        *b_eHF_neg;   //!
   TBranch        *b_nTrack;   //!
   TBranch        *b_nAcceptedTracks;   //!
   TBranch        *b_nPixel;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_phiError;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_etaError;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_ptError;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_adc0;   //!
   TBranch        *b_nfC0;   //!
   TBranch        *b_adc1;   //!
   TBranch        *b_nfC1;   //!
   TBranch        *b_adc2;   //!
   TBranch        *b_nfC2;   //!
   TBranch        *b_adc3;   //!
   TBranch        *b_nfC3;   //!
   TBranch        *b_adc4;   //!
   TBranch        *b_nfC4;   //!
   TBranch        *b_adc5;   //!
   TBranch        *b_nfC5;   //!
   TBranch        *b_adc6;   //!
   TBranch        *b_nfC6;   //!
   TBranch        *b_adc7;   //!
   TBranch        *b_nfC7;   //!
   TBranch        *b_adc8;   //!
   TBranch        *b_nfC8;   //!
   TBranch        *b_adc9;   //!
   TBranch        *b_nfC9;   //!
   TBranch        *b_HLTriggerFirstPath_acc;   //!
   TBranch        *b_HLTriggerFirstPath_psc;   //!
   TBranch        *b_DST_Physics_v7_acc;   //!
   TBranch        *b_DST_Physics_v7_psc;   //!
   TBranch        *b_HLT_EcalCalibration_v4_acc;   //!
   TBranch        *b_HLT_EcalCalibration_v4_psc;   //!
   TBranch        *b_HLT_HcalCalibration_v5_acc;   //!
   TBranch        *b_HLT_HcalCalibration_v5_psc;   //!
   TBranch        *b_HLT_HIPhysics_v1_acc;   //!
   TBranch        *b_HLT_HIPhysics_v1_psc;   //!
   TBranch        *b_HLT_HIPhysicsForZS_v1_acc;   //!
   TBranch        *b_HLT_HIPhysicsForZS_v1_psc;   //!
   TBranch        *b_HLT_HIRandom_v1_acc;   //!
   TBranch        *b_HLT_HIRandom_v1_psc;   //!
   TBranch        *b_AlCa_EcalPhiSymForHI_v1_acc;   //!
   TBranch        *b_AlCa_EcalPhiSymForHI_v1_psc;   //!
   TBranch        *b_HLT_HIHcalNZS_v1_acc;   //!
   TBranch        *b_HLT_HIHcalNZS_v1_psc;   //!
   TBranch        *b_HLT_HIHcalPhiSym_v1_acc;   //!
   TBranch        *b_HLT_HIHcalPhiSym_v1_psc;   //!
   TBranch        *b_AlCa_RPCMuonNormalisationForHI_v1_acc;   //!
   TBranch        *b_AlCa_RPCMuonNormalisationForHI_v1_psc;   //!
   TBranch        *b_AlCa_EcalPi0EBonlyForHI_v1_acc;   //!
   TBranch        *b_AlCa_EcalPi0EBonlyForHI_v1_psc;   //!
   TBranch        *b_AlCa_EcalPi0EEonlyForHI_v1_acc;   //!
   TBranch        *b_AlCa_EcalPi0EEonlyForHI_v1_psc;   //!
   TBranch        *b_AlCa_EcalEtaEBonlyForHI_v1_acc;   //!
   TBranch        *b_AlCa_EcalEtaEBonlyForHI_v1_psc;   //!
   TBranch        *b_AlCa_EcalEtaEEonlyForHI_v1_acc;   //!
   TBranch        *b_AlCa_EcalEtaEEonlyForHI_v1_psc;   //!
   TBranch        *b_HLT_HICentralityVeto_v1_acc;   //!
   TBranch        *b_HLT_HICentralityVeto_v1_psc;   //!
   TBranch        *b_HLT_HICentralityVeto_Beamspot_v1_acc;   //!
   TBranch        *b_HLT_HICentralityVeto_Beamspot_v1_psc;   //!
   TBranch        *b_HLT_HICentralityTag20100_v1_acc;   //!
   TBranch        *b_HLT_HICentralityTag20100_v1_psc;   //!
   TBranch        *b_HLT_HICentralityTag30100_v1_acc;   //!
   TBranch        *b_HLT_HICentralityTag30100_v1_psc;   //!
   TBranch        *b_HLT_HICentralityTag50100_v1_acc;   //!
   TBranch        *b_HLT_HICentralityTag50100_v1_psc;   //!
   TBranch        *b_HLT_HIZeroBias_v1_acc;   //!
   TBranch        *b_HLT_HIZeroBias_v1_psc;   //!
   TBranch        *b_HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_acc;   //!
   TBranch        *b_HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part0_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part0_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part1_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part1_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part2_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part2_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part3_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part3_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part4_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part4_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part5_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part5_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part6_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part6_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part7_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part7_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part8_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part8_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part9_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part9_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part10_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part10_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part11_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part11_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part12_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part12_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part13_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part13_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part14_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part14_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part15_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part15_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part16_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part16_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part17_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part17_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part18_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part18_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBias_part19_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBias_part19_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part0_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part0_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part1_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part1_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part2_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part2_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part3_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part3_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part4_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part4_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part5_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part5_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part6_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part6_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part7_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part7_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part8_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part8_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part9_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part9_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part10_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part10_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part11_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part11_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part12_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part12_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part13_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part13_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part14_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part14_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part15_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part15_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part16_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part16_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part17_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part17_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part18_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part18_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part19_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part19_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part20_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part20_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part21_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part21_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part22_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part22_v1_psc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part23_v1_acc;   //!
   TBranch        *b_HLT_HIMinimumBiasRF_part23_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet120Eta5p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet120Eta5p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Fwd_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet40Fwd_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Fwd_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Fwd_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Fwd_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Fwd_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Fwd_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Fwd_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet120Fwd_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet120Fwd_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton50_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton50_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton50_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton50_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton60_Eta2p4_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton60_Eta2p4_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton60_Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton60_Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_EB_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_EB_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton50_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_EB_HECut_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton60_EB_HECut_v1_psc;   //!
   TBranch        *b_HLT_HIEle10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle20Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle20Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle30Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle30Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle40Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle40Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle50Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle50Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Ele10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Ele10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Ele10GsfMass50_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Ele10GsfMass50_v1_psc;   //!
   TBranch        *b_HLT_HIDoubleEle10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIDoubleEle10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIDoubleEle10GsfMass50_v1_acc;   //!
   TBranch        *b_HLT_HIDoubleEle10GsfMass50_v1_psc;   //!
   TBranch        *b_HLT_HIDoubleEle15Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIDoubleEle15Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIDoubleEle15GsfMass50_v1_acc;   //!
   TBranch        *b_HLT_HIDoubleEle15GsfMass50_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_acc;   //!
   TBranch        *b_HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_psc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_psc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_acc;   //!
   TBranch        *b_HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_psc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt20_v1_acc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt20_v1_psc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt30_v1_acc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt30_v1_psc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt40_v1_acc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt40_v1_psc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt50_v1_acc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt50_v1_psc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt60_v1_acc;   //!
   TBranch        *b_HLT_HIDsPPTrackingGlobal_Dpt60_v1_psc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt20_v1_acc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt20_v1_psc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt30_v1_acc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt30_v1_psc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt40_v1_acc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt40_v1_psc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt50_v1_acc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt50_v1_psc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt60_v1_acc;   //!
   TBranch        *b_HLT_HILcPPTrackingGlobal_Dpt60_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt18_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt18_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt24_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt24_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt34_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt34_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt45_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt45_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt56_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt56_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt60_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks2018_HighPt60_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_er1p6_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_er1p6_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_er1p6_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_er1p6_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMu0_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMu0_v1_psc;   //!
   TBranch        *b_HLT_HIL1DoubleMu10_v1_acc;   //!
   TBranch        *b_HLT_HIL1DoubleMu10_v1_psc;   //!
   TBranch        *b_HLT_HIL2_L1DoubleMu10_v1_acc;   //!
   TBranch        *b_HLT_HIL2_L1DoubleMu10_v1_psc;   //!
   TBranch        *b_HLT_HIL3_L1DoubleMu10_v1_acc;   //!
   TBranch        *b_HLT_HIL3_L1DoubleMu10_v1_psc;   //!
   TBranch        *b_HLT_HIL2DoubleMuOpen_v1_acc;   //!
   TBranch        *b_HLT_HIL2DoubleMuOpen_v1_psc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_v1_acc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_v1_psc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_M60120_v1_acc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_M60120_v1_psc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_JpsiPsi_v1_acc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_JpsiPsi_v1_psc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_Upsi_v1_acc;   //!
   TBranch        *b_HLT_HIL3DoubleMuOpen_Upsi_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu0_L2Mu0_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu0_L2Mu0_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_psc;   //!
   TBranch        *b_HLT_HIL1MuOpen_Centrality_70_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1MuOpen_Centrality_70_100_v1_psc;   //!
   TBranch        *b_HLT_HIL1MuOpen_Centrality_80_100_v1_acc;   //!
   TBranch        *b_HLT_HIL1MuOpen_Centrality_80_100_v1_psc;   //!
   TBranch        *b_HLT_HIL2Mu3_NHitQ15_v1_acc;   //!
   TBranch        *b_HLT_HIL2Mu3_NHitQ15_v1_psc;   //!
   TBranch        *b_HLT_HIL2Mu5_NHitQ15_v1_acc;   //!
   TBranch        *b_HLT_HIL2Mu5_NHitQ15_v1_psc;   //!
   TBranch        *b_HLT_HIL2Mu7_NHitQ15_v1_acc;   //!
   TBranch        *b_HLT_HIL2Mu7_NHitQ15_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu2p5_L1DoubleMu0_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu2p5_L1DoubleMu0_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_L1TripleMuOpen_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_L1TripleMuOpen_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu12_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu12_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu15_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu15_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu20_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu20_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_NHitQ10_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_NHitQ10_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5_NHitQ10_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5_NHitQ10_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu7_NHitQ10_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu7_NHitQ10_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_psc;   //!
   TBranch        *b_HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF1AND_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF1AND_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity4060_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity4060_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity6080_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity6080_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity80100_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity80100_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF1OR_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF1OR_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity020_HF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_psc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_Mu8_Mu13_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_Mu8_Mu13_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_acc;   //!
   TBranch        *b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet120Eta1p5_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet120Eta1p5_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_psc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_acc;   //!
   TBranch        *b_HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG10HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG10HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG15HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG15HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG20HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG20HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG30HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3_EG30HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG10HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG10HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG15HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG15HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG20HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG20HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG30HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5_EG30HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG10HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG10HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG15HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG15HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG20HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG20HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG30HECut_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu7_EG30HECut_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc;   //!
   TBranch        *b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_v1_acc;   //!
   TBranch        *b_HLT_HICastor_MediumJet_v1_psc;   //!
   TBranch        *b_HLT_HICastor_HighJet_v1_acc;   //!
   TBranch        *b_HLT_HICastor_HighJet_v1_psc;   //!
   TBranch        *b_HLT_HICastor_HighJet_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_HighJet_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_HighJet_NotMBHF2OR_v1_acc;   //!
   TBranch        *b_HLT_HICastor_HighJet_NotMBHF2OR_v1_psc;   //!
   TBranch        *b_HLT_HICastor_HighJet_NotMBHF2AND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_HighJet_NotMBHF2AND_v1_psc;   //!
   TBranch        *b_HLT_HICastor_Muon_v1_acc;   //!
   TBranch        *b_HLT_HICastor_Muon_v1_psc;   //!
   TBranch        *b_HLT_HICastor_Muon_BptxAND_v1_acc;   //!
   TBranch        *b_HLT_HICastor_Muon_BptxAND_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_Cent30_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_Cent30_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton10_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton20_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton30_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_Cent50_100_v1_acc;   //!
   TBranch        *b_HLT_HIGEDPhoton40_Cent50_100_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_psc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_acc;   //!
   TBranch        *b_HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_psc;   //!
   TBranch        *b_HLT_HIL1NotBptxOR_v1_acc;   //!
   TBranch        *b_HLT_HIL1NotBptxOR_v1_psc;   //!
   TBranch        *b_HLT_HIL1UnpairedBunchBptxMinus_v1_acc;   //!
   TBranch        *b_HLT_HIL1UnpairedBunchBptxMinus_v1_psc;   //!
   TBranch        *b_HLT_HIL1UnpairedBunchBptxPlus_v1_acc;   //!
   TBranch        *b_HLT_HIL1UnpairedBunchBptxPlus_v1_psc;   //!
   TBranch        *b_HLTriggerFinalPath_acc;   //!
   TBranch        *b_HLTriggerFinalPath_psc;   //!

   zdcTreeClass(TTree *tree=0);
   virtual ~zdcTreeClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef zdcTreeClass_cxx
zdcTreeClass::zdcTreeClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/store/user/eadams/HIMinimumBias2/merged_rereco_PbPb2018_AOD_MB2_326822/rereco_PbPb2018_AOD_MinBias2_326822_ZDCandTracks_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/store/user/eadams/HIMinimumBias2/merged_rereco_PbPb2018_AOD_MB2_326822/rereco_PbPb2018_AOD_MinBias2_326822_ZDCandTracks_merged.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/store/user/eadams/HIMinimumBias2/merged_rereco_PbPb2018_AOD_MB2_326822/rereco_PbPb2018_AOD_MinBias2_326822_ZDCandTracks_merged.root:/analyzer");
      dir->GetObject("zdcdigi",tree);

   }
   Init(tree);
}

zdcTreeClass::~zdcTreeClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t zdcTreeClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t zdcTreeClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void zdcTreeClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   phi = 0;
   phiError = 0;
   eta = 0;
   etaError = 0;
   Pt = 0;
   ptError = 0;
   chi2 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("bxid", &bxid, &b_bxid);
   fChain->SetBranchAddress("Cent", &Cent, &b_cent);
   fChain->SetBranchAddress("n", &n, &b_n);
   fChain->SetBranchAddress("zside", zside, &b_zside);
   fChain->SetBranchAddress("section", section, &b_section);
   fChain->SetBranchAddress("channel", channel, &b_channel);
   fChain->SetBranchAddress("rejected", rejected, &b_rejected);
   fChain->SetBranchAddress("nHF_pos", &nHF_pos, &b_nHF_pos);
   fChain->SetBranchAddress("nHF_neg", &nHF_neg, &b_nHF_neg);
   fChain->SetBranchAddress("eHF_pos", &eHF_pos, &b_eHF_pos);
   fChain->SetBranchAddress("eHF_neg", &eHF_neg, &b_eHF_neg);
   fChain->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
   fChain->SetBranchAddress("nAcceptedTracks", &nAcceptedTracks, &b_nAcceptedTracks);
   fChain->SetBranchAddress("nPixel", &nPixel, &b_nPixel);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("phiError", &phiError, &b_phiError);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("etaError", &etaError, &b_etaError);
   fChain->SetBranchAddress("Pt", &Pt, &b_Pt);
   fChain->SetBranchAddress("ptError", &ptError, &b_ptError);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("adc0", adc0, &b_adc0);
   fChain->SetBranchAddress("nfC0", nfC0, &b_nfC0);
   fChain->SetBranchAddress("adc1", adc1, &b_adc1);
   fChain->SetBranchAddress("nfC1", nfC1, &b_nfC1);
   fChain->SetBranchAddress("adc2", adc2, &b_adc2);
   fChain->SetBranchAddress("nfC2", nfC2, &b_nfC2);
   fChain->SetBranchAddress("adc3", adc3, &b_adc3);
   fChain->SetBranchAddress("nfC3", nfC3, &b_nfC3);
   fChain->SetBranchAddress("adc4", adc4, &b_adc4);
   fChain->SetBranchAddress("nfC4", nfC4, &b_nfC4);
   fChain->SetBranchAddress("adc5", adc5, &b_adc5);
   fChain->SetBranchAddress("nfC5", nfC5, &b_nfC5);
   fChain->SetBranchAddress("adc6", adc6, &b_adc6);
   fChain->SetBranchAddress("nfC6", nfC6, &b_nfC6);
   fChain->SetBranchAddress("adc7", adc7, &b_adc7);
   fChain->SetBranchAddress("nfC7", nfC7, &b_nfC7);
   fChain->SetBranchAddress("adc8", adc8, &b_adc8);
   fChain->SetBranchAddress("nfC8", nfC8, &b_nfC8);
   fChain->SetBranchAddress("adc9", adc9, &b_adc9);
   fChain->SetBranchAddress("nfC9", nfC9, &b_nfC9);
   fChain->SetBranchAddress("HLTriggerFirstPath_acc", &HLTriggerFirstPath_acc, &b_HLTriggerFirstPath_acc);
   fChain->SetBranchAddress("HLTriggerFirstPath_psc", &HLTriggerFirstPath_psc, &b_HLTriggerFirstPath_psc);
   fChain->SetBranchAddress("DST_Physics_v7_acc", &DST_Physics_v7_acc, &b_DST_Physics_v7_acc);
   fChain->SetBranchAddress("DST_Physics_v7_psc", &DST_Physics_v7_psc, &b_DST_Physics_v7_psc);
   fChain->SetBranchAddress("HLT_EcalCalibration_v4_acc", &HLT_EcalCalibration_v4_acc, &b_HLT_EcalCalibration_v4_acc);
   fChain->SetBranchAddress("HLT_EcalCalibration_v4_psc", &HLT_EcalCalibration_v4_psc, &b_HLT_EcalCalibration_v4_psc);
   fChain->SetBranchAddress("HLT_HcalCalibration_v5_acc", &HLT_HcalCalibration_v5_acc, &b_HLT_HcalCalibration_v5_acc);
   fChain->SetBranchAddress("HLT_HcalCalibration_v5_psc", &HLT_HcalCalibration_v5_psc, &b_HLT_HcalCalibration_v5_psc);
   fChain->SetBranchAddress("HLT_HIPhysics_v1_acc", &HLT_HIPhysics_v1_acc, &b_HLT_HIPhysics_v1_acc);
   fChain->SetBranchAddress("HLT_HIPhysics_v1_psc", &HLT_HIPhysics_v1_psc, &b_HLT_HIPhysics_v1_psc);
   fChain->SetBranchAddress("HLT_HIPhysicsForZS_v1_acc", &HLT_HIPhysicsForZS_v1_acc, &b_HLT_HIPhysicsForZS_v1_acc);
   fChain->SetBranchAddress("HLT_HIPhysicsForZS_v1_psc", &HLT_HIPhysicsForZS_v1_psc, &b_HLT_HIPhysicsForZS_v1_psc);
   fChain->SetBranchAddress("HLT_HIRandom_v1_acc", &HLT_HIRandom_v1_acc, &b_HLT_HIRandom_v1_acc);
   fChain->SetBranchAddress("HLT_HIRandom_v1_psc", &HLT_HIRandom_v1_psc, &b_HLT_HIRandom_v1_psc);
   fChain->SetBranchAddress("AlCa_EcalPhiSymForHI_v1_acc", &AlCa_EcalPhiSymForHI_v1_acc, &b_AlCa_EcalPhiSymForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_EcalPhiSymForHI_v1_psc", &AlCa_EcalPhiSymForHI_v1_psc, &b_AlCa_EcalPhiSymForHI_v1_psc);
   fChain->SetBranchAddress("HLT_HIHcalNZS_v1_acc", &HLT_HIHcalNZS_v1_acc, &b_HLT_HIHcalNZS_v1_acc);
   fChain->SetBranchAddress("HLT_HIHcalNZS_v1_psc", &HLT_HIHcalNZS_v1_psc, &b_HLT_HIHcalNZS_v1_psc);
   fChain->SetBranchAddress("HLT_HIHcalPhiSym_v1_acc", &HLT_HIHcalPhiSym_v1_acc, &b_HLT_HIHcalPhiSym_v1_acc);
   fChain->SetBranchAddress("HLT_HIHcalPhiSym_v1_psc", &HLT_HIHcalPhiSym_v1_psc, &b_HLT_HIHcalPhiSym_v1_psc);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisationForHI_v1_acc", &AlCa_RPCMuonNormalisationForHI_v1_acc, &b_AlCa_RPCMuonNormalisationForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_RPCMuonNormalisationForHI_v1_psc", &AlCa_RPCMuonNormalisationForHI_v1_psc, &b_AlCa_RPCMuonNormalisationForHI_v1_psc);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonlyForHI_v1_acc", &AlCa_EcalPi0EBonlyForHI_v1_acc, &b_AlCa_EcalPi0EBonlyForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_EcalPi0EBonlyForHI_v1_psc", &AlCa_EcalPi0EBonlyForHI_v1_psc, &b_AlCa_EcalPi0EBonlyForHI_v1_psc);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonlyForHI_v1_acc", &AlCa_EcalPi0EEonlyForHI_v1_acc, &b_AlCa_EcalPi0EEonlyForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_EcalPi0EEonlyForHI_v1_psc", &AlCa_EcalPi0EEonlyForHI_v1_psc, &b_AlCa_EcalPi0EEonlyForHI_v1_psc);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonlyForHI_v1_acc", &AlCa_EcalEtaEBonlyForHI_v1_acc, &b_AlCa_EcalEtaEBonlyForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_EcalEtaEBonlyForHI_v1_psc", &AlCa_EcalEtaEBonlyForHI_v1_psc, &b_AlCa_EcalEtaEBonlyForHI_v1_psc);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonlyForHI_v1_acc", &AlCa_EcalEtaEEonlyForHI_v1_acc, &b_AlCa_EcalEtaEEonlyForHI_v1_acc);
   fChain->SetBranchAddress("AlCa_EcalEtaEEonlyForHI_v1_psc", &AlCa_EcalEtaEEonlyForHI_v1_psc, &b_AlCa_EcalEtaEEonlyForHI_v1_psc);
   fChain->SetBranchAddress("HLT_HICentralityVeto_v1_acc", &HLT_HICentralityVeto_v1_acc, &b_HLT_HICentralityVeto_v1_acc);
   fChain->SetBranchAddress("HLT_HICentralityVeto_v1_psc", &HLT_HICentralityVeto_v1_psc, &b_HLT_HICentralityVeto_v1_psc);
   fChain->SetBranchAddress("HLT_HICentralityVeto_Beamspot_v1_acc", &HLT_HICentralityVeto_Beamspot_v1_acc, &b_HLT_HICentralityVeto_Beamspot_v1_acc);
   fChain->SetBranchAddress("HLT_HICentralityVeto_Beamspot_v1_psc", &HLT_HICentralityVeto_Beamspot_v1_psc, &b_HLT_HICentralityVeto_Beamspot_v1_psc);
   fChain->SetBranchAddress("HLT_HICentralityTag20100_v1_acc", &HLT_HICentralityTag20100_v1_acc, &b_HLT_HICentralityTag20100_v1_acc);
   fChain->SetBranchAddress("HLT_HICentralityTag20100_v1_psc", &HLT_HICentralityTag20100_v1_psc, &b_HLT_HICentralityTag20100_v1_psc);
   fChain->SetBranchAddress("HLT_HICentralityTag30100_v1_acc", &HLT_HICentralityTag30100_v1_acc, &b_HLT_HICentralityTag30100_v1_acc);
   fChain->SetBranchAddress("HLT_HICentralityTag30100_v1_psc", &HLT_HICentralityTag30100_v1_psc, &b_HLT_HICentralityTag30100_v1_psc);
   fChain->SetBranchAddress("HLT_HICentralityTag50100_v1_acc", &HLT_HICentralityTag50100_v1_acc, &b_HLT_HICentralityTag50100_v1_acc);
   fChain->SetBranchAddress("HLT_HICentralityTag50100_v1_psc", &HLT_HICentralityTag50100_v1_psc, &b_HLT_HICentralityTag50100_v1_psc);
   fChain->SetBranchAddress("HLT_HIZeroBias_v1_acc", &HLT_HIZeroBias_v1_acc, &b_HLT_HIZeroBias_v1_acc);
   fChain->SetBranchAddress("HLT_HIZeroBias_v1_psc", &HLT_HIZeroBias_v1_psc, &b_HLT_HIZeroBias_v1_psc);
   fChain->SetBranchAddress("HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_acc", &HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_acc, &b_HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_acc);
   fChain->SetBranchAddress("HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_psc", &HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_psc, &b_HLT_HIZeroBias_FirstCollisionAfterAbortGap_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part0_v1_acc", &HLT_HIMinimumBias_part0_v1_acc, &b_HLT_HIMinimumBias_part0_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part0_v1_psc", &HLT_HIMinimumBias_part0_v1_psc, &b_HLT_HIMinimumBias_part0_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part1_v1_acc", &HLT_HIMinimumBias_part1_v1_acc, &b_HLT_HIMinimumBias_part1_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part1_v1_psc", &HLT_HIMinimumBias_part1_v1_psc, &b_HLT_HIMinimumBias_part1_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part2_v1_acc", &HLT_HIMinimumBias_part2_v1_acc, &b_HLT_HIMinimumBias_part2_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part2_v1_psc", &HLT_HIMinimumBias_part2_v1_psc, &b_HLT_HIMinimumBias_part2_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part3_v1_acc", &HLT_HIMinimumBias_part3_v1_acc, &b_HLT_HIMinimumBias_part3_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part3_v1_psc", &HLT_HIMinimumBias_part3_v1_psc, &b_HLT_HIMinimumBias_part3_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part4_v1_acc", &HLT_HIMinimumBias_part4_v1_acc, &b_HLT_HIMinimumBias_part4_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part4_v1_psc", &HLT_HIMinimumBias_part4_v1_psc, &b_HLT_HIMinimumBias_part4_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part5_v1_acc", &HLT_HIMinimumBias_part5_v1_acc, &b_HLT_HIMinimumBias_part5_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part5_v1_psc", &HLT_HIMinimumBias_part5_v1_psc, &b_HLT_HIMinimumBias_part5_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part6_v1_acc", &HLT_HIMinimumBias_part6_v1_acc, &b_HLT_HIMinimumBias_part6_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part6_v1_psc", &HLT_HIMinimumBias_part6_v1_psc, &b_HLT_HIMinimumBias_part6_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part7_v1_acc", &HLT_HIMinimumBias_part7_v1_acc, &b_HLT_HIMinimumBias_part7_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part7_v1_psc", &HLT_HIMinimumBias_part7_v1_psc, &b_HLT_HIMinimumBias_part7_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part8_v1_acc", &HLT_HIMinimumBias_part8_v1_acc, &b_HLT_HIMinimumBias_part8_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part8_v1_psc", &HLT_HIMinimumBias_part8_v1_psc, &b_HLT_HIMinimumBias_part8_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part9_v1_acc", &HLT_HIMinimumBias_part9_v1_acc, &b_HLT_HIMinimumBias_part9_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part9_v1_psc", &HLT_HIMinimumBias_part9_v1_psc, &b_HLT_HIMinimumBias_part9_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part10_v1_acc", &HLT_HIMinimumBias_part10_v1_acc, &b_HLT_HIMinimumBias_part10_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part10_v1_psc", &HLT_HIMinimumBias_part10_v1_psc, &b_HLT_HIMinimumBias_part10_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part11_v1_acc", &HLT_HIMinimumBias_part11_v1_acc, &b_HLT_HIMinimumBias_part11_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part11_v1_psc", &HLT_HIMinimumBias_part11_v1_psc, &b_HLT_HIMinimumBias_part11_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part12_v1_acc", &HLT_HIMinimumBias_part12_v1_acc, &b_HLT_HIMinimumBias_part12_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part12_v1_psc", &HLT_HIMinimumBias_part12_v1_psc, &b_HLT_HIMinimumBias_part12_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part13_v1_acc", &HLT_HIMinimumBias_part13_v1_acc, &b_HLT_HIMinimumBias_part13_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part13_v1_psc", &HLT_HIMinimumBias_part13_v1_psc, &b_HLT_HIMinimumBias_part13_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part14_v1_acc", &HLT_HIMinimumBias_part14_v1_acc, &b_HLT_HIMinimumBias_part14_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part14_v1_psc", &HLT_HIMinimumBias_part14_v1_psc, &b_HLT_HIMinimumBias_part14_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part15_v1_acc", &HLT_HIMinimumBias_part15_v1_acc, &b_HLT_HIMinimumBias_part15_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part15_v1_psc", &HLT_HIMinimumBias_part15_v1_psc, &b_HLT_HIMinimumBias_part15_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part16_v1_acc", &HLT_HIMinimumBias_part16_v1_acc, &b_HLT_HIMinimumBias_part16_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part16_v1_psc", &HLT_HIMinimumBias_part16_v1_psc, &b_HLT_HIMinimumBias_part16_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part17_v1_acc", &HLT_HIMinimumBias_part17_v1_acc, &b_HLT_HIMinimumBias_part17_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part17_v1_psc", &HLT_HIMinimumBias_part17_v1_psc, &b_HLT_HIMinimumBias_part17_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part18_v1_acc", &HLT_HIMinimumBias_part18_v1_acc, &b_HLT_HIMinimumBias_part18_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part18_v1_psc", &HLT_HIMinimumBias_part18_v1_psc, &b_HLT_HIMinimumBias_part18_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part19_v1_acc", &HLT_HIMinimumBias_part19_v1_acc, &b_HLT_HIMinimumBias_part19_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBias_part19_v1_psc", &HLT_HIMinimumBias_part19_v1_psc, &b_HLT_HIMinimumBias_part19_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part0_v1_acc", &HLT_HIMinimumBiasRF_part0_v1_acc, &b_HLT_HIMinimumBiasRF_part0_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part0_v1_psc", &HLT_HIMinimumBiasRF_part0_v1_psc, &b_HLT_HIMinimumBiasRF_part0_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part1_v1_acc", &HLT_HIMinimumBiasRF_part1_v1_acc, &b_HLT_HIMinimumBiasRF_part1_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part1_v1_psc", &HLT_HIMinimumBiasRF_part1_v1_psc, &b_HLT_HIMinimumBiasRF_part1_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part2_v1_acc", &HLT_HIMinimumBiasRF_part2_v1_acc, &b_HLT_HIMinimumBiasRF_part2_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part2_v1_psc", &HLT_HIMinimumBiasRF_part2_v1_psc, &b_HLT_HIMinimumBiasRF_part2_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part3_v1_acc", &HLT_HIMinimumBiasRF_part3_v1_acc, &b_HLT_HIMinimumBiasRF_part3_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part3_v1_psc", &HLT_HIMinimumBiasRF_part3_v1_psc, &b_HLT_HIMinimumBiasRF_part3_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part4_v1_acc", &HLT_HIMinimumBiasRF_part4_v1_acc, &b_HLT_HIMinimumBiasRF_part4_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part4_v1_psc", &HLT_HIMinimumBiasRF_part4_v1_psc, &b_HLT_HIMinimumBiasRF_part4_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part5_v1_acc", &HLT_HIMinimumBiasRF_part5_v1_acc, &b_HLT_HIMinimumBiasRF_part5_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part5_v1_psc", &HLT_HIMinimumBiasRF_part5_v1_psc, &b_HLT_HIMinimumBiasRF_part5_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part6_v1_acc", &HLT_HIMinimumBiasRF_part6_v1_acc, &b_HLT_HIMinimumBiasRF_part6_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part6_v1_psc", &HLT_HIMinimumBiasRF_part6_v1_psc, &b_HLT_HIMinimumBiasRF_part6_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part7_v1_acc", &HLT_HIMinimumBiasRF_part7_v1_acc, &b_HLT_HIMinimumBiasRF_part7_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part7_v1_psc", &HLT_HIMinimumBiasRF_part7_v1_psc, &b_HLT_HIMinimumBiasRF_part7_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part8_v1_acc", &HLT_HIMinimumBiasRF_part8_v1_acc, &b_HLT_HIMinimumBiasRF_part8_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part8_v1_psc", &HLT_HIMinimumBiasRF_part8_v1_psc, &b_HLT_HIMinimumBiasRF_part8_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part9_v1_acc", &HLT_HIMinimumBiasRF_part9_v1_acc, &b_HLT_HIMinimumBiasRF_part9_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part9_v1_psc", &HLT_HIMinimumBiasRF_part9_v1_psc, &b_HLT_HIMinimumBiasRF_part9_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part10_v1_acc", &HLT_HIMinimumBiasRF_part10_v1_acc, &b_HLT_HIMinimumBiasRF_part10_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part10_v1_psc", &HLT_HIMinimumBiasRF_part10_v1_psc, &b_HLT_HIMinimumBiasRF_part10_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part11_v1_acc", &HLT_HIMinimumBiasRF_part11_v1_acc, &b_HLT_HIMinimumBiasRF_part11_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part11_v1_psc", &HLT_HIMinimumBiasRF_part11_v1_psc, &b_HLT_HIMinimumBiasRF_part11_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part12_v1_acc", &HLT_HIMinimumBiasRF_part12_v1_acc, &b_HLT_HIMinimumBiasRF_part12_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part12_v1_psc", &HLT_HIMinimumBiasRF_part12_v1_psc, &b_HLT_HIMinimumBiasRF_part12_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part13_v1_acc", &HLT_HIMinimumBiasRF_part13_v1_acc, &b_HLT_HIMinimumBiasRF_part13_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part13_v1_psc", &HLT_HIMinimumBiasRF_part13_v1_psc, &b_HLT_HIMinimumBiasRF_part13_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part14_v1_acc", &HLT_HIMinimumBiasRF_part14_v1_acc, &b_HLT_HIMinimumBiasRF_part14_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part14_v1_psc", &HLT_HIMinimumBiasRF_part14_v1_psc, &b_HLT_HIMinimumBiasRF_part14_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part15_v1_acc", &HLT_HIMinimumBiasRF_part15_v1_acc, &b_HLT_HIMinimumBiasRF_part15_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part15_v1_psc", &HLT_HIMinimumBiasRF_part15_v1_psc, &b_HLT_HIMinimumBiasRF_part15_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part16_v1_acc", &HLT_HIMinimumBiasRF_part16_v1_acc, &b_HLT_HIMinimumBiasRF_part16_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part16_v1_psc", &HLT_HIMinimumBiasRF_part16_v1_psc, &b_HLT_HIMinimumBiasRF_part16_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part17_v1_acc", &HLT_HIMinimumBiasRF_part17_v1_acc, &b_HLT_HIMinimumBiasRF_part17_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part17_v1_psc", &HLT_HIMinimumBiasRF_part17_v1_psc, &b_HLT_HIMinimumBiasRF_part17_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part18_v1_acc", &HLT_HIMinimumBiasRF_part18_v1_acc, &b_HLT_HIMinimumBiasRF_part18_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part18_v1_psc", &HLT_HIMinimumBiasRF_part18_v1_psc, &b_HLT_HIMinimumBiasRF_part18_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part19_v1_acc", &HLT_HIMinimumBiasRF_part19_v1_acc, &b_HLT_HIMinimumBiasRF_part19_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part19_v1_psc", &HLT_HIMinimumBiasRF_part19_v1_psc, &b_HLT_HIMinimumBiasRF_part19_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part20_v1_acc", &HLT_HIMinimumBiasRF_part20_v1_acc, &b_HLT_HIMinimumBiasRF_part20_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part20_v1_psc", &HLT_HIMinimumBiasRF_part20_v1_psc, &b_HLT_HIMinimumBiasRF_part20_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part21_v1_acc", &HLT_HIMinimumBiasRF_part21_v1_acc, &b_HLT_HIMinimumBiasRF_part21_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part21_v1_psc", &HLT_HIMinimumBiasRF_part21_v1_psc, &b_HLT_HIMinimumBiasRF_part21_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part22_v1_acc", &HLT_HIMinimumBiasRF_part22_v1_acc, &b_HLT_HIMinimumBiasRF_part22_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part22_v1_psc", &HLT_HIMinimumBiasRF_part22_v1_psc, &b_HLT_HIMinimumBiasRF_part22_v1_psc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part23_v1_acc", &HLT_HIMinimumBiasRF_part23_v1_acc, &b_HLT_HIMinimumBiasRF_part23_v1_acc);
   fChain->SetBranchAddress("HLT_HIMinimumBiasRF_part23_v1_psc", &HLT_HIMinimumBiasRF_part23_v1_psc, &b_HLT_HIMinimumBiasRF_part23_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_v1_acc", &HLT_HIPuAK4CaloJet40Eta5p1_v1_acc, &b_HLT_HIPuAK4CaloJet40Eta5p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_v1_psc", &HLT_HIPuAK4CaloJet40Eta5p1_v1_psc, &b_HLT_HIPuAK4CaloJet40Eta5p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_v1_acc", &HLT_HIPuAK4CaloJet60Eta5p1_v1_acc, &b_HLT_HIPuAK4CaloJet60Eta5p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_v1_psc", &HLT_HIPuAK4CaloJet60Eta5p1_v1_psc, &b_HLT_HIPuAK4CaloJet60Eta5p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_v1_acc", &HLT_HIPuAK4CaloJet80Eta5p1_v1_acc, &b_HLT_HIPuAK4CaloJet80Eta5p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_v1_psc", &HLT_HIPuAK4CaloJet80Eta5p1_v1_psc, &b_HLT_HIPuAK4CaloJet80Eta5p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_v1_acc", &HLT_HIPuAK4CaloJet100Eta5p1_v1_acc, &b_HLT_HIPuAK4CaloJet100Eta5p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_v1_psc", &HLT_HIPuAK4CaloJet100Eta5p1_v1_psc, &b_HLT_HIPuAK4CaloJet100Eta5p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet120Eta5p1_v1_acc", &HLT_HIPuAK4CaloJet120Eta5p1_v1_acc, &b_HLT_HIPuAK4CaloJet120Eta5p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet120Eta5p1_v1_psc", &HLT_HIPuAK4CaloJet120Eta5p1_v1_psc, &b_HLT_HIPuAK4CaloJet120Eta5p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_acc", &HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_acc, &b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_psc", &HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_psc, &b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_acc", &HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_acc, &b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_psc", &HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_psc, &b_HLT_HIPuAK4CaloJet40Eta5p1_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_acc", &HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_acc, &b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_psc", &HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_psc, &b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_acc", &HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_acc, &b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_psc", &HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_psc, &b_HLT_HIPuAK4CaloJet60Eta5p1_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_acc", &HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_acc, &b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_psc", &HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_psc, &b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_acc", &HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_acc, &b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_psc", &HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_psc, &b_HLT_HIPuAK4CaloJet80Eta5p1_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_acc", &HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_acc, &b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_psc", &HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_psc, &b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_acc", &HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_acc, &b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_psc", &HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_psc, &b_HLT_HIPuAK4CaloJet100Eta5p1_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_acc", &HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_acc, &b_HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_psc", &HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_psc, &b_HLT_HIPuAK4CaloJet80_35_Eta1p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_acc", &HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_acc, &b_HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_psc", &HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_psc, &b_HLT_HIPuAK4CaloJet100_35_Eta1p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_acc", &HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_acc, &b_HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_psc", &HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_psc, &b_HLT_HIPuAK4CaloJet80_35_Eta0p7_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_acc", &HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_acc, &b_HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_psc", &HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_psc, &b_HLT_HIPuAK4CaloJet100_35_Eta0p7_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_acc", &HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_acc, &b_HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_psc", &HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_psc, &b_HLT_HIPuAK4CaloJet80_45_45_Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Fwd_v1_acc", &HLT_HIPuAK4CaloJet40Fwd_v1_acc, &b_HLT_HIPuAK4CaloJet40Fwd_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet40Fwd_v1_psc", &HLT_HIPuAK4CaloJet40Fwd_v1_psc, &b_HLT_HIPuAK4CaloJet40Fwd_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Fwd_v1_acc", &HLT_HIPuAK4CaloJet60Fwd_v1_acc, &b_HLT_HIPuAK4CaloJet60Fwd_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Fwd_v1_psc", &HLT_HIPuAK4CaloJet60Fwd_v1_psc, &b_HLT_HIPuAK4CaloJet60Fwd_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Fwd_v1_acc", &HLT_HIPuAK4CaloJet80Fwd_v1_acc, &b_HLT_HIPuAK4CaloJet80Fwd_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Fwd_v1_psc", &HLT_HIPuAK4CaloJet80Fwd_v1_psc, &b_HLT_HIPuAK4CaloJet80Fwd_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Fwd_v1_acc", &HLT_HIPuAK4CaloJet100Fwd_v1_acc, &b_HLT_HIPuAK4CaloJet100Fwd_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Fwd_v1_psc", &HLT_HIPuAK4CaloJet100Fwd_v1_psc, &b_HLT_HIPuAK4CaloJet100Fwd_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet120Fwd_v1_acc", &HLT_HIPuAK4CaloJet120Fwd_v1_acc, &b_HLT_HIPuAK4CaloJet120Fwd_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet120Fwd_v1_psc", &HLT_HIPuAK4CaloJet120Fwd_v1_psc, &b_HLT_HIPuAK4CaloJet120Fwd_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_v1_acc", &HLT_HIIslandPhoton10_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton10_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_v1_psc", &HLT_HIIslandPhoton10_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton10_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta1p5_v1_acc", &HLT_HIIslandPhoton10_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton10_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta1p5_v1_psc", &HLT_HIIslandPhoton10_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton10_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_v1_acc", &HLT_HIIslandPhoton20_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton20_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_v1_psc", &HLT_HIIslandPhoton20_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton20_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta1p5_v1_acc", &HLT_HIIslandPhoton20_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton20_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta1p5_v1_psc", &HLT_HIIslandPhoton20_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton20_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_v1_acc", &HLT_HIIslandPhoton30_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton30_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_v1_psc", &HLT_HIIslandPhoton30_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton30_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta1p5_v1_acc", &HLT_HIIslandPhoton30_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton30_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta1p5_v1_psc", &HLT_HIIslandPhoton30_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton30_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_v1_acc", &HLT_HIIslandPhoton40_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton40_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_v1_psc", &HLT_HIIslandPhoton40_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton40_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta1p5_v1_acc", &HLT_HIIslandPhoton40_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton40_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta1p5_v1_psc", &HLT_HIIslandPhoton40_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton40_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton50_Eta2p4_v1_acc", &HLT_HIIslandPhoton50_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton50_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton50_Eta2p4_v1_psc", &HLT_HIIslandPhoton50_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton50_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton50_Eta1p5_v1_acc", &HLT_HIIslandPhoton50_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton50_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton50_Eta1p5_v1_psc", &HLT_HIIslandPhoton50_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton50_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton60_Eta2p4_v1_acc", &HLT_HIIslandPhoton60_Eta2p4_v1_acc, &b_HLT_HIIslandPhoton60_Eta2p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton60_Eta2p4_v1_psc", &HLT_HIIslandPhoton60_Eta2p4_v1_psc, &b_HLT_HIIslandPhoton60_Eta2p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton60_Eta1p5_v1_acc", &HLT_HIIslandPhoton60_Eta1p5_v1_acc, &b_HLT_HIIslandPhoton60_Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton60_Eta1p5_v1_psc", &HLT_HIIslandPhoton60_Eta1p5_v1_psc, &b_HLT_HIIslandPhoton60_Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_v1_acc", &HLT_HIGEDPhoton10_v1_acc, &b_HLT_HIGEDPhoton10_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_v1_psc", &HLT_HIGEDPhoton10_v1_psc, &b_HLT_HIGEDPhoton10_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_v1_acc", &HLT_HIGEDPhoton20_v1_acc, &b_HLT_HIGEDPhoton20_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_v1_psc", &HLT_HIGEDPhoton20_v1_psc, &b_HLT_HIGEDPhoton20_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_v1_acc", &HLT_HIGEDPhoton30_v1_acc, &b_HLT_HIGEDPhoton30_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_v1_psc", &HLT_HIGEDPhoton30_v1_psc, &b_HLT_HIGEDPhoton30_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_v1_acc", &HLT_HIGEDPhoton40_v1_acc, &b_HLT_HIGEDPhoton40_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_v1_psc", &HLT_HIGEDPhoton40_v1_psc, &b_HLT_HIGEDPhoton40_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_v1_acc", &HLT_HIGEDPhoton50_v1_acc, &b_HLT_HIGEDPhoton50_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_v1_psc", &HLT_HIGEDPhoton50_v1_psc, &b_HLT_HIGEDPhoton50_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_v1_acc", &HLT_HIGEDPhoton60_v1_acc, &b_HLT_HIGEDPhoton60_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_v1_psc", &HLT_HIGEDPhoton60_v1_psc, &b_HLT_HIGEDPhoton60_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_EB_v1_acc", &HLT_HIGEDPhoton10_EB_v1_acc, &b_HLT_HIGEDPhoton10_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_EB_v1_psc", &HLT_HIGEDPhoton10_EB_v1_psc, &b_HLT_HIGEDPhoton10_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_EB_v1_acc", &HLT_HIGEDPhoton20_EB_v1_acc, &b_HLT_HIGEDPhoton20_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_EB_v1_psc", &HLT_HIGEDPhoton20_EB_v1_psc, &b_HLT_HIGEDPhoton20_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_EB_v1_acc", &HLT_HIGEDPhoton30_EB_v1_acc, &b_HLT_HIGEDPhoton30_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_EB_v1_psc", &HLT_HIGEDPhoton30_EB_v1_psc, &b_HLT_HIGEDPhoton30_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_EB_v1_acc", &HLT_HIGEDPhoton40_EB_v1_acc, &b_HLT_HIGEDPhoton40_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_EB_v1_psc", &HLT_HIGEDPhoton40_EB_v1_psc, &b_HLT_HIGEDPhoton40_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_EB_v1_acc", &HLT_HIGEDPhoton50_EB_v1_acc, &b_HLT_HIGEDPhoton50_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_EB_v1_psc", &HLT_HIGEDPhoton50_EB_v1_psc, &b_HLT_HIGEDPhoton50_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_EB_v1_acc", &HLT_HIGEDPhoton60_EB_v1_acc, &b_HLT_HIGEDPhoton60_EB_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_EB_v1_psc", &HLT_HIGEDPhoton60_EB_v1_psc, &b_HLT_HIGEDPhoton60_EB_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_HECut_v1_acc", &HLT_HIGEDPhoton10_HECut_v1_acc, &b_HLT_HIGEDPhoton10_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_HECut_v1_psc", &HLT_HIGEDPhoton10_HECut_v1_psc, &b_HLT_HIGEDPhoton10_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_HECut_v1_acc", &HLT_HIGEDPhoton20_HECut_v1_acc, &b_HLT_HIGEDPhoton20_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_HECut_v1_psc", &HLT_HIGEDPhoton20_HECut_v1_psc, &b_HLT_HIGEDPhoton20_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_HECut_v1_acc", &HLT_HIGEDPhoton30_HECut_v1_acc, &b_HLT_HIGEDPhoton30_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_HECut_v1_psc", &HLT_HIGEDPhoton30_HECut_v1_psc, &b_HLT_HIGEDPhoton30_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_HECut_v1_acc", &HLT_HIGEDPhoton40_HECut_v1_acc, &b_HLT_HIGEDPhoton40_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_HECut_v1_psc", &HLT_HIGEDPhoton40_HECut_v1_psc, &b_HLT_HIGEDPhoton40_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_HECut_v1_acc", &HLT_HIGEDPhoton50_HECut_v1_acc, &b_HLT_HIGEDPhoton50_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_HECut_v1_psc", &HLT_HIGEDPhoton50_HECut_v1_psc, &b_HLT_HIGEDPhoton50_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_HECut_v1_acc", &HLT_HIGEDPhoton60_HECut_v1_acc, &b_HLT_HIGEDPhoton60_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_HECut_v1_psc", &HLT_HIGEDPhoton60_HECut_v1_psc, &b_HLT_HIGEDPhoton60_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_EB_HECut_v1_acc", &HLT_HIGEDPhoton10_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton10_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_EB_HECut_v1_psc", &HLT_HIGEDPhoton10_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton10_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_EB_HECut_v1_acc", &HLT_HIGEDPhoton20_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton20_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_EB_HECut_v1_psc", &HLT_HIGEDPhoton20_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton20_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_EB_HECut_v1_acc", &HLT_HIGEDPhoton30_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton30_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_EB_HECut_v1_psc", &HLT_HIGEDPhoton30_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton30_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_EB_HECut_v1_acc", &HLT_HIGEDPhoton40_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton40_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_EB_HECut_v1_psc", &HLT_HIGEDPhoton40_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton40_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_EB_HECut_v1_acc", &HLT_HIGEDPhoton50_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton50_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton50_EB_HECut_v1_psc", &HLT_HIGEDPhoton50_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton50_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_EB_HECut_v1_acc", &HLT_HIGEDPhoton60_EB_HECut_v1_acc, &b_HLT_HIGEDPhoton60_EB_HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton60_EB_HECut_v1_psc", &HLT_HIGEDPhoton60_EB_HECut_v1_psc, &b_HLT_HIGEDPhoton60_EB_HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_v1_acc", &HLT_HIEle10Gsf_v1_acc, &b_HLT_HIEle10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_v1_psc", &HLT_HIEle10Gsf_v1_psc, &b_HLT_HIEle10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_v1_acc", &HLT_HIEle15Gsf_v1_acc, &b_HLT_HIEle15Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_v1_psc", &HLT_HIEle15Gsf_v1_psc, &b_HLT_HIEle15Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_v1_acc", &HLT_HIEle20Gsf_v1_acc, &b_HLT_HIEle20Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_v1_psc", &HLT_HIEle20Gsf_v1_psc, &b_HLT_HIEle20Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle30Gsf_v1_acc", &HLT_HIEle30Gsf_v1_acc, &b_HLT_HIEle30Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle30Gsf_v1_psc", &HLT_HIEle30Gsf_v1_psc, &b_HLT_HIEle30Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle40Gsf_v1_acc", &HLT_HIEle40Gsf_v1_acc, &b_HLT_HIEle40Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle40Gsf_v1_psc", &HLT_HIEle40Gsf_v1_psc, &b_HLT_HIEle40Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle50Gsf_v1_acc", &HLT_HIEle50Gsf_v1_acc, &b_HLT_HIEle50Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle50Gsf_v1_psc", &HLT_HIEle50Gsf_v1_psc, &b_HLT_HIEle50Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Ele10Gsf_v1_acc", &HLT_HIEle15Ele10Gsf_v1_acc, &b_HLT_HIEle15Ele10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Ele10Gsf_v1_psc", &HLT_HIEle15Ele10Gsf_v1_psc, &b_HLT_HIEle15Ele10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Ele10GsfMass50_v1_acc", &HLT_HIEle15Ele10GsfMass50_v1_acc, &b_HLT_HIEle15Ele10GsfMass50_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Ele10GsfMass50_v1_psc", &HLT_HIEle15Ele10GsfMass50_v1_psc, &b_HLT_HIEle15Ele10GsfMass50_v1_psc);
   fChain->SetBranchAddress("HLT_HIDoubleEle10Gsf_v1_acc", &HLT_HIDoubleEle10Gsf_v1_acc, &b_HLT_HIDoubleEle10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIDoubleEle10Gsf_v1_psc", &HLT_HIDoubleEle10Gsf_v1_psc, &b_HLT_HIDoubleEle10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIDoubleEle10GsfMass50_v1_acc", &HLT_HIDoubleEle10GsfMass50_v1_acc, &b_HLT_HIDoubleEle10GsfMass50_v1_acc);
   fChain->SetBranchAddress("HLT_HIDoubleEle10GsfMass50_v1_psc", &HLT_HIDoubleEle10GsfMass50_v1_psc, &b_HLT_HIDoubleEle10GsfMass50_v1_psc);
   fChain->SetBranchAddress("HLT_HIDoubleEle15Gsf_v1_acc", &HLT_HIDoubleEle15Gsf_v1_acc, &b_HLT_HIDoubleEle15Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIDoubleEle15Gsf_v1_psc", &HLT_HIDoubleEle15Gsf_v1_psc, &b_HLT_HIDoubleEle15Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIDoubleEle15GsfMass50_v1_acc", &HLT_HIDoubleEle15GsfMass50_v1_acc, &b_HLT_HIDoubleEle15GsfMass50_v1_acc);
   fChain->SetBranchAddress("HLT_HIDoubleEle15GsfMass50_v1_psc", &HLT_HIDoubleEle15GsfMass50_v1_psc, &b_HLT_HIDoubleEle15GsfMass50_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_acc", &HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_acc, &b_HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_psc", &HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_psc, &b_HLT_HIL1Mu3Eta2p5_Ele10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_acc", &HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_acc, &b_HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_psc", &HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_psc, &b_HLT_HIL1Mu3Eta2p5_Ele15Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_acc", &HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_acc, &b_HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_psc", &HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_psc, &b_HLT_HIL1Mu3Eta2p5_Ele20Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_acc", &HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_acc, &b_HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_psc", &HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_psc, &b_HLT_HIL1Mu5Eta2p5_Ele10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_acc", &HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_acc, &b_HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_psc", &HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_psc, &b_HLT_HIL1Mu5Eta2p5_Ele15Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_acc", &HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_acc, &b_HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_psc", &HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_psc, &b_HLT_HIL1Mu5Eta2p5_Ele20Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_acc", &HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_acc, &b_HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_psc", &HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_psc, &b_HLT_HIL1Mu7Eta2p5_Ele10Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_acc", &HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_acc, &b_HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_psc", &HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_psc, &b_HLT_HIL1Mu7Eta2p5_Ele15Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_acc", &HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_acc, &b_HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_psc", &HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_psc, &b_HLT_HIL1Mu7Eta2p5_Ele20Gsf_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_acc", &HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_acc, &b_HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_psc", &HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_psc, &b_HLT_HIEle10Gsf_PuAK4CaloJet40Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_acc", &HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_acc, &b_HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_psc", &HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_psc, &b_HLT_HIEle10Gsf_PuAK4CaloJet60Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_acc", &HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_acc, &b_HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_psc", &HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_psc, &b_HLT_HIEle10Gsf_PuAK4CaloJet80Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_acc", &HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_acc, &b_HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_psc", &HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_psc, &b_HLT_HIEle10Gsf_PuAK4CaloJet100Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_acc", &HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_acc, &b_HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_psc", &HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_psc, &b_HLT_HIEle15Gsf_PuAK4CaloJet40Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_acc", &HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_acc, &b_HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_psc", &HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_psc, &b_HLT_HIEle15Gsf_PuAK4CaloJet60Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_acc", &HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_acc, &b_HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_psc", &HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_psc, &b_HLT_HIEle15Gsf_PuAK4CaloJet80Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_acc", &HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_acc, &b_HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_psc", &HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_psc, &b_HLT_HIEle15Gsf_PuAK4CaloJet100Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_acc", &HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_acc, &b_HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_psc", &HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_psc, &b_HLT_HIEle20Gsf_PuAK4CaloJet40Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_acc", &HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_acc, &b_HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_psc", &HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_psc, &b_HLT_HIEle20Gsf_PuAK4CaloJet60Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_acc", &HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_acc, &b_HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_psc", &HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_psc, &b_HLT_HIEle20Gsf_PuAK4CaloJet80Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_acc", &HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_acc, &b_HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_psc", &HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_psc, &b_HLT_HIEle20Gsf_PuAK4CaloJet100Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt15_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt20_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt30_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt40_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt50_v1_psc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_acc", &HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_acc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_acc);
   fChain->SetBranchAddress("HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_psc", &HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_psc, &b_HLT_HIDmesonPPTrackingGlobal_Dpt60_v1_psc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt20_v1_acc", &HLT_HIDsPPTrackingGlobal_Dpt20_v1_acc, &b_HLT_HIDsPPTrackingGlobal_Dpt20_v1_acc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt20_v1_psc", &HLT_HIDsPPTrackingGlobal_Dpt20_v1_psc, &b_HLT_HIDsPPTrackingGlobal_Dpt20_v1_psc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt30_v1_acc", &HLT_HIDsPPTrackingGlobal_Dpt30_v1_acc, &b_HLT_HIDsPPTrackingGlobal_Dpt30_v1_acc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt30_v1_psc", &HLT_HIDsPPTrackingGlobal_Dpt30_v1_psc, &b_HLT_HIDsPPTrackingGlobal_Dpt30_v1_psc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt40_v1_acc", &HLT_HIDsPPTrackingGlobal_Dpt40_v1_acc, &b_HLT_HIDsPPTrackingGlobal_Dpt40_v1_acc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt40_v1_psc", &HLT_HIDsPPTrackingGlobal_Dpt40_v1_psc, &b_HLT_HIDsPPTrackingGlobal_Dpt40_v1_psc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt50_v1_acc", &HLT_HIDsPPTrackingGlobal_Dpt50_v1_acc, &b_HLT_HIDsPPTrackingGlobal_Dpt50_v1_acc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt50_v1_psc", &HLT_HIDsPPTrackingGlobal_Dpt50_v1_psc, &b_HLT_HIDsPPTrackingGlobal_Dpt50_v1_psc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt60_v1_acc", &HLT_HIDsPPTrackingGlobal_Dpt60_v1_acc, &b_HLT_HIDsPPTrackingGlobal_Dpt60_v1_acc);
   fChain->SetBranchAddress("HLT_HIDsPPTrackingGlobal_Dpt60_v1_psc", &HLT_HIDsPPTrackingGlobal_Dpt60_v1_psc, &b_HLT_HIDsPPTrackingGlobal_Dpt60_v1_psc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt20_v1_acc", &HLT_HILcPPTrackingGlobal_Dpt20_v1_acc, &b_HLT_HILcPPTrackingGlobal_Dpt20_v1_acc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt20_v1_psc", &HLT_HILcPPTrackingGlobal_Dpt20_v1_psc, &b_HLT_HILcPPTrackingGlobal_Dpt20_v1_psc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt30_v1_acc", &HLT_HILcPPTrackingGlobal_Dpt30_v1_acc, &b_HLT_HILcPPTrackingGlobal_Dpt30_v1_acc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt30_v1_psc", &HLT_HILcPPTrackingGlobal_Dpt30_v1_psc, &b_HLT_HILcPPTrackingGlobal_Dpt30_v1_psc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt40_v1_acc", &HLT_HILcPPTrackingGlobal_Dpt40_v1_acc, &b_HLT_HILcPPTrackingGlobal_Dpt40_v1_acc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt40_v1_psc", &HLT_HILcPPTrackingGlobal_Dpt40_v1_psc, &b_HLT_HILcPPTrackingGlobal_Dpt40_v1_psc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt50_v1_acc", &HLT_HILcPPTrackingGlobal_Dpt50_v1_acc, &b_HLT_HILcPPTrackingGlobal_Dpt50_v1_acc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt50_v1_psc", &HLT_HILcPPTrackingGlobal_Dpt50_v1_psc, &b_HLT_HILcPPTrackingGlobal_Dpt50_v1_psc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt60_v1_acc", &HLT_HILcPPTrackingGlobal_Dpt60_v1_acc, &b_HLT_HILcPPTrackingGlobal_Dpt60_v1_acc);
   fChain->SetBranchAddress("HLT_HILcPPTrackingGlobal_Dpt60_v1_psc", &HLT_HILcPPTrackingGlobal_Dpt60_v1_psc, &b_HLT_HILcPPTrackingGlobal_Dpt60_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt18_v1_acc", &HLT_HIFullTracks2018_HighPt18_v1_acc, &b_HLT_HIFullTracks2018_HighPt18_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt18_v1_psc", &HLT_HIFullTracks2018_HighPt18_v1_psc, &b_HLT_HIFullTracks2018_HighPt18_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt24_v1_acc", &HLT_HIFullTracks2018_HighPt24_v1_acc, &b_HLT_HIFullTracks2018_HighPt24_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt24_v1_psc", &HLT_HIFullTracks2018_HighPt24_v1_psc, &b_HLT_HIFullTracks2018_HighPt24_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt34_v1_acc", &HLT_HIFullTracks2018_HighPt34_v1_acc, &b_HLT_HIFullTracks2018_HighPt34_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt34_v1_psc", &HLT_HIFullTracks2018_HighPt34_v1_psc, &b_HLT_HIFullTracks2018_HighPt34_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt45_v1_acc", &HLT_HIFullTracks2018_HighPt45_v1_acc, &b_HLT_HIFullTracks2018_HighPt45_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt45_v1_psc", &HLT_HIFullTracks2018_HighPt45_v1_psc, &b_HLT_HIFullTracks2018_HighPt45_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt56_v1_acc", &HLT_HIFullTracks2018_HighPt56_v1_acc, &b_HLT_HIFullTracks2018_HighPt56_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt56_v1_psc", &HLT_HIFullTracks2018_HighPt56_v1_psc, &b_HLT_HIFullTracks2018_HighPt56_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt60_v1_acc", &HLT_HIFullTracks2018_HighPt60_v1_acc, &b_HLT_HIFullTracks2018_HighPt60_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks2018_HighPt60_v1_psc", &HLT_HIFullTracks2018_HighPt60_v1_psc, &b_HLT_HIFullTracks2018_HighPt60_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_v1_acc", &HLT_HIL1DoubleMuOpen_v1_acc, &b_HLT_HIL1DoubleMuOpen_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_v1_psc", &HLT_HIL1DoubleMuOpen_v1_psc, &b_HLT_HIL1DoubleMuOpen_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_acc", &HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_acc, &b_HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_psc", &HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_psc, &b_HLT_HIL1DoubleMuOpen_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_acc", &HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_acc, &b_HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_psc", &HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_psc, &b_HLT_HIL1DoubleMuOpen_Centrality_40_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_acc", &HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_acc, &b_HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_psc", &HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_psc, &b_HLT_HIL1DoubleMuOpen_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_er1p6_v1_acc", &HLT_HIL1DoubleMuOpen_er1p6_v1_acc, &b_HLT_HIL1DoubleMuOpen_er1p6_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_er1p6_v1_psc", &HLT_HIL1DoubleMuOpen_er1p6_v1_psc, &b_HLT_HIL1DoubleMuOpen_er1p6_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_er1p6_v1_acc", &HLT_HIL1DoubleMuOpen_OS_er1p6_v1_acc, &b_HLT_HIL1DoubleMuOpen_OS_er1p6_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_er1p6_v1_psc", &HLT_HIL1DoubleMuOpen_OS_er1p6_v1_psc, &b_HLT_HIL1DoubleMuOpen_OS_er1p6_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_acc", &HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_acc, &b_HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_psc", &HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_psc, &b_HLT_HIL1DoubleMuOpen_OS_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_acc", &HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_acc, &b_HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_psc", &HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_psc, &b_HLT_HIL1DoubleMuOpen_OS_Centrality_40_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMu0_v1_acc", &HLT_HIL1DoubleMu0_v1_acc, &b_HLT_HIL1DoubleMu0_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMu0_v1_psc", &HLT_HIL1DoubleMu0_v1_psc, &b_HLT_HIL1DoubleMu0_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMu10_v1_acc", &HLT_HIL1DoubleMu10_v1_acc, &b_HLT_HIL1DoubleMu10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1DoubleMu10_v1_psc", &HLT_HIL1DoubleMu10_v1_psc, &b_HLT_HIL1DoubleMu10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL2_L1DoubleMu10_v1_acc", &HLT_HIL2_L1DoubleMu10_v1_acc, &b_HLT_HIL2_L1DoubleMu10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL2_L1DoubleMu10_v1_psc", &HLT_HIL2_L1DoubleMu10_v1_psc, &b_HLT_HIL2_L1DoubleMu10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3_L1DoubleMu10_v1_acc", &HLT_HIL3_L1DoubleMu10_v1_acc, &b_HLT_HIL3_L1DoubleMu10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3_L1DoubleMu10_v1_psc", &HLT_HIL3_L1DoubleMu10_v1_psc, &b_HLT_HIL3_L1DoubleMu10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL2DoubleMuOpen_v1_acc", &HLT_HIL2DoubleMuOpen_v1_acc, &b_HLT_HIL2DoubleMuOpen_v1_acc);
   fChain->SetBranchAddress("HLT_HIL2DoubleMuOpen_v1_psc", &HLT_HIL2DoubleMuOpen_v1_psc, &b_HLT_HIL2DoubleMuOpen_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_v1_acc", &HLT_HIL3DoubleMuOpen_v1_acc, &b_HLT_HIL3DoubleMuOpen_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_v1_psc", &HLT_HIL3DoubleMuOpen_v1_psc, &b_HLT_HIL3DoubleMuOpen_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_M60120_v1_acc", &HLT_HIL3DoubleMuOpen_M60120_v1_acc, &b_HLT_HIL3DoubleMuOpen_M60120_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_M60120_v1_psc", &HLT_HIL3DoubleMuOpen_M60120_v1_psc, &b_HLT_HIL3DoubleMuOpen_M60120_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_JpsiPsi_v1_acc", &HLT_HIL3DoubleMuOpen_JpsiPsi_v1_acc, &b_HLT_HIL3DoubleMuOpen_JpsiPsi_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_JpsiPsi_v1_psc", &HLT_HIL3DoubleMuOpen_JpsiPsi_v1_psc, &b_HLT_HIL3DoubleMuOpen_JpsiPsi_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_Upsi_v1_acc", &HLT_HIL3DoubleMuOpen_Upsi_v1_acc, &b_HLT_HIL3DoubleMuOpen_Upsi_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3DoubleMuOpen_Upsi_v1_psc", &HLT_HIL3DoubleMuOpen_Upsi_v1_psc, &b_HLT_HIL3DoubleMuOpen_Upsi_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu0_L2Mu0_v1_acc", &HLT_HIL3Mu0_L2Mu0_v1_acc, &b_HLT_HIL3Mu0_L2Mu0_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu0_L2Mu0_v1_psc", &HLT_HIL3Mu0_L2Mu0_v1_psc, &b_HLT_HIL3Mu0_L2Mu0_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_acc", &HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_acc, &b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_psc", &HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_psc, &b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1MuOpen_Centrality_70_100_v1_acc", &HLT_HIL1MuOpen_Centrality_70_100_v1_acc, &b_HLT_HIL1MuOpen_Centrality_70_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1MuOpen_Centrality_70_100_v1_psc", &HLT_HIL1MuOpen_Centrality_70_100_v1_psc, &b_HLT_HIL1MuOpen_Centrality_70_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1MuOpen_Centrality_80_100_v1_acc", &HLT_HIL1MuOpen_Centrality_80_100_v1_acc, &b_HLT_HIL1MuOpen_Centrality_80_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1MuOpen_Centrality_80_100_v1_psc", &HLT_HIL1MuOpen_Centrality_80_100_v1_psc, &b_HLT_HIL1MuOpen_Centrality_80_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL2Mu3_NHitQ15_v1_acc", &HLT_HIL2Mu3_NHitQ15_v1_acc, &b_HLT_HIL2Mu3_NHitQ15_v1_acc);
   fChain->SetBranchAddress("HLT_HIL2Mu3_NHitQ15_v1_psc", &HLT_HIL2Mu3_NHitQ15_v1_psc, &b_HLT_HIL2Mu3_NHitQ15_v1_psc);
   fChain->SetBranchAddress("HLT_HIL2Mu5_NHitQ15_v1_acc", &HLT_HIL2Mu5_NHitQ15_v1_acc, &b_HLT_HIL2Mu5_NHitQ15_v1_acc);
   fChain->SetBranchAddress("HLT_HIL2Mu5_NHitQ15_v1_psc", &HLT_HIL2Mu5_NHitQ15_v1_psc, &b_HLT_HIL2Mu5_NHitQ15_v1_psc);
   fChain->SetBranchAddress("HLT_HIL2Mu7_NHitQ15_v1_acc", &HLT_HIL2Mu7_NHitQ15_v1_acc, &b_HLT_HIL2Mu7_NHitQ15_v1_acc);
   fChain->SetBranchAddress("HLT_HIL2Mu7_NHitQ15_v1_psc", &HLT_HIL2Mu7_NHitQ15_v1_psc, &b_HLT_HIL2Mu7_NHitQ15_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5_L1DoubleMu0_v1_acc", &HLT_HIL3Mu2p5_L1DoubleMu0_v1_acc, &b_HLT_HIL3Mu2p5_L1DoubleMu0_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5_L1DoubleMu0_v1_psc", &HLT_HIL3Mu2p5_L1DoubleMu0_v1_psc, &b_HLT_HIL3Mu2p5_L1DoubleMu0_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_acc", &HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_acc, &b_HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_psc", &HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_psc, &b_HLT_HIL3Mu3_L1DoubleMuOpen_OS_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_acc", &HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_acc, &b_HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_psc", &HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_psc, &b_HLT_HIL3Mu3NHitQ10_L1DoubleMuOpen_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_L1TripleMuOpen_v1_acc", &HLT_HIL3Mu3_L1TripleMuOpen_v1_acc, &b_HLT_HIL3Mu3_L1TripleMuOpen_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_L1TripleMuOpen_v1_psc", &HLT_HIL3Mu3_L1TripleMuOpen_v1_psc, &b_HLT_HIL3Mu3_L1TripleMuOpen_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu12_v1_acc", &HLT_HIL3Mu12_v1_acc, &b_HLT_HIL3Mu12_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu12_v1_psc", &HLT_HIL3Mu12_v1_psc, &b_HLT_HIL3Mu12_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu15_v1_acc", &HLT_HIL3Mu15_v1_acc, &b_HLT_HIL3Mu15_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu15_v1_psc", &HLT_HIL3Mu15_v1_psc, &b_HLT_HIL3Mu15_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu20_v1_acc", &HLT_HIL3Mu20_v1_acc, &b_HLT_HIL3Mu20_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu20_v1_psc", &HLT_HIL3Mu20_v1_psc, &b_HLT_HIL3Mu20_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_NHitQ10_v1_acc", &HLT_HIL3Mu3_NHitQ10_v1_acc, &b_HLT_HIL3Mu3_NHitQ10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_NHitQ10_v1_psc", &HLT_HIL3Mu3_NHitQ10_v1_psc, &b_HLT_HIL3Mu3_NHitQ10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_NHitQ10_v1_acc", &HLT_HIL3Mu5_NHitQ10_v1_acc, &b_HLT_HIL3Mu5_NHitQ10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_NHitQ10_v1_psc", &HLT_HIL3Mu5_NHitQ10_v1_psc, &b_HLT_HIL3Mu5_NHitQ10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_NHitQ10_v1_acc", &HLT_HIL3Mu7_NHitQ10_v1_acc, &b_HLT_HIL3Mu7_NHitQ10_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_NHitQ10_v1_psc", &HLT_HIL3Mu7_NHitQ10_v1_psc, &b_HLT_HIL3Mu7_NHitQ10_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_acc", &HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_acc, &b_HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_psc", &HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_psc, &b_HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_acc", &HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_acc, &b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_psc", &HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_psc, &b_HLT_HIL3Mu2p5NHitQ10_L2Mu2_M7toinf_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc", &HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc, &b_HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc", &HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc, &b_HLT_HIL1_ETT8_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc", &HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc, &b_HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc", &HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc, &b_HLT_HIL1_ETT10_ETTAsym50_MinimumBiasHF1_OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF1AND_v1_acc", &HLT_HIFullTracks_Multiplicity020_HF1AND_v1_acc, &b_HLT_HIFullTracks_Multiplicity020_HF1AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF1AND_v1_psc", &HLT_HIFullTracks_Multiplicity020_HF1AND_v1_psc, &b_HLT_HIFullTracks_Multiplicity020_HF1AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_acc", &HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_acc, &b_HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_psc", &HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_psc, &b_HLT_HIFullTracks_Multiplicity2040_HF1AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity4060_v1_acc", &HLT_HIFullTracks_Multiplicity4060_v1_acc, &b_HLT_HIFullTracks_Multiplicity4060_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity4060_v1_psc", &HLT_HIFullTracks_Multiplicity4060_v1_psc, &b_HLT_HIFullTracks_Multiplicity4060_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity6080_v1_acc", &HLT_HIFullTracks_Multiplicity6080_v1_acc, &b_HLT_HIFullTracks_Multiplicity6080_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity6080_v1_psc", &HLT_HIFullTracks_Multiplicity6080_v1_psc, &b_HLT_HIFullTracks_Multiplicity6080_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity80100_v1_acc", &HLT_HIFullTracks_Multiplicity80100_v1_acc, &b_HLT_HIFullTracks_Multiplicity80100_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity80100_v1_psc", &HLT_HIFullTracks_Multiplicity80100_v1_psc, &b_HLT_HIFullTracks_Multiplicity80100_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_v1_acc", &HLT_HIFullTracks_Multiplicity020_v1_acc, &b_HLT_HIFullTracks_Multiplicity020_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_v1_psc", &HLT_HIFullTracks_Multiplicity020_v1_psc, &b_HLT_HIFullTracks_Multiplicity020_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF1OR_v1_acc", &HLT_HIFullTracks_Multiplicity020_HF1OR_v1_acc, &b_HLT_HIFullTracks_Multiplicity020_HF1OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF1OR_v1_psc", &HLT_HIFullTracks_Multiplicity020_HF1OR_v1_psc, &b_HLT_HIFullTracks_Multiplicity020_HF1OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF2OR_v1_acc", &HLT_HIFullTracks_Multiplicity020_HF2OR_v1_acc, &b_HLT_HIFullTracks_Multiplicity020_HF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity020_HF2OR_v1_psc", &HLT_HIFullTracks_Multiplicity020_HF2OR_v1_psc, &b_HLT_HIFullTracks_Multiplicity020_HF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_v1_acc", &HLT_HIFullTracks_Multiplicity2040_v1_acc, &b_HLT_HIFullTracks_Multiplicity2040_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_v1_psc", &HLT_HIFullTracks_Multiplicity2040_v1_psc, &b_HLT_HIFullTracks_Multiplicity2040_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_acc", &HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_acc, &b_HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_psc", &HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_psc, &b_HLT_HIFullTracks_Multiplicity2040_HF1OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_acc", &HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_acc, &b_HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_psc", &HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_psc, &b_HLT_HIFullTracks_Multiplicity2040_HF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_Mu8_Mu13_v1_acc", &HLT_HIUPC_Mu8_Mu13_v1_acc, &b_HLT_HIUPC_Mu8_Mu13_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_Mu8_Mu13_v1_psc", &HLT_HIUPC_Mu8_Mu13_v1_psc, &b_HLT_HIUPC_Mu8_Mu13_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_acc", &HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_psc", &HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_Mu8_Mu13_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMuOpen_BptxAND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleMuOpen_BptxAND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_acc", &HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_psc", &HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_acc", &HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_psc", &HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_DoubleMuOpen_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_acc", &HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_psc", &HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_SingleMuOpen_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_acc", &HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_psc", &HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_SingleMu0_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_acc", &HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_psc", &HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_acc", &HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_psc", &HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_DoubleMu0_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_acc", &HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_psc", &HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_SingleMu0_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMu3_NotMBHF2OR_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_acc", &HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_psc", &HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_SingleMu3_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMu0_BptxAND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleMu0_BptxAND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleMu3_BptxAND_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_acc", &HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_psc", &HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_NotMBHF2AND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_v1_acc", &HLT_HIUPC_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2AND_v1_psc", &HLT_HIUPC_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_acc", &HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_psc", &HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_NotMBHF2OR_BptxAND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_acc", &HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_psc", &HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_ZeroBias_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG2_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_acc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_psc", &HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_DoubleEG2_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_acc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_psc", &HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_DoubleEG5_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG5_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc", &HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc", &HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG3_BptxAND_SinglePixelTrack_MaxPixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_acc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_psc", &HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_SingleEG3_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_acc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_psc", &HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_SingleEG5_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_acc", &HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_acc, &b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_psc", &HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_psc, &b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_acc", &HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_acc, &b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_acc);
   fChain->SetBranchAddress("HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_psc", &HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_psc, &b_HLT_HIUPC_ETT5_Asym50_NotMBHF2OR_SinglePixelTrack_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_v1_acc", &HLT_HICsAK4PFJet60Eta1p5_v1_acc, &b_HLT_HICsAK4PFJet60Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_v1_psc", &HLT_HICsAK4PFJet60Eta1p5_v1_psc, &b_HLT_HICsAK4PFJet60Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_v1_acc", &HLT_HICsAK4PFJet80Eta1p5_v1_acc, &b_HLT_HICsAK4PFJet80Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_v1_psc", &HLT_HICsAK4PFJet80Eta1p5_v1_psc, &b_HLT_HICsAK4PFJet80Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_v1_acc", &HLT_HICsAK4PFJet100Eta1p5_v1_acc, &b_HLT_HICsAK4PFJet100Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_v1_psc", &HLT_HICsAK4PFJet100Eta1p5_v1_psc, &b_HLT_HICsAK4PFJet100Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_acc", &HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_acc, &b_HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_psc", &HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_psc, &b_HLT_HICsAK4PFJet100Eta1p5_Beamspot_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet120Eta1p5_v1_acc", &HLT_HICsAK4PFJet120Eta1p5_v1_acc, &b_HLT_HICsAK4PFJet120Eta1p5_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet120Eta1p5_v1_psc", &HLT_HICsAK4PFJet120Eta1p5_v1_psc, &b_HLT_HICsAK4PFJet120Eta1p5_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_acc", &HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_acc, &b_HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_psc", &HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_psc, &b_HLT_HICsAK4PFJet60Eta1p5_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_acc", &HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_acc, &b_HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_psc", &HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_psc, &b_HLT_HICsAK4PFJet60Eta1p5_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_acc", &HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_acc, &b_HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_psc", &HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_psc, &b_HLT_HICsAK4PFJet80Eta1p5_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_acc", &HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_acc, &b_HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_psc", &HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_psc, &b_HLT_HICsAK4PFJet80Eta1p5_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_acc", &HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_acc, &b_HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_psc", &HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_psc, &b_HLT_HICsAK4PFJet100Eta1p5_Centrality_30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_acc", &HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_acc, &b_HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_psc", &HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_psc, &b_HLT_HICsAK4PFJet100Eta1p5_Centrality_50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG10HECut_v1_acc", &HLT_HIL3Mu3_EG10HECut_v1_acc, &b_HLT_HIL3Mu3_EG10HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG10HECut_v1_psc", &HLT_HIL3Mu3_EG10HECut_v1_psc, &b_HLT_HIL3Mu3_EG10HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG15HECut_v1_acc", &HLT_HIL3Mu3_EG15HECut_v1_acc, &b_HLT_HIL3Mu3_EG15HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG15HECut_v1_psc", &HLT_HIL3Mu3_EG15HECut_v1_psc, &b_HLT_HIL3Mu3_EG15HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG20HECut_v1_acc", &HLT_HIL3Mu3_EG20HECut_v1_acc, &b_HLT_HIL3Mu3_EG20HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG20HECut_v1_psc", &HLT_HIL3Mu3_EG20HECut_v1_psc, &b_HLT_HIL3Mu3_EG20HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG30HECut_v1_acc", &HLT_HIL3Mu3_EG30HECut_v1_acc, &b_HLT_HIL3Mu3_EG30HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3_EG30HECut_v1_psc", &HLT_HIL3Mu3_EG30HECut_v1_psc, &b_HLT_HIL3Mu3_EG30HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG10HECut_v1_acc", &HLT_HIL3Mu5_EG10HECut_v1_acc, &b_HLT_HIL3Mu5_EG10HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG10HECut_v1_psc", &HLT_HIL3Mu5_EG10HECut_v1_psc, &b_HLT_HIL3Mu5_EG10HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG15HECut_v1_acc", &HLT_HIL3Mu5_EG15HECut_v1_acc, &b_HLT_HIL3Mu5_EG15HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG15HECut_v1_psc", &HLT_HIL3Mu5_EG15HECut_v1_psc, &b_HLT_HIL3Mu5_EG15HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG20HECut_v1_acc", &HLT_HIL3Mu5_EG20HECut_v1_acc, &b_HLT_HIL3Mu5_EG20HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG20HECut_v1_psc", &HLT_HIL3Mu5_EG20HECut_v1_psc, &b_HLT_HIL3Mu5_EG20HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG30HECut_v1_acc", &HLT_HIL3Mu5_EG30HECut_v1_acc, &b_HLT_HIL3Mu5_EG30HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5_EG30HECut_v1_psc", &HLT_HIL3Mu5_EG30HECut_v1_psc, &b_HLT_HIL3Mu5_EG30HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG10HECut_v1_acc", &HLT_HIL3Mu7_EG10HECut_v1_acc, &b_HLT_HIL3Mu7_EG10HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG10HECut_v1_psc", &HLT_HIL3Mu7_EG10HECut_v1_psc, &b_HLT_HIL3Mu7_EG10HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG15HECut_v1_acc", &HLT_HIL3Mu7_EG15HECut_v1_acc, &b_HLT_HIL3Mu7_EG15HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG15HECut_v1_psc", &HLT_HIL3Mu7_EG15HECut_v1_psc, &b_HLT_HIL3Mu7_EG15HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG20HECut_v1_acc", &HLT_HIL3Mu7_EG20HECut_v1_acc, &b_HLT_HIL3Mu7_EG20HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG20HECut_v1_psc", &HLT_HIL3Mu7_EG20HECut_v1_psc, &b_HLT_HIL3Mu7_EG20HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG30HECut_v1_acc", &HLT_HIL3Mu7_EG30HECut_v1_acc, &b_HLT_HIL3Mu7_EG30HECut_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu7_EG30HECut_v1_psc", &HLT_HIL3Mu7_EG30HECut_v1_psc, &b_HLT_HIL3Mu7_EG30HECut_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu3Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet40Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet60Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet80Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_acc);
   fChain->SetBranchAddress("HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc", &HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc, &b_HLT_HIL3Mu5Eta2p5_PuAK4CaloJet100Eta2p1_FilterDr_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_NotMBHF2AND_v1_acc", &HLT_HICastor_MediumJet_NotMBHF2AND_v1_acc, &b_HLT_HICastor_MediumJet_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_NotMBHF2AND_v1_psc", &HLT_HICastor_MediumJet_NotMBHF2AND_v1_psc, &b_HLT_HICastor_MediumJet_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_NotMBHF2OR_v1_acc", &HLT_HICastor_MediumJet_NotMBHF2OR_v1_acc, &b_HLT_HICastor_MediumJet_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_NotMBHF2OR_v1_psc", &HLT_HICastor_MediumJet_NotMBHF2OR_v1_psc, &b_HLT_HICastor_MediumJet_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_acc", &HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_acc, &b_HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_psc", &HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_psc, &b_HLT_HICastor_MediumJet_MBHF1OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_acc", &HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_acc, &b_HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_psc", &HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_psc, &b_HLT_HICastor_MediumJet_SingleMu0_MBHF1OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_acc", &HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_acc, &b_HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_psc", &HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_psc, &b_HLT_HICastor_MediumJet_SingleEG5_MBHF1OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_BptxAND_v1_acc", &HLT_HICastor_MediumJet_BptxAND_v1_acc, &b_HLT_HICastor_MediumJet_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_BptxAND_v1_psc", &HLT_HICastor_MediumJet_BptxAND_v1_psc, &b_HLT_HICastor_MediumJet_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_v1_acc", &HLT_HICastor_MediumJet_v1_acc, &b_HLT_HICastor_MediumJet_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_MediumJet_v1_psc", &HLT_HICastor_MediumJet_v1_psc, &b_HLT_HICastor_MediumJet_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_v1_acc", &HLT_HICastor_HighJet_v1_acc, &b_HLT_HICastor_HighJet_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_v1_psc", &HLT_HICastor_HighJet_v1_psc, &b_HLT_HICastor_HighJet_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_BptxAND_v1_acc", &HLT_HICastor_HighJet_BptxAND_v1_acc, &b_HLT_HICastor_HighJet_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_BptxAND_v1_psc", &HLT_HICastor_HighJet_BptxAND_v1_psc, &b_HLT_HICastor_HighJet_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_acc", &HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_acc, &b_HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_psc", &HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_psc, &b_HLT_HICastor_HighJet_MBHF1OR_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_NotMBHF2OR_v1_acc", &HLT_HICastor_HighJet_NotMBHF2OR_v1_acc, &b_HLT_HICastor_HighJet_NotMBHF2OR_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_NotMBHF2OR_v1_psc", &HLT_HICastor_HighJet_NotMBHF2OR_v1_psc, &b_HLT_HICastor_HighJet_NotMBHF2OR_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_NotMBHF2AND_v1_acc", &HLT_HICastor_HighJet_NotMBHF2AND_v1_acc, &b_HLT_HICastor_HighJet_NotMBHF2AND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_HighJet_NotMBHF2AND_v1_psc", &HLT_HICastor_HighJet_NotMBHF2AND_v1_psc, &b_HLT_HICastor_HighJet_NotMBHF2AND_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_Muon_v1_acc", &HLT_HICastor_Muon_v1_acc, &b_HLT_HICastor_Muon_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_Muon_v1_psc", &HLT_HICastor_Muon_v1_psc, &b_HLT_HICastor_Muon_v1_psc);
   fChain->SetBranchAddress("HLT_HICastor_Muon_BptxAND_v1_acc", &HLT_HICastor_Muon_BptxAND_v1_acc, &b_HLT_HICastor_Muon_BptxAND_v1_acc);
   fChain->SetBranchAddress("HLT_HICastor_Muon_BptxAND_v1_psc", &HLT_HICastor_Muon_BptxAND_v1_psc, &b_HLT_HICastor_Muon_BptxAND_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_acc", &HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_acc, &b_HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_psc", &HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_psc, &b_HLT_HIIslandPhoton10_Eta2p4_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_acc", &HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_acc, &b_HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_psc", &HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_psc, &b_HLT_HIIslandPhoton20_Eta2p4_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_acc", &HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_acc, &b_HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_psc", &HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_psc, &b_HLT_HIIslandPhoton30_Eta2p4_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_acc", &HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_acc, &b_HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_psc", &HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_psc, &b_HLT_HIIslandPhoton40_Eta2p4_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_acc", &HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_acc, &b_HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_psc", &HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_psc, &b_HLT_HIIslandPhoton10_Eta2p4_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_acc", &HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_acc, &b_HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_psc", &HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_psc, &b_HLT_HIIslandPhoton20_Eta2p4_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_acc", &HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_acc, &b_HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_psc", &HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_psc, &b_HLT_HIIslandPhoton30_Eta2p4_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_acc", &HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_acc, &b_HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_psc", &HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_psc, &b_HLT_HIIslandPhoton40_Eta2p4_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_Cent30_100_v1_acc", &HLT_HIGEDPhoton10_Cent30_100_v1_acc, &b_HLT_HIGEDPhoton10_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_Cent30_100_v1_psc", &HLT_HIGEDPhoton10_Cent30_100_v1_psc, &b_HLT_HIGEDPhoton10_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_Cent30_100_v1_acc", &HLT_HIGEDPhoton20_Cent30_100_v1_acc, &b_HLT_HIGEDPhoton20_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_Cent30_100_v1_psc", &HLT_HIGEDPhoton20_Cent30_100_v1_psc, &b_HLT_HIGEDPhoton20_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_Cent30_100_v1_acc", &HLT_HIGEDPhoton30_Cent30_100_v1_acc, &b_HLT_HIGEDPhoton30_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_Cent30_100_v1_psc", &HLT_HIGEDPhoton30_Cent30_100_v1_psc, &b_HLT_HIGEDPhoton30_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_Cent30_100_v1_acc", &HLT_HIGEDPhoton40_Cent30_100_v1_acc, &b_HLT_HIGEDPhoton40_Cent30_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_Cent30_100_v1_psc", &HLT_HIGEDPhoton40_Cent30_100_v1_psc, &b_HLT_HIGEDPhoton40_Cent30_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_Cent50_100_v1_acc", &HLT_HIGEDPhoton10_Cent50_100_v1_acc, &b_HLT_HIGEDPhoton10_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton10_Cent50_100_v1_psc", &HLT_HIGEDPhoton10_Cent50_100_v1_psc, &b_HLT_HIGEDPhoton10_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_Cent50_100_v1_acc", &HLT_HIGEDPhoton20_Cent50_100_v1_acc, &b_HLT_HIGEDPhoton20_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton20_Cent50_100_v1_psc", &HLT_HIGEDPhoton20_Cent50_100_v1_psc, &b_HLT_HIGEDPhoton20_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_Cent50_100_v1_acc", &HLT_HIGEDPhoton30_Cent50_100_v1_acc, &b_HLT_HIGEDPhoton30_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton30_Cent50_100_v1_psc", &HLT_HIGEDPhoton30_Cent50_100_v1_psc, &b_HLT_HIGEDPhoton30_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_Cent50_100_v1_acc", &HLT_HIGEDPhoton40_Cent50_100_v1_acc, &b_HLT_HIGEDPhoton40_Cent50_100_v1_acc);
   fChain->SetBranchAddress("HLT_HIGEDPhoton40_Cent50_100_v1_psc", &HLT_HIGEDPhoton40_Cent50_100_v1_psc, &b_HLT_HIGEDPhoton40_Cent50_100_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_acc", &HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_acc, &b_HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_psc", &HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_psc, &b_HLT_HIPuAK4CaloJet60Eta2p4_DeepCSV0p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_acc", &HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_acc, &b_HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_psc", &HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_psc, &b_HLT_HIPuAK4CaloJet80Eta2p4_DeepCSV0p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_acc", &HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_acc, &b_HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_psc", &HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_psc, &b_HLT_HIPuAK4CaloJet100Eta2p4_DeepCSV0p4_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_acc", &HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_acc, &b_HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_psc", &HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_psc, &b_HLT_HIPuAK4CaloJet60Eta2p4_CSVv2WP0p75_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_acc", &HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_acc, &b_HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_psc", &HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_psc, &b_HLT_HIPuAK4CaloJet80Eta2p4_CSVv2WP0p75_v1_psc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_acc", &HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_acc, &b_HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_acc);
   fChain->SetBranchAddress("HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_psc", &HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_psc, &b_HLT_HIPuAK4CaloJet100Eta2p4_CSVv2WP0p75_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1NotBptxOR_v1_acc", &HLT_HIL1NotBptxOR_v1_acc, &b_HLT_HIL1NotBptxOR_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1NotBptxOR_v1_psc", &HLT_HIL1NotBptxOR_v1_psc, &b_HLT_HIL1NotBptxOR_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1UnpairedBunchBptxMinus_v1_acc", &HLT_HIL1UnpairedBunchBptxMinus_v1_acc, &b_HLT_HIL1UnpairedBunchBptxMinus_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1UnpairedBunchBptxMinus_v1_psc", &HLT_HIL1UnpairedBunchBptxMinus_v1_psc, &b_HLT_HIL1UnpairedBunchBptxMinus_v1_psc);
   fChain->SetBranchAddress("HLT_HIL1UnpairedBunchBptxPlus_v1_acc", &HLT_HIL1UnpairedBunchBptxPlus_v1_acc, &b_HLT_HIL1UnpairedBunchBptxPlus_v1_acc);
   fChain->SetBranchAddress("HLT_HIL1UnpairedBunchBptxPlus_v1_psc", &HLT_HIL1UnpairedBunchBptxPlus_v1_psc, &b_HLT_HIL1UnpairedBunchBptxPlus_v1_psc);
   fChain->SetBranchAddress("HLTriggerFinalPath_acc", &HLTriggerFinalPath_acc, &b_HLTriggerFinalPath_acc);
   fChain->SetBranchAddress("HLTriggerFinalPath_psc", &HLTriggerFinalPath_psc, &b_HLTriggerFinalPath_psc);
   Notify();
}

Bool_t zdcTreeClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void zdcTreeClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t zdcTreeClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef zdcTreeClass_cxx
