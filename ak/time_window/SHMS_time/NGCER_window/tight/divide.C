void divide ()
{

  TFile *Myfile = new TFile("h1calcut_wide.root");
  TFile *Myfile1 = new TFile("h1calcut_tight.root");

  TH1F *hist[4];
  TH1F *hist1[4];

  // Myfile->GetListOfKeys()->Print();
  for(int i =0; i<4; i++)
    {
      hist[i] = (TH1F*)Myfile->Get(Form("h1goodTimecal%d",i+1));
      hist1[i] = (TH1F*)Myfile1->Get(Form("h1goodTimecal%d",i+1));
    }
  // hist1[0]->Draw();
  auto c1 = new TCanvas("c1", "" , 500, 500);
  
  c1->Divide(2,2);
  
  for ( int i =0; i< 4 ; i++)
    {
      c1->cd(i+1);
      gPad->SetLogy();
      hist[i]->Sumw2();
      hist1[i]->Sumw2();
      hist[i]->GetYaxis()->SetRangeUser(0.9,1.1);
      hist[i]->GetXaxis()->SetRangeUser(-30,-15);
      hist[i]->SetMarkerStyle(45);
      hist[i]->SetMarkerSize(1);
      hist[i]->Divide(hist1[i]);
      hist[i]->Draw("P");
      // auto rp = new TRatioPlot(hist[i], hist1[i]);
      // rp->Draw();
      // rp->GetLowerRefGraph()->SetMinimum(0.9);
      // rp->GetLowerRefGraph()->SetMaximum(1.1);
      // rp->GetLowerRefGraph()->GetXaxis()->SetRangeUser(-30,-15);
    }

  c1->SaveAs("final_ratio.eps");



      // hist[i]->Draw();
      // hist1[i]->Draw("same");
      // hist1[i]->SetLineColor(kBlue);
  //}


}
