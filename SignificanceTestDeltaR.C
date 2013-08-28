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

void SignificanceTestDeltaR();

int RebinFact = 10;

//choose obj
//TString Obj = "MuMu/";
//TString Obj = "EE/";
TString Obj = "EMu/";

TString RefSelection = "One Photon/";

TString Type ="Photons/";

//choose signal or all photons
//TString Next = "AllPhotons/";
TString Next = "SignalPhotons/";

//choose systematic
TString Systematic = "central/";

TString Cut = "TTbarPhotonAnalysis/";
//TString Cut = "TTbarDiLeptonAnalysis/";

//choose variable
TString Variable = "Photon_deltaR_electrons_";
//TString Variable = "Photon_deltaR_muons_";
//TString Variable = "Photon_deltaR_jets_";

void SignificanceTestDeltaR(){

setTDRStyle();
 
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
//TH1D* QCD_Pt_20_MuEnrichedPt_15 = getSample("QCD_Pt_20_MuEnrichedPt_15",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
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

TH1D* allMC = (TH1D*)ttgamma->Clone("all MC");
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

 
  	
TH1D* sigTest = new TH1D("sigTest", "#DeltaR(#gamma, jets) Significance Test", 500/RebinFact, 0, 5);
 	sigTest->GetYaxis()->SetTitle("Significance");
 	//sigTest->SetFillColor(kAzure);
 	//sigTest->SetLineColor(kAzure);
	
	if(Variable == "Photon_deltaR_muons_")
 		sigTest->GetXaxis()->SetTitle("#DeltaR(#gamma, #mu)");
	if(Variable == "Photon_deltaR_jets_")
 		sigTest->GetXaxis()->SetTitle("#DeltaR(#gamma, jets)"); 	
	if(Variable == "Photon_deltaR_electrons_")
 		sigTest->GetXaxis()->SetTitle("#DeltaR(#gamma, e)");
			
	for(int i = 1; i<ttgamma->GetNbinsX(); i++){	
 	
	double ttgammaErr, allErr;
	
	double sigVal = ttgamma->IntegralAndError(i,ttgamma->GetNbinsX(),ttgammaErr) / sqrt(ttgamma->IntegralAndError(i,allMC->GetNbinsX(), allErr));
	double sigErr = sigVal*sqrt(pow(ttgammaErr/ttgamma->Integral(i,ttgamma->GetNbinsX()),2)+pow(allErr/allMC->Integral(i,ttgamma->GetNbinsX()),2));
	
	if(sigVal > 0){
	 
 	sigTest->SetBinContent(i, sigVal);
	sigTest->SetBinError(i, sigErr);
	}
	
std::cout << sigVal << " , pm: " << sigErr << std::endl; 
	
 	}

TCanvas *c1 = new TCanvas("Plot");

	

	sigTest->Draw("E");

	TString plotName("plots/Control/" + Obj + Cut + Type + Next + Variable+"ge1b_sig");
	c1->SaveAs(plotName+".pdf");
	c1->SaveAs(plotName+".png");
	delete c1;

}
