#include "TFile.h"
#include "TH1.h"
#include "TObject.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLegend.h"
#include "THStack.h"
#include "TMath.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "tdrstyle.C"

using namespace std;

void allCutFlow();
TH1D* getSample(TString sample, double weight, TString Variable);
TText* doPrelim(float x, float y, TString Channel);


void allCutFlow(){

double lumi = 5800;
//stuff to choose
bool logPlot = true; //true for log plot


// number of btags
TString Nbtags = "";  //standard  "2btags" , qcd "0btag"

//muon variables

//TString Variable = "TTbarMuMuRefSelection";   //"TTbarMuMuRefSelectionUnweighted"
//TString Variable = "TTbarEERefSelection";    
//TString step[10] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "m(Z) veto", "#geq 1 jet", "#geq 2 jets", "#slash{E_{T}} cut", "#geq1 CSV b-tag", "#geq1 Good Photon" , "1 Good Photon"};
//TString step_latex[10] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "m(Z) veto", "$\\geq$ 1 jets", "$\\geq$ 2 jets", "$\\slash{E_{T}}$ cut", "$\\geq$ 1 CSV b-tag", "$\\geq$ 1 Good Photon" , "1 Good Photon"};

//Emu probs best to put 2 cuts back in but no make them
TString Variable = "TTbarEMuRefSelection";
TString step[8] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "#geq 1 jets", "#geq 2 jets", "#geq1 CSV b-tag", "#geq1 Good Photon", "1 Good Photon" };		
TString step_latex[8] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "$\\geq$ 1 jets", "$\\geq$ 2 jets", "$\\geq$ 1 CSV b-tag", "$\\geq$ 1 Good Photon" , "1 Good Photon"};


setTDRStyle();

TString Xtitle = "Cuts";

//Data
TH1D* data;
if(Variable == "TTbarMuMuRefSelection")
data = getSample("DoubleMu", 1, Variable);
if(Variable == "TTbarEERefSelection")
data = getSample("DoubleElectron", 1, Variable);
if(Variable == "TTbarEMuRefSelection")
data = getSample("MuEG", 1, Variable);

//MC
TH1D* tt = getSample("TTJet", lumi*225.2/6920475, Variable);
TH1D* tt_gamma = getSample("TTGamma", lumi*225.2/6920475, Variable);
TH1D* wjets = getSample("WJetsToLNu", lumi*5400.0/23140779, Variable);
TH1D* zjets = getSample("DYJetsToLL", lumi*5745.25/30457954, Variable);
TH1D* qcd = getSample("QCD_All",     lumi*34679.3/8500505, Variable);
TH1D* single_t = getSample("SingleTop", lumi*56.4/3757707, Variable);
TH1D* diboson = getSample("DiBoson", lumi*56.4/3757707, Variable);

cout << "got samples" << endl;

THStack *hs = new THStack("hs","test");

  hs->Add(qcd);
  hs->Add(diboson);  
  hs->Add(zjets);
  hs->Add(wjets);
  hs->Add(single_t);
  hs->Add(tt);
  hs->Add(tt_gamma);
  

TH1D * allMC = (TH1D*) tt->Clone("all");
allMC->Add(tt_gamma);
allMC->Add(wjets);
allMC->Add(zjets);
allMC->Add(single_t);
allMC->Add(diboson);
allMC->Add(qcd);

TH1D* dataEff = new TH1D("data eff","data eff",9,0,9);
TH1D* mcEff = new TH1D("mc eff","mc eff",9,0,9);

mcEff->Sumw2();
dataEff->Sumw2();

