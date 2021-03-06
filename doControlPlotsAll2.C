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

void doControlPlotsAll2();

//stuff to choose
bool logPlot = false; //true for log plot

//inclusive top or fakes
bool inclTop = true;

TString Type = "Photons/", "MET/", "DiMuon/", "DiElectron/", "DiLepton/", "Jets/";

TString Obj = "MuMu/";
//TString Obj = "EE/";
//TString Obj = "EMu/";

TString Cut = "TTbarPhotonAnalysis/", "TTbarDiLeptonAnalysis/";

TString RefSelection = "Ref selection/"; 

TString Next = "patType1CorrectedPFMet/", "AllPhotons/", "SignalPhotons/", "NminusOnePhotons/";

TString Systematic = "central/";


// for( Type == "Photons/" ){
// 
// TString Cut = "TTbarPhotonAnalysis/", "TTbarDiLeptonAnalysis/";
// TString Next = "AllPhotons/", "SignalPhotons/", "NminusOnePhotons/";
// TString Variable;
// 
//   if(Cut == "TTbarPhotonAnalysis/" || "TTbarDiLeptonAnalysis/"){
// 
//   for(Next == "AllPhotons/" || Next == "SignalPhotons/"){
//   const int N = 16;
//   
//   if(Next == "SignalPhotons/")
//   int RebinFacts[N] = {25, 22, 30, 30, 30, 30, 28, 28, 11, 10, 3, 22, 20, 20, 20, 38};
//   if(Next == "AllPhotons/")
//   int RebinFacts[N] = {20, 20, 5, 5, 2, 2, 5, 5, 25, 10, 1, 5, 1, 20, 20, 20}; 
//   
//   TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_", "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
//   "Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_",
//   "Photon_Phi_", "Photon_sigma_ietaieta_barrel_", "Photon_sigma_ietaieta_endcap_", "Photon_HtowoE_", "Photon_deltaR_electrons_", "Photon_deltaR_jets_", "Photon_deltaR_muons_"};
//   double MinXs[N] = {0, -3 , 0 , 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0};
//   double MaxXs[N] = {3,  3 , 130, 130, 40, 40, 100, 100, 260, 4, 0.05, 0.1, 0.06, 5, 5, 5};
//   TString XTitles[N] = {"#left|#eta#right|_{#gamma}", "#eta_{#gamma}", "RhoCorrPhotonIsobarrel", "RhoCorrPhotonIsoendcap", "RhoCorrNeutralHadronIsobarrel",
//   "RhoCorrNeutralHadronIsoendcap", "RhoCorrChargedHadronIsobarrel", "RhoCorrChargedHadronIsoendcap", "p_{T}(#gamma) [GeV]",  "#phi_{#gamma}",  "#sigma i#etai#eta barrel",
//   "#sigma i#etai#eta endcap",  "H/E", "#DeltaR(#gamma, e)", "#DeltaR(#gamma, jets)", "#DeltaR(#gamma, #mu)"};
//   }
//   
// 
//   for(Next == "NminusOnePhotons/"){
//   const int N = 14;
//   int RebinFacts[N] = {25, 22, 30, 30, 30, 30, 28, 28, 11, 3, 22, 20, 20, 38};
//   TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_",  "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
//   "Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_",
//   "Photon_sigma_ietaieta_barrel_", "Photon_sigma_ietaieta_endcap_", "Photon_HtowoE_", "Photon_deltaR_electrons_", "Photon_deltaR_muons_"};
//   double MinXs[N] = {0, -3 , 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0};
//   double MaxXs[N] = {3,  3 , 130, 130, 40, 40, 100, 100, 260, 0.05, 0.1, 5., 5,  5};
//   TString XTitles[N] = {"#left|#eta#right|_{#gamma}", "#eta_{#gamma}", "RhoCorrPhotonIsobarrel", "RhoCorrPhotonIsoendcap", "RhoCorrNeutralHadronIsobarrel",
//   "RhoCorrNeutralHadronIsoendcap", "RhoCorrChargedHadronIsobarrel", "RhoCorrChargedHadronIsoendcap", "p_{T}(#gamma) [GeV]",   "#sigma i#etai#eta barrel",
//   "#sigma i#etai#eta endcap",  "H/E", "#DeltaR(#gamma, e)", "#DeltaR(#gamma, #mu)"};
//   }
//   }
// }
// 
// for( Type == "DiMuon" || Type == "DiElectron" || Type == "DiLepton" ){
//   //Rebinning factors  
//   const int N = 5;
//   int RebinFacts[N] = {5, 5, 2, 2, 2};
//   
//   //Variables
//   TString Variable;
// 
// TString Variables[N] = {"LeadLepton_AbsEta_", "SecondLepton_AbsEta_", "LeadLepton_Pt_", "SecondLepton_Pt_", "diLepton_Mass_"};
//   
//   //X-axis range
//   double MinXs[N] = {0,    0,  0, 0, 0};
//   double MaxXs[N] = {2.5,  2.6, 400, 400, 500};
//   
//   //X-axis title
//   TString XTitles[N] = {"1^{st} #mu |#eta|", "2^{nd} #mu |#eta|", "1^{st} #mu p_{T} [GeV]", "2^{nd} #mu p_{T} [GeV]", "m(ll) [GeV]"};
//   //change to: TString XTitles[N] = {"1^{st} l |#eta|", "2^{nd} l |#eta|", "1^{st} l p_{T}", "2^{nd} l p_{T}", "m(ll)"};
//     
// }
// 
// for( Type == "MET/" ){
//   //Rebinning factors
//   const int N = 5;
//   int RebinFacts[N] = {1, 10, 2, 10, 10}; //Pre photon requirement
//   int RebinFacts[N] = {4, 30, 2, 10, 18}; //Pre photon requirement
// 
//   //Variables
//   TString Variable;
//   TString Variables[N] = {"MET_", "DeltaPhi_lepton_MET_", "MET_phi_", "METsignificance_", "Transverse_Mass_"};
//   
//   //X-axis range
//   double MinXs[N] = {0,   0,  -3.4, 0,   0};
//   double MaxXs[N] = {300, 3.2, 3.4, 300, 300};
//   
//   //X-axis title
//   TString XTitles[N] = {"#slash{E}_{T} [GeV]", "#Delta#phi(l, MET)", "#phi(#slash{E}_{T})", "#slash{E}_{T} significance", "M_{T}(MET) [GeV]"};
//   
// }
// 
// for( Type == "Jets/" ){
//   //Rebinning factors
//   const int N = 3;
//   int RebinFacts[N] = {5, 5, 1};
//   
//   //Variables
//   TString Variable;
//   TString Variables[N] = {"all_jet_pT_", "all_jet_eta_", "N_Jets_"};
//   
//   //X-axis range
//   double MinXs[N] = {0,   -2.6,  0};
//   double MaxXs[N] = {300,  2.6, 10};
//   
//   //X-axis title
//   TString XTitles[N] = {"Jet {p}_{T} [GeV]", "Jet #eta", "N Jets"};   
// } 
  


