#include "TFile.h"
#include "TH1.h"
#include "TH1D.h"
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
//#include "tdrstyle.C"

void printplots(){

//TFile* ttgamma = new TFile("TTJets_SemiLept_5050pb_PFElectron_PFMuon_PF2PATJets_PFMET_Photon_TEST.root");

//TFile ttgamma("TTJets_SemiLept_5050pb_PFElectron_PFMuon_PF2PATJets_PFMET_Photon_TEST.root");

TFile* ttgamma = TFile::Open("rootFiles/central/PassesCutsUpToMET/DoubleMu_19584pb_PFElectron_PFMuon_PF2PATJets_PFMET_Photon.root");

//Eta 
TH1D* etaMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Eta_0btag");
TH1D* etaMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Eta_1btag");
TH1D* etaMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Eta_2btags");
TH1D* etaMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Eta_3btags");
TH1D* etaMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Eta_4orMoreBtags");

etaMuMuSignalPhotons0histo->Add(etaMuMuSignalPhotons1histo);
etaMuMuSignalPhotons0histo->Add(etaMuMuSignalPhotons2histo);
etaMuMuSignalPhotons0histo->Add(etaMuMuSignalPhotons3histo);
etaMuMuSignalPhotons0histo->Add(etaMuMuSignalPhotons4histo);

TH1D* etaMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Eta_0btag");
TH1D* etaMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Eta_1btag");
TH1D* etaMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Eta_2btags");
TH1D* etaMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Eta_3btags");
TH1D* etaMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Eta_4orMoreBtags");

etaMuMuAllPhotons0histo->Add(etaMuMuAllPhotons1histo);
etaMuMuAllPhotons0histo->Add(etaMuMuAllPhotons2histo);
etaMuMuAllPhotons0histo->Add(etaMuMuAllPhotons3histo);
etaMuMuAllPhotons0histo->Add(etaMuMuAllPhotons4histo);

TH1D* etaEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Eta_0btag");
TH1D* etaEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Eta_1btag");
TH1D* etaEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Eta_2btags");
TH1D* etaEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Eta_3btags");
TH1D* etaEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Eta_4orMoreBtags");

etaEESignalPhotons0histo->Add(etaEESignalPhotons1histo);
etaEESignalPhotons0histo->Add(etaEESignalPhotons2histo);
etaEESignalPhotons0histo->Add(etaEESignalPhotons3histo);
etaEESignalPhotons0histo->Add(etaEESignalPhotons4histo);

TH1D* etaEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Eta_0btag");
TH1D* etaEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Eta_1btag");
TH1D* etaEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Eta_2btags");
TH1D* etaEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Eta_3btags");
TH1D* etaEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Eta_4orMoreBtags");

etaEEAllPhotons0histo->Add(etaEEAllPhotons1histo);
etaEEAllPhotons0histo->Add(etaEEAllPhotons2histo);
etaEEAllPhotons0histo->Add(etaEEAllPhotons3histo);
etaEEAllPhotons0histo->Add(etaEEAllPhotons4histo);

TCanvas* etaMuMuSignalPhotons = new TCanvas("etaMuMuSignalPhotons");

etaMuMuSignalPhotons0histo->Draw();

etaMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/eta/eta.pdf");

TCanvas* etaMuMuAllPhotons = new TCanvas("etaMuMuAllPhotons");

etaMuMuAllPhotons0histo->Draw();

etaMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/eta/eta.pdf");

TCanvas* etaEESignalPhotons = new TCanvas("etaEESignalPhotons");

etaEESignalPhotons0histo->Draw();

etaEESignalPhotons->SaveAs("plots/EE/SignalPhotons/eta/eta.pdf");

TCanvas* etaEEAllPhotons = new TCanvas("etaEEAllPhotons");

etaEEAllPhotons0histo->Draw();

etaEEAllPhotons->SaveAs("plots/EE/AllPhotons/eta/eta.pdf");

//Pt
TH1D* ptMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Pt_0btag");
TH1D* ptMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Pt_1btag");
TH1D* ptMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Pt_2btags");
TH1D* ptMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Pt_3btags");
TH1D* ptMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Pt_4orMoreBtags");

ptMuMuSignalPhotons0histo->Add(ptMuMuSignalPhotons1histo);
ptMuMuSignalPhotons0histo->Add(ptMuMuSignalPhotons2histo);
ptMuMuSignalPhotons0histo->Add(ptMuMuSignalPhotons3histo);
ptMuMuSignalPhotons0histo->Add(ptMuMuSignalPhotons4histo);

TH1D* ptMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Pt_0btag");
TH1D* ptMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Pt_1btag");
TH1D* ptMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Pt_2btags");
TH1D* ptMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Pt_3btags");
TH1D* ptMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Pt_4orMoreBtags");

ptMuMuAllPhotons0histo->Add(ptMuMuAllPhotons1histo);
ptMuMuAllPhotons0histo->Add(ptMuMuAllPhotons2histo);
ptMuMuAllPhotons0histo->Add(ptMuMuAllPhotons3histo);
ptMuMuAllPhotons0histo->Add(ptMuMuAllPhotons4histo);

TH1D* ptEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Pt_0btag");
TH1D* ptEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Pt_1btag");
TH1D* ptEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Pt_2btags");
TH1D* ptEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Pt_3btags");
TH1D* ptEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Pt_4orMoreBtags");

ptEESignalPhotons0histo->Add(ptEESignalPhotons1histo);
ptEESignalPhotons0histo->Add(ptEESignalPhotons2histo);
ptEESignalPhotons0histo->Add(ptEESignalPhotons3histo);
ptEESignalPhotons0histo->Add(ptEESignalPhotons4histo);

TH1D* ptEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Pt_0btag");
TH1D* ptEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Pt_1btag");
TH1D* ptEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Pt_2btags");
TH1D* ptEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Pt_3btags");
TH1D* ptEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Pt_4orMoreBtags");

ptEEAllPhotons0histo->Add(ptEEAllPhotons1histo);
ptEEAllPhotons0histo->Add(ptEEAllPhotons2histo);
ptEEAllPhotons0histo->Add(ptEEAllPhotons3histo);
ptEEAllPhotons0histo->Add(ptEEAllPhotons4histo);

TCanvas* ptMuMuSignalPhotons = new TCanvas("ptMuMuSignalPhotons");

ptMuMuSignalPhotons0histo->Draw();

ptMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/pt/pt.pdf");

TCanvas* ptMuMuAllPhotons = new TCanvas("ptMuMuAllPhotons");

ptMuMuAllPhotons0histo->Draw();

ptMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/pt/pt.pdf");

TCanvas* ptEESignalPhotons = new TCanvas("ptEESignalPhotons");

ptEESignalPhotons0histo->Draw();

ptEESignalPhotons->SaveAs("plots/EE/SignalPhotons/pt/pt.pdf");

TCanvas* ptEEAllPhotons = new TCanvas("ptEEAllPhotons");

ptEEAllPhotons0histo->Draw();

ptEEAllPhotons->SaveAs("plots/EE/AllPhotons/pt/pt.pdf");

TCanvas* logptMuMuSignalPhotons = new TCanvas("logptMuMuSignalPhotons");

logptMuMuSignalPhotons->SetLogy();
ptMuMuSignalPhotons0histo->Draw();

logptMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/pt/logpt.pdf");

TCanvas* logptMuMuAllPhotons = new TCanvas("logptMuMuAllPhotons");

logptMuMuAllPhotons->SetLogy();
ptMuMuAllPhotons0histo->Draw();

logptMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/pt/logpt.pdf");

TCanvas* logptEESignalPhotons = new TCanvas("logptEESignalPhotons");

logptEESignalPhotons->SetLogy();
ptEESignalPhotons0histo->Draw();

logptEESignalPhotons->SaveAs("plots/EE/SignalPhotons/pt/logpt.pdf");

TCanvas* logptEEAllPhotons = new TCanvas("logptEEAllPhotons");

logptEEAllPhotons->SetLogy();
ptEEAllPhotons0histo->Draw();

logptEEAllPhotons->SaveAs("plots/EE/AllPhotons/pt/logpt.pdf");

//Et
TH1D* etMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_ET_0btag");
TH1D* etMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_ET_1btag");
TH1D* etMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_ET_2btags");
TH1D* etMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_ET_3btags");
TH1D* etMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_ET_4orMoreBtags");

etMuMuSignalPhotons0histo->Add(etMuMuSignalPhotons1histo);
etMuMuSignalPhotons0histo->Add(etMuMuSignalPhotons2histo);
etMuMuSignalPhotons0histo->Add(etMuMuSignalPhotons3histo);
etMuMuSignalPhotons0histo->Add(etMuMuSignalPhotons4histo);

TH1D* etMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_ET_0btag");
TH1D* etMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_ET_1btag");
TH1D* etMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_ET_2btags");
TH1D* etMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_ET_3btags");
TH1D* etMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_ET_4orMoreBtags");

etMuMuAllPhotons0histo->Add(etMuMuAllPhotons1histo);
etMuMuAllPhotons0histo->Add(etMuMuAllPhotons2histo);
etMuMuAllPhotons0histo->Add(etMuMuAllPhotons3histo);
etMuMuAllPhotons0histo->Add(etMuMuAllPhotons4histo);

TH1D* etEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_ET_0btag");
TH1D* etEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_ET_1btag");
TH1D* etEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_ET_2btags");
TH1D* etEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_ET_3btags");
TH1D* etEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_ET_4orMoreBtags");

etEESignalPhotons0histo->Add(etEESignalPhotons1histo);
etEESignalPhotons0histo->Add(etEESignalPhotons2histo);
etEESignalPhotons0histo->Add(etEESignalPhotons3histo);
etEESignalPhotons0histo->Add(etEESignalPhotons4histo);

TH1D* etEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_ET_0btag");
TH1D* etEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_ET_1btag");
TH1D* etEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_ET_2btags");
TH1D* etEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_ET_3btags");
TH1D* etEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_ET_4orMoreBtags");

etEEAllPhotons0histo->Add(etEEAllPhotons1histo);
etEEAllPhotons0histo->Add(etEEAllPhotons2histo);
etEEAllPhotons0histo->Add(etEEAllPhotons3histo);
etEEAllPhotons0histo->Add(etEEAllPhotons4histo);

TCanvas* etMuMuSignalPhotons = new TCanvas("etMuMuSignalPhotons");

etMuMuSignalPhotons0histo->Draw();

etMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/et/et.pdf");

TCanvas* etMuMuAllPhotons = new TCanvas("etMuMuAllPhotons");

etMuMuAllPhotons0histo->Draw();

etMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/et/et.pdf");

TCanvas* etEESignalPhotons = new TCanvas("etEESignalPhotons");

etEESignalPhotons0histo->Draw();

etEESignalPhotons->SaveAs("plots/EE/SignalPhotons/et/et.pdf");

TCanvas* etEEAllPhotons = new TCanvas("etEEAllPhotons");

etEEAllPhotons0histo->Draw();

etEEAllPhotons->SaveAs("plots/EE/AllPhotons/et/et.pdf");

TCanvas* logetMuMuSignalPhotons = new TCanvas("logetMuMuSignalPhotons");

logetMuMuSignalPhotons->SetLogy();
etMuMuSignalPhotons0histo->Draw();

logetMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/et/loget.pdf");

TCanvas* logetMuMuAllPhotons = new TCanvas("logetMuMuAllPhotons");

logetMuMuAllPhotons->SetLogy();
etMuMuAllPhotons0histo->Draw();

logetMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/et/loget.pdf");

TCanvas* logetEESignalPhotons = new TCanvas("logetEESignalPhotons");

logetEESignalPhotons->SetLogy();
etEESignalPhotons0histo->Draw();

logetEESignalPhotons->SaveAs("plots/EE/SignalPhotons/et/loget.pdf");

TCanvas* logetEEAllPhotons = new TCanvas("logetEEAllPhotons");

logetEEAllPhotons->SetLogy();
etEEAllPhotons0histo->Draw();

logetEEAllPhotons->SaveAs("plots/EE/AllPhotons/et/loget.pdf");

//sigmaIetaIeta endcap
TH1D* sigmaietaietaendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_endcap_0btag");
TH1D* sigmaietaietaendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_endcap_1btag");
TH1D* sigmaietaietaendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_endcap_2btags");
TH1D* sigmaietaietaendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_endcap_3btags");
TH1D* sigmaietaietaendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_endcap_4orMoreBtags");

sigmaietaietaendcapMuMuSignalPhotons0histo->Add(sigmaietaietaendcapMuMuSignalPhotons1histo);
sigmaietaietaendcapMuMuSignalPhotons0histo->Add(sigmaietaietaendcapMuMuSignalPhotons2histo);
sigmaietaietaendcapMuMuSignalPhotons0histo->Add(sigmaietaietaendcapMuMuSignalPhotons3histo);
sigmaietaietaendcapMuMuSignalPhotons0histo->Add(sigmaietaietaendcapMuMuSignalPhotons4histo);

TH1D* sigmaietaietaendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_endcap_0btag");
TH1D* sigmaietaietaendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_endcap_1btag");
TH1D* sigmaietaietaendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_endcap_2btags");
TH1D* sigmaietaietaendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_endcap_3btags");
TH1D* sigmaietaietaendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_endcap_4orMoreBtags");

sigmaietaietaendcapMuMuAllPhotons0histo->Add(sigmaietaietaendcapMuMuAllPhotons1histo);
sigmaietaietaendcapMuMuAllPhotons0histo->Add(sigmaietaietaendcapMuMuAllPhotons2histo);
sigmaietaietaendcapMuMuAllPhotons0histo->Add(sigmaietaietaendcapMuMuAllPhotons3histo);
sigmaietaietaendcapMuMuAllPhotons0histo->Add(sigmaietaietaendcapMuMuAllPhotons4histo);

TH1D* sigmaietaietaendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_endcap_0btag");
TH1D* sigmaietaietaendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_endcap_1btag");
TH1D* sigmaietaietaendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_endcap_2btags");
TH1D* sigmaietaietaendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_endcap_3btags");
TH1D* sigmaietaietaendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_endcap_4orMoreBtags");

sigmaietaietaendcapEESignalPhotons0histo->Add(sigmaietaietaendcapEESignalPhotons1histo);
sigmaietaietaendcapEESignalPhotons0histo->Add(sigmaietaietaendcapEESignalPhotons2histo);
sigmaietaietaendcapEESignalPhotons0histo->Add(sigmaietaietaendcapEESignalPhotons3histo);
sigmaietaietaendcapEESignalPhotons0histo->Add(sigmaietaietaendcapEESignalPhotons4histo);

TH1D* sigmaietaietaendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_endcap_0btag");
TH1D* sigmaietaietaendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_endcap_1btag");
TH1D* sigmaietaietaendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_endcap_2btags");
TH1D* sigmaietaietaendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_endcap_3btags");
TH1D* sigmaietaietaendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_endcap_4orMoreBtags");

sigmaietaietaendcapEEAllPhotons0histo->Add(sigmaietaietaendcapEEAllPhotons1histo);
sigmaietaietaendcapEEAllPhotons0histo->Add(sigmaietaietaendcapEEAllPhotons2histo);
sigmaietaietaendcapEEAllPhotons0histo->Add(sigmaietaietaendcapEEAllPhotons3histo);
sigmaietaietaendcapEEAllPhotons0histo->Add(sigmaietaietaendcapEEAllPhotons4histo);

TCanvas* sigmaietaietaendcapMuMuSignalPhotons = new TCanvas("sigmaietaietaendcapMuMuSignalPhotons");

sigmaietaietaendcapMuMuSignalPhotons0histo->Draw();

sigmaietaietaendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/sigmaietaieta/sigmaietaieta_endcap.pdf");

TCanvas* sigmaietaietaendcapMuMuAllPhotons = new TCanvas("sigmaietaietaendcapMuMuAllPhotons");

sigmaietaietaendcapMuMuAllPhotons0histo->Draw();

sigmaietaietaendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/sigmaietaieta/sigmaietaieta_endcap.pdf");

TCanvas* sigmaietaietaendcapEESignalPhotons = new TCanvas("sigmaietaietaendcapEESignalPhotons");

sigmaietaietaendcapEESignalPhotons0histo->Draw();

sigmaietaietaendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/sigmaietaieta/sigmaietaieta_endcap.pdf");

TCanvas* sigmaietaietaendcapEEAllPhotons = new TCanvas("sigmaietaietaendcapEEAllPhotons");

sigmaietaietaendcapEEAllPhotons0histo->Draw();

sigmaietaietaendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/sigmaietaieta/sigmaietaieta_endcap.pdf");

//sigmaietaieta barrel
TH1D* sigmaietaietabarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_barrel_0btag");
TH1D* sigmaietaietabarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_barrel_1btag");
TH1D* sigmaietaietabarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_barrel_2btags");
TH1D* sigmaietaietabarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_barrel_3btags");
TH1D* sigmaietaietabarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_sigma_ietaieta_barrel_4orMoreBtags");

sigmaietaietabarrelMuMuSignalPhotons0histo->Add(sigmaietaietabarrelMuMuSignalPhotons1histo);
sigmaietaietabarrelMuMuSignalPhotons0histo->Add(sigmaietaietabarrelMuMuSignalPhotons2histo);
sigmaietaietabarrelMuMuSignalPhotons0histo->Add(sigmaietaietabarrelMuMuSignalPhotons3histo);
sigmaietaietabarrelMuMuSignalPhotons0histo->Add(sigmaietaietabarrelMuMuSignalPhotons4histo);

TH1D* sigmaietaietabarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_barrel_0btag");
TH1D* sigmaietaietabarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_barrel_1btag");
TH1D* sigmaietaietabarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_barrel_2btags");
TH1D* sigmaietaietabarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_barrel_3btags");
TH1D* sigmaietaietabarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_sigma_ietaieta_barrel_4orMoreBtags");

sigmaietaietabarrelMuMuAllPhotons0histo->Add(sigmaietaietabarrelMuMuAllPhotons1histo);
sigmaietaietabarrelMuMuAllPhotons0histo->Add(sigmaietaietabarrelMuMuAllPhotons2histo);
sigmaietaietabarrelMuMuAllPhotons0histo->Add(sigmaietaietabarrelMuMuAllPhotons3histo);
sigmaietaietabarrelMuMuAllPhotons0histo->Add(sigmaietaietabarrelMuMuAllPhotons4histo);

TH1D* sigmaietaietabarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_barrel_0btag");
TH1D* sigmaietaietabarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_barrel_1btag");
TH1D* sigmaietaietabarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_barrel_2btags");
TH1D* sigmaietaietabarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_barrel_3btags");
TH1D* sigmaietaietabarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_sigma_ietaieta_barrel_4orMoreBtags");

sigmaietaietabarrelEESignalPhotons0histo->Add(sigmaietaietabarrelEESignalPhotons1histo);
sigmaietaietabarrelEESignalPhotons0histo->Add(sigmaietaietabarrelEESignalPhotons2histo);
sigmaietaietabarrelEESignalPhotons0histo->Add(sigmaietaietabarrelEESignalPhotons3histo);
sigmaietaietabarrelEESignalPhotons0histo->Add(sigmaietaietabarrelEESignalPhotons4histo);

TH1D* sigmaietaietabarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_barrel_0btag");
TH1D* sigmaietaietabarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_barrel_1btag");
TH1D* sigmaietaietabarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_barrel_2btags");
TH1D* sigmaietaietabarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_barrel_3btags");
TH1D* sigmaietaietabarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_sigma_ietaieta_barrel_4orMoreBtags");

sigmaietaietabarrelEEAllPhotons0histo->Add(sigmaietaietabarrelEEAllPhotons1histo);
sigmaietaietabarrelEEAllPhotons0histo->Add(sigmaietaietabarrelEEAllPhotons2histo);
sigmaietaietabarrelEEAllPhotons0histo->Add(sigmaietaietabarrelEEAllPhotons3histo);
sigmaietaietabarrelEEAllPhotons0histo->Add(sigmaietaietabarrelEEAllPhotons4histo);

TCanvas* sigmaietaietabarrelMuMuSignalPhotons = new TCanvas("sigmaietaietabarrelMuMuSignalPhotons");

sigmaietaietabarrelMuMuSignalPhotons0histo->Draw();

sigmaietaietabarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/sigmaietaieta/sigmaietaieta_barrel.pdf");

TCanvas* sigmaietaietabarrelMuMuAllPhotons = new TCanvas("sigmaietaietabarrelMuMuAllPhotons");

sigmaietaietabarrelMuMuAllPhotons0histo->Draw();

sigmaietaietabarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/sigmaietaieta/sigmaietaieta_barrel.pdf");

TCanvas* sigmaietaietabarrelEESignalPhotons = new TCanvas("sigmaietaietabarrelEESignalPhotons");

sigmaietaietabarrelEESignalPhotons0histo->Draw();

sigmaietaietabarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/sigmaietaieta/sigmaietaieta_barrel.pdf");

TCanvas* sigmaietaietabarrelEEAllPhotons = new TCanvas("sigmaietaietabarrelEEAllPhotons");

sigmaietaietabarrelEEAllPhotons0histo->Draw();

sigmaietaietabarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/sigmaietaieta/sigmaietaieta_barrel.pdf");

//Number of Vertices
TH1D* nVertices = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Vertices/nVertex_reweighted");

//leading jet Pt
TH1D* ljetpt0histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_pT_0btag");
TH1D* ljetpt1histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_pT_1btag");
TH1D* ljetpt2histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_pT_2btags");
TH1D* ljetpt3histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_pT_3btags");
TH1D* ljetpt4histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_pT_4orMoreBtags");

ljetpt0histo->Add(ljetpt1histo);
ljetpt0histo->Add(ljetpt1histo);
ljetpt0histo->Add(ljetpt3histo);
ljetpt0histo->Add(ljetpt4histo);

TCanvas* leadingjetpt = new TCanvas("leadingjetpt");

ljetpt0histo->Draw();

leadingjetpt->SaveAs("plots/MuMu/SignalPhotons/leadingjetpt/leadingjetpt.pdf");
leadingjetpt->SaveAs("plots/MuMu/AllPhotons/leadingjetpt/leadingjetpt.pdf");
leadingjetpt->SaveAs("plots/EE/SignalPhotons/leadingjetpt/leadingjetpt.pdf");
leadingjetpt->SaveAs("plots/EE/AllPhotons/leadingjetpt/leadingjetpt.pdf");

//leading jet Et
TH1D* ljeteta0histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_eta_0btag");
TH1D* ljeteta1histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_eta_1btag");
TH1D* ljeteta2histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_eta_2btags");
TH1D* ljeteta3histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_eta_3btags");
TH1D* ljeteta4histo = (TH1D*)ttgamma->Get("TTbar_plus_X_analysis/EPlusJets/Ref selection/Jets/jet1_eta_4orMoreBtags");

ljeteta0histo->Add(ljeteta1histo);
ljeteta0histo->Add(ljeteta1histo);
ljeteta0histo->Add(ljeteta3histo);
ljeteta0histo->Add(ljeteta4histo);

TCanvas* leadingjeteta = new TCanvas("leadingjeteta");

ljeteta0histo->Draw();

leadingjeteta->SaveAs("plots/MuMu/SignalPhotons/leadingjeteta/leadingjeteta.pdf");
leadingjeteta->SaveAs("plots/MuMu/AllPhotons/leadingjeteta/leadingjeteta.pdf");
leadingjeteta->SaveAs("plots/EE/SignalPhotons/leadingjeteta/leadingjeteta.pdf");
leadingjeteta->SaveAs("plots/EE/AllPhotons/leadingjeteta/leadingjeteta.pdf");

//Delta R (gamma, jets)
TH1D* deltaRgammajetsMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_jets_0btag");
TH1D* deltaRgammajetsMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_jets_1btag");
TH1D* deltaRgammajetsMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_jets_2btags");
TH1D* deltaRgammajetsMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_jets_3btags");
TH1D* deltaRgammajetsMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_jets_4orMoreBtags");

deltaRgammajetsMuMuSignalPhotons0histo->Add(deltaRgammajetsMuMuSignalPhotons1histo);
deltaRgammajetsMuMuSignalPhotons0histo->Add(deltaRgammajetsMuMuSignalPhotons2histo);
deltaRgammajetsMuMuSignalPhotons0histo->Add(deltaRgammajetsMuMuSignalPhotons3histo);
deltaRgammajetsMuMuSignalPhotons0histo->Add(deltaRgammajetsMuMuSignalPhotons4histo);

TH1D* deltaRgammajetsMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_jets_0btag");
TH1D* deltaRgammajetsMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_jets_1btag");
TH1D* deltaRgammajetsMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_jets_2btags");
TH1D* deltaRgammajetsMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_jets_3btags");
TH1D* deltaRgammajetsMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_jets_4orMoreBtags");

deltaRgammajetsMuMuAllPhotons0histo->Add(deltaRgammajetsMuMuAllPhotons1histo);
deltaRgammajetsMuMuAllPhotons0histo->Add(deltaRgammajetsMuMuAllPhotons2histo);
deltaRgammajetsMuMuAllPhotons0histo->Add(deltaRgammajetsMuMuAllPhotons3histo);
deltaRgammajetsMuMuAllPhotons0histo->Add(deltaRgammajetsMuMuAllPhotons4histo);

TH1D* deltaRgammajetsEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_jets_0btag");
TH1D* deltaRgammajetsEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_jets_1btag");
TH1D* deltaRgammajetsEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_jets_2btags");
TH1D* deltaRgammajetsEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_jets_3btags");
TH1D* deltaRgammajetsEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_jets_4orMoreBtags");

deltaRgammajetsEESignalPhotons0histo->Add(deltaRgammajetsEESignalPhotons1histo);
deltaRgammajetsEESignalPhotons0histo->Add(deltaRgammajetsEESignalPhotons2histo);
deltaRgammajetsEESignalPhotons0histo->Add(deltaRgammajetsEESignalPhotons3histo);
deltaRgammajetsEESignalPhotons0histo->Add(deltaRgammajetsEESignalPhotons4histo);

TH1D* deltaRgammajetsEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_jets_0btag");
TH1D* deltaRgammajetsEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_jets_1btag");
TH1D* deltaRgammajetsEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_jets_2btags");
TH1D* deltaRgammajetsEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_jets_3btags");
TH1D* deltaRgammajetsEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_jets_4orMoreBtags");

deltaRgammajetsEEAllPhotons0histo->Add(deltaRgammajetsEEAllPhotons1histo);
deltaRgammajetsEEAllPhotons0histo->Add(deltaRgammajetsEEAllPhotons2histo);
deltaRgammajetsEEAllPhotons0histo->Add(deltaRgammajetsEEAllPhotons3histo);
deltaRgammajetsEEAllPhotons0histo->Add(deltaRgammajetsEEAllPhotons4histo);

TCanvas* deltaRgammajetsMuMuSignalPhotons = new TCanvas("deltaRgammajetsMuMuSignalPhotons");

deltaRgammajetsMuMuSignalPhotons0histo->Draw();

deltaRgammajetsMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/deltaRgammajets/deltaRgammajets.pdf");

TCanvas* deltaRgammajetsMuMuAllPhotons = new TCanvas("deltaRgammajetsMuMuAllPhotons");

deltaRgammajetsMuMuAllPhotons0histo->Draw();

deltaRgammajetsMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/deltaRgammajets/deltaRgammajets.pdf");

TCanvas* deltaRgammajetsEESignalPhotons = new TCanvas("deltaRgammajetsEESignalPhotons");

deltaRgammajetsEESignalPhotons0histo->Draw();

deltaRgammajetsEESignalPhotons->SaveAs("plots/EE/SignalPhotons/deltaRgammajets/deltaRgammajets.pdf");

TCanvas* deltaRgammajetsEEAllPhotons = new TCanvas("deltaRgammajetsEEAllPhotons");

deltaRgammajetsEEAllPhotons0histo->Draw();

deltaRgammajetsEEAllPhotons->SaveAs("plots/EE/AllPhotons/deltaRgammajets/deltaRgammajets.pdf");

//Delta R (gamma, electrons)
TH1D* deltaRgammaelectronsMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_electrons_0btag");
TH1D* deltaRgammaelectronsMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_electrons_1btag");
TH1D* deltaRgammaelectronsMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_electrons_2btags");
TH1D* deltaRgammaelectronsMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_electrons_3btags");
TH1D* deltaRgammaelectronsMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_deltaR_electrons_4orMoreBtags");

deltaRgammaelectronsMuMuSignalPhotons0histo->Add(deltaRgammaelectronsMuMuSignalPhotons1histo);
deltaRgammaelectronsMuMuSignalPhotons0histo->Add(deltaRgammaelectronsMuMuSignalPhotons2histo);
deltaRgammaelectronsMuMuSignalPhotons0histo->Add(deltaRgammaelectronsMuMuSignalPhotons3histo);
deltaRgammaelectronsMuMuSignalPhotons0histo->Add(deltaRgammaelectronsMuMuSignalPhotons4histo);

TH1D* deltaRgammaelectronsMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_electrons_0btag");
TH1D* deltaRgammaelectronsMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_electrons_1btag");
TH1D* deltaRgammaelectronsMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_electrons_2btags");
TH1D* deltaRgammaelectronsMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_electrons_3btags");
TH1D* deltaRgammaelectronsMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_deltaR_electrons_4orMoreBtags");

deltaRgammaelectronsMuMuAllPhotons0histo->Add(deltaRgammaelectronsMuMuAllPhotons1histo);
deltaRgammaelectronsMuMuAllPhotons0histo->Add(deltaRgammaelectronsMuMuAllPhotons2histo);
deltaRgammaelectronsMuMuAllPhotons0histo->Add(deltaRgammaelectronsMuMuAllPhotons3histo);
deltaRgammaelectronsMuMuAllPhotons0histo->Add(deltaRgammaelectronsMuMuAllPhotons4histo);

TH1D* deltaRgammaelectronsEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_electrons_0btag");
TH1D* deltaRgammaelectronsEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_electrons_1btag");
TH1D* deltaRgammaelectronsEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_electrons_2btags");
TH1D* deltaRgammaelectronsEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_electrons_3btags");
TH1D* deltaRgammaelectronsEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_deltaR_electrons_4orMoreBtags");

deltaRgammaelectronsEESignalPhotons0histo->Add(deltaRgammaelectronsEESignalPhotons1histo);
deltaRgammaelectronsEESignalPhotons0histo->Add(deltaRgammaelectronsEESignalPhotons2histo);
deltaRgammaelectronsEESignalPhotons0histo->Add(deltaRgammaelectronsEESignalPhotons3histo);
deltaRgammaelectronsEESignalPhotons0histo->Add(deltaRgammaelectronsEESignalPhotons4histo);

TH1D* deltaRgammaelectronsEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_electrons_0btag");
TH1D* deltaRgammaelectronsEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_electrons_1btag");
TH1D* deltaRgammaelectronsEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_electrons_2btags");
TH1D* deltaRgammaelectronsEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_electrons_3btags");
TH1D* deltaRgammaelectronsEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_deltaR_electrons_4orMoreBtags");

deltaRgammaelectronsEEAllPhotons0histo->Add(deltaRgammaelectronsEEAllPhotons1histo);
deltaRgammaelectronsEEAllPhotons0histo->Add(deltaRgammaelectronsEEAllPhotons2histo);
deltaRgammaelectronsEEAllPhotons0histo->Add(deltaRgammaelectronsEEAllPhotons3histo);
deltaRgammaelectronsEEAllPhotons0histo->Add(deltaRgammaelectronsEEAllPhotons4histo);

TCanvas* deltaRgammaelectronsMuMuSignalPhotons = new TCanvas("deltaRgammaelectronsMuMuSignalPhotons");

deltaRgammaelectronsMuMuSignalPhotons0histo->Draw();

deltaRgammaelectronsMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/deltaRgammaelectrons/deltaRgammaelectrons.pdf");

TCanvas* deltaRgammaelectronsMuMuAllPhotons = new TCanvas("deltaRgammaelectronsMuMuAllPhotons");

deltaRgammaelectronsMuMuAllPhotons0histo->Draw();

deltaRgammaelectronsMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/deltaRgammaelectrons/deltaRgammaelectrons.pdf");

TCanvas* deltaRgammaelectronsEESignalPhotons = new TCanvas("deltaRgammaelectronsEESignalPhotons");

deltaRgammaelectronsEESignalPhotons0histo->Draw();

deltaRgammaelectronsEESignalPhotons->SaveAs("plots/EE/SignalPhotons/deltaRgammaelectrons/deltaRgammaelectrons.pdf");

TCanvas* deltaRgammaelectronsEEAllPhotons = new TCanvas("deltaRgammaelectronsEEAllPhotons");

deltaRgammaelectronsEEAllPhotons0histo->Draw();

deltaRgammaelectronsEEAllPhotons->SaveAs("plots/EE/AllPhotons/deltaRgammaelectrons/deltaRgammaelectrons.pdf");



//Cut Flow MuMu
TH1D* cutflow_MuMu_singlecuts = (TH1D*)ttgamma->Get("EventCount/TTbarMuMuRefSelection_singleCuts");
TH1D* cutflow_MuMu_unweighted_singlecuts = (TH1D*)ttgamma->Get("EventCount/TTbarMuMuRefSelectionUnweighted_singleCuts");
TH1D* cutflow_MuMu = (TH1D*)ttgamma->Get("EventCount/TTbarMuMuRefSelection");
TH1D* cutflow_MuMu_unweighted = (TH1D*)ttgamma->Get("EventCount/TTbarMuMuRefSelectionUnweighted");

TCanvas* cutFlowMuMu_singlecuts = new TCanvas("cutFlowMuMu_singlecuts");

cutflow_MuMu_singlecuts->Draw();

cutFlowMuMu_singlecuts->SaveAs("plots/MuMu/SignalPhotons/cutFlow/TTbarMuMuRefSelection_singlecuts.pdf");

TCanvas* cutFlowMuMu_singlecutsall = new TCanvas("cutFlowMuMu_singlecutsall");

cutflow_MuMu_singlecuts->Draw();

cutFlowMuMu_singlecutsall->SaveAs("plots/MuMu/AllPhotons/cutFlow/TTbarMuMuRefSelection_singlecuts.pdf");

TCanvas* cutFlowMuMuUnweighted_singlecuts = new TCanvas("cutFlowMuMuUnweighted_singlecuts");

cutflow_MuMu_unweighted_singlecuts->Draw();

cutFlowMuMuUnweighted_singlecuts->SaveAs("plots/MuMu/SignalPhotons/cutFlow/TTbarMuMuRefSelectionUnweighted_singlecuts.pdf");

TCanvas* cutFlowMuMuUnweighted_singlecutsall = new TCanvas("cutFlowMuMuUnweighted_singlecutsall");

cutflow_MuMu_unweighted_singlecuts->Draw();

cutFlowMuMuUnweighted_singlecutsall->SaveAs("plots/MuMu/AllPhotons/cutFlow/TTbarMuMuRefSelectionUnweighted_singlecuts.pdf");

TCanvas* cutFlowMuMu = new TCanvas("cutFlowMuMu");

cutflow_MuMu->Draw();

cutFlowMuMu->SaveAs("plots/MuMu/SignalPhotons/cutFlow/TTbarMuMuRefSelection.pdf");

TCanvas* cutFlowMuMuall = new TCanvas("cutFlowMuMuall");

cutflow_MuMu->Draw();

cutFlowMuMuall->SaveAs("plots/MuMu/AllPhotons/cutFlow/TTbarMuMuRefSelection.pdf");

TCanvas* cutFlowMuMuUnweighted = new TCanvas("cutFlowMuMuUnweighted");

cutflow_MuMu_unweighted->Draw();

cutFlowMuMuUnweighted->SaveAs("plots/MuMu/SignalPhotons/cutFlow/TTbarMuMuRefSelectionUnweighted.pdf");

TCanvas* cutFlowMuMuUnweightedall = new TCanvas("cutFlowMuMuUnweightedall");

cutflow_MuMu_unweighted->Draw();

cutFlowMuMuUnweightedall->SaveAs("plots/MuMu/AllPhotons/cutFlow/TTbarMuMuRefSelectionUnweighted.pdf");

//Cut Flow EE
TH1D* cutflow_EE_singlecuts = (TH1D*)ttgamma->Get("EventCount/TTbarEERefSelection_singleCuts");
TH1D* cutflow_EE_unweighted_singlecuts = (TH1D*)ttgamma->Get("EventCount/TTbarEERefSelectionUnweighted_singleCuts");
TH1D* cutflow_EE = (TH1D*)ttgamma->Get("EventCount/TTbarEERefSelection");
TH1D* cutflow_EE_unweighted = (TH1D*)ttgamma->Get("EventCount/TTbarEERefSelectionUnweighted");

TCanvas* cutFlowEE_singlecuts = new TCanvas("cutFlowEE_singlecuts");

cutflow_EE_singlecuts->Draw();

cutFlowEE_singlecuts->SaveAs("plots/EE/SignalPhotons/cutFlow/TTbarEERefSelection_singlecuts.pdf");

TCanvas* cutFlowEE_singlecutsall = new TCanvas("cutFlowEE_singlecutsall");

cutflow_EE_singlecuts->Draw();

cutFlowEE_singlecutsall->SaveAs("plots/EE/AllPhotons/cutFlow/TTbarEERefSelection_singlecuts.pdf");

TCanvas* cutFlowEEUnweighted_singlecuts = new TCanvas("cutFlowEEUnweighted_singlecuts");

cutflow_EE_unweighted_singlecuts->Draw();

cutFlowEEUnweighted_singlecuts->SaveAs("plots/EE/SignalPhotons/cutFlow/TTbarEERefSelectionUnweighted_singlecuts.pdf");

TCanvas* cutFlowEEUnweighted_singlecutsall = new TCanvas("cutFlowEEUnweighted_singlecutsall");

cutflow_EE_unweighted_singlecuts->Draw();

cutFlowEEUnweighted_singlecutsall->SaveAs("plots/EE/AllPhotons/cutFlow/TTbarEERefSelectionUnweighted_singlecuts.pdf");

TCanvas* cutFlowEE = new TCanvas("cutFlowEE");

cutflow_EE->Draw();

cutFlowEE->SaveAs("plots/EE/SignalPhotons/cutFlow/TTbarEERefSelection.pdf");

TCanvas* cutFlowEEall = new TCanvas("cutFlowEEall");

cutflow_EE->Draw();

cutFlowEEall->SaveAs("plots/EE/AllPhotons/cutFlow/TTbarEERefSelection.pdf");

TCanvas* cutFlowEEUnweighted = new TCanvas("cutFlowEEUnweighted");

cutflow_EE_unweighted->Draw();

cutFlowEEUnweighted->SaveAs("plots/EE/SignalPhotons/cutFlow/TTbarEERefSelectionUnweighted.pdf");

TCanvas* cutFlowEEUnweightedall = new TCanvas("cutFlowEEUnweightedall");

cutflow_EE_unweighted->Draw();

cutFlowEEUnweightedall->SaveAs("plots/EE/AllPhotons/cutFlow/TTbarEERefSelectionUnweighted.pdf");

//Rho Corrected Photon Isolation endcap
TH1D* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_0btag");
TH1D* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_1btag");
TH1D* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_2btags");
TH1D* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_3btags");
TH1D* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_4orMoreBtags");

RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuSignalPhotons1histo);
RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuSignalPhotons2histo);
RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuSignalPhotons3histo);
RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuSignalPhotons4histo);

