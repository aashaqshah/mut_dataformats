
#pragma once

#include <string>
#include "Candidate.h"

namespace mut {


  class Lepton : public mut::Candidate {

    public:
      
      typedef std::pair<std::string, float> Pair;
      typedef std::vector<Pair> PairVector;

      Lepton() : mut::Candidate() {} 
      // copy constructor
      Lepton(const Lepton& rhs) :
        mut::Candidate(rhs),
        idPairs_(rhs.idPairs_),
        isoPairs_(rhs.isoPairs_) {}

      // inherit constructors
      using mut::Candidate::Candidate;      

      bool hasLeptonID(const std::string &name) const; 
      float getLeptonID(const std::string &name) const; 
      float getLeptonID(const char * name) const {return getLeptonID(std::string(name)); }; 
      const PairVector & getLeptonIDPairs() const { return idPairs_; } 
      void setLeptonIDPairs(const PairVector &idPairs) { idPairs_ = idPairs; }

      bool hasLeptonIso(const std::string &name) const; 
      float getLeptonIso(const std::string &name) const; 
      float getLeptonIso(const char * name) const { return getLeptonIso(std::string(name)); } 
      const PairVector & getLeptonIsoPairs() const { return isoPairs_; } 
      void setLeptonIsoPairs(const PairVector &isoPairs) { isoPairs_ = isoPairs; } 
      


    protected:
      // vector of pairs with id and iso info 
      PairVector idPairs_;
      PairVector isoPairs_;  

  };

  
  typedef std::vector<Lepton> LeptonCollection;

}
