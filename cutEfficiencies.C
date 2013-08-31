#include "TFile.h"
#include "TH1.h"
#include "TObject.h"
#include "TString.h"
#include "TCanvas.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include "tdrstyle.C"
#include "TLatex.h"


void cutEfficiencies();
//TH1D* getSample(bool muon, bool muonUnweighted, bool electron, bool electronUnweighted);
void printCutflow(string step, int bin, TH1D* cutFlow);
void printCutEff(string step, int bin, TH1D* cutEff);
//void weightHisto(TH1D* sample, double lumi, double xsect, double NEvts);

void cutEfficiencies(){

TFile* DoubleMu = new TFile("/data1/TTGammaAnalysis/HistogramFiles/Version3/central/DoubleMu_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon.root"); //TFile::Open
TFile* DoubleElectron = new TFile("/data1/TTGammaAnalysis/HistogramFiles/Version3/central/DoubleElectron_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon.root");
TFile* MuEG = new TFile("/data1/TTGammaAnalysis/HistogramFiles/Version3/central/MuEG_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon.root");

	bool muon = true;
	bool electron = true;
	bool emu = true;
	bool scale = false;
	bool muonUnweighted = true;
	bool electronUnweighted = true;
	bool emuUnweighted = true;
	
	

//double lumi = 5800;

//setTDRStyle();
TH1D* cutFlow_MuMu = (TH1D*)DoubleMu->Get("EventCount/TTbarMuMuRefSelection");
TH1D* cutFlow_MuMu_unweighted = (TH1D*)DoubleMu->Get("EventCount/TTbarMuMuRefSelectionUnweighted");
TH1D* cutFlow_EE = (TH1D*)DoubleElectron->Get("EventCount/TTbarEERefSelection");
TH1D* cutFlow_EE_unweighted = (TH1D*)DoubleElectron->Get("EventCount/TTbarEERefSelectionUnweighted");
TH1D* cutFlow_EMu = (TH1D*)MuEG->Get("EventCount/TTbarEMuRefSelection");
TH1D* cutFlow_EMu_unweighted = (TH1D*)MuEG->Get("EventCount/TTbarEMuRefSelectionUnweighted");

const int N = 10;
TString muonsteps[N] = {"Skim","Trigger & Cleaning","Di-Muon", "Z Mass Veto", ">= 1 jets", ">= 2 jets", "MET", ">= 1 btag", ">= 1 Photon", "== 1 Photon"};
TString electronsteps[N] = {"Skim","Trigger & Cleaning","Di-Muon", "Z Mass Veto", ">= 1 jets", ">= 2 jets", "MET", ">= 1 btag", ">= 1 Photon", "== 1 Photon"};
TString emusteps[N] = {"Skim","Trigger & Cleaning","Di-Lepton",">= 1 jets", ">= 2 jets", ">= 1 btag", ">= 1 Photon", "== 1 Photon"};

for(int i =0; i<cutFlow_MuMu->GetNbinsX(); i++)
cutFlow_MuMu->GetXaxis()->SetBinLabel(i+1, muonsteps[i]);

for(int i =0; i<cutFlow_MuMu_unweighted->GetNbinsX(); i++)
cutFlow_MuMu_unweighted->GetXaxis()->SetBinLabel(i+1, muonsteps[i]);

for(int i =0; i<cutFlow_EE->GetNbinsX(); i++)
cutFlow_EE->GetXaxis()->SetBinLabel(i+1, electronsteps[i]);

for(int i =0; i<cutFlow_EE_unweighted->GetNbinsX(); i++)
cutFlow_EE_unweighted->GetXaxis()->SetBinLabel(i+1, electronsteps[i]);

for(int i =0; i<cutFlow_EMu->GetNbinsX(); i++)
cutFlow_EMu->GetXaxis()->SetBinLabel(i+1, emusteps[i]);

for(int i =0; i<cutFlow_EMu_unweighted->GetNbinsX(); i++)
cutFlow_EMu_unweighted->GetXaxis()->SetBinLabel(i+1, emusteps[i]);


TH1D* cutEff_MuMu = new TH1D("cut eff","Cut Efficiency #mu#mu",10,0,10);
TH1D* cutEff_MuMu_unweighted = new TH1D("cut eff","Cut Efficiency #mu#mu",10,0,10);
TH1D* cutEff_EE = new TH1D("cut eff","Cut Efficiency e^{+}e^{-}",10,0,10);
TH1D* cutEff_EE_unweighted = new TH1D("cut eff","Cut Efficiency e^{+}e^{-}",10,0,10);
TH1D* cutEff_EMu = new TH1D("cut eff","Cut Efficiency e^{#pm}#mu^{#pm}",8,0,8);
TH1D* cutEff_EMu_unweighted = new TH1D("cut eff","Cut Efficiency e^{#pm}#mu^{#pm}",8,0,8);

for(int i =1; i<10; i++){
cutEff_MuMu->SetBinContent(i+1, cutFlow_MuMu->GetBinContent(i+1)/cutFlow_MuMu->GetBinContent(i));
}	

for(int i =1; i<10; i++){
cutEff_MuMu_unweighted->SetBinContent(i+1, cutFlow_MuMu_unweighted->GetBinContent(i+1)/cutFlow_MuMu_unweighted->GetBinContent(i));
}	

for(int i =1; i<10; i++){
cutEff_EE->SetBinContent(i+1, cutFlow_EE->GetBinContent(i+1)/cutFlow_EE->GetBinContent(i));
}	

for(int i =1; i<10; i++){
cutEff_EE_unweighted->SetBinContent(i+1, cutFlow_EE_unweighted->GetBinContent(i+1)/cutFlow_EE_unweighted->GetBinContent(i));
}	

for(int i =1; i<10; i++){
cutEff_EMu->SetBinContent(i+1, cutFlow_EMu->GetBinContent(i+1)/cutFlow_EMu->GetBinContent(i));
}	

for(int i =1; i<10; i++){
cutEff_EMu_unweighted->SetBinContent(i+1, cutFlow_EMu_unweighted->GetBinContent(i+1)/cutFlow_EMu_unweighted->GetBinContent(i));
}	


/* //weight by xsect and lumi etc..
if(scale == true){
weightHisto(tt, lumi, 157.5, 6920475);
} */

 //draw histos to files = TTbarPhotonAnalysis
  TCanvas *c1 = new TCanvas("Cutflow MuMu","Cutflow #mu#mu",600, 500);
	cutFlow_MuMu->Draw();
	c1->SaveAs("plots/Control/MuMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowMuMu.png");

  TCanvas *c2 = new TCanvas("Cut Eff MuMu","Cutflow Efficiency #mu#mu",600, 500);
	cutEff_MuMu->Draw();
	c2->SaveAs("plots/Control/MuMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffMuMu.png");
	
  TCanvas *c3 = new TCanvas("Cutflow MuMu Unweighted","Cutflow #mu#mu Unweighted",600, 500);
	cutFlow_MuMu_unweighted->Draw();
	c3->SaveAs("plots/Control/MuMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowMuMuUnweighted.png");

  TCanvas *c4 = new TCanvas("Cut Eff MuMu Unweighted","Cutflow Efficiency #mu#mu Unweighted",600, 500);
	cutEff_MuMu_unweighted->Draw();
	c4->SaveAs("plots/Control/MuMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffMuMuUnweighted.png");
	
  TCanvas *c5 = new TCanvas("Cutflow EE","Cutflow $e^+e^-$",600, 500);
	cutFlow_EE->Draw();
	c5->SaveAs("plots/Control/EE/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowEE.png");

  TCanvas *c6 = new TCanvas("Cut Eff EE","Cutflow Efficiency $e^+e^-$",600, 500);
	cutEff_EE->Draw();
	c6->SaveAs("plots/Control/EE/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffEE.png");
	
  TCanvas *c7 = new TCanvas("Cutflow EE Unweighted","Cutflow $e^+e^-$ Unweighted",600, 500);
	cutFlow_EE_unweighted->Draw();
	c7->SaveAs("plots/Control/EE/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowEEUnweighted.png");

  TCanvas *c8 = new TCanvas("Cut Eff EE Unweighted","Cutflow Efficiency $e^+e^-$ Unweighted",600, 500);
	cutEff_EE_unweighted->Draw();
	c8->SaveAs("plots/Control/EE/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffEEUnweighted.png");	
	
   TCanvas *c9 = new TCanvas("Cutflow EMu","Cutflow $e^{#pm}#mu^{#pm}$",600, 500);
	cutFlow_EMu->Draw();
	c9->SaveAs("plots/Control/EMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowEMu.png");

  TCanvas *c10 = new TCanvas("Cut Eff EMu","Cutflow Efficiency $e^{#pm}#mu^{#pm}$",600, 500);
	cutEff_EMu->Draw();
	c10->SaveAs("plots/Control/EMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffEMu.png");
	
  TCanvas *c11 = new TCanvas("Cutflow EMu Unweighted","Cutflow $e^{#pm}#mu^{#pm}$ Unweighted",600, 500);
	cutFlow_EMu_unweighted->Draw();
	c11->SaveAs("plots/Control/EMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutFlowEMuUnweighted.png");

  TCanvas *c12 = new TCanvas("Cut Eff EMu Unweighted","Cutflow Efficiency $e^{#pm}#mu^{#pm}$ Unweighted",600, 500);
	cutEff_EMu_unweighted->Draw();
	c12->SaveAs("plots/Control/EMu/TTbarPhotonAnalysis/Photons/SignalPhotons/cutEffEMuUnweighted.png");	



std::cout << "***********************************************************" << endl;
std::cout << "*                         Cut Flow                        *" << endl;
std::cout << "***********************************************************" << endl;
 		
if (muon == true){
std::cout << "Cut Flow Muon" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_MuMu);
printCutflow("Trigger and clean &  ", 2, cutFlow_MuMu);
printCutflow("Di-muon &  ", 3, cutFlow_MuMu);
printCutflow("Z mass veto &  ", 4, cutFlow_MuMu);
printCutflow("$\\geq$1 jets &  ", 5, cutFlow_MuMu);
printCutflow("$\\geq$2 jets &  ", 6, cutFlow_MuMu);
printCutflow("MET &  ", 7, cutFlow_MuMu);
printCutflow("$\\geq$1 btags &  ", 8, cutFlow_MuMu);
printCutflow("$\\geq$1 Photon &  ", 9, cutFlow_MuMu);
printCutflow("=1 Photon &  ", 10, cutFlow_MuMu);
}

