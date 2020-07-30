#define SHMSADCGates_cxx
// The class definition in SHMSADCGates.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("SHMSADCGates.C")
// root> T->Process("SHMSADCGates.C","some options")
// root> T->Process("SHMSADCGates.C+")
//


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


  for (Int_t ipmt=0; ipmt<4; ipmt++) {
    h1PHGCERPulseTime[ipmt] = new TH1F(Form("PHGCERPulseTime%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmp%d",ipmt+1),"",1000,-300,100, 1000, 0, 1000);

    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmpMultCut%d",ipmt+1),"",1000,-300,100, 1000, 0, 1000);

    h1PHGCERPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff%d",ipmt+1),"",1000,-300,100);
    
    h1PHGCERPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMult%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMultCut%d",ipmt+1),"",1000,-300,100);
    
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff_CalCut%d",ipmt+1),"",1000,-300,100);

    h1PHGCERPGoodAdcTdcDiffTime[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTime%d",ipmt+1),"", 1000, -300, 100);

    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTimeMult%d",ipmt+1), "", 1000, -300, 100);

    h1TimeVsAmpMult[ipmt] = new TH2F(Form("h1TimeVsAmpMult%d",ipmt+1), "" , 1000, -300, 100, 1000, 0, 1000);

    h1TimeVsAmpCal[ipmt] = new TH2F(Form("h1TimeVsAmpCal%d",ipmt+1), "" , 1000, -300, 100, 1000, 0, 1000);

    h1TimeVsAmpMultCal[ipmt] = new TH2F(Form("h1TimeVsAmpMultCal%d",ipmt+1), "" , 1000, -300, 100, 1000, 0, 1000);

    h1goodTimeVsAmpMult[ipmt]= new TH2F(Form("h1goodTimeVsAmpMult%d",ipmt+1), "" , 1000, -300, 100, 1000, 0, 1000);

    h1goodTimeCal[ipmt] = new TH1F (Form("h1goodTimecal%d", ipmt+1),"",1000,-300,100);
    
    h1goodTimeMultCal[ipmt] = new TH1F (Form("h1goodTimeMultCal%d", ipmt+1),"",1000,-300,100);

    GetOutputList()->Add(h1PHGCERPulseTime[ipmt]);
    GetOutputList()->Add(h1PHGCERPulseTimeStarttimeDiff[ipmt]);

    
  }
  
}


