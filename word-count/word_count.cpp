#include "word_count.h"

#include <cctype>

using std::map;
using std::string;

map<string, int> word_count::words(string phrase) {
  map<string, int> count;
  string word;

  const auto add_word = [&count, &word]() {
    const auto first = word.find_first_not_of('\'');
    if (first != string::npos) {
      const auto last = word.find_last_not_of('\'');
      ++count[word.substr(first, last - first + 1)];
    }
    word.clear();
  };

  for (const unsigned char character : phrase) {
    if (std::isalnum(character) || character == '\'') {
      word += static_cast<char>(std::tolower(character));
    } else {
      add_word();
    }
  }
  add_word();

  return count;
}