TH1D* RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_0btag");
TH1D* RhoCorrPFPhotonIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_1btag");
TH1D* RhoCorrPFPhotonIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_2btags");
TH1D* RhoCorrPFPhotonIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_3btags");
TH1D* RhoCorrPFPhotonIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_4orMoreBtags");

RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuAllPhotons1histo);
RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuAllPhotons2histo);
RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuAllPhotons3histo);
RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapMuMuAllPhotons4histo);

TH1D* RhoCorrPFPhotonIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_0btag");
TH1D* RhoCorrPFPhotonIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_1btag");
TH1D* RhoCorrPFPhotonIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_2btags");
TH1D* RhoCorrPFPhotonIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_3btags");
TH1D* RhoCorrPFPhotonIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_4orMoreBtags");

RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEESignalPhotons1histo);
RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEESignalPhotons2histo);
RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEESignalPhotons3histo);
RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEESignalPhotons4histo);

TH1D* RhoCorrPFPhotonIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_0btag");
TH1D* RhoCorrPFPhotonIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_1btag");
TH1D* RhoCorrPFPhotonIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_2btags");
TH1D* RhoCorrPFPhotonIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_3btags");
TH1D* RhoCorrPFPhotonIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_endcap_4orMoreBtags");

RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEEAllPhotons1histo);
RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEEAllPhotons2histo);
RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEEAllPhotons3histo);
RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Add(RhoCorrPFPhotonIsoendcapEEAllPhotons4histo);

