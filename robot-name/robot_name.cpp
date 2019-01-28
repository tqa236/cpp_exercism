#include <iostream>
#include <map>
#include <math.h>
#include <bitset>
#include <algorithm>
#include "robot_name.h"
using namespace std;

namespace robot_name{
  string robot::name() const{
    string name;
    if (name.empty()){
      for (int i = 0; i < 5; i++){
        if (i < 2){
          name += 'A' + rand() % 26;
        }
        else{
          name += '0' + rand() % 10;
        }
      }
    }
    r_name = "Hahaha";
    // r_name = name;
    cout << r_name << endl;
    return name;
  }
}
