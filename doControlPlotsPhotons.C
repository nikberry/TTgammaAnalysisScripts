#include "TFile.h"
#include "TH1.h"
#include "TObject.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLegend.h"
#include "THStack.h"
#include "TLine.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include "tdrstyle.C"
#include "getSample.C"

void doControlPlotsPhotons();

//stuff to choose
bool logPlot = false; //true for log plot

//choose object
TString Obj = "MuMu/";
//TString Obj = "EE/";
//TString Obj = "EMu/";

//TString RefSelection = "One Photon/";    //if use "TTbarPhotonAnalysis/";
TString RefSelection = "Ref selection/";   //if use "TTbarDiLeptonAnalysis/"

//TString Type = "MET/";
TString Type = "Photons/";
//TString Type = "Jets";
//TString Type = "DiMuon";

TString Next = "AllPhotons/";
//TString Next = "SignalPhotons/";

TString Systematic = "central/";

//TString Cut = "TTbarPhotonAnalysis/";
TString Cut = "TTbarDiLeptonAnalysis/";


//MuMu variables
const int N = 16;
//int RebinFact;

int RebinFacts[N] = {20, 25, 5, 5, 2, 2, 6, 6, 19, 15, 1, 5, 2, 20, 20, 20}; //SignalPhotons PassesCutsUpToOnePhoton1Btag  
//int RebinFacts[N] = {12, 11, 3, 3, 2, 2, 6, 6, 12, 16, 4, 4, 2}; //AllPhotons PassesCutsUpTo1Btag Muons
//int RebinFacts[N] = {58, 40, 18, 18, 5, 5, 5, 5, 36, 50, 9, 8, 3}; //SignalPhotons PassesCutsUpTo1Btag Muons


TString Variable;
TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_", "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
"Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_",
"Photon_Phi_", "Photon_sigma_ietaieta_barrel_", "Photon_sigma_ietaieta_endcap_", "Photon_HtowoE_", "Photon_deltaR_electrons_", "Photon_deltaR_jets_", "Photon_deltaR_muons_"};
double MinXs[N] = {0, -3 , 0 , 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0};
double MaxXs[N] = {3,  3 , 130, 130, 45, 45, 96, 96, 360, 4, 0.04, 0.1, 0.32, 5, 5, 5};
TString XTitles[N] = {"#left|#eta#right|_{#gamma}", "#eta_{#gamma}", "RhoCorrPhotonIsobarrel", "RhoCorrPhotonIsoendcap", "RhoCorrNeutralHadronIsobarrel",
"RhoCorrNeutralHadronIsoendcap", "RhoCorrChargedHadronIsobarrel", "RhoCorrChargedHadronIsoendcap", "p_{T}(#gamma)",  "#phi_{#gamma}",  "#sigmaI#etaI#eta_barrel",
"#sigmaI#etaI#eta_endcap",  "H/E", "#DeltaR(#gamma, e)", "#DeltaR(#gamma, jets)", "#DeltaR(#gamma, #mu)"};

