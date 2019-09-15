//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Sep 13 00:22:27 2019 by ROOT version 6.12/07
// from TTree pulse_tree/
// found on file: root://xrootd-cms.infn.it//store/group/dpg_ecal/comm_ecal/localreco/pulseshapes/2018/Run2018D/runs323841_324022/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root
//////////////////////////////////////////////////////////

#ifndef pulseplots_h
#define pulseplots_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class pulseplots {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Bool_t          barrel;
   UInt_t          gain;
   Double_t        pedrms;
   Double_t        pedval;
   Int_t           ietaix;
   Int_t           iphiiy;
   Int_t           iz;
   Double_t        pulse[10];
   UInt_t          rawid;
   Double_t        ene;
   Double_t        time;
   Double_t        chi2;
   Int_t           flag_kweird;
   Int_t           flag_kdiweird;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_barrel;   //!
   TBranch        *b_gain;   //!
   TBranch        *b_pedrms;   //!
   TBranch        *b_pedval;   //!
   TBranch        *b_ietaix;   //!
   TBranch        *b_iphiiy;   //!
   TBranch        *b_iz;   //!
   TBranch        *b_pulse;   //!
   TBranch        *b_rawid;   //!
   TBranch        *b_ene;   //!
   TBranch        *b_time;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_flag_kweird;   //!
   TBranch        *b_flag_kdiweird;   //!

   pulseplots(TTree *tree=0);
   virtual ~pulseplots();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef pulseplots_cxx
pulseplots::pulseplots(TTree *tree) : fChain(0) 
{

  /*
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://xrootd-cms.infn.it///store/group/dpg_ecal/comm_ecal/localreco/pulseshapes/2018/Run2018D/runs323841_324022/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root");
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/cms/store/group/dpg_ecal/comm_ecal/localreco/pulseshapes/2018/Run2018D/runs323841_324022/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/cms/store/group/dpg_ecal/comm_ecal/localreco/pulseshapes/2018/Run2018D/runs323841_324022/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/cms/store/group/dpg_ecal/comm_ecal/localreco/pulseshapes/2018/Run2018D/runs323841_324022/AlCaPhiSym_Run2018D-v1_runs323841_324022_62.root:/pulseDump");
      dir->GetObject("pulse_tree",tree);

   }
   Init(tree);
  */
}

pulseplots::~pulseplots()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t pulseplots::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t pulseplots::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void pulseplots::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("barrel", &barrel, &b_barrel);
   fChain->SetBranchAddress("gain", &gain, &b_gain);
   fChain->SetBranchAddress("pedrms", &pedrms, &b_pedrms);
   fChain->SetBranchAddress("pedval", &pedval, &b_pedval);
   fChain->SetBranchAddress("ietaix", &ietaix, &b_ietaix);
   fChain->SetBranchAddress("iphiiy", &iphiiy, &b_iphiiy);
   fChain->SetBranchAddress("iz", &iz, &b_iz);
   fChain->SetBranchAddress("pulse", pulse, &b_pulse);
   fChain->SetBranchAddress("rawid", &rawid, &b_rawid);
   fChain->SetBranchAddress("ene", &ene, &b_ene);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("flag_kweird", &flag_kweird, &b_flag_kweird);
   fChain->SetBranchAddress("flag_kdiweird", &flag_kdiweird, &b_flag_kdiweird);
   Notify();
}

Bool_t pulseplots::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void pulseplots::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t pulseplots::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef pulseplots_cxx
