
#include "../interface/EventInfo.h"

namespace mut {

  EventInfo::EventInfo(unsigned int event, unsigned int lumiBlock, unsigned int run) :
    event_(event),
    lumiBlock_(lumiBlock),
    run_(run)
  {

  }

  bool EventInfo::hasFilter( const std::string &name ) const {
    for( auto filterPair : filterPairs_)  {
      if (filterPair.first == name) return true;
    }
    return false; 
  }

  bool EventInfo::getFilter( const std::string &name ) const {
    for( auto filterPair : filterPairs_)  {
      if (filterPair.first == name) return filterPair.second;
    }
    return false; // TODO
  }

  bool EventInfo::hasWeight( const std::string &name ) const {
    for( auto weightPair : weightPairs_)  {
      if (weightPair.first == name) return true;
    }
    return false; 
  }

  float EventInfo::getWeight( const std::string &name ) const {
    for( auto weightPair : weightPairs_)  {
      if (weightPair.first == name) return weightPair.second;
    }
    return 1; // TODO
  }

}
