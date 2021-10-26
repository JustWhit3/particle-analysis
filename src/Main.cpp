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

using namespace std;

//gBenchmark->Start("Bench");

int Main ()
 { 
  Particle::AddParticleType ("Pion+", 0.13957, 1, 0);
  Particle::AddParticleType ("Pion-", 0.13957, -1, 0); 
  Particle::AddParticleType ("Kaon+", 0.49367, 1, 0);
  Particle::AddParticleType ("Kaon-", 0.49367, -1, 0);
  Particle::AddParticleType ("Proton+", 0.93827, 1, 0);
  Particle::AddParticleType ("Proton-", 0.93827, -1, 0);
  Particle::AddParticleType ("K*", 0.89166, 0, 0.050);

  Particle::Printer();

  Double_t y = 0, phi, theta, P, Px, Py, Pz, CrossP = sqrt(pow(Px, 2) + pow(Py, 2));

  const Int_t N = 140, a = 1E5, b = 100, part = 7;

  Particle particle[N];

  Int_t NK = 0, Over = 100+(2*NK), OverPlus = 100+(2*NK)+1, ArrayPos = 0;

  TH1F *TypeP = new TH1F ("TypeP", "Generated Particle Type", part, -0.5, -0.5 + part);
  TH1F *PhiGraph= new TH1F ("PhiGraph", "Distribution of Azimuth angles", 300, 0, 7);
  TH1F *ThetaGraph = new TH1F ("ThetaGraph", "Distribution of Polar angles", 300, 0, 3.5);
  TH1F *Impulse = new TH1F ("Impulse", "Distribution of the Impulse", 200, 0, 10);
  TH1F *CrossImpulse = new TH1F ("CrossImpulse", "Distribution of the Cross Impulse", 200, 0, 10);
  TH1F *Energy = new TH1F ("Energy", "Distribution of Energy", 200, 0, 10);
  TH1F *InvariantMass = new TH1F ("InvariantMass", "Distribution of Invariant Mass", 600, 0, 5);
  TH1F *InvMassDisc = new TH1F ("InvMassDisc", "Distribution of Invariant Mass with discordant charge sign", 5000, 0, 5);
  TH1F *InvMassConc = new TH1F ("InvMassConc", "Distribution of Invariant Mass with concordant charge sign", 5000, 0, 5);
  TH1F *InvMassPKDisc = new TH1F ("InvMassPKDisc", "Distribution of Invariant Mass of discordant Pions and Kions", 5000, 0, 5);
  TH1F *InvMassPKConc = new TH1F ("InvMassPKConc", "Distribution of Invariant Mass of concordant Pions and Kions", 5000, 0, 5);
  TH1F *InvMassGen = new TH1F ("InvMassGen", "Distribution of Invariant Mass of Generated Particles", 5000, 0, 2);

  for (Int_t i = 0; i < a; i++)
   {
    for (Int_t j = 0; j < b; j++)
     {
      gRandom->SetSeed();
      phi = gRandom->Uniform(0, (2*M_PI));
      theta = gRandom->Uniform(0, M_PI);
      P = gRandom->Exp(1);
      Px = P*sin(theta)*cos(phi);
      Py = P*sin(theta)*sin(phi);
      Pz = P*cos(theta);
      particle[j].SetP(P*sin(theta)*cos(phi), P*sin(theta)*sin(phi), P*cos(theta));
      PhiGraph->Fill(phi);
      ThetaGraph->Fill(theta);
      Impulse->Fill(P);
      CrossImpulse->Fill(CrossP);
      y = gRandom->Rndm();
      
      if (y < 0.4) 
       {
        particle[j].SetParticle ("Pion+");
        }
      else if (y < 0.8) 
       {
        particle[j].SetParticle ("Pion-");
        }
      else if (y < 0.85) 
       {
        particle[j].SetParticle ("Kaon+");
        }
      else if (y < 0.9) 
       {
        particle[j].SetParticle ("Kaon-");
        }
      else if (y < 0.945) 
       {
        particle[j].SetParticle ("Proton+");
        }
      else if (y < 0.99) 
       {
        particle[j].SetParticle ("Proton-");
        }
      else
       {
        particle[j].SetParticle ("K*");
        if(gRandom->Rndm() < 0.5)
         {
          particle[Over].SetParticle("Pion-");
          particle[OverPlus].SetParticle("Kaon+");
          particle[j].Decay2body(particle[Over], particle[OverPlus]);
          }
        else
         { 
          particle[Over].SetParticle("Pion+");
          particle[OverPlus].SetParticle("Kaon-");
          particle[j].Decay2body(particle[Over], particle[OverPlus]);
          }
        InvMassGen->Fill(particle[Over].GetInvMass(particle[OverPlus]));
        NK++;
        }

      Energy->Fill(particle[j].GetEnergy());
      TypeP->Fill(particle[j].GetIParticle());
      }
      
    for (Int_t w = 0; w < Over; w++)
     {
      for(Int_t u = w + 1; u < OverPlus; u++)
       {
        if (
            (particle[w].GetIParticle() != 6) && (particle[u].GetIParticle() != 6)
            ) 
         {
          InvariantMass->Fill(particle[w].GetInvMass(particle[u]));
          
          if (
              particle[w].GetCharge() != 
              particle[u].GetCharge()
              )
           {
            InvMassDisc->Fill(particle[w].GetInvMass(particle[u]));
            }
          if (
              particle[w].GetCharge() ==
              particle[u].GetCharge()
              )
           {
            InvMassConc->Fill(particle[w].GetInvMass(particle[u]));
            }
          if (
              ((particle[w].GetIParticle() == 0) && (particle[u].GetIParticle() == 3)) ||
              ((particle[w].GetIParticle() == 1) && (particle[u].GetIParticle() == 2))
              )
           {
            InvMassPKDisc->Fill(particle[w].GetInvMass(particle[u]));
            }
          if (
              ((particle[w].GetIParticle() == 0) && (particle[u].GetIParticle() == 2)) || 
              ((particle[w].GetIParticle() == 1) && (particle[u].GetIParticle() == 3))
              )
           {
            InvMassPKConc->Fill(particle[w].GetInvMass(particle[u]));
            }
          }
        }
      }  
    }

  TFile * File = new TFile( "../histograms.root", "RECREATE" );
  File->cd();
  TypeP->Write();
  PhiGraph->Write();
  ThetaGraph->Write();
  Impulse->Write();
  CrossImpulse->Write();
  Energy->Write();
  InvariantMass->Write();
  InvMassDisc->Write();
  InvMassConc->Write();
  InvMassPKDisc->Write();
  InvMassPKConc->Write();
  InvMassGen->Write();
  File->Close();
  File->ls();
  return 0;

  }

//gBenchmark->Show("Bench");



















