
#pragma once

#include <vector>
#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"

namespace mut {
  
  typedef ROOT::Math::PtEtaPhiEVector PtEtaPhiEVector;

  class Candidate : public PtEtaPhiEVector {

    public:
      Candidate() : PtEtaPhiEVector() {}
      // copy constructor
      Candidate( const Candidate& rhs) : 
        PtEtaPhiEVector(rhs),
        qx3_(rhs.qx3_),
        pdgId_(rhs.pdgId_) {}
      // inherit constructors
      using PtEtaPhiEVector::PtEtaPhiEVector;

      virtual ~Candidate() {}
      inline int charge() const { return qx3_/3; }
      inline void setCharge(int q) { qx3_ = q*3; }
      inline int threeCharge() const { return qx3_; }
      inline void setThreeCharge(int qx3) { qx3_ = qx3; }
      inline int pdgId() const { return pdgId_; }
      inline void setPdgId(int pdgId) { pdgId_ = pdgId; }

    protected:
      int qx3_ = 0;    // threeCharge
      int pdgId_ = 0;  // PDG id

  };

  typedef std::vector<mut::Candidate> CandidateCollection;

}
