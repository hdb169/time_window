#define SHMSADCGates_cxx
#include "SHMSADCGates.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSpectrum.h>
#include <TPolyMarker.h>
#include <TMath.h>
#include <TSystem.h>

void SHMSADCGates::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();
}

void SHMSADCGates::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();

  h1PHGCERPulseTimeStarttimeDiff_CalCut = new TH1F*[4];
  
  //****************** HgCer( 4 pmts) **********************************//
  h1PHGCERPulseTime              = new TH1F*[4];
  h1PHGCERPulseTimeStarttimeDiff = new TH1F*[4];
  h1PHGCERPGoodAdcTdcDiffTime = new TH1F*[4];
  h1PHGCERPGoodAdcTdcDiffTime_Mult = new TH1F*[4];
  h1PHGCERPulseTimeVsPulseAmp = new TH2F*[4];
  h1PHGCERPulseTimeStarttimeDiffMult = new TH1F*[4];
  h1PHGCERPulseTimeStarttimeDiffMultCut = new TH1F*[4];
  h1PHGCERPulseTimeVsPulseAmpMultCut = new TH2F*[4];
  h1TimeVsAmpMult =new TH2F*[4];
  h1TimeVsAmpCal = new TH2F*[4];
  h1TimeVsAmpMultCal=new TH2F*[4];
  h1goodTimeVsAmpMult=new TH2F*[4];

  h1goodTimeCal= new TH1F*[4];
  h1goodTimeMultCal= new TH1F *[4];

  h1 = new TH1F*[4];// amp
  h2 = new TH1F*[4];
  
  h1_int = new TH1F*[4]; //integral 
  h2_int = new TH1F*[4];
  
  h1_delta = new TH1F*[4];
  

  for (Int_t ipmt=0; ipmt<4; ipmt++) {
    h1PHGCERPulseTime[ipmt] = new TH1F(Form("PHGCERPulseTime%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmp%d",ipmt+1),"", 375, -100, 50, 1000, -20, 600);

    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmpMultCut%d",ipmt+1),"", 375, -100, 50, 1000, -20, 600);

    h1PHGCERPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff%d",ipmt+1),"",1000,-300,100);
    
    h1PHGCERPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMult%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMultCut%d",ipmt+1),"", 375, -100, 50);
    
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff_CalCut%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPGoodAdcTdcDiffTime[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTime%d",ipmt+1),"", 375, -100, 50); //hcana selection

    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTimeMult%d",ipmt+1), "", 375, -100, 50); // multiplicity cut 

    h1TimeVsAmpMult[ipmt] = new TH2F(Form("h1TimeVsAmpMult%d",ipmt+1), "" , 375, -100, 50, 1000, -20, 600);

    h1TimeVsAmpCal[ipmt] = new TH2F(Form("h1TimeVsAmpCal%d",ipmt+1), "" , 375, -100, 50, 1000, -20, 600);

    h1TimeVsAmpMultCal[ipmt] = new TH2F(Form("h1TimeVsAmpMultCal%d",ipmt+1), "" , 375, -100, 50, 1000, -20, 600);

    h1goodTimeVsAmpMult[ipmt]= new TH2F(Form("h1goodTimeVsAmpMult%d",ipmt+1), "" , 375, -100, 50, 1000, -20, 600);

    h1goodTimeCal[ipmt] = new TH1F (Form("h1goodTimecal%d", ipmt+1),"", 375, -100, 50);
    
    h1goodTimeMultCal[ipmt] = new TH1F (Form("h1goodTimeMultCal%d", ipmt+1),"", 375, -100, 50);
    
    

    h1[ipmt] = new TH1F (Form("h1%d", ipmt +1),"", 500, -30, 250);
    h2[ipmt] = new TH1F (Form("h2%d", ipmt +1),"", 500, -30, 250);


    h1_int[ipmt] = new TH1F (Form("h1_int%d", ipmt +1),"", 200, 0, 150);
    h2_int[ipmt] = new TH1F (Form("h2_int%d", ipmt +1),"", 200, 0, 150);

    h1_delta[ipmt] = new TH1F(Form("h1_delta%d",ipmt+1),"",375, -100, 50);
    
    GetOutputList()->Add(h1PHGCERPulseTime[ipmt]);
    GetOutputList()->Add(h1PHGCERPulseTimeStarttimeDiff[ipmt]);
    
    
  }
  
}


