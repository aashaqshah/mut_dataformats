
#pragma once

#include <vector>
#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"
#include "Math/VectorUtil.h"
#include "Candidate.h"

namespace mut {

    class DiObject : public Candidate {

    public:
      // default constructor
      DiObject() : Candidate() {}
      // copy constructor
      DiObject( const DiObject & rhs) : 
        Candidate(rhs),
        deta_(rhs.deta_),
        detaabs_(rhs.detaabs_),
        dphi_(rhs.dphi_),
        dphiabs_(rhs.dphiabs_),
        dr_(rhs.dr_),
        costhst_(rhs.costhst_),
        costhst1_(rhs.costhst1_) {}

      DiObject( const PtEtaPhiEVector & obj0_p4, const PtEtaPhiEVector & obj1_p4) :
        Candidate(obj0_p4+obj1_p4),
        deta_(obj0_p4.eta()-obj1_p4.eta()),
        detaabs_(std::abs(obj0_p4.eta()-obj1_p4.eta())),
        dphi_(ROOT::Math::VectorUtil::DeltaPhi(obj0_p4, obj1_p4)), 
        dphiabs_(M_PI - std::abs(std::abs(obj0_p4.phi() - obj1_p4.phi()) - M_PI)),
        dr_(ROOT::Math::VectorUtil::DeltaR(obj0_p4, obj1_p4)),  
        costhst_( std::abs(std::cos(
                  (ROOT::Math::VectorUtil::boost(obj0_p4, this->BoostToCM())).theta()) ) ),
        costhst1_( std::abs(std::cos(
                  (ROOT::Math::VectorUtil::boost(obj1_p4, this->BoostToCM())).theta())) ) {}

      // inherit other constructors
      using Candidate::Candidate;

//      float pdeta() const { return deta_;}
      float deta() const { return deta_;}
      float detaabs() const { return detaabs_;}
      float dphi() const { return dphi_;}
      float dphiabs() const { return dphiabs_;}
      float dr() const { return dr_;};
      float costhst() const { return costhst_;};
      float costhst1() const { return costhst1_;};
     
    // attributes (also public)

      // flavour attributes (0 if data/undefined)
      float deta_ = 0;
      float detaabs_ = 0;
      float dphi_ = 0;
      float dphiabs_ = 0;
      float dr_ = 0;
      float costhst_ = 0;
      float costhst1_ = 0;

  };
}
