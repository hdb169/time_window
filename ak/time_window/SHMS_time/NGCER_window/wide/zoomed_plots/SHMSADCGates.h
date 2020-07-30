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
   TH1F          **h1PHGCERPulseTime;
   TH1F          **h1PHGCERPulseTimeStarttimeDiff;
   TH1F          **h1PHGCERPulseTimeStarttimeDiffMult;
   TH1F          **h1PHGCERPulseTimeStarttimeDiffMultCut;
   TH2F          **h1PHGCERPulseTimeVsPulseAmpMultCut;

   TH1F          **h1PNGCERPulseTime;
   TH1F          **h1PNGCERPulseTimeStarttimeDiff;
   TH1F          **h1PNGCERPulseTimeStarttimeDiffMult;
   TH1F          **h1PNGCERPulseTimeStarttimeDiffMultCut;
   TH2F          **h1PNGCERPulseTimeVsPulseAmpMultCut;


   TH1F          **h1goodTimeCal;
   TH1F          **h1goodTimeMultCal;

   TH2F          **h1TimeVsAmpMult;
   TH2F          **h1TimeVsAmpCal;
   TH2F          **h1TimeVsAmpMultCal;
   TH2F          **h1goodTimeVsAmpMult;
   TH1F          **h1;
   TH1F          **h2;
   TH1F          **h1_int;
   TH1F          **h2_int;
   TH1F          **h1_delta;
   TH2F          **h1XtrackVsYtrack;

   TH1F          **h1PPRECALNegPulseTime;
   TH1F          **h1PPRECALNegPulseTimeStarttimeDiff;
   TH1F          **h1PPRECALNegPulseTimeStarttimeDiffMult;
   TH1F          **h1PPRECALNegPulseTimeStarttimeDiffMultCut;
   TH2F          **h1PPRECALNegPulseTimeVsPulseAmpMultCut;
   

   TH1F          **h1PPRECALPosPulseTime;
   TH1F          **h1PPRECALPosPulseTimeStarttimeDiff;
   TH1F          **h1PPRECALPosPulseTimeStarttimeDiffMult;
   TH1F          **h1PPRECALPosPulseTimeStarttimeDiffMultCut;
   TH2F          **h1PPRECALPosPulseTimeVsPulseAmpMultCut;


   
   
   TH1F          **h1PCALPulseTime;
   TH1F          **h1PCALPulseTimeStarttimeDiff;
   TH1F          **h1PCALPulseTimeStarttimeDiff_CalCut;
   TH1F          **h1PCALPulseTimeStarttimeDiffMult;
   TH1F          **h1PCALPulseTimeStarttimeDiffMultCut;
   TH2F          **h1PCALPulseTimeVsPulseAmp;
   TH2F          **h1PCALPulseTimeVsPulseAmpMultCut;

   TH1F          **h1PCALGoodAdcTdcDiffTime;
   TH1F          **h1PCALGoodAdcTdcDiffTime_Cut;



   TH1F          **h1PDCRawTdc;

   TH1F          **h1PHODO1xNegPulseTimeStarttimeDiff;
   TH1F          **h1PHODO1xPosPulseTimeStarttimeDiff;
   TH1F          **h1PHODO1yNegPulseTimeStarttimeDiff;
   TH1F          **h1PHODO1yPosPulseTimeStarttimeDiff;
   TH1F          **h1PHODO2xNegPulseTimeStarttimeDiff;
   TH1F          **h1PHODO2xPosPulseTimeStarttimeDiff;
   TH1F          **h1PHODO2yNegPulseTimeStarttimeDiff;
   TH1F          **h1PHODO2yPosPulseTimeStarttimeDiff;

   TH1F          **h1PHGCERPulseTimeStarttimeDiff_CalCut;
   TH1F          **h1PHGCERPGoodAdcTdcDiffTime;
   TH1F          **h1PHGCERPGoodAdcTdcDiffTime_Mult;

   TH1F          **h1PNGCERPulseTimeStarttimeDiff_CalCut;
   TH1F          **h1PNGCERPGoodAdcTdcDiffTime;
   TH1F          **h1PNGCERPGoodAdcTdcDiffTime_Mult;

   TH1F         **h1PPRECALPosPulseTimeStarttimeDiff_CalCut;
   TH1F         **h1PPRECALNegPulseTimeStarttimeDiff_CalCut;

   TH1F         **h1PPRECALGoodPosAdcTdcDiffTime;
   TH1F         **h1PPRECALGoodNegAdcTdcDiffTime;
   TH1F         **h1PPRECALGoodPosAdcTdcDiffTime_Cut;
   TH1F         **h1PPRECALGoodNegAdcTdcDiffTime_Cut;

   //************************************for 2D plots******************//
   TH2F         **h1PHGCERPulseTimeVsPulseAmp;
   TH2F         **h1PNGCERPulseTimeVsPulseAmp;

   TH2F         **h1PPRECALNegPulseTimeVsPulseAmp;
   TH2F         **h1PPRECALPosPulseTimeVsPulseAmp;

   TH2F         *h1weightAmp;
   TH2F         *h1weightAmpNorm;
   TH2F         *h1trackproject;

   // Readers to access the data (delete the ones you do not need).

   TTreeReaderValue<Double_t> P_cal_etottracknorm = {fReader, "P.cal.etottracknorm"};
   TTreeReaderValue<Double_t> P_gtr_dp = {fReader, "P.gtr.dp"};


   //TTreeReaderValue<Double_t> P_ngcer_xAtCer = {fReader, "P.ngcer.xAtCer"};
   // TTreeReaderValue<Double_t> P_ngcer_yAtCer = {fReader, "P.ngcer.yAtCer"};

   TTreeReaderValue<Double_t> P_dc_x_fp = {fReader, "P.dc.x_fp"};
   TTreeReaderValue<Double_t>  P_dc_xp_fp = {fReader, "P.dc.xp_fp"};
   TTreeReaderValue<Double_t> P_dc_y_fp = {fReader, "P.dc.y_fp"};
   TTreeReaderValue<Double_t>  P_dc_yp_fp = {fReader, "P.dc.yp_fp"};


   //***************************** HGCER *************************************//

   TTreeReaderValue<Int_t> Ndata_P_hgcer_adcPulseTime = {fReader, "Ndata.P.hgcer.adcPulseTime"};
   TTreeReaderArray<Double_t> P_hgcer_adcCounter = {fReader, "P.hgcer.adcCounter"};
   TTreeReaderArray<Double_t> P_hgcer_adcErrorFlag = {fReader, "P.hgcer.adcErrorFlag"};
   TTreeReaderArray<Double_t> P_hgcer_adcPulseTime = {fReader, "P.hgcer.adcPulseTime"};

   TTreeReaderValue<Int_t> Ndata_P_hgcer_goodAdcTdcDiffTime = {fReader, "Ndata.P.hgcer.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_hgcer_goodAdcTdcDiffTime = {fReader, "P.hgcer.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_hgcer_goodAdcMult = {fReader, "P.hgcer.goodAdcMult"};
   TTreeReaderArray<Double_t> P_hgcer_goodAdcPulseAmp = {fReader, "P.hgcer.goodAdcPulseAmp"};
   //TTreeReaderArray<Double_t> P_hgcer_goodAdcPulseInt = {fReader, "P.hgcer.goodAdcPulseInt"};
   
   TTreeReaderValue<Int_t> Ndata_P_hgcer_adcPulseAmp = {fReader, "Ndata.P.hgcer.adcPulseAmp"};
   TTreeReaderArray<Double_t> P_hgcer_adcPulseAmp = {fReader, "P.hgcer.adcPulseAmp"};

   //*******************************************NGCER*******************************//

   TTreeReaderValue<Int_t> Ndata_P_ngcer_adcPulseTime = {fReader, "Ndata.P.ngcer.adcPulseTime"};
   TTreeReaderArray<Double_t> P_ngcer_adcCounter = {fReader, "P.ngcer.adcCounter"};
   TTreeReaderArray<Double_t> P_ngcer_adcErrorFlag = {fReader, "P.ngcer.adcErrorFlag"};
   TTreeReaderArray<Double_t> P_ngcer_adcPulseTime = {fReader, "P.ngcer.adcPulseTime"};

   TTreeReaderValue<Int_t> Ndata_P_ngcer_goodAdcTdcDiffTime = {fReader, "Ndata.P.ngcer.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_ngcer_goodAdcTdcDiffTime = {fReader, "P.ngcer.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_ngcer_goodAdcMult = {fReader, "P.ngcer.goodAdcMult"};

   TTreeReaderValue<Int_t> Ndata_P_ngcer_adcPulseAmp = {fReader, "Ndata.P.ngcer.adcPulseAmp"};
   TTreeReaderArray<Double_t> P_ngcer_adcPulseAmp = {fReader, "P.ngcer.adcPulseAmp"};
   TTreeReaderArray<Double_t> P_ngcer_goodAdcPulseAmp = {fReader, "P.ngcer.goodAdcPulseAmp"};
   TTreeReaderArray<Double_t> P_ngcer_adcPulseInt = {fReader, "P.ngcer.adcPulseInt"};
   TTreeReaderArray<Double_t> P_ngcer_goodAdcPulseInt = {fReader, "P.ngcer.goodAdcPulseInt"};

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



   //************Negative side**********************************//
   TTreeReaderValue<Int_t> Ndata_P_precal_goodNegAdcTdcDiffTime = {fReader, "Ndata.P.cal.pr.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodNegAdcTdcDiffTime = {fReader, "P.cal.pr.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> P_precal_goodNegAdcMult = {fReader, "P.cal.pr.goodNegAdcMult"};
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

  
   /* TTreeReaderValue<Int_t> Ndata_P_hod_1x_negAdcPulseTime = {fReader, "Ndata.P.hod.1x.negAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_negAdcCounter = {fReader, "P.hod.1x.negAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_negAdcErrorFlag = {fReader, "P.hod.1x.negAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_negAdcPulseTime = {fReader, "P.hod.1x.negAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_1y_negAdcPulseTime = {fReader, "Ndata.P.hod.1y.negAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_negAdcCounter = {fReader, "P.hod.1y.negAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_negAdcErrorFlag = {fReader, "P.hod.1y.negAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_negAdcPulseTime = {fReader, "P.hod.1y.negAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_2x_negAdcPulseTime = {fReader, "Ndata.P.hod.2x.negAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_negAdcCounter = {fReader, "P.hod.2x.negAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_negAdcErrorFlag = {fReader, "P.hod.2x.negAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_negAdcPulseTime = {fReader, "P.hod.2x.negAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_2y_negAdcPulseTime = {fReader, "Ndata.P.hod.2y.negAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_negAdcCounter = {fReader, "P.hod.2y.negAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_negAdcErrorFlag = {fReader, "P.hod.2y.negAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_negAdcPulseTime = {fReader, "P.hod.2y.negAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_1x_posAdcPulseTime = {fReader, "Ndata.P.hod.1x.posAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_posAdcCounter = {fReader, "P.hod.1x.posAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_posAdcErrorFlag = {fReader, "P.hod.1x.posAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_1x_posAdcPulseTime = {fReader, "P.hod.1x.posAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_1y_posAdcPulseTime = {fReader, "Ndata.P.hod.1y.posAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_posAdcCounter = {fReader, "P.hod.1y.posAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_posAdcErrorFlag = {fReader, "P.hod.1y.posAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_1y_posAdcPulseTime = {fReader, "P.hod.1y.posAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_2x_posAdcPulseTime = {fReader, "Ndata.P.hod.2x.posAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_posAdcCounter = {fReader, "P.hod.2x.posAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_posAdcErrorFlag = {fReader, "P.hod.2x.posAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_2x_posAdcPulseTime = {fReader, "P.hod.2x.posAdcPulseTime"}; */

   /* TTreeReaderValue<Int_t> Ndata_P_hod_2y_posAdcPulseTime = {fReader, "Ndata.P.hod.2y.posAdcPulseTime"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_posAdcCounter = {fReader, "P.hod.2y.posAdcCounter"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_posAdcErrorFlag = {fReader, "P.hod.2y.posAdcErrorFlag"}; */
   /* TTreeReaderArray<Double_t> P_hod_2y_posAdcPulseTime = {fReader, "P.hod.2y.posAdcPulseTime"}; */
   
   TTreeReaderValue<Double_t> P_hod_starttime = {fReader, "P.hod.starttime"};

  

   SHMSADCGates(TTree * /*tree*/ =0) {h1XtrackVsYtrack=0,h1_delta=0,h1_int=0,h2_int=0,h2=0,h1=0,h1goodTimeMultCal=0,h1goodTimeCal=0,h1goodTimeVsAmpMult=0,h1TimeVsAmpMultCal=0,h1TimeVsAmpCal=0,h1TimeVsAmpMult=0,h1PCALPulseTimeVsPulseAmpMultCut=0,h1PCALPulseTimeStarttimeDiffMultCut=0,h1PCALPulseTimeStarttimeDiffMult=0,h1PPRECALPosPulseTimeVsPulseAmpMultCut=0,h1PPRECALPosPulseTimeStarttimeDiffMultCut=0,h1PPRECALPosPulseTimeStarttimeDiffMult=0,h1PPRECALNegPulseTimeVsPulseAmpMultCut=0,h1PPRECALNegPulseTimeStarttimeDiffMultCut=0,h1PPRECALNegPulseTimeStarttimeDiffMult=0,h1PNGCERPulseTimeVsPulseAmpMultCut=0,h1PHGCERPulseTimeVsPulseAmpMultCut=0,h1PNGCERPulseTimeStarttimeDiffMultCut=0,h1PNGCERPulseTimeStarttimeDiffMult=0,h1PHGCERPulseTimeStarttimeDiffMultCut=0,h1PHGCERPulseTimeStarttimeDiffMult=0,h1PCALPulseTime=0,h1PPRECALPosPulseTimeVsPulseAmp=0,h1PPRECALNegPulseTimeVsPulseAmp=0,h1PNGCERPulseTimeVsPulseAmp=0,h1PHGCERPulseTimeVsPulseAmp=0,h1PCALGoodAdcTdcDiffTime_Cut=0,h1PCALGoodAdcTdcDiffTime=0,h1PCALPulseTimeStarttimeDiff_CalCut=0,h1PPRECALGoodPosAdcTdcDiffTime_Cut=0,h1PPRECALGoodNegAdcTdcDiffTime_Cut=0,h1PPRECALGoodNegAdcTdcDiffTime=0,h1PPRECALGoodPosAdcTdcDiffTime=0,h1PPRECALPosPulseTimeStarttimeDiff_CalCut=0,h1PPRECALNegPulseTimeStarttimeDiff_CalCut=0,h1PHGCERPulseTime=0,h1PHGCERPulseTimeStarttimeDiff=0,h1PHGCERPulseTimeStarttimeDiff_CalCut=0,h1PHGCERPGoodAdcTdcDiffTime=0,h1PHGCERPGoodAdcTdcDiffTime_Mult=0,h1PNGCERPulseTime=0,h1PNGCERPulseTimeStarttimeDiff=0,/*h1PAERONegPulseTime=0,h1PAERONegPulseTimeStarttimeDiff=0,h1PAEROPosPulseTime=0,h1PAEROPosPulseTimeStarttimeDiff=0*/h1PPRECALNegPulseTime=0,h1PPRECALNegPulseTimeStarttimeDiff=0,h1PPRECALPosPulseTime=0,h1PPRECALPosPulseTimeStarttimeDiff=0,h1PCALPulseTimeStarttimeDiff=0,h1PDCRawTdc=0,h1PHODO1xNegPulseTimeStarttimeDiff=0,h1PHODO1xPosPulseTimeStarttimeDiff=0,h1PHODO1yNegPulseTimeStarttimeDiff=0,h1PHODO1yPosPulseTimeStarttimeDiff=0,h1PHODO2xNegPulseTimeStarttimeDiff=0,h1PHODO2xPosPulseTimeStarttimeDiff=0,h1PHODO2yNegPulseTimeStarttimeDiff=0,h1PHODO2yPosPulseTimeStarttimeDiff=0;}
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
