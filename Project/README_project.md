# Project: "Study and Analysis of the Elementary Particles Collisions"

## General Informations
This folder contains all the informations related to the code and the project itself.

## List of the documents in the folder
- [Main.c](https://github.com/JustWhit3/Particle-class/blob/master/Project/Main.c): this program generates events and histograms for the analysis. First of all are included libraries from ROOT and the three main classes `Particle`, `ParticleType` and `ResonanceType` (to understand their utility see [Reference guides](https://github.com/JustWhit3/Particle-class/tree/master/Reference%20guides). Than, are generated different kind of particles and the useful histograms for the analysis (see detailed explanation [here](https://github.com/JustWhit3/Particle-class/blob/master/Explanations/Explanations.pdf)). Finally, histograms are filled with random numbers, by taking into account different probabilities to get different particles.
- [Analisi.c](https://github.com/JustWhit3/Particle-class/blob/master/Project/Analisi.c): this program contain the `Analisi` function, useful to analyze the previously generated histograms and the compatibility with expected data. Are executed fits and operations between histograms (see technical explanation [here](https://github.com/JustWhit3/Particle-class/blob/master/Explanations/Explanations.pdf)).