Bool_t SHMSADCGates::Process(Long64_t entry)
{
  
  fReader.SetEntry(entry);

  if(entry<100000000) {//Abort("end of the desired entry");
    
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    cout << "Entry: " << entry << endl;
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    //cout <<"\n";
    
    //**************************** Filling Histograms****************************************// 
    //***************************************HGCER*******************************************//
    //********There are 4 pmts. Here we are looping over all hits ***************************//
    
    for (Int_t i = 0; i < *Ndata_P_ngcer_adcPulseTime; i++) {
      
      if (P_ngcer_adcErrorFlag[i] == 1) continue;

      Int_t current_pmt = P_ngcer_adcCounter[i] - 1;
      
      h1PHGCERPulseTime[current_pmt]->Fill(-P_ngcer_adcPulseTime[i]);

      if(*P_gtr_dp>-15 && *P_gtr_dp<30)
	{
	  h1_delta[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt]); //delta cut
	}
      
      h1PHGCERPulseTimeStarttimeDiff[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime); // no selection adctdc time diff
      
      if(*P_cal_etottracknorm >0.8)// all hits with electron 
	{
	  h1PHGCERPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime);  // adctdc time diff with mult electron

	  h1TimeVsAmpCal[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime, P_ngcer_adcPulseAmp[i]); // amplitude with electron

	  h1goodTimeCal[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt]); //
	}
      
      h1PHGCERPulseTimeVsPulseAmp[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime,  P_ngcer_adcPulseAmp[i]);
      
      h1PHGCERPGoodAdcTdcDiffTime[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt]);

      h1PHGCERPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt], P_ngcer_goodAdcPulseAmp[current_pmt]);//2d for hcana selection
      
      if (P_ngcer_goodAdcMult[current_pmt] == 1) //hits with multiplicity ==1
	{
	  h1PHGCERPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime);
	  
	  h1PHGCERPGoodAdcTdcDiffTime_Mult[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt]);
	  
	  h1goodTimeVsAmpMult[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt], P_ngcer_goodAdcPulseAmp[current_pmt]);
	  
	  h1TimeVsAmpMult[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime, P_ngcer_adcPulseAmp[i]);
	  
	  if(*P_cal_etottracknorm >0.8)//hits with electron and Multiplicity
	    {
	      h1PHGCERPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime);// all hit with elec and mult==1
	      
	      h1TimeVsAmpMultCal[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime,  P_ngcer_adcPulseAmp[i]);

	      h1goodTimeMultCal[current_pmt]->Fill(P_ngcer_goodAdcTdcDiffTime[current_pmt]);
	    }
	} 
      // if (P_ngcer_goodAdcTdcDiffTime[i]> -50 && P_ngcer_goodAdcTdcDiffTime[i]<-30)// big peak 
      // 	{
      // 	  h1[current_pmt]->Fill(P_ngcer_goodAdcPulseAmp[i]);
      // 	  h1_int[current_pmt]->Fill(P_ngcer_goodAdcPulseInt[i]);
      // 	}
      // if (P_ngcer_goodAdcTdcDiffTime[i]> -30 && P_ngcer_goodAdcTdcDiffTime[i] <-10)// small peak
      // 	{
      // 	  h2[current_pmt]->Fill(P_ngcer_goodAdcPulseAmp[i]);
      // 	  h2_int[current_pmt]->Fill(P_ngcer_goodAdcPulseInt[i]);
      // 	}
      
    }// end of multiple hit loop
    
    
    
  }
  return kTRUE;
}


void SHMSADCGates::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  
}

