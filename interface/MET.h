
#pragma once

#include "Candidate.h"

namespace mut {


  class MET : public mut::Candidate {

    public:
     
      MET() : mut::Candidate() {}
      MET(const MET& rhs) : mut::Candidate(rhs) {}
      // inherit constructors
      using mut::Candidate::Candidate;

    protected:  

      // TODO

  };

}
    
