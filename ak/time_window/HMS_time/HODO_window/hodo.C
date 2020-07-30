#include <iostream>
#include <fstream>
#include <string>
#include <TFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TMatrixD.h>
#include <TROOT.h>
#include <TMatrixDBase.h>
#include <TMath.h>
#include <TChain.h>
#include <TH1F.h>
#include <TF1.h>
#include <cstdlib>
#include <TH2F.h>
#include <TPad.h>
#include <TCutG.h>
#include <TLegend.h>
#include <TCanvas.h>
#include <TStyle.h>

using namespace std;

static const double degtorad = 3.141592653589793/180.;
TLegend *leg;

void formatit(TH1F *histo, TString bar, TString xax, TString yax, Int_t flag){

  gPad->SetLogy();
  gPad->SetTicks(1,1);
  gPad->SetLeftMargin(0.21);
  gPad->SetRightMargin(0.11);
  gPad->SetTopMargin(0.03);
  gPad->SetBottomMargin(0.13);

  gStyle->SetOptStat(0);

  histo->SetLabelSize(0.035, "x");
  histo->SetLabelSize(0.035, "y");
  histo->GetXaxis()->SetTitleSize(0.055);
  histo->GetYaxis()->SetTitleSize(0.055);
  histo->GetXaxis()->CenterTitle(1);
  histo->GetYaxis()->CenterTitle(1);
  histo->GetXaxis()->SetTitleOffset(1.1);
  histo->GetYaxis()->SetTitleOffset(1.3);
  histo->GetYaxis()->SetTitle(yax);
  histo->GetXaxis()->SetTitle(xax);
  histo->SetLineColor(kBlue);
  histo->SetLineWidth(1);
  histo->SetLineStyle(1);
  histo->Draw("");

  if (flag == 0){

    leg = new TLegend(0.2,0.85,0.35,0.95);
    leg->SetFillColor(-1);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.055);
    leg->SetTextColor(kAzure+7);
    leg->SetBorderSize(0);
    leg->AddEntry(histo,bar,"");
    leg->Draw("same");

  }

}
// TLine *line = new TLine(low,0.5,low,30);
// line->SetLineColor(kViolet+1);
// line->SetLineStyle(1);
// line->SetLineWidth(5);
// line->Draw("same");
// TLine *line1 = new TLine(high,0.5,high,30);
// line1->SetLineColor(kViolet+1);
// line1->SetLineStyle(1);
// line1->SetLineWidth(5);
// line1->Draw("same");

// line1->Draw("same");

//}

//TLegend * leg1;

void legend(TH1F * histo0, TH1F * histo1,TH1F * histo2, TH1F * histo3)
{

  leg = new TLegend(0.6,0.85,0.9,0.95);
  leg->SetFillColor(-1);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.025);
  leg->SetTextColor(kAzure+7);
  leg->SetBorderSize(0);
  leg->AddEntry(histo0,"no hit Sel","l");
  leg->AddEntry(histo1,"Mult Cut == 1","l");
  leg->AddEntry(histo2,"elec cut","l"); 
  leg->AddEntry(histo3,"Mult & elec cut","l");
  leg->Draw("same");
}

void legend_same(TH1F * histo0, TH1F * histo1,TH1F * histo2, TH1F * histo3)
{

  leg = new TLegend(0.6,0.8,0.9,0.95);
  leg->SetFillColor(-1);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.025);
  leg->SetTextColor(kAzure+7);
  leg->SetBorderSize(0);
  leg->AddEntry(histo0,"hit Sel","l");
  leg->AddEntry(histo1,"Mult cut == 1","l");
  leg->AddEntry(histo2,"elec cut","l"); 
  leg->AddEntry(histo3,"Mult & elec cut","l");
  leg->Draw("same");


}

void formatitd(TH1D *histo, TString bar, TString xax, TString yax, Int_t flag){

  gPad->SetTicks(1,1);
  gPad->SetLeftMargin(0.21);
  gPad->SetRightMargin(0.11);
  gPad->SetTopMargin(0.03);
  gPad->SetBottomMargin(0.13);


  histo->SetLabelSize(0.035, "x");
  histo->SetLabelSize(0.035, "y");
  histo->GetXaxis()->SetTitleSize(0.055);
  histo->GetYaxis()->SetTitleSize(0.055);
  histo->GetXaxis()->CenterTitle(1);
  histo->GetYaxis()->CenterTitle(1);
  histo->GetXaxis()->SetTitleOffset(1.1);
  histo->GetYaxis()->SetTitleOffset(1.3);
  histo->GetYaxis()->SetTitle(yax);
  histo->GetXaxis()->SetTitle(xax);
  histo->SetLineColor(kPink+10);
  histo->SetLineWidth(1);
  histo->SetLineStyle(2);
  histo->Draw("");

  if (flag == 0){

    leg = new TLegend(0.2,0.85,0.35,0.95);
    leg->SetFillColor(-1);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.055);
    leg->SetTextColor(kAzure+7);
    leg->SetBorderSize(0);
    leg->AddEntry(histo,bar,"");
    leg->Draw("same");

  }

}


