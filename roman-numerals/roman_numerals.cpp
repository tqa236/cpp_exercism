#include "roman_numerals.h"
#include <map>
#include <vector>
using namespace std;

string roman_numerals::convert(int number) {
  map<int, string> value = {{1, "I"},   {5, "V"},   {10, "X"},  {50, "L"},
                            {100, "C"}, {500, "D"}, {1000, "M"}};
  vector<int> addition = {1000, 500, 100, 50, 10, 5, 1};
  vector<int> substraction = {100, 100, 10, 10, 1, 1};
  int addition_number;
  int substraction_number;
  string roman_number = "";
  while (number > 0) {
    addition_number = addition.front();
    substraction_number = substraction.front();
    if (number < addition_number - substraction_number) {
      addition.erase(addition.begin());
      substraction.erase(substraction.begin());
    } else if (number < addition_number) {
      roman_number =
          roman_number + value[substraction_number] + value[addition_number];
      number = number + substraction_number - addition_number;
    } else {
      roman_number = roman_number + value[addition_number];
      number = number - addition_number;
    }
  }
  return roman_number;
}
