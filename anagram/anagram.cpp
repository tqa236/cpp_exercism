#include "anagram.h"
#include <algorithm>

namespace anagram {
std::tuple<std::string, std::string> anagram::process_word(
    std::string const& word) {
  auto lower_word_ = word;
  transform(lower_word_.begin(), lower_word_.end(), lower_word_.begin(),
            ::tolower);
  auto normalized_word_ = lower_word_;
  sort(normalized_word_.begin(), normalized_word_.end());
  return make_tuple(lower_word_, normalized_word_);
}
std::vector<std::string> anagram::matches(std::vector<std::string> candidates) {
  std::vector<std::string> anagrams;
  for (auto candidate : candidates) {
    auto processed_candidates = process_word(candidate);
    auto lower_candidate = std::get<0>(processed_candidates);
    auto normalized_candidate = std::get<1>(processed_candidates);
    if ((normalized_candidate.compare(normalized_word) == 0) &&
        (lower_candidate.compare(lower_word) != 0)) {
      anagrams.push_back(candidate);
    }
  }
  return anagrams;
}
}  // namespace anagram
