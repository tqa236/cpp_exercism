#include "pangram.h"
#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <string>

using std::bitset;
using std::out_of_range;
using std::string;

bool pangram::is_pangram(const string& sentence) {
  bitset<26> letters;
  for (auto c : sentence) {
    try {
      letters.set(tolower(c) - 'a');
    } catch (const out_of_range&) {
    }
  }
  return letters.all();
}
