#include "TauAnalysis/ClassicSVfit/interface/FastMTT.h"
#include "TauAnalysis/ClassicSVfit/interface/ClassicSVfit.h"
#include "TauAnalysis/ClassicSVfit/interface/MeasuredTauLepton.h"

class InterfaceFastMTT{

 public:

  InterfaceFastMTT();
  ~InterfaceFastMTT();

  void setTauOne(int leptype, double pt, double eta, double phi, double mass, int decaymode);

  void setTauTwo(int leptype, double pt, double eta, double phi, double mass, int decaymode);

  void setMetAndCovMat(double metx, double mety, double metxx, double metxy, double metyx, double metyy); 
 
  void clearLeptons();
  
  void calcSV();

  double getMass();

  double getPt();

  double getEta();

  double getPhi();


 private:

  classic_svFit::MeasuredTauLepton lepone;
  classic_svFit::MeasuredTauLepton leptwo;
  std::vector<classic_svFit::MeasuredTauLepton> measTauLeps;

  double metxval;
  double metyval;
  TMatrixD covMatr = TMatrixD(2, 2); 

  FastMTT fastMttInstance;


};



