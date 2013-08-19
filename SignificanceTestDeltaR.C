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

int RebinFact = 1;

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

TString Cut = "PassesCutsUpToOnePhoton1Btag/";
//TString Cut = "PassesCutsUpTo1Btag/";
//TString Cut = "PassesCutsUpToOnePhoton/";
//TString Cut = "PassesCutsUpToPhoton/";
//TString Cut = "PassesCutsUpToMET/";

//choose variable
//TString Variable = "Photon_deltaR_electrons_";
//TString Variable = "Photon_deltaR_muons_";
TString Variable = "Photon_deltaR_jets_";

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
	
TH1D* sigTest = new TH1D("sigTest", "#DeltaR(#gamma, jets) Significance Test", 25, 0, 5);
 	sigTest->GetYaxis()->SetTitle("Significance");
 	sigTest->SetFillColor(kAzure);
 	sigTest->SetLineColor(kAzure);
 	sigTest->GetXaxis()->SetTitle("#DeltaR(#gamma, jets)"); 	
		
	for(int i = 0; i<ttgamma->GetNbinsX()-1; i++){	
 	 
 	sigTest->SetBinContent(i+1, ttgamma->Integral(i,ttgamma->GetNbinsX()) / sqrt(ttgamma->Integral(i,ttgamma->GetNbinsX()) + tt->Integral(i,ttgamma->GetNbinsX())
	+ wjets->Integral(i,ttgamma->GetNbinsX()) + DY1->Integral(i,ttgamma->GetNbinsX()) + DY2->Integral(i,ttgamma->GetNbinsX()) 
	+ T_tW->Integral(i,ttgamma->GetNbinsX()) + Tbar_tW->Integral(i,ttgamma->GetNbinsX())));

std::cout << ttgamma->Integral(i,ttgamma->GetNbinsX()) / sqrt(ttgamma->Integral(i,ttgamma->GetNbinsX()) + tt->Integral(i,ttgamma->GetNbinsX())
        + wjets->Integral(i,ttgamma->GetNbinsX()) + DY1->Integral(i,ttgamma->GetNbinsX()) + DY2->Integral(i,ttgamma->GetNbinsX())
        + T_tW->Integral(i,ttgamma->GetNbinsX()) + Tbar_tW->Integral(i,ttgamma->GetNbinsX())) << std::endl; 
	
 	}

TCanvas *c1 = new TCanvas("Plot");

	sigTest->Draw();

	TString plotName("plots/Control/" + Cut + Type + Next + Obj +"SignificanceTestDeltaRJets.pdf");
	c1->SaveAs(plotName);
	delete c1;

}
