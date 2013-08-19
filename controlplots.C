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

void doControlPlots();

//double lumi = 5500;
//stuff to choose
//bool logPlot = false; //true for log plot
int rebinFact = 5;

// number of btags
//TString Nbtags = "0btag";  //standard  "2btags" , qcd "0btag"

//choose object
TString Obj = "MuMu/";
//TString Obj = "EE/";


//MuMu variables
const int N = 12;
TString Variable;
TString Variables[N] = {"Photon_AbsEta_", "Photon_Eta_", "Photon_RhoCorrectedPFPhotonIso_barrel_", "Photon_RhoCorrectedPFPhotonIso_endcap_", "Photon_RhoCorrectedPFNeutralHadronIso_barrel_",
"Photon_RhoCorrectedPFNeutralHadronIso_endcap_", "Photon_RhoCorrectedPFChargedHadronIso_barrel_", "Photon_RhoCorrectedPFChargedHadronIso_endcap_", "Photon_Pt_", "Photon_Phi_", "Photon_sigma_ietaieta_", "Photon_HtowoE_"};
// double MinXs[N] = {0,-2.6 ,0 , 0, -3.4, 0};
// double MaxXs[N] = {2.6,2.6 ,0.5 , 400,3.2 , 0.3};
// TString XTitles[N] = {"#left|#eta#right|_{#mu}", "#eta_{#mu}", "RelIso_{#mu}", "p_{T}(#mu)", "#phi_{#mu}", "dB_{#mu}"};


void doControlPlots(){
setTDRStyle();

//loop over variables
for(int i = 0; i<N; i++){
//double MinX = MinXs[i];
//double MaxX = MaxXs[i];
Variable = Variables[i];
//TString Xtitle = XTitles[i];

//Data
TH1D* data = getSample("DoubleMu", 1, Obj, Variable, RebinFact, Systematic);

//MC
TH1D* tt = getSample("TTJet", 1, Obj, Variable, RebinFact, Systematic);
TH1D* wjets = getSample("WJetsToLNu", 1, Obj, Variable, RebinFact, Systematic);
TH1D* DY1 = getSample("DYJetsToLL_M-10To50", 1, Obj, Variable, RebinFact, Systematic);
TH1D* DY2 = getSample("DYJetsToLL_M-50", 1, Obj, Variable, RebinFact, Systematic);
TH1D* T_tW = getSample("T_tW-channel", Obj, 1, Variable, RebinFact, Systematic);
TH1D* Tbar_tW = getSample("Tbar_tw-channel",Obj, 1, Variable, RebinFact, Systematic );
//TH1D* qcd = getSample("QCD_Pt-120to170_Mu", lumi*34679.3/8500505);
//TH1D* qcd = getSample("QCD_Pt_20_MuEnrichedPt_15", lumi*34679.3/21484326);

THStack *hs = new THStack("hs","test");

  hs->Add(tt);
  hs->Add(wjets);
  hs->Add(DY1);
  hs->Add(DY2);
  hs->Add(T_tW); 
  hs->Add(Tbar_tW);
  
  //draw histos to files
  TCanvas *c1 = new TCanvas("Plot","Plot",900, 600);
		
  hs->SetMaximum(data->GetBinContent(data->GetMaximumBin())*1.3);

  hs->Draw();
  data->Draw("E same");
  data->SetMarkerStyle(20);
  
//  hs->GetXaxis()->SetLimits(MinX, MaxX);
  hs->GetXaxis()->SetTitle(Xtitle); hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitle("Number of Events");hs->GetYaxis()->SetTitleSize(0.05);
  
  
  	TLegend *tleg2;
	tleg2 = new TLegend(0.7,0.7,0.8,0.9);
	tleg2->SetTextSize(0.04);
	tleg2->SetBorderSize(0);
	tleg2->SetFillColor(10);
	tleg2->AddEntry(data , "2012 data", "lpe");
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	tleg2->AddEntry(wjets , "w+jets", "lf");
	tleg2->AddEntry(DY1 , "DYJetsToLL_M-10To50", "lf");
	tleg2->AddEntry(DY2 , "DYJetsToLL_M-50", "lf");
	tleg2->AddEntry(T_tW, "single-t"      , "l");
	tleg2->AddEntry(Tbar_tW, "anti-single-tW"      , "l");
 	tleg2->Draw("same");	

  if(logPlot == true){
  c1->SetLogy();
  }	
  
  TString plotName("plots/Control/PassesCutsUpToPhoton");
  
  if(logPlot == true){
    plotName += Variable+"_Log";
    plotName += Nbtags+".pdf";
    
  }else{
    plotName += Variable;  
    plotName += Nbtags+".pdf";
  }
 
 
  c1->SaveAs(plotName);
  delete c1;
  
  }
  	
}


/* TH1D* getSample(TString sample, double weight){
	TString dir = "rootFiles/";
	TFile* file = new TFile(dir + sample + "_5050pb_PFElectron_PFMuon_PF2PATJets_PFMET_FULL.root");
	//TDirectoryFile* folder = (TDirectoryFile*) file->Get("TTbarPlusMetAnalysis/QCD No Iso/Muon/");
	
	TH1D* plot = (TH1D*) file->Get("TTbarPlusMetAnalysis/MuPlusJets/"+Obj+Variable+Nbtags);

        if(sample == "TTJet"){
	plot->SetFillColor(kRed+1);
        plot->SetLineColor(kRed+1);
	}else if(sample == "WJetsToLNu"){
	plot->SetLineColor(kGreen-3);	  
  	plot->SetFillColor(kGreen-3);
	}else if(sample == "DYJetsToLL"){
	plot->SetFillColor(kAzure-2);
	plot->SetLineColor(kAzure-2);
	}else if(sample == "QCD_Pt-120to170_Mu"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}
	
	plot->Scale(weight);
	plot->Rebin(rebinFact);
	
	return plot;

} */


