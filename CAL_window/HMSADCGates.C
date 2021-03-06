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

  h1 = new TH1F*[2];// amp
  h2 = new TH1F*[2];

  h1_int = new TH1F*[2]; //integral 
  h2_int = new TH1F*[2];

  h1_delta = new TH1F*[2];
  h1_gooddelta = new TH1F*[2];
  h1XtrackVsYtrack = new TH2F*[2];

  //h1wieghtAmp = new TH2F;
  // h1wieghtAmpNorm = new TH2F
  //h1XtrackVsYtrack_big = new TH2F*[2];
  // h1_ytrack = new TH1F*[2];

  for (Int_t ipmt=0; ipmt<4; ipmt++) {

    h1PHGCERPulseTime[ipmt] = new TH1F(Form("PHGCERPulseTime%d",ipmt+1),"",750,-150,150);

    //**************************************** NO Hit Selection ***************************************************//

    h1PHGCERPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff%d",ipmt+1),"", 750, -150, 150); // no hit selection 
    
    h1PHGCERPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMult%d",ipmt+1), "", 750, -150, 150); // no hit selection with multiplicity 

    h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiffMultCut%d",ipmt+1),"",750, -150, 150); // no hit selection with multiplicity and calorimeter
    
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PHGCERPulseTimeStarttimeDiff_CalCut%d",ipmt+1),"",750, -150, 150); // no hit selection with calorimeter

    h1_delta[ipmt] = new TH1F(Form("h1_delta%d",ipmt+1),"",750,-150,150);//no hit selection with delta cut

    //*********//********//*************//**********//******* Amplitude Histograms*******//************//*************//*********//***********//

    h1PHGCERPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmp%d",ipmt+1),"",750, -150, 150, 620, -20, 600); // no hit selection ADCTDC VS Amplitude

    h1TimeVsAmpMult[ipmt] = new TH2F(Form("h1TimeVsAmpMult%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600);// no hit selction AdcTdc Vs Amp with multiplicity cut

    h1TimeVsAmpMultCal[ipmt] = new TH2F(Form("h1TimeVsAmpMultCal%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600); // no hit selection AdcTdc Vs Amp with Multiplicity and Calorimter Cut

    h1TimeVsAmpCal[ipmt] = new TH2F(Form("h1TimeVsAmpCal%d",ipmt+1), "" , 750, -150, 150, 620, -20, 600); // no hit selection AdcTdc Vs Amp with Calorimeter cut

    //******************************************************************************************************************//
    //***********************************************HIT Selection ******************************************************//
    //***************************************************************************************************************//


    h1PHGCERPGoodAdcTdcDiffTime[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTime%d",ipmt+1),"", 500, 40, 160); // hit selection AdcTdc 

    h1_gooddelta[ipmt] = new TH1F(Form("h1_gooddelta%d",ipmt+1),"",500, 40, 160); // hit selection with delta cut

    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt] = new TH1F(Form("PHGCERGoodAdcTdcDiffTimeMult%d",ipmt+1), "", 500, 40, 160); // hit selection with multiplicity cut

    h1goodTimeCal[ipmt] = new TH1F (Form("h1goodTimecal%d", ipmt+1),"",500, 40, 160); //hit selection with calorimter cut only

    h1goodTimeMultCal[ipmt] = new TH1F (Form("h1goodTimeMultCal%d", ipmt+1),"",500, 40, 160); //hit selection with multiplicity and calorimeter cut

    ///////////////////////////////////////************************************************///////////////////////////////////////
    //*********************************************Amplitude PLots***************************************************************//
   
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PHGCERPulseTimeVsPulseAmpMultCut%d",ipmt+1),"",500, 40, 160, 620, -20, 600); //hit selection AdcTdc Vs Amplitude 

    h1goodTimeVsAmpMult[ipmt]= new TH2F(Form("h1goodTimeVsAmpMult%d",ipmt+1), "" , 500, 40, 160, 620, -20, 600); // hit selection  AdcTdc Vs Amplitude with multiplicity cut
    
    

    /////****************************************************************************************************/////

    h1[ipmt] = new TH1F (Form("h1%d", ipmt +1),"", 500, -30, 250);
    h2[ipmt] = new TH1F (Form("h2%d", ipmt +1),"", 500, -30, 250);


    h1_int[ipmt] = new TH1F (Form("h1_int%d", ipmt +1),"", 200, 0, 150);
    h2_int[ipmt] = new TH1F (Form("h2_int%d", ipmt +1),"", 200, 0, 150);

    h1XtrackVsYtrack[ipmt] = new TH2F(Form("h1TrackVsYtrack%d",ipmt+1),"",150, -40, 40, 150, -40 ,40);

    // h1XtrackVsYtrack_big[ipmt] = new TH2F(Form("h1TrackVsYtrack_big%d",ipmt+1),"",150, -40, 40, 150, 40 ,40); 

    GetOutputList()->Add(h1PHGCERPulseTime[ipmt]);
    GetOutputList()->Add(h1PHGCERPulseTimeStarttimeDiff[ipmt]);

    
  }

 h1weightAmp = new TH2F("h1weight", "", 100, -40, 40, 100, -40, 40);
 h1weightAmpNorm = new TH2F("h1weightNorm", "", 100, -40, 40, 100, -40, 40);
 h1trackproject = new TH2F("h1trackproject", "" , 100, -40, 40, 100, -40, 40);
}


Bool_t HMSADCGates::Process(Long64_t entry)
{
  fReader.SetEntry(entry);

  if(entry<100000000) {//Abort("end of the desired entry");
    
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    cout << "Entry: " << entry << endl;
    cout << "\n=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n" << endl;
    //cout <<"\n";
    
    //**************************** Filling Histograms****************************************// 
   
    //********There are 4 pmts. Here we are looping over all hits ***************************//

     
    
    for (Int_t i = 0; i < *Ndata_H_cer_adcPulseTime; i++) {
      
      if (H_cer_adcErrorFlag[i] == 1) continue;

      Int_t current_pmt = H_cer_adcCounter[i] - 1;

      // if (*H_hod_starttime>20 && *H_hod_starttime<30){ //*********************************************timing cut *********************//
	
	h1PHGCERPulseTime[current_pmt]->Fill(-H_cer_adcPulseTime[i]);
	
	h1PHGCERPulseTimeStarttimeDiff[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime); // no hit selection. Its adctdc time diff



	if(*H_cal_etottracknorm >0.8)// all hits with electron 
	  {
	    if(*H_gtr_dp>-8 && *H_gtr_dp<10)
	      {
		h1_delta[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime); //delta cut on no hit selection
		h1_gooddelta[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]); //delta cut on hit selection
	      }
	    
	    h1PHGCERPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime);  // adctdc time diff with multiplicity cut and calorimter cut
	    
	    h1TimeVsAmpCal[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime, H_cer_adcPulseAmp[i]); // amplitude with electron
	    
	    h1goodTimeCal[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]); //
	  }
	
	h1PHGCERPulseTimeVsPulseAmp[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime,  H_cer_adcPulseAmp[i]);
	
	h1PHGCERPGoodAdcTdcDiffTime[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	
	h1PHGCERPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt], H_cer_goodAdcPulseAmp[current_pmt]); // hit selection with no cuts
	
	if (H_cer_goodAdcMult[current_pmt] == 1) //hits with mult
	  {
	    h1PHGCERPulseTimeStarttimeDiffMult[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime);// no hit selection with multiplicity cut
	    
	    h1PHGCERPGoodAdcTdcDiffTime_Mult[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	    
	    h1goodTimeVsAmpMult[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt], H_cer_goodAdcPulseAmp[current_pmt]);
	    
	    h1TimeVsAmpMult[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime, H_cer_adcPulseAmp[i]);
	    
	    if(*H_cal_etottracknorm >.8)//hits with electron and Multiplicity
	      {
		h1PHGCERPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime);// all hit with elec and mult==1
		
		h1TimeVsAmpMultCal[current_pmt]->Fill(-H_cer_adcPulseTime[i] + *H_hod_starttime,  H_cer_adcPulseAmp[i]);
		
		h1goodTimeMultCal[current_pmt]->Fill(H_cer_goodAdcTdcDiffTime[current_pmt]);
	      }
	  } 
	
	//	cout <<"value"<<(-H_cer_adcPulseTime[i] + *H_hod_starttime)<<endl;
	
	// if ((-H_cer_adcPulseTime[i] + *H_hod_starttime)> -50 && (-H_cer_adcPulseTime[i] + *H_hod_starttime)<-30)// small peak 
	//   {
	//     h1[current_pmt]->Fill(H_cer_adcPulseAmp[i]);//amplitude
	//     h1_int[current_pmt]->Fill(H_cer_adcPulseInt[i]);//integral
	//     h1XtrackVsYtrack[current_pmt]->Fill(*H_cer_xAtCer, *H_cer_yAtCer);
	//   }
	// if ((-H_cer_adcPulseTime[i] + *H_hod_starttime)> -30 && (-H_cer_adcPulseTime[i] + *H_hod_starttime)<-10)// big peak
	//   {x
	//     h2[current_pmt]->Fill(H_cer_adcPulseAmp[i]);//amplitude
	//     h2_int[current_pmt]->Fill(H_cer_adcPulseInt[i]); //integral
	//   }

	// if (H_cer_goodAdcTdcDiffTime[current_pmt]> -50 && H_cer_goodAdcTdcDiffTime[current_pmt]<-38)// small peak looking into good variable
	//   {
	//     h1[current_pmt]->Fill(H_cer_goodAdcPulseAmp[current_pmt]);
	//     h1_int[current_pmt]->Fill(H_cer_goodAdcPulseInt[current_pmt]);

	//     //*******************track projection ************************************************************************************88//
	//     if (H_cer_goodAdcPulseAmp[current_pmt]<400)
	//       {
	// 	h1XtrackVsYtrack[current_pmt]->Fill(*H_dc_x_fp - 89.1 * (*H_dc_xp_fp), *H_dc_y_fp -89.1 *(*H_dc_yp_fp)); // in four pmt's which doesnt make sense
		
	// 	h1weightAmp->Fill(*H_dc_x_fp - 89.1 * (*H_dc_xp_fp), *H_dc_y_fp - 89.1 *(*H_dc_yp_fp), H_cer_goodAdcPulseAmp[current_pmt]); //weighting by Amplitude
		
	// 	h1trackproject->Fill(*H_dc_x_fp - 89.1 * (*H_dc_xp_fp), *H_dc_y_fp - 89.1 *(*H_dc_yp_fp)); // track projected onto mirror
	//       }
	//   }

	// if (H_cer_goodAdcTdcDiffTime[current_pmt]> -30 && H_cer_goodAdcTdcDiffTime[current_pmt] <-10)// big peak
	//   {
	//     h2[current_pmt]->Fill(H_cer_goodAdcPulseAmp[current_pmt]);
	//     h2_int[current_pmt]->Fill(H_cer_goodAdcPulseInt[current_pmt]);
	//   }
	
	
	//     // }
	
	//cout << *H_cer_xAtCer<<endl;
    }  
    
    

    // cout << " track: " <<*H_dc_x_fp - 89.1 * (*H_dc_xp_fp) <<endl;
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
  TLegend * legend[5];

  for (Int_t ipmt=0; ipmt < 2; ipmt++) {
    TCanvas *c1 = new TCanvas("c1", "" , 600, 600);//HGcer canvas
    c1->Divide(2,1);
    int ipmtt=0;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    // legend[ipmtt]->SetHeader("wide cut","C");
 
    c1->cd(1);  gPad->SetLogy(1); //gPad->SetGrid();
    
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->Draw();// no hit selection
    h1PHGCERPulseTimeStarttimeDiff[ipmt]->SetTitle(Form("PMT %d",ipmt+1));

    h1_delta[ipmt]->Draw("same"); // delta cut 
    h1_delta[ipmt]->SetLineColor(kGreen);

    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);// cal cut
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->SetTitle(Form("PMT %d",ipmt+1));
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt]-> GetYaxis()->SetTitle("Counts"); 


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
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Calorimeter Cut","l");
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    legend[ipmtt]->AddEntry(h1_delta[ipmt],"delta>-8 && delta<10 && Cal","l");
    legend[ipmtt]->SetTextSize(0.03);
    legend[ipmtt]->Draw();
    
    //h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    // PHGCPULSETIMEDIFFCUT[ipmt]->Draw("same");
    // PHGCPULSETIMEDIFFCUT[ipmt]->SetLineColor(kRed);


    // subplots for time and amplitude 
    c1->cd(2);gPad->Divide(2,2); //gPad->SetGrid();
    gPad->cd(1); // no hits selection
    ipmtt+=1;
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetXaxis()->SetTitleSize(0.05);
    // h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitleSize(0.04);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1PHGCERPulseTimeVsPulseAmp[ipmt]->SetLineStyle(2);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff[ipmt],"no hit selection", "l");
    legend[ipmtt]->SetTextSize(0.04);
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];

    c1->cd(2); gPad->cd(2); // multiplicity
    ipmtt+=1; //gPad->SetGrid();
    h1TimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMult[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1TimeVsAmpMult[ipmt ]->GetXaxis()->SetTitleSize(0.05);
    //h1TimeVsAmpMult[ipmt ]->GetYaxis()->SetLabelSize(0.05);
 
    h1TimeVsAmpMult[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMult [ipmt ], "mult=1", "l");
    legend[ipmtt]->Draw();legend[ipmtt]->SetTextSize(0.04);
    
    //  delete legend[ipmtt];

    c1->cd(2); gPad->cd(3); // Cal_Cut 
    ipmtt+=1; //gPad->SetGrid();
    h1TimeVsAmpCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpCal[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    h1TimeVsAmpCal[ipmt ] ->GetXaxis()->SetTitleSize(0.05);
    //h1TimeVsAmpCal[ipmt ]-> GetYaxis()->SetLabelSize(0.05);
 
    h1TimeVsAmpCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiff_CalCut[ipmt],"Cal Cut","l");
    legend[ipmtt]->Draw();legend[ipmtt]->SetTextSize(0.04);
    //  delete legend[ipmtt];
  
    c1->cd(2); gPad->cd(4); // multiplicity and cal cut
    ipmtt+=1; //gPad->SetGrid();
    h1TimeVsAmpMultCal[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1TimeVsAmpMultCal[ipmt ]->GetXaxis()->SetTitle("-H.cer.adcPulseTime + H.hod.starttime");
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitle("H.cer.adcPulseAmp");
    // h1TimeVsAmpMultCal[ipmt ] ->GetXaxis()->SetLabelSize(0.05);
    h1TimeVsAmpMultCal[ipmt ] -> GetXaxis()->SetTitleSize(0.05);
    h1TimeVsAmpMultCal[ipmt ] ->GetYaxis()->SetTitleOffset(1.5);
    // cout<<"kera   2222"<<endl;
    legend[ipmtt] = new TLegend(0.1,0.8,0.48,0.9);
    legend[ipmtt]->AddEntry(h1PHGCERPulseTimeStarttimeDiffMultCut[ipmt],"mult = 1 & Cal Cut","l");
    legend[ipmtt]->SetTextSize(0.04);
    legend[ipmtt]->Draw();
    //  delete legend[ipmtt];
   c1->SaveAs(Form("AdcTdc_CER_pmt_%i.pdf", ipmt+1));
    
    delete c1;
    for(int ii=0;ii<5;ii++)
    delete legend[ii];
  }

  //******************************************Canvas for hit Selection**********************************//
  TLegend * leg[3];

  for (Int_t ipmt=0; ipmt < 2; ipmt++) {
    
    auto *c0 = new TCanvas ("c0", "" , 600,600);
    c0->Divide(2,1);
    
    int ipmtt=0;
 
    c0->cd(1);gPad->SetLogy();
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->Draw();//hit selection
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->SetTitle(Form("PMT %d",ipmt+1));
    h1_gooddelta[ipmt]->Draw("same");
    h1_gooddelta[ipmt]->SetLineColor(kGreen);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->Draw("same");// hit selection with multiplicity cut 
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineColor(kBlue-7);
    h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineStyle(2);
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1PHGCERPGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("Counts");
    h1goodTimeCal[ipmt]->Draw("same");// with calorimeter cut
    h1goodTimeCal[ipmt]->SetLineColor(kRed);
    h1goodTimeMultCal[ipmt]->Draw("same");// with calorimeter and Multiplicity cut
    h1goodTimeMultCal[ipmt]->SetLineColor(kRed-10);
    h1goodTimeMultCal[ipmt]->SetLineStyle(2);

    leg[ipmtt] = new TLegend(0.5,0.8,0.9,0.9);
    leg[ipmtt]->SetHeader("wide cut","C");
    leg[ipmtt]->SetTextSize(0.03);
    leg[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana (good)", "l");
    leg[ipmtt]->AddEntry(h1_gooddelta[ipmt], "good with delta & mult", "l");
    leg[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    leg[ipmtt]->AddEntry( h1goodTimeCal[ipmt],"good with Cal","l");
    leg[ipmtt]->AddEntry( h1goodTimeMultCal[ipmt],"good with Cal & mult","l"); 

    leg[ipmtt]->Draw();




    c0->cd(2);gPad->Divide(2,1);
    gPad->cd(1);
    ipmtt=ipmtt+1;
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    h1PHGCERPulseTimeVsPulseAmpMultCut[ipmt]->GetXaxis()->SetTitleSize(0.05);
    leg[ipmtt] = new TLegend(0.12,0.8,0.48,0.89);
    leg[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana", "l");
    leg[ipmtt]->SetTextSize(0.05);
    leg[ipmtt]->SetBorderSize(0);
    leg[ipmtt]->Draw();

    // // delete legend[ipmtt];
   


         
    c0->cd(2); gPad->cd(2);
    ipmtt=ipmtt+1;
    h1goodTimeVsAmpMult[ipmt]->Draw("colz");gPad->SetLogz(1);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcTdcDiffTime");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitle("H.cer.goodAdcPulseAmp");
    h1goodTimeVsAmpMult[ipmt]->GetYaxis()->SetTitleOffset(1.65);
    h1goodTimeVsAmpMult[ipmt]->GetXaxis()->SetTitleSize(0.05);


    leg[ipmtt] = new TLegend(0.12,0.8,0.48,0.89);
    leg[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    leg[ipmtt]->SetTextSize(0.05);
    leg[ipmtt]->SetBorderSize(0);
    leg[ipmtt]->Draw();
    // delete legend[ipmtt];
    

    
    // ipmtt=ipmtt+1;
    // 
    // delete legend[ipmtt];
    
    c0->SaveAs(Form("GoodAdcTdc_CER_pmt_%i.pdf", ipmt+1));
    delete c0;
     for(int ii=0;ii<3;ii++)
       delete leg[ii];
  }
   
   
    
    //delete [] legend;
  
  //************************for the area under the curve***************************//
  // for (int pmt = 0; pmt < 4; pmt ++)
  //   {
  //     if (pmt == 0)
  // 	{
  // 	  cout << h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()<< endl;
  // 	  //cout << h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(683,698)<< endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(683,698)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100 <<"%"<<endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(625,670)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100 <<"%"<<endl;
  // 	}
  //     if (pmt == 1)
  // 	{
  // 	  cout <<h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()<< endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(694,711)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100<<"%" <<endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(625,670)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100 <<"%"<<endl;
  // 	}
  //     if (pmt == 2)
  // 	{
  // 	  cout <<h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()<< endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(691,704)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100<<"%" <<endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(625,670)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100 <<"%"<<endl;
  // 	}
  //      if (pmt == 3)
  // 	{
  // 	  cout <<h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()<< endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(688,704)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100<<"%" <<endl;
  // 	  cout << (h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->Integral(625,670)/h1PHGCERPulseTimeStarttimeDiff_CalCut[pmt]->GetEntries()) *100 <<"%"<<endl;
  // 	}

  //      cout <<"total :" << h1PHGCERPGoodAdcTdcDiffTime[pmt]->GetEntries()<<endl;
  //      cout <<"After Cut :" << h1PHGCERPGoodAdcTdcDiffTime_Mult[pmt]->GetEntries()<<endl;
       
  //   }
  



  //********************* for Integral and Amplitude selection ****************//

  // TCanvas *c2 = new TCanvas ("c2", "" , 600, 600);
  // c2->Divide(2,2);
  // TCanvas *c3 = new TCanvas ("c3", "" , 600, 600);
  // c3->Divide(2,2);


  // for (int ipmt = 0; ipmt<4; ipmt++){
  //   c2->cd(ipmt+1);gPad->SetLogy(1);
  //   h2[ipmt]->Draw();
  //   h1[ipmt]->Draw("same"); h1[ipmt]->SetLineColor(kRed);
  //   h2[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcPulseAmp");
  //   h2[ipmt]->SetTitle(Form("Amp_Pmt%d",ipmt+1));

  //   c3->cd(ipmt+1);gPad->SetLogy(1);
  //   h2_int[ipmt]->Draw();
  //   h1_int[ipmt]->Draw("same"); h1_int[ipmt]->SetLineColor(kRed);
  //   h2_int[ipmt]->GetXaxis()->SetTitle("H.cer.goodAdcPulseInt");
  //   h2_int[ipmt]->SetTitle(Form("Int_Pmt%d",ipmt+1));
  // }
  //  c2->SaveAs("Ngcer_Amplitude_pmt.eps");
  //  c3->SaveAs("Ngcer_Integral_pmt.eps");
  

  //******************** Ratio Plot no hit selection ***************************************************************//
  // TCanvas *c4 = new TCanvas("c4", "", 600, 600);
  // c4->Divide(2,2);
  // TCanvas *c5 = new TCanvas("c5", "", 600, 600);
  // c5->Divide(2,2);
  // for (int ii= 0; ii<4; ii++)
  //   {
  //     c4->cd(ii+1);gPad->SetLogy();
  //     h1PHGCERPulseTimeStarttimeDiff[ii]->Sumw2();h1PHGCERPulseTimeStarttimeDiffMult[ii]->Sumw2();
  //     // h1PHGCERPulseTimeStarttimeDiffMult[ii]->Scale(1/h1PHGCERPulseTimeStarttimeDiffMult[ii]->GetEntries());
  //     // h1PHGCERPulseTimeStarttimeDiff[ii]->Scale(1/h1PHGCERPulseTimeStarttimeDiff[ii]->GetEntries());
  //     auto rp = new TRatioPlot(h1PHGCERPulseTimeStarttimeDiff[ii], h1PHGCERPulseTimeStarttimeDiffMult[ii]);
  //     rp->Draw();
  //     rp->GetLowerRefGraph()->SetMinimum(0.9);
  //     rp->GetLowerRefGraph()->SetMaximum(1.1);
  //     rp->GetLowerRefGraph()->GetXaxis()->SetRangeUser(-60,10);
  //     c5->cd(ii+1);gPad->SetLogy();
  //     h1PHGCERPulseTimeStarttimeDiff_CalCut[ii]->Sumw2();
  //     h1PHGCERPulseTimeStarttimeDiffMultCut[ii]->Sumw2();
  //     // h1PHGCERPulseTimeStarttimeDiffMultCut[ii]->Scale(1/h1PHGCERPulseTimeStarttimeDiffMultCut[ii]->GetEntries());
  //     // h1PHGCERPulseTimeStarttimeDiff_CalCut[ii]->Scale(1/h1PHGCERPulseTimeStarttimeDiff_CalCut[ii]->GetEntries());

  //     auto rp1 = new TRatioPlot(h1PHGCERPulseTimeStarttimeDiff_CalCut[ii], h1PHGCERPulseTimeStarttimeDiffMultCut[ii]);
  //     rp1->Draw();
  //     rp1->GetLowerRefGraph()->SetMinimum(0.9);
  //     rp1->GetLowerRefGraph()->SetMaximum(1.1);
  //     rp1->GetLowerRefGraph()->GetXaxis()->SetRangeUser(-60,10);
      
  //   }
  // c4->Update(); c4->SetTicks(0, 1);
  // c4->SaveAs("Ngcer_Blue_ratio_plot.eps"); //these are obtained from goodAdcTdc diff time

  // c5->Update(); c5->SetTicks(0, 1);
  // c5->SaveAs("Ngcer_Red_ratio_plot.eps");



  // auto *test = new TCanvas("test", "",600, 600);
  // test->Divide(2,1);
  // test->cd(1);gPad->SetLogy();
  // h1PHGCERPulseTimeStarttimeDiff[2]->Sumw2();
  // auto rp = new TRatioPlot(h1PHGCERPulseTimeStarttimeDiff[2], h1PHGCERPulseTimeStarttimeDiffMult[2]);
  // rp->Draw(); 
  // rp->GetLowerRefGraph()->SetMinimum(0.9);
  // rp->GetLowerRefGraph()->SetMaximum(1.1);
  // rp->GetLowerRefGraph()->GetXaxis()->SetRangeUser(-40,-10);
  // test->cd(2);gPad->SetLogy();
  // h1PHGCERPulseTimeStarttimeDiff_CalCut[2]->Sumw2();
  // auto rp1 = new TRatioPlot(h1PHGCERPulseTimeStarttimeDiff_CalCut[2], h1PHGCERPulseTimeStarttimeDiffMultCut[2]);
  // rp1->Draw();
  // rp1->GetLowerRefGraph()->SetMinimum(0.9);
  // rp1->GetLowerRefGraph()->SetMaximum(1.1);
  // rp1->GetLowerRefGraph()->GetXaxis()->SetRangeUser(-40,-10);
  // test->SetTicks(0, 1);
  // test->Update();
  // test->SaveAs("pmt3_ratio.eps");
  //*************************** for track projection *************************************************//

  // TCanvas *c6 = new TCanvas("c6", "" ,600, 600);
  // c6->Divide(2,2);
  // for (int i= 0; i<4; i++)
  //   {
  //     c6->cd(i+1);gPad->SetLogz(1);
  //     h1XtrackVsYtrack[i]->Draw("colz");
  //   }
  // c6->SaveAs("Ngcer_track_cer.eps");

  // TCanvas *c7 = new TCanvas("c7", "" ,600, 600);
  // //c7->Divide(2,1);
  // // c7->cd(1);
  // // h1weightAmp->Draw("colz");

  // // c7->cd(2);
  // // h1weightAmp->Divide(h1trackproject);
  // // h1weightAmp->Draw("colz");
  
  // c7->cd(1);
  // h1weightAmpNorm = (TH2F*)h1weightAmp->Clone();
  // h1weightAmpNorm->Divide(h1trackproject);
  // h1weightAmpNorm->Draw("colz");
  // h1weightAmpNorm->SetTitle("h1/h2");
  // c7->SaveAs("Weighted_plots.eps");
 
}                  