TCanvas* RhoCorrPFPhotonIsoendcapMuMuSignalPhotons = new TCanvas("RhoCorrPFPhotonIsoendcapMuMuSignalPhotons");

RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Draw();

RhoCorrPFPhotonIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_endcap.pdf");

TCanvas* RhoCorrPFPhotonIsoendcapMuMuAllPhotons = new TCanvas("RhoCorrPFPhotonIsoendcapMuMuAllPhotons");

RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Draw();

RhoCorrPFPhotonIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_endcap.pdf");

TCanvas* RhoCorrPFPhotonIsoendcapEESignalPhotons = new TCanvas("RhoCorrPFPhotonIsoendcapEESignalPhotons");

RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Draw();

RhoCorrPFPhotonIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_endcap.pdf");

TCanvas* RhoCorrPFPhotonIsoendcapEEAllPhotons = new TCanvas("RhoCorrPFPhotonIsoendcapEEAllPhotons");

RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Draw();

RhoCorrPFPhotonIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_endcap.pdf");

TCanvas* logRhoCorrPFPhotonIsoendcapMuMuSignalPhotons = new TCanvas("logRhoCorrPFPhotonIsoendcapMuMuSignalPhotons");

logRhoCorrPFPhotonIsoendcapMuMuSignalPhotons->SetLogy();
RhoCorrPFPhotonIsoendcapMuMuSignalPhotons0histo->Draw();

logRhoCorrPFPhotonIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_endcap.pdf");

TCanvas* logRhoCorrPFPhotonIsoendcapMuMuAllPhotons = new TCanvas("logRhoCorrPFPhotonIsoendcapMuMuAllPhotons");

logRhoCorrPFPhotonIsoendcapMuMuAllPhotons->SetLogy();
RhoCorrPFPhotonIsoendcapMuMuAllPhotons0histo->Draw();

logRhoCorrPFPhotonIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_endcap.pdf");

TCanvas* logRhoCorrPFPhotonIsoendcapEESignalPhotons = new TCanvas("logRhoCorrPFPhotonIsoendcapEESignalPhotons");

logRhoCorrPFPhotonIsoendcapEESignalPhotons->SetLogy();
RhoCorrPFPhotonIsoendcapEESignalPhotons0histo->Draw();

logRhoCorrPFPhotonIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_endcap.pdf");

TCanvas* logRhoCorrPFPhotonIsoendcapEEAllPhotons = new TCanvas("logRhoCorrPFPhotonIsoendcapEEAllPhotons");

logRhoCorrPFPhotonIsoendcapEEAllPhotons->SetLogy();
RhoCorrPFPhotonIsoendcapEEAllPhotons0histo->Draw();

logRhoCorrPFPhotonIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_endcap.pdf");

//Rho Corrected Photon Isolation Barrel
TH1D* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_0btag");
TH1D* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_1btag");
TH1D* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_2btags");
TH1D* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_3btags");
TH1D* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_4orMoreBtags");

RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuSignalPhotons1histo);
RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuSignalPhotons2histo);
RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuSignalPhotons3histo);
RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuSignalPhotons4histo);

TH1D* RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_0btag");
TH1D* RhoCorrPFPhotonIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_1btag");
TH1D* RhoCorrPFPhotonIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_2btags");
TH1D* RhoCorrPFPhotonIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_3btags");
TH1D* RhoCorrPFPhotonIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_4orMoreBtags");

RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuAllPhotons1histo);
RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuAllPhotons2histo);
RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuAllPhotons3histo);
RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelMuMuAllPhotons4histo);

TH1D* RhoCorrPFPhotonIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_0btag");
TH1D* RhoCorrPFPhotonIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_1btag");
TH1D* RhoCorrPFPhotonIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_2btags");
TH1D* RhoCorrPFPhotonIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_3btags");
TH1D* RhoCorrPFPhotonIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_4orMoreBtags");

RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEESignalPhotons1histo);
RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEESignalPhotons2histo);
RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEESignalPhotons3histo);
RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEESignalPhotons4histo);

TH1D* RhoCorrPFPhotonIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_0btag");
TH1D* RhoCorrPFPhotonIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_1btag");
TH1D* RhoCorrPFPhotonIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_2btags");
TH1D* RhoCorrPFPhotonIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_3btags");
TH1D* RhoCorrPFPhotonIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFPhotonIso_barrel_4orMoreBtags");

RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEEAllPhotons1histo);
RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEEAllPhotons2histo);
RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEEAllPhotons3histo);
RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Add(RhoCorrPFPhotonIsobarrelEEAllPhotons4histo);

TCanvas* RhoCorrPFPhotonIsobarrelMuMuSignalPhotons = new TCanvas("RhoCorrPFPhotonIsobarrelMuMuSignalPhotons");

RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Draw();

RhoCorrPFPhotonIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_barrel.pdf");

TCanvas* RhoCorrPFPhotonIsobarrelMuMuAllPhotons = new TCanvas("RhoCorrPFPhotonIsobarrelMuMuAllPhotons");

RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Draw();

RhoCorrPFPhotonIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_barrel.pdf");

TCanvas* RhoCorrPFPhotonIsobarrelEESignalPhotons = new TCanvas("RhoCorrPFPhotonIsobarrelEESignalPhotons");

RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Draw();

RhoCorrPFPhotonIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_barrel.pdf");

TCanvas* RhoCorrPFPhotonIsobarrelEEAllPhotons = new TCanvas("RhoCorrPFPhotonIsobarrelEEAllPhotons");

RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Draw();

RhoCorrPFPhotonIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFPhotonIso/RhoCorrPFPhotonIso_barrel.pdf");

TCanvas* logRhoCorrPFPhotonIsobarrelMuMuSignalPhotons = new TCanvas("logRhoCorrPFPhotonIsobarrelMuMuSignalPhotons");

logRhoCorrPFPhotonIsobarrelMuMuSignalPhotons->SetLogy();
RhoCorrPFPhotonIsobarrelMuMuSignalPhotons0histo->Draw();

logRhoCorrPFPhotonIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_barrel.pdf");

TCanvas* logRhoCorrPFPhotonIsobarrelMuMuAllPhotons = new TCanvas("logRhoCorrPFPhotonIsobarrelMuMuAllPhotons");

logRhoCorrPFPhotonIsobarrelMuMuAllPhotons->SetLogy();
RhoCorrPFPhotonIsobarrelMuMuAllPhotons0histo->Draw();

logRhoCorrPFPhotonIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_barrel.pdf");

TCanvas* logRhoCorrPFPhotonIsobarrelEESignalPhotons = new TCanvas("logRhoCorrPFPhotonIsobarrelEESignalPhotons");

logRhoCorrPFPhotonIsobarrelEESignalPhotons->SetLogy();
RhoCorrPFPhotonIsobarrelEESignalPhotons0histo->Draw();

logRhoCorrPFPhotonIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_barrel.pdf");

TCanvas* logRhoCorrPFPhotonIsobarrelEEAllPhotons = new TCanvas("logRhoCorrPFPhotonIsobarrelEEAllPhotons");

logRhoCorrPFPhotonIsobarrelEEAllPhotons->SetLogy();
RhoCorrPFPhotonIsobarrelEEAllPhotons0histo->Draw();

logRhoCorrPFPhotonIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFPhotonIso/logRhoCorrPFPhotonIso_barrel.pdf");

//Rho Corrected Neutral Hadron Isolation Endcap
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_0btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_1btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_2btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_3btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_4orMoreBtags");

RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons1histo);
RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons2histo);
RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons3histo);
RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_0btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_1btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_2btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_3btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_4orMoreBtags");

RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons1histo);
RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons2histo);
RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons3histo);
RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_0btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_1btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_2btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_3btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_4orMoreBtags");

RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEESignalPhotons1histo);
RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEESignalPhotons2histo);
RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEESignalPhotons3histo);
RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEESignalPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_0btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_1btag");
TH1D* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_2btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_3btags");
TH1D* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_endcap_4orMoreBtags");

RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEEAllPhotons1histo);
RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEEAllPhotons2histo);
RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEEAllPhotons3histo);
RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsoendcapEEAllPhotons4histo);

TCanvas* RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons = new TCanvas("RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons");

RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons = new TCanvas("RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons");

RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* RhoCorrPFNeutralHadronIsoendcapEESignalPhotons = new TCanvas("RhoCorrPFNeutralHadronIsoendcapEESignalPhotons");

RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* RhoCorrPFNeutralHadronIsoendcapEEAllPhotons = new TCanvas("RhoCorrPFNeutralHadronIsoendcapEEAllPhotons");

RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons");

logRhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons->SetLogy();
RhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons");

logRhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons->SetLogy();
RhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsoendcapEESignalPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsoendcapEESignalPhotons");

logRhoCorrPFNeutralHadronIsoendcapEESignalPhotons->SetLogy();
RhoCorrPFNeutralHadronIsoendcapEESignalPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsoendcapEEAllPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsoendcapEEAllPhotons");

logRhoCorrPFNeutralHadronIsoendcapEEAllPhotons->SetLogy();
RhoCorrPFNeutralHadronIsoendcapEEAllPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_endcap.pdf");

//Rho Corrected Neutral Hadron Isolation Barrel
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_0btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_1btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_2btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_3btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_4orMoreBtags");

RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons1histo);
RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons2histo);
RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons3histo);
RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_0btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_1btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_2btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_3btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_4orMoreBtags");

RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons1histo);
RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons2histo);
RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons3histo);
RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_0btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_1btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_2btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_3btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_4orMoreBtags");

RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEESignalPhotons1histo);
RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEESignalPhotons2histo);
RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEESignalPhotons3histo);
RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEESignalPhotons4histo);

TH1D* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_0btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_1btag");
TH1D* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_2btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_3btags");
TH1D* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFNeutralHadronIso_barrel_4orMoreBtags");

RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEEAllPhotons1histo);
RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEEAllPhotons2histo);
RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEEAllPhotons3histo);
RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFNeutralHadronIsobarrelEEAllPhotons4histo);

TCanvas* RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons = new TCanvas("RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons");

RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons = new TCanvas("RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons");

RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* RhoCorrPFNeutralHadronIsobarrelEESignalPhotons = new TCanvas("RhoCorrPFNeutralHadronIsobarrelEESignalPhotons");

RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* RhoCorrPFNeutralHadronIsobarrelEEAllPhotons = new TCanvas("RhoCorrPFNeutralHadronIsobarrelEEAllPhotons");

RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Draw();

RhoCorrPFNeutralHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFNeutralHadronIso/RhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons");

logRhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons->SetLogy();
RhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons");

logRhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons->SetLogy();
RhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsobarrelEESignalPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsobarrelEESignalPhotons");

logRhoCorrPFNeutralHadronIsobarrelEESignalPhotons->SetLogy();
RhoCorrPFNeutralHadronIsobarrelEESignalPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFNeutralHadronIsobarrelEEAllPhotons = new TCanvas("logRhoCorrPFNeutralHadronIsobarrelEEAllPhotons");

logRhoCorrPFNeutralHadronIsobarrelEEAllPhotons->SetLogy();
RhoCorrPFNeutralHadronIsobarrelEEAllPhotons0histo->Draw();

logRhoCorrPFNeutralHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFNeutralHadronIso/logRhoCorrPFNeutralHadronIso_barrel.pdf");

//Rho Corrected Charged Hadron Isolation endcap
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_0btag");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_1btag");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_2btags");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_3btags");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_4orMoreBtags");

RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons1histo);
RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons2histo);
RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons3histo);
RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_0btag");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_1btag");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_2btags");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_3btags");
TH1D* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_4orMoreBtags");

RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons1histo);
RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons2histo);
RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons3histo);
RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_0btag");
TH1D* RhoCorrPFChargedHadronIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_1btag");
TH1D* RhoCorrPFChargedHadronIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_2btags");
TH1D* RhoCorrPFChargedHadronIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_3btags");
TH1D* RhoCorrPFChargedHadronIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_4orMoreBtags");

RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEESignalPhotons1histo);
RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEESignalPhotons2histo);
RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEESignalPhotons3histo);
RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEESignalPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_0btag");
TH1D* RhoCorrPFChargedHadronIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_1btag");
TH1D* RhoCorrPFChargedHadronIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_2btags");
TH1D* RhoCorrPFChargedHadronIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_3btags");
TH1D* RhoCorrPFChargedHadronIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_endcap_4orMoreBtags");

RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEEAllPhotons1histo);
RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEEAllPhotons2histo);
RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEEAllPhotons3histo);
RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsoendcapEEAllPhotons4histo);

TCanvas* RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons = new TCanvas("RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons");

RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Draw();

RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons = new TCanvas("RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons");

RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Draw();

RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* RhoCorrPFChargedHadronIsoendcapEESignalPhotons = new TCanvas("RhoCorrPFChargedHadronIsoendcapEESignalPhotons");

RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Draw();

RhoCorrPFChargedHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* RhoCorrPFChargedHadronIsoendcapEEAllPhotons = new TCanvas("RhoCorrPFChargedHadronIsoendcapEEAllPhotons");

RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Draw();

RhoCorrPFChargedHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons = new TCanvas("logRhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons");

logRhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons->SetLogy();
RhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFChargedHadronIsoendcapMuMuAllPhotons = new TCanvas("logRhoCorrPFChargedHadronIsoendcapMuMuAllPhotons");

logRhoCorrPFChargedHadronIsoendcapMuMuAllPhotons->SetLogy();
RhoCorrPFChargedHadronIsoendcapMuMuAllPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFChargedHadronIsoendcapEESignalPhotons = new TCanvas("logRhoCorrPFChargedHadronIsoendcapEESignalPhotons");

logRhoCorrPFChargedHadronIsoendcapEESignalPhotons->SetLogy();
RhoCorrPFChargedHadronIsoendcapEESignalPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_endcap.pdf");

TCanvas* logRhoCorrPFChargedHadronIsoendcapEEAllPhotons = new TCanvas("logRhoCorrPFChargedHadronIsoendcapEEAllPhotons");

logRhoCorrPFChargedHadronIsoendcapEEAllPhotons->SetLogy();
RhoCorrPFChargedHadronIsoendcapEEAllPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_endcap.pdf");

//Rho Corrected Charged Hadron Isolation barrel
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_0btag");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_1btag");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_2btags");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_3btags");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_4orMoreBtags");

RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons1histo);
RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons2histo);
RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons3histo);
RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_0btag");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_1btag");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_2btags");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_3btags");
TH1D* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_4orMoreBtags");

RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons1histo);
RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons2histo);
RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons3histo);
RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_0btag");
TH1D* RhoCorrPFChargedHadronIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_1btag");
TH1D* RhoCorrPFChargedHadronIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_2btags");
TH1D* RhoCorrPFChargedHadronIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_3btags");
TH1D* RhoCorrPFChargedHadronIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_4orMoreBtags");

RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEESignalPhotons1histo);
RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEESignalPhotons2histo);
RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEESignalPhotons3histo);
RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEESignalPhotons4histo);

TH1D* RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_0btag");
TH1D* RhoCorrPFChargedHadronIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_1btag");
TH1D* RhoCorrPFChargedHadronIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_2btags");
TH1D* RhoCorrPFChargedHadronIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_3btags");
TH1D* RhoCorrPFChargedHadronIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_RhoCorrectedPFChargedHadronIso_barrel_4orMoreBtags");

RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEEAllPhotons1histo);
RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEEAllPhotons2histo);
RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEEAllPhotons3histo);
RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Add(RhoCorrPFChargedHadronIsobarrelEEAllPhotons4histo);

TCanvas* RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons = new TCanvas("RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons");

RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Draw();

RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons = new TCanvas("RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons");

RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Draw();

RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* RhoCorrPFChargedHadronIsobarrelEESignalPhotons = new TCanvas("RhoCorrPFChargedHadronIsobarrelEESignalPhotons");

RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Draw();

RhoCorrPFChargedHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* RhoCorrPFChargedHadronIsobarrelEEAllPhotons = new TCanvas("RhoCorrPFChargedHadronIsobarrelEEAllPhotons");

RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Draw();

RhoCorrPFChargedHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFChargedHadronIso/RhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons = new TCanvas("logRhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons");

logRhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons->SetLogy();
RhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFChargedHadronIsobarrelMuMuAllPhotons = new TCanvas("logRhoCorrPFChargedHadronIsobarrelMuMuAllPhotons");

logRhoCorrPFChargedHadronIsobarrelMuMuAllPhotons->SetLogy();
RhoCorrPFChargedHadronIsobarrelMuMuAllPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFChargedHadronIsobarrelEESignalPhotons = new TCanvas("logRhoCorrPFChargedHadronIsobarrelEESignalPhotons");

logRhoCorrPFChargedHadronIsobarrelEESignalPhotons->SetLogy();
RhoCorrPFChargedHadronIsobarrelEESignalPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_barrel.pdf");

TCanvas* logRhoCorrPFChargedHadronIsobarrelEEAllPhotons = new TCanvas("logRhoCorrPFChargedHadronIsobarrelEEAllPhotons");

logRhoCorrPFChargedHadronIsobarrelEEAllPhotons->SetLogy();
RhoCorrPFChargedHadronIsobarrelEEAllPhotons0histo->Draw();

logRhoCorrPFChargedHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/RhoCorrPFChargedHadronIso/logRhoCorrPFChargedHadronIso_barrel.pdf");

//PF Photon Isolation Endcap
TH1D* PFPhotonIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_endcap_0btag");
TH1D* PFPhotonIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_endcap_1btag");
TH1D* PFPhotonIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_endcap_2btags");
TH1D* PFPhotonIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_endcap_3btags");
TH1D* PFPhotonIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_endcap_4orMoreBtags");

PFPhotonIsoendcapMuMuSignalPhotons0histo->Add(PFPhotonIsoendcapMuMuSignalPhotons1histo);
PFPhotonIsoendcapMuMuSignalPhotons0histo->Add(PFPhotonIsoendcapMuMuSignalPhotons2histo);
PFPhotonIsoendcapMuMuSignalPhotons0histo->Add(PFPhotonIsoendcapMuMuSignalPhotons3histo);
PFPhotonIsoendcapMuMuSignalPhotons0histo->Add(PFPhotonIsoendcapMuMuSignalPhotons4histo);

TH1D* PFPhotonIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_endcap_0btag");
TH1D* PFPhotonIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_endcap_1btag");
TH1D* PFPhotonIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_endcap_2btags");
TH1D* PFPhotonIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_endcap_3btags");
TH1D* PFPhotonIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_endcap_4orMoreBtags");

PFPhotonIsoendcapMuMuAllPhotons0histo->Add(PFPhotonIsoendcapMuMuAllPhotons1histo);
PFPhotonIsoendcapMuMuAllPhotons0histo->Add(PFPhotonIsoendcapMuMuAllPhotons2histo);
PFPhotonIsoendcapMuMuAllPhotons0histo->Add(PFPhotonIsoendcapMuMuAllPhotons3histo);
PFPhotonIsoendcapMuMuAllPhotons0histo->Add(PFPhotonIsoendcapMuMuAllPhotons4histo);

TH1D* PFPhotonIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_endcap_0btag");
TH1D* PFPhotonIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_endcap_1btag");
TH1D* PFPhotonIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_endcap_2btags");
TH1D* PFPhotonIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_endcap_3btags");
TH1D* PFPhotonIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_endcap_4orMoreBtags");

PFPhotonIsoendcapEESignalPhotons0histo->Add(PFPhotonIsoendcapEESignalPhotons1histo);
PFPhotonIsoendcapEESignalPhotons0histo->Add(PFPhotonIsoendcapEESignalPhotons2histo);
PFPhotonIsoendcapEESignalPhotons0histo->Add(PFPhotonIsoendcapEESignalPhotons3histo);
PFPhotonIsoendcapEESignalPhotons0histo->Add(PFPhotonIsoendcapEESignalPhotons4histo);

TH1D* PFPhotonIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_endcap_0btag");
TH1D* PFPhotonIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_endcap_1btag");
TH1D* PFPhotonIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_endcap_2btags");
TH1D* PFPhotonIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_endcap_3btags");
TH1D* PFPhotonIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_endcap_4orMoreBtags");

PFPhotonIsoendcapEEAllPhotons0histo->Add(PFPhotonIsoendcapEEAllPhotons1histo);
PFPhotonIsoendcapEEAllPhotons0histo->Add(PFPhotonIsoendcapEEAllPhotons2histo);
PFPhotonIsoendcapEEAllPhotons0histo->Add(PFPhotonIsoendcapEEAllPhotons3histo);
PFPhotonIsoendcapEEAllPhotons0histo->Add(PFPhotonIsoendcapEEAllPhotons4histo);

TCanvas* PFPhotonIsoendcapMuMuSignalPhotons = new TCanvas("PFPhotonIsoendcapMuMuSignalPhotons");

PFPhotonIsoendcapMuMuSignalPhotons0histo->Draw();

PFPhotonIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFPhotonIso/PFPhotonIso_endcap.pdf");

TCanvas* PFPhotonIsoendcapMuMuAllPhotons = new TCanvas("PFPhotonIsoendcapMuMuAllPhotons");

PFPhotonIsoendcapMuMuAllPhotons0histo->Draw();

PFPhotonIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFPhotonIso/PFPhotonIso_endcap.pdf");

TCanvas* PFPhotonIsoendcapEESignalPhotons = new TCanvas("PFPhotonIsoendcapEESignalPhotons");

PFPhotonIsoendcapEESignalPhotons0histo->Draw();

PFPhotonIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFPhotonIso/PFPhotonIso_endcap.pdf");

TCanvas* PFPhotonIsoendcapEEAllPhotons = new TCanvas("PFPhotonIsoendcapEEAllPhotons");

PFPhotonIsoendcapEEAllPhotons0histo->Draw();

PFPhotonIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFPhotonIso/PFPhotonIso_endcap.pdf");

TCanvas* logPFPhotonIsoendcapMuMuSignalPhotons = new TCanvas("logPFPhotonIsoendcapMuMuSignalPhotons");

logPFPhotonIsoendcapMuMuSignalPhotons->SetLogy();
PFPhotonIsoendcapMuMuSignalPhotons0histo->Draw();

logPFPhotonIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFPhotonIso/logPFPhotonIso_endcap.pdf");

TCanvas* logPFPhotonIsoendcapMuMuAllPhotons = new TCanvas("logPFPhotonIsoendcapMuMuAllPhotons");

logPFPhotonIsoendcapMuMuAllPhotons->SetLogy();
PFPhotonIsoendcapMuMuAllPhotons0histo->Draw();

logPFPhotonIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFPhotonIso/logPFPhotonIso_endcap.pdf");

TCanvas* logPFPhotonIsoendcapEESignalPhotons = new TCanvas("logPFPhotonIsoendcapEESignalPhotons");

logPFPhotonIsoendcapEESignalPhotons->SetLogy();
PFPhotonIsoendcapEESignalPhotons0histo->Draw();

logPFPhotonIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFPhotonIso/logPFPhotonIso_endcap.pdf");

TCanvas* logPFPhotonIsoendcapEEAllPhotons = new TCanvas("logPFPhotonIsoendcapEEAllPhotons");

logPFPhotonIsoendcapEEAllPhotons->SetLogy();
PFPhotonIsoendcapEEAllPhotons0histo->Draw();

logPFPhotonIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFPhotonIso/logPFPhotonIso_endcap.pdf");

//PF Photon Isolation Barrel
TH1D* PFPhotonIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_barrel_0btag");
TH1D* PFPhotonIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_barrel_1btag");
TH1D* PFPhotonIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_barrel_2btags");
TH1D* PFPhotonIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_barrel_3btags");
TH1D* PFPhotonIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFPhotonIso_barrel_4orMoreBtags");

PFPhotonIsobarrelMuMuSignalPhotons0histo->Add(PFPhotonIsobarrelMuMuSignalPhotons1histo);
PFPhotonIsobarrelMuMuSignalPhotons0histo->Add(PFPhotonIsobarrelMuMuSignalPhotons2histo);
PFPhotonIsobarrelMuMuSignalPhotons0histo->Add(PFPhotonIsobarrelMuMuSignalPhotons3histo);
PFPhotonIsobarrelMuMuSignalPhotons0histo->Add(PFPhotonIsobarrelMuMuSignalPhotons4histo);

TH1D* PFPhotonIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_barrel_0btag");
TH1D* PFPhotonIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_barrel_1btag");
TH1D* PFPhotonIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_barrel_2btags");
TH1D* PFPhotonIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_barrel_3btags");
TH1D* PFPhotonIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFPhotonIso_barrel_4orMoreBtags");

PFPhotonIsobarrelMuMuAllPhotons0histo->Add(PFPhotonIsobarrelMuMuAllPhotons1histo);
PFPhotonIsobarrelMuMuAllPhotons0histo->Add(PFPhotonIsobarrelMuMuAllPhotons2histo);
PFPhotonIsobarrelMuMuAllPhotons0histo->Add(PFPhotonIsobarrelMuMuAllPhotons3histo);
PFPhotonIsobarrelMuMuAllPhotons0histo->Add(PFPhotonIsobarrelMuMuAllPhotons4histo);

TH1D* PFPhotonIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_barrel_0btag");
TH1D* PFPhotonIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_barrel_1btag");
TH1D* PFPhotonIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_barrel_2btags");
TH1D* PFPhotonIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_barrel_3btags");
TH1D* PFPhotonIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFPhotonIso_barrel_4orMoreBtags");

PFPhotonIsobarrelEESignalPhotons0histo->Add(PFPhotonIsobarrelEESignalPhotons1histo);
PFPhotonIsobarrelEESignalPhotons0histo->Add(PFPhotonIsobarrelEESignalPhotons2histo);
PFPhotonIsobarrelEESignalPhotons0histo->Add(PFPhotonIsobarrelEESignalPhotons3histo);
PFPhotonIsobarrelEESignalPhotons0histo->Add(PFPhotonIsobarrelEESignalPhotons4histo);

TH1D* PFPhotonIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_barrel_0btag");
TH1D* PFPhotonIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_barrel_1btag");
TH1D* PFPhotonIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_barrel_2btags");
TH1D* PFPhotonIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_barrel_3btags");
TH1D* PFPhotonIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFPhotonIso_barrel_4orMoreBtags");

PFPhotonIsobarrelEEAllPhotons0histo->Add(PFPhotonIsobarrelEEAllPhotons1histo);
PFPhotonIsobarrelEEAllPhotons0histo->Add(PFPhotonIsobarrelEEAllPhotons2histo);
PFPhotonIsobarrelEEAllPhotons0histo->Add(PFPhotonIsobarrelEEAllPhotons3histo);
PFPhotonIsobarrelEEAllPhotons0histo->Add(PFPhotonIsobarrelEEAllPhotons4histo);

TCanvas* PFPhotonIsobarrelMuMuSignalPhotons = new TCanvas("PFPhotonIsobarrelMuMuSignalPhotons");

PFPhotonIsobarrelMuMuSignalPhotons0histo->Draw();

PFPhotonIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFPhotonIso/PFPhotonIso_barrel.pdf");

