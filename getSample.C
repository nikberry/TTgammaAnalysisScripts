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
#include <sstream>
#include <iomanip>
#include "TROOT.h"

TH1D* getSample(TString sample, double weight, TString Obj, TString RefSelection, TString Type, TString Next, TString Variable, int RebinFact, TString Systematic, TString Cut);
//TH1D* getQCD(TString Obj, TString Variable, int RebinFact);
TText* doPrelim(float x, float y, TString Cut, TString Channel);


TH1D* getSample(TString sample, double weight, TString Obj, TString RefSelection, TString Type, TString Next, TString Variable, int RebinFact, TString Systematic, TString Cut){
	TString dir = "/data1/TTGammaAnalysis/HistogramFiles/Version3/"+ Systematic;
	
	TString syst = "";
	
	if(Systematic == "BJet_down")
		syst = "_minusBJet";
	else if(Systematic == "BJet_up")
		syst = "_plusBjet";
	else if(Systematic == "JES_down")
		syst = "_minusJES";
	else if(Systematic == "JES_up")
		syst = "_plusJES";
	else if(Systematic == "LightJet_up")
		syst = "_plusLightJet";	
	else if(Systematic == "LightJet_down")
		syst = "_minusLightJet";							
	else if(Systematic == "PU_down")
		syst = "_PU_65835mb";
	else if(Systematic == "PU_up")
		syst = "_PU_72765mb";
	else if(Systematic == "central")
		syst = "";	
	//else	
		//syst = "";
		
	TFile* file = new TFile(dir + sample + "_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon"+syst+".root");
	//TDirectoryFile* folder = (TDirectoryFile*) file->Get("TTbarPlusMetAnalysis/QCD No Iso/Muon/");

	cout << "file: "<< dir + sample + "_19584pb_PFElectron_PFMuon_PF2PATJets_patType1CorrectedPFMet_Photon"+syst+".root" << endl;
	cout << "folder: "<< Cut + Obj + RefSelection + Type + Next + Variable + "1btag" << endl;

	TH1D* plot;
	TH1D* plot1;
	TH1D* plot2;
	TH1D* plot3;
	TH1D* plot4;

	plot = (TH1D*)  file->Get(Cut + Obj + RefSelection + Type + Next + Variable + "1btag");
	plot2 = (TH1D*) file->Get(Cut + Obj + RefSelection + Type + Next + Variable + "2btags");
	plot3 = (TH1D*) file->Get(Cut + Obj + RefSelection + Type + Next + Variable + "3btags");
	plot4 = (TH1D*) file->Get(Cut + Obj + RefSelection + Type + Next + Variable + "4orMoreBtags");

	plot->Add(plot2);
	plot->Add(plot3);	
	plot->Add(plot4);


	if(sample == "TTGamma"){
	plot->SetFillColor(kAzure+8);
	plot->SetLineColor(kAzure+8);
        } else if(sample == "TTJet"){
	plot->SetFillColor(kRed+1);
        plot->SetLineColor(kRed+1);
	}else if(sample == "WJetsToLNu"){
	plot->SetLineColor(kGreen-3);	  
  	plot->SetFillColor(kGreen-3);
	}else if(sample == "DYJetsToLL_M-10To50" || sample == "DYJetsToLL_M-50"){
	plot->SetFillColor(kAzure-2);
	plot->SetLineColor(kAzure-2);
	}else if(sample == "ZZtoAnything"){
	plot->SetFillColor(kGreen);
	plot->SetLineColor(kGreen);
	}else if(sample == "WWtoAnything"){
	plot->SetFillColor(kGreen+1);
	plot->SetLineColor(kGreen+1);
	}else if(sample == "WZtoAnything"){
	plot->SetFillColor(kGreen+2);
	plot->SetLineColor(kGreen+2);
	}else if(sample == "QCD_Pt_20_MuEnrichedPt_15" || sample == "QCD_All"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_20_30_BCtoE"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_20_30_EMEnriched"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_30_80_BCtoE"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_30_80_EMEnriched"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_80_170_BCtoE"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "QCD_Pt_80_170_EMEnriched"){
	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
	}else if(sample == "T_tW-channel" || sample == "Tbar_tW-channel"){
	plot->SetFillColor(kMagenta);
	plot->SetLineColor(kMagenta);
	}else if(sample == "DoubleMu"){
	plot->SetLineColor(kBlack);	  
	}else if(sample == "DoubleElectron"){
	plot->SetLineColor(kBlack);	  
	}else if(sample == "MuEG"){
	plot->SetLineColor(kBlack);	  
	}

	//plot->Scale(weight);
	plot->Rebin(RebinFact);
	
	plot->SetDirectory(gROOT);
	file->Close();
	
	return plot;

}

/* //always data
TH1D* getQCD(TString Obj, TString Variable, int rebinFact){
	TString dir = "rootFiles/central/";
	TFile* file = new TFile(dir + "SingleMu_5814pb_PFElectron_PFMuon_PF2PATJets_PFMET.root");
	//TDirectoryFile* folder = (TDirectoryFile*) file->Get("TTbarPlusMetAnalysis/QCD No Iso/Muon/");
	
	TH1D* plot = (TH1D*) file->Get("TTbar_plus_X_analysis/MuPlusJets/QCD non iso mu+jets/"+Obj+Variable+"0btag");

	plot->SetFillColor(kYellow);
	plot->SetLineColor(kYellow);
    	
	plot->Scale(1/plot->Integral());
	plot->Rebin(rebinFact);
	
	plot->SetDirectory(gROOT);
	file->Close();
	
	return plot;

}
 */
TText* doPrelim(float x, float y, TString Cut, TString Channel)
{
  std::ostringstream stream;

  if(Channel == "MuMu/"){
  	stream << "#mu#mu";
  }else if(Channel == "EE/"){
  	stream << "ee";
  }else{
  	stream << "e#mu";
  }
  
  
  if(Cut == "TTbarDiLeptonAnalysis/"){
  	stream  << ", #geq 2 jets, #geq 1 b-tags                                             CMS Preliminary, L = 19.6 fb^{-1}";
  }else{
  	stream  << ", #geq 2 jets, #geq 1 b-tags, 1 #gamma                                   CMS Preliminary, L = 19.6 fb^{-1}";   
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
