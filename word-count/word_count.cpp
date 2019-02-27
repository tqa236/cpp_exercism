#include "word_count.h"

using std::map;
using std::string;

map<string, int> word_count::words(string phrase) {
  map<string, int> count;
  count[phrase] = 1;
  return count;
}
