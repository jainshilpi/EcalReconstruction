#define pulseplots_cxx
#include "pulseplots.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void pulseplots::Loop()
{
  
  TFile *f = new TFile("/net/data_cms/cmspos/ECAL/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root");
  TDirectory * dir = (TDirectory*)f->Get("net/data_cms/cmspos/ECAL/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root:/pulseDump");
  TTree *tree = new TTree();
  dir->GetObject("pulse_tree",tree);   
  Init(tree);
  
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   double time[10] = {25*0, 25*1, 25*2, 25*3, 25*4, 25*5, 25*6, 25*7, 25*8, 25*9};

   double ADC[10];
   Long64_t nbytes = 0, nb = 0;

   bool gotNicePulse = false;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      for(int ipulse=0; ipulse<10; ipulse++){
	
	if(pulse[0] > 10) continue;
	if(pulse[5] > 500) continue;
	
	ADC[ipulse] = pulse[ipulse];
      }//for(int ipulse=0; ipulse<10; ipulse++)
      
	if(gotNicePulse) 
	  break;

   }

   TGraph *g = new TGraph(10,time, ADC);
   g->SetMarkerStyle(20);
   g->Draw("ACP");
}