void doControlPlotsAll2(){
setTDRStyle();
gROOT->SetBatch();
gStyle->SetErrorX(0.5);


for( Type == "Photons/" ){

//TString Cut = "TTbarPhotonAnalysis/", "TTbarDiLeptonAnalysis/";
//TString Next = "AllPhotons/", "SignalPhotons/", "NminusOnePhotons/";
TString Variable;

  if(Cut == "TTbarPhotonAnalysis/" || "TTbarDiLeptonAnalysis/"){

  for(Next == "AllPhotons/" || Next == "SignalPhotons/"){
  const int N = 16;
  
  if(Next == "SignalPhotons/")
  int RebinFacts[N] = {25, 22, 30, 30, 30, 30, 28, 28, 11, 10, 3, 22, 20, 20, 20, 38};
  if(Next == "AllPhotons/")
  int RebinFacts[N] = {20, 20, 5, 5, 2, 2, 5, 5, 25, 10, 1, 5, 1, 20, 20, 20}; 
  
  TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_", "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
  "Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_",
  "Photon_Phi_", "Photon_sigma_ietaieta_barrel_", "Photon_sigma_ietaieta_endcap_", "Photon_HtowoE_", "Photon_deltaR_electrons_", "Photon_deltaR_jets_", "Photon_deltaR_muons_"};
  double MinXs[N] = {0, -3 , 0 , 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0};
  double MaxXs[N] = {3,  3 , 130, 130, 40, 40, 100, 100, 260, 4, 0.05, 0.1, 0.06, 5, 5, 5};
  TString XTitles[N] = {"#left|#eta#right|_{#gamma}", "#eta_{#gamma}", "RhoCorrPhotonIsobarrel", "RhoCorrPhotonIsoendcap", "RhoCorrNeutralHadronIsobarrel",
  "RhoCorrNeutralHadronIsoendcap", "RhoCorrChargedHadronIsobarrel", "RhoCorrChargedHadronIsoendcap", "p_{T}(#gamma) [GeV]",  "#phi_{#gamma}",  "#sigma i#etai#eta barrel",
  "#sigma i#etai#eta endcap",  "H/E", "#DeltaR(#gamma, e)", "#DeltaR(#gamma, jets)", "#DeltaR(#gamma, #mu)"};
  }
  

  for(Next == "NminusOnePhotons/"){
  const int N = 14;
  int RebinFacts[N] = {25, 22, 30, 30, 30, 30, 28, 28, 11, 3, 22, 20, 20, 38};
  TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_",  "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
  "Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_",
  "Photon_sigma_ietaieta_barrel_", "Photon_sigma_ietaieta_endcap_", "Photon_HtowoE_", "Photon_deltaR_electrons_", "Photon_deltaR_muons_"};
  double MinXs[N] = {0, -3 , 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0};
  double MaxXs[N] = {3,  3 , 130, 130, 40, 40, 100, 100, 260, 0.05, 0.1, 5., 5,  5};
  TString XTitles[N] = {"#left|#eta#right|_{#gamma}", "#eta_{#gamma}", "RhoCorrPhotonIsobarrel", "RhoCorrPhotonIsoendcap", "RhoCorrNeutralHadronIsobarrel",
  "RhoCorrNeutralHadronIsoendcap", "RhoCorrChargedHadronIsobarrel", "RhoCorrChargedHadronIsoendcap", "p_{T}(#gamma) [GeV]",   "#sigma i#etai#eta barrel",
  "#sigma i#etai#eta endcap",  "H/E", "#DeltaR(#gamma, e)", "#DeltaR(#gamma, #mu)"};
  }
  }
}

