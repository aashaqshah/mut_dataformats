
#include "mut_framework/DataFormats/interface"

namespace mut {

  bool Lepton::hasLeptonID( const std::string &name ) const {
    for( auto idPair : idPairs_)  {
      if (idPair.first == name) return true;
    }
    return false; 
  }

  float Lepton::getLeptonID( const std::string &name ) const {
    for( auto idPair : idPairs_)  {
      if (idPair.first == name) return idPair.second;
    }
    return 0; // TODO
  }

  bool Lepton::hasLeptonIso( const std::string &name ) const {
    for( auto isoPair : isoPairs_)  {
      if (isoPair.first == name) return true;
    }
    return false; 
  }

  float Lepton::getLeptonIso( const std::string &name ) const {
    for( auto isoPair : isoPairs_)  {
      if (isoPair.first == name) return isoPair.second;
    }
    return 0; // TODO
  }

}
