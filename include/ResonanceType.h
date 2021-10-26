#ifndef RESONANCETYPE_H
#define RESONANCETYPE_H

#include "ParticleType.h"

class ResonanceType : public ParticleType
 {
  public:
  double GetWidth() const 
   {
    return fWidth;
    };
  void Print();
  ResonanceType (const char *Name, const double Mass, const int Charge, const double Width);
  
  private:
  const double fWidth;
  };

#endif 
