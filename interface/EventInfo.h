
#pragma once

#include <vector>
#include <utility>
#include <string>

namespace mut {
    
  class EventInfo {

    public:
 
      typedef std::pair<std::string, float> FloatPair;
      typedef std::vector<FloatPair> FloatPairVector; 
      typedef std::pair<std::string, bool> BoolPair;
      typedef std::vector<BoolPair> BoolPairVector; 

      EventInfo() {}
      EventInfo(unsigned int event, unsigned int lumiBlock, unsigned int run);
      // copy constructor
      EventInfo( const EventInfo& rhs) :
        isRealData_(rhs.isRealData_),
        event_(rhs.event_),
        lumiBlock_(rhs.lumiBlock_),
        run_(rhs.run_),
        numPV_(rhs.numPV_),
        filterPairs_(rhs.filterPairs_),
        weightPairs_(rhs.weightPairs_) {}

      ~EventInfo() {}

      bool hasFilter(const std::string &name) const; 
      bool getFilter(const std::string &name) const; 
      bool getFilterC(const char * name) const { return getFilter(std::string(name)); }; 
      const BoolPairVector & getFilterPairs() const { return filterPairs_; } 
      void setFilterPairs(const BoolPairVector &filterPairs) { filterPairs_ = filterPairs; }

      bool hasWeight(const std::string &name) const; 
      float getWeight(const std::string &name) const; 
      float getWeightC(const char * name) const { return getWeight(std::string(name)); }; 
      const FloatPairVector & getWeightPairs() const { return weightPairs_; } 
      void setWeightPairs(const FloatPairVector &weightPairs) { weightPairs_ = weightPairs; } 
      void emplaceWeight(const std::string &name, const float &weight)
         { weightPairs_.emplace_back(name, weight); } 

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
      inline unsigned int getNumPU() const { return numPU_; }
      inline void setNumPU(unsigned int numPU) { numPU_ = numPU; }
      inline unsigned int getNumTruePU() const { return numTruePU_; }
      inline void setNumTruePU(unsigned int numTruePU) { numTruePU_ = numTruePU; }

      inline std::string getPName() const { return pName_; }
      inline const char * getPNameC() const { return pName_.c_str(); }
      inline void setPName(const std::string & pName) { pName_ = pName; }
      inline void setPNameC(const char * pName) { pName_ = pName; }

    protected:
      bool isRealData_ = false;

      unsigned int event_;
      unsigned int lumiBlock_;
      unsigned int run_; 

      unsigned int numPV_;
      unsigned int numPU_ = 0;
      unsigned int numTruePU_ = 0;

      //  human readable event origin
      std::string pName_ = "";
     
      // vector of generic event filters
      BoolPairVector filterPairs_;  
      // vector of pairs of weights 
      FloatPairVector weightPairs_;
      
  };


}


