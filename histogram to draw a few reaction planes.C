//logic needed to choose 5 events
/*

have it get # of events and set that to the maximum value for the c++ random number generator 

have the rndm generate 5 values in a loopp and fill in a ASK COILIN for how efficient

......pseudo begin
int randomValues[15] = {0};

int MaxNum = ZDCDigiTree->GetEntries();

for ( int n = 0; n <  14; n++){

randomValues[n] = rand() % Maxnum + 0; //chosses random #s between 0 and the # of entries

//this is suseptable to missing some because some events will be rejected


// the checking normally would be ineffeicnt as heck so I need to use a trick. 

// suggestions from here https://stackoverflow.com/questions/15181579/c-most-efficient-way-to-compare-a-variable-to-multiple-values
}
.... pseudo end

*/
#include <cmath>


TH2F* RPD_Pos_w_RXN_Plane;
TH2F* RPD_Neg_w_RXN_Plane;

RPD_Pos_w_RXN_Plane = new TH2F(Form("RPD_Pos %d", runnumber), Form("RPD_Pos_w_RXN_Plane%d", runnumber), 4, -2, 2, 4, -2, 2);

RPD_Pos_w_RXN_Plane->GetXaxis()->SetNdivisions(4);
RPD_Pos_w_RXN_Plane->GetYaxis()->SetNdivisions(4);

RPD_Neg_w_RXN_Plane = new TH2F(Form("RPD_Neg %d", runnumber), Form("RPD_Neg_w_RXN_Plane%d", runnumber), 4, -2, 2, 4, -2, 2);

RPD_Neg_w_RXN_Plane->GetXaxis()->SetNdivisions(4);
RPD_Neg_w_RXN_Plane->GetYaxis()->SetNdivisions(4);

 
  //c++ uses radians as input and output

double HolderForRXNPlanePos;
double HolderForRXNPlaneNeg;


double X_position_cm[2][16] = {{1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1},  //neg
							   {1, 1, 1, 1, 3, 3, 3, 3, -3, -3, -3, -3, -1, -1, -1, -1}}; //pos
	
double Y_position_cm[2][16] = {{-1, 1, 3, -3, -1, 1, 3, -3, 1, -1, -3, 3, 1, -1, -3, 3},  //neg
							   {-1, 1, 3, -3, -1, 3, 1, -3, 1, -1, -3, 3, 1, -1, -3, 3}}; //pos 

for (int h = 0; h <2; h++){
	for (int i = 0; i < 15; i++){
	
		if (h == 0){
			int bin = RPD_Neg_w_RXN_Plane->GetBin(X_position_cm[h][i], Y_position_cm[h][i]/*,binz*/);
			//double ContentOfBin = RPD_Neg_w_RXN_Plane->GetBinContent(bin);
			RPD_Neg_w_RXN_Plane->SetBinContent(bin, (NEG_OutPut_RPDfC_X_Y_coord[i] /*+ ContentOfBin*/));
			//double label = RPD_Neg_w_RXN_Plane->GetBinContent(bin);
			RPD_Neg_w_RXN_Plane->SetBinLabel(bin, NEG_OutPut_RPDfC_X_Y_coord[i]/*label*/);

		}
		else{
			int bin = RPD_Pos_w_RXN_Plane->GetBin(X_position_cm[h][i], Y_position_cm[h][i]/*,binz*/);
			//double ContentOfBin = RPD_Pos_w_RXN_Plane->GetBinContent(bin);
			RPD_Pos_w_RXN_Plane->SetBinContent(bin, (POS_OutPut_RPDfC_X_Y_coord[i] /* + ContentOfBin*/)); //it might be the other way around idk
			//double label = RPD_Pos_w_RXN_Plane->GetBinContent(bin);
			RPD_Pos_w_RXN_Plane->SetBinLabel(bin, POS_OutPut_RPDfC_X_Y_coord[i]/*label*/);
		}	
	}
}

RPD_Pos_w_RXN_Plane->Draw("colz");
TLine *linePos = new TLine(0,0,(cos(HolderForRXNPlanePos)),(sin(HolderForRXNPlanePos)) ); 

RPD_Neg_w_RXN_Plane->Draw("colz");
TLine *linePos = new TLine(0,0,(cos(HolderForRXNPlaneNeg)),(sin(HolderForRXNPlaneNeg)) ); 

/*h->Fill(x,y,w);

TAxis::SetBinLabel(bin,label);


TCanvas *c1 = new TCanvas("c1","Visualizzazione",10,10,1000,500);
   gStyle->SetOptStat(0);

   TFile *f = new TFile("visualizzazione.root","RECREATE");

   TH2C *h100 = new TH2C("h100","Visualizzazione",32,0.,32.,64,0.,64.);

  
   //h100->SetFillColor(3);
//   h100->Draw();

   TPad *grid = new TPad("grid","",0,0,1,1);
   grid->Draw();
   grid->cd();
   grid->SetGrid();
   grid->SetFillStyle(4000);


   TH2C *hgrid = new TH2C("hgrid","",32,0.,32.,64,0.,64.);   
   hgrid->GetXaxis()->SetNdivisions(32);
   hgrid->GetYaxis()->SetNdivisions(64);
   hgrid->GetYaxis()->SetLabelOffset(999.);
   hgrid->GetXaxis()->SetLabelOffset(999.); 
   hgrid->Draw();

.......

    h100->Draw("BOX");
    hgrid->Draw("SAME");*/