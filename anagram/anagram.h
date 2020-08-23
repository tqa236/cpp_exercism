#pragma once

#include <string>
#include <tuple>
#include <vector>

namespace anagram {
class anagram {
 private:
  std::string word;
  std::string lower_word;
  std::string normalized_word;
  std::tuple<std::string, std::string> process_word(std::string);

 public:
  explicit anagram(std::string word) {
    this->word = word;
    std::tuple<std::string, std::string> processed_words = process_word(word);
    lower_word = std::get<0>(processed_words);
    normalized_word = std::get<1>(processed_words);
  }
  std::vector<std::string> matches(std::vector<std::string>);
};
}  // namespace anagram
