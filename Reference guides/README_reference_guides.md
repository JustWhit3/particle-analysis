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
