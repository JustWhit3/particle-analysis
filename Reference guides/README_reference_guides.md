# Reference guides folder

## General informations
This folder contains all the informations related to the classes and functions used in the program.

## ParticleType.h ([link](https://github.com/JustWhit3/Particle-class/blob/master/Reference%20guides/ParticleType.h))
This document contains the definition of the`ResonanceType` class class and of its methods and members. This class has the purpose of create instances that bring with them the three fundamental characteristics of a particle: name, charge and mass.

### Methods
This class contains only definitions of public methods:
- `const char *GetName() const`: to set the name of the particle.
- `double GetMass() const`: to set the mass of the particle.
- `int GetCharge() const`: to set the charge of the particle.
- `virtual double GetWidth() const`: that returns 0.
- `virtual void Print()`: to print informations of a particle.

### Members
This class contains only definition of private members:
- `const char *fName`: that is the name of the particle.
- `const double fMass`: that is the mass of the particle.
- `const int fCharge`: that is the charge of the particle.

## ParticleType.c ([link](https://github.com/JustWhit3/Particle-class/blob/master/Reference%20guides/ParticleType.c))
This document contain the initialization of the `virtual void Print()` method and of the `ParticleType` constructor, that construct the proper particle with mass, charge and name.

## ResonanceType.h ([link](https://github.com/JustWhit3/Particle-class/blob/master/Reference%20guides/ResonanceType.h))
This document contains the definition of the `ResonanceType` class and of its methods and members. `ResonanceType` class is heir of the`ResonanceType` one and creates particles with characteristics of the mother class , but also with the resonance width attribute, for particles that have one.

### Methods
This class contains only definitions of public methods:
- `double GetWidth() const`: to define the width of the resonance.
- `virtual void Print()`: to print updated informations of a particle.

### Members
This class contains only definition of private members:
- `const double fWidth`: that is the width of the particle resonance.

## ResonanceType.c ([link](https://github.com/JustWhit3/Particle-class/blob/master/Reference%20guides/ResonanceType.c))
This document contain the initialization of the `virtual void Print()` method and of the `ResonanceType` constructor, that construct the proper particle with mass, charge, name and resonance width.ù

## Particle.h ([link](https://github.com/JustWhit3/Particle-class/blob/master/Reference%20guides/Particle.h))
This document contains the definition of the `Particle` class and of its methods and members. This class contains all the previous ones and has the purpose of being used for the event generations. To do this, it uses methods to create arrays of particles, with their own characteristics, and the way of decaying of particles with resonances.

### Methods
This class contains only definitions of public methods:
- `int GetIParticle() const`: to get the particle ID.
- `double GetPx() const`, `double GetPy() const` and `double GetPz() const`: to set momentum along axis.
- `double GetMass() const`: to get mass of the particle.
- `double GetCharge() const`: to get charge of the particle.
- `double GetEnergy() const`: to get energy of the particle.
- `double GetInvMass(Particle &) const`: to get invariant mass of the particle.
- `void SetParticle (int IParticle)`: to set ID of the particle.
- `void SetParticle (const char *Name)`: to set name of the particle.
- `void SetP (double, double, double)`: to set momentum values of the particle along axis.
- `static int AddParticleType (const char *Name, const double Mass, const int Charge, const double Width)`: to create a particle with characteristics.
- `int Decay2body(Particle &dau1,Particle &dau2) const`: to set the decay products of a particle.
- `static void Printer()`: to print informations of a particle.
- `void Printex(int IParticle, const char *Name)`: to print particle ID and name.

### Members
This class contains one public member:
- `static const int fMaxNumParticleType`: set equal to 10.

And private members
- `static ParticleType *fParticleType[fMaxNumParticleType]`: ParticleType pointer.
- `static int fNParticleType`: integer value.
- `int fIParticle`: ID of the particle.
- `double fPx, fPy, fPz`: momentum along axis.
- `static int FindParticle (const char *Name)`: name of the particle.
- `void Boost(double Bx, double By, double Bz)`: Lorentz boost along axis.

### Constructors and Destroyers
This class has three constructors:
- `Particle()`
- `Particle (const char *Name, double Px = 0., double Py = 0., double Pz = 0.)`
- `Particle (int IParticle, double Px = 0., double Py = 0., double Pz = 0.)`
