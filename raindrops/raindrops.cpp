#include "raindrops.h"

#include <map>

using std::map;
using std::string;
using std::to_string;

string raindrops::convert(int number) {
  map<int, string> drops = {{3, "Pling"}, {5, "Plang"}, {7, "Plong"}};
  string raindrop = "";

  for (auto const& drop : drops) {
    if (number % drop.first == 0) {
      raindrop = raindrop + drop.second;
    }
  }

  if (raindrop == "") {
    return to_string(number);
  }
  return raindrop;
}
