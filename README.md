These are n-tuples containing simulations of some Higgs bosons produced in gluon-gluon fusion in selected decay channels. 
(e+e-,Z(->e+e-)gammma,mu+mu-,(Z->mu+mu1)gamma) and reconstructed with Delphes.

Root Analysis skeleton is created by the root commands 
TFile *f = new TFile("flat_hzgamma_ee.root")

f->ls()  // Finne navn på rett TTree.  The name is CollectionTree

CollectionTree->MakeClass("hee")


In hee.C you can find instructions of how to run the analysis
In hee.h you find the names of all variables.
n-tuple "flat_hee.root" can be analyzed with the same code if you change the name of the file to be connected in hee.h 
