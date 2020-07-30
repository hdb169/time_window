#ifndef HMSADCGates_h
#define HMSADCGates_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

class HMSADCGates : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree *fChain = 0; 

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
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodNegAdcMult = {fReader, "Ndata.H.cal.1pr.goodNegAdcMult"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodNegAdcMult = {fReader, "H.cal.1pr.goodNegAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodNegAdcPulseAmp = {fReader, "Ndata.H.cal.1pr.goodNegAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodNegAdcPulseAmp = {fReader, "H.cal.1pr.goodNegAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodNegAdcTdcDiffTime = {fReader, "Ndata.H.cal.1pr.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodNegAdcTdcDiffTime = {fReader, "H.cal.1pr.goodNegAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodPosAdcMult = {fReader, "Ndata.H.cal.1pr.goodPosAdcMult"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodPosAdcMult = {fReader, "H.cal.1pr.goodPosAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodPosAdcPulseAmp = {fReader, "Ndata.H.cal.1pr.goodPosAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodPosAdcPulseAmp = {fReader, "H.cal.1pr.goodPosAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_goodPosAdcTdcDiffTime = {fReader, "Ndata.H.cal.1pr.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_1pr_goodPosAdcTdcDiffTime = {fReader, "H.cal.1pr.goodPosAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_negAdcCounter = {fReader, "Ndata.H.cal.1pr.negAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_1pr_negAdcCounter = {fReader, "H.cal.1pr.negAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_negAdcErrorFlag = {fReader, "Ndata.H.cal.1pr.negAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_1pr_negAdcErrorFlag = {fReader, "H.cal.1pr.negAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_negAdcPulseAmp = {fReader, "Ndata.H.cal.1pr.negAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_1pr_negAdcPulseAmp = {fReader, "H.cal.1pr.negAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_negAdcPulseTime = {fReader, "Ndata.H.cal.1pr.negAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_1pr_negAdcPulseTime = {fReader, "H.cal.1pr.negAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_posAdcCounter = {fReader, "Ndata.H.cal.1pr.posAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_1pr_posAdcCounter = {fReader, "H.cal.1pr.posAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_posAdcErrorFlag = {fReader, "Ndata.H.cal.1pr.posAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_1pr_posAdcErrorFlag = {fReader, "H.cal.1pr.posAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_posAdcPulseAmp = {fReader, "Ndata.H.cal.1pr.posAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_1pr_posAdcPulseAmp = {fReader, "H.cal.1pr.posAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_1pr_posAdcPulseTime = {fReader, "Ndata.H.cal.1pr.posAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_1pr_posAdcPulseTime = {fReader, "H.cal.1pr.posAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodNegAdcMult = {fReader, "Ndata.H.cal.2ta.goodNegAdcMult"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodNegAdcMult = {fReader, "H.cal.2ta.goodNegAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodNegAdcPulseAmp = {fReader, "Ndata.H.cal.2ta.goodNegAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodNegAdcPulseAmp = {fReader, "H.cal.2ta.goodNegAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodNegAdcTdcDiffTime = {fReader, "Ndata.H.cal.2ta.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodNegAdcTdcDiffTime = {fReader, "H.cal.2ta.goodNegAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodPosAdcMult = {fReader, "Ndata.H.cal.2ta.goodPosAdcMult"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodPosAdcMult = {fReader, "H.cal.2ta.goodPosAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodPosAdcPulseAmp = {fReader, "Ndata.H.cal.2ta.goodPosAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodPosAdcPulseAmp = {fReader, "H.cal.2ta.goodPosAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_goodPosAdcTdcDiffTime = {fReader, "Ndata.H.cal.2ta.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_2ta_goodPosAdcTdcDiffTime = {fReader, "H.cal.2ta.goodPosAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_negAdcCounter = {fReader, "Ndata.H.cal.2ta.negAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_2ta_negAdcCounter = {fReader, "H.cal.2ta.negAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_negAdcErrorFlag = {fReader, "Ndata.H.cal.2ta.negAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_2ta_negAdcErrorFlag = {fReader, "H.cal.2ta.negAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_negAdcPulseAmp = {fReader, "Ndata.H.cal.2ta.negAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_2ta_negAdcPulseAmp = {fReader, "H.cal.2ta.negAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_negAdcPulseTime = {fReader, "Ndata.H.cal.2ta.negAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_2ta_negAdcPulseTime = {fReader, "H.cal.2ta.negAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_posAdcCounter = {fReader, "Ndata.H.cal.2ta.posAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_2ta_posAdcCounter = {fReader, "H.cal.2ta.posAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_posAdcErrorFlag = {fReader, "Ndata.H.cal.2ta.posAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_2ta_posAdcErrorFlag = {fReader, "H.cal.2ta.posAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_posAdcPulseAmp = {fReader, "Ndata.H.cal.2ta.posAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_2ta_posAdcPulseAmp = {fReader, "H.cal.2ta.posAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_2ta_posAdcPulseTime = {fReader, "Ndata.H.cal.2ta.posAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_2ta_posAdcPulseTime = {fReader, "H.cal.2ta.posAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodNegAdcMult = {fReader, "Ndata.H.cal.3ta.goodNegAdcMult"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodNegAdcMult = {fReader, "H.cal.3ta.goodNegAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodNegAdcPulseAmp = {fReader, "Ndata.H.cal.3ta.goodNegAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodNegAdcPulseAmp = {fReader, "H.cal.3ta.goodNegAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodNegAdcTdcDiffTime = {fReader, "Ndata.H.cal.3ta.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodNegAdcTdcDiffTime = {fReader, "H.cal.3ta.goodNegAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodPosAdcMult = {fReader, "Ndata.H.cal.3ta.goodPosAdcMult"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodPosAdcMult = {fReader, "H.cal.3ta.goodPosAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodPosAdcPulseAmp = {fReader, "Ndata.H.cal.3ta.goodPosAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodPosAdcPulseAmp = {fReader, "H.cal.3ta.goodPosAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_goodPosAdcTdcDiffTime = {fReader, "Ndata.H.cal.3ta.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_3ta_goodPosAdcTdcDiffTime = {fReader, "H.cal.3ta.goodPosAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_negAdcCounter = {fReader, "Ndata.H.cal.3ta.negAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_3ta_negAdcCounter = {fReader, "H.cal.3ta.negAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_negAdcErrorFlag = {fReader, "Ndata.H.cal.3ta.negAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_3ta_negAdcErrorFlag = {fReader, "H.cal.3ta.negAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_negAdcPulseAmp = {fReader, "Ndata.H.cal.3ta.negAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_3ta_negAdcPulseAmp = {fReader, "H.cal.3ta.negAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_negAdcPulseTime = {fReader, "Ndata.H.cal.3ta.negAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_3ta_negAdcPulseTime = {fReader, "H.cal.3ta.negAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_posAdcCounter = {fReader, "Ndata.H.cal.3ta.posAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_3ta_posAdcCounter = {fReader, "H.cal.3ta.posAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_posAdcErrorFlag = {fReader, "Ndata.H.cal.3ta.posAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_3ta_posAdcErrorFlag = {fReader, "H.cal.3ta.posAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_posAdcPulseAmp = {fReader, "Ndata.H.cal.3ta.posAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_3ta_posAdcPulseAmp = {fReader, "H.cal.3ta.posAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_3ta_posAdcPulseTime = {fReader, "Ndata.H.cal.3ta.posAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_3ta_posAdcPulseTime = {fReader, "H.cal.3ta.posAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodNegAdcMult = {fReader, "Ndata.H.cal.4ta.goodNegAdcMult"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodNegAdcMult = {fReader, "H.cal.4ta.goodNegAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodNegAdcPulseAmp = {fReader, "Ndata.H.cal.4ta.goodNegAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodNegAdcPulseAmp = {fReader, "H.cal.4ta.goodNegAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodNegAdcTdcDiffTime = {fReader, "Ndata.H.cal.4ta.goodNegAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodNegAdcTdcDiffTime = {fReader, "H.cal.4ta.goodNegAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodPosAdcMult = {fReader, "Ndata.H.cal.4ta.goodPosAdcMult"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodPosAdcMult = {fReader, "H.cal.4ta.goodPosAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodPosAdcPulseAmp = {fReader, "Ndata.H.cal.4ta.goodPosAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodPosAdcPulseAmp = {fReader, "H.cal.4ta.goodPosAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_goodPosAdcTdcDiffTime = {fReader, "Ndata.H.cal.4ta.goodPosAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cal_4ta_goodPosAdcTdcDiffTime = {fReader, "H.cal.4ta.goodPosAdcTdcDiffTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_negAdcCounter = {fReader, "Ndata.H.cal.4ta.negAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_4ta_negAdcCounter = {fReader, "H.cal.4ta.negAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_negAdcErrorFlag = {fReader, "Ndata.H.cal.4ta.negAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_4ta_negAdcErrorFlag = {fReader, "H.cal.4ta.negAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_negAdcPulseAmp = {fReader, "Ndata.H.cal.4ta.negAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_4ta_negAdcPulseAmp = {fReader, "H.cal.4ta.negAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_negAdcPulseTime = {fReader, "Ndata.H.cal.4ta.negAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_4ta_negAdcPulseTime = {fReader, "H.cal.4ta.negAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_posAdcCounter = {fReader, "Ndata.H.cal.4ta.posAdcCounter"};
   TTreeReaderArray<Double_t> H_cal_4ta_posAdcCounter = {fReader, "H.cal.4ta.posAdcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_posAdcErrorFlag = {fReader, "Ndata.H.cal.4ta.posAdcErrorFlag"};
   TTreeReaderArray<Double_t> H_cal_4ta_posAdcErrorFlag = {fReader, "H.cal.4ta.posAdcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_posAdcPulseAmp = {fReader, "Ndata.H.cal.4ta.posAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cal_4ta_posAdcPulseAmp = {fReader, "H.cal.4ta.posAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cal_4ta_posAdcPulseTime = {fReader, "Ndata.H.cal.4ta.posAdcPulseTime"};
   TTreeReaderArray<Double_t> H_cal_4ta_posAdcPulseTime = {fReader, "H.cal.4ta.posAdcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cer_adcCounter = {fReader, "Ndata.H.cer.adcCounter"};
   TTreeReaderArray<Double_t> H_cer_adcCounter = {fReader, "H.cer.adcCounter"};
   TTreeReaderValue<Int_t> Ndata_H_cer_adcErrorFlag = {fReader, "Ndata.H.cer.adcErrorFlag"};
   TTreeReaderArray<Double_t> H_cer_adcErrorFlag = {fReader, "H.cer.adcErrorFlag"};
   TTreeReaderValue<Int_t> Ndata_H_cer_adcPulseAmp = {fReader, "Ndata.H.cer.adcPulseAmp"};
   TTreeReaderArray<Double_t> H_cer_adcPulseAmp = {fReader, "H.cer.adcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cer_adcPulseTime = {fReader, "Ndata.H.cer.adcPulseTime"};
   TTreeReaderArray<Double_t> H_cer_adcPulseTime = {fReader, "H.cer.adcPulseTime"};
   TTreeReaderValue<Int_t> Ndata_H_cer_goodAdcMult = {fReader, "Ndata.H.cer.goodAdcMult"};
   TTreeReaderArray<Double_t> H_cer_goodAdcMult = {fReader, "H.cer.goodAdcMult"};
   TTreeReaderValue<Int_t> Ndata_H_cer_goodAdcPulseAmp = {fReader, "Ndata.H.cer.goodAdcPulseAmp"};
   TTreeReaderArray<Double_t> H_cer_goodAdcPulseAmp = {fReader, "H.cer.goodAdcPulseAmp"};
   TTreeReaderValue<Int_t> Ndata_H_cer_goodAdcTdcDiffTime = {fReader, "Ndata.H.cer.goodAdcTdcDiffTime"};
   TTreeReaderArray<Double_t> H_cer_goodAdcTdcDiffTime = {fReader, "H.cer.goodAdcTdcDiffTime"};
   TTreeReaderValue<Double_t> H_cer_npeSum = {fReader, "H.cer.npeSum"};
   TTreeReaderValue<Double_t> H_hod_starttime = {fReader, "H.hod.starttime"};
   TTreeReaderValue<Double_t> H_gtr_dp = {fReader, "H.gtr.dp"};
   TTreeReaderValue<Double_t> H_cal_etottracknorm = {fReader, "H.cal.etottracknorm"};
  
   HMSADCGates(TTree * /*tree*/ =0) {h1_delta=0,h1_gooddelta=0,h1PHGCERPulseTimeVsPulseAmp=0,h1PHGCERPGoodAdcTdcDiffTime_Mult =0,h1PHGCERPGoodAdcTdcDiffTime =0,h1PHGCERPulseTimeStarttimeDiff=0,h1goodTimeVsAmpMult=0,h1TimeVsAmpMultCal=0, h1TimeVsAmpCal=0,h1TimeVsAmpMult=0,h1goodTimeMultCal =0,h1goodTimeCal =0,h1PHGCERPulseTimeVsPulseAmpMultCut =0,h1PHGCERPulseTimeStarttimeDiffMultCut =0,h1PHGCERPulseTimeStarttimeDiffMult=0,h1PHGCERPulseTimeStarttimeDiff=0,h1PHGCERPulseTime=0;}
   virtual ~HMSADCGates() { }
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

   ClassDef(HMSADCGates,0);

};

#endif

#ifdef HMSADCGates_cxx
void HMSADCGates::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t HMSADCGates::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef HMSADCGates_cxx