void formatit_2d(TH2F *histo, TString bar, TString xax, TString yax, Int_t flag){

  gPad->SetTicks(1,1);
  gPad->SetLeftMargin(0.21);
  gPad->SetRightMargin(0.11);
  gPad->SetTopMargin(0.03);
  gPad->SetBottomMargin(0.13);


  histo->SetLabelSize(0.035, "x");
  histo->SetLabelSize(0.035, "y");
  histo->GetXaxis()->SetTitleSize(0.055);
  histo->GetYaxis()->SetTitleSize(0.055);
  histo->GetXaxis()->CenterTitle(1);
  histo->GetYaxis()->CenterTitle(1);
  histo->GetXaxis()->SetTitleOffset(1.1);
  histo->GetYaxis()->SetTitleOffset(1.3);
  histo->GetYaxis()->SetTitle(yax);
  histo->GetXaxis()->SetTitle(xax);
  //  histo->SetLineColor(kPink+10);
  //  histo->SetLineWidth(3);
  //  histo->SetLineStyle(2);
  //  histo->Draw("colz");

  /*  TCutG *mycut = new TCutG("mycut",7);
      mycut->SetVarX("");
      mycut->SetVarY("");
      mycut->SetPoint(0,20,-202.);
      mycut->SetPoint(1,70,-205.);
      mycut->SetPoint(2,140,-206.);
      mycut->SetPoint(3,140,-209.);
      mycut->SetPoint(4,60,-208.);
      mycut->SetPoint(5,20,-205.);
      mycut->SetPoint(6,20,-202.); */

  histo->Draw("colz");


  if (flag == 0){

    leg = new TLegend(0.2,0.85,0.35,0.95);
    leg->SetFillColor(-1);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.055);
    leg->SetTextColor(kAzure+7);
    leg->SetBorderSize(0);
    leg->AddEntry(histo,bar,"");
    leg->Draw("same");

  }

}
void formatit_2dd(TH2F *histo, TString bar, TString xax, TString yax, Int_t flag){

  gPad->SetTicks(1,1);
  gPad->SetLeftMargin(0.21);
  gPad->SetRightMargin(0.11);
  gPad->SetTopMargin(0.03);
  gPad->SetBottomMargin(0.13);


  histo->SetLabelSize(0.035, "x");
  histo->SetLabelSize(0.035, "y");
  histo->GetXaxis()->SetTitleSize(0.055);
  histo->GetYaxis()->SetTitleSize(0.055);
  histo->GetXaxis()->CenterTitle(1);
  histo->GetYaxis()->CenterTitle(1);
  histo->GetXaxis()->SetTitleOffset(1.1);
  histo->GetYaxis()->SetTitleOffset(1.3);
  histo->GetYaxis()->SetTitle(yax);
  histo->GetXaxis()->SetTitle(xax);
  //  histo->SetLineColor(kPink+10);
  //  histo->SetLineWidth(3);
  //  histo->SetLineStyle(2);
  histo->Draw("colz");

  if (flag == 0){

    leg = new TLegend(0.2,0.85,0.35,0.95);
    leg->SetFillColor(-1);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.055);
    leg->SetTextColor(kAzure+7);
    leg->SetBorderSize(0);
    leg->AddEntry(histo,bar,"");
    leg->Draw("same");

  }

}

void formatit_same(TH1F *histo, TString bar, TString xax, TString yax, Int_t flag){

  gPad->SetTicks(1,1);
  gPad->SetLeftMargin(0.21);
  gPad->SetRightMargin(0.11);
  gPad->SetTopMargin(0.03);
  gPad->SetBottomMargin(0.13);


  histo->SetLabelSize(0.035, "x");
  histo->SetLabelSize(0.035, "y");
  histo->GetXaxis()->SetTitleSize(0.055);
  histo->GetYaxis()->SetTitleSize(0.055);
  histo->GetXaxis()->CenterTitle(1);
  histo->GetYaxis()->CenterTitle(1);
  histo->GetXaxis()->SetTitleOffset(1.1);
  histo->GetYaxis()->SetTitleOffset(1.3);
  histo->GetYaxis()->SetTitle(yax);
  histo->GetXaxis()->SetTitle(xax);
  // histo->SetLineColor(kAzure+7);
  histo->SetLineWidth(1);
  histo->SetLineStyle(4);
  histo->Draw("same");

  if (flag == 0){

    leg = new TLegend(0.2,0.85,0.35,0.95);
    leg->SetFillColor(-1);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.055);
    leg->SetTextColor(kRed-4);
    leg->SetBorderSize(0);
    leg->AddEntry(histo,bar,"");
    leg->Draw("same");

  }

}
void histoAttributes(TH1F *hist11, TH1F *hist12, TH1F *hist13){

  hist11->SetLineColor(kRed);
  hist11->SetLineStyle(1);
  
  hist12->SetLineColor(kBlue-7);

  hist13->SetLineColor(kRed-10);

  hist11->Draw("same");
  hist12->Draw("same");
  hist13->Draw("same");



}


int binmax  = 0;
double x    = 0;
double xmin = 0;
double xmax = 0;

//ofstream phodo_neg, phodo_pos;

// ofstream hhodo_neg_min("hhodo_neg_min.txt", fstream::app);
// ofstream hhodo_neg_max("hhodo_neg_max.txt", fstream::app);

// ofstream hhodo_pos_min("hhodo_pos_min.txt", fstream::app);
// ofstream hhodo_pos_max("hhodo_pos_max.txt", fstream::app);

// //ofstream phodo_pos("phodo_pos.txt", fstream::app);

// void window_neg(TH1F * histo){

