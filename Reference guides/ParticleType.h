#ifndef PARTICLETYPE_H
#define PARTICLETYPE_H

class ParticleType
 {
  public:
  const char *GetName() const 
   {
    return fName;
    };
  double GetMass() const
   {
    return fMass;
    };
  int GetCharge() const 
   {
    return fCharge;
    };
  virtual double GetWidth() const 
   {
    return 0;
    };
  virtual void Print();
  ParticleType (const char *Name, const double Mass, const int Charge);
  
  private:
  const char *fName;
  const double fMass;
  const int fCharge;
  };
  
#endif 





