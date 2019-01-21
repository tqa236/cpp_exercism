#include "reverse_string.h"

using namespace std;

string reverse_string::reverse_string(string s){
    string reverse_s = "";
    for(char& c : s) {
      reverse_s = c + reverse_s;
    }
    return reverse_s;
  }
