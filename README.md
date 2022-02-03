<p align="center"><img src="https://github.com/JustWhit3/particle-analysis/blob/master/img/logo.svg" height=220></p>

<h3 align="center">A project to simulate and analyse interactions with particles using the ROOT framework</h3>
<p align="center">
    <img title="v2.0" alt="v2.0" src="https://img.shields.io/badge/version-v2.0-informational?style=flat-square"
    <a href="LICENSE">
        <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
    </a>
	<img title="C++11" alt="C++11" src="https://img.shields.io/badge/c++-11-informational?style=flat-square">
    </a>
</p>

## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Prerequisites](#prerequisites)
- [Run the code](#run-the-code)
  * [Download](#download)
    * [Download the whole repository](#download-the-whole-repository)
    * [Download the latest release](#download-the-latest-release)
  * [Compile and run](#compile-and-run)
- [Classes and functions](#classes-and-functions)
- [List of features](#list-of-features)
- [Authors](#authors)

## Introduction

This project simulates particle events generation and analysis by using only simulated data. Its purpose is of teaching bachelor's degree students in physics at University of Bologna, how a particle analysis works.

## Description of the repository

Repository diagram structure:
```
particle-analysis/
├── img/
│   ├── CanvasA.pdf
│   ├── CanvasB.pdf
│   ├── CanvasA.png
│   ├── CanvasB.png
├── include/
│   ├── Particle.h
│   ├── ParticleType.h
│   ├── ResonanceType.h
├── src/
│   ├── Particle.cpp
│   ├── ParticleType.cpp
│   ├── ResonanceType.cpp
│   ├── Main.cpp
│   ├── Analysis.cpp
│── README.md
│── License
│── .gitignore
│── .all-contributorsrc
│── Analysis.sh
│── Main.sh
```

## Prerequisites

- [ROOT framework](https://root.cern/): see [this](https://github.com/JustWhit3/root-framework-installer) for installation.

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
cd particle-analysis
```

### Compile and run

Now, let's suppose to continue from the previous step. For the compilation part I prepared two scripts [*Main.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Main.sh) and [*Analysis.sh*](https://github.com/JustWhit3/particle-analysis/blob/master/Analysis.sh) in order to simplify this procedure. So you have to simply run this two commands one after the other:
```shell
./Main.sh
./Analysis.sh
```
The first two commands make the .sh files executables and ./ commands run them. The first script runs the data generation macro, while the second one runs the data analysis macro.

> The first command needs a bit of time to end since the program is doing billions of particles generations.

An extra **obj** folder with object files and a .root file (containing the histograms to be analyzed) are now created. The new **obj** folder files with cpp.so termination are used in the [*Main.cpp*](https://github.com/JustWhit3/particle-analysis/blob/master/src/Main.cpp) macro to run the command:
```C++
R__LOAD_LIBRARY(ClassName_cpp.so)
```
in order to load the libraries in the macro itself. Once the `./Analysis.sh` is finished a new **img** folder is produced and contains the final analysis plots.

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
- [`ParticleType.cpp`](https://github.com/JustWhit3/particle-analysis/blob/master/src/ParticleType.cpp): this script contains the initialization of the `virtual void Print()` method and of the `ParticleType` constructor.

- [`ResonanceType.h`](https://github.com/JustWhit3/particle-analysis/blob/master/include/ResonanceType.h): this header contains the definition of the `ResonanceType` class and of its methods and members. `ResonanceType` class is heir of the`ParticleType` one and creates particles with characteristics of the mother class plus the resonance width attribute.
  * Constructor: 
    - `ResonanceType (const char *Name, const double Mass, const int Charge, const double Width)`.
  * Public methods:
    - `double GetWidth() const`: to get the width of the resonance.
    - `void Print()`: to print updated informations of a particle.
  * Public members:
    - `const double fWidth`: that is the width of the particle resonance.
- [`ResonanceType.cpp`](https://github.com/JustWhit3/particle-analysis/blob/master/src/ResonanceType.cpp): this script contains the initialization of the `void Print()` method and of the `ResonanceType` constructor.

- [`Particle.h`](https://github.com/JustWhit3/particle-analysis/blob/master/include/Particle.h): this header contains the definition of the `Particle` class and of its methods and members. This class contains all the previous ones and has the purpose of being used for the events generation.
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
- [`Particle.cpp`](https://github.com/JustWhit3/particle-analysis/blob/master/src/Particle.cpp): this script contains the initialization of the three constructors and of all the methods of the `Particle` class.

## Background analysis explanation

The three implemented classes have different purposes:

- `ParticleType` creates istances that bring with them the three fundamental characteristics of a particle: mass, name and charge.
- `ResonanceType`, inherit from previous one and creates particles that has characteristics of the mother class and the resonance width (for particles that have one).
- `Particle`: this class is used for the event generation. 

To generate particles, a `Main.cpp` macro has been written and simulates the event generation. This generated events are analyzed by a `Analysis.cpp` program.

Interested histograms are:

- Particle types.
- Azimuthal impulse angle distribution.
- Polar impulse angle distribution.
- Impulse distribution.
- Combination of invariant mass distributions.

10^5 events have been generated, each of them of about 100 particles. 80% of generated particles are Pions, 10% are Kaons, 9% protons and the remaining 1% are resonances.

For the cinematic properties, the following distributions are used: a uniform distribution for the azimuthal coordinate (0, 2PI), a uniform distribution for the polar coordinate (0, PI) and an exponential distribution for the impulse. To analyze the resonant signal, the result of the subtraction between only Pions histograms and Kaons with opposite sign and the one of the histogram for only Pions and Kaons with same sign with the resonance histogram have been compared.

Significative resulting histograms are shown below:

<img src="https://github.com/JustWhit3/particle-analysis/blob/master/img/CanvasA.png">

<img src="https://github.com/JustWhit3/particle-analysis/blob/master/img/CanvasB.png">

## Authors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
    <td align="center"><a href="https://github.com/MarcoCollesei"><img src="https://avatars.githubusercontent.com/u/48796536?v=4" width="100px;" alt=""/><br /><sub><b>Marco Collesei</b></sub></a></td>
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->