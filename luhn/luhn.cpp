#include "luhn.h"

#include <algorithm>

using std::reverse;

bool luhn::valid(string number) {
  number.erase(remove_if(number.begin(), number.end(), isspace), number.end());
  if (number == "0") {
    return false;
  }
  reverse(number.begin(), number.end());
  int counter = 0;
  int sum = 0;
  for (char& digit : number) {
    digit = digit - '0';
    if (digit < 0 || digit > 9) return false;
    if (counter % 2 != 0) {
      digit = 2 * digit - 9 * (digit / 5);
    }
    counter = counter + 1;
    sum = sum + digit;
  }

  return sum % 10 == 0;
}