std::cout << "***********************************************************" << endl;

if (electron == true){
std::cout << "Cut Flow Electron" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_EE);
printCutflow("Trigger and clean &  ", 2, cutFlow_EE);
printCutflow("Di-electron &  ", 3, cutFlow_EE);
printCutflow("Z mass veto &  ", 4, cutFlow_EE);
printCutflow("$\\geq$1 jets &  ", 5, cutFlow_EE);
printCutflow("$\\geq$2 jets &  ", 6, cutFlow_EE);
printCutflow("MET &  ", 7, cutFlow_EE);
printCutflow("$\\geq$1 btags &  ", 8, cutFlow_EE);
printCutflow("$\\geq$1 Photon &  ", 9, cutFlow_EE);
printCutflow("=1 Photon &  ", 10, cutFlow_EE);
}

std::cout << "***********************************************************" << endl;

if (emu == true){
std::cout << "Cut Flow EMu" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_EMu);
printCutflow("Trigger and clean &  ", 2, cutFlow_EMu);
printCutflow("Di-lepton &  ", 3, cutFlow_EMu);
printCutflow("$\\geq$1 jets &  ", 4, cutFlow_EMu);
printCutflow("$\\geq$2 jets &  ", 5, cutFlow_EMu);
printCutflow("$\\geq$1 btags &  ", 6, cutFlow_EMu);
printCutflow("$\\geq$1 Photon &  ", 7, cutFlow_EMu);
printCutflow("=1 Photon &  ", 8, cutFlow_EMu);
}