TCanvas* PFPhotonIsobarrelMuMuAllPhotons = new TCanvas("PFPhotonIsobarrelMuMuAllPhotons");

PFPhotonIsobarrelMuMuAllPhotons0histo->Draw();

PFPhotonIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFPhotonIso/PFPhotonIso_barrel.pdf");

TCanvas* PFPhotonIsobarrelEESignalPhotons = new TCanvas("PFPhotonIsobarrelEESignalPhotons");

PFPhotonIsobarrelEESignalPhotons0histo->Draw();

PFPhotonIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFPhotonIso/PFPhotonIso_barrel.pdf");

TCanvas* PFPhotonIsobarrelEEAllPhotons = new TCanvas("PFPhotonIsobarrelEEAllPhotons");

PFPhotonIsobarrelEEAllPhotons0histo->Draw();

PFPhotonIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFPhotonIso/PFPhotonIso_barrel.pdf");

TCanvas* logPFPhotonIsobarrelMuMuSignalPhotons = new TCanvas("logPFPhotonIsobarrelMuMuSignalPhotons");

logPFPhotonIsobarrelMuMuSignalPhotons->SetLogy();
PFPhotonIsobarrelMuMuSignalPhotons0histo->Draw();

logPFPhotonIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFPhotonIso/logPFPhotonIso_barrel.pdf");

TCanvas* logPFPhotonIsobarrelMuMuAllPhotons = new TCanvas("logPFPhotonIsobarrelMuMuAllPhotons");

logPFPhotonIsobarrelMuMuAllPhotons->SetLogy();
PFPhotonIsobarrelMuMuAllPhotons0histo->Draw();

logPFPhotonIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFPhotonIso/logPFPhotonIso_barrel.pdf");

TCanvas* logPFPhotonIsobarrelEESignalPhotons = new TCanvas("logPFPhotonIsobarrelEESignalPhotons");

logPFPhotonIsobarrelEESignalPhotons->SetLogy();
PFPhotonIsobarrelEESignalPhotons0histo->Draw();

logPFPhotonIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFPhotonIso/logPFPhotonIso_barrel.pdf");

TCanvas* logPFPhotonIsobarrelEEAllPhotons = new TCanvas("logPFPhotonIsobarrelEEAllPhotons");

logPFPhotonIsobarrelEEAllPhotons->SetLogy();
PFPhotonIsobarrelEEAllPhotons0histo->Draw();

logPFPhotonIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFPhotonIso/logPFPhotonIso_barrel.pdf");

//PF Neutral Hadron Isolation endcap
TH1D* PFNeutralHadronIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_endcap_0btag");
TH1D* PFNeutralHadronIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_endcap_1btag");
TH1D* PFNeutralHadronIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_endcap_2btags");
TH1D* PFNeutralHadronIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_endcap_3btags");
TH1D* PFNeutralHadronIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_endcap_4orMoreBtags");

PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuSignalPhotons1histo);
PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuSignalPhotons2histo);
PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuSignalPhotons3histo);
PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuSignalPhotons4histo);

TH1D* PFNeutralHadronIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_endcap_0btag");
TH1D* PFNeutralHadronIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_endcap_1btag");
TH1D* PFNeutralHadronIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_endcap_2btags");
TH1D* PFNeutralHadronIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_endcap_3btags");
TH1D* PFNeutralHadronIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_endcap_4orMoreBtags");

PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuAllPhotons1histo);
PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuAllPhotons2histo);
PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuAllPhotons3histo);
PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Add(PFNeutralHadronIsoendcapMuMuAllPhotons4histo);

TH1D* PFNeutralHadronIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_endcap_0btag");
TH1D* PFNeutralHadronIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_endcap_1btag");
TH1D* PFNeutralHadronIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_endcap_2btags");
TH1D* PFNeutralHadronIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_endcap_3btags");
TH1D* PFNeutralHadronIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_endcap_4orMoreBtags");

PFNeutralHadronIsoendcapEESignalPhotons0histo->Add(PFNeutralHadronIsoendcapEESignalPhotons1histo);
PFNeutralHadronIsoendcapEESignalPhotons0histo->Add(PFNeutralHadronIsoendcapEESignalPhotons2histo);
PFNeutralHadronIsoendcapEESignalPhotons0histo->Add(PFNeutralHadronIsoendcapEESignalPhotons3histo);
PFNeutralHadronIsoendcapEESignalPhotons0histo->Add(PFNeutralHadronIsoendcapEESignalPhotons4histo);

TH1D* PFNeutralHadronIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_endcap_0btag");
TH1D* PFNeutralHadronIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_endcap_1btag");
TH1D* PFNeutralHadronIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_endcap_2btags");
TH1D* PFNeutralHadronIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_endcap_3btags");
TH1D* PFNeutralHadronIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_endcap_4orMoreBtags");

PFNeutralHadronIsoendcapEEAllPhotons0histo->Add(PFNeutralHadronIsoendcapEEAllPhotons1histo);
PFNeutralHadronIsoendcapEEAllPhotons0histo->Add(PFNeutralHadronIsoendcapEEAllPhotons2histo);
PFNeutralHadronIsoendcapEEAllPhotons0histo->Add(PFNeutralHadronIsoendcapEEAllPhotons3histo);
PFNeutralHadronIsoendcapEEAllPhotons0histo->Add(PFNeutralHadronIsoendcapEEAllPhotons4histo);

TCanvas* PFNeutralHadronIsoendcapMuMuSignalPhotons = new TCanvas("PFNeutralHadronIsoendcapMuMuSignalPhotons");

PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Draw();

PFNeutralHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFNeutralHadronIso/PFNeutralHadronIso_endcap.pdf");

TCanvas* PFNeutralHadronIsoendcapMuMuAllPhotons = new TCanvas("PFNeutralHadronIsoendcapMuMuAllPhotons");

PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Draw();

PFNeutralHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFNeutralHadronIso/PFNeutralHadronIso_endcap.pdf");

TCanvas* PFNeutralHadronIsoendcapEESignalPhotons = new TCanvas("PFNeutralHadronIsoendcapEESignalPhotons");

PFNeutralHadronIsoendcapEESignalPhotons0histo->Draw();

PFNeutralHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFNeutralHadronIso/PFNeutralHadronIso_endcap.pdf");

TCanvas* PFNeutralHadronIsoendcapEEAllPhotons = new TCanvas("PFNeutralHadronIsoendcapEEAllPhotons");

PFNeutralHadronIsoendcapEEAllPhotons0histo->Draw();

PFNeutralHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFNeutralHadronIso/PFNeutralHadronIso_endcap.pdf");

TCanvas* logPFNeutralHadronIsoendcapMuMuSignalPhotons = new TCanvas("logPFNeutralHadronIsoendcapMuMuSignalPhotons");

logPFNeutralHadronIsoendcapMuMuSignalPhotons->SetLogy();
PFNeutralHadronIsoendcapMuMuSignalPhotons0histo->Draw();

logPFNeutralHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_endcap.pdf");

TCanvas* logPFNeutralHadronIsoendcapMuMuAllPhotons = new TCanvas("logPFNeutralHadronIsoendcapMuMuAllPhotons");

logPFNeutralHadronIsoendcapMuMuAllPhotons->SetLogy();
PFNeutralHadronIsoendcapMuMuAllPhotons0histo->Draw();

logPFNeutralHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_endcap.pdf");

TCanvas* logPFNeutralHadronIsoendcapEESignalPhotons = new TCanvas("logPFNeutralHadronIsoendcapEESignalPhotons");

logPFNeutralHadronIsoendcapEESignalPhotons->SetLogy();
PFNeutralHadronIsoendcapEESignalPhotons0histo->Draw();

logPFNeutralHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_endcap.pdf");

TCanvas* logPFNeutralHadronIsoendcapEEAllPhotons = new TCanvas("logPFNeutralHadronIsoendcapEEAllPhotons");

logPFNeutralHadronIsoendcapEEAllPhotons->SetLogy();
PFNeutralHadronIsoendcapEEAllPhotons0histo->Draw();

logPFNeutralHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_endcap.pdf");

//PF Neutral Hadron Isolation barrel
TH1D* PFNeutralHadronIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_barrel_0btag");
TH1D* PFNeutralHadronIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_barrel_1btag");
TH1D* PFNeutralHadronIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_barrel_2btags");
TH1D* PFNeutralHadronIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_barrel_3btags");
TH1D* PFNeutralHadronIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFNeutralHadronIso_barrel_4orMoreBtags");

PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuSignalPhotons1histo);
PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuSignalPhotons2histo);
PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuSignalPhotons3histo);
PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuSignalPhotons4histo);

TH1D* PFNeutralHadronIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_barrel_0btag");
TH1D* PFNeutralHadronIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_barrel_1btag");
TH1D* PFNeutralHadronIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_barrel_2btags");
TH1D* PFNeutralHadronIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_barrel_3btags");
TH1D* PFNeutralHadronIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFNeutralHadronIso_barrel_4orMoreBtags");

PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuAllPhotons1histo);
PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuAllPhotons2histo);
PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuAllPhotons3histo);
PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Add(PFNeutralHadronIsobarrelMuMuAllPhotons4histo);

TH1D* PFNeutralHadronIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_barrel_0btag");
TH1D* PFNeutralHadronIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_barrel_1btag");
TH1D* PFNeutralHadronIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_barrel_2btags");
TH1D* PFNeutralHadronIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_barrel_3btags");
TH1D* PFNeutralHadronIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFNeutralHadronIso_barrel_4orMoreBtags");

PFNeutralHadronIsobarrelEESignalPhotons0histo->Add(PFNeutralHadronIsobarrelEESignalPhotons1histo);
PFNeutralHadronIsobarrelEESignalPhotons0histo->Add(PFNeutralHadronIsobarrelEESignalPhotons2histo);
PFNeutralHadronIsobarrelEESignalPhotons0histo->Add(PFNeutralHadronIsobarrelEESignalPhotons3histo);
PFNeutralHadronIsobarrelEESignalPhotons0histo->Add(PFNeutralHadronIsobarrelEESignalPhotons4histo);

TH1D* PFNeutralHadronIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_barrel_0btag");
TH1D* PFNeutralHadronIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_barrel_1btag");
TH1D* PFNeutralHadronIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_barrel_2btags");
TH1D* PFNeutralHadronIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_barrel_3btags");
TH1D* PFNeutralHadronIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFNeutralHadronIso_barrel_4orMoreBtags");

PFNeutralHadronIsobarrelEEAllPhotons0histo->Add(PFNeutralHadronIsobarrelEEAllPhotons1histo);
PFNeutralHadronIsobarrelEEAllPhotons0histo->Add(PFNeutralHadronIsobarrelEEAllPhotons2histo);
PFNeutralHadronIsobarrelEEAllPhotons0histo->Add(PFNeutralHadronIsobarrelEEAllPhotons3histo);
PFNeutralHadronIsobarrelEEAllPhotons0histo->Add(PFNeutralHadronIsobarrelEEAllPhotons4histo);

TCanvas* PFNeutralHadronIsobarrelMuMuSignalPhotons = new TCanvas("PFNeutralHadronIsobarrelMuMuSignalPhotons");

PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Draw();

PFNeutralHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFNeutralHadronIso/PFNeutralHadronIso_barrel.pdf");

TCanvas* PFNeutralHadronIsobarrelMuMuAllPhotons = new TCanvas("PFNeutralHadronIsobarrelMuMuAllPhotons");

PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Draw();

PFNeutralHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFNeutralHadronIso/PFNeutralHadronIso_barrel.pdf");

TCanvas* PFNeutralHadronIsobarrelEESignalPhotons = new TCanvas("PFNeutralHadronIsobarrelEESignalPhotons");

PFNeutralHadronIsobarrelEESignalPhotons0histo->Draw();

PFNeutralHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFNeutralHadronIso/PFNeutralHadronIso_barrel.pdf");

TCanvas* PFNeutralHadronIsobarrelEEAllPhotons = new TCanvas("PFNeutralHadronIsobarrelEEAllPhotons");

PFNeutralHadronIsobarrelEEAllPhotons0histo->Draw();

PFNeutralHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFNeutralHadronIso/PFNeutralHadronIso_barrel.pdf");

TCanvas* logPFNeutralHadronIsobarrelMuMuSignalPhotons = new TCanvas("logPFNeutralHadronIsobarrelMuMuSignalPhotons");

logPFNeutralHadronIsobarrelMuMuSignalPhotons->SetLogy();
PFNeutralHadronIsobarrelMuMuSignalPhotons0histo->Draw();

logPFNeutralHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_barrel.pdf");

TCanvas* logPFNeutralHadronIsobarrelMuMuAllPhotons = new TCanvas("logPFNeutralHadronIsobarrelMuMuAllPhotons");

logPFNeutralHadronIsobarrelMuMuAllPhotons->SetLogy();
PFNeutralHadronIsobarrelMuMuAllPhotons0histo->Draw();

logPFNeutralHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_barrel.pdf");

TCanvas* logPFNeutralHadronIsobarrelEESignalPhotons = new TCanvas("logPFNeutralHadronIsobarrelEESignalPhotons");

logPFNeutralHadronIsobarrelEESignalPhotons->SetLogy();
PFNeutralHadronIsobarrelEESignalPhotons0histo->Draw();

logPFNeutralHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_barrel.pdf");

TCanvas* logPFNeutralHadronIsobarrelEEAllPhotons = new TCanvas("logPFNeutralHadronIsobarrelEEAllPhotons");

logPFNeutralHadronIsobarrelEEAllPhotons->SetLogy();
PFNeutralHadronIsobarrelEEAllPhotons0histo->Draw();

logPFNeutralHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFNeutralHadronIso/logPFNeutralHadronIso_barrel.pdf");

//PF Charged Hadron Isolation endcap
TH1D* PFChargedHadronIsoendcapMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_endcap_0btag");
TH1D* PFChargedHadronIsoendcapMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_endcap_1btag");
TH1D* PFChargedHadronIsoendcapMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_endcap_2btags");
TH1D* PFChargedHadronIsoendcapMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_endcap_3btags");
TH1D* PFChargedHadronIsoendcapMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_endcap_4orMoreBtags");

PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(PFChargedHadronIsoendcapMuMuSignalPhotons1histo);
PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(PFChargedHadronIsoendcapMuMuSignalPhotons2histo);
PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(PFChargedHadronIsoendcapMuMuSignalPhotons3histo);
PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Add(PFChargedHadronIsoendcapMuMuSignalPhotons4histo);

TH1D* PFChargedHadronIsoendcapMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_endcap_0btag");
TH1D* PFChargedHadronIsoendcapMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_endcap_1btag");
TH1D* PFChargedHadronIsoendcapMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_endcap_2btags");
TH1D* PFChargedHadronIsoendcapMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_endcap_3btags");
TH1D* PFChargedHadronIsoendcapMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_endcap_4orMoreBtags");

PFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(PFChargedHadronIsoendcapMuMuAllPhotons1histo);
PFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(PFChargedHadronIsoendcapMuMuAllPhotons2histo);
PFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(PFChargedHadronIsoendcapMuMuAllPhotons3histo);
PFChargedHadronIsoendcapMuMuAllPhotons0histo->Add(PFChargedHadronIsoendcapMuMuAllPhotons4histo);

TH1D* PFChargedHadronIsoendcapEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_endcap_0btag");
TH1D* PFChargedHadronIsoendcapEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_endcap_1btag");
TH1D* PFChargedHadronIsoendcapEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_endcap_2btags");
TH1D* PFChargedHadronIsoendcapEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_endcap_3btags");
TH1D* PFChargedHadronIsoendcapEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_endcap_4orMoreBtags");

PFChargedHadronIsoendcapEESignalPhotons0histo->Add(PFChargedHadronIsoendcapEESignalPhotons1histo);
PFChargedHadronIsoendcapEESignalPhotons0histo->Add(PFChargedHadronIsoendcapEESignalPhotons2histo);
PFChargedHadronIsoendcapEESignalPhotons0histo->Add(PFChargedHadronIsoendcapEESignalPhotons3histo);
PFChargedHadronIsoendcapEESignalPhotons0histo->Add(PFChargedHadronIsoendcapEESignalPhotons4histo);

TH1D* PFChargedHadronIsoendcapEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_endcap_0btag");
TH1D* PFChargedHadronIsoendcapEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_endcap_1btag");
TH1D* PFChargedHadronIsoendcapEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_endcap_2btags");
TH1D* PFChargedHadronIsoendcapEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_endcap_3btags");
TH1D* PFChargedHadronIsoendcapEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_endcap_4orMoreBtags");

PFChargedHadronIsoendcapEEAllPhotons0histo->Add(PFChargedHadronIsoendcapEEAllPhotons1histo);
PFChargedHadronIsoendcapEEAllPhotons0histo->Add(PFChargedHadronIsoendcapEEAllPhotons2histo);
PFChargedHadronIsoendcapEEAllPhotons0histo->Add(PFChargedHadronIsoendcapEEAllPhotons3histo);
PFChargedHadronIsoendcapEEAllPhotons0histo->Add(PFChargedHadronIsoendcapEEAllPhotons4histo);