//loop over variables
for(int i = 0; i<N; i++){
double MinX = MinXs[i];
double MaxX = MaxXs[i];
Variable = Variables[i];
TString Xtitle = XTitles[i];
int RebinFact = RebinFacts[i];

//Data
TH1D* data;
if(Obj == "MuMu/")
data = getSample("DoubleMu", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
if(Obj == "EE/")
data = getSample("DoubleElectron", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
if(Obj == "EMu/")
data = getSample("MuEG", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

//MC
TH1D* ttgamma = getSample("TTGamma", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

//this to get all ttbar

TH1D* tt;
TH1D* tt_lep; 
TH1D* tt_sig; 
if(inclTop == false){
//fake ttgamma
tt = getSample("TTJet", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut, "fake");
tt_lep = getSample("TTJet", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut, "lep");
tt_sig = getSample("TTJet", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut, "sig");
}else{
tt = getSample("TTJet", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
}

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
  
  if(inclTop == false){
  allMC->Add(tt_lep);
  allMC->Add(tt_sig);
  }
  
  allMC->Add(wjets);
  allMC->Add(DY1);
  allMC->Add(DY2);
  allMC->Add(T_tW);
  allMC->Add(Tbar_tW);
  allMC->Add(ZZ);
  allMC->Add(WW);
  allMC->Add(WZ);
  allMC->Add(QCD_all);
  
  allMC->SetFillColor(kBlack);
  allMC->SetFillStyle(3354);
  allMC->SetMarkerSize(0.);
  allMC->SetStats(0);

THStack *hs = new THStack("hs","test");
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
  
  if(inclTop == false){
  hs->Add(tt_lep);
  hs->Add(tt_sig);
  } 
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

  hs->Draw("hist");
  allMC->Draw("same e2");
	
  hs->SetMaximum(data->GetBinContent(data->GetMaximumBin())*1.3);

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
	
	if(inclTop == false){
	tleg2->AddEntry(tt_sig , "t#bar{t}#gamma (MG)", "lf");
	tleg2->AddEntry(tt_lep , "t#bar{t} l #rightarrow #gamma (MG)", "lf");
	tleg2->AddEntry(tt , "t#bar{t} fake (MG)", "lf");
	}else{
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	}
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

	TText* textPrelim = doPrelim(0.20, 0.96, Cut, Obj);
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
   ratio->SetFillColor(kBlack);
   ratio->SetFillStyle(3354);
   ratio->SetMarkerSize(0.);

   cout << "width: " << ratio->GetBinWidth(1)  << " , max: " << MaxX << std::endl;
   
   if(MaxX <= 0.1){
   ratio->SetAxisRange(MinX, MaxX);
   }else{ 
   ratio->SetAxisRange(MinX, MaxX-ratio->GetBinWidth(1));
   }

   ratio->SetLabelSize(0.1, "X");
   ratio->SetTitleOffset(0.5, "Y");
   ratio->GetYaxis()->SetTitle("data/MC");ratio->GetYaxis()->SetTitleSize(0.1);
   ratio->GetXaxis()->SetTitle(Xtitle);ratio->GetXaxis()->SetTitleSize(0.15);
   ratio->Draw("ep");

   TLine *line = new TLine(MinX,1,MaxX,1);
   line->Draw();

  TString plotName("plots/Control/"+ Obj + Cut  + Type + Next );
  
  if(logPlot == true){
    plotName += Variable+"ge1b_Log.pdf";   
  }else{
    plotName += Variable+"ge1b";  
  }
 
  c1->SaveAs(plotName+".pdf");
  c1->SaveAs(plotName+".png");
  
  delete c1;
  
  }
  	
}