std::cout << "***********************************************************" << endl;

if (muonUnweighted == true){
std::cout << "Cut Flow Muon Unweighted" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_MuMu_unweighted);
printCutflow("Trigger and clean &  ", 2, cutFlow_MuMu_unweighted);
printCutflow("Di-muon &  ", 3, cutFlow_MuMu_unweighted);
printCutflow("Z mass veto &  ", 4, cutFlow_MuMu_unweighted);
printCutflow("$\\geq$1 jets &  ", 5, cutFlow_MuMu_unweighted);
printCutflow("$\\geq$2 jets &  ", 6, cutFlow_MuMu_unweighted);
printCutflow("MET &  ", 7, cutFlow_MuMu_unweighted);
printCutflow("$\\geq$1 btags &  ", 8, cutFlow_MuMu_unweighted);
printCutflow("$\\geq$1 Photon &  ", 9, cutFlow_MuMu_unweighted);
printCutflow("=1 Photon &  ", 10, cutFlow_MuMu_unweighted);
}

std::cout << "***********************************************************" << endl;

if (electronUnweighted == true){
std::cout << "Cut Flow Electron Unweighted" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_EE_unweighted);
printCutflow("Trigger and clean &  ", 2, cutFlow_EE_unweighted);
printCutflow("Di-electron &  ", 3, cutFlow_EE_unweighted);
printCutflow("Z mass veto &  ", 4, cutFlow_EE_unweighted);
printCutflow("$\\geq$1 jets &  ", 5, cutFlow_EE_unweighted);
printCutflow("$\\geq$2 jets &  ", 6, cutFlow_EE_unweighted);
printCutflow("MET &  ", 7, cutFlow_EE_unweighted);
printCutflow("$\\geq$1 btags &  ", 8, cutFlow_EE_unweighted);
printCutflow("$\\geq$1 Photon &  ", 9, cutFlow_EE_unweighted);
printCutflow("=1 Photon &  ", 10, cutFlow_EE_unweighted);
}