TCanvas* PFChargedHadronIsoendcapMuMuSignalPhotons = new TCanvas("PFChargedHadronIsoendcapMuMuSignalPhotons");

PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Draw();

PFChargedHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFChargedHadronIso/PFChargedHadronIso_endcap.pdf");

TCanvas* PFChargedHadronIsoendcapMuMuAllPhotons = new TCanvas("PFChargedHadronIsoendcapMuMuAllPhotons");

PFChargedHadronIsoendcapMuMuAllPhotons0histo->Draw();

PFChargedHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFChargedHadronIso/PFChargedHadronIso_endcap.pdf");

TCanvas* PFChargedHadronIsoendcapEESignalPhotons = new TCanvas("PFChargedHadronIsoendcapEESignalPhotons");

PFChargedHadronIsoendcapEESignalPhotons0histo->Draw();

PFChargedHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFChargedHadronIso/PFChargedHadronIso_endcap.pdf");

TCanvas* PFChargedHadronIsoendcapEEAllPhotons = new TCanvas("PFChargedHadronIsoendcapEEAllPhotons");

PFChargedHadronIsoendcapEEAllPhotons0histo->Draw();

PFChargedHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFChargedHadronIso/PFChargedHadronIso_endcap.pdf");

TCanvas* logPFChargedHadronIsoendcapMuMuSignalPhotons = new TCanvas("logPFChargedHadronIsoendcapMuMuSignalPhotons");

logPFChargedHadronIsoendcapMuMuSignalPhotons->SetLogy();
PFChargedHadronIsoendcapMuMuSignalPhotons0histo->Draw();

logPFChargedHadronIsoendcapMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFChargedHadronIso/logPFChargedHadronIso_endcap.pdf");

TCanvas* logPFChargedHadronIsoendcapMuMuAllPhotons = new TCanvas("logPFChargedHadronIsoendcapMuMuAllPhotons");

logPFChargedHadronIsoendcapMuMuAllPhotons->SetLogy();
PFChargedHadronIsoendcapMuMuAllPhotons0histo->Draw();

logPFChargedHadronIsoendcapMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFChargedHadronIso/logPFChargedHadronIso_endcap.pdf");

TCanvas* logPFChargedHadronIsoendcapEESignalPhotons = new TCanvas("logPFChargedHadronIsoendcapEESignalPhotons");

logPFChargedHadronIsoendcapEESignalPhotons->SetLogy();
PFChargedHadronIsoendcapEESignalPhotons0histo->Draw();

logPFChargedHadronIsoendcapEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFChargedHadronIso/logPFChargedHadronIso_endcap.pdf");

TCanvas* logPFChargedHadronIsoendcapEEAllPhotons = new TCanvas("logPFChargedHadronIsoendcapEEAllPhotons");

logPFChargedHadronIsoendcapEEAllPhotons->SetLogy();
PFChargedHadronIsoendcapEEAllPhotons0histo->Draw();

logPFChargedHadronIsoendcapEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFChargedHadronIso/logPFChargedHadronIso_endcap.pdf");

//PF Charged Hadron Isolation barrel
TH1D* PFChargedHadronIsobarrelMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_barrel_0btag");
TH1D* PFChargedHadronIsobarrelMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_barrel_1btag");
TH1D* PFChargedHadronIsobarrelMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_barrel_2btags");
TH1D* PFChargedHadronIsobarrelMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_barrel_3btags");
TH1D* PFChargedHadronIsobarrelMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_PFChargedHadronIso_barrel_4orMoreBtags");

PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(PFChargedHadronIsobarrelMuMuSignalPhotons1histo);
PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(PFChargedHadronIsobarrelMuMuSignalPhotons2histo);
PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(PFChargedHadronIsobarrelMuMuSignalPhotons3histo);
PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Add(PFChargedHadronIsobarrelMuMuSignalPhotons4histo);

TH1D* PFChargedHadronIsobarrelMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_barrel_0btag");
TH1D* PFChargedHadronIsobarrelMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_barrel_1btag");
TH1D* PFChargedHadronIsobarrelMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_barrel_2btags");
TH1D* PFChargedHadronIsobarrelMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_barrel_3btags");
TH1D* PFChargedHadronIsobarrelMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_PFChargedHadronIso_barrel_4orMoreBtags");

PFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(PFChargedHadronIsobarrelMuMuAllPhotons1histo);
PFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(PFChargedHadronIsobarrelMuMuAllPhotons2histo);
PFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(PFChargedHadronIsobarrelMuMuAllPhotons3histo);
PFChargedHadronIsobarrelMuMuAllPhotons0histo->Add(PFChargedHadronIsobarrelMuMuAllPhotons4histo);

TH1D* PFChargedHadronIsobarrelEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_barrel_0btag");
TH1D* PFChargedHadronIsobarrelEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_barrel_1btag");
TH1D* PFChargedHadronIsobarrelEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_barrel_2btags");
TH1D* PFChargedHadronIsobarrelEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_barrel_3btags");
TH1D* PFChargedHadronIsobarrelEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_PFChargedHadronIso_barrel_4orMoreBtags");

PFChargedHadronIsobarrelEESignalPhotons0histo->Add(PFChargedHadronIsobarrelEESignalPhotons1histo);
PFChargedHadronIsobarrelEESignalPhotons0histo->Add(PFChargedHadronIsobarrelEESignalPhotons2histo);
PFChargedHadronIsobarrelEESignalPhotons0histo->Add(PFChargedHadronIsobarrelEESignalPhotons3histo);
PFChargedHadronIsobarrelEESignalPhotons0histo->Add(PFChargedHadronIsobarrelEESignalPhotons4histo);

TH1D* PFChargedHadronIsobarrelEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_barrel_0btag");
TH1D* PFChargedHadronIsobarrelEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_barrel_1btag");
TH1D* PFChargedHadronIsobarrelEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_barrel_2btags");
TH1D* PFChargedHadronIsobarrelEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_barrel_3btags");
TH1D* PFChargedHadronIsobarrelEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_PFChargedHadronIso_barrel_4orMoreBtags");

PFChargedHadronIsobarrelEEAllPhotons0histo->Add(PFChargedHadronIsobarrelEEAllPhotons1histo);
PFChargedHadronIsobarrelEEAllPhotons0histo->Add(PFChargedHadronIsobarrelEEAllPhotons2histo);
PFChargedHadronIsobarrelEEAllPhotons0histo->Add(PFChargedHadronIsobarrelEEAllPhotons3histo);
PFChargedHadronIsobarrelEEAllPhotons0histo->Add(PFChargedHadronIsobarrelEEAllPhotons4histo);

TCanvas* PFChargedHadronIsobarrelMuMuSignalPhotons = new TCanvas("PFChargedHadronIsobarrelMuMuSignalPhotons");

PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Draw();

PFChargedHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFChargedHadronIso/PFChargedHadronIso_barrel.pdf");

TCanvas* PFChargedHadronIsobarrelMuMuAllPhotons = new TCanvas("PFChargedHadronIsobarrelMuMuAllPhotons");

PFChargedHadronIsobarrelMuMuAllPhotons0histo->Draw();

PFChargedHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFChargedHadronIso/PFChargedHadronIso_barrel.pdf");

TCanvas* PFChargedHadronIsobarrelEESignalPhotons = new TCanvas("PFChargedHadronIsobarrelEESignalPhotons");

PFChargedHadronIsobarrelEESignalPhotons0histo->Draw();

PFChargedHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFChargedHadronIso/PFChargedHadronIso_barrel.pdf");

TCanvas* PFChargedHadronIsobarrelEEAllPhotons = new TCanvas("PFChargedHadronIsobarrelEEAllPhotons");

PFChargedHadronIsobarrelEEAllPhotons0histo->Draw();

PFChargedHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFChargedHadronIso/PFChargedHadronIso_barrel.pdf");

TCanvas* logPFChargedHadronIsobarrelMuMuSignalPhotons = new TCanvas("logPFChargedHadronIsobarrelMuMuSignalPhotons");

logPFChargedHadronIsobarrelMuMuSignalPhotons->SetLogy();
PFChargedHadronIsobarrelMuMuSignalPhotons0histo->Draw();

logPFChargedHadronIsobarrelMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/PFChargedHadronIso/logPFChargedHadronIso_barrel.pdf");

TCanvas* logPFChargedHadronIsobarrelMuMuAllPhotons = new TCanvas("logPFChargedHadronIsobarrelMuMuAllPhotons");

logPFChargedHadronIsobarrelMuMuAllPhotons->SetLogy();
PFChargedHadronIsobarrelMuMuAllPhotons0histo->Draw();

logPFChargedHadronIsobarrelMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/PFChargedHadronIso/logPFChargedHadronIso_barrel.pdf");

TCanvas* logPFChargedHadronIsobarrelEESignalPhotons = new TCanvas("logPFChargedHadronIsobarrelEESignalPhotons");

logPFChargedHadronIsobarrelEESignalPhotons->SetLogy();
PFChargedHadronIsobarrelEESignalPhotons0histo->Draw();

logPFChargedHadronIsobarrelEESignalPhotons->SaveAs("plots/EE/SignalPhotons/PFChargedHadronIso/logPFChargedHadronIso_barrel.pdf");

TCanvas* logPFChargedHadronIsobarrelEEAllPhotons = new TCanvas("logPFChargedHadronIsobarrelEEAllPhotons");

logPFChargedHadronIsobarrelEEAllPhotons->SetLogy();
PFChargedHadronIsobarrelEEAllPhotons0histo->Draw();

logPFChargedHadronIsobarrelEEAllPhotons->SaveAs("plots/EE/AllPhotons/PFChargedHadronIso/logPFChargedHadronIso_barrel.pdf");

//Single Tower Hadron Calo Energy over Electromagnetic Calo Energy
TH1D* singleTowerHoEMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_HtowoE_0btag");
TH1D* singleTowerHoEMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_HtowoE_1btag");
TH1D* singleTowerHoEMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_HtowoE_2btags");
TH1D* singleTowerHoEMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_HtowoE_3btags");
TH1D* singleTowerHoEMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_HtowoE_4orMoreBtags");

singleTowerHoEMuMuSignalPhotons0histo->Add(singleTowerHoEMuMuSignalPhotons1histo);
singleTowerHoEMuMuSignalPhotons0histo->Add(singleTowerHoEMuMuSignalPhotons2histo);
singleTowerHoEMuMuSignalPhotons0histo->Add(singleTowerHoEMuMuSignalPhotons3histo);
singleTowerHoEMuMuSignalPhotons0histo->Add(singleTowerHoEMuMuSignalPhotons4histo);

TH1D* singleTowerHoEMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_HtowoE_0btag");
TH1D* singleTowerHoEMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_HtowoE_1btag");
TH1D* singleTowerHoEMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_HtowoE_2btags");
TH1D* singleTowerHoEMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_HtowoE_3btags");
TH1D* singleTowerHoEMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_HtowoE_4orMoreBtags");

singleTowerHoEMuMuAllPhotons0histo->Add(singleTowerHoEMuMuAllPhotons1histo);
singleTowerHoEMuMuAllPhotons0histo->Add(singleTowerHoEMuMuAllPhotons2histo);
singleTowerHoEMuMuAllPhotons0histo->Add(singleTowerHoEMuMuAllPhotons3histo);
singleTowerHoEMuMuAllPhotons0histo->Add(singleTowerHoEMuMuAllPhotons4histo);

TH1D* singleTowerHoEEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_HtowoE_0btag");
TH1D* singleTowerHoEEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_HtowoE_1btag");
TH1D* singleTowerHoEEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_HtowoE_2btags");
TH1D* singleTowerHoEEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_HtowoE_3btags");
TH1D* singleTowerHoEEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_HtowoE_4orMoreBtags");

singleTowerHoEEESignalPhotons0histo->Add(singleTowerHoEEESignalPhotons1histo);
singleTowerHoEEESignalPhotons0histo->Add(singleTowerHoEEESignalPhotons2histo);
singleTowerHoEEESignalPhotons0histo->Add(singleTowerHoEEESignalPhotons3histo);
singleTowerHoEEESignalPhotons0histo->Add(singleTowerHoEEESignalPhotons4histo);

TH1D* singleTowerHoEEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_HtowoE_0btag");
TH1D* singleTowerHoEEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_HtowoE_1btag");
TH1D* singleTowerHoEEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_HtowoE_2btags");
TH1D* singleTowerHoEEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_HtowoE_3btags");
TH1D* singleTowerHoEEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_HtowoE_4orMoreBtags");

singleTowerHoEEEAllPhotons0histo->Add(singleTowerHoEEEAllPhotons1histo);
singleTowerHoEEEAllPhotons0histo->Add(singleTowerHoEEEAllPhotons2histo);
singleTowerHoEEEAllPhotons0histo->Add(singleTowerHoEEEAllPhotons3histo);
singleTowerHoEEEAllPhotons0histo->Add(singleTowerHoEEEAllPhotons4histo);

TCanvas* singleTowerHoEMuMuSignalPhotons = new TCanvas("singleTowerHoEMuMuSignalPhotons");

singleTowerHoEMuMuSignalPhotons0histo->Draw();

singleTowerHoEMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/singleTowerHoE/singleTowerHoE.pdf");

TCanvas* singleTowerHoEMuMuAllPhotons = new TCanvas("singleTowerHoEMuMuAllPhotons");

singleTowerHoEMuMuAllPhotons0histo->Draw();

singleTowerHoEMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/singleTowerHoE/singleTowerHoE.pdf");

TCanvas* singleTowerHoEEESignalPhotons = new TCanvas("singleTowerHoEEESignalPhotons");

singleTowerHoEEESignalPhotons0histo->Draw();

singleTowerHoEEESignalPhotons->SaveAs("plots/EE/SignalPhotons/singleTowerHoE/singleTowerHoE.pdf");

TCanvas* singleTowerHoEEEAllPhotons = new TCanvas("singleTowerHoEEEAllPhotons");

singleTowerHoEEEAllPhotons0histo->Draw();

singleTowerHoEEEAllPhotons->SaveAs("plots/EE/AllPhotons/singleTowerHoE/singleTowerHoE.pdf");

TCanvas* logsingleTowerHoEMuMuSignalPhotons = new TCanvas("logsingleTowerHoEMuMuSignalPhotons");

logsingleTowerHoEMuMuSignalPhotons->SetLogy();
singleTowerHoEMuMuSignalPhotons0histo->Draw();

logsingleTowerHoEMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/singleTowerHoE/logsingleTowerHoE.pdf");

TCanvas* logsingleTowerHoEMuMuAllPhotons = new TCanvas("logsingleTowerHoEMuMuAllPhotons");

logsingleTowerHoEMuMuAllPhotons->SetLogy();
singleTowerHoEMuMuAllPhotons0histo->Draw();

logsingleTowerHoEMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/singleTowerHoE/logsingleTowerHoE.pdf");

TCanvas* logsingleTowerHoEEESignalPhotons = new TCanvas("logsingleTowerHoEEESignalPhotons");

logsingleTowerHoEEESignalPhotons->SetLogy();
singleTowerHoEEESignalPhotons0histo->Draw();

logsingleTowerHoEEESignalPhotons->SaveAs("plots/EE/SignalPhotons/singleTowerHoE/logsingleTowerHoE.pdf");

TCanvas* logsingleTowerHoEEEAllPhotons = new TCanvas("logsingleTowerHoEEEAllPhotons");

logsingleTowerHoEEEAllPhotons->SetLogy();
singleTowerHoEEEAllPhotons0histo->Draw();

logsingleTowerHoEEEAllPhotons->SaveAs("plots/EE/AllPhotons/singleTowerHoE/logsingleTowerHoE.pdf");

//Super Cluster Energy
TH1D* SCenergyMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCenergy_0btag");
TH1D* SCenergyMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCenergy_1btag");
TH1D* SCenergyMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCenergy_2btags");
TH1D* SCenergyMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCenergy_3btags");
TH1D* SCenergyMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCenergy_4orMoreBtags");

SCenergyMuMuSignalPhotons0histo->Add(SCenergyMuMuSignalPhotons1histo);
SCenergyMuMuSignalPhotons0histo->Add(SCenergyMuMuSignalPhotons2histo);
SCenergyMuMuSignalPhotons0histo->Add(SCenergyMuMuSignalPhotons3histo);
SCenergyMuMuSignalPhotons0histo->Add(SCenergyMuMuSignalPhotons4histo);

TH1D* SCenergyMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCenergy_0btag");
TH1D* SCenergyMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCenergy_1btag");
TH1D* SCenergyMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCenergy_2btags");
TH1D* SCenergyMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCenergy_3btags");
TH1D* SCenergyMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCenergy_4orMoreBtags");

SCenergyMuMuAllPhotons0histo->Add(SCenergyMuMuAllPhotons1histo);
SCenergyMuMuAllPhotons0histo->Add(SCenergyMuMuAllPhotons2histo);
SCenergyMuMuAllPhotons0histo->Add(SCenergyMuMuAllPhotons3histo);
SCenergyMuMuAllPhotons0histo->Add(SCenergyMuMuAllPhotons4histo);

