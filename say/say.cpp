#include "say.h"

#include <map>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::int64_t;
using std::map;
using std::string;
using std::vector;

string say::in_english(int64_t number) {
  if ((number < 0) || (number >= 1'000'000'000'000)) {
    throw domain_error("Not in range.");
  }
  if (number == 0) {
    return "zero";
  }
  const static map<int64_t, string> words = {{0, ""},
                                             {1, "one"},
                                             {2, "two"},
                                             {3, "three"},
                                             {4, "four"},
                                             {5, "five"},
                                             {6, "six"},
                                             {7, "seven"},
                                             {8, "eight"},
                                             {9, "nine"},
                                             {10, "ten"},
                                             {11, "eleven"},
                                             {12, "twelve"},
                                             {13, "thirteen"},
                                             {14, "fourteen"},
                                             {15, "fifteen"},
                                             {16, "sixteen"},
                                             {17, "seventeen"},
                                             {18, "eighteen"},
                                             {19, "nineteen"},
                                             {20, "twenty"},
                                             {30, "thirty"},
                                             {40, "forty"},
                                             {50, "fifty"},
                                             {60, "sixty"},
                                             {70, "seventy"},
                                             {80, "eighty"},
                                             {90, "ninety"},
                                             {100, "hundred"},
                                             {1000, "thousand"},
                                             {1'000'000, "million"},
                                             {1'000'000'000, "billion"}};
  string spelling = "";
  vector<int64_t> checkpoints = {1'000'000'000, 1'000'000, 1000, 100};
  for (int64_t& checkpoint : checkpoints) {
    if (number >= checkpoint) {
      spelling += in_english(number / checkpoint) + " " + words.at(checkpoint);
      number %= checkpoint;
      if (number > 0) {
        spelling += " ";
      }
    }
  };
  if (number > 20) {
    spelling += words.at((number / 10) * 10);
    number %= 10;
    if (number > 0) {
      spelling += "-";
    }
  }
  spelling += words.at(number);
  return spelling;
}
