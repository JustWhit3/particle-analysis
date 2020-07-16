# Steps to run the code

### 1) Download the file
You need to download the file from the repository of GitHub.

Click on the button "Code" and than click on "Download ZIP".
### 2) Extract the program from the download file
You need a software like "Winrar" to extract the files from the ZIP document.

Once you've done this, you need to search for the file "Analisi.c", "Main.c", "Particle.c", "Particle.h", "ParticleType.c", "ParticleType.h", "ResonanceType.c" and "ResonanceType.h, into the "Project" and the "Reference guide" folders and move them to your "Home" folder (to make the program easier to run).
### 3) Download ROOT
To compile the code, you need to download and install the ROOT data analysis framework from [here](https://d35c7d8c.web.cern.ch/downloading-root).

### 4) Run the code on your computer
Once you've downloaded ROOT, open a shell and tip:
 
- `root -l`

to open ROOT. Than run the "Main.c" program to generate events:

- `.X Main.c`

and than run the "Analisi.c" program to analyze the histograms and get the results:

- `.X Analisi.c`

