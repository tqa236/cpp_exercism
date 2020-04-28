#include "isogram.h"
#include <bitset>

bool isogram::is_isogram(std::string phrase) {
  std::bitset<26> letters;
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