std::cout << "***********************************************************" << endl;

if (emuUnweighted == true){
std::cout << "Cut Flow EMu Unweighted" << std::endl;
printCutflow("Skim &  ", 1, cutFlow_EMu_unweighted);
printCutflow("Trigger and clean &  ", 2, cutFlow_EMu_unweighted);
printCutflow("Di-lepton &  ", 3, cutFlow_EMu_unweighted);
printCutflow("$\\geq$1 jets &  ", 4, cutFlow_EMu_unweighted);
printCutflow("$\\geq$2 jets &  ", 5, cutFlow_EMu_unweighted);
printCutflow("$\\geq$1 btags &  ", 6, cutFlow_EMu_unweighted);
printCutflow("$\\geq$1 Photon &  ", 7, cutFlow_EMu_unweighted);
printCutflow("=1 Photon &  ", 8, cutFlow_EMu_unweighted);
}

std::cout << "***********************************************************" << endl;
std::cout << "*                        Efficienies                      *" << endl;
std::cout << "***********************************************************" << endl;

if (muon == true) {
std::cout << "Cut Efficiencies Muon" << std::endl;
printCutEff("Skim &  ", 1, cutEff_MuMu);
printCutEff("Trigger and clean &  ", 2, cutEff_MuMu);
printCutEff("Di-muon &  ", 3, cutEff_MuMu);
printCutEff("Z mass veto &  ", 4, cutEff_MuMu);
printCutEff("$\\geq$1 jets &  ", 5, cutEff_MuMu);
printCutEff("$\\geq$2 jets &  ", 6, cutEff_MuMu);
printCutEff("MET &  ", 7, cutEff_MuMu);
printCutEff("$\\geq$1 btags &  ", 8, cutEff_MuMu);
printCutflow("$\\geq$1 Photon &  ", 9, cutEff_MuMu);
printCutflow("$\\eq$1 Photon &  ", 10, cutEff_MuMu);
}

std::cout << "***********************************************************" << endl;

if (electron == true) {
std::cout << "Cut Efficiencies Electron" << std::endl;
printCutEff("Skim &  ", 1, cutEff_EE);
printCutEff("Trigger and clean &  ", 2, cutEff_EE);
printCutEff("Di-electron &  ", 3, cutEff_EE);
printCutEff("Z mass veto &  ", 4, cutEff_EE);
printCutEff("$\\geq$1 jets &  ", 5, cutEff_EE);
printCutEff("$\\geq$2 jets &  ", 6, cutEff_EE);
printCutEff("MET &  ", 7, cutEff_EE);
printCutEff("$\\geq$1 btags &  ", 8, cutEff_EE);
printCutflow("$\\geq$1 Photon &  ", 9, cutEff_EE);
printCutflow("$\\eq$1 Photon &  ", 10, cutEff_EE);
} 

std::cout << "***********************************************************" << endl;

