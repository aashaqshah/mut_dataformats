
#pragma once

#include <TTreeReader.h>
#include <TTreeReaderValue.h>

namespace mut {

  template <class Base> class Reader : public Base {

    public:

    TTreeReaderValue<Base>  * value_reader_;

    Reader() : value_reader_(nullptr) {}

    Reader(TTreeReader & reader, std::string b_name) :
      value_reader_(new TTreeReaderValue<Base>(reader, b_name.c_str())) {}

    ~Reader() { delete value_reader_;}

    void update() {

      Base::operator=(**value_reader_);

    }
    
  };




}
