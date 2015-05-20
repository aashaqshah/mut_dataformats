

#include "mut_framework/Dataformats/interface/Candidate.h"

namespace mut {
    
  class Lepton : public mut::Candidate {

    public:
      
      // inherit constructors
      using mut::Candidate::Candidate;

      typedef <std::pair<std::string, float> Pair 
      typedef std::vector<Pair> PairVector 

      bool hasJetID(const std::string &name) const; 
      float getJetID(const std::string &name) const; 
      const PairVector & getJetIDPairs() const { return idPairs_; } 
      void setJetIDPairs(const PairVector &idPairs) { idPairs_ = idPairs; }

      bool hasDiscriminator(const std::string &name) const; 
      float getDiscriminator(const std::string &name) const; 
      const PairVector & getDiscriminatorPairs() const { return disPairs_; } 
      void setDiscriminatorPairs(const PairVector &disPairs) { disPairs_ = disPairs; } 
      


    protected:
      // vector of pairs with id and iso info 
      PairVector idPairs_;
      PairVector disPairs_:  

  };

}