//   binmax = histo->GetMaximumBin(); 
//   x = histo->GetXaxis()->GetBinCenter(binmax);
  
//   xmin = x -40;
//   xmax = x +40;
    
//   hhodo_neg_min << xmin << ",";
//   hhodo_neg_max << xmax << ",";

//   auto * line =  new TLine (xmin, 0, xmin, 10000);
//   line->Draw();
//   line->SetLineColor(kMagenta);
//   line->SetLineWidth(2);
//   auto * line1 =  new TLine (xmax, 0, xmax, 10000);
//   line1->Draw();
//   line1->SetLineColor(kMagenta);
//   line1->SetLineWidth(2);
  


// }

// void window_pos(TH1F * histo){

// binmax = histo->GetMaximumBin(); 
// x = histo->GetXaxis()->GetBinCenter(binmax);
  
// xmin = x -40;
// xmax = x +40;
    
// hhodo_pos_max << xmax << ",";
// hhodo_pos_min << xmin << ",";

// // phodo_neg << xmax << ",";

// auto * line =  new TLine (xmin, 0, xmin, 10000);
// line->Draw();
// line->SetLineColor(kMagenta);
// line->SetLineWidth(2);
// auto * line1 =  new TLine (xmax, 0, xmax, 10000);
// line1->Draw();
// line1->SetLineColor(kMagenta);
// line1->SetLineWidth(2);

//}



