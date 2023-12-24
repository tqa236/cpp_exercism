#include "nucleotide_count.h"
#include <iostream>
#include <map>

using namespace std;

namespace nucleotide_count {
map<char, int> counter::nucleotide_counts() const {
  return {{'A', count('A')},
          {'T', count('T')},
          {'C', count('C')},
          {'G', count('G')}};
}
int counter::count(char c) const {
  const string nucleotides = "ATCG";
  if (nucleotides.find(c) == std::string::npos) {
    throw invalid_argument("This is not a nucleotide name.");
  }
  int cnt = 0;
  for (unsigned int i = 0; i < dna_string.size(); i++) {
    if (dna_string[i] == c) cnt++;
  }
  return cnt;
}
}  // namespace nucleotide_count
