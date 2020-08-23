#include "matching_brackets.h"

#include <map>
#include <vector>

bool matching_brackets::check(std::string phrase) {
  std::vector<char> bracket;
  std::map<char, char> brackets = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
  for (char const& c : phrase) {
    if (c == '(' || c == '[' || c == '{') {
      bracket.push_back(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (bracket.empty())
        return false;
      else {
        if (c != brackets[bracket.back()]) return false;
        bracket.pop_back();
      }
    }
  }
  return bracket.empty();
}
