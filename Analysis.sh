
mkdir -p img
cd src

root -l <<EOF

gROOT->LoadMacro("Analysis.cpp+")
Analysis()

EOF

mkdir -p ../obj
mv *.so ../obj
mv *_cpp* ../obj
cd ..
