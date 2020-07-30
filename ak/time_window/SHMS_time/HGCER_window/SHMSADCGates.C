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

  //*********************************************NGCER ****************************************************//
  // h1PNGCERPulseTime              = new TH1F*[4];
  // h1PNGCERPulseTimeStarttimeDiff = new TH1F*[4];

  // h1PNGCERPulseTimeStarttimeDiff_CalCut = new TH1F*[4];
  // h1PNGCERPGoodAdcTdcDiffTime = new TH1F *[4];
  // h1PNGCERPGoodAdcTdcDiffTime_Mult = new TH1F*[4];

  // h1PNGCERPulseTimeVsPulseAmp = new TH2F*[4];
  // h1PNGCERPulseTimeStarttimeDiffMult = new TH1F*[4];
  // h1PNGCERPulseTimeStarttimeDiffMultCut = new TH1F*[4];

  // h1PNGCERPulseTimeVsPulseAmpMultCut = new TH2F*[4];

  // for (Int_t ipmt=0; ipmt<4; ipmt++) {

  //   h1PNGCERPulseTime[ipmt] = new TH1F(Form("PNGCERPulseTime%d",ipmt+1),Form("Pulse Time Information for SHMS NGC PMT%d;Time (ns);Counts",ipmt+1),1000,-400,100);

  //   h1PNGCERPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PNGCERPulseTimeVsPulseAmp%d",ipmt+1),Form("Pulse Time Vs Pulse Amp PMT%d;Pulse Time(ns); Pulse Amp",ipmt+1),1000,-400, 100, 1000, 0, 1000);

  //   h1PNGCERPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PNGCERPulseTimeVsPulseAmpMultCut%d",ipmt+1),Form("Pulse Time Vs Pulse Amp PMT MultCut%d;PulseTime(ns); Pulse Amp",ipmt+1),1000,-300,100, 1000, 0, 1000);
  //   h1PNGCERPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PNGCERPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS NGC  PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,100);
    
  //   h1PNGCERPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PNGCERPulseTimeStarttimeDiffMult%d",ipmt+1),Form("Pulse Time Information for SHMS NGC  PMT Mult%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,100);
  //   h1PNGCERPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PNGCERPulseTimeStarttimeDiffMultCut%d",ipmt+1),Form("Pulse Time Information for SHMS NGC  PMT mult&cut%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,100);

  //   h1PNGCERPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PNGCERPulseTimeStarttimeDiff_CalCut%d",ipmt+1),Form("Pulse Time Information for SHMS NGC  PMT%d Start Time Subtracted(Cut);Time (ns);Counts",ipmt+1),1000,-400,100);
  //   h1PNGCERPGoodAdcTdcDiffTime[ipmt] = new TH1F(Form("PNGCERGoodAdcTdcDiffTime%d",ipmt+1), Form("NGCER Good Adc Tdc Time Diff PMT%d", ipmt+1), 1000, -400, 100);
  //   h1PNGCERPGoodAdcTdcDiffTime_Mult[ipmt] = new TH1F(Form("PNGCERGoodAdcTdcDiffTimeMult%d",ipmt+1), Form("NGCER Good Adc Tdc Time Diff withMult PMT%d", ipmt+1), 1000, -400, 100);

  //   GetOutputList()->Add(h1PNGCERPulseTime[ipmt]);
  //   GetOutputList()->Add(h1PNGCERPulseTimeStarttimeDiff[ipmt]);
  // }
  
 

  //*************************PRESHOWER ******************************************//

  // h1PPRECALNegPulseTime                     = new TH1F*[14];
  // h1PPRECALNegPulseTimeStarttimeDiff        = new TH1F*[14];
  // h1PPRECALNegPulseTimeStarttimeDiffMult    = new TH1F*[14];
  // h1PPRECALNegPulseTimeStarttimeDiffMultCut = new TH1F*[14];
  // h1PPRECALNegPulseTimeStarttimeDiff_CalCut = new TH1F*[14];
  
  // h1PPRECALNegPulseTimeVsPulseAmp           = new TH2F*[14];
  // h1PPRECALNegPulseTimeVsPulseAmpMultCut    = new TH2F*[14];
 
  // h1PPRECALPosPulseTime                     = new TH1F*[14];
  // h1PPRECALPosPulseTimeStarttimeDiff        = new TH1F*[14];
  // h1PPRECALPosPulseTimeStarttimeDiff_CalCut = new TH1F*[14];
  // h1PPRECALPosPulseTimeStarttimeDiffMult    = new TH1F*[14];
  // h1PPRECALPosPulseTimeStarttimeDiffMultCut = new TH1F*[14];
    
  // h1PPRECALPosPulseTimeVsPulseAmpMultCut    = new TH2F*[14];
  // h1PPRECALPosPulseTimeVsPulseAmp           = new TH2F*[14];
  
  // h1PPRECALGoodPosAdcTdcDiffTime            = new TH1F*[14];
  // h1PPRECALGoodNegAdcTdcDiffTime            = new TH1F*[14];
  // h1PPRECALGoodPosAdcTdcDiffTime_Cut        = new TH1F*[14];
  // h1PPRECALGoodNegAdcTdcDiffTime_Cut        = new TH1F*[14];

  


  // for (Int_t ipmt=0; ipmt<14; ipmt++) {

  //   h1PPRECALNegPulseTime[ipmt] = new TH1F(Form("PPRECALNegPulseTime%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Neg PMT%d;Time (ns);Counts",ipmt+1),1000,-400, 0);
    
  //   h1PPRECALNegPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PreCALNegPulseTimeVsPulseAmp%d",ipmt+1),Form("Pulse Time Vs Pulse Neg Amp PMT%d;Pulse Time(ns); Pulse Amp",ipmt+1),1000,-400, 0, 1000, 0, 1000);
    
  //   h1PPRECALPosPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PreCALPosPulseTimeVsPulseAmp%d",ipmt+1),Form("Pulse Time Vs Pulse Amp Pos PMT%d;Pulse Time(ns); Pulse Amp",ipmt+1),1000,-400, 0, 1000, 0, 1000);
    
  //   h1PPRECALNegPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PreCALNegPulseTimeVsPulseAmpWithMultCut%d",ipmt+1),Form("Pulse Time Vs Pulse Amp NegMultCut PMT%d;Pulse Time(ns); Pulse Amp",ipmt+1),1000,-400, 0, 1000, 0, 1000);
    
  //   h1PPRECALPosPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PreCALPosPulseTimeVsPulseAmpWithMultCut%d",ipmt+1),Form("Pulse Time Vs Pulse Amp PosMultCut PMT%d;Pulse Time(ns); Pulse Amp",ipmt+1),1000,-400, 0, 1000, 0, 1000);
    
  //   h1PPRECALNegPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PPRECALNegPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALNegPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PPRECALNegPulseTimeStarttimeDiffMult%d",ipmt+1),Form("Pulse Time with Mult PRECAL Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALNegPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PPRECALNegPulseTimeStarttimeDiffMultCut%d",ipmt+1),Form("Pulse Time MultCut for SHMS PRECAL Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
    
  //   h1PPRECALPosPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PPRECALPosPulseTimeStarttimeDiffMult%d",ipmt+1),Form("Pulse Time with Mult PRECAL Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALPosPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PPRECALPosPulseTimeStarttimeDiffMultCut%d",ipmt+1),Form("Pulse Time MultCut for SHMS PRECAL Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALPosPulseTime[ipmt] = new TH1F(Form("PPRECALPosPulseTime%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Pos PMT%d;Time (ns);Counts",ipmt+1),1000,-400, 0);
    
  //   h1PPRECALPosPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PPRECALPosPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Pos PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALNegPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PPRECALNegPulseTimeStarttimeDiff_Cut%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Neg PMT%d Start Time Subtracted(cut);Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALPosPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PPRECALPosPulseTimeStarttimeDiff_Cut%d",ipmt+1),Form("Pulse Time Information for SHMS PRECAL Pos PMT%d Start Time Subtracted(cut);Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALGoodPosAdcTdcDiffTime[ipmt] =  new TH1F(Form("PPRECALGoodPosAdcTdcDiffTime%d",ipmt+1),Form(" SHMS PRECAL GOOD Pos Adc Tdc Diff Time%d;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALGoodPosAdcTdcDiffTime_Cut[ipmt] =  new TH1F(Form("PPRECALGoodPosAdcTdcDiffTimeCut%d",ipmt+1),Form(" SHMS PRECAL GOOD Pos Adc Tdc Diff TimeCut%d;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALGoodNegAdcTdcDiffTime[ipmt] =  new TH1F(Form("PPRECALGoodNegAdcTdcDiffTime%d",ipmt+1),Form(" SHMS PRECAL GOOD Neg Adc Tdc Diff Time PMT_%d;Time (ns);Counts",ipmt+1),1000,-400,0);
    
  //   h1PPRECALGoodNegAdcTdcDiffTime_Cut[ipmt] =  new TH1F(Form("PPRECALGoodNegAdcTdcDiffTimeCut%d",ipmt+1),Form(" SHMS PRECAL Neg Adc Tdc Diff TimeCut%d;Time (ns);Counts",ipmt+1),1000,-400,0);

  //   GetOutputList()->Add(h1PPRECALNegPulseTime[ipmt]);
  //   GetOutputList()->Add(h1PPRECALNegPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PPRECALPosPulseTime[ipmt]);
  //   GetOutputList()->Add(h1PPRECALPosPulseTimeStarttimeDiff[ipmt]);
  // }
   
  //***********************************SHOWER HISTO********************************//

  // h1PCALPulseTime = new TH1F*[224];
  // h1PCALPulseTimeStarttimeDiff = new TH1F*[224];
  // h1PCALPulseTimeStarttimeDiff_CalCut = new TH1F*[224];
  // h1PCALPulseTimeStarttimeDiffMult = new TH1F*[224];
  // h1PCALPulseTimeStarttimeDiffMultCut = new TH1F*[224];

  // h1PCALGoodAdcTdcDiffTime =  new TH1F*[224];
  // h1PCALGoodAdcTdcDiffTime_Cut =  new TH1F*[224];
  
  // h1PCALPulseTimeVsPulseAmp = new TH2F*[224];
  // h1PCALPulseTimeVsPulseAmpMultCut = new TH2F*[224];
  
  // for (Int_t ipmt=0; ipmt<224; ipmt++) {
    
  //   h1PCALPulseTime[ipmt] = new TH1F(Form("PulseTime%d",ipmt+1),Form("Pulse Time for PMT %d;Time (ns);Counts",ipmt+1),1000,-100,0);

  //   h1PCALPulseTimeVsPulseAmp[ipmt] = new TH2F(Form("PulseTimeVsPulseAmp%d",ipmt+1),Form("Pulse Time Vs Pulse Amp For PMT %d; Pulse Time  (ns); Pulse Amp",ipmt+1),1000,-100, 0, 1000, 0, 1000);

  //   h1PCALPulseTimeVsPulseAmpMultCut[ipmt] = new TH2F(Form("PulseTimeVsPulseAmpWithMult&CalCut%d",ipmt+1),Form("Pulse Time Vs Pulse Amp With Mult&Elec PMT %d; Pulse Time  (ns); Pulse Amp",ipmt+1),1000,-100, 0, 1000, 0, 1000);


  //   h1PCALPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PCALPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-100,0);

  //   h1PCALPulseTimeStarttimeDiffMult[ipmt] = new TH1F(Form("PCALPulseTimeStarttimeDiffMult%d",ipmt+1),Form("Pulse Time With Mult for SHMS CAL PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-100,0);

  //   h1PCALPulseTimeStarttimeDiffMultCut[ipmt] = new TH1F(Form("PCALPulseTimeStarttimeDiffMultCut%d",ipmt+1),Form("Pulse Time With Mult & elec for SHMS CAL PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-100,0);



  //   h1PCALPulseTimeStarttimeDiff_CalCut[ipmt] = new TH1F(Form("PCALPulseTimeStarttimeDiffWithCalCut%d",ipmt+1),Form("Pulse Time Information for PMT%d With CalCut Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-100,0);

  //   h1PCALGoodAdcTdcDiffTime[ipmt] = new TH1F (Form("PCALGoodAdcTdctimeDiff%d",ipmt+1),Form("Cal Good Adc Tdc TimeDiff%d;Time (ns);Counts",ipmt+1),1000,-100,0);

  //   h1PCALGoodAdcTdcDiffTime_Cut[ipmt] = new TH1F (Form("PCALGoodAdcTdctimeDiff(Cut)%d",ipmt+1),Form("Cal Good Adc Tdc TimeDiff(Cut)%d;Time (ns);Counts",ipmt+1),1000,-100,0);
 
  //   GetOutputList()->Add(h1PCALPulseTimeStarttimeDiff[ipmt]);
  // }
  
 
  // h1PHODO1xNegPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO1xPosPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO1yNegPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO1yPosPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO2xNegPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO2xPosPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO2yNegPulseTimeStarttimeDiff = new TH1F*[18];
  // h1PHODO2yPosPulseTimeStarttimeDiff = new TH1F*[18];
  // for (Int_t ipmt=0; ipmt<18; ipmt++) {
  //   h1PHODO1xNegPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO1xNegPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 1x Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO1xPosPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO1xPosPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 1x Pos PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO1yNegPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO1yNegPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 1y Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO1yPosPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO1yPosPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 1y Pos PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO2xNegPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO2xNegPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 2x Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO2xPosPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO2xPosPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 2x Pos PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO2yNegPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO2yNegPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 2y Neg PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);
  //   h1PHODO2yPosPulseTimeStarttimeDiff[ipmt] = new TH1F(Form("PHODO2yPosPulseTimeStarttimeDiff%d",ipmt+1),Form("Pulse Time Information for SHMS HODO 2y Pos PMT%d Start Time Subtracted;Time (ns);Counts",ipmt+1),1000,-50,50);

  //   GetOutputList()->Add(h1PHODO1xNegPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO1xPosPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO1yNegPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO1yPosPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO2xNegPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO2xPosPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO2yNegPulseTimeStarttimeDiff[ipmt]);
  //   GetOutputList()->Add(h1PHODO2yPosPulseTimeStarttimeDiff[ipmt]);

    
  }


