#pragma once
#include <string>
#include <unordered_set>

namespace allergies {
using std::string;
using std::unordered_set;

class allergy_test {
 private:
  int score;
  unordered_set<string> allergies;

 public:
  explicit allergy_test(int p_score) {
    score = p_score;
    allergies = get_allergies();
  }
  bool is_allergic_to(string);
  unordered_set<string> get_allergies();
};
}  // namespace allergies
