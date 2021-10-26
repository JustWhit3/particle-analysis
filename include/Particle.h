#ifndef PARTICLE_H
#define PARTICLE_H

#include "ParticleType.h"
#include "ResonanceType.h"

class Particle
 {
  public:
  Particle();
  Particle (const char *Name, double Px = 0., double Py = 0., double Pz = 0.);
  Particle (int IParticle, double Px = 0., double Py = 0., double Pz = 0.);

  int GetIParticle() const 
  {
   return fIParticle;
   };
   double GetPx() const 
   { 
    return fPx;
    };
  double GetPy() const 
   {
    return fPy;
    };
  double GetPz() const 
   {
    return fPz;
    };
  double GetMass() const;
  double GetCharge() const;
  double GetEnergy() const;
  double GetInvMass(Particle &) const;
  
  void SetParticle (int IParticle);
  void SetParticle (const char *Name);
  void SetP (double, double, double);   

  static int AddParticleType (const char *Name, const double Mass, const int Charge, const double Width);
  int Decay2body(Particle &dau1,Particle &dau2) const;
  static void Printer();
  void Printex(int IParticle, const char *Name);

  static const int fMaxNumParticleType = 10;

  private:
  static ParticleType *fParticleType[fMaxNumParticleType]; 
  static int fNParticleType;
  int fIParticle;
  double fPx, fPy, fPz;
  static int FindParticle (const char *Name);
  void Boost(double Bx, double By, double Bz);
  };

#endif











