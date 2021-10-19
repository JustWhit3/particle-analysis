#include <iostream>
#include "ResonanceType.h"

using namespace std;

void ResonanceType::Print()
 {
  ParticleType::Print();
  cout << "Particle Width: " << fWidth << endl;
  };

ResonanceType::ResonanceType(const char *Name, const double Mass, const int Charge, const double Width): 
ParticleType (Name, Mass, Charge), fWidth (Width) {};