Bool_t SHMSADCGates::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // When processing keyed objects with PROOF, the object is already loaded
  // and is available via the fObject pointer.
  //
  // This function should contain the \"body\" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.

  fReader.SetEntry(entry);
  if(entry<10000000) {//Abort("end of the desired entry");
    
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
    
   
    // ***********************************************NGCER*************************************************//
    
    // for (Int_t i = 0; i < *Ndata_P_ngcer_adcPulseTime; i++) {
      
    //   //  cout << "i = " << i << endl;
      
    //   // cout << "hits " << *Ndata_P_ngcer_adcPulseTime << endl;
      
    //   // cout << "error flag before Cut : " << P_ngcer_adcErrorFlag[i]<< endl;
      
    //   if (P_ngcer_adcErrorFlag[i] == 1) continue;
      
    //   // cout << "error flag: " << P_ngcer_adcErrorFlag[i]<< endl;
      
    //   // cout <<"initial counter: "<< P_ngcer_adcCounter[i] << endl;
      
    //   // if (P_ngcer_adcCounter[i] < 1 || P_ngcer_adcCounter[i] > 4) continue;
      
    //   //  cout <<"After counter: "<< P_ngcer_adcCounter[i] << endl;
      
    //   Int_t current_pmt = P_ngcer_adcCounter[i] - 1;
      
    //   // cout << "pmt no: " << current_pmt << endl;
    //   //  cout <<"\n";
      
    //   // cout <<"Pulse time : " <<  -P_ngcer_adcPulseTime[i]<<endl;
      
    //   h1PNGCERPulseTime[current_pmt]->Fill(-P_ngcer_adcPulseTime[i]);
      
    //   //cout <<"*****************"<< h1PNGCERPulseTime[current_pmt]->GetEntries()<<endl;
      
    //   h1PNGCERPulseTimeStarttimeDiff[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime);// all hits 
      
    //   if(P_ngcer_goodAdcMult[current_pmt] ==1)h1PNGCERPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime);// multiplicit cut
      
    //   if(*P_cal_etottracknorm >0.8)
    // 	{
    // 	  h1PNGCERPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime); // electron cuts 
	  
    // 	  if(P_ngcer_goodAdcMult[current_pmt] ==1)
    // 	    {
    // 	      h1PNGCERPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime); //all hits + multiciplity 
    // 	      h1PNGCERPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime,  P_ngcer_adcPulseAmp[i]);// cal cut with mulitplicity 2D
    // 	    }
    // 	}
    //   h1PNGCERPulseTimeVsPulseAmp[current_pmt]->Fill(-P_ngcer_adcPulseTime[i] + *P_hod_starttime ,  P_ngcer_adcPulseAmp[i]);    
    // }
    
    
    // for(Int_t i =0; i<*Ndata_P_ngcer_goodAdcTdcDiffTime; i++)
    //   {
    // 	// cout <<"NdataPngcer:    " <<*Ndata_P_ngcer_goodAdcTdcDiffTime<<endl;
    // 	//Int_t current_pmt = P_hgcer_adcCounter[i] - 1;
    // 	if(P_ngcer_goodAdcMult[i] ==1)
    // 	  {
    // 	    // cout <<"Multiplicity:  "<< P_ngcer_goodAdcMult[i] << endl;
	    
    // 	    h1PNGCERPGoodAdcTdcDiffTime[i]->Fill(P_ngcer_goodAdcTdcDiffTime[i]);
    // 	    // cout << "Entry: " << h1PNGCERPGoodAdcTdcDiffTime[i]->GetEntries()<< endl;
    // 	    if(*P_cal_etottracknorm >0.8){h1PNGCERPGoodAdcTdcDiffTime_Mult[i]->Fill(P_ngcer_goodAdcTdcDiffTime[i]); //cout << "Entry with cut: " << h1PNGCERPGoodAdcTdcDiffTime_Mult[i]->GetEntries()<< endl;
    // 	    }
    // 	  }
    //   }
    
    
    
    //************************************PRE SHOWER ******************************//
    // its one plane and contains 14 paddle. each paddle contains 14 pmts on each side. The two side are named as positive and negative side.
    //so we  have to loop over each side.
    
    //******************** this part is for Negative side of the paddle**************************//
    
    // for (Int_t i = 0; i < *Ndata_P_precal_negAdcPulseTime; i++) {
      
    //   if (P_precal_negAdcErrorFlag[i] == 1) continue;
      
    //   //if (P_precal_negAdcCounter[i] < 1 || P_precal_negAdcCounter[i] > 14) continue;
    //   //if (P_precal_negAdcPulseTime[i] == 0) continue;
      
    //   Int_t current_pmt = P_precal_negAdcCounter[i] - 1;
      
    //   h1PPRECALNegPulseTime[current_pmt]->Fill(-P_precal_negAdcPulseTime[i]);
      
    //   h1PPRECALNegPulseTimeStarttimeDiff[current_pmt]->Fill(-P_precal_negAdcPulseTime[i] + *P_hod_starttime); // all hits 
      
    //   if (P_precal_goodNegAdcMult[current_pmt] == 1)h1PPRECALNegPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_precal_negAdcPulseTime[i] + *P_hod_starttime); // mult cut only
      
    //   if(*P_cal_etottracknorm >0.8)
    // 	{ 
    // 	  h1PPRECALNegPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_precal_negAdcPulseTime[i] + *P_hod_starttime);// elec cut
	  
    // 	  if (P_precal_goodNegAdcMult[current_pmt] == 1)
    // 	    {
    // 	      h1PPRECALNegPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_precal_negAdcPulseTime[i] + *P_hod_starttime);// mult and elec cut
    // 	      h1PPRECALNegPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(-P_precal_negAdcPulseTime[i] + *P_hod_starttime,  P_precal_negAdcPulseAmp[i]);// cal cut with mulitplicity 2D
    // 	    }
	  
    // 	}
      
      
    //   h1PPRECALNegPulseTimeVsPulseAmp[current_pmt]->Fill(-P_precal_negAdcPulseTime[i]+ *P_hod_starttime , P_precal_negAdcPulseAmp[i]);
    // }
    
    //*******Good Adc Tdc Diff Time for preshower Negative side **********************//
    // for (Int_t i = 0; i <*Ndata_P_precal_goodNegAdcTdcDiffTime; i++){
    //   //  cout << *Ndata_P_precal_goodNegAdcTdcDiffTime << endl;
    //   if (P_precal_goodNegAdcMult[i] == 1)
    // 	{
    // 	  //cout <<"electron cut: " << *P_cal_etottracknorm << endl;
	  
    // 	  h1PPRECALGoodNegAdcTdcDiffTime[i]->Fill(P_precal_goodNegAdcTdcDiffTime[i]);
    // 	  if(*P_cal_etottracknorm>0.8)
    // 	    {
    // 	      h1PPRECALGoodNegAdcTdcDiffTime_Cut[i]->Fill(P_precal_goodNegAdcTdcDiffTime[i]); 
    // 	      // cout << "hi"<<endl;
    // 	    }
    // 	}
    // }
    
    
    //This is for the Positive Side of the paddle *********************//
    
    // for (Int_t i = 0; i < *Ndata_P_precal_posAdcPulseTime; i++) {
    //   if (P_precal_posAdcErrorFlag[i] == 1) continue;
    //   //if (P_precal_posAdcCounter[i] < 1 || P_precal_posAdcCounter[i] > 14) continue;
    //   //if (P_precal_posAdcPulseTime[i] == 0) continue;
    //   Int_t current_pmt = P_precal_posAdcCounter[i] - 1;
    //   h1PPRECALPosPulseTime[current_pmt]->Fill(-P_precal_posAdcPulseTime[i]);
      
    //   h1PPRECALPosPulseTimeStarttimeDiff[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime); // all hits 
      
    //   if (P_precal_goodPosAdcMult[current_pmt] == 1) h1PPRECALPosPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime); // all hits with mult
      
    //   if(*P_cal_etottracknorm >0.8)
    // 	{
    // 	  h1PPRECALPosPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime);// all hits with elec
	  
    // 	  if (P_precal_goodPosAdcMult[current_pmt] == 1) 
    // 	    {
    // 	      h1PPRECALPosPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime);
    // 	      h1PPRECALPosPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime, P_precal_posAdcPulseAmp[i]); // 2d mult and elec
    // 	    }
    // 	}
    //   h1PPRECALPosPulseTimeVsPulseAmp[current_pmt]->Fill(-P_precal_posAdcPulseTime[i] + *P_hod_starttime, P_precal_posAdcPulseAmp[i]); // 2d all hits with 
    // }
    
    // //**************************GoodAdcTdc Diff time for positive side pmts **************************//
    // for (Int_t i = 0; i <*Ndata_P_precal_goodPosAdcTdcDiffTime; i++){
    //   if (P_precal_goodPosAdcMult[i] == 1)
    // 	{
    // 	  h1PPRECALGoodPosAdcTdcDiffTime[i]->Fill(P_precal_goodPosAdcTdcDiffTime[i]);
    // 	  if(*P_cal_etottracknorm >0.8){h1PPRECALGoodPosAdcTdcDiffTime_Cut[i]->Fill(P_precal_goodPosAdcTdcDiffTime[i]); }
    // 	}
    // }
    
    
    //***********************************Calorimeter***********************************//
    
    // for (Int_t i = 0; i < *Ndata_P_cal_adcPulseTime; i++) {
    //   if (P_cal_adcErrorFlag[i] == 1) continue;
    //   //if (P_cal_adcCounter[i] < 1 || P_cal_adcCounter[i] > 255) continue;
    //   //if (P_cal_adcPulseTime[i] == 0) continue;
    //   Int_t current_pmt = P_cal_adcCounter[i] - 1;
      
    //   h1PCALPulseTime[current_pmt]->Fill(-P_cal_adcPulseTime[i]);
      
    //   h1PCALPulseTimeStarttimeDiff[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime); // all hits 
      
    //   if(P_cal_goodAdcMult[current_pmt] ==1)h1PCALPulseTimeStarttimeDiffMult[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime); // all hits with mult
      
    //   // cout << "Adc Pulse Value: " <<  -P_cal_adcPulseTime[i] << endl;
      
    //   if(*P_cal_etottracknorm >0.8) 
    // 	{
    // 	  h1PCALPulseTimeStarttimeDiff_CalCut[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime);// all hits with electron 
	  
    // 	  //	cout << "Pulse vAlue after electron cut: "<< -P_cal_adcPulseTime[i] << endl;
	  
    // 	  if(P_cal_goodAdcMult[current_pmt] ==1)
    // 	    {
    // 	      // cout << "Adc Value after Multiciplity cut "<<  -P_cal_adcPulseTime[i] << endl;
	      
    // 	      h1PCALPulseTimeStarttimeDiffMultCut[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime);// all hits with mult and elec cuts
	      
    // 	      h1PCALPulseTimeVsPulseAmpMultCut[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime, P_cal_adcPulseAmp[i]); // 2d with mult and electron cuts
	      
    // 	      //cout << "adcPulse value After ALL********* cut "<< -P_cal_adcPulseTime[i] << endl;
    // 	    }
    // 	}
      
    //   h1PCALPulseTimeVsPulseAmp[current_pmt]->Fill(-P_cal_adcPulseTime[i] + *P_hod_starttime, P_cal_adcPulseAmp[i]); // 2d all hits 
    // }
    
    // // cout <<"*******  "<< h1PCALPulseTimeVsPulseAmpMultCut[1]->GetEntries()<<endl;
    
    // // cout << "other HIsto value : " << h1PCALPulseTimeStarttimeDiffMultCut[1]->GetEntries()<<endl;
    
    // for (Int_t i = 0; i<*Ndata_P_cal_goodAdcTdcTimeDiff; i++)
    //   {
    // 	if(P_cal_goodAdcMult[i] ==1)
    // 	  {
    // 	    h1PCALGoodAdcTdcDiffTime[i]->Fill(P_cal_goodAdcTdcTimeDiff[i]);
    // 	    if (*P_cal_etottracknorm >0.8){h1PCALGoodAdcTdcDiffTime_Cut[i]->Fill(P_cal_goodAdcTdcTimeDiff[i]);}
    // 	  }
    //   }
    
    
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
  
  // TH1F* PHGCPULSETIME[4];
  // TH1F* PHGCPULSETIMEDIFF[4];
  // TH1F* PHGCPULSETIMEDIFFCUT[4];
  // for (Int_t ipmt = 0; ipmt < 4; ipmt++) {
  //   PHGCPULSETIME[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHGCERPulseTime%d",ipmt+1)));
  //   PHGCPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHGCERPulseTimeStarttimeDiff%d",ipmt+1)));
  //   //PHGCPULSETIMEDIFFCUT[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHGCERPulseTimeStarttimeDiffCut%d",ipmt+1)));
  // }

  // TH1F* PNGCPULSETIME[4];
  // TH1F* PNGCPULSETIMEDIFF[4];
  // for (Int_t ipmt = 0; ipmt < 4; ipmt++) {
  //   PNGCPULSETIME[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PNGCERPulseTime%d",ipmt+1)));
  //   PNGCPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PNGCERPulseTimeStarttimeDiff%d",ipmt+1)));
  // }
  
 
  // TH1F* PPRECALNEGPULSETIME[14];
  // TH1F* PPRECALNEGPULSETIMEDIFF[14];
  // TH1F* PPRECALPOSPULSETIME[14];
  // TH1F* PPRECALPOSPULSETIMEDIFF[14];
  // for (Int_t ipmt = 0; ipmt < 14; ipmt++) {
  //   PPRECALNEGPULSETIME[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PPRECALNegPulseTime%d",ipmt+1)));
  //   PPRECALNEGPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PPRECALNegPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PPRECALPOSPULSETIME[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PPRECALPosPulseTime%d",ipmt+1)));
  //   PPRECALPOSPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PPRECALPosPulseTimeStarttimeDiff%d",ipmt+1)));
  // }
  
  // TH1F* PCALPULSETIMEDIFF[224];
  // for (Int_t ipmt = 0; ipmt < 224; ipmt++) {
  //   PCALPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PCALPulseTimeStarttimeDiff%d",ipmt+1)));
  // }

 

  // TH1F* PHODO1xNEGPULSETIMEDIFF[18];
  // TH1F* PHODO1xPOSPULSETIMEDIFF[18];
  // TH1F* PHODO1yNEGPULSETIMEDIFF[18];
  // TH1F* PHODO1yPOSPULSETIMEDIFF[18];
  // TH1F* PHODO2xNEGPULSETIMEDIFF[18];
  // TH1F* PHODO2xPOSPULSETIMEDIFF[18];
  // TH1F* PHODO2yNEGPULSETIMEDIFF[18];
  // TH1F* PHODO2yPOSPULSETIMEDIFF[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   PHODO1xNEGPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO1xNegPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO1xPOSPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO1xPosPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO1yNEGPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO1yNegPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO1yPOSPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO1yPosPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO2xNEGPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO2xNegPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO2xPOSPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO2xPosPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO2yNEGPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO2yNegPulseTimeStarttimeDiff%d",ipmt+1)));
  //   PHODO2yPOSPULSETIMEDIFF[ipmt] = dynamic_cast<TH1F*> (GetOutputList()->FindObject(Form("PHODO2yPosPulseTimeStarttimeDiff%d",ipmt+1)));
  // }
  

  //Begin peak Finding
  gSystem->RedirectOutput("/dev/null","a");
  // Double_t HGC_Window[4];
  // for (Int_t ipmt = 0; ipmt < 4; ipmt++) {
  //   if (PHGCPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHGCPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHGCPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HGC_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     HGC_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t NGC_Window[4];
  // for (Int_t ipmt = 0; ipmt < 4; ipmt++) {
  //   if (PNGCPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PNGCPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PNGCPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     NGC_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     NGC_Window[ipmt] = 1e+38;
  //   }
  // }
 
  // Double_t PRECALNEG_Window[14];
  // for (Int_t ipmt = 0; ipmt < 14; ipmt++) {
  //   if (PPRECALNEGPULSETIMEDIFF[ipmt]->GetEntries() !=0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PPRECALNEGPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PPRECALNEGPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     PRECALNEG_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     PRECALNEG_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t PRECALPOS_Window[14];
  // for (Int_t ipmt = 0; ipmt < 14; ipmt++) {
  //   if (PPRECALPOSPULSETIMEDIFF[ipmt]->GetEntries() !=0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PPRECALPOSPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PPRECALPOSPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     PRECALPOS_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     PRECALPOS_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t CAL_Window[224];
  // for (Int_t ipmt = 0; ipmt < 224; ipmt++) {
  //   if (PCALPULSETIMEDIFF[ipmt]->GetEntries() < 50) {
  //     cout << PCALPULSETIMEDIFF[ipmt]->GetEntries() << endl;
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PCALPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PCALPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     if (pm) {
  // 	CAL_Window[ipmt] = *pm->GetX();
  //     }
  //     else CAL_Window[ipmt] = 1e+38;
  //   }
  //   else {
  //     CAL_Window[ipmt] = 1e+38;
  //   }
  // }
  
  // Double_t DC_Window[12];
  // for (Int_t ipmt = 0; ipmt < 12; ipmt++) {
  //   if (PDCRAWTDC[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PDCRAWTDC[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PDCRAWTDC[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     DC_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     DC_Window[ipmt] = 1e+38;
  //   }
  // }
  
  // Double_t HODO1xNeg_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 13 || PHODO1xNEGPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO1xNEGPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO1xNEGPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     // TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     // HODO1xNeg_Window[ipmt] = *pm->GetX();
  //   } else {
  //     HODO1xNeg_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO1xPos_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 13 || PHODO1xPOSPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO1xPOSPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO1xPOSPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO1xPos_Window[ipmt] = *pm->GetX();
  //   } else {
  //     HODO1xPos_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO1yNeg_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 13 || PHODO1yNEGPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO1yNEGPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO1yNEGPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO1yNeg_Window[ipmt] = *pm->GetX();
  //   } else {
  //     HODO1yNeg_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO1yPos_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 13 || PHODO1yPOSPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO1yPOSPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO1yPOSPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO1yPos_Window[ipmt] = *pm->GetX();
  //   } else {
  //     HODO1yPos_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO2xNeg_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 14 || PHODO2xNEGPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO2xNEGPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO2xNEGPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO2xNeg_Window[ipmt] = *pm->GetX();
  //   }    
  //   else {
  //     HODO2xNeg_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO2xPos_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (ipmt < 14 || PHODO2xPOSPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO2xPOSPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO2xPOSPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO2xPos_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     HODO2xPos_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO2yNeg_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (PHODO2yNEGPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO2yNEGPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO2yNEGPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO2yNeg_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     HODO2yNeg_Window[ipmt] = 1e+38;
  //   }
  // }

  // Double_t HODO2yPos_Window[18];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   if (PHODO2yPOSPULSETIMEDIFF[ipmt]->GetEntries() != 0) {
  //     TSpectrum *s = new TSpectrum(1);
  //     s->Search(PHODO2yPOSPULSETIMEDIFF[ipmt], 1.0, "nobackground&&nodraw", 0.001);
  //     TList *functions = PHODO2yPOSPULSETIMEDIFF[ipmt]->GetListOfFunctions();
  //     TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
  //     HODO2yPos_Window[ipmt] = *pm->GetX();
  //   }
  //   else {
  //     HODO2yPos_Window[ipmt] = 1e+38;
  //   }
  // }
  gSystem->RedirectOutput(0);

  //Begin Calculation of Window Values
  // Int_t AeroPosMin = TMath::Mean(7,AEROPOS_Window) - 35;
  // Int_t AeroPosMax = TMath::Mean(7,AEROPOS_Window) + 20;
  // Int_t AeroNegMin = TMath::Mean(7,AERONEG_Window) - 35;
  // Int_t AeroNegMax = TMath::Mean(7,AERONEG_Window) + 20;

  // Int_t HGCMinPMT1 = HGC_Window[0] - 10; Int_t HGCMaxPMT1 = HGC_Window[0] + 10;
  // Int_t HGCMinPMT2 = HGC_Window[1] - 10; Int_t HGCMaxPMT2 = HGC_Window[1] + 10;
  // Int_t HGCMinPMT3 = HGC_Window[2] - 10; Int_t HGCMaxPMT3 = HGC_Window[2] + 10;
  // Int_t HGCMinPMT4 = HGC_Window[3] - 10; Int_t HGCMaxPMT4 = HGC_Window[3] + 10;

  // Int_t NGCMinPMT1 = NGC_Window[0] - 10; Int_t NGCMaxPMT1 = NGC_Window[0] + 10;
  // Int_t NGCMinPMT2 = NGC_Window[1] - 10; Int_t NGCMaxPMT2 = NGC_Window[1] + 10;
  // Int_t NGCMinPMT3 = NGC_Window[2] - 10; Int_t NGCMaxPMT3 = NGC_Window[2] + 10;
  // Int_t NGCMinPMT4 = NGC_Window[3] - 10; Int_t NGCMaxPMT4 = NGC_Window[3] + 10;
  
  // Int_t HODOPosMin[72]; Int_t HODOPosMax[72];
  // Int_t HODONegMin[72]; Int_t HODONegMax[72];
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {  
  //   (HODO1xPos_Window[ipmt] == 1e+38) ? HODOPosMin[4*ipmt]    = -200 : HODOPosMin[4*ipmt]    = HODO1xPos_Window[ipmt] - 10;
  //   (HODO1yPos_Window[ipmt] == 1e+38) ? HODOPosMin[4*ipmt+1]  = -200 : HODOPosMin[4*ipmt+1]  = HODO1yPos_Window[ipmt] - 20;
  //   (HODO2xPos_Window[ipmt] == 1e+38) ? HODOPosMin[4*ipmt+2]  = -200 : HODOPosMin[4*ipmt+2]  = HODO2xPos_Window[ipmt] - 10;
  //   (HODO2yPos_Window[ipmt] == 1e+38) ? HODOPosMin[4*ipmt+3]  = -200 : HODOPosMin[4*ipmt+3]  = HODO2yPos_Window[ipmt] - 20;
  //   (HODO1xNeg_Window[ipmt] == 1e+38) ? HODONegMin[4*ipmt]    = -200 : HODONegMin[4*ipmt]    = HODO1xNeg_Window[ipmt] - 10;
  //   (HODO1yNeg_Window[ipmt] == 1e+38) ? HODONegMin[4*ipmt+1]  = -200 : HODONegMin[4*ipmt+1]  = HODO1yNeg_Window[ipmt] - 20;
  //   (HODO2xNeg_Window[ipmt] == 1e+38) ? HODONegMin[4*ipmt+2]  = -200 : HODONegMin[4*ipmt+2]  = HODO2xNeg_Window[ipmt] - 10;
  //   (HODO2yNeg_Window[ipmt] == 1e+38) ? HODONegMin[4*ipmt+3]  = -200 : HODONegMin[4*ipmt+3]  = HODO2yNeg_Window[ipmt] - 20;
  //   (HODO1xPos_Window[ipmt] == 1e+38) ? HODOPosMax[4*ipmt]    = 200 : HODOPosMax[4*ipmt]    = HODO1xPos_Window[ipmt] + 10;
  //   (HODO1yPos_Window[ipmt] == 1e+38) ? HODOPosMax[4*ipmt+1]  = 200 : HODOPosMax[4*ipmt+1]  = HODO1yPos_Window[ipmt] + 20;
  //   (HODO2xPos_Window[ipmt] == 1e+38) ? HODOPosMax[4*ipmt+2]  = 200 : HODOPosMax[4*ipmt+2]  = HODO2xPos_Window[ipmt] + 10;
  //   (HODO2yPos_Window[ipmt] == 1e+38) ? HODOPosMax[4*ipmt+3]  = 200 : HODOPosMax[4*ipmt+3]  = HODO2yPos_Window[ipmt] + 20;
  //   (HODO1xNeg_Window[ipmt] == 1e+38) ? HODONegMax[4*ipmt]    = 200 : HODONegMax[4*ipmt]    = HODO1xNeg_Window[ipmt] + 10;
  //   (HODO1yNeg_Window[ipmt] == 1e+38) ? HODONegMax[4*ipmt+1]  = 200 : HODONegMax[4*ipmt+1]  = HODO1yNeg_Window[ipmt] + 20;
  //   (HODO2xNeg_Window[ipmt] == 1e+38) ? HODONegMax[4*ipmt+2]  = 200 : HODONegMax[4*ipmt+2]  = HODO2xNeg_Window[ipmt] + 10;
  //   (HODO2yNeg_Window[ipmt] == 1e+38) ? HODONegMax[4*ipmt+3]  = 200 : HODONegMax[4*ipmt+3]  = HODO2yNeg_Window[ipmt] + 20;
  // }

  // Int_t PRECALPosMin[14]; Int_t PRECALPosMax[14];
  // Int_t PRECALNegMin[14]; Int_t PRECALNegMax[14];
  // for (Int_t ipmt = 0; ipmt < 14; ipmt++) {  
  //   (PRECALPOS_Window[ipmt] == 1e+38) ? PRECALPosMin[ipmt] = -200 : PRECALPosMin[ipmt] = PRECALPOS_Window[ipmt] - 10;
  //   (PRECALNEG_Window[ipmt] == 1e+38) ? PRECALNegMin[ipmt] = -200 : PRECALNegMin[ipmt] = PRECALNEG_Window[ipmt] - 10;
  //   (PRECALPOS_Window[ipmt] == 1e+38) ? PRECALPosMax[ipmt] = 200 : PRECALPosMax[ipmt] = PRECALPOS_Window[ipmt] + 10;
  //   (PRECALNEG_Window[ipmt] == 1e+38) ? PRECALNegMax[ipmt] = 200 : PRECALNegMax[ipmt] = PRECALNEG_Window[ipmt] + 10;
  // }

  // Int_t CALMin[224]; Int_t CALMax[224];
  // for (Int_t ipmt = 0; ipmt < 224; ipmt++) {
  //   (CAL_Window[ipmt] == 1e+38) ? CALMin[ipmt] = -200 : CALMin[ipmt] = CAL_Window[ipmt] - 10;
  //   (CAL_Window[ipmt] == 1e+38) ? CALMax[ipmt] = 200 : CALMax[ipmt] = CAL_Window[ipmt] + 10;
  // }

  // Int_t DCMin[12]; Int_t DCMax[12];
  // for (Int_t ipmt = 0; ipmt < 12; ipmt++) {
  //   (DC_Window[ipmt] == 1e+38) ? DCMin[ipmt] = -13000 : DCMin[ipmt] = DC_Window[ipmt] - 2000;
  //   (DC_Window[ipmt] == 1e+38) ? DCMax[ipmt] = -10000 : DCMax[ipmt] = DC_Window[ipmt] + 2000;
  // }
  
  //Begin Plotting Results 
  /*
    TCanvas *HGC = new TCanvas("HGC","ADC Timing Window for SHMS HGC");
    HGC->Divide(2,2); 
    for (Int_t ipmt = 0; ipmt < 4; ipmt++) {
    HGC->cd(ipmt); PHGCPULSETIMEDIFF[ipmt]->Draw(); PHGCPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.1); PHGCPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHGCPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    }

    TCanvas *AERO = new TCanvas("AERO","ADC Timing Window for SHMS AERO");
    AERO->Divide(2,7);
    for (Int_t ipmt = 0; ipmt < 7; ipmt++) {
    AERO->cd(2*ipmt+1); PAERONEGPULSETIMEDIFF[ipmt]->Draw(); PAERONEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PAERONEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PAERONEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    AERO->cd(2*ipmt+2); PAEROPOSPULSETIMEDIFF[ipmt]->Draw(); PAEROPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PAEROPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PAEROPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    }

    TCanvas *PRECAL = new TCanvas("PRECAL","ADC Timing Window for SHMS PRECAL");
    PRECAL->Divide(2,14);
    for (Int_t ipmt = 0; ipmt < 14; ipmt++) {
    PRECAL->cd(2*ipmt+1); PPRECALNEGPULSETIMEDIFF[ipmt]->Draw(); PPRECALNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PPRECALNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PPRECALNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    PRECAL->cd(2*ipmt+2); PPRECALPOSPULSETIMEDIFF[ipmt]->Draw(); PPRECALPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PPRECALPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PPRECALPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    }

    TCanvas *CAL = new TCanvas("CAL","ADC Timing Window for SHMS CAL");
    CAL->Divide(14,16);
    for (Int_t ipmt = 0; ipmt < 224; ipmt++) {
    CAL->cd(ipmt+1); PCALPULSETIMEDIFF[ipmt]->Draw();
    }
  
    TCanvas *DC = new TCanvas("DC","ADC Timing Window for SHMS DC");
    DC->Divide(2,6);
    for (Int_t ipmt = 0; ipmt < 6; ipmt++) {
    DC->cd(2*ipmt+1); PDCRAWTDC[2*ipmt]->Draw();
    DC->cd(2*ipmt+2); PDCRAWTDC[2*ipmt+1]->Draw();
    }

    TCanvas *HODONEG = new TCanvas("HODONEG","ADC Timing Window for SHMS NEG HODO");
    HODONEG->Divide(4,18);
    for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
    HODONEG->cd(4*ipmt+1); PHODO1xNEGPULSETIMEDIFF[ipmt]->Draw(); PHODO1xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO1xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO1xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODONEG->cd(4*ipmt+2); PHODO1yNEGPULSETIMEDIFF[ipmt]->Draw(); PHODO1yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO1yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO1yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODONEG->cd(4*ipmt+3); PHODO2xNEGPULSETIMEDIFF[ipmt]->Draw(); PHODO2xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO2xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO2xNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODONEG->cd(4*ipmt+4); PHODO2yNEGPULSETIMEDIFF[ipmt]->Draw();PHODO2yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO2yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO2yNEGPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    }

    TCanvas *HODOPOS = new TCanvas("HODOPOS","ADC Timing Window for SHMS POS HODO");
    HODOPOS->Divide(4,18);
    for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
    HODOPOS->cd(4*ipmt+1); PHODO1xPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO1xPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO1xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO1xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO1xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODOPOS->cd(4*ipmt+2); PHODO1yPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO1yPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO1yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO1yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO1yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODOPOS->cd(4*ipmt+3); PHODO2xPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO2xPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO2xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO2xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO2xPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    HODOPOS->cd(4*ipmt+4); PHODO2yPOSPULSETIMEDIFF[ipmt]->Draw(); PHODO2yPOSPULSETIMEDIFF[ipmt]->Draw();PHODO2yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetLabelSize(0.12); PHODO2yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleOffset(-1.0); PHODO2yPOSPULSETIMEDIFF[ipmt]->GetXaxis()->SetTitleSize(0.1);
    }
  */
  //Output Adc Time Window Values into an ascii file
  TString option = GetOption();
  // ofstream SHMSWindows;
  // SHMSWindows.open("SHMSADCTimingWindows.dat", fstream::trunc);
  // SHMSWindows << Form(";Values obtained from Run %s",option.Data()) << endl;
  // // SHMSWindows << Form("paero_adcPosTimeWindowMin = %d\npaero_adcPosTimeWindowMax = %d\npaero_adcNegTimeWindowMin = %d\npaero_adcNegTimeWindowMax = %d\n",AeroPosMin,AeroPosMax,AeroNegMin,AeroNegMax) <<  endl;
  // SHMSWindows << Form(";Values obtained from Run %s",option.Data()) << endl;
  // SHMSWindows << Form("phgcer_adcTimeWindowMin = %d, %d, %d, %d\nphgcer_adcTimeWindowMax = %d, %d, %d, %d\n",HGCMinPMT1,HGCMinPMT2,HGCMinPMT3,HGCMinPMT4,HGCMaxPMT1,HGCMaxPMT2,HGCMaxPMT3,HGCMaxPMT4) << endl;
  // SHMSWindows << Form(";Values obtained from Run %s",option.Data()) << endl;
  // //SHMSWindows << Form("pngcer_adcTimeWindowMin = %d, %d, %d, %d\npngcer_adcTimeWindowMax = %d, %d, %d, %d\n",NGCMinPMT1,NGCMinPMT2,NGCMinPMT3,NGCMinPMT4,NGCMaxPMT1,NGCMaxPMT2,NGCMaxPMT3,NGCMaxPMT4) << endl;
  // SHMSWindows << Form(";Values obtained from Run %s\nphodo_PosAdcTimeWindowMin =",option.Data());
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   SHMSWindows << Form(" %d, %d, %d, %d\n",HODOPosMin[4*ipmt],HODOPosMin[4*ipmt+1],HODOPosMin[4*ipmt+2],HODOPosMin[4*ipmt+3]);
  // }
  // SHMSWindows << "\nphodo_PosAdcTimeWindowMax =";
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   SHMSWindows << Form(" %d, %d, %d, %d\n",HODOPosMax[4*ipmt],HODOPosMax[4*ipmt+1],HODOPosMax[4*ipmt+2],HODOPosMax[4*ipmt+3]);
  // }
  // SHMSWindows << "\nphodo_NegAdcTimeWindowMin =";
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   SHMSWindows << Form(" %d, %d, %d, %d\n",HODONegMin[4*ipmt],HODONegMin[4*ipmt+1],HODONegMin[4*ipmt+2],HODONegMin[4*ipmt+3]);
  // }
  // SHMSWindows << "\nphodo_NegAdcTimeWindowMax =";
  // for (Int_t ipmt = 0; ipmt < 18; ipmt++) {
  //   SHMSWindows << Form(" %d, %d, %d, %d\n",HODONegMax[4*ipmt],HODONegMax[4*ipmt+1],HODONegMax[4*ipmt+2],HODONegMax[4*ipmt+3]);
  // }
  // SHMSWindows << Form("\n;Values obtained from Run %s",option.Data()) << endl;
  // SHMSWindows << Form("pcal_pos_AdcTimeWindowMin = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",PRECALPosMin[0],PRECALPosMin[1],PRECALPosMin[2],PRECALPosMin[3],PRECALPosMin[4],PRECALPosMin[5],PRECALPosMin[6],PRECALPosMin[7],PRECALPosMin[8],PRECALPosMin[9],PRECALPosMin[10],PRECALPosMin[11],PRECALPosMin[12],PRECALPosMin[13]) << endl;
  // SHMSWindows << Form("\npcal_neg_AdcTimeWindowMin = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",PRECALNegMin[0],PRECALNegMin[1],PRECALNegMin[2],PRECALNegMin[3],PRECALNegMin[4],PRECALNegMin[5],PRECALNegMin[6],PRECALNegMin[7],PRECALNegMin[8],PRECALNegMin[9],PRECALNegMin[10],PRECALNegMin[11],PRECALNegMin[12],PRECALNegMin[13]) << endl;
  // SHMSWindows << Form("\npcal_pos_AdcTimeWindowMax = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",PRECALPosMax[0],PRECALPosMax[1],PRECALPosMax[2],PRECALPosMax[3],PRECALPosMax[4],PRECALPosMax[5],PRECALPosMax[6],PRECALPosMax[7],PRECALPosMax[8],PRECALPosMax[9],PRECALPosMax[10],PRECALPosMax[11],PRECALPosMax[12],PRECALPosMax[13]) << endl;
  // SHMSWindows << Form("\npcal_neg_AdcTimeWindowMax = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",PRECALNegMax[0],PRECALNegMax[1],PRECALNegMax[2],PRECALNegMax[3],PRECALNegMax[4],PRECALNegMax[5],PRECALNegMax[6],PRECALNegMax[7],PRECALNegMax[8],PRECALNegMax[9],PRECALNegMax[10],PRECALNegMax[11],PRECALNegMax[12],PRECALNegMax[13]) << endl;
  // SHMSWindows << Form("\n;Values obtained from Run %s",option.Data()) << endl;
  // SHMSWindows << "pcal_arr_AdcTimeWindowMin = ";
  // for (Int_t ipmt = 0; ipmt < 16; ipmt++) {
  //   SHMSWindows << Form("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt],CALMin[14*ipmt]) << endl;
  // }
  // SHMSWindows << "\npcal_arr_AdcTimeWindowMax = ";
  // for (Int_t ipmt = 0; ipmt < 16; ipmt++) {
  //   SHMSWindows << Form("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt],CALMax[14*ipmt]) << endl;
  // }

  // SHMSWindows << Form("\n;Values obtained from Run %s\nptdc_win_min =  ",option.Data());
  // // for (Int_t iplane = 0; iplane < 2; iplane++) {
  // //   SHMSWindows << Form("%d, %d, %d, %d, %d, %d\n",DCMin[6*iplane],DCMin[6*iplane+1],DCMin[6*iplane+2],DCMin[6*iplane+3],DCMin[6*iplane+4],DCMin[6*iplane+5]);
  // // }
  // // SHMSWindows << "ptdc_win_max =  ";
  // // for (Int_t iplane = 0; iplane < 2; iplane++) {
  // //   SHMSWindows << Form("%d, %d, %d, %d, %d, %d\n",DCMax[6*iplane],DCMax[6*iplane+1],DCMax[6*iplane+2],DCMax[6*iplane+3],DCMax[6*iplane+4],DCMax[6*iplane+5]);
  // // }
  // SHMSWindows.close();

  //Start output of .root file with all histograms
  // TFile *Histogram_file = new TFile(Form("HISTOGRAMS/SHMSADCGates_Run%i.root",option.Atoi()),"RECREATE");
  // TDirectory *DHGC = Histogram_file->mkdir("Heavy Gas Cherenkov ADC Timing Spectra"); DHGC->cd();
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
    legend[ipmtt]->SetHeader("tight cut","C");
 
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
    
    //h1PHGCERPulseTimeStarttimeDiff[ipmt]->GetYaxis()->SetTitleOffset(1.5);
    // PHGCPULSETIMEDIFFCUT[ipmt]->Draw("same");
    // PHGCPULSETIMEDIFFCUT[ipmt]->SetLineColor(kRed);


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
    legend[ipmtt]->SetHeader("tight cut","C");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime[ipmt],"hit selection by hcana (good)", "l");
    legend[ipmtt]->AddEntry(h1PHGCERPGoodAdcTdcDiffTime_Mult[ipmt],"good with mult == 1", "l");
    legend[ipmtt]->AddEntry( h1goodTimeCal[ipmt],"good with Cal","l");
    legend[ipmtt]->AddEntry( h1goodTimeMultCal[ipmt],"good with cal & mult","l"); 
    legend[ipmtt]->Draw();
    // delete legend[ipmtt];
    
    c1->SaveAs(Form("tight_HGCER_pmt_%i.pdf", ipmt+1));
    
    delete c1;
    for(int ii=0;ii<8;ii++)
    delete legend[ii];
    //delete [] legend;
  }

 
  // TDirectory *DNGC = Histogram_file->mkdir("Noble Gas Cherenkov ADC Timing Spectra"); DNGC->cd();

  //******************* NGCER CAnvas************************************//

  // TCanvas *c2 = new TCanvas("c2", "NGCER" , 600, 600);
  // c2->Divide(2,2);
  // for (Int_t ipmt=0; ipmt < 4; ipmt++) {
   
  // c2->cd(1);
  // h1PNGCERPulseTimeStarttimeDiff[ipmt]->Draw();gPad->SetLogy();
  // h1PNGCERPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
  // h1PNGCERPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);
  // h1PNGCERPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
  // h1PNGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kMagenta);
  // h1PNGCERPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
  // h1PNGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed+4);

  // c2->cd(2);
  // h1PNGCERPulseTimeVsPulseAmp[ipmt]->Draw("colz"); gPad->SetLogz(1);

  // c2->cd(4);
  // //h1PNGCERPulseTime[ipmt]->Draw();
  // h1PNGCERPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);
  // c2->cd(3);gPad->SetLogy();
  // h1PNGCERPGoodAdcTdcDiffTime[ipmt]->Draw();
  // h1PNGCERPGoodAdcTdcDiffTime_Mult[ipmt]->Draw("same");
  // h1PNGCERPGoodAdcTdcDiffTime_Mult[ipmt]->SetLineColor(kRed);
  // h1PNGCERPGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("Time[ns]");
  // h1PNGCERPGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("counts");
  // h1PNGCERPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
  // h1PNGCERPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kMagenta);
  // h1PNGCERPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
  // h1PNGCERPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed+4);

  // c2->SaveAs(Form("./NGC_PMT_%i.pdf",ipmt+1));
  // }
  
  

  // // TDirectory *DPRECAL = Histogram_file->mkdir("Pre-Shower ADC Timing Spectra"); DPRECAL->cd();

  // //***************************************Preshower ***************************//
  // for (Int_t ipmt=0; ipmt < 14; ipmt++) {
  //   TCanvas *c3 = new TCanvas("c3", "AdcTdcNeg" , 600, 600);
  //   c3->Divide(2,2);//negative
  //   c3->cd(1);gPad->SetLogy();
  //   h1PPRECALNegPulseTimeStarttimeDiff[ipmt]->Draw();
  //   h1PPRECALNegPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
  //   h1PPRECALNegPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);
  //   h1PPRECALNegPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
  //   h1PPRECALNegPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kMagenta);
  //   h1PPRECALNegPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
  //   h1PPRECALNegPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed+4);

  //   c3->cd(2);
  //   h1PPRECALNegPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);

  //   c3->cd(4);
  //   h1PPRECALNegPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);

  //   c3->cd(3);gPad->SetLogy();

  //   h1PPRECALGoodNegAdcTdcDiffTime[ipmt]->Draw();
  //   h1PPRECALGoodNegAdcTdcDiffTime_Cut[ipmt]->Draw("same");
  //   h1PPRECALGoodNegAdcTdcDiffTime_Cut[ipmt]->SetLineColor(kRed);
  //   h1PPRECALGoodNegAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("Time[ns]");
  //   h1PPRECALGoodNegAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("counts");
  //   c3->SaveAs(Form("./PRECAL_NEG_PMT_%i.pdf",ipmt+1));

  //   TCanvas *c4 = new TCanvas("c4", "AdcTdcPos" , 600, 600);// positive 
  //   c4->Divide(2,2);
  //   c4->cd(1);gPad->SetLogy();
  //   h1PPRECALPosPulseTimeStarttimeDiff[ipmt]->Draw();
  //   h1PPRECALPosPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
  //   h1PPRECALPosPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);
  //   h1PPRECALPosPulseTimeStarttimeDiffMult[ipmt]->Draw("same"); 
  //   h1PPRECALPosPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kMagenta);
  //   h1PPRECALPosPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same"); 
  //   h1PPRECALPosPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed+4);


  //   c4->cd(2);
  //   h1PPRECALPosPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);

  //   c4->cd(4);
  //   h1PPRECALPosPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);

  //   c4->cd(3);gPad->SetLogy();
  //   h1PPRECALGoodPosAdcTdcDiffTime[ipmt]->Draw();
  //   h1PPRECALGoodPosAdcTdcDiffTime_Cut[ipmt]->Draw("same");
  //   h1PPRECALGoodPosAdcTdcDiffTime_Cut[ipmt]->SetLineColor(kRed);
  //   h1PPRECALGoodPosAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("Time[ns]");
  //   h1PPRECALGoodPosAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("counts");
  //   c4->SaveAs(Form("./PRECAL_POS_PMT_%i.pdf",ipmt+1));
  // }

  // // TDirectory *DCAL = Histogram_file->mkdir("Calorimeter ADC Timing Spectra"); DCAL->cd();

  // //****************************CanVas for Shower ****************************//
  // for (Int_t ipmt=0; ipmt < 224; ipmt++) {
  //   TCanvas *c5 = new TCanvas("c5", "Cal_FlyEye" , 600, 600);c5->Divide(2,2);
  //   c5->cd(1);gPad->SetLogy();
  //   // PCALPULSETIMEDIFF[ipmt]->Draw();
  //   h1PCALPulseTimeStarttimeDiff[ipmt]->Draw();
  //   h1PCALPulseTimeStarttimeDiff_CalCut[ipmt]->Draw("same");
  //   h1PCALPulseTimeStarttimeDiff_CalCut[ipmt]->SetLineColor(kRed);
  //   h1PCALPulseTimeStarttimeDiffMult[ipmt]->Draw("same");
  //   h1PCALPulseTimeStarttimeDiffMult[ipmt]->SetLineColor(kMagenta);
  //   h1PCALPulseTimeStarttimeDiffMultCut[ipmt]->Draw("same");
  //   h1PCALPulseTimeStarttimeDiffMultCut[ipmt]->SetLineColor(kRed+4);
    

  //   c5->cd(2);
  //   h1PCALPulseTimeVsPulseAmp[ipmt]->Draw("colz");gPad->SetLogz(1);


  //   c5->cd(4);
  //   h1PCALPulseTimeVsPulseAmpMultCut[ipmt]->Draw("colz");gPad->SetLogz(1);


  //   c5->cd(3);gPad->SetLogy();
  //   h1PCALGoodAdcTdcDiffTime[ipmt]->Draw();
  //   h1PCALGoodAdcTdcDiffTime_Cut[ipmt]->Draw("same");
  //   h1PCALGoodAdcTdcDiffTime_Cut[ipmt]->SetLineColor(kRed);
  //   h1PCALGoodAdcTdcDiffTime[ipmt]->GetXaxis()->SetTitle("Time[ns]");
  //   h1PCALGoodAdcTdcDiffTime[ipmt]->GetYaxis()->SetTitle("counts");
  //   c5->SaveAs(Form("CAL_PMT_%i.pdf",ipmt+1));
  // }

  // //  TDirectory *DHODO = Histogram_file->mkdir("Hodoscope ADC Timing Spectra"); DHODO->cd();
  // // for (Int_t ipmt=0; ipmt < 18; ipmt++) {
  // //   PHODO1xNEGPULSETIMEDIFF[ipmt]->Write(Form("HODO 1x NEG PMT %i",ipmt+1));
  // //   PHODO1yNEGPULSETIMEDIFF[ipmt]->Write(Form("HODO 1y NEG PMT %i",ipmt+1));
  // //   PHODO2xNEGPULSETIMEDIFF[ipmt]->Write(Form("HODO 2x NEG PMT %i",ipmt+1));
  // //   PHODO2yNEGPULSETIMEDIFF[ipmt]->Write(Form("HODO 2y NEG PMT %i",ipmt+1));
  // //   PHODO1xPOSPULSETIMEDIFF[ipmt]->Write(Form("HODO 1x POS PMT %i",ipmt+1));
  // //   PHODO1yPOSPULSETIMEDIFF[ipmt]->Write(Form("HODO 1y POS PMT %i",ipmt+1));
  // //   PHODO2xPOSPULSETIMEDIFF[ipmt]->Write(Form("HODO 2x POS PMT %i",ipmt+1));
  // //   PHODO2yPOSPULSETIMEDIFF[ipmt]->Write(Form("HODO 2y POS PMT %i",ipmt+1));
  // // }

  // // TDirectory *DDC = Histogram_file->mkdir("Drift Chamber ADC Timing Spectra"); DDC->cd();
  // // for (Int_t iplane = 0; iplane < 2; iplane++) {
  // //   PDCRAWTDC[6*iplane]->Write(Form("DC %du1 Plane",iplane+1));
  // //   PDCRAWTDC[6*iplane+1]->Write(Form("DC %dv1 Plane",iplane+1));
  // //   PDCRAWTDC[6*iplane+2]->Write(Form("DC %dx1 Plane",iplane+1));
  // //   PDCRAWTDC[6*iplane+3]->Write(Form("DC %du2 Plane",iplane+1));
  // //   PDCRAWTDC[6*iplane+4]->Write(Form("DC %dv2 Plane",iplane+1));
  // //   PDCRAWTDC[6*iplane+5]->Write(Form("DC %dx2 Plane",iplane+1));
  // // }

  // Histogram_file->Close();
}                  
