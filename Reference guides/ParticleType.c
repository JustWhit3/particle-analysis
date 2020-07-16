#include <iostream>
#include "ParticleType.h"

using namespace std;

void ParticleType::Print() 
 {
  cout << "Particle Name: " << fName << endl << "Particle Mass: " << fMass << endl << "Particle Charge: " << fCharge << endl;
  };

ParticleType::ParticleType(const char *Name, const double Mass, const int Charge): 
fName (Name), fMass (Mass), fCharge (Charge) {};