void doControlPlotsPhotons(){
setTDRStyle();

//loop over variables
for(int i = 0; i<N; i++){
double MinX = MinXs[i];
double MaxX = MaxXs[i];
Variable = Variables[i];
TString Xtitle = XTitles[i];
int RebinFact = RebinFacts[i];

//Data
TH1D* data = getSample("DoubleMu", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
//TH1D* data = getSample("DoubleElectron", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
//TH1D* data = getSample("MuEG", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

//MC
TH1D* ttgamma = getSample("TTGamma", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* tt = getSample("TTJet", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* wjets = getSample("WJetsToLNu", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* DY1 = getSample("DYJetsToLL_M-10To50", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* DY2 = getSample("DYJetsToLL_M-50", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* T_tW = getSample("T_tW-channel", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* Tbar_tW = getSample("Tbar_tW-channel",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* ZZ = getSample("ZZtoAnything",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* WW = getSample("WWtoAnything",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* WZ = getSample("WZtoAnything",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

//QCD
TH1D* QCD_Pt_20_30_BCtoE = getSample("QCD_Pt_20_30_BCtoE",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_20_30_EMEnriched = getSample("QCD_Pt_20_30_EMEnriched",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_20_MuEnrichedPt_15 = getSample("QCD_Pt_20_MuEnrichedPt_15",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_30_80_BCtoE = getSample("QCD_Pt_30_80_BCtoE",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_30_80_EMEnriched = getSample("QCD_Pt_30_80_EMEnriched",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_80_170_BCtoE = getSample("QCD_Pt_80_170_BCtoE",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
TH1D* QCD_Pt_80_170_EMEnriched = getSample("QCD_Pt_80_170_EMEnriched",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

TH1D* QCD_all = getSample("QCD_Pt_20_MuEnrichedPt_15",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
  QCD_all->Add(QCD_Pt_20_30_BCtoE);
  QCD_all->Add(QCD_Pt_20_30_EMEnriched);
  QCD_all->Add(QCD_Pt_30_80_BCtoE);
  QCD_all->Add(QCD_Pt_30_80_EMEnriched);
  QCD_all->Add(QCD_Pt_80_170_BCtoE);
  QCD_all->Add(QCD_Pt_80_170_EMEnriched);
  

TH1D* allMC = (TH1D*)ttgamma->Clone("ratio");
  allMC->Add(tt);
  allMC->Add(wjets);
  allMC->Add(DY1);
  allMC->Add(DY2);
  allMC->Add(T_tW);
  allMC->Add(Tbar_tW);
  allMC->Add(ZZ);
  allMC->Add(WW);
  allMC->Add(WZ);
  allMC->Add(QCD_all);
//   allMC->Add(QCD_Pt_20_30_BCtoE);
//   allMC->Add(QCD_Pt_20_30_EMEnriched);
//   allMC->Add(QCD_Pt_30_80_BCtoE);
//   allMC->Add(QCD_Pt_30_80_EMEnriched);
//   allMC->Add(QCD_Pt_80_170_BCtoE);
//   allMC->Add(QCD_Pt_80_170_EMEnriched);

THStack *hs = new THStack("hs","test");
//   hs->Add(QCD_Pt_20_30_BCtoE);
//   hs->Add(QCD_Pt_20_30_EMEnriched);
//   hs->Add(QCD_Pt_30_80_BCtoE);
//   hs->Add(QCD_Pt_30_80_EMEnriched);
//   hs->Add(QCD_Pt_80_170_BCtoE);
//   hs->Add(QCD_Pt_80_170_EMEnriched);
  hs->Add(QCD_all);
  hs->Add(wjets);
  hs->Add(WZ); 
  hs->Add(WW);
  hs->Add(ZZ);
  hs->Add(DY1);
  hs->Add(DY2);
  hs->Add(T_tW); 
  hs->Add(Tbar_tW);
  hs->Add(tt); 
  hs->Add(ttgamma);
  

std::cout << "Total number of events" << std::endl;
std::cout << "Data: " << data->Integral() << std::endl;
std::cout << "ttbar + gamma: " << ttgamma->Integral() << std::endl;
std::cout << "Inclusive ttbar: " << tt->Integral() << std::endl;
std::cout << "W+Jets: " << wjets->Integral() << std::endl;
std::cout << "Drell-Yan1: " << DY1->Integral() << std::endl;
std::cout << "Drell-Yan2: " << DY2->Integral() << std::endl;
std::cout << "Single top: " << T_tW->Integral() << std::endl;
std::cout << "Anti-Single top: " << Tbar_tW->Integral() << std::endl;
std::cout << "ZZ: " << ZZ->Integral() << std::endl;
std::cout << "WW: " << WW->Integral() << std::endl;
std::cout << "WZ: " << WZ->Integral() << std::endl;
std::cout << "QCD: " << QCD_all->Integral() << std::endl;


  //draw histos to files
  TCanvas *c1 = new TCanvas("Plot","Plot",900, 600);
  TPad *pad1 = new TPad("pad1","pad1",0,0.3,1,1);
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();	  

  data->Draw();
  data->SetAxisRange(MinX, MaxX, "X");
//  data->Draw();

  hs->Draw("hist");
  hs->GetXaxis()->SetLimits(MinX, MaxX);	
	
  hs->SetMaximum(data->GetBinContent(data->GetMaximumBin())*1.3);

//  hs->Draw();
  data->Draw("E same");
  data->SetMarkerStyle(20);
  
  hs->GetXaxis()->SetLimits(MinX, MaxX);
  hs->GetXaxis()->SetTitle(Xtitle); hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitle("Number of Events");hs->GetYaxis()->SetTitleSize(0.05);
   
  
  	TLegend *tleg2;
	tleg2 = new TLegend(0.7, 0.6, 0.8, 0.9);
	tleg2->SetTextSize(0.04);
	tleg2->SetBorderSize(0);
	tleg2->SetFillColor(10);
	tleg2->AddEntry(data , "2012 data", "lpe");
	tleg2->AddEntry(ttgamma , "t#bar{t}#gamma", "lf");
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	tleg2->AddEntry(T_tW, "Single Top"      , "lf");
//	tleg2->AddEntry(Tbar_tW, "anti-single-tW"      , "lf");	
	tleg2->AddEntry(DY1 , "Z+Jets", "lf");
//	tleg2->AddEntry(DY2 , "DYJetsToLL", "lf");
	tleg2->AddEntry(ZZ, "Diboson", "lf");
//	tleg2->AddEntry(WW, "WW", "lf");
//	tleg2->AddEntry(WZ , "WZ", "lf");
	tleg2->AddEntry(wjets , "W+Jets", "lf");
	tleg2->AddEntry(QCD_all, "QCD", "lf");
	
 	tleg2->Draw("same");	

	TText* textPrelim = doPrelim(0.20, 0.96);
        textPrelim->Draw();

  c1->cd();

  if(logPlot == true){
     c1->SetLogy();
  }

   TPad *pad2 = new TPad("pad2","pad2",0,0,1,0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.4);
   pad2->Draw();
   pad2->cd();

   TH1D * ratio = (TH1D*)data->Clone("ratio plot");
   //ratio->Sumw2();
   ratio->SetStats(0);
   ratio->Divide(allMC);
   ratio->SetMinimum(0);
   ratio->SetMaximum(2);

   cout << "width: " << ratio->GetBinWidth(1) << std::endl;
   ratio->SetAxisRange(MinX, MaxX-ratio->GetBinWidth(1));

   ratio->SetLabelSize(0.1, "X");
   ratio->SetTitleOffset(0.5, "Y");
   ratio->GetYaxis()->SetTitle("data/MC");ratio->GetYaxis()->SetTitleSize(0.1);
   ratio->GetXaxis()->SetTitle(Xtitle);ratio->GetXaxis()->SetTitleSize(0.15);
   ratio->Draw("ep");

   TLine *line = new TLine(MinX,1,MaxX,1);
   line->Draw();

  TString plotName("plots/Control/" + Cut + Type + Next + Obj);
  
  if(logPlot == true){
    plotName += Variable+"Log.pdf";
//    plotName += Nbtags+".pdf";
    
  }else{
    plotName += Variable+".pdf";  
//    plotName += Nbtags+".pdf";
  }
 
  c1->SaveAs(plotName);
  delete c1;
  
  }
  	
}


