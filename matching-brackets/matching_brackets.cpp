#include "matching_brackets.h"

#include <algorithm>
#include <vector>

bool matching_brackets::check(std::string phrase) {
  phrase.erase(
      std::remove_if(phrase.begin(), phrase.end(),
                     [](char c) {
                       std::string all_brackets = "()[]{}";
                       return !(all_brackets.find(c) != std::string::npos);
                     }),
      phrase.end());

  std::vector<std::string> brackets = {"()", "[]", "{}"};
  bool stop = false;
  while (!stop) {
    stop = true;
    for (auto const& bracket : brackets) {
      size_t position = phrase.find(bracket);
      if (position != std::string::npos) {
        stop = false;
        phrase.replace(position, bracket.length(), "");
      }
    }
  }
  return phrase == "";
}
