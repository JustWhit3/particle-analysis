#include <iostream>
#include <cmath>
#include "../include/ParticleType.h"
#include "../include/ResonanceType.h"
#include "../include/Particle.h"
#include "TRandom.h"
#include "TBenchmark.h"
#include "TH1F.h"
#include "TStyle.h"
#include "TH1D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include "TLegend.h"

double fi (double *x, double *y)
{return y[0] + x[0] * y[1];}

void Analysis ()
{
TFile *file = new TFile("../histograms.root");
file->ls();

TH1D * type = (TH1D *)file->Get("TypeP");
type->GetXaxis()->SetTitle("Particles");
type->GetXaxis()->CenterTitle(true);
type->GetYaxis()->SetTitle("Counts");
type->SetFillColor(kGreen-9);
        
TH1D * phi = (TH1D *)file->Get("PhiGraph");
phi->GetXaxis()->SetTitle("Phi");
phi->GetYaxis()->SetTitle("Counts");
        
TH1D * theta = (TH1D *)file->Get("ThetaGraph");
theta->GetXaxis()->SetTitle("Theta");
theta->GetYaxis()->SetTitle("Counts");
        
TH1D * impulse = (TH1D *)file->Get("Impulse");
impulse->GetXaxis()->SetTitle("Impulse [GeV/c]");
impulse->GetYaxis()->SetTitle("Counts");
        
TH1D * cross = (TH1D *)file->Get("CrossImpulse");
cross->GetXaxis()->SetTitle("Cross Impulse [GeV/c]");
cross->GetYaxis()->SetTitle("Counts");
        
TH1D * energy = (TH1D *)file->Get("Energy");
energy->GetXaxis()->SetTitle("Energy [GeV/c^2]");
energy->GetYaxis()->SetTitle("Counts");
energy->SetFillColor(kCyan-7);                                
        
TH1D * inv_mass = (TH1D *)file->Get("InvariantMass");
inv_mass->GetXaxis()->SetTitle("Invariant Mass [GeV/c^2]");
inv_mass->GetYaxis()->SetTitle("Counts");
inv_mass->SetFillColor(kRed-9);
        
TH1D * inv_mass_discorde = (TH1D *)file->Get("InvMassDisc");
inv_mass_discorde->GetXaxis()->SetTitle("Invariant Discord Mass [GeV/c^2]");
inv_mass_discorde->GetYaxis()->SetTitle("Counts");
inv_mass_discorde->SetFillColor(kOrange-3);
        
TH1D * inv_mass_concorde = (TH1D *)file->Get("InvMassConc");
inv_mass_concorde->GetXaxis()->SetTitle("Invariant Concord Mass [GeV/c^2]");
inv_mass_concorde->GetYaxis()->SetTitle("Counts");
inv_mass_concorde->SetFillColor(kOrange-3);
        
TH1D * inv_mass_pkd = (TH1D *)file->Get("InvMassPKDisc");
inv_mass_pkd->GetXaxis()->SetTitle("Invariant Discord Mass of P and K [GeV/c^2]");
inv_mass_pkd->GetYaxis()->SetTitle("Counts");
inv_mass_pkd->SetFillColor(kYellow-9);
        
TH1D * inv_mass_pkc = (TH1D *)file->Get("InvMassPKConc");
inv_mass_pkc->GetXaxis()->SetTitle("Invariant Concord Mass of P and K [GeV/c^2]");
inv_mass_pkc->GetYaxis()->SetTitle("Counts");
inv_mass_pkc->SetFillColor(kYellow-9);
        
TH1D * inv_mass_res = (TH1D *)file->Get("InvMassGen");
inv_mass_res->GetXaxis()->SetTitle("Invariant Mass of generated Particles [GeV/c^2]");
inv_mass_res->GetYaxis()->SetTitle("Counts");

cout <<endl;

double positive_pion = type->GetBinContent(1);
double positive_pion_error = type->GetBinError(1);
cout << "Pions+ : " << positive_pion << " +- " << positive_pion_error 
<< " generations -> " << (positive_pion*100)/1e7 << "%" << '\n';
double negative_pion = type->GetBinContent(2);
double negative_pion_error = type->GetBinError(2);
cout << "Pions- : " << negative_pion << " +- " << negative_pion_error
<< " generations -> " << (negative_pion*100)/1e7 << "%" << '\n';
double positive_kaon = type->GetBinContent(3);
double positive_kaon_error = type->GetBinError(3);
cout << "Kaons+ : " << positive_kaon << " +- " << positive_kaon_error
<< " generations -> " << (positive_kaon*100)/1e7 << "%" << '\n';
double negative_kaon = type->GetBinContent(4);
double negative_kaon_error = type->GetBinError(4);
cout << "Kaons- : " << negative_kaon << " +- " << negative_kaon_error
<< " generations -> " << (negative_kaon*100)/1e7 << "%" << '\n';
double positive_proton = type->GetBinContent(5);
double positive_proton_error = type->GetBinError(5);
cout << "Protons+ : " << positive_proton << " +- " << positive_proton_error
<< " generations -> " << (positive_proton*100)/1e7 << "%" << '\n';
double negative_proton = type->GetBinContent(6);
double negative_proton_error = type->GetBinError(6);
cout << "Protons- : " << negative_proton << " +- " << negative_proton_error
<< " generations -> " << (negative_proton*100)/1e7 << "%" << '\n';
double resonance = type->GetBinContent(7);
double resonance_error = type->GetBinError(7);
cout << "K* : " << resonance << " +- " << resonance_error
<< " generations -> " << (resonance*100)/1e7 << "%" << '\n';

cout << endl;
double sum, sum_error;
sum = positive_pion + negative_pion + positive_kaon + negative_kaon + positive_proton + negative_proton + resonance;
sum_error = positive_pion_error + negative_pion_error + positive_kaon_error + negative_kaon_error +
positive_proton_error + negative_proton_error + resonance_error;
cout << "Total number of entries is: " << sum << " +- " << sum_error <<endl
<< "In percentage: " << (sum*100)/1e7 << "%" <<endl <<endl;

double *ptr = new double[2];

//CANVAS A.
TCanvas *CanvasA = new TCanvas ( "CanvasA", "Abundance of particles distributions, impulse, polar angle e azimuthal angle",
50, 10, 1200, 700);
CanvasA->Divide(2,2);
CanvasA->cd(1);
type->Draw();

CanvasA->cd(2);
impulse->Draw();
TF1 * exponential_fit = new TF1( "exponential_fit", "expo", 0, 4);
exponential_fit->SetParameters(1, 1);
impulse->Fit(exponential_fit, "R");
exponential_fit->GetParameters(&ptr[0]);
exponential_fit->SetParameters(ptr);
exponential_fit->Draw("same");
gStyle->SetOptFit(1111);

CanvasA->cd(3);
theta->Draw();
TF1 * gunza = new TF1 ("gunza", fi, 0, M_PI, 2); 
gunza->SetParNames("q", "m"); 
gunza->SetParameters(10000, 0);
theta->Fit(gunza, "R"); 
gunza->GetParameters(&ptr[0]);
gunza->SetParameters(ptr);
gunza->Draw("same");
gStyle->SetOptFit(1111);

CanvasA->cd(4);
phi->Draw();
TF1 * funza = new TF1 ("funza", fi, 0, 2*M_PI, 2);
funza->SetParNames("q", "m");
funza->SetParameters(10000, 0);
phi->Fit(funza, "R");
funza->GetParameters(&ptr[0]);
funza->SetParameters(ptr);
funza->Draw("same");
gStyle->SetOptFit(1111);

//CANVAS B.
TCanvas *CanvasB = new TCanvas ( "CanvasB", "Invariant mass distribution: particles generated by k*, difference among combinations",
50, 10, 1200, 700);
CanvasB->Divide(2,2);

CanvasB->cd(1);
TH1F *h0 = new TH1F ("h0","Invariant mass distribution of generated particles", 5000, 0, 2);
TF1 * dunza = new TF1 ("dunza", "gaus", 0, 2);
inv_mass_res->Fit(dunza, "R");
inv_mass_res->Draw();

CanvasB->cd(2);
TH1F *h1 = new TH1F ("h1","Difference among invariant mass distributions of Pion and Kaon", 5000, 0, 5);
h1->Add(inv_mass_pkd, inv_mass_pkc,1, -1);
TF1 * hunza = new TF1 ("hunza", "gaus", 0.4, 0.9);
h1->Fit(hunza, "R");
h1->Draw(); 

CanvasB->cd(3);
TH1F *h2 = new TH1F ("h2","Difference among invariant mass distribution of generated particles", 5000, 0, 5);
h2->Add(inv_mass_discorde, inv_mass_concorde,1, -1);
TF1 * lunza = new TF1 ("lunza", "gaus", 0.6, 0.7);
h2->Fit(lunza, "R");
h2->Draw();

CanvasA->SaveAs("../img/CanvasA.pdf");
CanvasB->SaveAs("../img/CanvasB.pdf");
}
