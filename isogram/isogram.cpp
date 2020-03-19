#include "isogram.h"

#include <algorithm>
#include <bitset>
#include <stdexcept>

using std::bitset;
using std::tolower;

bool isogram::is_isogram(string phrase) {
  bitset<26> letters;
  for (char c : phrase) {
    int position = tolower(c) - 'a';
    if ((position >= 0) && (position <= 25)) {
      if (letters[position] == 1) {
        return false;
      }
      letters.set(position);
    }
  }
  return true;
}