if (muonUnweighted == true) {
std::cout << "Cut Efficiencies Muon Unweighted" << std::endl;
printCutEff("Skim &  ", 1, cutEff_MuMu_unweighted);
printCutEff("Trigger and clean &  ", 2, cutEff_MuMu_unweighted);
printCutEff("Di-muon &  ", 3, cutEff_MuMu_unweighted);
printCutEff("Z mass veto &  ", 4, cutEff_MuMu_unweighted);
printCutEff("$\\geq$1 jets &  ", 5, cutEff_MuMu_unweighted);
printCutEff("$\\geq$2 jets &  ", 6, cutEff_MuMu_unweighted);
printCutEff("MET &  ", 7, cutEff_MuMu_unweighted);
printCutEff("$\\geq$1 btags &  ", 8, cutEff_MuMu_unweighted);
printCutflow("$\\geq$1 Photon &  ", 9, cutEff_MuMu_unweighted);
printCutflow("$\\eq$1 Photon &  ", 10, cutEff_MuMu_unweighted);
} 

std::cout << "***********************************************************" << endl;

if (electronUnweighted == true){
std::cout << "Cut Efficiencies Electron Unweighted" << std::endl;
printCutEff("Skim &  ", 1, cutEff_EE_unweighted);
printCutEff("Trigger and clean &  ", 2, cutEff_EE_unweighted);
printCutEff("Di-electron &  ", 3, cutEff_EE_unweighted);
printCutEff("Z mass veto &  ", 4, cutEff_EE_unweighted);
printCutEff("$\\geq$1 jets &  ", 5, cutEff_EE_unweighted);
printCutEff("$\\geq$2 jets &  ", 6, cutEff_EE_unweighted);
printCutEff("MET &  ", 7, cutEff_EE_unweighted);
printCutEff("$\\geq$1 btags &  ", 8, cutEff_EE_unweighted);
printCutflow("$\\geq$1 Photon &  ", 9, cutEff_EE_unweighted);
printCutflow("$\\eq$1 Photon &  ", 10, cutEff_EE_unweighted);
}

std::cout << "***********************************************************" << endl;

if (emu == true) {
std::cout << "Cut Efficiencies EMu" << std::endl;
printCutEff("Skim &  ", 1, cutEff_MuMu);
printCutEff("Trigger and clean &  ", 2, cutEff_MuMu);
printCutEff("Di-lepton &  ", 3, cutEff_MuMu);
printCutEff("$\\geq$1 jets &  ", 4, cutEff_MuMu);
printCutEff("$\\geq$2 jets &  ", 5, cutEff_MuMu);
printCutEff("$\\geq$1 btags &  ", 6, cutEff_MuMu);
printCutflow("$\\geq$1 Photon &  ", 7, cutEff_MuMu);
printCutflow("$\\eq$1 Photon &  ", 8, cutEff_MuMu);
} 

std::cout << "***********************************************************" << endl;

if (emuUnweighted == true){
std::cout << "Cut Efficiencies EMu Unweighted" << std::endl;
printCutEff("Skim &  ", 1, cutEff_EMu_unweighted);
printCutEff("Trigger and clean &  ", 2, cutEff_EMu_unweighted);
printCutEff("Di-lepton &  ", 3, cutEff_EMu_unweighted);
printCutEff("$\\geq$1 jets &  ", 4, cutEff_EMu_unweighted);
printCutEff("$\\geq$2 jets &  ", 5, cutEff_EMu_unweighted);
printCutEff("$\\geq$1 btags &  ", 6, cutEff_EMu_unweighted);
printCutflow("$\\geq$1 Photon &  ", 7, cutEff_EMu_unweighted);
printCutflow("$\\eq$1 Photon &  ", 8, cutEff_EMu_unweighted);
}

}

void printCutflow(string step, int bin, TH1D* cutFlow){
std::cout  << setprecision(6) << step  << cutFlow->GetBinContent(bin) << "  $\\pm$ " << setprecision(3) << cutFlow->GetBinError(bin) << "  \\\\ " << std::endl;
} 

void printCutEff(string step, int bin, TH1D* cutEff){
std::cout  << setprecision(6) << step  << cutEff->GetBinContent(bin) << "  $\\pm$ " << setprecision(3) << cutEff->GetBinError(bin) << "  \\\\ " << std::endl;
} 

/* void weightHisto(TH1D* sample, double lumi, double xsect, double NEvts){
sample->Scale(lumi*xsect/NEvts);
}

  */