TH1D* SCenergyEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCenergy_0btag");
TH1D* SCenergyEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCenergy_1btag");
TH1D* SCenergyEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCenergy_2btags");
TH1D* SCenergyEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCenergy_3btags");
TH1D* SCenergyEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCenergy_4orMoreBtags");

SCenergyEESignalPhotons0histo->Add(SCenergyEESignalPhotons1histo);
SCenergyEESignalPhotons0histo->Add(SCenergyEESignalPhotons2histo);
SCenergyEESignalPhotons0histo->Add(SCenergyEESignalPhotons3histo);
SCenergyEESignalPhotons0histo->Add(SCenergyEESignalPhotons4histo);

TH1D* SCenergyEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCenergy_0btag");
TH1D* SCenergyEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCenergy_1btag");
TH1D* SCenergyEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCenergy_2btags");
TH1D* SCenergyEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCenergy_3btags");
TH1D* SCenergyEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCenergy_4orMoreBtags");

SCenergyEEAllPhotons0histo->Add(SCenergyEEAllPhotons1histo);
SCenergyEEAllPhotons0histo->Add(SCenergyEEAllPhotons2histo);
SCenergyEEAllPhotons0histo->Add(SCenergyEEAllPhotons3histo);
SCenergyEEAllPhotons0histo->Add(SCenergyEEAllPhotons4histo);

TCanvas* SCenergyMuMuSignalPhotons = new TCanvas("SCenergyMuMuSignalPhotons");

SCenergyMuMuSignalPhotons0histo->Draw();

SCenergyMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCenergy/SCenergy.pdf");

TCanvas* SCenergyMuMuAllPhotons = new TCanvas("SCenergyMuMuAllPhotons");

SCenergyMuMuAllPhotons0histo->Draw();

SCenergyMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCenergy/SCenergy.pdf");

TCanvas* SCenergyEESignalPhotons = new TCanvas("SCenergyEESignalPhotons");

SCenergyEESignalPhotons0histo->Draw();

SCenergyEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCenergy/SCenergy.pdf");

TCanvas* SCenergyEEAllPhotons = new TCanvas("SCenergyEEAllPhotons");

SCenergyEEAllPhotons0histo->Draw();

SCenergyEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCenergy/SCenergy.pdf");

TCanvas* logSCenergyMuMuSignalPhotons = new TCanvas("logSCenergyMuMuSignalPhotons");

logSCenergyMuMuSignalPhotons->SetLogy();
SCenergyMuMuSignalPhotons0histo->Draw();

logSCenergyMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCenergy/logSCenergy.pdf");

TCanvas* logSCenergyMuMuAllPhotons = new TCanvas("logSCenergyMuMuAllPhotons");

logSCenergyMuMuAllPhotons->SetLogy();
SCenergyMuMuAllPhotons0histo->Draw();

logSCenergyMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCenergy/logSCenergy.pdf");

TCanvas* logSCenergyEESignalPhotons = new TCanvas("logSCenergyEESignalPhotons");

logSCenergyEESignalPhotons->SetLogy();
SCenergyEESignalPhotons0histo->Draw();

logSCenergyEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCenergy/logSCenergy.pdf");

TCanvas* logSCenergyEEAllPhotons = new TCanvas("logSCenergyEEAllPhotons");

logSCenergyEEAllPhotons->SetLogy();
SCenergyEEAllPhotons0histo->Draw();

logSCenergyEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCenergy/logSCenergy.pdf");

//Phi
TH1D* PhiMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Phi_0btag");
TH1D* PhiMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Phi_1btag");
TH1D* PhiMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Phi_2btags");
TH1D* PhiMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Phi_3btags");
TH1D* PhiMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_Phi_4orMoreBtags");

PhiMuMuSignalPhotons0histo->Add(PhiMuMuSignalPhotons1histo);
PhiMuMuSignalPhotons0histo->Add(PhiMuMuSignalPhotons2histo);
PhiMuMuSignalPhotons0histo->Add(PhiMuMuSignalPhotons3histo);
PhiMuMuSignalPhotons0histo->Add(PhiMuMuSignalPhotons4histo);

TH1D* PhiMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Phi_0btag");
TH1D* PhiMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Phi_1btag");
TH1D* PhiMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Phi_2btags");
TH1D* PhiMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Phi_3btags");
TH1D* PhiMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_Phi_4orMoreBtags");

PhiMuMuAllPhotons0histo->Add(PhiMuMuAllPhotons1histo);
PhiMuMuAllPhotons0histo->Add(PhiMuMuAllPhotons2histo);
PhiMuMuAllPhotons0histo->Add(PhiMuMuAllPhotons3histo);
PhiMuMuAllPhotons0histo->Add(PhiMuMuAllPhotons4histo);

TH1D* PhiEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Phi_0btag");
TH1D* PhiEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Phi_1btag");
TH1D* PhiEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Phi_2btags");
TH1D* PhiEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Phi_3btags");
TH1D* PhiEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_Phi_4orMoreBtags");

PhiEESignalPhotons0histo->Add(PhiEESignalPhotons1histo);
PhiEESignalPhotons0histo->Add(PhiEESignalPhotons2histo);
PhiEESignalPhotons0histo->Add(PhiEESignalPhotons3histo);
PhiEESignalPhotons0histo->Add(PhiEESignalPhotons4histo);

TH1D* PhiEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Phi_0btag");
TH1D* PhiEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Phi_1btag");
TH1D* PhiEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Phi_2btags");
TH1D* PhiEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Phi_3btags");
TH1D* PhiEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_Phi_4orMoreBtags");

PhiEEAllPhotons0histo->Add(PhiEEAllPhotons1histo);
PhiEEAllPhotons0histo->Add(PhiEEAllPhotons2histo);
PhiEEAllPhotons0histo->Add(PhiEEAllPhotons3histo);
PhiEEAllPhotons0histo->Add(PhiEEAllPhotons4histo);

TCanvas* PhiMuMuSignalPhotons = new TCanvas("PhiMuMuSignalPhotons");

PhiMuMuSignalPhotons0histo->Draw();

PhiMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/Phi/Phi.pdf");

TCanvas* PhiMuMuAllPhotons = new TCanvas("PhiMuMuAllPhotons");

PhiMuMuAllPhotons0histo->Draw();

PhiMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/Phi/Phi.pdf");

TCanvas* PhiEESignalPhotons = new TCanvas("PhiEESignalPhotons");

PhiEESignalPhotons0histo->Draw();

PhiEESignalPhotons->SaveAs("plots/EE/SignalPhotons/Phi/Phi.pdf");

TCanvas* PhiEEAllPhotons = new TCanvas("PhiEEAllPhotons");

PhiEEAllPhotons0histo->Draw();

PhiEEAllPhotons->SaveAs("plots/EE/AllPhotons/Phi/Phi.pdf");

//Absolute Eta (pseudorapidity)
TH1D* AbsEtaMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_AbsEta_0btag");
TH1D* AbsEtaMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_AbsEta_1btag");
TH1D* AbsEtaMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_AbsEta_2btags");
TH1D* AbsEtaMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_AbsEta_3btags");
TH1D* AbsEtaMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_AbsEta_4orMoreBtags");

AbsEtaMuMuSignalPhotons0histo->Add(AbsEtaMuMuSignalPhotons1histo);
AbsEtaMuMuSignalPhotons0histo->Add(AbsEtaMuMuSignalPhotons2histo);
AbsEtaMuMuSignalPhotons0histo->Add(AbsEtaMuMuSignalPhotons3histo);
AbsEtaMuMuSignalPhotons0histo->Add(AbsEtaMuMuSignalPhotons4histo);

TH1D* AbsEtaMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_AbsEta_0btag");
TH1D* AbsEtaMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_AbsEta_1btag");
TH1D* AbsEtaMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_AbsEta_2btags");
TH1D* AbsEtaMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_AbsEta_3btags");
TH1D* AbsEtaMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_AbsEta_4orMoreBtags");

AbsEtaMuMuAllPhotons0histo->Add(AbsEtaMuMuAllPhotons1histo);
AbsEtaMuMuAllPhotons0histo->Add(AbsEtaMuMuAllPhotons2histo);
AbsEtaMuMuAllPhotons0histo->Add(AbsEtaMuMuAllPhotons3histo);
AbsEtaMuMuAllPhotons0histo->Add(AbsEtaMuMuAllPhotons4histo);

TH1D* AbsEtaEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_AbsEta_0btag");
TH1D* AbsEtaEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_AbsEta_1btag");
TH1D* AbsEtaEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_AbsEta_2btags");
TH1D* AbsEtaEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_AbsEta_3btags");
TH1D* AbsEtaEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_AbsEta_4orMoreBtags");

AbsEtaEESignalPhotons0histo->Add(AbsEtaEESignalPhotons1histo);
AbsEtaEESignalPhotons0histo->Add(AbsEtaEESignalPhotons2histo);
AbsEtaEESignalPhotons0histo->Add(AbsEtaEESignalPhotons3histo);
AbsEtaEESignalPhotons0histo->Add(AbsEtaEESignalPhotons4histo);

TH1D* AbsEtaEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_AbsEta_0btag");
TH1D* AbsEtaEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_AbsEta_1btag");
TH1D* AbsEtaEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_AbsEta_2btags");
TH1D* AbsEtaEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_AbsEta_3btags");
TH1D* AbsEtaEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_AbsEta_4orMoreBtags");

AbsEtaEEAllPhotons0histo->Add(AbsEtaEEAllPhotons1histo);
AbsEtaEEAllPhotons0histo->Add(AbsEtaEEAllPhotons2histo);
AbsEtaEEAllPhotons0histo->Add(AbsEtaEEAllPhotons3histo);
AbsEtaEEAllPhotons0histo->Add(AbsEtaEEAllPhotons4histo);

TCanvas* AbsEtaMuMuSignalPhotons = new TCanvas("AbsEtaMuMuSignalPhotons");

AbsEtaMuMuSignalPhotons0histo->Draw();

AbsEtaMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/AbsEta/AbsEta.pdf");

TCanvas* AbsEtaMuMuAllPhotons = new TCanvas("AbsEtaMuMuAllPhotons");

AbsEtaMuMuAllPhotons0histo->Draw();

AbsEtaMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/AbsEta/AbsEta.pdf");

TCanvas* AbsEtaEESignalPhotons = new TCanvas("AbsEtaEESignalPhotons");

AbsEtaEESignalPhotons0histo->Draw();

AbsEtaEESignalPhotons->SaveAs("plots/EE/SignalPhotons/AbsEta/AbsEta.pdf");

TCanvas* AbsEtaEEAllPhotons = new TCanvas("AbsEtaEEAllPhotons");

AbsEtaEEAllPhotons0histo->Draw();

AbsEtaEEAllPhotons->SaveAs("plots/EE/AllPhotons/AbsEta/AbsEta.pdf");

//Super Cluster Seed Energy
TH1D* SCSeedEnergyMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCSeedEnergy_0btag");
TH1D* SCSeedEnergyMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCSeedEnergy_1btag");
TH1D* SCSeedEnergyMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCSeedEnergy_2btags");
TH1D* SCSeedEnergyMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCSeedEnergy_3btags");
TH1D* SCSeedEnergyMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCSeedEnergy_4orMoreBtags");

SCSeedEnergyMuMuSignalPhotons0histo->Add(SCSeedEnergyMuMuSignalPhotons1histo);
SCSeedEnergyMuMuSignalPhotons0histo->Add(SCSeedEnergyMuMuSignalPhotons2histo);
SCSeedEnergyMuMuSignalPhotons0histo->Add(SCSeedEnergyMuMuSignalPhotons3histo);
SCSeedEnergyMuMuSignalPhotons0histo->Add(SCSeedEnergyMuMuSignalPhotons4histo);

TH1D* SCSeedEnergyMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCSeedEnergy_0btag");
TH1D* SCSeedEnergyMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCSeedEnergy_1btag");
TH1D* SCSeedEnergyMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCSeedEnergy_2btags");
TH1D* SCSeedEnergyMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCSeedEnergy_3btags");
TH1D* SCSeedEnergyMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCSeedEnergy_4orMoreBtags");

SCSeedEnergyMuMuAllPhotons0histo->Add(SCSeedEnergyMuMuAllPhotons1histo);
SCSeedEnergyMuMuAllPhotons0histo->Add(SCSeedEnergyMuMuAllPhotons2histo);
SCSeedEnergyMuMuAllPhotons0histo->Add(SCSeedEnergyMuMuAllPhotons3histo);
SCSeedEnergyMuMuAllPhotons0histo->Add(SCSeedEnergyMuMuAllPhotons4histo);

TH1D* SCSeedEnergyEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCSeedEnergy_0btag");
TH1D* SCSeedEnergyEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCSeedEnergy_1btag");
TH1D* SCSeedEnergyEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCSeedEnergy_2btags");
TH1D* SCSeedEnergyEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCSeedEnergy_3btags");
TH1D* SCSeedEnergyEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCSeedEnergy_4orMoreBtags");

SCSeedEnergyEESignalPhotons0histo->Add(SCSeedEnergyEESignalPhotons1histo);
SCSeedEnergyEESignalPhotons0histo->Add(SCSeedEnergyEESignalPhotons2histo);
SCSeedEnergyEESignalPhotons0histo->Add(SCSeedEnergyEESignalPhotons3histo);
SCSeedEnergyEESignalPhotons0histo->Add(SCSeedEnergyEESignalPhotons4histo);

TH1D* SCSeedEnergyEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCSeedEnergy_0btag");
TH1D* SCSeedEnergyEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCSeedEnergy_1btag");
TH1D* SCSeedEnergyEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCSeedEnergy_2btags");
TH1D* SCSeedEnergyEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCSeedEnergy_3btags");
TH1D* SCSeedEnergyEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCSeedEnergy_4orMoreBtags");

SCSeedEnergyEEAllPhotons0histo->Add(SCSeedEnergyEEAllPhotons1histo);
SCSeedEnergyEEAllPhotons0histo->Add(SCSeedEnergyEEAllPhotons2histo);
SCSeedEnergyEEAllPhotons0histo->Add(SCSeedEnergyEEAllPhotons3histo);
SCSeedEnergyEEAllPhotons0histo->Add(SCSeedEnergyEEAllPhotons4histo);

TCanvas* SCSeedEnergyMuMuSignalPhotons = new TCanvas("SCSeedEnergyMuMuSignalPhotons");

SCSeedEnergyMuMuSignalPhotons0histo->Draw();

SCSeedEnergyMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCSeedEnergy/SCSeedEnergy.pdf");

TCanvas* SCSeedEnergyMuMuAllPhotons = new TCanvas("SCSeedEnergyMuMuAllPhotons");

SCSeedEnergyMuMuAllPhotons0histo->Draw();

SCSeedEnergyMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCSeedEnergy/SCSeedEnergy.pdf");

TCanvas* SCSeedEnergyEESignalPhotons = new TCanvas("SCSeedEnergyEESignalPhotons");

SCSeedEnergyEESignalPhotons0histo->Draw();

SCSeedEnergyEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCSeedEnergy/SCSeedEnergy.pdf");

TCanvas* SCSeedEnergyEEAllPhotons = new TCanvas("SCSeedEnergyEEAllPhotons");

SCSeedEnergyEEAllPhotons0histo->Draw();

SCSeedEnergyEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCSeedEnergy/SCSeedEnergy.pdf");

TCanvas* logSCSeedEnergyMuMuSignalPhotons = new TCanvas("logSCSeedEnergyMuMuSignalPhotons");

logSCSeedEnergyMuMuSignalPhotons->SetLogy();
SCSeedEnergyMuMuSignalPhotons0histo->Draw();

logSCSeedEnergyMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCSeedEnergy/logSCSeedEnergy.pdf");

TCanvas* logSCSeedEnergyMuMuAllPhotons = new TCanvas("logSCSeedEnergyMuMuAllPhotons");

logSCSeedEnergyMuMuAllPhotons->SetLogy();
SCSeedEnergyMuMuAllPhotons0histo->Draw();

logSCSeedEnergyMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCSeedEnergy/logSCSeedEnergy.pdf");

TCanvas* logSCSeedEnergyEESignalPhotons = new TCanvas("logSCSeedEnergyEESignalPhotons");

logSCSeedEnergyEESignalPhotons->SetLogy();
SCSeedEnergyEESignalPhotons0histo->Draw();

logSCSeedEnergyEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCSeedEnergy/logSCSeedEnergy.pdf");

TCanvas* logSCSeedEnergyEEAllPhotons = new TCanvas("logSCSeedEnergyEEAllPhotons");

logSCSeedEnergyEEAllPhotons->SetLogy();
SCSeedEnergyEEAllPhotons0histo->Draw();

logSCSeedEnergyEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCSeedEnergy/logSCSeedEnergy.pdf");

//Super Cluster Eta
TH1D* SCetaMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCeta_0btag");
TH1D* SCetaMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCeta_1btag");
TH1D* SCetaMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCeta_2btags");
TH1D* SCetaMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCeta_3btags");
TH1D* SCetaMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCeta_4orMoreBtags");

