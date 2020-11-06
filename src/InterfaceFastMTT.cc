#include "TauAnalysis/NanoToolsInterface/interface/InterfaceFastMTT.h"

InterfaceFastMTT::InterfaceFastMTT(){
}

InterfaceFastMTT::~InterfaceFastMTT(){
}


void InterfaceFastMTT::setTauOne(int leptype, double pt, double eta, double phi, double mass, int decaymode){

  if(leptype == 0){
    lepone = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToElecDecay,pt,eta,phi,mass,-1);
  } else if(leptype == 1){
    lepone = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToMuDecay,pt,eta,phi,mass,-1);
  } else if(leptype == 2){
    lepone = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToHadDecay,pt,eta,phi,mass,decaymode);
  }
}

void InterfaceFastMTT::setTauTwo(int leptype, double pt, double eta, double phi, double mass, int decaymode){

  if(leptype == 0){
    leptwo = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToElecDecay,pt,eta,phi,mass,-1);
  } else if(leptype == 1){
    leptwo = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToMuDecay,pt,eta,phi,mass,-1);
  } else if(leptype == 2){
    leptwo = classic_svFit::MeasuredTauLepton(classic_svFit::MeasuredTauLepton::kTauToHadDecay,pt,eta,phi,mass,decaymode);
  }

}

void InterfaceFastMTT::setMetAndCovMat(double metx, double mety, double metxx, double metxy, double metyx, double metyy){

  covMatr[0][0] = metxx;
  covMatr[1][0] = metxy;
  covMatr[0][1] = metyx;
  covMatr[1][1] = metyy;

  metxval = metx;
  metyval = mety;
}

void InterfaceFastMTT::clearLeptons(){
  measTauLeps.clear();
}

void InterfaceFastMTT::calcSV(){

  measTauLeps.push_back(lepone);
  measTauLeps.push_back(leptwo);
  
  fastMttInstance.run(measTauLeps, metxval, metyval, covMatr);

}


double InterfaceFastMTT::getMass(){
  return fastMttInstance.getBestP4().M();
}

double InterfaceFastMTT::getPt(){
  return fastMttInstance.getBestP4().Pt();
}

double InterfaceFastMTT::getEta(){
  return fastMttInstance.getBestP4().Eta();
}

double InterfaceFastMTT::getPhi(){
  return fastMttInstance.getBestP4().Phi();
}



