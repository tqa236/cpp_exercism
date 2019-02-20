#pragma once
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

namespace anagram {
using std::get;
using std::make_tuple;
using std::sort;
using std::string;
using std::transform;
using std::tuple;
using std::vector;

class anagram {
 private:
  string word;
  string lower_word;
  string normalized_word;
  tuple<string, string> process_word(string);

 public:
  explicit anagram(string word) {
    this->word = word;
    tuple<string, string> processed_words = process_word(word);
    lower_word = get<0>(processed_words);
    normalized_word = get<1>(processed_words);
  }
  vector<string> matches(vector<string>);
};
}  // namespace anagram
