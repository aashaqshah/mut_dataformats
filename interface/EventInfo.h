
#pragma once

#include <vector>
#include <utility>

namespace mut {
    
  class EventInfo {

    public:
 
      typedef std::pair<std::string, float> FloatPair;
      typedef std::vector<FloatPair> FloatPairVector; 
      typedef std::pair<std::string, bool> BoolPair;
      typedef std::vector<BoolPair> BoolPairVector; 

      EventInfo() {}
      EventInfo(unsigned int event, unsigned int lumiBlock, unsigned int run);
      ~EventInfo() {}

      bool hasFilter(const std::string &name) const; 
      bool getFilter(const std::string &name) const; 
      const BoolPairVector & getFilterPairs() const { return filterPairs_; } 
      void setFilterPairs(const BoolPairVector &filterPairs) { filterPairs_ = filterPairs; }

      bool hasWeight(const std::string &name) const; 
      float getWeight(const std::string &name) const; 
      const FloatPairVector & getWeightPairs() const { return weightPairs_; } 
      void setWeightPairs(const FloatPairVector &weightPairs) { weightPairs_ = weightPairs; } 

      inline bool isRealData() const { return isRealData_; }
      inline void setIsRealData(bool isRealData) { isRealData_ = isRealData; }

      inline unsigned int getEvent() const { return event_; }
      inline void setEvent(unsigned int event) { event_ = event; }
      inline unsigned int getLumiBlock() const { return lumiBlock_; }
      inline void setLumiBlock(unsigned int lumiBlock) { lumiBlock_ = lumiBlock; }
      inline unsigned int getRun() const { return run_; }
      inline void setRun(int run) { run_ = run; }

      inline unsigned int getNumPV() const { return numPV_; }
      inline void setNumPV(unsigned int numPV) { numPV_ = numPV; }


    protected:
      bool isRealData_;

      unsigned int event_;
      unsigned int lumiBlock_;
      unsigned int run_; 

      unsigned int numPV_;
     
      // vector of generic event filters
      BoolPairVector filterPairs_;  
      // vector of pairs of weights 
      FloatPairVector weightPairs_;
      
  };


}


