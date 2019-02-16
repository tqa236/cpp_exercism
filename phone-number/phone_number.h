#pragma once
#include <string>

using namespace std;

class phone_number {
 private:
  string only_number = "";

 public:
  phone_number(string number_) {
    only_number = number_;
    // for (char& c : number_){
    //     if (( c >= '0') && (c <= '9')){
    //         number = number + c;
    //     }
    // }
  }
  string number() const { return const only_number; }
};
