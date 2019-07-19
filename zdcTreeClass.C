#define zdcTreeClass_cxx
#include "zdcTreeClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;


const int nBins = 200; // table of bin edges
   const double binTable[nBins+1] = {0, 10.5072, 11.2099, 11.8364, 12.478, 13.1194, 13.7623, 14.4081, 15.0709, 15.7532, 16.4673, 17.1881, 17.923, 18.673, 19.4865, 20.3033, 21.1536, 22.0086, 22.9046, 23.8196, 24.7924, 25.8082, 26.8714, 27.9481, 29.0828, 30.2757, 31.5043, 32.8044, 34.1572, 35.6142, 37.1211, 38.6798, 40.3116, 42.0398, 43.8572, 45.6977, 47.6312, 49.6899, 51.815, 54.028, 56.3037, 58.7091, 61.2024, 63.8353, 66.5926, 69.3617, 72.2068, 75.2459, 78.3873, 81.5916, 84.9419, 88.498, 92.1789, 95.9582, 99.8431, 103.739, 107.78, 111.97, 116.312, 120.806, 125.46, 130.269, 135.247, 140.389, 145.713, 151.212, 156.871, 162.729, 168.762, 174.998, 181.424, 188.063, 194.907, 201.942, 209.19, 216.683, 224.37, 232.291, 240.43, 248.807, 257.416, 266.256, 275.348, 284.668, 294.216, 304.053, 314.142, 324.488, 335.101, 345.974, 357.116, 368.547, 380.283, 392.29, 404.564, 417.122, 429.968, 443.116, 456.577, 470.357, 484.422, 498.78, 513.473, 528.479, 543.813, 559.445, 575.411, 591.724, 608.352, 625.344, 642.686, 660.361, 678.371, 696.749, 715.485, 734.608, 754.068, 773.846, 794.046, 814.649, 835.608, 856.972, 878.719, 900.887, 923.409, 946.374, 969.674, 993.435, 1017.62, 1042.21, 1067.28, 1092.72, 1118.64, 1144.96, 1171.71, 1198.98, 1226.67, 1254.82, 1283.46, 1312.65, 1342.21, 1372.27, 1402.85, 1433.93, 1465.49, 1497.62, 1530.29, 1563.49, 1597.22, 1631.49, 1666.37, 1701.8, 1737.75, 1774.35, 1811.51, 1849.29, 1887.75, 1926.79, 1966.6, 2006.97, 2047.99, 2089.71, 2132.1, 2175.23, 2219.17, 2263.72, 2309.2, 2355.43, 2402.47, 2450.33, 2499.05, 2548.66, 2599.16, 2650.59, 2703.03, 2756.32, 2810.75, 2866.27, 2922.91, 2980.54, 3039.47, 3099.53, 3160.98, 3223.66, 3287.71, 3353.18, 3420.34, 3489.13, 3559.72, 3632.06, 3706.18, 3782.42, 3860.78, 3941.42, 4024.52, 4110.27, 4199.4, 4292.8, 4394.49, 4519.52, 5199.95};
      
   int getHiBinFromhiHF(const double hiHF)
   {
        int binPos = -1;
        for(int i = 0; i < nBins; ++i){
          if(hiHF >= binTable[i] && hiHF < binTable[i+1]){
            binPos = i;
            break;
          }
        }
      
        binPos = nBins - 1 - binPos;
      
        return (int)(200*((double)binPos)/((double)nBins)); 
   }


void zdcTreeClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L zdcTreeClass.C
//      root> zdcTreeClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   
   fChain->SetBranchStatus("*",0); //turns off all branches
   fChain->SetBranchStatus("zside",1); //turnns on branch
   fChain->SetBranchStatus("section",1); //turnns on branch
   fChain->SetBranchStatus("channel",1); //turnns on branch
   fChain->SetBranchStatus("nTrack",1); //turnns on branch
   fChain->SetBranchStatus("nAcceptedTracks",1); //turnns on branch
   fChain->SetBranchStatus("Cent",1); //turnns on branch
   fChain->SetBranchStatus("phi",1); //turnns on branch
   fChain->SetBranchStatus("eta",1); //turnns on branch
   fChain->SetBranchStatus("Pt",1); //turnns on branch
   fChain->SetBranchStatus("chi2",1); //turnns on branch
   fChain->SetBranchStatus("nfC0", 1);// turns branch on
   fChain->SetBranchStatus("nfC1", 1);// turns branch on
   fChain->SetBranchStatus("nfC2", 1);// turns branch on
   fChain->SetBranchStatus("nfC3", 1);// turns branch on
   fChain->SetBranchStatus("nfC4", 1);// turns branch on
   fChain->SetBranchStatus("nfC5", 1);// turns branch on
   fChain->SetBranchStatus("nfC6", 1);// turns branch on
   fChain->SetBranchStatus("nfC7", 1);// turns branch on
   fChain->SetBranchStatus("nfC8", 1);// turns branch on
   fChain->SetBranchStatus("nfC9", 1);// turns branch on

   TH1D* PtDist;
   TH1D* EtaDist;

    //PtDist = new TH1D("PtDist", "PtDist",1000,0, 10000);
    
    EtaDist = new TH1D("EtaDist", "EtaDist",100,-10, 10);
    PtDist = new TH1D("PtDist", "PtDist",100,-10, 10);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   cout << "#entries" << nentries << endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //cout << "NumberofTracks " << nTrack << endl;
      //cout << "accNumberofTracks " << nAcceptedTracks << endl;
     // double Centrality = Cent;

      //double centBin = getHiBinFromhiHF(Centrality);

     // cout << "centBin" << centBin << endl;

      for (int k = 0; k < nAcceptedTracks; k++){
         double PhiValues = phi->at(k);
         double EtaValues = eta->at(k);
         double PtValues = Pt->at(k);
         double chi2Values = chi2->at(k);

        // cout << "phi " << k << ": " << PhiValues << endl;
       // cout << "eta " << k << ": " << EtaValues << endl;
        // cout << "Pt "  << k << ": " << PtValues << endl;
        // cout << "chi2" << k << ":" << chi2Values << endl;
         PtDist->Fill(PtValues); //this line causes a exceeding size of vector error
         EtaDist->Fill(EtaValues);
         
      }
      if(jentry % 100000 == 0) cout << jentry << " events are processed." << endl;
   }

   EtaDist->Draw("HIST E");
   PtDist->Draw("HIST E");

}

