#include <iostream>
#include <map>
#include "nucleotide_count.h"

using namespace std;

namespace dna {
  class counter{
    string dna;
    public:
      counter(string a_dna){
        dna = a_dna;
      }
      const std::map<char, int> nucleotide_counts(){
        const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };
        return expected;
      };
  }
}
