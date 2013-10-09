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
#include "getSample.C"

using namespace std;

void allCutFlow();
TText* dostuff(float x, float y, TString Channel);

void allCutFlow(){
setTDRStyle();
gROOT->SetBatch();

//stuff to choose
bool logPlot = true; //true for log plot

//choose object
// bool MuMu = true;
// bool EE = false;
// bool EMu = false;

TString Cut = "EventCount/";

TString Nbtags = "";
TString Obj = "";
TString RefSelection = "";
TString Type = "";
TString Next = "";
int RebinFact = 1;

TString Systematic = "central/";

//TString Variable = "TTbarMuMuRefSelection";   //"TTbarMuMuRefSelectionUnweighted"
//TString Variable = "TTbarEERefSelection";  
TString Variable = "TTbarEMuRefSelection"; 
 
TString Xtitle = "Cuts";

//if( Variable == "TTbarMuMuRefSelection" || Variable == "TTbarEERefSelection" )
//TString step[10] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "m(Z) veto", "#geq 1 jet", "#geq 2 jets", "#slash{E_{T}} cut", "#geq1 CSV b-tag", "#geq1 Good Photon" , "1 Good Photon"};
//TString step_latex[10] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "m(Z) veto", "$\\geq$ 1 jets", "$\\geq$ 2 jets", "$\\slash{E_{T}}$ cut", "$\\geq$ 1 CSV b-tag", "$\\geq$ 1 Good Photon" , "1 Good Photon"};
//if( Variable == "TTbarEMuRefSelection" )
TString step[8] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "#geq 1 jets", "#geq 2 jets", "#geq1 CSV b-tag", "#geq1 Good Photon", "1 Good Photon" };		
TString step_latex[8] = {"Skim" ,"Cleaning and HLT","Di-lepton Sel", "$\\geq$ 1 jets", "$\\geq$ 2 jets", "$\\geq$ 1 CSV b-tag", "$\\geq$ 1 Good Photon" , "1 Good Photon"};


//Data
if( Variable == "TTbarMuMuRefSelection" )
TH1D* data = getSample("DoubleMu", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
if( Variable == "TTbarEERefSelection" )
TH1D* data = getSample("DoubleElectron", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
if( Variable == "TTbarEMuRefSelection" )
TH1D* data = getSample("MuEG", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);

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
  
TH1D* DY = getSample("DYJetsToLL_M-10To50", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
  DY->Add(DY2);
  
TH1D* Diboson = getSample("ZZtoAnything",1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
  Diboson->Add(WW);
  Diboson->Add(WZ);
  
TH1D* SingleTop = getSample("T_tW-channel", 1, Obj, RefSelection, Type, Next, Variable, RebinFact, Systematic, Cut);
  SingleTop->Add(Tbar_tW); 
 
cout << "got samples" << endl;

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
  hs->Add(ttgamma);
  

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
  
TH1D* dataEff = new TH1D("data eff","data eff",9,0,9);
TH1D* mcEff = new TH1D("mc eff","mc eff",9,0,9);

mcEff->Sumw2();
dataEff->Sumw2();

for(int q =1; q<ttgamma->GetNbinsX(); q++){
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
  
  for(int q =0; q<ttgamma->GetNbinsX(); q++)
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
	tleg2->AddEntry(ttgamma , "t#bar{t}+gamma", "lf");
	tleg2->AddEntry(tt , "t#bar{t}", "lf");
	tleg2->AddEntry(T_tW, "single top", "lf");
	tleg2->AddEntry(DY1 , "Drell-Yan", "lf");
	tleg2->AddEntry(ZZ , "Di-boson", "lf");
	tleg2->AddEntry(wjets , "w+jets", "lf");
	tleg2->AddEntry(QCD_all , "QCD", "lf");
	
	//tleg2->AddEntry(singtEff, "single-t"      , "l");
	//tleg2->AddEntry(singtwEff, "single-tW"      , "l");
 	tleg2->Draw("same");	
	
	TText* textstuff = dostuff(0.22,0.96, Variable);
	textstuff->Draw();
	
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
 
 for(int q = 0; q < ttgamma->GetNbinsX(); q++){
 cout << step_latex[q] << " & " << ttgamma->GetBinContent(q+1) << " $\\pm$ " << ttgamma->GetBinError(q+1)  << " & " <<
 tt->GetBinContent(q+1) << " $\\pm$ " << tt->GetBinError(q+1)  << " & " << SingleTop->GetBinContent(q+1) << " $\\pm$ " <<
 SingleTop->GetBinError(q+1)  << " & " << DY->GetBinContent(q+1) << " $\\pm$ " << DY->GetBinError(q+1)  << " & " <<
 Diboson->GetBinContent(q+1) << " $\\pm$ " << Diboson->GetBinError(q+1)  << " & "<< wjets->GetBinContent(q+1) << " $\\pm$ "
 << wjets->GetBinError(q+1)  << " & " << QCD_all->GetBinContent(q+1) << " $\\pm$ " << QCD_all->GetBinError(q+1)  << " & " <<
 allMC->GetBinContent(q+1) << " $\\pm$ " << allMC->GetBinError(q+1)  << " & " << data->GetBinContent(q+1) << " $\\pm$ " <<
 data->GetBinError(q+1) << " \\\\ " << endl;
 
 }
  	
}
TText* dostuff(float x, float y, TString Channel)
{

  std::ostringstream stream;

  if(Channel == "TTbarMuMuRefSelection" || Channel == "TTbarMuMuRefSelectionUnweighted"){
  	stream << "#mu#mu                              CMS Preliminary, L = 19.6 fb^{-1}";
  }else if(Channel == "TTbarEERefSelection"){
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

