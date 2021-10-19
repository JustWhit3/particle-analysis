#include <iostream>
#include <cmath>
#include "ParticleType.h"
#include "ResonanceType.h"
#include "Particle.h"
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

void Analisi ()
{
TFile *file = new TFile("Istogrammi.root");
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

double Pione_Positivo = type->GetBinContent(1);
double Pione_Positivo_Errore = type->GetBinError(1);
cout << "Pioni+ : " << Pione_Positivo << " +- " << Pione_Positivo_Errore 
<< " generazioni -> " << (Pione_Positivo*100)/1e7 << "%" << '\n';
double Pione_Negativo = type->GetBinContent(2);
double Pione_Negativo_Errore = type->GetBinError(2);
cout << "Pioni- : " << Pione_Negativo << " +- " << Pione_Negativo_Errore
<< " generazioni -> " << (Pione_Negativo*100)/1e7 << "%" << '\n';
double Kaone_Positivo = type->GetBinContent(3);
double Kaone_Positivo_Errore = type->GetBinError(3);
cout << "Kaoni+ : " << Kaone_Positivo << " +- " << Kaone_Positivo_Errore
<< " generazioni -> " << (Kaone_Positivo*100)/1e7 << "%" << '\n';
double Kaone_Negativo = type->GetBinContent(4);
double Kaone_Negativo_Errore = type->GetBinError(4);
cout << "Kaoni- : " << Kaone_Negativo << " +- " << Kaone_Negativo_Errore
<< " generazioni -> " << (Kaone_Negativo*100)/1e7 << "%" << '\n';
double Protone_Positivo = type->GetBinContent(5);
double Protone_Positivo_Errore = type->GetBinError(5);
cout << "Protoni+ : " << Protone_Positivo << " +- " << Protone_Positivo_Errore
<< " generazioni -> " << (Protone_Positivo*100)/1e7 << "%" << '\n';
double Protone_Negativo = type->GetBinContent(6);
double Protone_Negativo_Errore = type->GetBinError(6);
cout << "Protoni- : " << Protone_Negativo << " +- " << Protone_Negativo_Errore
<< " generazioni -> " << (Protone_Negativo*100)/1e7 << "%" << '\n';
double Risonanza = type->GetBinContent(7);
double Risonanza_Errore = type->GetBinError(7);
cout << "K* : " << Risonanza << " +- " << Risonanza_Errore
<< " generazioni -> " << (Risonanza*100)/1e7 << "%" << '\n';

cout << endl;
double Somma, Errore_Somma;
Somma = Pione_Positivo + Pione_Negativo + Kaone_Positivo + Kaone_Negativo + Protone_Positivo + Protone_Negativo + Risonanza;
Errore_Somma = Pione_Positivo_Errore + Pione_Negativo_Errore + Kaone_Positivo_Errore + Kaone_Negativo_Errore +
Protone_Positivo_Errore + Protone_Negativo_Errore + Risonanza_Errore;
cout << "Il numero di ingressi totale è il seguente: " << Somma << " +- " << Errore_Somma <<endl
<< "In percentuale: " << (Somma*100)/1e7 << "%" <<endl <<endl;

double *ptr = new double[2];
double *ptr2 = new double [3];

//CANVAS A.
TCanvas *CanvasA = new TCanvas ( "CanvasA", "Distribuzioni di abbondanza particelle, impulso, angolo polare e angolo azimutale",
50, 10, 1200, 700);
CanvasA->Divide(2,2);
CanvasA->cd(1);
type->Draw();

CanvasA->cd(2);
impulse->Draw();
TF1 * fit_esponenziale = new TF1( "fit_esponenziale", "expo", 0, 4);
fit_esponenziale->SetParameters(1, 1);
impulse->Fit(fit_esponenziale, "R");
fit_esponenziale->GetParameters(&ptr[0]);
fit_esponenziale->SetParameters(ptr);
fit_esponenziale->Draw("same");
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
TCanvas *CanvasB = new TCanvas ( "CanvasB", "Distribuzione di massa invariante: particelle generate da k*, differenza di combinazioni",
50, 10, 1200, 700);
CanvasB->Divide(2,2);

CanvasB->cd(1);
TH1F *h0 = new TH1F ("h0","Distribuzione Della Massa Invariante Delle Particelle Generate", 5000, 0, 2);
TF1 * dunza = new TF1 ("dunza", "gaus", 0, 2);
inv_mass_res->Fit(dunza, "R");
inv_mass_res->Draw();

CanvasB->cd(2);
TH1F *h1 = new TH1F ("h1","Differenza Tra Distribuzione Della Massa Invariante del Pione e del Kaone", 5000, 0, 5);
h1->Add(inv_mass_pkd, inv_mass_pkc,1, -1);
TF1 * hunza = new TF1 ("hunza", "gaus", 0.4, 0.9);
h1->Fit(hunza, "R");
h1->Draw(); 

CanvasB->cd(3);
TH1F *h2 = new TH1F ("h2","Differenza Tra Distribuzione Della Massa Invariante delle Particelle Generate", 5000, 0, 5);
h2->Add(inv_mass_discorde, inv_mass_concorde,1, -1);
TF1 * lunza = new TF1 ("lunza", "gaus", 0.6, 0.7);
h2->Fit(lunza, "R");
h2->Draw();
}