Bool_t SHMSADCGates::Process(Long64_t entry)
{
  
  fReader.SetEntry(entry);

  if(entry<1000) {//Abort("end of the desired entry");
    
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    cout << "Entry: " << entry << endl;
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    //cout <<"\n";
    
    //**************************** Filling Histograms****************************************// 
    //***************************************HGCER*******************************************//
    //********There are 4 pmts. Here we are looping over all hits ***************************//
    
    for (Int_t i = 0; i < *Ndata_P_hgcer_adcPulseTime; i++) {
      
      if (P_hgcer_adcErrorFlag[i] == 1) continue;

      Int_t current_pmt = P_hgcer_adcCounter[i] - 1;
      
      h1PHGCERPulseTime[current_pmt]->Fill(-P_hgcer_adcPulseTime[i]);
      
      h1PHGCERPulseTimeStarttimeDiff[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime); // no selection
      
      if(*P_cal_etottracknorm >0.8)// all hits with electron 
	{
	  h1PHGCERPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime); 

	  h1TimeVsAmpCal[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime, P_hgcer_adcPulseAmp[i]);

	  h1goodTimeCal[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[current_pmt]);
	}
      
      h1PHGCERPulseTimeVsPulseAmp[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime,  P_hgcer_adcPulseAmp[i]);
      
      h1PHGCERPGoodAdcTdcDiffTime[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[current_pmt]);

      h1PHGCERPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[i], P_hgcer_goodAdcPulseAmp[i]);
      
      if (P_hgcer_goodAdcMult[current_pmt] == 1) //hits with mult
	{
	  h1PHGCERPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime);
	  
	  h1PHGCERPGoodAdcTdcDiffTime_Mult[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[current_pmt]);
	  
	  h1goodTimeVsAmpMult[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[i], P_hgcer_goodAdcPulseAmp[i]);
	  
	  h1TimeVsAmpMult[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime, P_hgcer_adcPulseAmp[i]);
	  
	  if(*P_cal_etottracknorm >0.8)//hits with electron and Multiplicity
	    {
	      h1PHGCERPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime);// all hit with elec and mult==1
	      
	      h1TimeVsAmpMultCal[current_pmt]->Fill(-P_hgcer_adcPulseTime[i] + *P_hod_starttime,  P_hgcer_adcPulseAmp[i]);

	      h1goodTimeMultCal[current_pmt]->Fill(P_hgcer_goodAdcTdcDiffTime[current_pmt]);
	    }
	}    
    }
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
  
 

  //Begin peak Finding
  gSystem->RedirectOutput("/dev/null","a");
  gSystem->RedirectOutput(0);

 

  //Begin Plotting Results 
  TString option = GetOption();
  gStyle->SetOptStat(0);

  TLegend * legend[8];

  
  // legend[1] = new TLegend(0.1,0.7,0.48,0.9);
  // legend[2] = new TLegend(0.1,0.7,0.48,0.9);
  // legend[3] = new TLegend(0.1,0.7,0.48,0.9);

 
  
  for (Int_t ipmt=0; ipmt < 4; ipmt++) {
    TCanvas *c1 = new TCanvas("c1", "" , 600, 600);//HGcer canvas
    c1->Divide(2,2);
    int ipmtt=0;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->SetHeader("tighter cut","C");
 
    c1->cd(1);  gPad->SetLogy();
    
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->Draw();// no hit selection
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->SetTitle(Form("PMT %d",ipmt+1));
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);// cal cut

    h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
    h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineStyle(2);
    h1PHGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kBlue-7); // multiplicity cut

    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed-10); // electron and multiplicity cut
    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineStyle(2);
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetXaxis()->SetTitle("-P.hgcer.adcPulseTime + P.hod.starttime");
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitle("Counts");
    
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult[ipmt],"mult = 1","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Calorimeter Cut","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    legend[ipmtt]->Draw();
    
    // subplots for time and amplitude 
    c1->cd(2);gPad->Divide(2,2);
    gPad->cd(1); // no hits selection
    ipmtt+=1;
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetXaxis()->SetTitle("-P.hgcer.adcPulseTime + P.hod.starttime");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitle("P.hgcer.adcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->SetLineStyle(2);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection", "l");
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];

    c1->cd(2); gPad->cd(2); // multiplicity
    ipmtt+=1;
    h1TimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMult[ipmt ]->GetXaxis()->SetTitle("-P.hgcer.adcPulseTime + P.hod.starttime");
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitle("P.hgcer.adcPulseAmp");
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult [ipmt ], "mult=1", "l");
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];

    c1->cd(2); gPad->cd(3); // Cal_Cut 
    ipmtt+=1;
    h1TimeVsAmpCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpCal[ipmt ]->GetXaxis()->SetTitle("-P.hgcer.adcPulseTime + P.hod.starttime");
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitle("P.hgcer.adcPulseAmp");
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Cal Cut","l");
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  
    c1->cd(2); gPad->cd(4); // multiplicity and cal cut
    ipmtt+=1;
    h1TimeVsAmpMultCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMultCal[ipmt ]->GetXaxis()->SetTitle("-P.hgcer.adcPulseTime + P.hod.starttime");
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitle("P.hgcer.adcPulseAmp");
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // cout<<"kera   2222"<<endl;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    legend[ipmtt]->SetTextSize(0.03);
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  

    c1->cd(4);gPad->Divide(2,1);
    gPad->cd(1);
    ipmtt=ipmtt+1;
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitle("P.hgcer.goodAdcTdcDiffTime");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitle("P.hgcer.goodAdcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.12,0.8,0.48,0.89);
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana", "l");
    legend[ipmtt]->SetTextSize(0.05);legend[ipmtt]->SetBorderSize(0);
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
   


         
    c1->cd(4); gPad->cd(2);
    ipmtt=ipmtt+1;
    h1goodTimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitle("P.hgcer.goodAdcTdcDiffTime");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitle("P.hgcer.goodAdcPulseAmp");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitleOffset(1.65);
    legend[ipmtt] = new TLegend(0.12,0.8,0.48,0.89);
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->SetTextSize(0.05); legend[ipmtt]->SetBorderSize(0);
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
   

    c1->cd(3);gPad->SetLogy();
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->Draw();//
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->Draw("same");
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineColor(kBlue-7);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineStyle(2);
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("P.hgcer.goodAdcTdcDiffTime");
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("Counts");
    h1goodTimeCal[ipmt]->Draw("same");
    h1goodTimeCal[ipmt]->SetLineColor(kRed);
    h1goodTimeMultCal[ipmt]->Draw("same");
    h1goodTimeMultCal[ipmt]->SetLineColor(kRed-10);
    h1goodTimeMultCal[ipmt]->SetLineStyle(2);
    ipmtt=ipmtt+1;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->SetHeader("tighter cut","C");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana (good)", "l");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->AddEntry( h1goodTimeCal[ipmt],"good with Cal","l");
    legend[ipmtt]->AddEntry( h1goodTimeMultCal[ipmt],"good with cal & mult","l"); 
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
    
    c1->SaveAs(Form("tighter_HGCER_pmt_%i.pdf", ipmt+1));
    
    delete c1;
    for(int ii=0;ii<8;ii++)
    delete legend[ii];
    //delete [] legend;
  } 
}                  
