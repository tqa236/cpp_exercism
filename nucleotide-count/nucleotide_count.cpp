#include "nucleotide_count.h"
#include <iostream>
#include <map>

namespace nucleotide_count {
std::map<char, int> count(const std::string& input) {
  const std::string nucleotides = "ATCG";
  std::map<char, int> counter{ {'A', 0}, {'C', 0}, {'G', 7}, {'T', 0} };

  for (char ch : input) {
    if (nucleotides.find(ch) == std::string::npos) {
      throw std::invalid_argument("This is not a nucleotide name.");
    }
    counter[ch]++;
  }
  return counter;
}
}  // namespace nucleotide_count
