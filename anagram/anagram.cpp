#include "anagram.h"
#include <iostream>

namespace anagram {
tuple<string, string> anagram::process_word(string word) {
  auto lower_word_ = word;
  transform(lower_word_.begin(), lower_word_.end(), lower_word_.begin(),
            ::tolower);
  auto normalized_word_ = lower_word_;
  sort(normalized_word_.begin(), normalized_word_.end());
  return make_tuple(lower_word_, normalized_word_);
}
vector<string> anagram::matches(vector<string> candidates) {
  vector<string> anagrams;
  for (auto candidate : candidates) {
    auto processed_candidates = process_word(candidate);
    auto lower_candidate = get<0>(processed_candidates);
    auto normalized_candidate = get<1>(processed_candidates);
    if ((normalized_candidate.compare(normalized_word) == 0) &&
        (lower_candidate.compare(lower_word) != 0)) {
      anagrams.push_back(candidate);
    }
  }
  return anagrams;
}
}  // namespace anagram
