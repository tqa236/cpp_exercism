#include "pangram.h"
#include <algorithm>
#include <set>
#include <string>

using std::set;
using std::string;

bool pangram::is_pangram(string sentence) {
  set<char> letters;
  for (char c : sentence) {
    char lower_char = tolower(c);
    if ((lower_char >= 'a') && (lower_char <= 'z')) letters.insert(lower_char);
  }
  if (letters.size() == 26) return true;
  return false;
}
