
#pragma once

#include "Candidate.h"

namespace mut {

  class Jet : public mut::Candidate {

    public:

      typedef std::pair<std::string, float> Pair;
      typedef std::vector<Pair> PairVector;

      Jet() : mut::Candidate() {}
      // copy constructor
      Jet(const Jet& rhs) :
        mut::Candidate(rhs),
        idPairs_(rhs.idPairs_),
        disPairs_(rhs.disPairs_),
        partonFlavour_(rhs.partonFlavour_),
        hadronFlavour_(rhs.hadronFlavour_) {}

      // inherit constructors
      using mut::Candidate::Candidate;

      bool hasJetID(const std::string &name) const;
      float getJetID(const std::string &name) const;
      float getJetIDC(const char * name) const { return getJetID(std::string(name)); };
      const PairVector & getJetIDPairs() const { return idPairs_; }
      void setJetIDPairs(const PairVector &idPairs) { idPairs_ = idPairs; }

      bool hasDiscriminator(const std::string &name) const;
      float getDiscriminator(const std::string &name = "") const;
      float getDiscriminatorC(const char * name = "") const { return getDiscriminator(std::string(name)); };
      const PairVector & getDiscriminatorPairs() const { return disPairs_; }
      void setDiscriminatorPairs(const PairVector &disPairs) { disPairs_ = disPairs; }

      void setPartonFlavour(const int &partonFlavour) { partonFlavour_ = partonFlavour; }
      int  getPartonFlavour() const { return partonFlavour_; }

      void setHadronFlavour(const int &hadronFlavour) { hadronFlavour_ = hadronFlavour; }
      int  getHadronFlavour() const { return hadronFlavour_; }


    protected:
      // vector of pairs with id and discriminator info
      PairVector idPairs_;
      PairVector disPairs_;
      // MC based flavours (0 if data/undefined)
      int partonFlavour_ = 0;
      int hadronFlavour_ = 0;

  };

  typedef std::vector<Jet> JetCollection;

}


