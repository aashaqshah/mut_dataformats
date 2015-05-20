
#include "mut_framework/DataFormats/interface"

namespace mut {

  bool Jet::hasJetID( const std::string &name ) const {
    for( auto idPair : idPairs_)  {
      if (idPair.first == name) return true;
    }
    return false; 
  }

  float Jet::getJetID( const std::string &name ) const {
    for( auto idPair : idPairs_)  {
      if (idPair.first == name) return idPair.second;
    }
    return 0; // TODO
  }

  bool Jet::hasDiscriminator( const std::string &name ) const {
    for( auto disPair : disPairs_)  {
      if (disPair.first == name) return true;
    }
    return false; 
  }

  float Jet::getDiscriminator( const std::string &name ) const {
    for( auto disPair : disPairs_)  {
      if (disPair.first == name) return disPair.second;
    }
    return 0; // TODO
  }

}