void SHMSADCGates::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.

  Info("Terminate", "Branches Sorted, Now Calculating Windows");
  gSystem->RedirectOutput("/dev/null","a");
  gSystem->RedirectOutput(0);
    
  //Output Adc Time Window Values into an ascii file
  TString option = GetOption();
  
  gStyle->SetOptStat(0);

  TLegend * legend[4];

  
  // legend[1] = new TLegend(0.1,0.7,0.48,0.9);
  // legend[2] = new TLegend(0.1,0.7,0.48,0.9);
  // legend[3] = new TLegend(0.1,0.7,0.48,0.9);

  TFile *MyFile = new TFile("h1calcut_wide.root","NEW");
  
  for (Int_t ipmt=0; ipmt < 4; ipmt++) {
   TCanvas *c1=  new TCanvas("c1", "" , 600, 600); c1->Divide(2,1);
    int ipmtt=0;
    
    // legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->SetHeader("tight cut","C");
    
    // c1->cd(1);  gPad->SetLogy();
    
    // h1PHGCERPulseTimeStarttimeDiff[ipmt]->Draw();// no hit selection
    // h1PHGCERPulseTimeStarttimeDiff[ipmt]->SetTitle(Form("PMT %d",ipmt+1));
    // h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
    // h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);// cal cut

    // h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
    // h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineStyle(2);
    // h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kBlue-7); // multiplicity cut

    // h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
    // h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed-10); // electron and multiplicity cut
    // h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineStyle(2);
    // h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetXaxis()->SetTitle("-P.ngcer.adcPulseTime + P.hod.starttime");
    // h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitle("Counts");
    
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection","l");
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult[ipmt],"mult = 1","l");
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Calorimeter Cut","l");
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    // legend[ipmtt]->Draw();
    
    //h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    // PHGCPULSETIMEDIFFCUT[ipmt]->Draw("same");
    // PHGCPULSETIMEDIFFCUT[ipmt]->SetLineColor(kRed);


    // subplots for time and amplitude 
    // c1->cd(2);gPad->Divide(2,2);
    // gPad->cd(1); // no hits selection
    // ipmtt+=1;
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetXaxis()->SetTitle("-P.ngcer.adcPulseTime + P.hod.starttime");
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitle("P.ngcer.adcPulseAmp");
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->SetLineStyle(2);
    // legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection", "l");
    // legend[ipmtt]->Draw();
    // delete legend[ipmtt];

    // c1->cd(2); gPad->cd(2); multiplicity
    // ipmtt+=1;
    // h1TimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    // h1TimeVsAmpMult[ipmt ]->GetXaxis()->SetTitle("-P.ngcer.adcPulseTime + P.hod.starttime");
    // h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitle("P.ngcer.adcPulseAmp");
    // h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult [ipmt ], "mult=1", "l");
    // legend[ipmtt]->Draw();
    //  delete legend[ipmtt];

    // c1->cd(2); gPad->cd(3); // Cal_Cut 
    // ipmtt+=1;
    // h1TimeVsAmpCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    // h1TimeVsAmpCal[ipmt ]->GetXaxis()->SetTitle("-P.ngcer.adcPulseTime + P.hod.starttime");
    // h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitle("P.ngcer.adcPulseAmp");
    // h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Cal Cut","l");
    // legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  
    // c1->cd(2); gPad->cd(4); // multiplicity and cal cut
    // ipmtt+=1;
    // h1TimeVsAmpMultCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    // h1TimeVsAmpMultCal[ipmt ]->GetXaxis()->SetTitle("-P.ngcer.adcPulseTime + P.hod.starttime");
    // h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitle("P.ngcer.adcPulseAmp");
    // h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // cout<<"kera   2222"<<endl;
    // legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    // legend[ipmtt]->SetTextSize(0.03);
    // legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  

    c1->cd(2);gPad->Divide(2,1); //gPad->SetGrid();
    gPad->cd(1);
    ipmtt=ipmtt+1;
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitle("P.ngcer.goodAdcTdcDiffTime");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitle("P.ngcer.goodAdcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitleSize(0.05);
    legend[ipmtt] = new TLegend(0.12,0.8,0.4,0.89);
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit sel. by hcana", "l");
    legend[ipmtt]->SetTextSize(0.05);legend[ipmtt]->SetBorderSize(0);
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
   
    //cout << ipmtt << endl;

         
    c1->cd(2); gPad->cd(2); //gPad->SetGrid();
    ipmtt=ipmtt+1;
    h1goodTimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitle("P.ngcer.goodAdcTdcDiffTime");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitle("P.ngcer.goodAdcPulseAmp");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitleSize(0.05);
    legend[ipmtt] = new TLegend(0.12,0.8,0.42,0.89);
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->SetTextSize(0.05); legend[ipmtt]->SetBorderSize(0);
    legend[ipmtt]->Draw();


    //**************************************************Pad 1****************//
   
    c1->cd(1);gPad->SetLogy();// gPad->SetGrid();
    
    // h1PHGCERPGoodAdcTdcDiffTime[ipmt]->Scale(1);
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->SetMinimum(1);
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->Draw();//
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->SetTitle(Form("PMT %d",ipmt+1));

    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetMinimum(1);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->Draw("same");
    
    // h1_delta[ipmt]->SetMinimum(1);
    h1_delta[ipmt]->Draw("same"); // delta cut 
    h1_delta[ipmt]->SetLineColor(kGreen);
    
    // h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetMinimum(1);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineColor(kBlue-7);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineStyle(2);
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("P.ngcer.goodAdcTdcDiffTime");
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("Counts");

    // h1goodTimeCal[ipmt]->SetMinimum(1);
    h1goodTimeCal[ipmt]->Draw("same");
    h1goodTimeCal[ipmt]->SetLineColor(kRed);
    h1goodTimeMultCal[ipmt]->Draw("same");
    h1goodTimeMultCal[ipmt]->SetLineColor(kRed-10);
    h1goodTimeMultCal[ipmt]->SetLineStyle(2);
    ipmtt=ipmtt+1;
    legend[ipmtt] = new TLegend(0.12,0.81,0.42,0.89);
    legend[ipmtt]->SetHeader("wide cut","C");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit sel. by hcana (good)", "l");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->AddEntry( h1goodTimeCal[ipmt],"good with Cal","l");
    legend[ipmtt]->AddEntry( h1goodTimeMultCal[ipmt],"good with Cal & mult","l"); 
    legend[ipmtt]->AddEntry(h1_delta[ipmt]," good with delta cut", "l");
    legend[ipmtt]->Draw(); legend[ipmtt]->SetTextSize(0.03);
    legend[ipmtt]->SetBorderSize(0);
    
    if (ipmt==0)
      {
    	auto * line =  new TLine (-48, 0, -48, 11000);
    	line->Draw();
    	line->SetLineColor(kMagenta);
    	line->SetLineWidth(2);
    	auto * line1 =  new TLine (-10, 0, -10, 11000);
    	line1->Draw();
    	line1->SetLineColor(kMagenta);
      	line1->SetLineWidth(2);
      }
    if (ipmt==1)
      {
    	auto * line =  new TLine (-45, 0, -45, 12000);
    	line->Draw();
    	line->SetLineColor(kMagenta);
    	line->SetLineWidth(2);
    	auto * line1 =  new TLine (-10, 0, -10, 12000);
    	line1->Draw();
    	line1->SetLineColor(kMagenta);
      	line1->SetLineWidth(2);
      }
    if (ipmt==2)
      {
    	auto * line =  new TLine (-40, 0, -40, 11000);
    	line->Draw();
    	line->SetLineColor(kMagenta);
    	line->SetLineWidth(2);
    	auto * line1 =  new TLine (-10, 0, -10, 11000);
    	line1->Draw();
    	line1->SetLineColor(kMagenta);
      	line1->SetLineWidth(2);
      }
    if (ipmt==3)
      {
    	auto * line =  new TLine (-45, 0, -45, 11000);
    	line->Draw();
    	line->SetLineColor(kMagenta);
    	line->SetLineWidth(2);
    	auto * line1 =  new TLine (-10, 0, -10, 11000);
    	line1->Draw();
    	line1->SetLineColor(kMagenta);
      	line1->SetLineWidth(2);
      }




     
    //  h1goodTimeCal[ipmt]->SaveAs(Form("hcalcut_tight%d.root",ipmt));
    // h1goodTimeCal[ipmt]->Write();
    

    c1->SaveAs(Form("wide_NGCER_pmt_%i.eps", ipmt+1));
    
    delete c1;
    for(int ii=1;ii<4;ii++)
      delete legend[ii];
    
  }




  
  // TCanvas *c2 = new TCanvas ("c2", "" , 600, 600);
  // c2->Divide(2,2);
  // TCanvas *c3 = new TCanvas ("c3", "" , 600, 600);
  // c3->Divide(2,2);
  
  
  // for (int ipmt = 0; ipmt<4; ipmt++){
  //   // c1[ipmt]->SaveAs(Form("tight_NGCER_pmt_%i.pdf", ipmt+1));
  //   c2->cd(ipmt+1);gPad->SetLogy(1);
  //   h2[ipmt]->Draw();
  //   h1[ipmt]->Draw("same"); h1[ipmt]->SetLineColor(kRed);
  //   h2[ipmt]->GetXaxis()->SetTitle("P.ngcer.adcPulseAmp");
  //   h2[ipmt]->SetTitle(Form("Amp_Pmt%d",ipmt+1));

  //   c3->cd(ipmt+1);gPad->SetLogy(1);
  //   h2_int[ipmt]->Draw();
  //   h1_int[ipmt]->Draw("same"); h1_int[ipmt]->SetLineColor(kRed);
  //   h2_int[ipmt]->GetXaxis()->SetTitle("P.ngcer.adcPulseInt");
  //   h2_int[ipmt]->SetTitle(Form("Int_Pmt%d",ipmt+1));
  // }
  // c2->SaveAs("good_Amp_pmt.pdf");
  // c3->SaveAs("good_Integral_pmt.pdf");

  //***************************************statistic under the peak ********************//
  // double tot_Entry_pmt[4];

  // for (int i=0; i<4; i++)
  //   {
  //     tot_Entry_pmt[i] = h1PHGCERPGoodAdcTdcDiffTime[i]->GetEntries();
  //     cout << "total entry: "<< tot_Entry_pmt[i] << endl;
  //     cout << "aftercut: "<< h1PHGCERPGoodAdcTdcDiffTime_Mult[i]->GetEntries() << endl;
  //   }
  
   
}                  
