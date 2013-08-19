#include "TFile.h"
#include "TH1.h"
#include "TObject.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLegend.h"
#include "THStack.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include "tdrstyle.C"
#include "getSample.C"

void doControlPlotsMuons();

//stuff to choose
bool logPlot = true; //true for log plot

//choose object
TString Obj = "Muons/";
//TString Obj = "EE/";

TString Next = "AllMuons/";
//TString Next = "SignalMuons";


TString Systematic = "central";

//MuMu variables
const int N = 9;
int RebinFact;
int RebinFacts[N] = {16, 13, 10, 13, 2, 13, 25, 25, 25};
TString Variable;
TString Variables[N] = {"Muon_AbsEta_", "Muon_Eta_", "Muon_Pt_", "Muon_Phi_", "Muon_deltaR_jets_", "Muon_dB_", "Muon_pfIsolation_03_", "Muon_pfIsolation_04_", "Muon_pfIsolation_05_"};
// double MinXs[N] = {0,-2.6 ,0 , 0, -3.4, 0};
// double MaxXs[N] = {2.6,2.6 ,0.5 , 400,3.2 , 0.3};
TString XTitles[N] = {"#left|#eta#right|_{#mu}", "#eta_{#mu}", "p_{T}(#mu)", "#phi_{#mu}", "#DeltaR(#mu,jets)", "dB(#mu)", "PFIso03(#mu)", "PFIso04(#mu)", "PFIso05(#mu)"};

void doControlPlotsMuons(){
setTDRStyle();

//loop over variables
for(int i = 0; i<N; i++){
//double MinX = MinXs[i];
//double MaxX = MaxXs[i];
RebinFact = RebinFacts[i];
Variable = Variables[i];
TString Xtitle = XTitles[i];

//Data
TH1D* data = getSample("DoubleMu", 1, Obj, Next, Variable, RebinFact, Systematic);

std::cout << data->Integral() << std::endl;

//MC
TH1D* tt = getSample("TTJet", 1, Obj, Next, Variable, RebinFact, Systematic);
TH1D* wjets = getSample("WJetsToLNu", 1, Obj, Next, Variable, RebinFact, Systematic);
TH1D* DY1 = getSample("DYJetsToLL_M-10To50", 1, Obj, Next, Variable, RebinFact, Systematic);
TH1D* DY2 = getSample("DYJetsToLL_M-50", 1, Obj, Next, Variable, RebinFact, Systematic);
TH1D* T_tW = getSample("T_tW-channel", 1, Obj, Next, Variable, RebinFact, Systematic);
TH1D* Tbar_tW = getSample("Tbar_tW-channel",1, Obj, Next, Variable, RebinFact, Systematic);

THStack *hs = new THStack("hs","test");

  hs->Add(wjets);
  hs->Add(DY1);
  hs->Add(DY2);
  hs->Add(T_tW); 
  hs->Add(Tbar_tW);
  hs->Add(tt); 
  
  //draw histos to files
  TCanvas *c1 = new TCanvas("Plot","Plot",900, 600);
		
  hs->SetMaximum(data->GetBinContent(data->GetMaximumBin())*1.3);

  hs->Draw();
  data->Draw("E same");
  data->SetMarkerStyle(20);
  
//  hs->GetXaxis()->SetLimits(MinX, MaxX);
  hs->GetXaxis()->SetTitle(Xtitle); hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitle("Number of Events");hs->GetYaxis()->SetTitleSize(0.05);
   
   
  if(logPlot == true){
  c1->SetLogy();
  }	
  
  	TLegend *tleg2;
	tleg2 = new TLegend(0.6,0.7,0.8,0.9);
	tleg2->SetTextSize(0.04);
	tleg2->SetBorderSize(0);
	tleg2->SetFillColor(10);
	tleg2->AddEntry(data , "2012 data", "lpe");
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	tleg2->AddEntry(T_tW, "single-t", "lf");
	tleg2->AddEntry(Tbar_tW, "single-#bar{t}", "lf");	
	tleg2->AddEntry(DY1 , "DYJetsToLL-10To50", "lf");
	tleg2->AddEntry(DY2 , "DYJetsToLL-50", "lf");
	tleg2->AddEntry(wjets , "W+jets", "lf");
	
 	tleg2->Draw("same");	

  TString plotName("plots/Control/PassesCutsUpTo1Btag/Muons/");
  
  if(logPlot == true){
    plotName += Variable+"Log.pdf";
//    plotName += Nbtags+".pdf";
    
  }else{
    plotName += Variable+".pdf";  
//    plotName += Nbtags+".pdf";
  }
 
  TText* textPrelim = doPrelim(0.16,0.96); 
  textPrelim->Draw();
  
  c1->SaveAs(plotName);
  delete c1;
  
  }
  	
}


