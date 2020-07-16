#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Particle.h"

using namespace std;

int Particle::fNParticleType = 0;

ParticleType* Particle::fParticleType [Particle::fMaxNumParticleType];

int Particle::FindParticle (const char *Name)
 {
  for (int i = 0; i < fNParticleType; i++)
   {
    const char *type = fParticleType[i]->GetName();
    int k = 0;
    while((type[k] == Name[k]) && type[k] != '\0' && Name[k] != '\0')
     {
      k++;
      }
    if(type[k] == Name[k]) return i;
    }
  return -1;
  }

Particle::Particle ():
fIParticle (-1), fPx (0), fPy(0), fPz(0) 
{}; 

Particle::Particle (const char *Name, double Px, double Py, double Pz):
fPx (Px), fPy (Py), fPz (Pz)
 {
  int FP = FindParticle(Name);
  if(FP != -1)
   {
    fIParticle = FP;
    }
  else
   {
    cout << "La particella non è presente nella casella numero: " << fParticleType[fIParticle]->GetName() << endl;
    fIParticle = -1;
    }
  }

Particle::Particle (int IParticle, double Px, double Py, double Pz):
fPx (Px), fPy (Py), fPz (Pz)
 {
  if (IParticle < fNParticleType && IParticle >= 0)
   {
    fIParticle = IParticle;
    }
  else
   {
    cout <<"La particella non è presente nella casella numero: " << IParticle <<endl;
    }
  fIParticle = -1;
  }


double Particle::GetMass() const 
 {
  if(fIParticle > -1)
   {
    return fParticleType[fIParticle]->GetMass();
    }
  else
   { 
    return 0.;
    }
  }

double Particle::GetCharge() const 
 {
  if(fIParticle > -1)
   {
    return fParticleType[fIParticle]->GetCharge();
    }
  else
   { 
    return 0.;
    }
  }

double Particle::GetEnergy() const 
 {
  double Mass = GetMass();
  return sqrt(fPx*fPx + fPy*fPy + fPz*fPz + Mass*Mass); 
  }

double Particle::GetInvMass (Particle & p) const
 {
  return sqrt(pow(GetEnergy()+p.GetEnergy(),2) -
              (pow(fPx+p.GetPx(),2) + 
               pow(fPy+p.GetPy(),2) + 
               pow(fPz+GetPz(),2)
               )
              );
  }

void Particle::SetParticle (int IParticle)
 {
  if(IParticle >= 0 && IParticle < fNParticleType)
   {
    fIParticle = IParticle;
    }
  else
   {
    cout << "La particella non esiste: " << IParticle << endl;
    }
  }

void Particle::SetParticle(const char *Name)
 {
  int FP = FindParticle(Name);
  if(FP != -1)
   {
    fIParticle = FP;
    }
  else
   {
    cout << "La particella non è presente nella casella numero: " << fParticleType[fIParticle]->GetName() << endl; 
    }
  }

void Particle::SetP (double Px, double Py, double Pz)
 {
  fPx = Px;
  fPy = Py;
  fPz = Pz;
  }

int Particle::AddParticleType(const char *Name,double Mass,int Charge,double Width)
 {
  if(fNParticleType < fMaxNumParticleType)
   {
    int FP = FindParticle(Name);
    if(FP != -1)
     {
      cout << "Esiste già una particella con questo nome: " << Name << endl; return 7;
      }
    if(Width > 0)
     {
      fParticleType[fNParticleType] = new ResonanceType(Name, Mass, Charge, Width);
      }
    else
     {
      fParticleType[fNParticleType] = new ParticleType(Name, Mass, Charge);
      }
    fNParticleType++;
    }
  else
   {
    cout << "Il contenitore è pieno perchè hai inserito " << fMaxNumParticleType << " particelle" << endl; return 6;
    }
  return 5;
  }

void Particle::Boost(double Bx, double By, double Bz)
 {
  double energy = GetEnergy();
  double B2 = Bx*Bx + By*By + Bz*Bz;
  double gamma = 1.0 / sqrt(1.0 - B2);
  double Bp = Bx*fPx + By*fPy + Bz*fPz;
  double gamma2 = B2 > 0 ? (gamma - 1.0)/B2 : 0.0;
  fPx += gamma2*Bp*Bx + gamma*Bx*energy;
  fPy += gamma2*Bp*By + gamma*By*energy;
  fPz += gamma2*Bp*Bz + gamma*Bz*energy;
  }

int Particle::Decay2body(Particle &dau1,Particle &dau2) const 
 {
  if(GetMass() == 0.0)
   {
    cout << "Se la massa è zero non c'è nessun decadimento." << endl; return 1;
    }
  double massMot = GetMass();
  double massDau1 = dau1.GetMass();
  double massDau2 = dau2.GetMass();
  if(fIParticle > -1)
   {
    float x1, x2, w, y1, y2;
    double invnum = 1./RAND_MAX;
    do 
     {
      x1 = 2.0 * rand()*invnum - 1.0;
      x2 = 2.0 * rand()*invnum - 1.0;
      w = x1 * x1 + x2 * x2;
      } 
    while (w >= 1.0);
    w = sqrt((-2.0 * log( w )) / w );
    y1 = x1 * w;
    y2 = x2 * w;
    massMot += fParticleType[fIParticle]->GetWidth() * y1;
    }
  if(massMot < massDau1 + massDau2)
   {
    cout << "Il decadimento non può avvenire perchè la massa è troppo piccola" << endl; return 2;
    }
  double pout = sqrt((massMot*massMot - (massDau1+massDau2)*(massDau1+massDau2)) *
                     (massMot*massMot - (massDau1-massDau2)*(massDau1-massDau2))
                     ) / 
                massMot*0.5;
  double norm = 2*M_PI/RAND_MAX;
  double phi = rand()*norm;
  double theta = rand()*norm*0.5 - M_PI/2.;
  dau1.SetP(pout*sin(theta)*cos(phi), pout*sin(theta)*sin(phi), pout*cos(theta));
  dau2.SetP(-pout*sin(theta)*cos(phi), -pout*sin(theta)*sin(phi), -pout*cos(theta));
  double energy = sqrt(fPx*fPx + fPy*fPy + fPz*fPz + massMot*massMot);
  double Bx = fPx/energy;
  double By = fPy/energy;
  double Bz = fPz/energy;
  dau1.Boost(Bx,By,Bz);
  dau2.Boost(Bx,By,Bz);
  return 0;
  }

void Particle::Printer() 
 {
  for (int j = 0; j < fNParticleType; j++)
   {
    fParticleType[j]->Print();
    }
  }

void Particle::Printex (int IParticle, const char *Name)
 {
  cout << "Particle Type: " << fIParticle << endl << "Particle Name: " << fParticleType[fIParticle]->GetName() << endl << "Particle P: " << "(" << fPx << ", "  << fPy << ", " << fPz << ")" << endl;
  };