for(int q =1; q<tt->GetNbinsX(); q++){
mcEff->GetXaxis()->SetBinLabel(q, step[q]);
dataEff->SetBinContent(q, data->GetBinContent(q+1)/data->GetBinContent(q));
dataEff->SetBinError(q, dataEff->GetBinContent(q)*sqrt(pow(data->GetBinError(q+1)/data->GetBinContent(q+1),2)+pow(data->GetBinError(q)/data->GetBinContent(q),2)));
mcEff->SetBinContent(q, allMC->GetBinContent(q+1)/allMC->GetBinContent(q));

}  

	
	TCanvas *c2 = new TCanvas("cutflow eff","cutflow eff",600, 500);
  	
	mcEff->SetLineColor(kRed);
	mcEff->Draw();
	dataEff->Draw("Esame");
	
	TLegend *tleg3;
	tleg3 = new TLegend(0.7,0.7,0.8,0.9);
	tleg3->SetTextSize(0.04);
	tleg3->SetBorderSize(0);
	tleg3->SetFillColor(10);
	tleg3->AddEntry(dataEff , "data", "l");
	tleg3->AddEntry(mcEff , "mc", "l");
	
	tleg3->Draw("same");
	
	c2->SaveAs("plots/cutFlow/cutEff_"+Variable+".pdf");
	c2->SaveAs("plots/cutFlow/cutEff_"+Variable+".png");
	delete c2;

  //draw histos to files
  TCanvas *c1 = new TCanvas("cutflow","cutflow",900, 600);

  hs->SetMaximum(data->GetBinContent(data->GetMaximumBin())*1.3);
  
  if(logPlot ==true)
  hs->SetMinimum(10.);

  hs->Draw("hist");
  
  for(int q =0; q<tt->GetNbinsX(); q++)
  hs->GetXaxis()->SetBinLabel(q+1, step[q]);
  
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
	tleg2->AddEntry(tt_gamma , "t#bar{t}+gamma", "lf");
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	tleg2->AddEntry(single_t, "single top", "lf");
	tleg2->AddEntry(wjets , "w+jets", "lf");
	tleg2->AddEntry(zjets , "z+jets", "lf");
	tleg2->AddEntry(diboson , "diboson", "lf");
	tleg2->AddEntry(qcd , "QCD", "lf");
	
	//tleg2->AddEntry(singtEff, "single-t"      , "l");
	//tleg2->AddEntry(singtwEff, "single-tW"      , "l");
 	tleg2->Draw("same");	
	
	TText* textPrelim = doPrelim(0.22,0.96, Variable);
	textPrelim->Draw();
	
  if(logPlot ==true){
  c1->SetLogy();
  }	
  
  TString plotName("plots/cutFlow/");
  
  if(logPlot ==true){
    plotName += Variable+"_Log";
    plotName += Nbtags;
    
  }else{
    plotName += Variable+"";  
    plotName += Nbtags;
  }
 
 
  c1->SaveAs(plotName+".png");
  c1->SaveAs(plotName+".pdf");
  delete c1;
 
 //print out
 
    std::cout.setf(std::ios::fixed);
    std::cout.precision(0);

 cout << "& ttgamma & ttbar & single-t  & wjets & zjets & diboson & qcd & all MC & data  \\\\" << endl; 
 
 for(int q = 0; q < tt->GetNbinsX(); q++){
 cout << step_latex[q] << " & " << tt_gamma->GetBinContent(q+1) << " $\\pm$ " << tt_gamma->GetBinError(q+1)  << " & " <<
 tt->GetBinContent(q+1) << " $\\pm$ " << tt->GetBinError(q+1)  << " & " << wjets->GetBinContent(q+1) << " $\\pm$ " <<
 wjets->GetBinError(q+1)  << " & " << zjets->GetBinContent(q+1) << " $\\pm$ " << zjets->GetBinError(q+1)  << " & " <<
 diboson->GetBinContent(q+1) << " $\\pm$ " << diboson->GetBinError(q+1)  << " & "<< single_t->GetBinContent(q+1) << " $\\pm$ "
 << single_t->GetBinError(q+1)  << " & " << qcd->GetBinContent(q+1) << " $\\pm$ " << qcd->GetBinError(q+1)  << " & " <<
 allMC->GetBinContent(q+1) << " $\\pm$ " << allMC->GetBinError(q+1)  << " & " << data->GetBinContent(q+1) << " $\\pm$ " <<
 data->GetBinError(q+1) << " \\\\ " << endl;
 
 }

  	
}


TH1D* getSample(TString sample, double weight,TString Variable){
	TString dir = "/data1/TTGammaAnalysis/HistogramFiles/Version3/central/";
	TFile* file = new TFile(dir + sample + "_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon.root");
	//TDirectoryFile* folder = (TDirectoryFile*) file->Get("TTbarPlusMetAnalysis/QCD No Iso/Muon/");
	
	TH1D* plot = (TH1D*) file->Get("EventCount/"+Variable);

        if(sample == "TTJet"){
	plot->SetFillColor(kRed+1);
        plot->SetLineColor(kRed+1);
	}else if(sample == "WJetsToLNu"){
	plot->SetLineColor(kGreen-3);	  
  	plot->SetFillColor(kGreen-3);
	}else if(sample == "DYJetsToLL"){
	plot->SetFillColor(kAzure-2);
	plot->SetLineColor(kAzure-2);
	}else if(sample == "QCD_All"){ 
	plot->SetLineColor(kYellow);
	plot->SetFillColor(kYellow);
	}else if(sample == "SingleTop"){
	plot->SetFillColor(kMagenta);
	plot->SetLineColor(kMagenta);
	}else if(sample == "DiBoson"){
	plot->SetFillColor(kGreen);
	plot->SetLineColor(kGreen);
	}else if(sample == "TTGamma"){
	plot->SetFillColor(kAzure+8);
	plot->SetLineColor(kAzure+8);
	}
	
	if(sample != "SingleMu")
	plot->Scale(19.605/19.584);
	//plot->Scale(weight);
	
	
	return plot;

}

TText* doPrelim(float x, float y, TString Channel)
{

  std::ostringstream stream;

  if(Channel == "TTbarMuMuRefSelection" || Channel == "TTbarMuMuRefSelectionUnweighted"){
  	stream << "#mu#mu                              CMS Preliminary, L = 19.6 fb^{-1}";
  }else if(Channel == "EE/"){
  	stream << "ee                              CMS Preliminary, L = 19.6 fb^{-1}";
  }else{
  	stream << "e#mu                              CMS Preliminary, L = 19.6 fb^{-1}";
  }
  
  TLatex* text = new TLatex(x, y, stream.str().c_str());
  //text->SetTextAlign(33);  //left
  //text->SetTextAlign(22);  //center
  //text->SetTextAlign(11);  //right
  text->SetNDC(true);
  text->SetTextFont(62);
  text->SetTextSize(0.045);  // for thesis

  return text;
}
