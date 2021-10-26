
cd src

root -l <<EOF

gROOT->LoadMacro("ParticleType.cpp+")
gROOT->LoadMacro("ResonanceType.cpp+")
gROOT->LoadMacro("Particle.cpp+")
gROOT->LoadMacro("Main.cpp+")
Main();
.q

EOF

mkdir -p ../obj
mv *.so ../obj
mv *_cpp* ../obj
cd ..
