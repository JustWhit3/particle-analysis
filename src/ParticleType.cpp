#include <iostream>
#include "../include/ParticleType.h"

void ParticleType::Print() 
 {
  std::cout << "Particle Name: " << fName << std::endl << "Particle Mass: " << fMass << std::endl << "Particle Charge: " << fCharge << std::endl;
  };

ParticleType::ParticleType(const char *Name, const double Mass, const int Charge): 
fName (Name), fMass (Mass), fCharge (Charge) {};
