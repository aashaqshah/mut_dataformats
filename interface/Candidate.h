
#pragma once

#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"

namespace mut {
  
  typedef ROOT::Math::PtEtaPhiEVector PtEtaPhiEVector;

  class Candidate : public PtEtaPhiEVector {

    public:

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

}
