# Interface for svfit
Nicer user interface for accessing from python

# Installation 
In order to install the code, execute:

```
cmsrel CMSSW_10_6_0
cd CMSSW_10_6_0/src
cmsenv
git clone https://github.com/SVfit/ClassicSVfit TauAnalysis/ClassicSVfit -b fastMTT_21_06_2018
git clone https://github.com/SVfit/SVfitTF TauAnalysis/SVfitTF
git clone https://github.com/adewit/NanoToolsInterface TauAnalysis/NanoToolsInterface
cd $CMSSW_BASE/src
scram b -j 4
```