SCetaMuMuSignalPhotons0histo->Add(SCetaMuMuSignalPhotons1histo);
SCetaMuMuSignalPhotons0histo->Add(SCetaMuMuSignalPhotons2histo);
SCetaMuMuSignalPhotons0histo->Add(SCetaMuMuSignalPhotons3histo);
SCetaMuMuSignalPhotons0histo->Add(SCetaMuMuSignalPhotons4histo);

TH1D* SCetaMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCeta_0btag");
TH1D* SCetaMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCeta_1btag");
TH1D* SCetaMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCeta_2btags");
TH1D* SCetaMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCeta_3btags");
TH1D* SCetaMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCeta_4orMoreBtags");

SCetaMuMuAllPhotons0histo->Add(SCetaMuMuAllPhotons1histo);
SCetaMuMuAllPhotons0histo->Add(SCetaMuMuAllPhotons2histo);
SCetaMuMuAllPhotons0histo->Add(SCetaMuMuAllPhotons3histo);
SCetaMuMuAllPhotons0histo->Add(SCetaMuMuAllPhotons4histo);

TH1D* SCetaEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCeta_0btag");
TH1D* SCetaEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCeta_1btag");
TH1D* SCetaEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCeta_2btags");
TH1D* SCetaEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCeta_3btags");
TH1D* SCetaEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCeta_4orMoreBtags");

SCetaEESignalPhotons0histo->Add(SCetaEESignalPhotons1histo);
SCetaEESignalPhotons0histo->Add(SCetaEESignalPhotons2histo);
SCetaEESignalPhotons0histo->Add(SCetaEESignalPhotons3histo);
SCetaEESignalPhotons0histo->Add(SCetaEESignalPhotons4histo);

TH1D* SCetaEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCeta_0btag");
TH1D* SCetaEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCeta_1btag");
TH1D* SCetaEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCeta_2btags");
TH1D* SCetaEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCeta_3btags");
TH1D* SCetaEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCeta_4orMoreBtags");

SCetaEEAllPhotons0histo->Add(SCetaEEAllPhotons1histo);
SCetaEEAllPhotons0histo->Add(SCetaEEAllPhotons2histo);
SCetaEEAllPhotons0histo->Add(SCetaEEAllPhotons3histo);
SCetaEEAllPhotons0histo->Add(SCetaEEAllPhotons4histo);

TCanvas* SCetaMuMuSignalPhotons = new TCanvas("SCetaMuMuSignalPhotons");

SCetaMuMuSignalPhotons0histo->Draw();

SCetaMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCeta/SCeta.pdf");

TCanvas* SCetaMuMuAllPhotons = new TCanvas("SCetaMuMuAllPhotons");

SCetaMuMuAllPhotons0histo->Draw();

SCetaMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCeta/SCeta.pdf");

TCanvas* SCetaEESignalPhotons = new TCanvas("SCetaEESignalPhotons");

SCetaEESignalPhotons0histo->Draw();

SCetaEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCeta/SCeta.pdf");

TCanvas* SCetaEEAllPhotons = new TCanvas("SCetaEEAllPhotons");

SCetaEEAllPhotons0histo->Draw();

SCetaEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCeta/SCeta.pdf");

//Super Cluster Phi
TH1D* SCphiMuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCphi_0btag");
TH1D* SCphiMuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCphi_1btag");
TH1D* SCphiMuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCphi_2btags");
TH1D* SCphiMuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCphi_3btags");
TH1D* SCphiMuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_SCphi_4orMoreBtags");

SCphiMuMuSignalPhotons0histo->Add(SCphiMuMuSignalPhotons1histo);
SCphiMuMuSignalPhotons0histo->Add(SCphiMuMuSignalPhotons2histo);
SCphiMuMuSignalPhotons0histo->Add(SCphiMuMuSignalPhotons3histo);
SCphiMuMuSignalPhotons0histo->Add(SCphiMuMuSignalPhotons4histo);

TH1D* SCphiMuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCphi_0btag");
TH1D* SCphiMuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCphi_1btag");
TH1D* SCphiMuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCphi_2btags");
TH1D* SCphiMuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCphi_3btags");
TH1D* SCphiMuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_SCphi_4orMoreBtags");

SCphiMuMuAllPhotons0histo->Add(SCphiMuMuAllPhotons1histo);
SCphiMuMuAllPhotons0histo->Add(SCphiMuMuAllPhotons2histo);
SCphiMuMuAllPhotons0histo->Add(SCphiMuMuAllPhotons3histo);
SCphiMuMuAllPhotons0histo->Add(SCphiMuMuAllPhotons4histo);

TH1D* SCphiEESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCphi_0btag");
TH1D* SCphiEESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCphi_1btag");
TH1D* SCphiEESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCphi_2btags");
TH1D* SCphiEESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCphi_3btags");
TH1D* SCphiEESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_SCphi_4orMoreBtags");

SCphiEESignalPhotons0histo->Add(SCphiEESignalPhotons1histo);
SCphiEESignalPhotons0histo->Add(SCphiEESignalPhotons2histo);
SCphiEESignalPhotons0histo->Add(SCphiEESignalPhotons3histo);
SCphiEESignalPhotons0histo->Add(SCphiEESignalPhotons4histo);

TH1D* SCphiEEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCphi_0btag");
TH1D* SCphiEEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCphi_1btag");
TH1D* SCphiEEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCphi_2btags");
TH1D* SCphiEEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCphi_3btags");
TH1D* SCphiEEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_SCphi_4orMoreBtags");

SCphiEEAllPhotons0histo->Add(SCphiEEAllPhotons1histo);
SCphiEEAllPhotons0histo->Add(SCphiEEAllPhotons2histo);
SCphiEEAllPhotons0histo->Add(SCphiEEAllPhotons3histo);
SCphiEEAllPhotons0histo->Add(SCphiEEAllPhotons4histo);

TCanvas* SCphiMuMuSignalPhotons = new TCanvas("SCphiMuMuSignalPhotons");

SCphiMuMuSignalPhotons0histo->Draw();

SCphiMuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/SCphi/SCphi.pdf");

TCanvas* SCphiMuMuAllPhotons = new TCanvas("SCphiMuMuAllPhotons");

SCphiMuMuAllPhotons0histo->Draw();

SCphiMuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/SCphi/SCphi.pdf");

TCanvas* SCphiEESignalPhotons = new TCanvas("SCphiEESignalPhotons");

SCphiEESignalPhotons0histo->Draw();

SCphiEESignalPhotons->SaveAs("plots/EE/SignalPhotons/SCphi/SCphi.pdf");

TCanvas* SCphiEEAllPhotons = new TCanvas("SCphiEEAllPhotons");

SCphiEEAllPhotons0histo->Draw();

SCphiEEAllPhotons->SaveAs("plots/EE/AllPhotons/SCphi/SCphi.pdf");

//5x5 PbWO4 lead tungstate scintillating crystals
TH1D* E5x5MuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E5x5_0btag");
TH1D* E5x5MuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E5x5_1btag");
TH1D* E5x5MuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E5x5_2btags");
TH1D* E5x5MuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E5x5_3btags");
TH1D* E5x5MuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E5x5_4orMoreBtags");

E5x5MuMuSignalPhotons0histo->Add(E5x5MuMuSignalPhotons1histo);
E5x5MuMuSignalPhotons0histo->Add(E5x5MuMuSignalPhotons2histo);
E5x5MuMuSignalPhotons0histo->Add(E5x5MuMuSignalPhotons3histo);
E5x5MuMuSignalPhotons0histo->Add(E5x5MuMuSignalPhotons4histo);

TH1D* E5x5MuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E5x5_0btag");
TH1D* E5x5MuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E5x5_1btag");
TH1D* E5x5MuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E5x5_2btags");
TH1D* E5x5MuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E5x5_3btags");
TH1D* E5x5MuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E5x5_4orMoreBtags");

E5x5MuMuAllPhotons0histo->Add(E5x5MuMuAllPhotons1histo);
E5x5MuMuAllPhotons0histo->Add(E5x5MuMuAllPhotons2histo);
E5x5MuMuAllPhotons0histo->Add(E5x5MuMuAllPhotons3histo);
E5x5MuMuAllPhotons0histo->Add(E5x5MuMuAllPhotons4histo);

TH1D* E5x5EESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E5x5_0btag");
TH1D* E5x5EESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E5x5_1btag");
TH1D* E5x5EESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E5x5_2btags");
TH1D* E5x5EESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E5x5_3btags");
TH1D* E5x5EESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E5x5_4orMoreBtags");

E5x5EESignalPhotons0histo->Add(E5x5EESignalPhotons1histo);
E5x5EESignalPhotons0histo->Add(E5x5EESignalPhotons2histo);
E5x5EESignalPhotons0histo->Add(E5x5EESignalPhotons3histo);
E5x5EESignalPhotons0histo->Add(E5x5EESignalPhotons4histo);

TH1D* E5x5EEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E5x5_0btag");
TH1D* E5x5EEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E5x5_1btag");
TH1D* E5x5EEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E5x5_2btags");
TH1D* E5x5EEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E5x5_3btags");
TH1D* E5x5EEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E5x5_4orMoreBtags");

E5x5EEAllPhotons0histo->Add(E5x5EEAllPhotons1histo);
E5x5EEAllPhotons0histo->Add(E5x5EEAllPhotons2histo);
E5x5EEAllPhotons0histo->Add(E5x5EEAllPhotons3histo);
E5x5EEAllPhotons0histo->Add(E5x5EEAllPhotons4histo);

TCanvas* E5x5MuMuSignalPhotons = new TCanvas("E5x5MuMuSignalPhotons");

E5x5MuMuSignalPhotons0histo->Draw();

E5x5MuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/E5x5/E5x5.pdf");

TCanvas* E5x5MuMuAllPhotons = new TCanvas("E5x5MuMuAllPhotons");

E5x5MuMuAllPhotons0histo->Draw();

E5x5MuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/E5x5/E5x5.pdf");

TCanvas* E5x5EESignalPhotons = new TCanvas("E5x5EESignalPhotons");

E5x5EESignalPhotons0histo->Draw();

E5x5EESignalPhotons->SaveAs("plots/EE/SignalPhotons/E5x5/E5x5.pdf");

TCanvas* E5x5EEAllPhotons = new TCanvas("E5x5EEAllPhotons");

E5x5EEAllPhotons0histo->Draw();

E5x5EEAllPhotons->SaveAs("plots/EE/AllPhotons/E5x5/E5x5.pdf");

TCanvas* logE5x5MuMuSignalPhotons = new TCanvas("logE5x5MuMuSignalPhotons");

logE5x5MuMuSignalPhotons->SetLogy();
E5x5MuMuSignalPhotons0histo->Draw();

logE5x5MuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/E5x5/logE5x5.pdf");

TCanvas* logE5x5MuMuAllPhotons = new TCanvas("logE5x5MuMuAllPhotons");

logE5x5MuMuAllPhotons->SetLogy();
E5x5MuMuAllPhotons0histo->Draw();

logE5x5MuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/E5x5/logE5x5.pdf");

TCanvas* logE5x5EESignalPhotons = new TCanvas("logE5x5EESignalPhotons");

logE5x5EESignalPhotons->SetLogy();
E5x5EESignalPhotons0histo->Draw();

logE5x5EESignalPhotons->SaveAs("plots/EE/SignalPhotons/E5x5/logE5x5.pdf");

TCanvas* logE5x5EEAllPhotons = new TCanvas("logE5x5EEAllPhotons");

logE5x5EEAllPhotons->SetLogy();
E5x5EEAllPhotons0histo->Draw();

logE5x5EEAllPhotons->SaveAs("plots/EE/AllPhotons/E5x5/logE5x5.pdf");

//3x3 PbWO4 lead tungstate scintillating crystals
TH1D* E3x3MuMuSignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E3x3_0btag");
TH1D* E3x3MuMuSignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E3x3_1btag");
TH1D* E3x3MuMuSignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E3x3_2btags");
TH1D* E3x3MuMuSignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E3x3_3btags");
TH1D* E3x3MuMuSignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/SignalPhotons/Photon_E3x3_4orMoreBtags");

E3x3MuMuSignalPhotons0histo->Add(E3x3MuMuSignalPhotons1histo);
E3x3MuMuSignalPhotons0histo->Add(E3x3MuMuSignalPhotons2histo);
E3x3MuMuSignalPhotons0histo->Add(E3x3MuMuSignalPhotons3histo);
E3x3MuMuSignalPhotons0histo->Add(E3x3MuMuSignalPhotons4histo);

TH1D* E3x3MuMuAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E3x3_0btag");
TH1D* E3x3MuMuAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E3x3_1btag");
TH1D* E3x3MuMuAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E3x3_2btags");
TH1D* E3x3MuMuAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E3x3_3btags");
TH1D* E3x3MuMuAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/MuMu/AllPhotons/Photon_E3x3_4orMoreBtags");

E3x3MuMuAllPhotons0histo->Add(E3x3MuMuAllPhotons1histo);
E3x3MuMuAllPhotons0histo->Add(E3x3MuMuAllPhotons2histo);
E3x3MuMuAllPhotons0histo->Add(E3x3MuMuAllPhotons3histo);
E3x3MuMuAllPhotons0histo->Add(E3x3MuMuAllPhotons4histo);

TH1D* E3x3EESignalPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E3x3_0btag");
TH1D* E3x3EESignalPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E3x3_1btag");
TH1D* E3x3EESignalPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E3x3_2btags");
TH1D* E3x3EESignalPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E3x3_3btags");
TH1D* E3x3EESignalPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/SignalPhotons/Photon_E3x3_4orMoreBtags");

E3x3EESignalPhotons0histo->Add(E3x3EESignalPhotons1histo);
E3x3EESignalPhotons0histo->Add(E3x3EESignalPhotons2histo);
E3x3EESignalPhotons0histo->Add(E3x3EESignalPhotons3histo);
E3x3EESignalPhotons0histo->Add(E3x3EESignalPhotons4histo);

TH1D* E3x3EEAllPhotons0histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E3x3_0btag");
TH1D* E3x3EEAllPhotons1histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E3x3_1btag");
TH1D* E3x3EEAllPhotons2histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E3x3_2btags");
TH1D* E3x3EEAllPhotons3histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E3x3_3btags");
TH1D* E3x3EEAllPhotons4histo = (TH1D*)ttgamma->Get("PhotonAnalysis/EE/AllPhotons/Photon_E3x3_4orMoreBtags");

E3x3EEAllPhotons0histo->Add(E3x3EEAllPhotons1histo);
E3x3EEAllPhotons0histo->Add(E3x3EEAllPhotons2histo);
E3x3EEAllPhotons0histo->Add(E3x3EEAllPhotons3histo);
E3x3EEAllPhotons0histo->Add(E3x3EEAllPhotons4histo);

TCanvas* E3x3MuMuSignalPhotons = new TCanvas("E3x3MuMuSignalPhotons");

E3x3MuMuSignalPhotons0histo->Draw();

E3x3MuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/E3x3/E3x3.pdf");

TCanvas* E3x3MuMuAllPhotons = new TCanvas("E3x3MuMuAllPhotons");

E3x3MuMuAllPhotons0histo->Draw();

E3x3MuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/E3x3/E3x3.pdf");

TCanvas* E3x3EESignalPhotons = new TCanvas("E3x3EESignalPhotons");

E3x3EESignalPhotons0histo->Draw();

E3x3EESignalPhotons->SaveAs("plots/EE/SignalPhotons/E3x3/E3x3.pdf");

TCanvas* E3x3EEAllPhotons = new TCanvas("E3x3EEAllPhotons");

E3x3EEAllPhotons0histo->Draw();

E3x3EEAllPhotons->SaveAs("plots/EE/AllPhotons/E3x3/E3x3.pdf");

TCanvas* logE3x3MuMuSignalPhotons = new TCanvas("logE3x3MuMuSignalPhotons");

logE3x3MuMuSignalPhotons->SetLogy();
E3x3MuMuSignalPhotons0histo->Draw();

logE3x3MuMuSignalPhotons->SaveAs("plots/MuMu/SignalPhotons/E3x3/logE3x3.pdf");

TCanvas* logE3x3MuMuAllPhotons = new TCanvas("logE3x3MuMuAllPhotons");

logE3x3MuMuAllPhotons->SetLogy();
E3x3MuMuAllPhotons0histo->Draw();

logE3x3MuMuAllPhotons->SaveAs("plots/MuMu/AllPhotons/E3x3/logE3x3.pdf");

TCanvas* logE3x3EESignalPhotons = new TCanvas("logE3x3EESignalPhotons");

logE3x3EESignalPhotons->SetLogy();
E3x3EESignalPhotons0histo->Draw();

logE3x3EESignalPhotons->SaveAs("plots/EE/SignalPhotons/E3x3/logE3x3.pdf");

TCanvas* logE3x3EEAllPhotons = new TCanvas("logE3x3EEAllPhotons");

logE3x3EEAllPhotons->SetLogy();
E3x3EEAllPhotons0histo->Draw();

logE3x3EEAllPhotons->SaveAs("plots/EE/AllPhotons/E3x3/logE3x3.pdf");

}
