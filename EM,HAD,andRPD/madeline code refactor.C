#include <iostream>
#include <string>
using namespace std;



class ZDC_Data_Structure(){
  private:
  //type
  int EM = 0;
  int HAD = 1;
  int RPD = 3;
  //quantity
  int NSIDE = 2;
  int NEM= 5;
  int NHAD = 4;
  int NRPD = 16;
  int NTS = 10;
  int num_channels = 50;
  //correction for inversion
  
  for( int iTS = 0; iTS < NTS; iTS++) {
    fCleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
    fCPureleaf[iTS] = (TLeaf*) ZDCDigiTree->GetLeaf(Form("nfC%d",iTS));
  }
  
  int INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[NRPD] = {13, 12, 15, 14, 9, 11, 8, 10, 5, 4, 7, 6, 1, 0, 3, 2}; //tenative needs to be checked
  public:

  double  RawDataEM[NSIDE][NEM][NTS] = {{{0}, {0}, {0}, {0}, {0}},   //neg
                                       {{0}, {0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

  double RawDataHAD[NSIDE][NHAD][NTS] = {{{0}, {0}, {0}, {0}},   //neg
                                        {{0}, {0}, {0}, {0}}}; // pos // these are used to store the raw data 

  double RawDataRPD[NSIDE][NRPD][NTS] = { {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},    //neg  // these are used to store the raw data 
                                          {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}} }; //pos
  
   double TS_ARRAY[NTS] = {0};
};

enum DetectorType {em, had, rpm};

    // struct TSArray {
    //   double ts_array[NTS];
    // };

    // enum etectorType {em, had, rpd};

    // int main
  
    //    EMData emd(data[em])
    //    HADData had(data[had])
    //    RPDData rpd(data[rpd])
    int side = (int)((zsideLeaf->GetValue(n)+1)/2.0);
    int type = (int)(sectionLeaf->GetValue(n))-1;
    int channel = (int)(channelLeaf->GetValue(n))-1;

void fill_ts_array(int n) { 


    /// Begin filling timeslices with fC (discrimination is by channel number iteration)

    //ternary if operator (x ? y : z) returns y if x is true, otherwise returns z
    //this is used below to keep values at 0 or greater
    double TS_Zero  = (fCleaf[0]->GetValue(n) < 0) ? 0.0 : (fCleaf[0]->GetValue(n));
    double TS_One   = (fCleaf[1]->GetValue(n) < 0) ? 0.0 : (fCleaf[1]->GetValue(n));
    double TS_Two   = (fCleaf[2]->GetValue(n) < 0) ? 0.0 : (fCleaf[2]->GetValue(n));
    double TS_Three = (fCleaf[3]->GetValue(n) < 0) ? 0.0 : (fCleaf[3]->GetValue(n));
    double TS_Four  = (fCleaf[4]->GetValue(n) < 0) ? 0.0 : (fCleaf[4]->GetValue(n)); 
    double TS_Five  = (fCleaf[5]->GetValue(n) < 0) ? 0.0 : (fCleaf[5]->GetValue(n));
    double TS_Six   = (fCleaf[6]->GetValue(n) < 0) ? 0.0 : (fCleaf[6]->GetValue(n));
    double TS_Seven = (fCleaf[7]->GetValue(n) < 0) ? 0.0 : (fCleaf[7]->GetValue(n));
    double TS_Eight = (fCleaf[8]->GetValue(n) < 0) ? 0.0 : (fCleaf[8]->GetValue(n));
    double TS_Nine  = (fCleaf[9]->GetValue(n) < 0) ? 0.0 : (fCleaf[9]->GetValue(n));

    /// END filling timeslices with fC (discrimination is by channel number iteration)

    // Declare variables for sums of TS fCs (456 is main signal of RPD and 45 is main signal of EM and HAD)



    TS_ARRAY[NTS] = { TS_Zero, TS_One, TS_Two, TS_Three, TS_Four, TS_Five, TS_Six, TS_Seven, TS_Eight, TS_Nine};
}

void ParseEntry() {
      for (int n = 0; n < num_channels; ++n) { 
          fill_ts_array(n);
          // filling arrays with the data per channel side and timeslice for use in the functions that are called. Allows for easier function use and greater efficiency

          if (type == EM){
            for (int TS = 0; TS < NTS; TS++){
              RawDataEM[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE EM DATA FOR THAT EVENT
            }
          }
          else if (type == HAD){ //figure out what cutoff for HAD
            for (int TS = 0; TS < NTS; TS++){
              RawDataHAD[side][channel][TS] = TS_ARRAY[TS]; //USE THIS ARRAY IF YOU WANT THE HAD DATA FOR THAT EVENT
            }
          }
          else if (type == RPD){ // make sure to set cuttoff to 40 fC for RPD
            for (int TS = 0; TS < NTS; TS++){
              if (side == 0){
                RawDataRPD[side][INVERSION_CORRECTION_ARRAY_FOR_NEG_ONLY[channel]][TS] = TS_ARRAY[TS];
              }
              else{
                RawDataRPD[side][channel][TS] = TS_ARRAY[TS];
              }    //USE THIS ARRAY IF YOU WANT THE RPD DATA FOR THAT EVENT
              //  THERE MUST BE A TRTANSLATOR AS RPD CHANNEL # DOES NOT EQUAL REAL CHANNEL NUMBER!!!
            }
          }
      }
  
}



void ZDC_DATA_Function(double num_ZDC_DigiTree_Entries, int i, double ) {
  for ( int i = 0;  i < ZDCDigiTree->GetEntries(); i++ ){
      ZDCDigiTree->GetEntry(i)
      ParseEntry()
     //->>>>> memset for TS_array to be 0
  } //end channel loop
}
    
    
    // int main
    //    ts_array = make_ts_array()
  
    //    EMData emd(ts_array)
    //    HADData had(ts_array)
    //    RPDData rpd(ts_array)
    