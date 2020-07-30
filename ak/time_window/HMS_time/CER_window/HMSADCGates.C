#define HMSADCGates_cxx

#include "HMSADCGates.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSpectrum.h>
#include <TPolyMarker.h>
#include <TMath.h>
#include <TSystem.h>

void HMSADCGates::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   
   Info("Begin", "Starting HMS Detector ADC Timing Window Script");
}

void HMSADCGates::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
  
  
 
  
  h1PHGCERPulseTimeStarttimeDiff_CalCut = new TH1F*[2];
  
  //****************** HgCer( 4 pmts) **********************************//
  h1PHGCERPulseTime              = new TH1F*[2];
  h1PHGCERPulseTimeStarttimeDiff = new TH1F*[2];
  h1PHGCERPGoodAdcTdcDiffTime = new TH1F*[2];
  h1PHGCERPGoodAdcTdcDiffTime_Mult = new TH1F*[2];
  h1PHGCERPulseTimeVsPulseAmp = new TH2F*[2];
  h1PHGCERPulseTimeStarttimeDiffMult = new TH1F*[2];
  h1PHGCERPulseTimeStarttimeDiffMultCut = new TH1F*[2];
  h1PHGCERPulseTimeVsPulseAmpMultCut = new TH2F*[2];
  h1TimeVsAmpMult =new TH2F*[2];
  h1TimeVsAmpCal = new TH2F*[2];
  h1TimeVsAmpMultCal=new TH2F*[2];
  h1goodTimeVsAmpMult=new TH2F*[2];
  
  h1goodTimeCal= new TH1F*[2];
  h1goodTimeMultCal= new TH1F *[2];
  
  
  for (Int_t ipmt=0; ipmt<4; ipmt++) {

    h1PHGCERPulseTime[ipmt] = new TH1F(Form("PHGCERPulseTime%d",ipmt+1),"",750, -150, 150);
    
    //********************************************NO hit Selectin********************************************//
    h1PHGCERPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff%d",ipmt+1),"",750, -150, 150);

    h1PHGCERPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMult%d",ipmt+1),"",750, -150, 150);

    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMultCut%d",ipmt+1),"",750, -150, 150);

    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff_CalCut%d",ipmt+1),"",750, -150, 150);
    
    //***********************************Amplitude plot NO hit Selection ******************************************************//
    
    h1PHGCERPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmp%d",ipmt+1),"",750, -150, 150, 620, -20, 600);

    h1TimeVsAmpMult[ipmt] = new TH2F(Form("h1TimeVsAmpMult%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600);

    h1TimeVsAmpCal[ipmt] = new TH2F(Form("h1TimeVsAmpCal%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600);

    h1TimeVsAmpMultCal[ipmt] = new TH2F(Form("h1TimeVsAmpMultCal%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600);

    //**********************************************Hit selection********************************************//
  
    h1PHGCERPGoodAdcTdcDiffTime[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTime%d",ipmt+1),"", 500, 40, 160);

    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTimeMult%d",ipmt+1), "", 500, 40, 160);

    h1goodTimeCal[ipmt] = new TH1F (Form("h1goodTimecal%d", ipmt+1),"",500, 40, 160);
    
    h1goodTimeMultCal[ipmt] = new TH1F (Form("h1goodTimeMultCal%d", ipmt+1),"", 500, 40, 160);

     //***********************************Amplitude plot Hit  Selection ******************************************************//

    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmpMultCut%d",ipmt+1),"",750, -150, 150, 620, -20, 600);
    
    h1goodTimeVsAmpMult[ipmt]= new TH2F(Form("h1goodTimeVsAmpMult%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600);

    
    
  }
}
  
  Bool_t HMSADCGates::Process(Long64_t entry)
  {
    
    fReader.SetEntry(entry);

    if(entry<10000000) {


      cout <<":=:=:=:=::=:=:=:=:=:=:=:=:=:==:=:"<<endl;
      cout <<"Entry: "<<entry << endl;
      cout <<":=:=:=:=::=:=:=:=:=:=:=:=:=:==:=:"<<endl;
      cout <<"npeSum :" << *H_cer_npeSum << endl;
      
      for (Int_t i = 0; i < *Ndata_H_cer_adcPulseTime; i++) {
	
	if (H_cer_adcErrorFlag[i] == 1) continue;
	
	Int_t current_pmt = H_cer_adcCounter[i] - 1;
	
	h1PHGCERPulseTime[current_pmt]->Fill(-H_cer_adcPulseTime[i]);
	
	h1PHGCERPulseTimeStarttimeDiff[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime); // no selection
	
	if(*H_cer_npeSum >2.0)// all hits with electron 
	  {
	    h1PHGCERPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime); 
	    
	    h1TimeVsAmpCal[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime, H_cer_adcPulseAmp[i]);
	    
	    h1goodTimeCal[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	  }
	
	h1PHGCERPulseTimeVsPulseAmp[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime,  H_cer_adcPulseAmp[i]);
	
	h1PHGCERPGoodAdcTdcDiffTime[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	
	h1PHGCERPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[i], H_cer_goodAdcPulseAmp[i]);
	
	if (H_cer_goodAdcMult[current_pmt] == 1) //hits with mult
	  {
	    h1PHGCERPulseTimeStarttimeDiffMult[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime);
	    
	    h1PHGCERPGoodAdcTdcDiffTime_Mult[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	    
	    h1goodTimeVsAmpMult[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[i], H_cer_goodAdcPulseAmp[i]);
	    
	    h1TimeVsAmpMult[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime, H_cer_adcPulseAmp[i]);
	    
	    if(*H_cer_npeSum >2.0)//hits with electron and Multiplicity
	      {
		h1PHGCERPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime);// all hit with elec and mult==1
		
		h1TimeVsAmpMultCal[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime,  H_cer_adcPulseAmp[i]);
		
		h1goodTimeMultCal[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	      }
	  }    
      }
    } 
    
    return kTRUE;
  }

void HMSADCGates::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void HMSADCGates::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
  
  Info("Terminate", "Branches Sorted, Now Calculating Windows");
  
  gSystem->RedirectOutput("/dev/null","a");
  gSystem->RedirectOutput(0);
  TString option = GetOption();

  gStyle->SetOptStat(0);
  
  TLegend * legend[8];
  
  for (Int_t ipmt=0; ipmt < 2; ipmt++) {
    TCanvas *c1 = new TCanvas("c1", "" , 600, 600);//HGcer canvas
    c1->Divide(2,2);
    int ipmtt=0;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->SetHeader("wide cut","C");
 
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
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitle("Counts");
    
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult[ipmt],"mult = 1","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Cer Cut","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cer Cut","l");
    legend[ipmtt]->Draw();
    
    //h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    // PHGCPULSETIMEDIFFCUT[ipmt]->Draw("same");
    // PHGCPULSETIMEDIFFCUT[ipmt]->SetLineColor(kRed);


    // subplots for time and amplitude 
    c1->cd(2);gPad->Divide(2,2);
    gPad->cd(1); // no hits selection
    ipmtt+=1;
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->SetLineStyle(2);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection", "l");
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];

    c1->cd(2); gPad->cd(2); // multiplicity
    ipmtt+=1;
    h1TimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMult[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult [ipmt ], "mult=1", "l");
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];

    c1->cd(2); gPad->cd(3); // Cal_Cut 
    ipmtt+=1;
    h1TimeVsAmpCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpCal[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Cer Cut","l");
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  
    c1->cd(2); gPad->cd(4); // multiplicity and cal cut
    ipmtt+=1;
    h1TimeVsAmpMultCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMultCal[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // cout<<"kera   2222"<<endl;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cer Cut","l");
    legend[ipmtt]->SetTextSize(0.03);
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
  

    c1->cd(4);gPad->Divide(2,1);
    gPad->cd(1);
    ipmtt=ipmtt+1;
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.12,0.8,0.48,0.89);
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana", "l");
    legend[ipmtt]->SetTextSize(0.05);legend[ipmtt]->SetBorderSize(0);
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
   


         
    c1->cd(4); gPad->cd(2);
    ipmtt=ipmtt+1;
    h1goodTimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
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
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("Counts");
    h1goodTimeCal[ipmt]->Draw("same");
    h1goodTimeCal[ipmt]->SetLineColor(kRed);
    h1goodTimeMultCal[ipmt]->Draw("same");
    h1goodTimeMultCal[ipmt]->SetLineColor(kRed-10);
    h1goodTimeMultCal[ipmt]->SetLineStyle(2);
    ipmtt=ipmtt+1;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->SetHeader("wide cut","C");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana (good)", "l");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->AddEntry( h1goodTimeCal[ipmt],"good with Cer","l");
    legend[ipmtt]->AddEntry( h1goodTimeMultCal[ipmt],"good with Cer & mult","l"); 
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
    
    c1->SaveAs(Form("Plots/wide_CER_pmt_%i.pdf", ipmt+1));
    
    delete c1;
    for(int ii=0;ii<8;ii++)
    delete legend[ii];
    //delete [] legend;
  }


}
