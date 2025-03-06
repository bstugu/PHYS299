//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  2 10:56:16 2023 by ROOT version 6.24/02
// from TTree CollectionTree/Tree from Delphes
// found on file: flat_hee.root
//////////////////////////////////////////////////////////

#ifndef hee_h
#define hee_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class hee {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         true_gamma_pt;
   Float_t         true_gamma_eta;
   Float_t         true_gamma_phi;
   Float_t         true_elepos_pt;
   Float_t         true_elepos_eta;
   Float_t         true_elepos_phi;
   Float_t         true_eleneg_pt;
   Float_t         true_eleneg_eta;
   Float_t         true_eleneg_phi;
   Float_t         reco_gamma_pt;
   Float_t         reco_gamma_eta;
   Float_t         reco_gamma_phi;
   Float_t         reco_ele1_pt;
   Float_t         reco_ele1_eta;
   Float_t         reco_ele1_phi;
   Float_t         reco_ele1_charge;
   Float_t         reco_ele2_pt;
   Float_t         reco_ele2_eta;
   Float_t         reco_ele2_phi;
   Float_t         reco_ele2_charge;
   Float_t         met;
   Float_t         met_phi;

   // List of branches
   TBranch        *b_true_gamma_pt;   //!
   TBranch        *b_true_gamma_eta;   //!
   TBranch        *b_true_gamma_phi;   //!
   TBranch        *b_true_elepos_pt;   //!
   TBranch        *b_true_elepos_eta;   //!
   TBranch        *b_true_elepos_phi;   //!
   TBranch        *b_true_eleneg_pt;   //!
   TBranch        *b_true_eleneg_eta;   //!
   TBranch        *b_true_eleneg_phi;   //!
   TBranch        *b_reco_gamma_pt;   //!
   TBranch        *b_reco_gamma_eta;   //!
   TBranch        *b_reco_gamma_phi;   //!
   TBranch        *b_reco_ele1_pt;   //!
   TBranch        *b_reco_ele1_eta;   //!
   TBranch        *b_reco_ele1_phi;   //!
   TBranch        *b_reco_ele1_charge;   //!
   TBranch        *b_reco_ele2_pt;   //!
   TBranch        *b_reco_ele2_eta;   //!
   TBranch        *b_reco_ele2_phi;   //!
   TBranch        *b_reco_ele2_charge;   //!
   TBranch        *b_met;   //!
   TBranch        *b_met_phi;   //!

   hee(TTree *tree=0);
   virtual ~hee();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef hee_cxx
hee::hee(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("flat_hee.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("flat_hee.root");
      }
      f->GetObject("CollectionTree",tree);

   }
   Init(tree);
}

hee::~hee()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t hee::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t hee::LoadTree(Long64_t entry)
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

void hee::Init(TTree *tree)
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

   fChain->SetBranchAddress("true_gamma_pt", &true_gamma_pt, &b_true_gamma_pt);
   fChain->SetBranchAddress("true_gamma_eta", &true_gamma_eta, &b_true_gamma_eta);
   fChain->SetBranchAddress("true_gamma_phi", &true_gamma_phi, &b_true_gamma_phi);
   fChain->SetBranchAddress("true_elepos_pt", &true_elepos_pt, &b_true_elepos_pt);
   fChain->SetBranchAddress("true_elepos_eta", &true_elepos_eta, &b_true_elepos_eta);
   fChain->SetBranchAddress("true_elepos_phi", &true_elepos_phi, &b_true_elepos_phi);
   fChain->SetBranchAddress("true_eleneg_pt", &true_eleneg_pt, &b_true_eleneg_pt);
   fChain->SetBranchAddress("true_eleneg_eta", &true_eleneg_eta, &b_true_eleneg_eta);
   fChain->SetBranchAddress("true_eleneg_phi", &true_eleneg_phi, &b_true_eleneg_phi);
   fChain->SetBranchAddress("reco_gamma_pt", &reco_gamma_pt, &b_reco_gamma_pt);
   fChain->SetBranchAddress("reco_gamma_eta", &reco_gamma_eta, &b_reco_gamma_eta);
   fChain->SetBranchAddress("reco_gamma_phi", &reco_gamma_phi, &b_reco_gamma_phi);
   fChain->SetBranchAddress("reco_ele1_pt", &reco_ele1_pt, &b_reco_ele1_pt);
   fChain->SetBranchAddress("reco_ele1_eta", &reco_ele1_eta, &b_reco_ele1_eta);
   fChain->SetBranchAddress("reco_ele1_phi", &reco_ele1_phi, &b_reco_ele1_phi);
   fChain->SetBranchAddress("reco_ele1_charge", &reco_ele1_charge, &b_reco_ele1_charge);
   fChain->SetBranchAddress("reco_ele2_pt", &reco_ele2_pt, &b_reco_ele2_pt);
   fChain->SetBranchAddress("reco_ele2_eta", &reco_ele2_eta, &b_reco_ele2_eta);
   fChain->SetBranchAddress("reco_ele2_phi", &reco_ele2_phi, &b_reco_ele2_phi);
   fChain->SetBranchAddress("reco_ele2_charge", &reco_ele2_charge, &b_reco_ele2_charge);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   Notify();
}

Bool_t hee::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void hee::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t hee::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef hee_cxx