int main(){
  
  TFile *myfile;
  
  TChain chain("T");

  TString fname = "/home/abishek.old/myanalysis/hallc-replay-f2xem/ROOTfiles/hms_replay_production_all_wide_1624_3000000.root";
  
  chain.Add(fname);

  const UInt_t nplanes          = 4;
  const UInt_t nsides           = 2;
  const UInt_t maxbars          = 16;
  const UInt_t nsignals         = 2;
  const UInt_t nadcsignals      = 8;
  const UInt_t ntdcsignals      = 2;
  const UInt_t maxhits          = 128*16*4;

  const Double_t planeOffset[nplanes]      = {1580, 1580, 1580, 1580};
  const TString plane_names[nplanes]       = {"1x", "1y", "2x", "2y"};
  const UInt_t  nbars[nplanes]             = {16, 10, 16, 10};
  const TString sides[nsides]              = {"Neg", "Pos"};
  const TString sides_counter[nsides]      = {"neg", "pos"};
  const TString signals[nsides]            = {"Adc", "Tdc"};
  const TString adc_signals[nadcsignals]   = {"Ped", "PedRaw", "PulseInt", "PulseIntRaw","PulseAmp", "PulseAmpRaw", "PulseTimeRaw", "PulseTime"};
  const TString tdc_signals[ntdcsignals]   = {"Time", "TimeRaw"};

  Int_t nadchits[nplanes][nsides];
  Int_t ntdchits[nplanes][nsides];
  
  Double_t adc_paddles[nplanes][nsides][maxhits];
  Double_t tdc_paddles[nplanes][nsides][maxhits];
  
  Double_t adc_values[nplanes][nsides][nadcsignals][maxhits];
  Double_t tdc_values[nplanes][nsides][ntdcsignals][maxhits];

  Double_t goodAdcTdcDiff[nplanes][nsides][30];
  
  Double_t goodPulseAmp[nplanes][nsides][30];
  
  Double_t goodAdcMult[nplanes][nsides][30];

  Double_t errorFlag[nplanes][nsides][maxhits];
  
  for(UInt_t ip = 0; ip < nplanes; ip++) {
    
    for(UInt_t iside = 0; iside < nsides; iside++) {

      for(UInt_t ibar = 0; ibar < nbars[ip]; ibar++) {
      }
      
      for(UInt_t isignal = 0; isignal < nsignals; isignal++) {
	
	if(signals[isignal] == "Adc") {

	  TString adc_base_name          = "H.hod."+ plane_names[ip]+"."+sides_counter[iside]+signals[isignal];

	  TString adc_base_name_good     = "H.hod."+ plane_names[ip]+".Good"+sides[iside]+signals[isignal];

	  TString adc_base_name_raw      = "H.hod."+plane_names[ip]+"."+sides_counter[iside]+signals[isignal];

	  TString adc_base_name_raw_low  = "H.hod."+ plane_names[ip]+"."+sides_counter[iside]+signals[isignal];

	  TString adc_base_name_low      = "H.hod."+ plane_names[ip]+".good"+sides[iside]+signals[isignal];

	  TString adc_base_name_counter  = "H.hod."+ plane_names[ip]+"."+sides_counter[iside]+signals[isignal];

	  TString error_flag             = adc_base_name + "ErrorFlag";
	  chain.SetBranchAddress( error_flag, &errorFlag[ip][iside]);

	  TString good_adc_mult          = adc_base_name_good + "Mult";
	  chain.SetBranchAddress(good_adc_mult, &goodAdcMult[ip][iside]);
	  
	  TString good_AdcTdcDiff        = adc_base_name_good + "TdcDiffTime";
	  chain.SetBranchAddress(good_AdcTdcDiff, &goodAdcTdcDiff[ip][iside]);
	 
	  TString good_adc_neg_pulse_amp = adc_base_name_good + "PulseAmp";
	  chain.SetBranchAddress(good_adc_neg_pulse_amp, &goodPulseAmp[ip][iside]);
	  
	  TString adc_ndata_name         = "Ndata."+adc_base_name_counter+"Counter";
	  chain.SetBranchAddress(adc_ndata_name, &nadchits[ip][iside]);

	  TString adc_paddle_name        = adc_base_name_counter+"Counter";
	  chain.SetBranchAddress(adc_paddle_name, &adc_paddles[ip][iside][0]);
	  
	  for (UInt_t iadcsignal = 0; iadcsignal < nadcsignals; iadcsignal++) {
	    if (adc_signals[iadcsignal] == "Ped") {
	      TString pedlist_name = adc_base_name_raw_low+"Ped";
	      chain.SetBranchAddress(pedlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PedRaw") {
	      TString pedrawlist_name = adc_base_name_raw_low+"PedRaw";
	      chain.SetBranchAddress(pedrawlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PulseInt") {
	      TString intlist_name = adc_base_name+"PulseInt";
	      chain.SetBranchAddress(intlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PulseTime") {
	      TString intlist_name = adc_base_name+"PulseTime";
	      chain.SetBranchAddress(intlist_name, &adc_values[ip][iside][iadcsignal][0]);
	      cout << "name is: " << intlist_name << endl;
	    }
	    if (adc_signals[iadcsignal] == "PulseIntRaw") {
	      TString intrawlist_name = adc_base_name_raw+"PulseIntRaw";
	      chain.SetBranchAddress(intrawlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PulseAmp") {
	      TString amplist_name = adc_base_name+"PulseAmp";
	      chain.SetBranchAddress(amplist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PulseAmpRaw") {
	      TString amprawlist_name = adc_base_name_raw+"PulseAmpRaw";
	      chain.SetBranchAddress(amprawlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	    if (adc_signals[iadcsignal] == "PulseTimeRaw") {
	      TString ptrawlist_name = adc_base_name_raw+"PulseTimeRaw";
	      chain.SetBranchAddress(ptrawlist_name, &adc_values[ip][iside][iadcsignal][0]);
	    }
	  }
	}
	
	if(signals[isignal] == "Tdc") 
	  {
	    TString tdc_base_name         = "H.hod."+ plane_names[ip]+"."+sides_counter[iside]+signals[isignal];
	    
	    TString tdc_base_name_good    = "H.hod."+ plane_names[ip]+".Good"+sides[iside]+signals[isignal];
	    
	    TString tdc_base_name_counter = "H.hod."+ plane_names[ip]+"."+sides_counter[iside]+signals[isignal];
	    
	    TString tdc_ndata_name        = "Ndata."+tdc_base_name_counter+"Counter";
	    chain.SetBranchAddress(tdc_ndata_name, &ntdchits[ip][iside]); 
	    
	    TString tdc_paddle_name       = tdc_base_name_counter+"Counter";
	    chain.SetBranchAddress(tdc_paddle_name, &tdc_paddles[ip][iside][0]);
	    
	    for (UInt_t itdcsignal = 0; itdcsignal < ntdcsignals; itdcsignal++) 
	      {
		
		if (tdc_signals[itdcsignal] == "Time") 
		  {
		    TString tdclist_name = tdc_base_name+"Time";
		    chain.SetBranchAddress(tdclist_name, &tdc_values[ip][iside][itdcsignal][0]);
		    cout << "name is: " << tdclist_name << endl;
		  }
		if (tdc_signals[itdcsignal] == "TimeRaw") 
		  {
		    TString tdcrawlist_name = tdc_base_name+"TimeRaw";
		    chain.SetBranchAddress(tdcrawlist_name, &tdc_values[ip][iside][itdcsignal][0]);
		  }
	      }
	  }
	
      }
    }
  }
 
  Double_t cal;
  Double_t cerNpe;
  Double_t starttime;
  
  chain.SetBranchAddress("H.cal.etottracknorm",   &cal);
  chain.SetBranchAddress("H.cer.npeSum",       &cerNpe);
  chain.SetBranchAddress("H.hod.starttime", &starttime);

  TH1F* diff_pos[4][20];
  TH1F* diff_pos_eCut[4][20];
  TH1F* diff_pos_multCut[4][20];
  TH1F* diff_pos_mult_eCut[4][20];
  

  TH1F* diff_neg[4][20];
  TH1F* diff_neg_eCut[4][20];
  TH1F* diff_neg_multCut[4][20];
  TH1F* diff_neg_mult_eCut[4][20];

  TH1F* good_neg[4][20];
  TH1F* good_neg_eCut[4][20];
  TH1F* good_neg_multCut[4][20];
  TH1F* good_neg_mult_eCut[4][20];

  TH1F* good_pos[4][20];
  TH1F* good_pos_eCut[4][20];
  TH1F* good_pos_multCut[4][20];
  TH1F* good_pos_mult_eCut[4][20];

  TH2F* diff_neg_amp[4][20];
  TH2F* diff_neg_amp_eCut[4][20];
  TH2F* diff_neg_amp_multCut[4][20];
  TH2F* diff_neg_amp_mult_eCut[4][20];

  TH2F* good_neg_amp[4][20];
  TH2F* good_neg_amp_multCut[4][20];

  TH2F* good_pos_amp[4][20];
  TH2F* good_pos_amp_multCut[4][20];
   
  TH2F* diff_pos_amp[4][20];
  TH2F* diff_pos_amp_eCut[4][20];
  TH2F* diff_pos_amp_multCut[4][20];
  TH2F* diff_pos_amp_mult_eCut[4][20];

  TH2F* diff_pos_amp_cut[4][20];
 

  Int_t bin  =  320;
  Int_t maxR =  180;
  Int_t minR = -180;
  
  for (int i =0; i < nplanes; i++){
    for(Int_t mm = 0; mm < nbars[i]; mm++){
           
      diff_pos[i][mm]               = new TH1F(Form("h1%d_%d_",i,mm),"", bin, minR, maxR);
      diff_pos_eCut[i][mm]          = new TH1F(Form("h2%d_%d_",i,mm),"", bin, minR, maxR);
      diff_pos_multCut[i][mm]       = new TH1F(Form("h3%d_%d_",i,mm),"", bin, minR, maxR);
      diff_pos_mult_eCut[i][mm]     = new TH1F(Form("h4%d_%d_",i,mm),"", bin, minR, maxR);

      diff_neg[i][mm]               = new TH1F(Form("h5%d_%d_",i,mm),"", bin, minR, maxR);
      diff_neg_eCut[i][mm]          = new TH1F(Form("h6%d_%d_",i,mm),"", bin, minR, maxR);
      diff_neg_multCut[i][mm]       = new TH1F(Form("h7%d_%d_",i,mm),"", bin, minR, maxR);
      diff_neg_mult_eCut[i][mm]     = new TH1F(Form("h8%d_%d_",i,mm),"", bin, minR, maxR);

      good_neg[i][mm]               = new TH1F(Form("h9%d_%d_",i, mm),"", bin, minR, maxR);
      good_neg_eCut[i][mm]          = new TH1F(Form("h10%d_%d_",i,mm),"", bin, minR, maxR);
      good_neg_multCut[i][mm]       = new TH1F(Form("h11%d_%d_",i,mm),"", bin, minR, maxR);
      good_neg_mult_eCut[i][mm]     = new TH1F(Form("h12%d_%d_",i,mm),"", bin, minR, maxR);

      good_pos[i][mm]               = new TH1F(Form("h13%d_%d_",i,mm),"", bin, minR, maxR);
      good_pos_eCut[i][mm]          = new TH1F(Form("h14%d_%d_",i,mm),"", bin, minR, maxR);
      good_pos_multCut[i][mm]       = new TH1F(Form("h15%d_%d_",i,mm),"", bin, minR, maxR);
      good_pos_mult_eCut[i][mm]     = new TH1F(Form("h16%d_%d_",i,mm),"", bin, minR, maxR); 

      diff_pos_amp[i][mm]           = new TH2F(Form("h17%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_pos_amp_eCut[i][mm]      = new TH2F(Form("h18%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_pos_amp_multCut[i][mm]   = new TH2F(Form("h19%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_pos_amp_mult_eCut[i][mm] = new TH2F(Form("h20%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);

      good_pos_amp[i][mm]           = new TH2F(Form("h21%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      good_pos_amp_multCut[i][mm]   = new TH2F(Form("h22%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);


      diff_neg_amp[i][mm]           = new TH2F(Form("h23%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_neg_amp_eCut[i][mm]      = new TH2F(Form("h24%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_neg_amp_multCut[i][mm]   = new TH2F(Form("h25%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      diff_neg_amp_mult_eCut[i][mm] = new TH2F(Form("h26%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);

      good_neg_amp[i][mm]           = new TH2F(Form("h27%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);
      good_neg_amp_multCut[i][mm]   = new TH2F(Form("h28%d_%d_",i,mm),"", bin, minR, maxR, 100, -20., 400.);

    }
  }

  Int_t nentries = chain.GetEntries();
    
  cout << "Total Entries "<< nentries <<endl;
    
  for(Int_t i=0; i < nentries; i++){
      
    cout << "entry : " << i << endl;
    // cout << "*******************************"<<endl;
    chain.GetEntry(i);
   
    for(UInt_t ip = 0; ip < nplanes; ip++) {
    
      //if (ip == 0){
    
      // cout << "plane :" << ip << endl;
    
      //  cout << " totals hits adc hits in plane" << ip << " " << nadchits[ip][0]<< endl;
    
      for(Int_t adc_neg_ihit = 0; adc_neg_ihit < nadchits[ip][0]; adc_neg_ihit++){
      
	//cout << " loop over adc hits " << " " << adc_neg_ihit + 1 << endl;
      
	if (errorFlag[ip][0][adc_neg_ihit]==1)continue;
      
	UInt_t adc_neg_bar = TMath::Nint(adc_paddles[ip][0][adc_neg_ihit]) - 1; // Adc hit associate with bar one side
      
	//  cout <<" adc_neg_bar number : " <<  adc_neg_bar << endl;
      
	// cout << " total tdc hits" << " " <<  ntdchits[ip][0] << endl;
      
	for(Int_t tdc_neg_ihit = 0; tdc_neg_ihit < ntdchits[ip][0]; tdc_neg_ihit++){
	
	  // cout << " looping over tdc hits : "<<  tdc_neg_ihit + 1 << endl;
	
	  UInt_t tdc_neg_bar = TMath::Nint(tdc_paddles[ip][0][tdc_neg_ihit]) - 1; // Tdc hit associate with bar one side
	
	  //	cout <<" tdc_neg_bar number : "<< tdc_neg_bar << endl;
	
	  //	cout <<"\n";
	
	  for (Int_t pmt_neg = 0; pmt_neg < nbars[ip]; pmt_neg++){
	  
	    if ( adc_neg_bar == pmt_neg &&  tdc_neg_bar == pmt_neg ){
	    
	      //cout << "pmt number " << pmt_neg << endl;
	    
	      // 2000. is the fTdcOffset from the PARAM file like in the email; 
	      //0.1 is the conversion from TDC channels to ns
	      //  pleas change 0.1 to pscin_tdc_to_time = 0.09766 ; 0.1
	      //(See Log Entry 3574348)
	    
	    
	      Double_t adc_tdc_neg_tdiff = (tdc_values[ip][0][0][tdc_neg_ihit] + planeOffset[ip]) * 0.09766 - adc_values[ip][0][7][adc_neg_ihit] ; // ?? pulsetime substraction 
	    
	      Double_t adc_amp_neg = adc_values[ip][0][2][adc_neg_ihit];
	    
	      //  Double_t tdc_time_neg = (tdc_values[ip][0][1][tdc_neg_ihit] + 2000.) * 0.1 - tdc_ref_time*0.1;
	    
	      //  cout << " time neg: " << tdc_time_neg << " " <<tdc_values[ip][0][1][tdc_neg_ihit]*0.1 << " " << tdc_ref_time*0.1<< endl;	  
	    
	      //  cout << "value : "<<good_AdcTdcDiff[ip][0][pmt_neg]<< endl;
	    
	      diff_neg[ip][pmt_neg]    ->Fill(adc_tdc_neg_tdiff);                                            // no hit selection  Adtdc time diff 
	    
	      good_neg[ip][pmt_neg]    ->Fill(goodAdcTdcDiff[ip][0][pmt_neg]);                               // good Adc TDC (hit selection)
	    
	      diff_neg_amp[ip][pmt_neg]->Fill(adc_tdc_neg_tdiff, adc_amp_neg);                               // Pulse Amp
	    
	      good_neg_amp[ip][pmt_neg]->Fill(goodAdcTdcDiff[ip][0][pmt_neg], goodPulseAmp[ip][0][pmt_neg]); // Good Pulse Amp 
	    
	      // cout <<"good  amp Value : "<<  goodAdc_amp_neg[ip][0][4][pmt_neg]<< endl;
	    
	    
	      if (cal>0.8 && cerNpe>2.0)                // electron cut
		{
		  diff_neg_eCut[ip][pmt_neg]     ->Fill(adc_tdc_neg_tdiff);              
		  diff_neg_amp_eCut[ip][pmt_neg] ->Fill(adc_tdc_neg_tdiff, adc_amp_neg);
		  good_neg_eCut[ip][pmt_neg]     ->Fill(goodAdcTdcDiff[ip][0][pmt_neg]);
		
		  if (goodAdcMult[ip][0][pmt_neg]==1)    //elec and Mult Cut
		    {
		      diff_neg_mult_eCut[ip][pmt_neg]     ->Fill(adc_tdc_neg_tdiff); 
		      diff_neg_amp_mult_eCut[ip][pmt_neg] ->Fill(adc_tdc_neg_tdiff, adc_amp_neg);
		      good_neg_mult_eCut[ip][pmt_neg]     ->Fill(goodAdcTdcDiff[ip][0][pmt_neg]);
		    
		    }
		}
	    
	      if (goodAdcMult[ip][0][pmt_neg]==1)       // only multiplicity cut
		{
		  diff_neg_multCut[ip][pmt_neg]     ->Fill(adc_tdc_neg_tdiff);
		  diff_neg_amp_multCut[ip][pmt_neg] ->Fill(adc_tdc_neg_tdiff, adc_amp_neg);
		  good_neg_multCut[ip][pmt_neg]     ->Fill(goodAdcTdcDiff[ip][0][pmt_neg]);
		  good_neg_amp_multCut[ip][pmt_neg] ->Fill(goodAdcTdcDiff[ip][0][pmt_neg], goodPulseAmp[ip][0][pmt_neg]);
		}
	    }
	  }
	}
      }
    
      for(Int_t adc_pos_ihit = 0; adc_pos_ihit < nadchits[ip][1];adc_pos_ihit++){
      
	if (errorFlag[ip][1][adc_pos_ihit]==1)continue;
      
	UInt_t adc_pos_bar = TMath::Nint(adc_paddles[ip][1][adc_pos_ihit]) - 1;
      
	for(Int_t tdc_pos_ihit = 0; tdc_pos_ihit < ntdchits[ip][1];tdc_pos_ihit++){
	
	  UInt_t tdc_pos_bar = TMath::Nint(tdc_paddles[ip][1][tdc_pos_ihit])- 1;
	      
	  for (Int_t pmt = 0; pmt < nbars[ip]; pmt++){
		
	    if ( adc_pos_bar == pmt && tdc_pos_bar == pmt){
		  
	      Double_t adc_tdc_pos_tdiff = (tdc_values[ip][1][0][tdc_pos_ihit] + planeOffset[ip]) * 0.09766- adc_values[ip][1][7][adc_pos_ihit];
	      Double_t adc_amp_pos = adc_values[ip][1][2][adc_pos_ihit];

	      // Double_t tdc_time_pos = (tdc_values[ip][1][1][tdc_pos_ihit] +2000.) * 0.1 - tdc_ref_time*0.1;
		  
	      // diff_pos_tdc[ip][pmt]->Fill(adc_tdc_pos_tdiff,tdc_time_pos);
		  
	      // diff_pos_tdc_1d[ip][pmt]->Fill(tdc_time_pos);
		  
	      diff_pos[ip][pmt]      ->Fill(adc_tdc_pos_tdiff);
	      good_pos[ip][pmt]      ->Fill(goodAdcTdcDiff[ip][1][pmt]);
	      diff_pos_amp[ip][pmt]  ->Fill(adc_tdc_pos_tdiff,adc_amp_pos);
	      good_pos_amp[ip][pmt]  ->Fill(goodAdcTdcDiff[ip][1][pmt], goodPulseAmp[ip][1][pmt]);
		  
	      if (cal>0.8 && cerNpe>2.0)         // electron cut
		{
		  diff_pos_eCut[ip][pmt]    ->Fill(adc_tdc_pos_tdiff); 
		  diff_pos_amp_eCut[ip][pmt]->Fill(adc_tdc_pos_tdiff, adc_amp_pos);
		  good_pos_eCut[ip][pmt]    ->Fill(goodAdcTdcDiff[ip][1][pmt]);
		      
		  if (goodAdcMult[ip][1][pmt]==1)  //elec and Mult Cut 
		    {
		      diff_pos_mult_eCut[ip][pmt]    ->Fill(adc_tdc_pos_tdiff); 
		      diff_pos_amp_mult_eCut[ip][pmt]->Fill(adc_tdc_pos_tdiff, adc_amp_pos); 
		      good_pos_mult_eCut[ip][pmt]    ->Fill(goodAdcTdcDiff[ip][1][pmt]);
		    }
		}
	      if (goodAdcMult[ip][1][pmt]==1)
		{
		  //cout << nadcMult[ip][1][pmt]<< endl;
		  diff_pos_multCut[ip][pmt]    ->Fill(adc_tdc_pos_tdiff);
		  diff_pos_amp_multCut[ip][pmt]->Fill(adc_tdc_pos_tdiff, adc_amp_pos);
		  good_pos_multCut[ip][pmt]    ->Fill(goodAdcTdcDiff[ip][1][pmt]);
		  good_pos_amp_multCut[ip][pmt]->Fill(goodAdcTdcDiff[ip][1][pmt], goodPulseAmp[ip][1][pmt]);
		}
	    }
	  }
	}
      }
    }
  }
    
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(84);
    
  //======================================== canvas for negative side =========================================//
      
  TCanvas *c1[nplanes][42]; 
  TCanvas *c2[nplanes][42]; 

  for (int i =0; i<nplanes; i++)
  //for (int i =0; i<1; i++)
    {
      //cout << "Plane " << i+1 << endl;
      for (int pmt = 0; pmt<nbars[i] ; pmt++)

      //for (int pmt = 0; pmt<1 ; pmt++)
	{
	  // cout << " tot pmt in plane" << i+1<< "================== "<< nbars[i]<< endl;
	  //cout << pmt +1 << endl;

	  c1[i][pmt] = new TCanvas();
	   
	  c2[i][pmt] = new TCanvas();
	    
	  c1[i][pmt]->Divide(2,2);
	    
	  c1[i][pmt]->cd(1);
	    
	  formatit(diff_neg[i][pmt],"no hit sel",Form("TdcAdcTimeDiffPlane[%d]_Neg[%d](ns)",i,pmt+1),"Events", 1);
	    
	  formatit_same(diff_neg_multCut[i][pmt],  " "," "," ", 1);
	    
	  formatit_same(diff_neg_eCut[i][pmt],     " "," "," ", 1);
	    
	  formatit_same(diff_neg_mult_eCut[i][pmt]," "," ","", 1);
	    
	  histoAttributes(diff_neg_eCut[i][pmt],diff_neg_multCut[i][pmt], diff_neg_mult_eCut[i][pmt]);
	    
	  legend(diff_neg[i][pmt],  diff_neg_multCut[i][pmt], diff_neg_eCut[i][pmt], diff_neg_mult_eCut[i][pmt]);
	    
	  //======================================================================================================//
	    
	  c1[i][pmt]->cd(2);
	  gPad->Divide(2,2);
	    
	  gPad->cd(1);
	  formatit_2d(diff_neg_amp[i][pmt], " no hit Sel","TdcAdcTimeDiff_Neg(ns)", "PulseAmp",0); 
	    
	  c1[i][pmt]->cd(2);
	  gPad->cd(2);
	  formatit_2d(diff_neg_amp_multCut[i][pmt], "mult Cut","TdcAdcTimeDiff_Neg(ns)", "PulseAmp",0);
	    
	    
	  c1[i][pmt]->cd(2);
	  gPad->cd(3);
	  formatit_2d(diff_neg_amp_eCut[i][pmt], "elec Cut","TdcAdcTimeDiff_Neg(ns)", "PulseAmp",0);
	    
      
      
	  c1[i][pmt]->cd(2);
	  gPad->cd(4);
	  formatit_2d(diff_neg_amp_mult_eCut[i][pmt], "Mult & eCut","TdcAdcTimeDiff_Neg(ns)", "PulseAmp",0);

	  ////=============================================================================================================//
	  c1[i][pmt]->cd(3);
	  formatit(good_neg[i][pmt]," ",Form("H.hod.1x.GoodNegAdcTdcDiffTime_%d(ns)",pmt+1),"Events", 0);

	  formatit_same(good_neg_multCut[i][pmt],  " "," "," ", 1);

	  formatit_same(good_neg_eCut[i][pmt],     " "," "," ", 1);
      
	  formatit_same(good_neg_mult_eCut[i][pmt]," "," ","", 1);

	  histoAttributes( good_neg_eCut[i][pmt], good_neg_multCut[i][pmt],good_neg_mult_eCut[i][pmt]);   

	  legend_same(good_neg[i][pmt], good_neg_multCut[i][pmt], good_neg_eCut[i][pmt], good_neg_mult_eCut[i][pmt]);

	  // window_neg(good_neg[i][pmt]);
     
      
	  // //===========================================================================================================//
	  c1[i][pmt]->cd(4); 
	  gPad->Divide(2,1);
	  gPad->cd(1);
	  formatit_2d(good_neg_amp[i][pmt],"hit sel hcana ", "GoodTdcAdcTimeDiff_Neg(ns)", "PulseAmp", 0);

	  c1[i][pmt]->cd(4);
	  gPad->cd(2);
	  formatit_2d(good_neg_amp_multCut[i][pmt],"mult Cut ", "GoodTdcAdcTimeDiff_Neg(ns)", "PulseAmp", 0);

	  c1[i][pmt]->SaveAs(Form("test_plots/Neg_S1X_plane_%d_Pmt_%d_test.pdf", i+1, pmt+1));



	  ///==================================================================================================//

	  ////   :=:=:=:=:=:=:=:=:=:=:=:=:     Canvas for positive side    :=:=:=:=:=:=:=:=:=:=:=:=:=:=:=     //

	  ////================================================================================================//

	  c2[i][pmt]->Divide(2,2);
	  c2[i][pmt]->cd(1);

	  formatit(diff_pos[i][pmt],"no hit sel",Form("TdcAdcTimeDiffPlane[%d]_Pos[%d](ns)",i, pmt+1),"Events", 1);      

	  formatit_same(diff_pos_multCut[i][pmt],  " "," "," ", 1);

	  formatit_same(diff_pos_eCut[i][pmt],     " "," "," ", 1);

	  formatit_same(diff_pos_mult_eCut[i][pmt]," "," ","", 1);

	  histoAttributes( diff_pos_eCut[i][pmt],diff_pos_multCut[i][pmt], diff_pos_mult_eCut[i][pmt]);
	  legend(diff_pos[i][pmt], diff_pos_multCut[i][pmt], diff_pos_eCut[i][pmt],  diff_pos_mult_eCut[i][pmt]);
    
	  c2[i][pmt]->cd(2);
	  gPad->Divide(2,2);
	  gPad->cd(1);
	  formatit_2d(diff_pos_amp[i][pmt], "no hit sel","TdcAdcTimeDiff_Pos(ns)", "PulseAmp",0);

	  c2[i][pmt]->cd(2);
	  gPad->cd(2);
	  formatit_2d(diff_pos_amp_multCut[i][pmt], "mult Cut","TdcAdcTimeDiff_Pos(ns)", "PulseAmp",0);
      
      
	  c2[i][pmt]->cd(2);
	  gPad->cd(3);
	  formatit_2d(diff_pos_amp_eCut[i][pmt], "elec Cut","TdcAdcTimeDiff_Pos(ns)", "PulseAmp",0);
 
	  c2[i][pmt]->cd(2);
	  gPad->cd(4);
	  formatit_2d(diff_pos_amp_mult_eCut[i][pmt], "Mult & eCut","TdcAdcTimeDiff_Pos(ns)", "PulseAmp",0);

	  ////===============================================================================================================//

	  c2[i][pmt]->cd(3);
	  formatit(good_pos[i][pmt]," ",Form("H.hod.1x.GoodPosAdcTdcDiffTime_%d(ns)",pmt+1),"Events", 0);

	  formatit_same(good_pos_multCut[i][pmt],  " "," "," ", 1);

	  formatit_same(good_pos_eCut[i][pmt],     " "," "," ", 1);
      
	  formatit_same(good_pos_mult_eCut[i][pmt]," "," ","", 1);

	  histoAttributes(good_pos_eCut[i][pmt],good_pos_multCut[i][pmt],good_pos_mult_eCut[i][pmt]);

	  legend_same(good_pos[i][pmt], good_pos_multCut[i][pmt], good_pos_eCut[i][pmt], good_pos_mult_eCut[i][pmt]);

	  //window_pos(good_pos[i][pmt]);
     
      
	  ////============================================================================================================//

	  c2[i][pmt]->cd(4); 
	  gPad->Divide(2,1);
	  gPad->cd(1);
	  formatit_2d(good_pos_amp[i][pmt],"hit sel hcana ", "GoodTdcAdcTimeDiff_Pos(ns)", "PulseAmp", 0);
      
	  c2[i][pmt]->cd(4);
	  gPad->cd(2);
	  formatit_2d(good_pos_amp_multCut[i][pmt],"mult Cut ", "GoodTdcAdcTimeDiff_Pos(ns)", "PulseAmp", 0);
      
      
	  c2[i][pmt]->SaveAs(Form("test_plots/Pos_S1X_Plane_%d_Pmt%d_test.pdf", i+1, pmt+1));
	    
	  delete c1[i][pmt];
	  delete c2[i][pmt];    
	   
	}
	
    }
      
  return 0; 
}
