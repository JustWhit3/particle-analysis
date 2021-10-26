#include <iostream>
#include "../include/ResonanceType.h"

void ResonanceType::Print()
 {
  ParticleType::Print();
  std::cout << "Particle Width: " << fWidth << std::endl;
  };

ResonanceType::ResonanceType(const char *Name, const double Mass, const int Charge, const double Width): 
ParticleType (Name, Mass, Charge), fWidth (Width) {};
