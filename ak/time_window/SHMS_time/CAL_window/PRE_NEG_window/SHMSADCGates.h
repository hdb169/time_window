//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 13 11:12:03 2018 by ROOT version 6.10/02
// from TTree T/Hall A Analyzer Output DST
// found on file: ../../ROOTfiles/coin_replay_production_3423_-1.root
//////////////////////////////////////////////////////////

#ifndef SHMSADCGates_h
#define SHMSADCGates_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class SHMSADCGates : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Declaration of histograms
    //*********** no hit selection *************************//

   TH1F          **h1PHGCERPulseTime;
   TH1F          **h1PHGCERPulseTimeStarttimeDiff; // no hit selection AdcTdc 
   TH1F          **h1PHGCERPulseTimeStarttimeDiffMult; // no hit selction with mult Cut
   TH1F          **h1PHGCERPulseTimeStarttimeDiffMultCut; // no hit selection with mult and cal
   TH1F          **h1_delta; // no hit selction with delta cut 
   TH1F          **h1PHGCERPulseTimeStarttimeDiff_CalCut; // no hit selection with Calorimeter cut

   //******//********//*********Amplitude plot*********//**************//*********//

   TH2F          **h1PHGCERPulseTimeVsPulseAmp;
   TH2F          **h1TimeVsAmpMult;
   TH2F          **h1TimeVsAmpCal;
   TH2F          **h1TimeVsAmpMultCal;

   //*********************************Hit Selection *******************************//
   TH1F          **h1PHGCERPGoodAdcTdcDiffTime;
   TH1F          **h1_gooddelta;
   TH1F          **h1PHGCERPGoodAdcTdcDiffTime_Mult;
   TH1F          **h1goodTimeCal;
   TH1F          **h1goodTimeMultCal;

   //**********************************Amplitude plot *************************//

   TH2F          **h1PHGCERPulseTimeVsPulseAmpMultCut;
   TH2F          **h1goodTimeVsAmpMult;


   // Readers to access the data (delete the ones you do not need).

   TTreeReaderValue<Double_t> P_cal_etottracknorm = {fReader, "P.cal.etottracknorm"};
   TTreeReaderValue<Double_t> P_ngcer_npeSum = {fReader, "P.ngcer.npeSum"};
   TTreeReaderValue<Double_t> P_gtr_dp = {fReader, "P.gtr.dp"};


   //***************************** HGCER *************************************//

   /* TTreeReaderValue<Int_t> Ndata_P_hgcer_adcPulseTime = {fReader, "Ndata.P.hgcer.adcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_adcCounter = {fReader, "P.hgcer.adcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_adcErrorFlag = {fReader, "P.hgcer.adcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_adcPulseTime = {fReader, "P.hgcer.adcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hgcer_goodAdcTdcDiffTime = {fReader, "Ndata.P.hgcer.goodAdcTdcDiffTime"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_goodAdcTdcDiffTime = {fReader, "P.hgcer.goodAdcTdcDiffTime"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_goodAdcMult = {fReader, "P.hgcer.goodAdcMult"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_goodAdcPulseAmp = {fReader, "P.hgcer.goodAdcPulseAmp"}; */
   
   
   /* TTreeReaderValue<Int_t> Ndata_P_hgcer_adcPulseAmp = {fReader, "Ndata.P.hgcer.adcPulseAmp"}; */
   /* TTreeReaderArray<Double_t> P_hgcer_adcPulseAmp = {fReader, "P.hgcer.adcPulseAmp"}; */

   //*******************************************NGCER*******************************//

   /* TTreeReaderValue<Int_t> Ndata_P_ngcer_adcPulseTime = {fReader, "Ndata.P.ngcer.adcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_adcCounter = {fReader, "P.ngcer.adcCounter"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_adcErrorFlag = {fReader, "P.ngcer.adcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_adcPulseTime = {fReader, "P.ngcer.adcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_ngcer_goodAdcTdcDiffTime = {fReader, "Ndata.P.ngcer.goodAdcTdcDiffTime"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_goodAdcTdcDiffTime = {fReader, "P.ngcer.goodAdcTdcDiffTime"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_goodAdcMult = {fReader, "P.ngcer.goodAdcMult"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_ngcer_adcPulseAmp = {fReader, "Ndata.P.ngcer.adcPulseAmp"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_adcPulseAmp = {fReader, "P.ngcer.adcPulseAmp"}; */
   /* TTreeReaderArray<Double_t> P_ngcer_goodAdcPulseAmp = {fReader, "P.ngcer.goodAdcPulseAmp"}; */

   //*******************************************PRESHOWER*******************************//

   TTreeReaderValue<Int_t> Ndata_P_precal_negAdcPulseTime = {fReader, "Ndata.P.cal.pr.negAdcPulseTime"};
   TTreeReaderArray<Double_t> P_precal_negAdcCounter = {fReader, "P.cal.pr.negAdcCounter"};
   TTreeReaderArray<Double_t> P_precal_negAdcErrorFlag = {fReader, "P.cal.pr.negAdcErrorFlag"};
   TTreeReaderArray<Double_t> P_precal_negAdcPulseTime = {fReader, "P.cal.pr.negAdcPulseTime"};
   //TTreeReaderArray<Double_t> P_precal_negAdcPulseTime = {fReader, "P.cal.pr.negAdcPulseTime"};
   TTreeReaderArray<Double_t> P_precal_negAdcPulseAmp = {fReader, "P.cal.pr.negAdcPulseAmp"};
   

   TTreeReaderValue<Int_t> Ndata_P_precal_posAdcPulseTime = {fReader, "Ndata.P.cal.pr.posAdcPulseTime"};
   TTreeReaderArray<Double_t> P_precal_posAdcCounter = {fReader, "P.cal.pr.posAdcCounter"};
   TTreeReaderArray<Double_t> P_precal_posAdcErrorFlag = {fReader, "P.cal.pr.posAdcErrorFlag"};

   TTreeReaderArray<Double_t> P_precal_posAdcPulseTime = {fReader, "P.cal.pr.posAdcPulseTime"};

   TTreeReaderArray<Double_t> P_precal_posAdcPulseAmp = {fReader, "P.cal.pr.posAdcPulseAmp"};
   
   
  


   //********************GOOD ADC TDC TIME DIFF***********************************//
   //********************calorimter***********************************//
   //*************** Positive side**************************************//

   TTreeReaderValue<Int_t> Ndata_P_precal_goodPosAdcTdcDiffTime = {fReader, "Ndata.P.cal.pr.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodPosAdcTdcDiffTime ={fReader, "P.cal.pr.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodPosAdcMult = {fReader, "P.cal.pr.goodPosAdcMult" };
   TTreeReaderValue<Int_t> Ndata_P_precal_goodPosAdcMult = {fReader, "Ndata.P.cal.pr.goodPosAdcMult"};
   TTreeReaderArray<Double_t> P_precal_goodPosAdcPulseAmp = {fReader, "P.cal.pr.goodPosAdcPulseAmp"};


   //************Negative side**********************************//
   TTreeReaderValue<Int_t> Ndata_P_precal_goodNegAdcTdcDiffTime = {fReader, "Ndata.P.cal.pr.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodNegAdcTdcDiffTime = {fReader, "P.cal.pr.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodNegAdcMult = {fReader, "P.cal.pr.goodNegAdcMult"};
   TTreeReaderArray<Double_t> P_precal_goodNegAdcPulseAmp = {fReader, "P.cal.pr.goodNegAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_P_precal_goodNegAdcMult = {fReader, "Ndata.P.cal.pr.goodNegAdcMult"};

   //***************************************SHOWER*****************************************//

   TTreeReaderValue<Int_t> Ndata_P_cal_adcPulseTime = {fReader, "Ndata.P.cal.fly.adcPulseTime"};
   TTreeReaderArray<Double_t> P_cal_adcCounter = {fReader, "P.cal.fly.adcCounter"};
   TTreeReaderArray<Double_t> P_cal_adcErrorFlag = {fReader, "P.cal.fly.adcErrorFlag"};
   TTreeReaderArray<Double_t> P_cal_adcPulseTime = {fReader, "P.cal.fly.adcPulseTime"};
   TTreeReaderArray<Double_t> P_cal_adcPulseAmp = {fReader, "P.cal.fly.adcPulseAmp"};

   //*********GoodAdcTdcTimeDiff***********************//
   TTreeReaderValue<Int_t> Ndata_P_cal_goodAdcTdcTimeDiff = {fReader, "Ndata.P.cal.fly.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_cal_goodAdcTdcTimeDiff = {fReader, "P.cal.fly.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_cal_goodAdcMult = {fReader, "P.cal.fly.goodAdcMult"};
   TTreeReaderArray<Double_t> P_cal_goodAdcPulseAmp = {fReader, "P.cal.fly.goodAdcPulseAmp"};

   
   TTreeReaderValue<Double_t> P_hod_starttime = {fReader, "P.hod.starttime"};

  

   SHMSADCGates(TTree * /*tree*/ =0) {h1_delta=0,h1_gooddelta=0,h1PHGCERPulseTimeVsPulseAmp=0,h1PHGCERPGoodAdcTdcDiffTime_Mult =0,h1PHGCERPGoodAdcTdcDiffTime =0,h1PHGCERPulseTimeStarttimeDiff=0,h1goodTimeVsAmpMult=0,h1TimeVsAmpMultCal=0, h1TimeVsAmpCal=0,h1TimeVsAmpMult=0,h1goodTimeMultCal =0,h1goodTimeCal =0,h1PHGCERPulseTimeVsPulseAmpMultCut =0,h1PHGCERPulseTimeStarttimeDiffMultCut =0,h1PHGCERPulseTimeStarttimeDiffMult=0,h1PHGCERPulseTimeStarttimeDiff=0,h1PHGCERPulseTime=0;}
   virtual ~SHMSADCGates() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(SHMSADCGates,0);

};

#endif

#ifdef SHMSADCGates_cxx
void SHMSADCGates::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t SHMSADCGates::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef SHMSADCGates_cxx
