#define hee_cxx
#include "hee.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>   // the package to create and handle relativistic 4-vectors

void hee::Loop()
{
//   In a ROOT session, you can do:
//      root> .L hee.C
//      root> hee t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
// 
// Bestille histogrammer:
//       
   TH1F h_true_elepos_pt("true_elepos_pt","Sann pt til positron",100,0.0,300.0);
   TH2F h_navn("navn","pt til positron mot pt til reconstruert elektron 1",50,0.0,100,50,0.0,100);
   TH1F h_mee_rec("mee_rec","electron-positron invariant mass, reconstructed",60,110,140);
   // count events analyzed
   int myCounter = 0;
   // Define file to store my histograms
   TFile myOutputFile("histogrammer.root","RECREATE");
   // define objects of type 4-vector (TLorentzVector)
   TLorentzVector e1_rec_4v,e2_rec_4v;
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      
      // My own code:
      myCounter++;
      h_true_elepos_pt.Fill(true_elepos_pt);
      h_navn.Fill(true_elepos_pt,reco_ele1_pt);
      // create 4-vectors from eta,phi,pt in order to easily compute invariant mass (electron mass is 0.000511 GeV)
      e1_rec_4v.SetPtEtaPhiM(reco_ele1_pt,reco_ele1_eta,reco_ele1_phi,0.000511);
      e2_rec_4v.SetPtEtaPhiM(reco_ele2_pt,reco_ele2_eta,reco_ele2_phi,0.000511);
      // This magic gives you the invariant mass of the e1-e2 pair! 
      Double_t me1e2_rec = (e1_rec_4v + e2_rec_4v).M();
      // fill the histograam
      h_mee_rec.Fill(me1e2_rec);      
      
      
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
   // Avslutning og oppsummering
   cout <<  " ====================Antall analysert " << myCounter << endl;
   // Store all my histograms, one by one  
   h_true_elepos_pt.Write();
   h_navn.Write();
   h_mee_rec.Write();
   myOutputFile.Close();
}
