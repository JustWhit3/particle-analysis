## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
    * [Download the whole repository](#download-the-whole-repository)
    * [Download the latest release](#download-the-latest-release)
  * [Compile and run](#compile-and-run)
- [Classes and functions](#classes-and-functions)
- [List of features](#list-of-features)

## Introduction

This project simulates a particle events generation and analysis by using only simulations and not real data. Its purpose is of teaching bachelor's degree students in physics how a particle analysis works. I have developed this project in 2016-2017 for the exam "[Laboratorio di Elettromagnetismo e Ottica [Modulo 3]](https://www.unibo.it/it/didattica/insegnamenti/insegnamento/2021/434322)" (when I was a noob in programming ;) ). Since in 2021 I became the tutor of this course, I decided to update a bit the repository for teaching purpose only, therefore, this is the motivation for which the final update is this data. I don't upgrade technical structures like (pointers into vectors etc...) I simply upgrade the whole structure of the project (scripts, compilation etc...).

## Description of the repository

Excluding this README.md file, the [*License*](https://github.com/JustWhit3/particle-analysis/commit/1ca307afd07cc3e42aa440819695136c0cac5b43) file and the [*.gitignore*](https://github.com/JustWhit3/particle-analysis/blob/master/.gitignore) file, the repository contains some directories:
- [**include**](https://github.com/JustWhit3/particle-analysis/tree/master/include): which contains the classes declaration files [*ParticleType.h*](https://github.com/JustWhit3/particle-analysis/blob/master/include/ParticleType.h), [*ResonanceType.h*](https://github.com/JustWhit3/particle-analysis/blob/master/include/ResonanceType.h) and [*Particle.h*](https://github.com/JustWhit3/particle-analysis/blob/master/include/Particle.h).
- [**src**](https://github.com/JustWhit3/matrixop/tree/master/src): which contains .cpp files of classes and main / analysis programs:
  * [*ParticleType.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/ParticleType.cpp), [*ResonanceType.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/ResonanceType.cpp), and [*Particle.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/Particle.cpp).
  * [*Main.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/Main.cpp) for data simulation and [*Analysis.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/Analisi.cpp) for data analysis. For data simulation the 3 previously mentioned classes are used.
- [**doc**](https://github.com/JustWhit3/matrixop/tree/master/doc): which contains documents useful for physical explanations.

It contains also two bash scripts ([*Main.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Main.sh) and [*Analysis.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Analysis.sh)) created to make easier the running of the programs without the needing of entering in [ROOT](https://github.com/root-project/root) framework every time.

## Run the code

### Download

To download the project you can proceed in two independent ways.

#### Download the whole repository

Go to the [main page](https://github.com/JustWhit3/particle-analysis) of the repository and click on the upper right green button called `Code`. Than click on `Download ZIP` and wait the download to be completed.

Then open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/particle-analysis-master.zip $HOME
```
Where ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip particle-analysis-master.zip
mv particle-analysis-master particle-analysis
```
And that's all. You can enter the folder by simply typing:
```shell
cd particle-analysis
```

#### Download the latest release

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link. In this case the procedure is similar:

Open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/particle-analysis-x.y.z.zip $HOME
```
Where `x.y.z` is the release tag and ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip particle-analysis-x.y.z.zip
mv particle-analysis-x.y.z particle-analysis
```

> If you prefer to download the tar.gz format of the release you have to run the `gunzip` command followed by the `tar -xvf` command on the zipped release folder and than proceed with `mv`. 

And that's all. You can enter the folder by simply typing:
```shell
cd matrixop
```

### Compile and run

Now, let's suppose to continue from the previous step. For the compilation part I prepared two scripts [*Main.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Main.sh) and [*Analysis.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Analysis.sh) in order to simplify this procedure. So you have to simply run this two commands one after the other:
```shell
chmod +x Main.sh
chmod +x Analysis.sh
./Main.sh
./Analysis.sh
```
The first two commands make the .sh files executables and ./ commands run them. The first script runs the data generation macro, while the second one runs the data analysis macro.

> NOTE:
> The first command needs a bit of time since the program is doing billions of particles generations.

An extra **obj** folder with object files and a .root file (containing the histograms to be analyzed) are now created. The new **obj** folder files with cpp.so termination are used in the *Main.cpp* macro to run the command:
```C++
R__LOAD_LIBRARY(ClassName_cpp.so)
```
in order to load the libraries in the macro itself.

> NOTE:
> Thanks to this scripts you wouldn't need to enter the ROOT command prompt, since this process is automatically inserted in .sh files.

## Classes and functions

The following classes are defined:

- [`ParticleType.h`](https://github.com/JustWhit3/particle-analysis/blob/master/include/ParticleType.h): this header contains the definition of the`ParticleType` class and of its methods and members. This class has the purpose of createing instances that bring with them the three fundamental characteristics of a particle: name, charge and mass.
  * Constructor: 
    -  `ParticleType (const char *Name, const double Mass, const int Charge)`.
  * Public methods:
    - `const char *GetName() const`: to get the name of the particle.
    - `double GetMass() const`: to get the mass of the particle.
    - `int GetCharge() const`: to get the charge of the particle.
    - `virtual double GetWidth() const`: which returns 0.
    - `virtual void Print()`: to print information of a particle.
  * Private members:
    - `const char *fName`: which is the name of the particle.
    - `const double fMass`: which is the mass of the particle.
    - `const int fCharge`: which is the charge of the particle.
- [ParticleType.cpp](https://github.com/JustWhit3/particle-analysis/blob/master/src/ParticleType.cpp): this script contains the initialization of the `virtual void Print()` method and of the `ParticleType` constructor.

- [ResonanceType.h](https://github.com/JustWhit3/particle-analysis/blob/master/include/ResonanceType.h): this header contains the definition of the `ResonanceType` class and of its methods and members. `ResonanceType` class is heir of the`ParticleType` one and creates particles with characteristics of the mother class plus the resonance width attribute.
  * Constructor: 
    - `ResonanceType (const char *Name, const double Mass, const int Charge, const double Width)`.
  * Public methods:
    - `double GetWidth() const`: to get the width of the resonance.
    - `void Print()`: to print updated informations of a particle.
  * Public members:
    - `const double fWidth`: that is the width of the particle resonance.
- [ResonanceType.cpp](https://github.com/JustWhit3/particle-analysis/blob/master/src/ResonanceType.cpp): this script contains the initialization of the `void Print()` method and of the `ResonanceType` constructor.

- [Particle.h](https://github.com/JustWhit3/particle-analysis/blob/master/include/Particle.h): this header contains the definition of the `Particle` class and of its methods and members. This class contains all the previous ones and has the purpose of being used for the events generation.
  * Constructors:
    - `Particle()`.
    - `Particle (const char *Name, double Px = 0., double Py = 0., double Pz = 0.)`.
    - `Particle (int IParticle, double Px = 0., double Py = 0., double Pz = 0.)`.
  * Methods:
    - `int GetIParticle() const`: to get the particle ID.
    - `double GetPx() const`, `double GetPy() const` and `double GetPz() const`: to get momentum components along axis.
    - `double GetMass() const`: to get mass of the particle.
    - `double GetCharge() const`: to get charge of the particle.
    - `double GetEnergy() const`: to get energy of the particle.
    - `double GetInvMass(Particle &) const`: to get invariant mass of the particle.
    - `void SetParticle (int IParticle)`: to set ID of the particle.
    - `void SetParticle (const char *Name)`: to set name of the particle.
    - `void SetP (double, double, double)`: to set momentum values of the particle along axis.
    - `void Boost(double Bx, double By, double Bz)`: Lorentz boost along axis.
    - `static int AddParticleType (const char *Name, const double Mass, const int Charge, const double Width)`: to create a particle with characteristics.
    - `int Decay2body(Particle &dau1,Particle &dau2) const`: to set the decay products of a particle.
    - `static void Printer()`: to print information of a particle.
    - `void Printex(int IParticle, const char *Name)`: to print particle ID and name.
    - `static int FindParticle (const char *Name)`: to find the particle name in the class.
  * Members:
    - `static const int fMaxNumParticleType`: set equal to 10. It is the maximum number of particle types that can be produced.
    - `static ParticleType *fParticleType[fMaxNumParticleType]`: ParticleType pointer which stores particles informations.
    - `static int fNParticleType`: number of the pointer positions that are stored by existing particles.
    - `int fIParticle`: ID of the particle.
    - `double fPx, fPy, fPz`: momentum along axis.
- [Particle.cpp](https://github.com/JustWhit3/particle-analysis/blob/master/src/Particle.cpp): this script contains the initialization of the three constructors and of all the methods of the `Particle` class.

## Background analysis explanation

An explanation of the whole project in terms of physical utility can be found in [Explanations.pdf](https://github.com/JustWhit3/particle-analysis/blob/master/doc/Explanations.pdf) file, please remember that I wrote this at my second year of bachelor degree without using Latex ;( .
