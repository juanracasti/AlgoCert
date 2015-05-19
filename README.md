# AlgoCert
Automatic certification algorithm for CMS muon data Runs

Choose your favorite CMSSW release.

    cmsrel CMSSW_7_2_0
    cd CMSSW_7_2_0/src
    cmsenv

Get the material
====

    git clone https://github.com/juanracasti/AlgoCert.git

Edit runAlgo.sh
====

Select the Run number of the samples and the reference you want to compare with

Run the code
====

Execute ./runAlgo.sh

See the results
====

A table will be created with the values of D and S for each sample, computed using the chi2/ndof of the full Global Track, the Trk from Glb Track, and the Sta from Glb Track.
